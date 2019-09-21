//#include "Platinenbelichtung.ino"
/* ===================================================================== *
 *                                                                       *
   Menu Callback Function
 *                                                                       *
   =====================================================================

   EXAMPLE CODE:

  // *********************************************************************
  void your_function_name(uint8_t param)
  // *********************************************************************
  {
  if(LCDML.FUNC_setup())          // ****** SETUP *********
  {
    // setup
    // is called only if it is started

    // starts a trigger event for the loop function every 100 millisecounds
    LCDML.FUNC_setLoopInterval(100);
  }

  if(LCDML.FUNC_loop())           // ****** LOOP *********
  {
    // loop
    // is called when it is triggert
    // - with LCDML_DISP_triggerMenu( millisecounds )
    // - with every button status change

    // check if any button is presed (enter, up, down, left, right)
    if(LCDML.BT_checkAny()) {
      LCDML.FUNC_goBackToMenu();
    }
  }

  if(LCDML.FUNC_close())      // ****** STABLE END *********
  {
    // loop end
    // you can here reset some global vars or delete it
  }
  }


   =====================================================================
*/

unsigned long starttime , stoptime;
long countdown;
int savetime;
bool lastbutton;

// *********************************************************************
void mFunc_timer(uint8_t timer)
// *********************************************************************
{
  if (LCDML.FUNC_setup())         // ****** SETUP *********
  {
    Serial.println(timer);
    if (digitalRead(A3)) {
      lcd.clear();
      lcd.print("Deckel nicht");
      lcd.setCursor(0, 1);
      lcd.print("geschlossen!");
      bool last = 0;
      for (int i = 0; i < 10; i++) {
        last = !last;
        digitalWrite(A1, !last);
        delay (100);
      }
      digitalWrite(A1, 0);
      LCDML.FUNC_goBackToMenu();
      return;
    }
    digitalWrite(A2, 0);
    digitalWrite(A1, 1);
    lcd.clear();
    lcd.print("Knopf gedr" UUML "ckt");
    lcd.setCursor(0, 1);
    lcd.print("halten f" UUML "r Start");
    do {} while (!digitalRead(4));
    do {} while (digitalRead(4));
    starttime = millis();
    do {} while (!digitalRead(4) && starttime + 1000 > millis());
    if (starttime + 1000 > millis()) {
      LCDML.FUNC_goBackToMenu();
      return;
    }
    lcd.clear();
    initProgbar(&tim);
    stoptime = millis() + (unsigned long) timer * 1000;
    LCDML.FUNC_setLoopInterval(50);
    lastbutton = 0;
    uvledControl(1);
    digitalWrite(A1, 0);
  }

  if (LCDML.FUNC_loop())          // ****** LOOP *********
  {
    countdown = (stoptime - millis());
    Serial.println(stoptime);
    Serial.println(millis());
    Serial.println(countdown);
    Serial.println("-----");
    if (digitalRead(A3)) {
      digitalWrite(A1, 1);
      uvledControl(0);
      savetime = countdown;
      bool last = 1;
back:
      do {
        last = !last;
        digitalWrite(A1, last);
        delay(100);
      } while (digitalRead(A3));
      digitalWrite(A1, 1);
      do {
        if (digitalRead(A3))goto back;
      } while (digitalRead(4));
      starttime = millis();
      do {} while (!digitalRead(4) && starttime + 1000 > millis());
      if (starttime + 1000 < millis()) {
        LCDML.FUNC_goBackToMenu();
        return;
      }
      stoptime = millis() + savetime;
      digitalWrite(A1, 0);
    }
    if (!digitalRead(4) && lastbutton == 1) {
      savetime = countdown;
      digitalWrite(A1, 1);
      uvledControl(0);
      do {} while (!digitalRead(4));
      delay(100);
      do {} while (digitalRead(4));
      starttime = millis();
      do {} while (!digitalRead(4) && starttime + 1000 > millis());
      if (starttime + 1000 <= millis()) {
        LCDML.FUNC_goBackToMenu();
        return;
      }
      stoptime = millis() + savetime;
      digitalWrite(A1, 0);
    }
    uvledControl(1);
    lastbutton = digitalRead(4);
    lcd.setCursor(0, 0);
    lcd.print(convertTime(countdown));
    tim.progress = map(millis(), stoptime - (unsigned long) timer * 1000, stoptime, 0, 100);
    updateProgbar(&tim);
    if (countdown <= 0) {
      digitalWrite(A2, 1);
      uvledControl(0);
      debouncePB();
      LCDML.FUNC_goBackToMenu();
    }
  }

  if (LCDML.FUNC_close())     // ****** STABLE END *********
  {
    digitalWrite(A2, 1);
    digitalWrite(A1, 0);
    lcd.clear();
    do {} while (!digitalRead(4));
    lcd.createChar(0, (uint8_t*)scroll_bar[0]);
    lcd.createChar(1, (uint8_t*)scroll_bar[1]);
    lcd.createChar(2, (uint8_t*)scroll_bar[2]);
    lcd.createChar(3, (uint8_t*)scroll_bar[3]);
    lcd.createChar(4, (uint8_t*)scroll_bar[4]);
  }
}

