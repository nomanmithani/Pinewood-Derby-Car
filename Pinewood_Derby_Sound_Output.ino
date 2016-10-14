
 
#define BLUELED 1  // the input pin for blue led from thunderboard (controls headlights)
#define GREENLED 2 // the input pin for green led from thunderboard (controls taillights)
#define WHITELED 5 // the output pin for the white leds (headlights)
#define REDLED 6   // the output pin for the red leds (taillights)


int voltstate_b = 0; // variable to store voltage from blue led
int voltstate_g = 0; // variable to store voltage from green led
                 


void setup() 
  { 
    pinMode(REDLED, OUTPUT);   // define inputs and outputs
    pinMode(WHITELED, OUTPUT); 
    pinMode(BLUELED, INPUT);
    pinMode(GREENLED, INPUT);
} 

void loop(){ 
  voltstate_b = analogRead(1); // read input value from blue led and store as int (0-1023)
  voltstate_g = analogRead(2); // read input voltage from green led and store as int (0-1023)


  if ((voltstate_b < 100) && (voltstate_g < 100))//both ON
  {  
    digitalWrite(WHITELED, HIGH); //turn headlights ON
    digitalWrite(REDLED, HIGH); //turn taillights ON
    
  }  
  else if ((voltstate_b < 100) && (voltstate_g > 100)) //blue ON green OFF
  { 
    digitalWrite(WHITELED, HIGH);
    digitalWrite(REDLED, LOW);
  } 
  else if ((voltstate_b > 100) && (voltstate_g < 100)) //blue OFF green ON
  {
    digitalWrite(WHITELED, LOW);
    digitalWrite(REDLED, HIGH);
  }
  else //both OFF
  {
    digitalWrite(WHITELED, LOW);
    digitalWrite(REDLED, LOW);
  }
}
