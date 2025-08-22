/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"


static void screen_btn_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.screen_1_del == true) {
	          setup_scr_screen_1(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.screen_1, LV_SCR_LOAD_ANIM_NONE, 200, 200, true);
	        guider_ui.screen_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_screen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_btn_1, screen_btn_1_event_handler, LV_EVENT_ALL, NULL);
}
static void screen_1_ddlist_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		uint16_t id = lv_dropdown_get_selected(guider_ui.screen_1_ddlist_1);
		switch(id) {
		case 0:
		{
			lv_obj_set_style_text_font(guider_ui.screen_1_ta_1, &lv_font_simsun_22, 0);
			lv_textarea_set_text(guider_ui.screen_1_ta_1, "A1");
			break;
		}
		case 1:
		{
			lv_obj_set_style_text_font(guider_ui.screen_1_ta_1, &lv_font_simsun_22, 0);
			lv_textarea_set_text(guider_ui.screen_1_ta_1, "A2");
			break;
		}
		case 2:
		{
			lv_obj_set_style_text_font(guider_ui.screen_1_ta_1, &lv_font_simsun_22, 0);
			lv_textarea_set_text(guider_ui.screen_1_ta_1, "A3");
			break;
		}
		case 3:
		{
			lv_obj_set_style_text_font(guider_ui.screen_1_ta_1, &lv_font_simsun_22, 0);
			lv_textarea_set_text(guider_ui.screen_1_ta_1, "A4");
			break;
		}
		case 4:
		{
			lv_obj_set_style_text_font(guider_ui.screen_1_ta_1, &lv_font_simsun_22, 0);
			lv_textarea_set_text(guider_ui.screen_1_ta_1, "A5");
			break;
		}
		case 5:
		{
			lv_obj_set_style_text_font(guider_ui.screen_1_ta_1, &lv_font_simsun_22, 0);
			lv_textarea_set_text(guider_ui.screen_1_ta_1, "A6");
			break;
		}
		case 6:
		{
			lv_obj_set_style_text_font(guider_ui.screen_1_ta_1, &lv_font_simsun_22, 0);
			lv_textarea_set_text(guider_ui.screen_1_ta_1, "B1");
			break;
		}
		case 7:
		{
			lv_obj_set_style_text_font(guider_ui.screen_1_ta_1, &lv_font_simsun_22, 0);
			lv_textarea_set_text(guider_ui.screen_1_ta_1, "B2");
			break;
		}
		case 8:
		{
			lv_obj_set_style_text_font(guider_ui.screen_1_ta_1, &lv_font_simsun_22, 0);
			lv_textarea_set_text(guider_ui.screen_1_ta_1, "B3");
			break;
		}
		case 9:
		{
			lv_obj_set_style_text_font(guider_ui.screen_1_ta_1, &lv_font_simsun_22, 0);
			lv_textarea_set_text(guider_ui.screen_1_ta_1, "B4");
			break;
		}
		case 10:
		{
			lv_obj_set_style_text_font(guider_ui.screen_1_ta_1, &lv_font_simsun_22, 0);
			lv_textarea_set_text(guider_ui.screen_1_ta_1, "B5");
			break;
		}
		case 11:
		{
			lv_obj_set_style_text_font(guider_ui.screen_1_ta_1, &lv_font_simsun_22, 0);
			lv_textarea_set_text(guider_ui.screen_1_ta_1, "B6");
			break;
		}
		case 12:
		{
			lv_obj_set_style_text_font(guider_ui.screen_1_ta_1, &lv_font_simsun_22, 0);
			lv_textarea_set_text(guider_ui.screen_1_ta_1, "C1");
			break;
		}
		case 13:
		{
			lv_obj_set_style_text_font(guider_ui.screen_1_ta_1, &lv_font_simsun_22, 0);
			lv_textarea_set_text(guider_ui.screen_1_ta_1, "C2");
			break;
		}
		case 14:
		{
			lv_obj_set_style_text_font(guider_ui.screen_1_ta_1, &lv_font_simsun_22, 0);
			lv_textarea_set_text(guider_ui.screen_1_ta_1, "C3");
			break;
		}
		case 15:
		{
			lv_obj_set_style_text_font(guider_ui.screen_1_ta_1, &lv_font_simsun_22, 0);
			lv_textarea_set_text(guider_ui.screen_1_ta_1, "C4");
			break;
		}
		case 16:
		{
			lv_obj_set_style_text_font(guider_ui.screen_1_ta_1, &lv_font_simsun_22, 0);
			lv_textarea_set_text(guider_ui.screen_1_ta_1, "C5");
			break;
		}
		case 17:
		{
			lv_obj_set_style_text_font(guider_ui.screen_1_ta_1, &lv_font_simsun_22, 0);
			lv_textarea_set_text(guider_ui.screen_1_ta_1, "C6");
			break;
		}
		case 18:
		{
			lv_obj_set_style_text_font(guider_ui.screen_1_ta_1, &lv_font_simsun_22, 0);
			lv_textarea_set_text(guider_ui.screen_1_ta_1, "D1");
			break;
		}
		case 19:
		{
			lv_obj_set_style_text_font(guider_ui.screen_1_ta_1, &lv_font_simsun_22, 0);
			lv_textarea_set_text(guider_ui.screen_1_ta_1, "D2");
			break;
		}
		case 20:
		{
			lv_obj_set_style_text_font(guider_ui.screen_1_ta_1, &lv_font_simsun_22, 0);
			lv_textarea_set_text(guider_ui.screen_1_ta_1, "D3");
			break;
		}
		case 21:
		{
			lv_obj_set_style_text_font(guider_ui.screen_1_ta_1, &lv_font_simsun_22, 0);
			lv_textarea_set_text(guider_ui.screen_1_ta_1, "D4");
			break;
		}
		case 23:
		{
			lv_obj_set_style_text_font(guider_ui.screen_1_ta_1, &lv_font_simsun_22, 0);
			lv_textarea_set_text(guider_ui.screen_1_ta_1, "D6");
			break;
		}
		default:
			break;
		}
		break;
	}
	default:
		break;
	}
}
static void screen_1_btn_2_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.screen_del == true) {
	          setup_scr_screen(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.screen, LV_SCR_LOAD_ANIM_NONE, 200, 200, true);
	        guider_ui.screen_1_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_screen_1(lv_ui *ui)
{
	lv_obj_add_event_cb(lv_dropdown_get_list(ui->screen_1_ddlist_1), screen_1_ddlist_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_1_btn_2, screen_1_btn_2_event_handler, LV_EVENT_ALL, NULL);
}

void events_init(lv_ui *ui)
{

}