void uvledControl(bool state) {
  if (state) {
    digitalWrite(A0, 1);
    digitalWrite(5, 1);
  }
  else {
    digitalWrite(A0, 0);
    digitalWrite(5, 0);
  }
}

void debouncePB() {
  do {} while (digitalRead(4));
  delay(100);
  do {} while (!digitalRead(4));
}

void initProgbar(PB* pb) {
  lcd.createChar(0, (uint8_t*)progress_bar[0]);
  lcd.createChar(1, (uint8_t*)progress_bar[1]);
  lcd.createChar(2, (uint8_t*)progress_bar[2]);
  lcd.createChar(3, (uint8_t*)progress_bar[3]);
  lcd.createChar(4, (uint8_t*)progress_bar[4]);
  lcd.createChar(5, (uint8_t*)progress_bar[5]);
  lcd.createChar(6, (uint8_t*)progress_bar[6]);
  lcd.setCursor(0, pb->line);
  lcd.write(pb->label);
  lcd.write(":");

  lcd.rightToLeft();
  lcd.setCursor(pb->columns - 1, pb->line);
  for (int i = 0; i < pb->pbsize; i++) {
    lcd.write(byte(0));
  }
  lcd.write("%");
  lcd.leftToRight();
}

void updateProgbar(PB* pb) {
  int startpb = pb->columns - pb->pbsize;
  float divider = 100.0 / ((float)pb->pbsize);

  lcd.setCursor(startpb - 4, pb->line);
  String str = String(pb->progress, DEC);
  char cstr[4];
  str.toCharArray(cstr, 4);
  if (pb->progress < 100) {
    lcd.write("0");
    if (pb->progress < 10) {
      lcd.write("0");
    }
  }
  lcd.write(cstr);
  lcd.setCursor(startpb, pb->line);
  if (pb->progress > 100) {
    for (int i = 1; i <= pb->pbsize; i++) {
      lcd.write(byte(6));
    }
    return;
  }
  for (int i = 1; i <= pb->pbsize; i++) {
    if ((float)pb->progress / (i * divider) >= 1) {
      lcd.write(byte(5));
    }
    else {
      float remainder = pb->progress - (i - 1) * divider;
      //Serial.println(divider);
      //Serial.println(remainder);
      int j = 1;
      for (j; remainder / (j * (divider / 5.0)) >= 1; j++) {}
      switch (j - 1) {
        case 0:
          lcd.write(byte(0));
          break;
        case 1:
          lcd.write(byte(1));
          break;
        case 2:
          lcd.write(byte(2));
          break;
        case 3:
          lcd.write(byte(3));
          break;
        case 4:
          lcd.write(byte(4));
          break;
        case 5:
          lcd.write(byte(5));
          break;
      }
      for (i; i <= 11; i++) {
        lcd.write(byte(0));
      }
    }
  }
}

String convertTime(long time) {
  time += 999;
  int sec, min;
  String formatted;
  min = time / 1000 / 60;
  if (min < 10)formatted += "0";
  formatted += (String) min;
  sec = time / 1000 % 60;
  formatted += ":";
  if (sec < 10)formatted += "0";
  formatted += (String) sec;
  return formatted;
}



// *********************************************************************
uint8_t g_func_timer_info = 0;  // time counter (global variable)
unsigned long g_timer_1 = 0;    // timer variable (globale variable)
void mFunc_timer_info(uint8_t param)
// *********************************************************************
{
  if (LCDML.FUNC_setup())         // ****** SETUP *********
  {
    lcd.print(F("20 sec wait")); // print some content on first row
    g_func_timer_info = 20;       // reset and set timer
    LCDML.FUNC_setLoopInterval(100);  // starts a trigger event for the loop function every 100 millisecounds

    LCDML.TIMER_msReset(g_timer_1);
  }


  if (LCDML.FUNC_loop())          // ****** LOOP *********
  {
    // loop function, can be run in a loop when LCDML_DISP_triggerMenu(xx) is set
    // the quit button works in every DISP function without any checks; it starts the loop_end function

    // reset screensaver timer
    LCDML.SCREEN_resetTimer();

    // this function is called every 100 millisecounds

    // this method checks every 1000 millisecounds if it is called
    if (LCDML.TIMER_ms(g_timer_1, 1000)) {
      g_func_timer_info--;                // increment the value every secound
      lcd.setCursor(0, 0);                // set cursor pos
      lcd.print(F("  "));
      lcd.setCursor(0, 0);                // set cursor pos
      lcd.print(g_func_timer_info);       // print the time counter value
    }

    // this function can only be ended when quit button is pressed or the time is over
    // check if the function ends normaly
    if (g_func_timer_info <= 0)
    {
      // leave this function
      LCDML.FUNC_goBackToMenu();
    }
  }

  if (LCDML.FUNC_close())     // ****** STABLE END *********
  {
    // you can here reset some global vars or do nothing
  }
}


