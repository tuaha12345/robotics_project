int IRSensor = 7;
int buzzer = 5;
int led = 12;
int motor=6;
int b=3000;
int m=1500;
int l=1500;
void setup()
{ pinMode (IRSensor, INPUT);
pinMode (buzzer, OUTPUT);
pinMode (led, OUTPUT);
pinMode (motor, OUTPUT);
}
void loop()
{ int statusSensor = digitalRead (IRSensor);
if (statusSensor == 1)
{ digitalWrite(buzzer, LOW);
digitalWrite(led, LOW);
digitalWrite(motor, HIGH);
delay(b);
}
else
{ digitalWrite(buzzer, HIGH);
delay(l);
digitalWrite(led, HIGH);
delay(m);
digitalWrite(motor, LOW);
}
}
