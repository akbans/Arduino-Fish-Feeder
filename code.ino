#include <Wire.h>
#include <RTClib.h>
#include <Servo.h>

// Create RTC and Servo objects
RTC_DS3231 rtc; // Real-Time Clock object
Servo myServo;  // Servo motor object

// Define LED and Servo pins
const int ledPin = 9;       // LED connected to pin 9
const int servoPin = 10;    // Servo signal connected to pin 10

// Define the target activation time
const int targetHour = 8;   // Hour for activation (24-hour format)
const int targetMinute = 30; // Minute for activation
const int targetSecond = 0;  // Second for activation

// Initialize state variables
bool actionPerformed = false; // To track if the action was performed

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  Serial.println("Initializing system...");

  // Attach servo motor to the defined pin
  myServo.attach(servoPin);
  Serial.println("Servo attached to pin " + String(servoPin));

  // Initialize the RTC module
  if (!rtc.begin()) {
    Serial.println("RTC module not found! Please check connections.");
    while (1); // Halt the program if RTC is not detected
  }

  // Check if the RTC is running
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, setting the time...");
    // Set the RTC to the time when the sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  // Set LED pin mode to output
  pinMode(ledPin, OUTPUT);
  Serial.println("LED pin set to output mode.");
}

void loop() {
  // Fetch the current time from the RTC module
  DateTime now = rtc.now();

  // Print current time to the Serial Monitor
  Serial.print("Current Time: ");
  Serial.print(now.hour());
  Serial.print(":");
  Serial.print(now.minute());
  Serial.print(":");
  Serial.println(now.second());

  // Check if the current time matches the target time
  if (now.hour() == targetHour && now.minute() == targetMinute && now.second() == targetSecond && !actionPerformed) {
    // Perform the action if the time matches
    activateServoAndLED();
    actionPerformed = true; // Mark the action as performed
  }

  // Reset the actionPerformed flag if the time moves past the target second
  if (now.second() != targetSecond) {
    actionPerformed = false;
  }

  // Add a short delay to prevent excessive polling
  delay(500); // 500ms delay for smoother operation
}

// Function to activate the servo and LED
void activateServoAndLED() {
  Serial.println("Target time reached. Activating servo and LED...");

  // Turn on the LED
  digitalWrite(ledPin, HIGH);
  Serial.println("LED turned ON.");

  // Rotate the servo motor to 180 degrees
  myServo.write(180);
  Serial.println("Servo rotated to 180 degrees.");

  // Wait for 4 seconds (4000 milliseconds)
  delay(4000);

  // Rotate the servo motor back to 0 degrees
  myServo.write(0);
  Serial.println("Servo rotated back to 0 degrees.");

  // Turn off the LED
  digitalWrite(ledPin, LOW);
  Serial.println("LED turned OFF.");
}
