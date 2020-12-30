#include "Adafruit_Thermal.h"
#include "z.h"


#include "SoftwareSerial.h"
#define TX_PIN 6 // Arduino transmit  YELLOW WIRE  labeled RX on printer
#define RX_PIN 5 // Arduino receive   GREEN WIRE   labeled TX on printer

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Declare SoftwareSerial obj first
Adafruit_Thermal printer(&mySerial);     // Pass addr to printer constructor

int curs=0,curv=0;
int maxScenes=12, maxVersions=6;
const int btn = 2; 
int buttonState = 0;  
bool printing;

void setup() {

  pinMode(7, OUTPUT); digitalWrite(7, LOW);
  pinMode(btn,INPUT);
  mySerial.begin(19200);  // Initialize SoftwareSerial
  printer.begin();        // Init printer (same regardless of serial type)
  printer.justify('L');  // Set text justification (right, center, left) -- accepts 'L', 'C', 'R'
  printer.sleep();      // Tell printer to sleep
}

void loop() {
  if (curs==0){
    printer.wake(); 
    printer.doubleHeightOn();
    printer.println(F("An upated report on your case  is now available!"));
    printer.println(F("   "));
    printer.doubleHeightOff();
  }
  else if(curs>0&&curs<=maxScenes){
      curv=ceil(random(0,maxVersions-1));
      printScene(curs,curv);
      printer.println(F("   "));
  }else{
       printer.sleep();
          buttonState = digitalRead(btn);
         if (buttonState == HIGH) {
          curs=-1;
          }
  }  
curs++;
}

void printScene(int s, int v){
  // print a different text according to scene number (s) and version number (v) using the function  printer.println(F("your_text"));
} 
