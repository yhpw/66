#ifndef MY_H
#define MY_H

#include <lvgl.h>
#include "ui/gui_guider.h"
#include <BluetoothSerial.h>
extern BluetoothSerial SerialBT;
extern lv_ui guider_ui;

void enter_dropdown();
void enter_dropdown_1();
void update_dropdown_option(int8_t increment);
void update_dropdown_option_1(int8_t increment);
void confirm_selection();
void confirm_selection_1();
#endif // MY_H
