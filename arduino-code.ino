 
boolean sensingLow = true;
boolean takeSensingTime; 
 
int pirPin = 7;    //the digital pin connected to the PIR sensor's output
int ledPin = 8;
 

void setup(){
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(pirPin, LOW);
  
  Serial.print("calibrating sensor ");
    for(int i = 0; i < 10; i++){
      Serial.print(".");
      delay(1000);
      }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
    delay(50);
  }
 

void loop(){
 
     if(digitalRead(pirPin) == HIGH){
       digitalWrite(ledPin, LOW);   //the led visualizes the sensors output pin state
       if(sensingLow){ 
        sensingLow = false;           
         }        
         takeSensingTime = true;
       }
 
     if(digitalRead(pirPin) == LOW){      
       digitalWrite(ledPin, HIGH);  //the led visualizes the sensors output pin state
       if(takeSensingTime){
        takeSensingTime = false;       //make sure this is only done at the start of a LOW phase
        }
       }
  }
