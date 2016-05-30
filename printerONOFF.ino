
int RelayPin=5;
int ButtonPin=6;
int led=13;
int ButtonStat=0;
char stat=0;
int stat1=0;

void setup() 
{               
  Serial.begin(9600);
  delay(200);
  pinMode(RelayPin, OUTPUT);     
  pinMode(led, OUTPUT);     
  pinMode(ButtonPin, INPUT);
}

void loop()
{
  stat=Serial.read();
  ButtonStat=digitalRead(ButtonPin);
  
  if(ButtonStat==LOW)
  {
    if(stat1==1)
    {
      digitalWrite(RelayPin, LOW);
      delay(100);
      stat1=0;
    }
     switch(stat)
     {
       case '1':
       digitalWrite(RelayPin, HIGH);
       delay(100);
       break;
       case '0':
       digitalWrite(RelayPin, LOW);
       delay(100);
       break;
     }
  }
  else if(ButtonStat==HIGH)
  {
    digitalWrite(RelayPin, HIGH);
    stat1=1;   
    delay(100);  
  }
}
