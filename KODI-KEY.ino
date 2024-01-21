#include <BleKeyboard.h>


//Disable LEDENABLE to remove LED-support
#define LEDENABLE 1

#define LONGTIME 500
#define LONGTIME2 1000
#define LONGTIME3 2000

#define SLEEPTIME 3L*60L*1000L //3 Minute to go to DeepSleep

// 12 Keys and the Ports
#define KEY1 32
#define KEY2 33
#define KEY3 25
#define KEY4 26
#define KEY5 27
#define KEY6 14
#define KEY7 12
#define KEY8 13
#define KEY9 15
#define KEYA 16
#define KEYB 17
#define KEYC 5

// What Key whith what Key-Number
#define CKVOLUP KEY1
#define CKRIGHT KEY2
#define CKSTOP KEY3
#define CKC KEY4
#define CKUP KEY5
#define CKRETURN KEY6
#define CKDOWN KEY7
#define CKTAB KEY8
#define CKVOLDOWN KEY9
#define CKLEFT KEYA
#define CKBACK KEYB
#define CKM KEYC

// Port for LED (if enabled)
#define LED 18

BleKeyboard bleKeyboard("KODI-KEY","TUTORIUS",100);
int old,old2;
int isstop,isenter,isvolup,isvoldown,isback;
int isleftarrow,isrightarrow,isuparrow,isdownarrow;
unsigned long millibilli;
unsigned long sleepibilli;
unsigned long difibilli;
char s[80];
int printflag=true;
int i;

void setup()
{
  #ifdef SER
  Serial.begin(115200);
  #endif
  pinMode(KEY1,INPUT_PULLUP);
  pinMode(KEY2,INPUT_PULLUP);
  pinMode(KEY3,INPUT_PULLUP);
  pinMode(KEY4,INPUT_PULLUP);
  pinMode(KEY5,INPUT_PULLUP);
  pinMode(KEY6,INPUT_PULLUP);
  pinMode(KEY7,INPUT_PULLUP);
  pinMode(KEY8,INPUT_PULLUP);
  pinMode(KEY9,INPUT_PULLUP);
  pinMode(KEYA,INPUT_PULLUP);
  pinMode(KEYB,INPUT_PULLUP);
  pinMode(KEYC,INPUT_PULLUP);

#ifdef LEDENABLE
  pinMode(LED,OUTPUT);
#endif

  bleKeyboard.begin();
  old=true;
  isstop=0;isenter=0;isback=0;isvoldown=0;isvolup=0;
  isrightarrow=0;isleftarrow=0;isuparrow=0;isdownarrow=0;

  esp_sleep_enable_ext0_wakeup(GPIO_NUM_14,0);
  sleepibilli=millis();
  digitalWrite(LED,true);
  delay(1000);
}

