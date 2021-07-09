#include <MI0283QT2.h>

//Declare only one display !
 MI0283QT2 lcd;  //MI0283QT2 Adapter v1


const char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
const int seq[] = {1, 13, 12, 124, 14, 123, 1234, 134, 23, 234, 15, 135, 125, 1245, 145, 1235, 12345, 1345, 235, 2345, 156, 1356, 2346, 1256, 12456, 1456}; 
const int len[] = {1, 2, 2, 3, 2, 3, 4, 3, 2, 3, 2, 3, 3, 4, 3, 4, 5, 4, 3, 4, 3, 4, 4, 4, 5, 4};
int keyPressed[5] = {9, 9, 9, 9, 9};
int currLen = 0;

long rndm = 0;
int score = 0;


int* sort(int *arr, int s){
  int temp;
  for(int i=0; i<s; i++)
    {
        for(int j=i+1; j<s; j++)
        {
            //If there is a smaller element found on right of the array then swap it.
            if(arr[j] < arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
   return arr;
  }
  

void setup()
{
//  Serial.begin(9600);
  
  //init display
  lcd.begin();
  lcd.fillScreen(RGB(255,255,255));
  lcd.drawText(50, 100, "Welcome ", RGB(255,0,0), RGB(255,255,255), 4);
  delay(1000);
  randomSeed(analogRead(0));
  rndm = random(26);
  
  lcd.touchRead();
//  Serial.print("\nTouchX: ");
//  Serial.print(lcd.touchX());
//  Serial.print("\nTouchY: ");
//  Serial.print(lcd.touchY());
//  Serial.print("\nTouchZ: ");
//  Serial.print(lcd.touchZ());
  if(lcd.touchZ())
  {
    lcd.touchStartCal(); //calibrate touchpanel
  }

  //clear screen
  lcd.fillScreen(RGB(255,255,255));

  lcd.drawText(2, 10, "Score    ", RGB(255,0,0), RGB(255,255,255), 1);
  lcd.drawInteger(50, 10, score, DEC, RGB(255,0,0), RGB(255,255,255), 1);
  
  lcd.fillRect(160,10,70,70,RGB(51, 153, 102));
  lcd.drawRect(161,11,68,68,RGB( 0, 0, 0));

  lcd.fillRect(235,10,70,70,RGB(102, 255, 153));
  lcd.drawRect(236,11,68,68,RGB( 0, 0, 0));

  lcd.fillRect(160, 85,70,70,RGB(51, 102, 100));
  lcd.drawRect(161,86,68,68,RGB( 0, 0, 0));

  lcd.fillRect(235, 85,70,70,RGB(0, 51, 150));
  lcd.drawRect(236,86,68,68,RGB( 0, 0, 0));

  lcd.fillRect(160,160,70,70,RGB(255, 204, 0));
  lcd.drawRect(161,161,68,68,RGB( 0, 0, 0));

  lcd.fillRect(235,160,70,70,RGB(255, 60, 60));
  lcd.drawRect(236,161,68,68,RGB( 0, 0, 0));

   lcd.drawChar(20, 50, alphabet[rndm], RGB(255,0,0), RGB(255,255,255), 15);
}


void loop()
{

  static unsigned long m;
  static long prevMillis=0;
  static bool notPressed = true;
  static int sqval = 0;

  lcd.touchRead();

  
  if(lcd.touchZ() && notPressed && len[rndm] > currLen) //touch press?
  {
    
//  Serial.print("\nTouchX: ");
//  Serial.print(lcd.touchX());
//  Serial.print("\nTouchY: ");
//  Serial.print(lcd.touchY());
//  Serial.print("\nTouchZ: ");
//  Serial.println(lcd.touchZ());
    notPressed = false;

    m = millis();
    if((m - prevMillis) > 200) //change only every 800ms
    {
        prevMillis = m;
        lcd.led(30);
        delay(8);
        lcd.led(100);
      if((lcd.tp_x > 770 &&  lcd.tp_x < 865) && (lcd.tp_y > 50 &&  lcd.tp_y < 170)){
            keyPressed[currLen] = 1;
            currLen++;
        }
      else if((lcd.tp_x > 880 &&  lcd.tp_x < 970) && (lcd.tp_y > 50 &&  lcd.tp_y < 170)){
            keyPressed[currLen] = 2;
            currLen++;
        }
      else if((lcd.tp_x > 770 &&  lcd.tp_x < 865) && (lcd.tp_y > 200 &&  lcd.tp_y < 320)){
            keyPressed[currLen] = 3;
            currLen++;
        }
      else if((lcd.tp_x > 880 &&  lcd.tp_x < 970) && (lcd.tp_y > 200 &&  lcd.tp_y < 320)){
            keyPressed[currLen] = 4;
            currLen++;
        }
      else if((lcd.tp_x > 770 &&  lcd.tp_x < 865) && (lcd.tp_y > 330 &&  lcd.tp_y < 450)){
            keyPressed[currLen] = 5;
            currLen++;
        }
      else if((lcd.tp_x > 880 &&  lcd.tp_x < 970) && (lcd.tp_y > 330 &&  lcd.tp_y < 450)){
            keyPressed[currLen] = 6;
            currLen++;
        }
      }
    }
  if (lcd.touchZ()==0) {
    notPressed = true;  
    }
    
  if (len[rndm] == currLen){
    sort(keyPressed, currLen);
    for(int i=0; i < currLen; i++){
        sqval = sqval * 10 + keyPressed[i];
      }
      if(sqval == seq[rndm]){
        score += 10;
        lcd.drawInteger(50, 10, score, DEC, RGB(255,0,0), RGB(255,255,255), 1);
        }
      else{
        lcd.drawChar(20, 50, ' ', RGB(255,0,0), RGB(255,255,255), 15);
        lcd.drawText(50, 10, "     ", RGB(255,0,0), RGB(255,255,255), 1);
        lcd.drawText(20, 50, "End", RGB(255,0,0), RGB(255,255,255), 5);
        lcd.drawInteger(20, 100, score, DEC, RGB(255,0,0), RGB(255,255,255), 5);
        score = 0;
        delay(3000);
        for(int k=0; k<3; k++){
          lcd.led(10);
          delay(300);
          lcd.led(100);
          delay(300);
          }
          lcd.drawInteger(50, 10, score, DEC, RGB(255,0,0), RGB(255,255,255), 1);
        }
    sqval = 0;
    currLen = 0;
    rndm = random(26);
    lcd.drawChar(20, 50, alphabet[rndm], RGB(255,0,0), RGB(255,255,255), 15);  
    }
}
