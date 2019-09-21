#include "Arduino.h"
#include "pins_arduino.h"
#include <LiquidCrystal.h>
#include <LCDMenuLib2.h>

typedef struct{
  char* label;
  int progress;
  byte line;
  byte columns;
  byte pbsize;
}PB;


PB tim = {"T", 0, 1, 16, 12};


void mFunc_timer(uint8_t timer);
void mFunc_back(uint8_t param);
void initProgbar(PB* pb);
void updateProgbar(PB* pb);


#define _LCDML_DISP_cols  16
#define _LCDML_DISP_rows  2

#define _LCDML_DISP_cfg_cursor    0x7E   // cursor Symbol
#define _LCDML_DISP_cfg_scrollbar 1      // enable a scrollbar


#define UUML     "\365"
#define AUML     "\341"
#define OUML     "\357"

const uint8_t progress_bar[7][8] = {{B11111,B00000,B00000,B00000,B00000,B00000,B00000,B11111},
                                    {B11111,B10000,B10000,B10000,B10000,B10000,B10000,B11111},
                                    {B11111,B11000,B11000,B11000,B11000,B11000,B11000,B11111},
                                    {B11111,B11100,B11100,B11100,B11100,B11100,B11100,B11111},
                                    {B11111,B11110,B11110,B11110,B11110,B11110,B11110,B11111},
                                    {B11111,B11111,B11111,B11111,B11111,B11111,B11111,B11111},
                                    {B11111,B01010,B10101,B01010,B10101,B01010,B10101,B11111}
                                   };

const char start_msg[] = "Starte...";
const char compile_date[] = __DATE__;
const char compile_time[] = __TIME__;
const char compile_file[] = __FILE__;

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

const uint8_t scroll_bar[5][8] = {
  {B10001, B10001, B10001, B10001, B10001, B10001, B10001, B10001}, // scrollbar top
  {B11111, B11111, B10001, B10001, B10001, B10001, B10001, B10001}, // scroll state 1
  {B10001, B10001, B11111, B11111, B10001, B10001, B10001, B10001}, // scroll state 2
  {B10001, B10001, B10001, B10001, B11111, B11111, B10001, B10001}, // scroll state 3
  {B10001, B10001, B10001, B10001, B10001, B10001, B11111, B11111}  // scrollbar bottom
};

// *********************************************************************
// Prototypes
// *********************************************************************
void lcdml_menu_display();
void lcdml_menu_clear();
void lcdml_menu_control();

// *********************************************************************
// Global variables
// *********************************************************************


// *********************************************************************
// Objects
// *********************************************************************
LCDMenuLib2_menu LCDML_0 (255, 0, 0, NULL, NULL); // root menu element (do not change)
LCDMenuLib2 LCDML(LCDML_0, _LCDML_DISP_rows, _LCDML_DISP_cols, lcdml_menu_display, lcdml_menu_clear, lcdml_menu_control);

// *********************************************************************
// LCDML MENU/DISP
// *********************************************************************
// LCDML_0        => layer 0
// LCDML_0_X      => layer 1
// LCDML_0_X_X    => layer 2
// LCDML_0_X_X_X  => layer 3
// LCDML_0_...      => layer ...

// For beginners
// LCDML_add(id, prev_layer, new_num, lang_char_array, callback_function)
LCDML_add         (0  , LCDML_0         , 1  , "Timer"              , NULL);       // this menu function can be found on "LCDML_display_menuFunction" tab
LCDML_add         (1  , LCDML_0         , 2  , "Manuell"            , NULL);        // this menu function can be found on "LCDML_display_menuFunction" tab
LCDML_add         (2  , LCDML_0         , 3  , "Einstellungen"      , NULL);                    // NULL = no menu function
LCDML_add         (3  , LCDML_0_1       , 1  , "Zeit ausw" AUML "hlen"      , NULL);                    // NULL = no menu function

