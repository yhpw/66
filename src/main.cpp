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
const char *pin = "1103"; // 蓝牙匹配代码，根据自己需要更改

// 定义分辨率
static const uint16_t screenWidth  = 320;
static const uint16_t screenHeight = 480;
// 定义缓冲
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

    // 初始化TFT
    tft.begin(); // TFT 初始化
    tft.setRotation(0); // 设置屏幕旋转方向
    lvgl_setup();
    
    // 初始化 UI
    setup_ui(&guider_ui);
    events_init(&guider_ui);
    custom_init(&guider_ui);

    // 设置引脚模式
    pinMode(33, INPUT_PULLUP); // 使用内部上拉电阻
    pinMode(32, INPUT_PULLUP); // 使用内部上拉电阻
    pinMode(18, INPUT_PULLUP); // 用于滚动选择下拉框1选项
    pinMode(19, INPUT_PULLUP); // 用于确认选择
    pinMode(13, INPUT_PULLUP); // 用于进入下拉框1
    pinMode(21, INPUT_PULLUP); // 用于滚动选择下拉框选项2
    pinMode(22, INPUT_PULLUP); // 用于确认选择
    pinMode(23, INPUT_PULLUP); // 用于进入下拉框2
    // 初始显示屏幕
    lv_scr_load(guider_ui.screen); // 确保初始屏幕正确显示

    // 初始化蓝牙
    SerialBT.begin("ESP32-BT-Master", true);
    SerialBT.setPin(pin); // 设置蓝牙配对代码
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
 lv_timer_handler(); // LVGL任务处理
    delay(5); // 稍作延迟，确保UI更新

    uint32_t now = millis();
    static uint32_t last_button1 = 0;
    static uint32_t last_button2 = 0;
    static uint32_t last_enter = 0;
    static uint32_t last_scroll = 0;
    static uint32_t last_confirm = 0;
   static uint32_t last_enter_1 = 0;
    static uint32_t last_scroll_1 = 0;
    static uint32_t last_confirm_1 = 0;

    // 检查按钮1状态
    if (digitalRead(33) == LOW) {
        if (now - last_button1 > 300) {
            last_button1 = now;
            Serial.println("Button 1 Pressed");
            lv_event_send(guider_ui.screen_btn_1, LV_EVENT_CLICKED, NULL); // 触发按钮事件处理函数
        }
    }

    // 检查按钮2状态
    if (digitalRead(32) == LOW) {
        if (now - last_button2 > 300) {
            last_button2 = now;
            Serial.println("Button 2 Pressed");
            lv_event_send(guider_ui.screen_1_btn_2, LV_EVENT_CLICKED, NULL); // 触发按钮事件处理函数
        }
    }

    // 检查进入下拉框状态
    if (digitalRead(13) == LOW) {
        if (now - last_enter > 300) {
            last_enter = now;
            Serial.println("Enter Dropdown");
            enter_dropdown();
        }
    }
        // 检查进入下拉框状态
    if (digitalRead(21) == LOW) {
        if (now - last_enter_1 > 300) {
            last_enter_1 = now;
            enter_dropdown_1();
        }
    }
    

    // 检查滚动选择状态
    if (digitalRead(18) == LOW) {
        if (now - last_scroll > 300) {
            last_scroll = now;
            Serial.println("Scroll Option");
            update_dropdown_option( 1);
        }
    }

        // 检查滚动选择状态
    if (digitalRead(22) == LOW) {
        if (now - last_scroll_1 > 300) {
            last_scroll_1 = now;
            update_dropdown_option_1( 1);
        }
    }

    // 检查确认选择状态
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
    // 检查蓝牙数据
    if (SerialBT.available()) {
        String received = SerialBT.readString();
        lv_textarea_set_text(guider_ui.screen_ta_2, received.c_str());
        Serial.println("Received from Bluetooth: " + received);
    }

}
