// C++ code
//

const int distancia_buzzer = 10;

// Sensor

const int TRIG = 3;
const int ECHO = 2;

const int red = 7;
const int green = 8;
const int buzzer = 9;

// Variaveis para funcionamento do buzzer

float seno;
int frequencia;

void setup()
{
  
  Serial.begin(9600);
  
  // Sensor
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  
  // Led
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  
  // Buzzer
  pinMode(buzzer, OUTPUT);
  
}

void loop()
{
  int distancia = sensor_morcego(TRIG,ECHO);
  
  if(distancia <= distancia_buzzer){
  	
    Serial.print("Atenção: ");
    Serial.print(distancia);
    Serial.print("cm");
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    tocaBuzzer();
    
  } else {
  	
    Serial.print("Livre: ");
    Serial.print(distancia);
    Serial.print("cm");
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    noTone(buzzer);
    
  }
  
  delay(100);
  
}

int sensor_morcego(int pinoTrig, int pinoEcho){

	digitalWrite(pinoTrig, LOW);
  	delayMicroseconds(2);
  	digitalWrite(pinoTrig, HIGH);
    delayMicroseconds(10);
	digitalWrite(pinoTrig, LOW);

  	return pulseIn(pinoEcho, HIGH)/58;
  
}
void tocaBuzzer(){
  	
  for(int x=0; x<100; x++){
   
    seno=(sin(x*3.1416/180));
    frequencia = 2000+(int(seno*1000));
    tone(buzzer, frequencia);
    delay(2);
  }
}
