#include <Adafruit_Fingerprint.h>
#include <LiquidCrystal.h>
#include<SoftwareSerial.h>
#include <stdint.h>

SoftwareSerial Bluetooth(3,2);                   
#define serialCommunicationSpeed 9600 

const int rs = 14, en = 15, d4 = 16, d5 = 17, d6 = 18, d7 = 19;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int buttonPin1 = 8;     // the number of the pushbutton pin
const int buttonPin2 = 9;     // the number of the pushbutton pin
const int buttonPin3 = 10;     // the number of the pushbutton pin

int RELAY_PIN1 = 6;  //Rice
int RELAY_PIN2 = 7; //Wheat

//// variables will change:
//int buttonState1 = 1;         // variable for reading the pushbutton status
//int buttonState2 = 1;         // variable for reading the pushbutton status
//int buttonState3 = 1;         // variable for reading the pushbutton status


int Rice_state1 = 1;
int Rice_state2 = 2;
int Rice_state3 = 3;
int Rice_state4 = 4;

int Wheat_state1 = 5;
int Wheat_state2 = 6;
int Wheat_state3 = 7;
int Wheat_state4 = 8;

int BT_state = 0;

#if (defined(__AVR__) || defined(ESP8266)) && !defined(__AVR_ATmega2560__)
// For UNO and others without hardware serial, we must use software serial...
// pin #2 is IN from sensor (GREEN wire)
// pin #3 is OUT from arduino  (WHITE wire)
// Set up the serial port to use softwareserial..
SoftwareSerial mySerial(4, 5);

#else
// On Leonardo/M0/etc, others with hardware serial, use hardware serial!
// #0 is green wire, #1 is white
#define mySerial Serial1

