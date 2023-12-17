//LED Pins
int led_uv = 10, led_oj = 11, led_pk = 12;

//Analog Button 
int btn = 3;

//button state variables
int butState = 0; //Last Button State
int val = 0, val2 = 0; // Button Pin HIGH/LOW Status (twice for debounce)

//Switch Mode Variables
int mode = 0; //Selector State (Initial state = everything off)
int modeState = 0; //Last Mode State

//===============================================================================
// Set-Up
//===============================================================================
void setup() {
  pinMode(btn, INPUT);
  pinMode(led_uv, OUTPUT);
  pinMode(led_oj, OUTPUT);
  pinMode(led_pk, OUTPUT);
  //butState = digitalRead(btn);
  Serial.begin(9600);
}

//===============================================================================
// PROGRAM LOOP
//===============================================================================

void loop() {
  val = digitalRead(btn);
  delay(10);  //Wait to make sure button press is good
  val2 = digitalRead(btn);
  
  if (val == val2){  //debounce check
    if (val != butState && val == HIGH){  //If we see a change in the button state,
      mode++;                             //we increment the mode value by 1
    }
  }
  butState = val; //update the most recent button state
  
  if (modeState != mode){
    switch (mode) {
      case 2:            //Start with Case 2 because Case 1 is considered the default 
//      ColorBreath("uv");  //"start-up" mode.
      analogWrite(led_uv, 255);
      break;
      case 3:
//      ColorBreath("oj");
      analogWrite(led_uv, 155);
      break;
      case 4:
//      ColorBreath("pk");
      analogWrite(led_uv, 55);
      break;
      default:
      mode = 1;
      ColorSelect();
      break;
    }
  }
  else {
    switch (modeState) {
      case 2:            //Start with Case 2 because Case 1 is considered the default 
 //     ColorBreath("uv");  //"start-up" mode.
      analogWrite(led_uv, 255);
      break;
      case 3:
//      ColorBreath("oj");
      analogWrite(led_uv, 155);
      break;
      case 4:
//      ColorBreath("pk");
      analogWrite(led_uv, 55);
      break;
      default:
      mode = 1;
      ColorSelect();
      break;
    }
  }
  modeState = mode;
}

//===============================================================================
// Color Funcitons
//===============================================================================

void ColorSelect(){
  analogWrite(led_uv, 0);
}

void ColorBreath(String color){
  if (color == "uv"){
    led_uv = 255;
  }
  else if (color == "oj"){
    led_uv = 150;
  }
  else if (color == "pk"){
    led_uv = 50;
  }
}

