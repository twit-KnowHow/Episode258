// We're going to include a single library to control the PWM output to the servo
#include <Servo.h>

// Now that we have the library, we need to create an object from that library
Servo myservo;

// Let's setup our constants:
#define ServoPin 7      // This is the pin to which the servo data line is connected
#define ServoSpeed 15   // This is the speed at which the servo will turn (lower value = faster)
#define maxPWM 180      // This is the maximum PWM value that can be sent to the servo
#define minPWM 0        // This is the minimum PWM value that can be sent to the servo
#define LEDpin1 8       // LED 1
#define LEDpin2 9       // LED 2

// We want a variable that will store the current PWM value that indicates the servo's position
int servoVal = 0;    // variable to store the servo position

void setup() 
{
  // Configures the object "myservo" to use the data pin defined in "ServoPin"
  myservo.attach(ServoPin);

  // Setting the mode for the pin to which LED1 is connected
  pinMode(LEDpin1, OUTPUT);
  
  // Setting the mode for the pin to which LED2 is connected
  pinMode(LEDpin2, OUTPUT);
}

void loop() 
{
  for (servoVal = minPWM; servoVal <= maxPWM;) 
  { 
    digitalWrite(LEDpin1, HIGH);
    digitalWrite(LEDpin2, LOW);
    myservo.write(servoVal);              // sends the PWM value to the servo that will turn it to the degree position in ServoVal
    servoVal = servoVal+1;                // advance the counter
    delay(ServoSpeed);                    // wait for as many ms as are defined in "ServoSpeed"
  }


  for (servoVal = maxPWM; servoVal >= minPWM;)
  { 
    digitalWrite(LEDpin1, LOW);
    digitalWrite(LEDpin2, HIGH);
    myservo.write(servoVal);              // sends the PWM value to the servo that will turn it to the degree position in ServoVal
    servoVal = servoVal - 1;              // decrement the counter
    delay(ServoSpeed);                    // wait for as many ms as are defined in "ServoSpeed"
  }
}