#endif


Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void buttonWait(int Fingr_ID){  //int buttonPin
  int buttonState1 = 1;
  int buttonState2 = 1;
  int buttonState3 = 1;
  while(1){
    buttonState1 = digitalRead(buttonPin1);
	buttonState2 = digitalRead(buttonPin2);
	
    if (buttonState1 == LOW && Fingr_ID==1) { //RICE for 1st person
			if (Rice_state1 != 0) {
        Serial.println("Inside Rice_state1");
				lcd.clear();
				lcd.setCursor(0, 0);
				lcd.print("PRESS SWITCH 3");
				lcd.setCursor(0, 1);
				lcd.print("FOR RICE");
//				while(buttonState3 == LOW){
          while(1){
            buttonState3 = digitalRead(buttonPin3);
            if(buttonState3 == LOW){
					digitalWrite(RELAY_PIN1, HIGH);
					delay(4000);
					digitalWrite(RELAY_PIN1, LOW);	
					lcd.clear();
					lcd.setCursor(2, 0);
					lcd.print("RICE QUOTA");
					lcd.setCursor(3, 1);
					lcd.print("COMPLETED");
          Bluetooth.write("RICE QUOTA COMPLETED FOR THIS MONTH");
          Bluetooth.write('\n');
					Rice_state1 = 0;
//					delay(2000);	
          break;
				}			
          }
			}
			else{
				lcd.clear();
				lcd.setCursor(2, 0);
				lcd.print("RICE QUOTA");
				lcd.setCursor(3, 1);
				lcd.print("EXAUSTED");
				Bluetooth.write("RICE QUOTA EXHAUSTED");
        Bluetooth.write('\n');
//          delay(2000);  
          break;  
			}
     break;
	}
    else if (buttonState1 == LOW && Fingr_ID==2) { //RICE for 2nd person
			if (Rice_state2 != 0) {
				lcd.clear();
				lcd.setCursor(1, 0);
				lcd.print("PRESS SWITCH 3");
				lcd.setCursor(0, 1);
				lcd.print("FOR RICE");
//				while(buttonState3 == LOW){
          while(1){
            buttonState3 = digitalRead(buttonPin3);
            if(buttonState3 == LOW){
					digitalWrite(RELAY_PIN1, HIGH);
					delay(4000);
					digitalWrite(RELAY_PIN1, LOW);	
					lcd.clear();
					lcd.setCursor(4, 0);
					lcd.print("RICE QUOTA");
					lcd.setCursor(5, 1);
					lcd.print("COMPLETED");
          Bluetooth.write("RICE QUOTA COMPLETED FOR THIS MONTH");
          Bluetooth.write('\n');
					Rice_state2 = 0;
//          delay(2000);  
          break;	
				}			
          }
			}
			else{
				lcd.clear();
				lcd.setCursor(2, 0);
				lcd.print("RICE QUOTA");
				lcd.setCursor(5, 1);
				lcd.print("EXAUSTED");
        Bluetooth.write("RICE QUOTA EXHAUSTED");
//        delay(2000);  
        break;
			}
     break;
	}
    else if (buttonState1 == LOW && Fingr_ID==3) { //RICE for 3rd person
			if (Rice_state3 != 0) {
				lcd.clear();
				lcd.setCursor(1, 0);
				lcd.print("PRESS SWITCH 3");
				lcd.setCursor(0, 1);
				lcd.print("FOR RICE");
//        while(buttonState3 == LOW){
          while(1){
            buttonState3 = digitalRead(buttonPin3);
            if(buttonState3 == LOW){
					digitalWrite(RELAY_PIN1, HIGH);
					delay(4000);
					digitalWrite(RELAY_PIN1, LOW);	
					lcd.clear();
					lcd.setCursor(4, 0);
					lcd.print("RICE QUOTA");
					lcd.setCursor(5, 1);
					lcd.print("COMPLETED");
          Bluetooth.write("RICE QUOTA COMPLETED FOR THIS MONTH");
          Bluetooth.write('\n');
					Rice_state3 = 0;
//          delay(2000);  
          break;  
				}			
          }
			}
			else{
				lcd.clear();
				lcd.setCursor(2, 0);
				lcd.print("RICE QUOTA");
				lcd.setCursor(3, 1);
				lcd.print("EXAUSTED");
        Bluetooth.write("RICE QUOTA EXHAUSTED");
        Bluetooth.write('\n');
//                  delay(2000);  
          break;  
			}
     break;
	}
    else if (buttonState1 == LOW && Fingr_ID==4) { //RICE for 4th person
			if (Rice_state4 != 0) {
				lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("PRESS SWITCH3");
        lcd.setCursor(0, 1);
        lcd.print("FOR RICE");
//				while(buttonState3 == LOW){
          while(1){
            buttonState3 = digitalRead(buttonPin3);
            if(buttonState3 == LOW){
					digitalWrite(RELAY_PIN1, HIGH);
					delay(4000);
					digitalWrite(RELAY_PIN1, LOW);	
					lcd.clear();
					lcd.setCursor(4, 0);
					lcd.print("RICE QUOTA");
					lcd.setCursor(5, 1);
					lcd.print("COMPLETED");
          Bluetooth.write("RICE QUOTA COMPLETED FOR THIS MONTH");
          Bluetooth.write('\n');
					Rice_state4 = 0;
//          delay(2000);  
          break;  	
				}			
          }
			}
			else{
				lcd.clear();
				lcd.setCursor(2, 0);
				lcd.print("RICE QUOTA");
				lcd.setCursor(3, 1);
				lcd.print("EXAUSTED");
//                  delay(2000);  
          break;  
			}
     break;
	}
    else if (buttonState2 == LOW && Fingr_ID==1) { //Wheat for 1st person
			if (Wheat_state1 != 0) {
				lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("PRESS SWITCH 3");
        lcd.setCursor(0, 1);
        lcd.print("FOR WHEAT");
//				while(buttonState3 == LOW){
          while(1){
            buttonState3 = digitalRead(buttonPin3);
            if(buttonState3 == LOW){
					digitalWrite(RELAY_PIN2, HIGH);
					delay(4000);
					digitalWrite(RELAY_PIN2, LOW);	
					lcd.clear();
					lcd.setCursor(2, 0);
					lcd.print("WHEAT QUOTA");
					lcd.setCursor(5, 1);
					lcd.print("COMPLETED");
          Bluetooth.write("WHEAT QUOTA COMPLETED FOR THIS MONTH");
          Bluetooth.write('\n');
					Wheat_state1 = 0;
//          delay(2000);  
          break;  
				}			
			  
			}
			}
			else{
				lcd.clear();
				lcd.setCursor(2, 0);
				lcd.print("WHEAT QUOTA");
				lcd.setCursor(3, 1);
				lcd.print("EXAUSTED");
        Bluetooth.write("WHEAT QUOTA EXHAUSTED");
        Bluetooth.write('\n');
//                  delay(2000);  
          break;  
			}
     break;
	}
    else if (buttonState2 == LOW && Fingr_ID==2) { //Wheat for 2st person
			if (Wheat_state2 != 0) {
				lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("PRESS SWITCH 3");
        lcd.setCursor(0, 1);
        lcd.print("FOR WHEAT");
//				while(buttonState3 == LOW){
          while(1){
            buttonState3 = digitalRead(buttonPin3);
            if(buttonState3 == LOW){
            
					digitalWrite(RELAY_PIN2, HIGH);
					delay(4000);
					digitalWrite(RELAY_PIN2, LOW);	
					lcd.clear();
					lcd.setCursor(2, 0);
					lcd.print("WHEAT QUOTA");
					lcd.setCursor(5, 1);
					lcd.print("COMPLETED");
          Bluetooth.write("WHEAT QUOTA COMPLETED FOR THIS MONTH");
          Bluetooth.write('\n');
					Wheat_state2 = 0;
//          delay(2000);  
          break;  
				}
          }			
			  
			}
			else{
				lcd.clear();
				lcd.setCursor(2, 0);
				lcd.print("WHEAT QUOTA");
				lcd.setCursor(3, 1);
				lcd.print("EXAUSTED");
        Bluetooth.write("WHEAT QUOTA EXHAUSTED");
        Bluetooth.write('\n');
                  //delay(2000);  
          break;  
			}
     break;
	}
			
	    else if (buttonState2 == LOW && Fingr_ID==3) { //Wheat for 3rd person
  			if (Wheat_state3 != 0) {
  				lcd.clear();
  				lcd.setCursor(1, 0);
  				lcd.print("PRESS SWITCH 3");
  				lcd.setCursor(0, 1);
  				lcd.print("FOR WHEAT");
//        while(buttonState3 == LOW){
          while(1){
            buttonState3 = digitalRead(buttonPin3);
            if(buttonState3 == LOW){
    					digitalWrite(RELAY_PIN2, HIGH);
    					delay(4000);
    					digitalWrite(RELAY_PIN2, LOW);	
    					lcd.clear();
    					lcd.setCursor(2, 0);
    					lcd.print("WHEAT QUOTA");
    					lcd.setCursor(5, 1);
    					lcd.print("COMPLETED");
              Bluetooth.write("WHEAT QUOTA COMPLETED FOR THIS MONTH");
              Bluetooth.write('\n');
    					Wheat_state3 = 0;
//          delay(2000);  
          break;  	
    				}
  			}
  			}
  			else{
  				lcd.clear();
  				lcd.setCursor(2, 0);
  				lcd.print("WHEAT QUOTA");
  				lcd.setCursor(3, 1);
  				lcd.print("EXAUSTED");
          Bluetooth.write("WHEAT QUOTA EXHAUSTED");
          Bluetooth.write('\n');
//                    delay(2000);  
          break;  
  			}			
     break;
    }
	    else if (buttonState2 == LOW && Fingr_ID==4) { //Wheat for 4th person
  		if (Wheat_state4 != 0) { //Wheat for 4th person	
  			lcd.clear();
  			lcd.setCursor(1, 0);
  			lcd.print("PRESS SWITCH 3");
  			lcd.setCursor(0, 1);
  			lcd.print("FOR WHEAT");
//        while(buttonState3 == LOW){
          while(1){
            buttonState3 = digitalRead(buttonPin3);
            if(buttonState3 == LOW){

      				digitalWrite(RELAY_PIN2, HIGH);
      				delay(4000);
      				digitalWrite(RELAY_PIN2, LOW);	
      				lcd.clear();
      				lcd.setCursor(2, 0);
      				lcd.print("WHEAT QUOTA");
      				lcd.setCursor(5, 1);
      				lcd.print("COMPLETED");
              Bluetooth.write("WHEAT QUOTA COMPLETED FOR THIS MONTH");
              Bluetooth.write('\n');
      				Wheat_state4 = 0;
      				delay(3000);	
//                        delay(2000);  
               break;  
      			}			
          }
      }
  		else{
  			lcd.clear();
  			lcd.setCursor(2, 0);
  			lcd.print("WHEAT QUOTA");
  			lcd.setCursor(3, 1);
  			lcd.print("EXAUSTED");
        Bluetooth.write("WHEAT QUOTA EXHAUSTED");
        Bluetooth.write('\n');
//                  delay(2000);  
          break;  
  		}
	break;
  }
  
  }
}


