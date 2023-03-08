Servo busServoL;
Servo busServoR;


Servo carServoL;
Servo carServoR;


Servo bikeServoL;
Servo bikeServoR;


const int busPinR = ;  // the number of the right Bus pin
const int busPinL = ;  // the number of the left Bus pin
const int carPinR = ;  // the number of the right Carpin
const int carPinL = ;  // the number of the left Car pin
const int bikePinR = ;  // the number of the right Bike pin
const int bikePinL = ;  // the number of the left Bike pin




int busLState, busRState, carLState, carRState, bikePinL, bikePinR= 0; //sets the state of the button associated with either Mater or Doc to be low so it doesn't set the state to high when the electronics doesn't activate when the arduino is started up


//need calculations for equating numDegrees to distance the belt needs to rotate on the scale


void setup() {
 // initialize the pushbutton pin as an input:
 pinMode(docButtonPin, INPUT);
   // initialize the pushbutton pin as an input:
 pinMode(materButtonPin, INPUT);


 docServo.attach(7); // initializes servo for doc
 materServo.attach(6); // initializes servo for mater


}


void loop() {
 // set the cursor to column 0, line 1
 // (note: line 1 is the second row, since counting begins with 0)
 // read the state of the pushbutton value:
 docState = digitalRead(docButtonPin); // this stores what the state of the pin is for doc button and stores it in docState
 materState = digitalRead(materButtonPin); // this stores what the state of the pin is for mater button and stores it in materState
 if (docState == HIGH){ // if the doc button is pressed
   lcd.setCursor(0, 1); // go to the place where the docScore is kept on the lcd screen
   docScore++; // increment the number of votes for Doc Hudson by one
   lcd.print(docScore); // print the new doc score
   delay(250); // wait a quarter of a second
   servoTime = 0; // set the time elapsed to 0
   servoTime = millis(); // start counting the amount of time that has passed and store it onto the servo time
   servoTime5000 = servoTime + 5000; // set a variable equal to the amount of time that has passed and add 5 seconds
   while (servoTime < servoTime5000){ // while the time elapsed is less than 5 seconds
     docServo.write(15); // rotate the doc servo to 15 degrees
     delay(1000); // wait a second
     docServo.write(165); // rotate the doc servo to 165 degrees
     delay(1000); // wait another second
     servoTime = millis(); // update time counter for the servo 
   }


   //reset the scores of mater and doc back to 50
   docScore = 50
   materScore = 50
  
 }
else if (materState == HIGH){ // if the mater button was pressed,
 lcd.setCursor(13, 1); // go to where the mater score is
   materScore++; // increment the mater score by one
   lcd.print(materScore); // print the new mater score onto the lcd display
   delay(250); // wait a quarter of a second
   servoTime = 0; // set the time elapsed to 0
   servoTime = millis(); // start counting the time elapsed and store it in the servoTime variable
   servoTime5000 = servoTime + 5000; // set a variable equal to the amount of time that has passed and add 5 seconds
   while (servoTime < servoTime5000){ // while the time elapsed is less than 5 seconds
     materServo.write(15); // rotate the doc servo to 15 degrees
     delay(1000); // wait a second
     materServo.write(165); // rotate the doc servo to 165 degrees
     delay(1000); // wait another second
     servoTime = millis(); // update time counter for the servo    
   }


   //reset the scores of mater and doc back to 50
   docScore = 50
   materScore = 50
}
 }
