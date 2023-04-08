#include <Servo.h> 
char t;
// Motor A connections

int Left_forward = 2;
int Left_backward = 3;
// Motor B connections

int Right_backward = 4;
int Right_forward  = 5;

Servo s1,s2,s3;
int pos = 0;
int x=20;
int y=100;

void setup() {
  s1.attach(9); 
  s2.attach(10); 
  s3.attach(11); 
  pinMode(Left_forward, OUTPUT);
  pinMode(Left_backward, OUTPUT);
  pinMode(Right_backward, OUTPUT);
  pinMode(Right_forward , OUTPUT);
Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'A'){            //move  forward(all motors rotate in forward direction)
  digitalWrite(Right_forward,HIGH);
  digitalWrite(Left_forward,HIGH);
  
     delay(10);
//  digitalWrite(Right_forward,LOW);
//  digitalWrite(Left_forward,LOW);
//     delay(50);

  digitalWrite(Right_backward,LOW);
  digitalWrite(Left_backward,LOW);

//  delay(200);
  t = '0';
}
 
else if(t == 'B'){      //move reverse (all  motors rotate in reverse direction)
  digitalWrite(Right_backward,HIGH);
  digitalWrite(Left_backward,HIGH);
     delay(10);
//  digitalWrite(Right_backward,LOW);
//  digitalWrite(Left_backward,LOW);
//     delay(50);
  digitalWrite(Right_forward,LOW);
  digitalWrite(Left_forward,LOW);
//    delay(200);
  t = '0';

}
  
else if(t == 'C'){      //turn right (left side motors rotate in forward direction,  right side motors doesn't rotate)
  digitalWrite(Right_forward,HIGH);
     delay(50);
  digitalWrite(Right_forward,LOW);
     delay(60);

   digitalWrite(Left_forward,LOW);
   digitalWrite(Left_backward,LOW);
   digitalWrite(Right_backward,LOW);
   t = '0';
}
 
else  if(t == 'D'){      //turn left (right side motors rotate in forward direction, left  side motors doesn't rotate)
     digitalWrite(Left_forward,HIGH);
     delay(50);
   digitalWrite(Left_forward,LOW);
    delay(50);
    digitalWrite(Left_backward,LOW);
    digitalWrite(Right_forward,LOW);
     digitalWrite(Right_backward,LOW);
     t = '0';
}

else if(t ==  'X'){    //STOP (all motors stop)
      digitalWrite(Left_backward,LOW);
      digitalWrite(Left_forward,LOW);
    digitalWrite(Right_forward,LOW);
     digitalWrite(Right_backward,LOW);
     s3.write(135);
}
else if(t == 'a'){
   for (pos = x; pos <= 160; pos += 1) { 
    s1.write(pos);             
    delay(15);
    x =x+1;
   break;
    t = '0';
    }
}
 
else if(t == 'b'){  
  for (pos = x; pos >= 20; pos -= 1) { 
    s1.write(pos);              
    delay(15);
    x =x-1;
    break;
     t = '0';
    }

}
else if(t == 'c'){  
 for (pos = y; pos <= 180; pos += 1) { 
    s2.write(pos);             
    delay(15);
    y =y+1;
    break;
     t = '0';
    }
}
else if(t == 'd'){  
  for (pos = y; pos >= 100; pos -= 1) { 
    s2.write(pos);              
    delay(15);
    y =y-1;
    break;
     t = '0';
    }

}
else if(t == 'e'){  
s3.write(95);  
}
else if(t == '0'){  
      digitalWrite(Left_backward,LOW);
      digitalWrite(Left_forward,LOW);
    digitalWrite(Right_forward,LOW);
     digitalWrite(Right_backward,LOW);
}

delay(100);
}
