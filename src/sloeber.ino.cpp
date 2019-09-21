#ifdef __IN_ECLIPSE__
//This is a automatic generated file
//Please do not modify this file
//If you touch this file your change will be overwritten during the next build
//This file has been generated on 2018-02-06 14:54:12

#include "Arduino.h"
#define _LCDML_CONTROL_cfg      3
#define _LCDML_CONTROL_encoder_pin_a           2
#define _LCDML_CONTROL_encoder_pin_b           3
#define _LCDML_CONTROL_encoder_pin_button      4
#define _LCDML_CONTROL_encoder_high_active     0
extern unsigned long g_LCDML_DISP_press_time;
extern uint8_t g_LCDML_CONTROL_encoder_t_prev;
extern uint8_t g_LCDML_CONTROL_encoder_a_prev;
#include "Arduino.h"
#include "pins_arduino.h"
#include <LiquidCrystal.h>
#include <LCDMenuLib2.h>
extern PB tim;
#define _LCDML_DISP_cols  16
#define _LCDML_DISP_rows  2
#define _LCDML_DISP_cfg_cursor    0x7E
#define _LCDML_DISP_cfg_scrollbar 1
#define UUML     "\365"
#define AUML     "\341"
#define OUML     "\357"
extern const char start_msg[];
extern const char compile_date[];
extern const char compile_time[];
extern const char compile_file[];
extern LiquidCrystal lcd;
extern LCDMenuLib2_menu LCDML_0;
extern LCDMenuLib2 LCDML;
extern const char g_LCDML_DISP_lang_0_var[];
extern const char g_LCDML_DISP_lang_1_var[];
extern const char g_LCDML_DISP_lang_2_var[];
extern const char g_LCDML_DISP_lang_3_var[];
extern const char g_LCDML_DISP_lang_4_var[];
extern const char g_LCDML_DISP_lang_5_var[];
extern const char g_LCDML_DISP_lang_6_var[];
extern const char g_LCDML_DISP_lang_7_var[];
extern const char g_LCDML_DISP_lang_8_var[];
extern const char g_LCDML_DISP_lang_9_var[];
extern const char g_LCDML_DISP_lang_10_var[];
extern const char g_LCDML_DISP_lang_11_var[];
extern const char g_LCDML_DISP_lang_12_var[];
#define _LCDML_DISP_cnt    12
extern const char* const g_LCDML_DISP_lang_table[];
#include "LCDML_display_menuFunction.ino"
#include "LCDML_display_menu.ino"
#include "LCDML_display_dynFunction.ino"
#include "LCDML_control.ino"
#include "LCDML_condetion.ino"

boolean COND_hide()    ;
void lcdml_menu_control(void) ;
void mDyn_para(uint8_t line)  ;
void lcdml_menu_clear() /* ******************************************************************** */ ;
void lcdml_menu_display() /* ******************************************************************** */ ;
void mFunc_timer(uint8_t timer)  ;
void uvledControl(bool state) ;
void debouncePB() ;
void initProgbar(PB* pb) ;
void updateProgbar(PB* pb) ;
String convertTime(long time) ;
void mFunc_timer_info(uint8_t param)  ;
void mFunc_p2(uint8_t param)  ;
void mFunc_screensaver(uint8_t param)  ;
void mFunc_back(uint8_t param)  ;
void mFunc_goToRootMenu(uint8_t param)  ;
void mFunc_jumpTo_timer_info(uint8_t param)  ;
void mFunc_para(uint8_t param)  ;
LCDML_add         (0  , LCDML_0         , 1  , "Timer"              , NULL);
LCDML_add         (1  , LCDML_0         , 2  , "Manuell"            , NULL);
LCDML_add         (2  , LCDML_0         , 3  , "Einstellungen"      , NULL);
LCDML_add         (3  , LCDML_0_1       , 1  , "Zeit ausw" AUML "hlen"      , NULL);
LCDML_addAdvanced (4  , LCDML_0_1_1     , 1  ,  NULL, "15 Sekunden" , mFunc_timer, 15, _LCDML_TYPE_default);
LCDML_addAdvanced (5  , LCDML_0_1_1     , 2  ,  NULL, "30 Sekunden" , mFunc_timer, 30, _LCDML_TYPE_default);
LCDML_addAdvanced (6  , LCDML_0_1_1     , 3  ,  NULL, "45 Sekunden" , mFunc_timer, 45, _LCDML_TYPE_default);
LCDML_addAdvanced (7  , LCDML_0_1_1     , 4  ,  NULL, "60 Sekunden" , mFunc_timer, 60, _LCDML_TYPE_default);
LCDML_add         (8  , LCDML_0_1_1     , 5  , "Zur" UUML "ck"        ,mFunc_back);
LCDML_add         (9  , LCDML_0_1       , 2  , "Zeit eingeben"      , NULL);
LCDML_add         (10  , LCDML_0_1       , 3  , "Zur" UUML "ck"        ,mFunc_back);
LCDML_add         (11  , LCDML_0_2       , 1  , "Ein"      , NULL);
LCDML_add         (12  , LCDML_0_2       , 2  , "Aus"      , NULL);
void setup() ;
void boardinit();
void loop() ;

#include "Platinenbelichtung.ino"

#include "LCDML_condetion.ino"
#include "LCDML_control.ino"
#include "LCDML_display_dynFunction.ino"
#include "LCDML_display_menu.ino"
#include "LCDML_display_menuFunction.ino"

#endif
