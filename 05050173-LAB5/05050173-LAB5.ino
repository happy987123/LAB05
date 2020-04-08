#include<Keypad.h>
//--------------------------------------
byte ledPins[]={12,13,14,15,16,17,6};   //abcdefg  com-7
byte num[10]={
  B0111111,//0   GFEDCBA
  B0000110,//1
  B1011011,//2
  B1001111,//3
  B1100110,//4
  B1101101,//5
  B1111101,//6
  B0000111,//7
  B1111111,//8
  B1101111 //9 
 };
//----------------------------------------

const byte Rows = 4;//|a
const byte Cols = 4;//|C

// Value
char keys[Rows][Cols] = {
  {'F','E','D','C'},
  {'B','3','6','9'},
  {'A','2','5','8'},
  {'0','1','4','7'}
};
//Pins
byte rowPins[Rows] = {5,4,3,2};
byte colPins[Cols]= {11,10,9,8};
//make object
Keypad keypad = 
Keypad(makeKeymap(keys),rowPins,colPins,Rows,Cols);

//-----------------------------------------------------

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7,OUTPUT);
  int i;
  for(i=0;i<8;i++)
    pinMode(ledPins[i],OUTPUT);  
}
void loop() {
  // put your main code here, to run repeatedly:
   
   char  k=keypad.getKey();
   if(k!=NO_KEY){
      int Value=k-48,i;
      Serial.println(k);
      
      for(i=0;i<7;i++){
        if(bitRead(num[Value],i))
          digitalWrite(ledPins[i],1);  
        else
          digitalWrite(ledPins[i],0);
      } 
   } 
}
