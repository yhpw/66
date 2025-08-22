/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"


void setup_scr_screen_1(lv_ui *ui)
{
	//Write codes screen_1
	ui->screen_1 = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_1, 320, 480);

	//Write style for screen_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_1_ddlist_1
	ui->screen_1_ddlist_1 = lv_dropdown_create(ui->screen_1);
	lv_dropdown_set_options(ui->screen_1_ddlist_1, "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24");
	lv_obj_set_pos(ui->screen_1_ddlist_1, 8, 41);
	lv_obj_set_size(ui->screen_1_ddlist_1, 130, 30);

	//Write style for screen_1_ddlist_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_1_ddlist_1, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_1_ddlist_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_1_ddlist_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_1_ddlist_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_1_ddlist_1, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_1_ddlist_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_1_ddlist_1, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_1_ddlist_1, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_1_ddlist_1, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_1_ddlist_1, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_1_ddlist_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_1_ddlist_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_1_ddlist_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for &style_screen_1_ddlist_1_extra_list_selected_checked
	static lv_style_t style_screen_1_ddlist_1_extra_list_selected_checked;
	ui_init_style(&style_screen_1_ddlist_1_extra_list_selected_checked);
	
	lv_style_set_text_color(&style_screen_1_ddlist_1_extra_list_selected_checked, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_screen_1_ddlist_1_extra_list_selected_checked, &lv_font_montserratMedium_12);
	lv_style_set_border_width(&style_screen_1_ddlist_1_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_screen_1_ddlist_1_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_screen_1_ddlist_1_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_screen_1_ddlist_1_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_1_ddlist_1_extra_list_selected_checked, 3);
	lv_style_set_bg_opa(&style_screen_1_ddlist_1_extra_list_selected_checked, 255);
	lv_style_set_bg_color(&style_screen_1_ddlist_1_extra_list_selected_checked, lv_color_hex(0x00a1b5));
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_1_ddlist_1), &style_screen_1_ddlist_1_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for &style_screen_1_ddlist_1_extra_list_main_default
	static lv_style_t style_screen_1_ddlist_1_extra_list_main_default;
	ui_init_style(&style_screen_1_ddlist_1_extra_list_main_default);
	
	lv_style_set_max_height(&style_screen_1_ddlist_1_extra_list_main_default, 90);
	lv_style_set_text_color(&style_screen_1_ddlist_1_extra_list_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_screen_1_ddlist_1_extra_list_main_default, &lv_font_montserratMedium_12);
	lv_style_set_border_width(&style_screen_1_ddlist_1_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_screen_1_ddlist_1_extra_list_main_default, 255);
	lv_style_set_border_color(&style_screen_1_ddlist_1_extra_list_main_default, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_screen_1_ddlist_1_extra_list_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_1_ddlist_1_extra_list_main_default, 3);
	lv_style_set_bg_opa(&style_screen_1_ddlist_1_extra_list_main_default, 255);
	lv_style_set_bg_color(&style_screen_1_ddlist_1_extra_list_main_default, lv_color_hex(0xffffff));
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_1_ddlist_1), &style_screen_1_ddlist_1_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_1_ddlist_1_extra_list_scrollbar_default
	static lv_style_t style_screen_1_ddlist_1_extra_list_scrollbar_default;
	ui_init_style(&style_screen_1_ddlist_1_extra_list_scrollbar_default);
	
	lv_style_set_radius(&style_screen_1_ddlist_1_extra_list_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_screen_1_ddlist_1_extra_list_scrollbar_default, 255);
	lv_style_set_bg_color(&style_screen_1_ddlist_1_extra_list_scrollbar_default, lv_color_hex(0x00ff00));
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_1_ddlist_1), &style_screen_1_ddlist_1_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes screen_1_label_1
	ui->screen_1_label_1 = lv_label_create(ui->screen_1);
	lv_label_set_text(ui->screen_1_label_1, "bianhao");
	lv_label_set_long_mode(ui->screen_1_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_1_label_1, 8, 9);
	lv_obj_set_size(ui->screen_1_label_1, 100, 32);

	//Write style for screen_1_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_1_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_1_label_1, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_1_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_1_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_1_ta_1
	ui->screen_1_ta_1 = lv_textarea_create(ui->screen_1);
	lv_textarea_set_text(ui->screen_1_ta_1, "");
	lv_textarea_set_password_bullet(ui->screen_1_ta_1, "*");
	lv_textarea_set_password_mode(ui->screen_1_ta_1, false);
	lv_textarea_set_one_line(ui->screen_1_ta_1, false);
	lv_obj_set_pos(ui->screen_1_ta_1, 5, 92);
	lv_obj_set_size(ui->screen_1_ta_1, 311, 39);

	//Write style for screen_1_ta_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_1_ta_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_1_ta_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_1_ta_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_1_ta_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_1_ta_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_1_ta_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_1_ta_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_1_ta_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_1_ta_1, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_1_ta_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_1_ta_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_1_ta_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_1_ta_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_1_ta_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_1_ta_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_1_ta_1, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_1_ta_1, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_1_ta_1, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_1_ta_1, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes screen_1_btn_2
	ui->screen_1_btn_2 = lv_btn_create(ui->screen_1);
	ui->screen_1_btn_2_label = lv_label_create(ui->screen_1_btn_2);
	lv_label_set_text(ui->screen_1_btn_2_label, "screen\n");
	lv_label_set_long_mode(ui->screen_1_btn_2_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_1_btn_2_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_1_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_1_btn_2, 201, 21);
	lv_obj_set_size(ui->screen_1_btn_2, 100, 50);

	//Write style for screen_1_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_1_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_1_btn_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_1_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_1_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_1_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_1_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_1_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_1_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_1_map
	ui->screen_1_map = lv_img_create(ui->screen_1);
	lv_obj_add_flag(ui->screen_1_map, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_1_map, &_Image_1722325870577_edit_884270991487571_alpha_310x239);
	lv_img_set_pivot(ui->screen_1_map, 50,50);
	lv_img_set_angle(ui->screen_1_map, 0);
	lv_obj_set_pos(ui->screen_1_map, 6, 149);
	lv_obj_set_size(ui->screen_1_map, 310, 239);

	//Write style for screen_1_map, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_1_map, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_1);

	
	//Init events for screen.
	events_init_screen_1(ui);
}