void setup()
{
  //send to LCD
  lcd.begin(16, 2);
  //send to LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("RATION DISPENSOR");
  lcd.setCursor(5, 1);
  lcd.print("PROJECT");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("PAIR/CONNECT TO");
  lcd.setCursor(1, 1);
  lcd.print("BLUETOOTH");
  delay(3000);
  Serial.begin(9600);
  while (!Serial);  // For Yun/Leo/Micro/Zero/...
  delay(100);
  Serial.println("\n\nAdafruit finger detect test");
  Bluetooth.begin(9600);
   delay(5);

  // set the data rate for the sensor serial port
  finger.begin(57600);
  delay(5);
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }

  pinMode(RELAY_PIN1, OUTPUT);
  digitalWrite(RELAY_PIN1, LOW);   //Switch off relay initially. Relay is LOW level triggered relay so we need to write HIGH.
  pinMode(RELAY_PIN2, OUTPUT);
  digitalWrite(RELAY_PIN2, LOW);   //Switch off relay initially. Relay is LOW level triggered relay so we need to write HIGH.

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT); 
  pinMode(buttonPin2, INPUT); 
  pinMode(buttonPin3, INPUT); 

  //-------------- read the state of the pushbutton value:--------------------
//  buttonState = digitalRead(buttonPin);

  Serial.println(F("Reading sensor parameters"));
  finger.getParameters();
  Serial.print(F("Status: 0x")); Serial.println(finger.status_reg, HEX);
  Serial.print(F("Sys ID: 0x")); Serial.println(finger.system_id, HEX);
  Serial.print(F("Capacity: ")); Serial.println(finger.capacity);
  Serial.print(F("Security level: ")); Serial.println(finger.security_level);
  Serial.print(F("Device address: ")); Serial.println(finger.device_addr, HEX);
  Serial.print(F("Packet len: ")); Serial.println(finger.packet_len);
  Serial.print(F("Baud rate: ")); Serial.println(finger.baud_rate);

  finger.getTemplateCount();

  if (finger.templateCount == 0) {
    Serial.print("Sensor doesn't contain any fingerprint data. Please run the 'enroll' example.");
  }
  else {
    Serial.println("Waiting for valid finger...");
      Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
  }
}

