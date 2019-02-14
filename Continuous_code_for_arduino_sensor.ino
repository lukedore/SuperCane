
#define trigPin 13
#define echoPin 10
#define motor A5
int sensorValue = 0;
int sensorPin = A1;
  
void setup()
  { pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motor, OUTPUT);
  Serial.begin(9600);
     }

void loop()
{ long duration, distance,power;
  int maxDis = 150;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);


      
    
  duration = pulseIn(echoPin, HIGH);  
  distance = (duration/2) / 29.1;
  if (distance<maxDis){
    power = (400-distance)/2;
  } else {
      power = 0 ;
  }
  
  analogWrite (motor,(power*255/100));
  
  Serial.print(distance);
  Serial.print("   <  ");
  Serial.print(maxDis);
  Serial.print("     ");  
  Serial.print(power);
  Serial.print("     ");  
  Serial.print(sensorPin);
  Serial.println();

  
  
}

