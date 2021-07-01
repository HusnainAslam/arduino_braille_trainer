const char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
const int seq[] = {1, 13, 12, 124, 14, 123, 1234, 134, 23, 234, 15, 135, 125, 1245, 145, 1235, 12345, 1345, 235, 2345, 156, 1356, 2346, 1256, 12456, 1456}; 
const int len[] = {1, 2, 2, 3, 2, 3, 4, 3, 2, 3, 2, 3, 3, 4, 3, 4, 5, 4, 3, 4, 3, 4, 4, 4, 5, 4};
int keyPressed[5] = {9, 9, 9, 9, 9};
int currLen = 0;
int rndm = 0;
int score = 0;


// constants won't change. They're used here to set pin numbers:
const int buttonPin1 = 2;     // the number of the pushbutton pin
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const int buttonPin4 = 5;
const int buttonPin5 = 6;
const int buttonPin6= 7;
const int ledPin = 13;

// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;
int buttonState6 = 0;


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
  Serial.begin(9600);
  randomSeed(analogRead(0));
  rndm = random(26);

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  pinMode(buttonPin6, INPUT);
  Serial.println(alphabet[rndm]);
}


void loop()
{

  static bool btnNotPressed = true;
  static int sqval = 0;
  
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  buttonState5 = digitalRead(buttonPin5);
  buttonState6 = digitalRead(buttonPin6);
  
  if ((buttonState1 == HIGH || buttonState2 == HIGH || buttonState3 == HIGH || buttonState4 == HIGH || buttonState5 == HIGH || buttonState6 == HIGH) && btnNotPressed && len[rndm] > currLen) //button press?
  {
    
//  Serial.println(buttonState1);
//  Serial.println(buttonState2);
//  Serial.println(buttonState3);
//  Serial.println(buttonState4);
//  Serial.println(buttonState5);
//  Serial.println(buttonState6);
    btnNotPressed = false;
    digitalWrite(ledPin, HIGH);
    delay(300);
    digitalWrite(ledPin, LOW);
      if(buttonState1){
            keyPressed[currLen] = 1;
            currLen++;
        }
      else if(buttonState2){
            keyPressed[currLen] = 2;
            currLen++;
        }
      else if(buttonState3){
            keyPressed[currLen] = 3;
            currLen++;
        }
      else if(buttonState4){
            keyPressed[currLen] = 4;
            currLen++;
        }
      else if(buttonState5){
            keyPressed[currLen] = 5;
            currLen++;
        }
      else if(buttonState6){
            keyPressed[currLen] = 6;
            currLen++;
        }
    }
  if (buttonState1 == 0 && buttonState2 == 0 && buttonState3 == 0 && buttonState4 == 0 && buttonState5 == 0 && buttonState6 == 0)
  {
    btnNotPressed = true;
  }
    
  if (len[rndm] == currLen){
      sort(keyPressed, currLen);
      for(int i=0; i < currLen; i++){
          sqval = sqval * 10 + keyPressed[i];
        }
        if(sqval == seq[rndm]){
          score += 10;
          Serial.print("Score: ");
          Serial.println(score);
          }
        else{ 
          Serial.println("End");
          Serial.print("Score: ");
          Serial.println(score);
          score = 0;
          delay(3000);
          for(int k=0; k<3; k++){
            digitalWrite(ledPin, HIGH);
            delay(300);
            digitalWrite(ledPin, LOW);
            delay(300);
            }
          Serial.println();
          Serial.println("Start...");
          }
      sqval = 0;
      currLen = 0;
      rndm = random(26);
      Serial.println(alphabet[rndm]); 
    }
}
