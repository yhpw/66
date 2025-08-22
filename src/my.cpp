#include "my.h"
#include <TFT_eSPI.h>

bool dropdown_active = false;

// 进入下拉框
void enter_dropdown()
{
    lv_obj_t *current_screen = lv_disp_get_scr_act(NULL);
    if (lv_obj_get_screen(guider_ui.screen_1_ddlist_1) == current_screen) {
        Serial.println("Entering Dropdown");
        lv_event_send(guider_ui.screen_1_ddlist_1, LV_EVENT_CLICKED, NULL);
        dropdown_active = true; // 标记下拉框为活跃状态
    } else {
        Serial.println("Dropdown not visible on current screen");
    }
}
void enter_dropdown_1()
{
    lv_obj_t *current_screen = lv_disp_get_scr_act(NULL);
    if (lv_obj_get_screen(guider_ui.screen_ddlist_1) == current_screen) {
        Serial.println("Entering Dropdown");
        lv_event_send(guider_ui.screen_ddlist_1, LV_EVENT_CLICKED, NULL);
        dropdown_active = true; // 标记下拉框为活跃状态
    } else {
        Serial.println("Dropdown not visible on current screen");
    }
}
// 滚动选择下拉框选项
void update_dropdown_option(int8_t increment)
{
    if (dropdown_active) {
        lv_obj_t *current_screen = lv_disp_get_scr_act(NULL);
        if (lv_obj_get_screen(guider_ui.screen_1_ddlist_1) == current_screen) {
            int16_t current = lv_dropdown_get_selected(guider_ui.screen_1_ddlist_1);
            int16_t new_selected = current + increment;

            if (new_selected < 0) new_selected = 0;
            if (new_selected > 23) new_selected = 23;

            Serial.print("Updating Dropdown Option: ");
            Serial.println(new_selected);
            lv_dropdown_set_selected(guider_ui.screen_1_ddlist_1, new_selected);
            lv_event_send(guider_ui.screen_1_ddlist_1, LV_EVENT_VALUE_CHANGED, NULL);
        } else {
            Serial.println("Dropdown not visible on current screen");
        }
    }
}
void update_dropdown_option_1(int8_t increment)
{
    if (dropdown_active) {
        lv_obj_t *current_screen = lv_disp_get_scr_act(NULL);
        if (lv_obj_get_screen(guider_ui.screen_ddlist_1) == current_screen) {
            int16_t current = lv_dropdown_get_selected(guider_ui.screen_ddlist_1);
            int16_t new_selected = current + increment;

            if (new_selected < 0) new_selected = 0;
            if (new_selected > 23) new_selected = 23;

            Serial.print("Updating Dropdown Option: ");
            Serial.println(new_selected);
            lv_dropdown_set_selected(guider_ui.screen_ddlist_1, new_selected);
            lv_event_send(guider_ui.screen_ddlist_1, LV_EVENT_VALUE_CHANGED, NULL);
        } else {
            Serial.println("Dropdown not visible on current screen");
        }
    }
}
void confirm_selection()
{
    if (dropdown_active) {
        lv_obj_t *current_screen = lv_disp_get_scr_act(NULL);
        if (lv_obj_get_screen(guider_ui.screen_1_ddlist_1) == current_screen) {
            Serial.println("Confirming Selection");

            // 获取当前选择的值
            uint16_t selected_id = lv_dropdown_get_selected(guider_ui.screen_1_ddlist_1);
            Serial.print("Selected ID: ");
            Serial.println(selected_id);

            // 更新文本区域内容
            switch (selected_id) {
                case 0: lv_textarea_set_text(guider_ui.screen_1_ta_1, "A1"); break;
                case 1: lv_textarea_set_text(guider_ui.screen_1_ta_1, "A2"); break;
                case 2: lv_textarea_set_text(guider_ui.screen_1_ta_1, "A3"); break;
                case 3: lv_textarea_set_text(guider_ui.screen_1_ta_1, "A4"); break;
                case 4: lv_textarea_set_text(guider_ui.screen_1_ta_1, "A5"); break;
                case 5: lv_textarea_set_text(guider_ui.screen_1_ta_1, "A6"); break;
                case 6: lv_textarea_set_text(guider_ui.screen_1_ta_1, "B1"); break;
                case 7: lv_textarea_set_text(guider_ui.screen_1_ta_1, "B2"); break;
                case 8: lv_textarea_set_text(guider_ui.screen_1_ta_1, "B3"); break;
                case 9: lv_textarea_set_text(guider_ui.screen_1_ta_1, "B4"); break;
                case 10: lv_textarea_set_text(guider_ui.screen_1_ta_1, "B5"); break;
                case 11: lv_textarea_set_text(guider_ui.screen_1_ta_1, "B6"); break;
                case 12: lv_textarea_set_text(guider_ui.screen_1_ta_1, "C1"); break;
                case 13: lv_textarea_set_text(guider_ui.screen_1_ta_1, "C2"); break;
                case 14: lv_textarea_set_text(guider_ui.screen_1_ta_1, "C3"); break;
                case 15: lv_textarea_set_text(guider_ui.screen_1_ta_1, "C4"); break;
                case 16: lv_textarea_set_text(guider_ui.screen_1_ta_1, "C5"); break;
                case 17: lv_textarea_set_text(guider_ui.screen_1_ta_1, "C6"); break;
                case 18: lv_textarea_set_text(guider_ui.screen_1_ta_1, "D1"); break;
                case 19: lv_textarea_set_text(guider_ui.screen_1_ta_1, "D2"); break;
                case 20: lv_textarea_set_text(guider_ui.screen_1_ta_1, "D3"); break;
                case 21: lv_textarea_set_text(guider_ui.screen_1_ta_1, "D4"); break;
                case 22: lv_textarea_set_text(guider_ui.screen_1_ta_1, "D5"); break;
                case 23: lv_textarea_set_text(guider_ui.screen_1_ta_1, "D6"); break;
            }

            dropdown_active = false; // 标记下拉框为非活跃状态
        } else {
            Serial.println("Dropdown not visible on current screen");
        }
    }
}
void confirm_selection_1()
{
    if (dropdown_active) {
        lv_obj_t *current_screen = lv_disp_get_scr_act(NULL);
        if (lv_obj_get_screen(guider_ui.screen_ddlist_1) == current_screen) {
            Serial.println("Confirming Selection");

            // 获取当前选择的值
            uint16_t selected_id = lv_dropdown_get_selected(guider_ui.screen_ddlist_1);
            Serial.print("Selected ID: ");
            Serial.println(selected_id);

            // 更新文本区域内容
            switch (selected_id) {
                case 0:
                    lv_textarea_set_text(guider_ui.screen_ta_3, "send 1");
                    SerialBT.println('1');
                    break;
                case 1:
                    lv_textarea_set_text(guider_ui.screen_ta_3, "send 2");
                    SerialBT.println('2');
                    break;
                case 2:
                    lv_textarea_set_text(guider_ui.screen_ta_3, "send 3");
                    SerialBT.println('3');
                    break;
                case 3:
                    lv_textarea_set_text(guider_ui.screen_ta_3, "send 4");
                    SerialBT.println('4');
                    break;
                case 4:
                    lv_textarea_set_text(guider_ui.screen_ta_3, "send 5");
                    SerialBT.println('5');
                    break;
                case 5:
                    lv_textarea_set_text(guider_ui.screen_ta_3, "send 6");
                    SerialBT.println('6');
                    break;
                default:
                    lv_textarea_set_text(guider_ui.screen_ta_3, "Invalid selection");
                    SerialBT.println('X'); // 默认值，指示无效选择
                    break;
            }

            dropdown_active = false; // 标记下拉框为非活跃状态
        } else {
            Serial.println("Dropdown not visible on current screen");
        }
    }
}

