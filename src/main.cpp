#include <lvgl.h>
#include <TFT_eSPI.h>
#include "ui/gui_guider.h"
#include "ui/events_init.h"
#include "ui/custom.h"
#include "my.h" 
#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;
const char *pin = "1103"; // ����ƥ����룬�����Լ���Ҫ����

// ����ֱ���
static const uint16_t screenWidth  = 320;
static const uint16_t screenHeight = 480;
// ���建��
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * 10];

TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */

void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);
    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t *)&color_p->full, w * h, true);
    tft.endWrite();
    lv_disp_flush_ready(disp);
}

void lvgl_setup()
{
    lv_init();

    lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * 10);
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);
}

lv_ui guider_ui;

void setup()
{
    Serial.begin(115200);

    // ��ʼ��TFT
    tft.begin(); // TFT ��ʼ��
    tft.setRotation(0); // ������Ļ��ת����
    lvgl_setup();
    
    // ��ʼ�� UI
    setup_ui(&guider_ui);
    events_init(&guider_ui);
    custom_init(&guider_ui);

    // ��������ģʽ
    pinMode(33, INPUT_PULLUP); // ʹ���ڲ���������
    pinMode(32, INPUT_PULLUP); // ʹ���ڲ���������
    pinMode(18, INPUT_PULLUP); // ���ڹ���ѡ��������1ѡ��
    pinMode(19, INPUT_PULLUP); // ����ȷ��ѡ��
    pinMode(13, INPUT_PULLUP); // ���ڽ���������1
    pinMode(21, INPUT_PULLUP); // ���ڹ���ѡ��������ѡ��2
    pinMode(22, INPUT_PULLUP); // ����ȷ��ѡ��
    pinMode(23, INPUT_PULLUP); // ���ڽ���������2
    // ��ʼ��ʾ��Ļ
    lv_scr_load(guider_ui.screen); // ȷ����ʼ��Ļ��ȷ��ʾ

    // ��ʼ������
    SerialBT.begin("ESP32-BT-Master", true);
    SerialBT.setPin(pin); // ����������Դ���
    lv_textarea_set_text(guider_ui.screen_ta_3, "Start Bluetooth connection");
    bool connected =SerialBT.connect("ESP32-BT-Slave");
    if (connected) {
            lv_textarea_set_text(guider_ui.screen_ta_3, "Bluetooth connection successfully");
        } 
    else {
            lv_textarea_set_text(guider_ui.screen_ta_3, "Bluetooth connection failed");
        }
}

void loop()
{   
 lv_timer_handler(); // LVGL������
    delay(5); // �����ӳ٣�ȷ��UI����

    uint32_t now = millis();
    static uint32_t last_button1 = 0;
    static uint32_t last_button2 = 0;
    static uint32_t last_enter = 0;
    static uint32_t last_scroll = 0;
    static uint32_t last_confirm = 0;
   static uint32_t last_enter_1 = 0;
    static uint32_t last_scroll_1 = 0;
    static uint32_t last_confirm_1 = 0;

    // ��鰴ť1״̬
    if (digitalRead(33) == LOW) {
        if (now - last_button1 > 300) {
            last_button1 = now;
            Serial.println("Button 1 Pressed");
            lv_event_send(guider_ui.screen_btn_1, LV_EVENT_CLICKED, NULL); // ������ť�¼�������
        }
    }

    // ��鰴ť2״̬
    if (digitalRead(32) == LOW) {
        if (now - last_button2 > 300) {
            last_button2 = now;
            Serial.println("Button 2 Pressed");
            lv_event_send(guider_ui.screen_1_btn_2, LV_EVENT_CLICKED, NULL); // ������ť�¼�������
        }
    }

    // ������������״̬
    if (digitalRead(13) == LOW) {
        if (now - last_enter > 300) {
            last_enter = now;
            Serial.println("Enter Dropdown");
            enter_dropdown();
        }
    }
        // ������������״̬
    if (digitalRead(21) == LOW) {
        if (now - last_enter_1 > 300) {
            last_enter_1 = now;
            enter_dropdown_1();
        }
    }
    

    // ������ѡ��״̬
    if (digitalRead(18) == LOW) {
        if (now - last_scroll > 300) {
            last_scroll = now;
            Serial.println("Scroll Option");
            update_dropdown_option( 1);
        }
    }

        // ������ѡ��״̬
    if (digitalRead(22) == LOW) {
        if (now - last_scroll_1 > 300) {
            last_scroll_1 = now;
            update_dropdown_option_1( 1);
        }
    }

    // ���ȷ��ѡ��״̬
    if (digitalRead(19) == LOW) {
        if (now - last_confirm > 300) {
            last_confirm = now;
            Serial.println("Confirm Selection");
            confirm_selection();
        }
    }
    if (digitalRead(23) == LOW) {
        if (now - last_confirm_1 > 300) {
            last_confirm_1 = now;
            confirm_selection_1();
        }
    }
    // �����������
    if (SerialBT.available()) {
        String received = SerialBT.readString();
        lv_textarea_set_text(guider_ui.screen_ta_2, received.c_str());
        Serial.println("Received from Bluetooth: " + received);
    }

}
