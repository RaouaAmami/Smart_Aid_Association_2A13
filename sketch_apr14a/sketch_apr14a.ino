
int Buzz= 8; // Define Bizzer pin
int LED= 13; // Define LED pin
int PIR= 3; // Define PIR pin
int val= 0; // Initializing the value as zero at the beginning
char data;

void setup() {

pinMode(Buzz, OUTPUT);
pinMode(LED, OUTPUT);
pinMode(PIR, INPUT);
Serial.begin(9600);
}

void loop() {
val = digitalRead(PIR); // The value read from PIR pin 3 will be assigned to 'val'
if(val == HIGH){
  digitalWrite(LED, HIGH); // Turn LED ON
  digitalWrite(Buzz, HIGH); // Turn Buzzer ON 
 
 // Serial.write('0');
  //Serial.println("Movement Detected"); // Print this text in Serial Monitor
 Serial.println("0");
}
else 
{
  digitalWrite(LED, LOW);
  digitalWrite(Buzz, LOW);
  //Serial.write('1');
  //Serial.println("Movement not Detected");
 Serial.println("1");
}
 if (Serial.available()){
  
    data=Serial.read();
    if(data=='2')
    {
      digitalWrite(Buzz, LOW);
    }
    }
    }
    






  
