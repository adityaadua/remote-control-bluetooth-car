// C++ code
char input;
void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(2, INPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int potentiometer = analogRead(A0);
  int potent = potentiometer / 4;

  analogWrite(10, potent);
  analogWrite(11, potent);

  while(Serial.available())
  {
    input=Serial.read();
    
    if(input=='F')
    {
      forward();

    }

    else if(input=='G')
    {
      backward();

    }

    else if(input=='L')
    {
      left();

    }

    else if(input=='R')
    {
      right();

    }

    else if(input=='S')
    {
      stop();
    }

  }



  // if (digitalRead(2) == LOW) {
  //   Serial.println("stop");
  //   stop();
  //   //  delay(500);
  //   //  right();
  //   //  delay(600);
  //   // forward();
  // } else {
  //   Serial.println("moving");
  //   forward();
  // }
}

void backward() {
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}

void stop() {
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}

void forward() {
  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
}

void right() {
  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}

void left() {
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
};