LCDML_addAdvanced (4  , LCDML_0_1_1     , 1  ,  NULL, "15 Sekunden" , mFunc_timer, 15, _LCDML_TYPE_default);                    // NULL = no menu function
LCDML_addAdvanced (5  , LCDML_0_1_1     , 2  ,  NULL, "30 Sekunden" , mFunc_timer, 30, _LCDML_TYPE_default);
LCDML_addAdvanced (6  , LCDML_0_1_1     , 3  ,  NULL, "45 Sekunden" , mFunc_timer, 45, _LCDML_TYPE_default);
LCDML_addAdvanced (7  , LCDML_0_1_1     , 4  ,  NULL, "60 Sekunden" , mFunc_timer, 60, _LCDML_TYPE_default);
LCDML_add         (8  , LCDML_0_1_1     , 5  , "Zur" UUML "ck"        ,mFunc_back);

LCDML_add         (9  , LCDML_0_1       , 2  , "Zeit eingeben"      , NULL);                    // NULL = no menu function
LCDML_add         (10  , LCDML_0_1       , 3  , "Zur" UUML "ck"        ,mFunc_back);                    // NULL = no menu function

LCDML_add         (11  , LCDML_0_2       , 1  , "Ein"      , NULL);                    // NULL = no menu function
LCDML_add         (12  , LCDML_0_2       , 2  , "Aus"      , NULL);                    // NULL = no menu function

// ***TIP*** Try to update _LCDML_DISP_cnt when you add a menu elment.

// menu element count - last element id
// this value must be the same as the last menu element
#define _LCDML_DISP_cnt    12
// create menu
LCDML_createMenu(_LCDML_DISP_cnt);


#include "LCDML_display_menuFunction.ino"
#include "LCDML_display_menu.ino"
#include "LCDML_display_dynFunction.ino"
#include "LCDML_control.ino"
#include "LCDML_condetion.ino"


// *********************************************************************
// SETUP
// *********************************************************************
void setup()
{
  lcd.begin(16, 2);
  lcd.print(start_msg);
  lcd.setCursor(0,1);
  lcd.print(compile_date);
  boardinit();

  // set special chars for scrollbar
  lcd.createChar(0, (uint8_t*)scroll_bar[0]);
  lcd.createChar(1, (uint8_t*)scroll_bar[1]);
  lcd.createChar(2, (uint8_t*)scroll_bar[2]);
  lcd.createChar(3, (uint8_t*)scroll_bar[3]);
  lcd.createChar(4, (uint8_t*)scroll_bar[4]);

  LCDML_setup(_LCDML_DISP_cnt);
  LCDML.MENU_enRollover();
}

void boardinit(){
  Serial.begin(9600);
  Serial.println(start_msg);
  Serial.println("Time: " + (String) compile_date +" "+ (String) compile_time);
  Serial.println("Path: " + (String) compile_file);

  pinMode(A0, OUTPUT); //green
  pinMode(A1, OUTPUT); //yellow
  pinMode(A2, OUTPUT); //red
  pinMode(4, INPUT_PULLUP); //push button
  pinMode(5, OUTPUT); //MOSFET
  pinMode(A3, INPUT_PULLUP); //closing switch
  pinMode(A4, OUTPUT); //opt buzzer

  digitalWrite(A0, 1);
  digitalWrite(A1, 1);
  digitalWrite(A2, 1);

  delay(500);

  digitalWrite(A0, 0);
  digitalWrite(A1, 0);
  //digitalWrite(A2, 0);

  lcd.clear();

  //initProgbar(&tim);
}

// *********************************************************************
// LOOP
// *********************************************************************
void loop()
{
  LCDML.loop();
}

// *********************************************************************
// check some errors - do not change here anything
// *********************************************************************
# if(_LCDML_DISP_rows > _LCDML_DISP_cfg_max_rows)
# error change value of _LCDML_DISP_cfg_max_rows in LCDMenuLib2.h
# endif