void loop()                     // run over and over again
{
//  if(Bluetooth.available() > 0){ // Checks whether data is comming from the serial port
//    BT_state = Bluetooth.read(); // Reads the data from the serial port
//    Serial.println(BT_state);
// }
//
// if (BT_state == '1') {
//  while(1){
//	getFingerprintID();		
//	BT_state = 0;
//  }
// }
// else if (BT_state == '2') {
//  while(1){
//  getFingerprintID();   
//  BT_state = 0;
//  }
// } 
// else if (BT_state == '3') {
//  while(1){
//  getFingerprintID();   
//  BT_state = 0;
//  }
// } 
// else if (BT_state == '4') {
//  while(1){
//  getFingerprintID();   
//  BT_state = 0;
//  }
// } 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("PAIR/CONNECT TO");
  lcd.setCursor(0, 1);
  lcd.print("BLUETOOTH");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("PLACE FINGER");
  lcd.setCursor(0, 1);
  lcd.print("TO SCAN");
  delay(3000);
  getFingerprintID();
  delay(50);            //don't ned to run this at full speed.
}

uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK converted!
  p = finger.fingerSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }

  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  if(finger.fingerID == 1)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ACCESS GRANTED");
    lcd.setCursor(0, 1);
    lcd.print("Hi ADARSH");
	delay(4000);
	lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SWITCH 1 : RICE");
    lcd.setCursor(0, 1);
    lcd.print("SWITCH 2 : WHEAT");
	delay(1000);
	buttonWait(1);

  }
	

  if(finger.fingerID == 2)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ACCESS GRANTED");
    lcd.setCursor(0, 1);
    lcd.print("Hi JAHNAVI");
	  delay(4000);
	  lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SWITCH 1 : RICE");
    lcd.setCursor(0, 1);
    lcd.print("SWITCH 2 : WHEAT");
	  delay(1000);
	  buttonWait(2);

  }
  if(finger.fingerID == 3)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ACCESS GRANTED");
    lcd.setCursor(0, 1);
    lcd.print("Hi AMULYA");
	delay(4000);
	lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SWITCH 1 : RICE");
    lcd.setCursor(0, 1);
    lcd.print("SWITCH 2 : WHEAT");
	delay(1000);
	buttonWait(3);

  }
   if(finger.fingerID == 4)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ACCESS GRANTED");
    lcd.setCursor(0, 1);
    lcd.print("Hi ANEES");
	delay(4000);
	lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SWITCH 1 : RICE");
    lcd.setCursor(0, 1);
    lcd.print("SWITCH 2 : WHEAT");
	delay(1000);
	buttonWait(4);

  }

  return finger.fingerID;
}


// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;

  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID;
}