void loop()
{
  difibilli=millis()-sleepibilli;
  switch(difibilli/1000L/60L)
  {
    case 0:
      digitalWrite(LED,((difibilli/120L)%32L==0)&&(difibilli%16L==0)); break;
    case 1:
      digitalWrite(LED,((difibilli/60L)%32L==0)&&(difibilli%16L==0)); break;
    case 2:
    default:
      digitalWrite(LED,((difibilli/30L)%32L==0)&&(difibilli%16L==0)); break;
  }
  if(bleKeyboard.isConnected())
  {
    if ((!digitalRead(CKLEFT))&old)
    {
      old=false;
      millibilli=millis(); sleepibilli=millibilli;
      isstop=0;
      isenter=0;
      isback=0;
      isvolup=0;
      isvoldown=0;
      isleftarrow=1;
      isrightarrow=0;
      isuparrow=0;
      isdownarrow=0;
    }
    if ((!digitalRead(CKRIGHT))&old)
    {
      old=false;
      millibilli=millis(); sleepibilli=millibilli;
      isstop=0;
      isenter=0;
      isback=0;
      isvolup=0;
      isvoldown=0;
      isleftarrow=0;
      isrightarrow=1;
      isuparrow=0;
      isdownarrow=0;
    }
    if ((!digitalRead(CKUP))&&old)
    {
      // bleKeyboard.write(KEY_UP_ARROW);
      old=false;
      millibilli=millis(); sleepibilli=millibilli;
      isstop=0;
      isenter=0;
      isback=0;
      isvolup=0;
      isvoldown=0;
      isleftarrow=0;
      isrightarrow=0;
      isuparrow=true;
      isdownarrow=false;
    }
    if ((!digitalRead(CKDOWN))&&old)
    {
      //bleKeyboard.write(KEY_DOWN_ARROW);
      old=false;
      millibilli=millis(); sleepibilli=millibilli;
      isstop=0;
      isenter=0;
      isback=0;
      isvolup=0;
      isvoldown=0;
      isleftarrow=0;
      isrightarrow=0;
      isuparrow=0;
      isdownarrow=true;
    }
    if ((!digitalRead(CKBACK))&&old)
    {
      isback=true;
//      bleKeyboard.write(KEY_BACKSPACE);
      old=false;
      millibilli=millis(); sleepibilli=millibilli;
      isstop=0;
      isenter=0;
      isvolup=0;
      isvoldown=0;
      isleftarrow=0;
      isrightarrow=0;
      isuparrow=0;
      isdownarrow=0;
    }
    if ((!digitalRead(CKRETURN))&&old)
    {
//      bleKeyboard.write(KEY_RETURN);
      isenter=1;
      old=false;
      millibilli=millis(); sleepibilli=millibilli;
      isstop=0;
      isback=0;
      isvolup=0;
      isvoldown=0;
      isleftarrow=0;
      isrightarrow=0;
      isuparrow=0;
      isdownarrow=0;
    }
    if ((!digitalRead(CKVOLUP))&&old)
    {
      old=false;
//      bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
      millibilli=millis(); sleepibilli=millibilli;
      isstop=0;
      isenter=0;
      isback=0;
      isvolup=1;
      isvoldown=0;
      isleftarrow=0;
      isrightarrow=0;
      isuparrow=0;
      isdownarrow=0;
    }
    if ((!digitalRead(CKVOLDOWN))&&old)
    {
//      bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
      old=false;
      millibilli=millis(); sleepibilli=millibilli;
      isstop=0;
      isenter=0;
      isback=0;
      isvolup=0;
      isvoldown=1;
      isleftarrow=0;
      isrightarrow=0;
      isuparrow=0;
      isdownarrow=0;
    }
    if ((!digitalRead(CKSTOP))&&old)
    {
 //     bleKeyboard.write('x');
      old=false;
      millibilli=millis(); sleepibilli=millibilli;
      isstop=1;
      isenter=0;
      isback=0;
      isvolup=0;
      isvoldown=0;
      isleftarrow=0;
      isrightarrow=0;
      isuparrow=0;
      isdownarrow=0;
    }
    if ((!digitalRead(CKM))&&old)
    {
      old=false;
      bleKeyboard.write('m');
      millibilli=millis(); sleepibilli=millibilli;
      isstop=0;
      isenter=0;
      isback=0;
      isvolup=0;
      isvoldown=0;
      isleftarrow=0;
      isrightarrow=0;
      isuparrow=0;
      isdownarrow=0;
    }
    if ((!digitalRead(CKC))&&old)
    {
      old=false;
      bleKeyboard.write('c');
      millibilli=millis(); sleepibilli=millibilli;
      isstop=0;
      isenter=0;
      isback=0;
      isvolup=0;
      isvoldown=0;
      isleftarrow=0;
      isrightarrow=0;
      isuparrow=0;
      isdownarrow=0;
    }
    if ((!digitalRead(CKTAB))&&old)
    {
      old=false;
      bleKeyboard.write(KEY_TAB);
      millibilli=millis(); sleepibilli=millibilli;
      isstop=0;
      isenter=0;
      isback=0;
      isvolup=0;
      isvoldown=0;
      isleftarrow=0;
      isrightarrow=0;
      isuparrow=0;
      isdownarrow=0;
    }
    if (isstop==1)
    {
      if (millis()-millibilli>LONGTIME)
      {
        bleKeyboard.write(KEY_MEDIA_STOP);
        isstop++;
      }
    }
    if (isenter==1)
    {
      if (millis()-millibilli>LONGTIME)
      {
        bleKeyboard.write('i');
        isenter++;
      }
    }
    if (isvolup==1)
    {
      if (millis()-millibilli>LONGTIME)
      {
        bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
        isvolup=0; old=true;
        millibilli=millis();
      }
    }
    if (isvoldown==1)
    {
      if (millis()-millibilli>LONGTIME)
      {
        bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
        isvoldown=0; old=true;
        millibilli=millis();
      }
    }
    if (isleftarrow==1)
    {
      if (millis()-millibilli>LONGTIME)
      {
        bleKeyboard.write('r');
        isleftarrow++;
      }
    }
    if (isrightarrow==1)
    {
      if (millis()-millibilli>LONGTIME)
      {
        bleKeyboard.write('f');
        isrightarrow++;
      }
    }
    if (isuparrow==1)
    {
      if (millis()-millibilli>LONGTIME)
      {
        bleKeyboard.write('y');
        isuparrow++;
      }
    }
    if (isdownarrow==1)
    {
      if (millis()-millibilli>LONGTIME)
      {
        bleKeyboard.write('o');
        isdownarrow++;
      }
    }
    if (digitalRead(KEY1)&&digitalRead(KEY2)&&digitalRead(KEY3)&&digitalRead(KEY4)&&digitalRead(KEY5)&&digitalRead(KEY6)
  &&digitalRead(KEY7)&&digitalRead(KEY8)&&digitalRead(KEY9)&&digitalRead(KEYA)&&digitalRead(KEYB)&&digitalRead(KEYC))
    {
      if (isleftarrow==1)
      {
        bleKeyboard.write(KEY_LEFT_ARROW);
      }
      if (isrightarrow==1)
      {
        bleKeyboard.write(KEY_RIGHT_ARROW);
      }
      if (isuparrow==1)
      {
        bleKeyboard.write(KEY_UP_ARROW);
      }
      if (isdownarrow==1)
      {
        bleKeyboard.write(KEY_DOWN_ARROW);
      }
      if (isstop==1)
      {
        bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
      }
      if (isenter==1)
      {
        bleKeyboard.write(KEY_RETURN);
      }
      if (isback==1)
      {
        bleKeyboard.write(KEY_BACKSPACE);
      }
      if ((isvolup==1)||(isvoldown==1))
      {
        if (isvoldown==1)
        {
          bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
        }
        else
        {
          bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
        }
      }
      old=true;
      isvolup=isvoldown=isuparrow=isdownarrow=isleftarrow=isrightarrow=0;
      isenter=isstop=isback=0;
    }
    /*if (!old)
      delay(50);
    else
      delay(10);
    */
  }
  if (millis()-sleepibilli>=SLEEPTIME)
  {
    esp_deep_sleep_start();
  }
}
