// Quiz Plus) screamGo 퀴즈의 캐릭터를 소리감지가 아니라 블루투스로 연결

#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int blueTx=2;
int blueRx=3;
// 
SoftwareSerial bluetooth(2, 3); // 3번 TX, 2번 RX

int xStart;
int yStart;

int temp;

void setup() {
  bluetooth.begin(9600);
  xStart = 0;
  yStart = 0;
  lcd.begin();
  lcd.backlight();
  temp = 0;
}

void loop() {
  lcd.clear();
  lcd.home();
  // 아두이노에서 온 값을 읽음
  char val = bluetooth.read();

  if (bluetooth.available()) {
    Serial.write(bluetooth.read());
  }

  if (val == 'f'){
    if(temp == 0){
      temp = 1;  
    } else if (temp==1){
      temp =0;
    }
  }
  

  if (temp == 1)
  {
    
    if( val == 'a')
    {
      xStart=xStart-3;
    }

    if(val == 'b')
    {
      yStart=yStart+1;
    }
  
    if(val == 'c')
    {
      xStart=xStart+3;
    }

    if(val == 'd')
    {
      yStart=yStart-1;
    }
  
    lcd.setCursor(xStart,yStart);
    lcd.print("(-_-)");
    delay(300);
  
    if(val == 'e')
    {
      int fireX = xStart+4;
      int fireY = yStart;
    
      for (int i=xStart+4; i<16; i++) {
        lcd.clear();
        lcd.setCursor(xStart,yStart);
        lcd.print(")--(");
        lcd.setCursor(fireX,0);
        lcd.print("**");  
        lcd.setCursor(fireX,1);
        lcd.print("**");            
        fireX++;
        delay(150);
    }
  }
}


  if(temp==0){

     lcd.setCursor(xStart,yStart);
     lcd.print("(^^)");
     delay(300);
    
      if(val == 'a')
      {
        xStart--;
      }
    
      if(val == 'b')
      {
        yStart++;
      }
      
      if(val == 'c')
      {
        xStart++;
      }
    
      if(val == 'd')
      {
        yStart--;
      }
    
      
      if( val == 'e')
      {
        int fireX = xStart+4;
        int fireY = yStart;
        
        for (int i=xStart+4; i<16; i++) {
          lcd.clear();
          lcd.setCursor(xStart,yStart);
          lcd.print("(^^)");
          lcd.setCursor(fireX,fireY);
          lcd.print("*");
          fireX++;
          delay(150);
        }
      }
   }

  
}