// *********************************************************************
uint8_t g_button_value = 0; // button value counter (global variable)
void mFunc_p2(uint8_t param)
// *********************************************************************
{
  if (LCDML.FUNC_setup())         // ****** SETUP *********
  {
    // setup function
    // print lcd content
    // print lcd content
    lcd.setCursor(0, 0);
    lcd.print(F("press left or up"));
    lcd.setCursor(0, 1);
    lcd.print(F("count: 0 of 3"));
    // Reset Button Value
    g_button_value = 0;

    // Disable the screensaver for this function until it is closed
    LCDML.FUNC_disableScreensaver();

  }

  if (LCDML.FUNC_loop())          // ****** LOOP *********
  {
    // the quit button works in every DISP function without any checks; it starts the loop_end function
    if (LCDML.BT_checkAny()) // check if any button is pressed (enter, up, down, left, right)
    {
      if (LCDML.BT_checkLeft() || LCDML.BT_checkUp()) // check if button left is pressed
      {
        LCDML.BT_resetLeft(); // reset the left button
        LCDML.BT_resetUp(); // reset the left button
        g_button_value++;

        // update lcd content
        // update lcd content
        lcd.setCursor(7, 1); // set cursor
        lcd.print(g_button_value); // print change content
      }
    }

    // check if button count is three
    if (g_button_value >= 3) {
      LCDML.FUNC_goBackToMenu();      // leave this function
    }
  }

  if (LCDML.FUNC_close())    // ****** STABLE END *********
  {
    // you can here reset some global vars or do nothing
  }
}



// *********************************************************************
void mFunc_screensaver(uint8_t param)
// *********************************************************************
{
  if (LCDML.FUNC_setup())         // ****** SETUP *********
  {
    // update lcd content
    lcd.setCursor(0, 0); // set cursor
    lcd.print("screensaver"); // print change content
    lcd.setCursor(0, 1); // set cursor
    lcd.print("press any key");
    lcd.setCursor(0, 2); // set cursor
    lcd.print("to leave it");
    LCDML.FUNC_setLoopInterval(100);  // starts a trigger event for the loop function every 100 millisecounds
  }

  if (LCDML.FUNC_loop())
  {
    if (LCDML.BT_checkAny()) // check if any button is pressed (enter, up, down, left, right)
    {
      LCDML.FUNC_goBackToMenu();  // leave this function
    }
  }

  if (LCDML.FUNC_close())
  {
    // The screensaver go to the root menu
    LCDML.MENU_goRoot();
  }
}



// *********************************************************************
void mFunc_back(uint8_t param)
// *********************************************************************
{
  if (LCDML.FUNC_setup())         // ****** SETUP *********
  {
    // end function and go an layer back
    LCDML.FUNC_goBackToMenu(1);      // leave this function and go a layer back
  }
}


// *********************************************************************
void mFunc_goToRootMenu(uint8_t param)
// *********************************************************************
{
  if (LCDML.FUNC_setup())         // ****** SETUP *********
  {
    // go to root and display menu
    LCDML.MENU_goRoot();
  }
}

// *********************************************************************
void mFunc_jumpTo_timer_info(uint8_t param)
// *********************************************************************
{
  if (LCDML.FUNC_setup())         // ****** SETUP *********
  {
    // Jump to Initscreen
    if (!LCDML.OTHER_jumpToFunc(mFunc_timer_info))
    {
      // function not found or not callable
      LCDML.MENU_goRoot();
    }
  }
}


// *********************************************************************
void mFunc_para(uint8_t param)
// *********************************************************************
{
  if (LCDML.FUNC_setup())         // ****** SETUP *********
  {

    char buf[20];
    sprintf (buf, "parameter: %d", param);

    lcd.setCursor(0, 0);
    lcd.print(buf);
    lcd.setCursor(0, 1);
    lcd.print(F("press any key"));
    lcd.setCursor(0, 2);
    lcd.print(F("to leave it"));

    LCDML.FUNC_setLoopInterval(100);  // starts a trigger event for the loop function every 100 millisecounds
  }

  if (LCDML.FUNC_loop())         // ****** LOOP *********
  {
    // For example
    switch (param)
    {
      case 10:
        // do something
        break;

      case 20:
        // do something
        break;

      case 30:
        // do something
        break;

      default:
        // do nothing
        break;
    }


    if (LCDML.BT_checkAny()) // check if any button is pressed (enter, up, down, left, right)
    {
      LCDML.FUNC_goBackToMenu();  // leave this function
    }
  }

  if (LCDML.FUNC_close())       // ****** STABLE END *********
  {
    // you can here reset some global vars or do nothing
  }
}
