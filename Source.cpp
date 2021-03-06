/********************************************
Samanth Mottera Srinivas
2nd October, 2015
Smart Tripod

I used two 5 volt sources in series to power 
the arduino. The Stepper motors were standard
NEMA 17 and NEMA 23(for pan) motors.
*********************************************/

/*******************
Output Pins
pan_dir = 22;
pan_stepper = 24;
tilt_dir = 26;
tilt_stepper = 28;
PowerLED = 31;
Pan_LED = 33;
Tilt_LED = 35;
x1_LED = 37;
x10_LED = 39;
x50_LED = 41;

//Input Pins
Multiplier = 44;
Pan_pos = 46;
Tilt_pos = 48;
Pan_neg = 50;
Tilt_neg = 52;
******************/

void setup() 
{
  
  pinMode(24, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(31, OUTPUT);  //Lights up when the arduino is fired up
  pinMode(33, OUTPUT);  //pulsates when any movement in provoked 
  pinMode(35, OUTPUT);  
  pinMode(37, OUTPUT);  //LED indicates step multiplier 
  pinMode(39, OUTPUT);
  pinMode(41, OUTPUT);
  
  pinMode(44, INPUT_PULLUP); //Multiplier selector button
  pinMode(46, INPUT_PULLUP);
  pinMode(48, INPUT_PULLUP);
  pinMode(50, INPUT_PULLUP);
  pinMode(52, INPUT_PULLUP);
  
  
  
}

void loop()
{
  int Multiplier_value = 1;
  int Multiplier_Button_status = digitalRead(44);
  digitalWrite(31, HIGH);
  
  /******* MULTIPLIER SELECTION ***************/
  
  digitalWrite(37, HIGH);
  
  if(Multiplier_Button_status == LOW)
  {
    Multiplier_value = 10;
    digitalWrite(39, HIGH);
	delay(500);
  }
  
  if(Multiplier_value == 10 && Multiplier_Button_status == LOW)
  {
	Multiplier_value = 50; 
	digitalWrite(41, HIGH);
	delay(500);
  }
  
  if(Multiplier_value == 50 && Multiplier_Button_status == LOW)
  {
    Multiplier_value = 1;
    digitalWrite(37, HIGH);
	delay(500);
  }  

  /************ Stepper Motor Action ***********/

  //Pans up
  if(digitalRead(46) == LOW)
  {
    digitalWrite(22, LOW);
    for(int i = 0; i < Multiplier_value; i++)
    { 
      digitalWrite(33, HIGH); //LED Turns on
      digitalWrite(24, LOW);
      digitalWrite(24, HIGH);  //One step
      delayMicroseconds(50);
      digitalWrite(33, LOW);  //LED Turns off
    }
      
  }
  
  //Tilts Down
  if(digitalRead(48) == LOW)
  {
    digitalWrite(26, LOW);
    for(int j = 0; j < Multiplier_value; j++)
    { 
      digitalWrite(35, HIGH); //LED Turns on
      digitalWrite(28, LOW);
      digitalWrite(28, HIGH);  //One step
      delayMicroseconds(50);
      digitalWrite(35, LOW);  //LED Turns off
    }
      
  } 
  
  //Pans down
  if(digitalRead(50) == LOW)
  {	
    digitalWrite(22, HIGH);
    for(int k = 0; k < Multiplier_value; k++)
    { 
      digitalWrite(33, HIGH); //LED Turns on
      digitalWrite(24, LOW);
      digitalWrite(24, HIGH);  //One step
      delayMicroseconds(50);
      digitalWrite(33, LOW);  //LED Turns off
    }
      
  } 
  
  //Tilts up
  if(digitalRead(52) == LOW)
  {
    digitalWrite(26, HIGH);
    for(int l = 0; l < Multiplier_value; l++)
    { 
      digitalWrite(35, HIGH); //LED Turns on
      digitalWrite(28, LOW);
      digitalWrite(28, HIGH);  //One step
      delayMicroseconds(50);
      digitalWrite(35, LOW);  //LED Turns off
    }
      
  } 
  
}
