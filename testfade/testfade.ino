//LED Pins
int led_uv_left = 11;
int led_oj_left = 10;
int led_pk_left = 9;
int led_uv_right = 6;
int led_oj_right = 5;
int led_pk_right = 3;

int value, value2, value3;
long time=0;

int periode = 4000;
int displace = 1300; //oj
int displace2 =2600; //pk

//Analog Button 
int btn = 2;

//button state variables
int butState = 0; //Last Button State
int val = 0, val2 = 0; // Button Pin HIGH/LOW Status (twice for debounce)

//Switch Mode Variables
int mode = 0; //Selector State (Initial state = everything off)
int modeState = 0; //Last Mode State

//===============================================================================
// THE SETUP YO
//===============================================================================
void setup() {
  pinMode(btn, INPUT);
  pinMode(led_uv_left, OUTPUT);
  pinMode(led_oj_left, OUTPUT);
  pinMode(led_pk_left, OUTPUT);
  pinMode(led_uv_right, OUTPUT);
  pinMode(led_oj_right, OUTPUT);
  pinMode(led_pk_right, OUTPUT);
  //butState = digitalRead(btn);
  Serial.begin(9600);
}

//===============================================================================
// THE LIGHTS YO
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
//      Solid ("uv")  
      analogWrite(led_uv_left, 255);
      analogWrite(led_pk_left, 0);
      analogWrite(led_oj_left, 0);
      analogWrite(led_uv_right, 255);
      analogWrite(led_pk_right, 0);
      analogWrite(led_oj_right, 0);
      break;
      case 3:
//      Solid ("oj")
      analogWrite(led_oj_left, 255);
      analogWrite(led_uv_left, 0);
      analogWrite(led_pk_left, 0);
      analogWrite(led_oj_right, 255);
      analogWrite(led_uv_right, 0);
      analogWrite(led_pk_right, 0);
      break;
      case 4:
//      Solid ("pk")
      analogWrite(led_pk_left, 255);
      analogWrite(led_uv_left, 0);
      analogWrite(led_oj_left, 0);
      analogWrite(led_pk_right, 255);
      analogWrite(led_uv_right, 0);
      analogWrite(led_oj_right, 0);
      break;
      case 5:
 //     Breathe ("uv")   
 // put breath code here scrub
      analogWrite(led_pk_left, 0);
      analogWrite(led_oj_left, 0); 
      analogWrite(led_pk_right, 0);
      analogWrite(led_oj_right, 0); 
      time = millis();
      value = 128+127*cos(2*PI/periode*time);
      analogWrite(led_uv_left, value);           // sets the value (range from 0 to 255) 
      analogWrite(led_uv_right, value); 
      break;
      case 6:
 //     Breathe ("oj")  
      analogWrite(led_pk_left, 0);
      analogWrite(led_uv_left, 0); 
      analogWrite(led_pk_right, 0);
      analogWrite(led_uv_right, 0); 
       time = millis();
      value = 128+127*cos(2*PI/periode*time);
      analogWrite(led_oj_left, value);   
      analogWrite(led_oj_right, value);  
      break;
      case 7:
 //     Breathe ("pk") 
      analogWrite(led_uv_left, 0);
      analogWrite(led_oj_left, 0);  
      analogWrite(led_uv_right, 0);
      analogWrite(led_oj_right, 0);  
       time = millis();
      value = 128+127*cos(2*PI/periode*time);
      analogWrite(led_pk_left, value);   
      analogWrite(led_pk_right, value); 
      break;
     case 8:
 //     Breathe ("complex")   
 // put something cool here scrub
      time = millis();
      value = 128+127*cos(2*PI/periode*time);
      analogWrite(led_uv_left, value);
      analogWrite(led_oj_left, value); 
      analogWrite(led_pk_left, value);     
      analogWrite(led_uv_right, value);
      analogWrite(led_oj_right, value); 
      analogWrite(led_pk_right, value);  
      break;
     case 9:
 //     Breathe ("complex chase")   
 // put something cool here scrub
      time = millis();
      value = 128+127*cos(2*PI/periode*time);
      value2 = 128+127*cos(2*PI/periode*(displace-time));
      value3 = 128+127*cos(2*PI/periode*(displace2-time));
      analogWrite(led_uv_left, value);
      analogWrite(led_oj_left, value2); 
      analogWrite(led_pk_left, value3);     
      analogWrite(led_uv_right, value);
      analogWrite(led_oj_right, value2); 
      analogWrite(led_pk_right, value3);   
      break;
     case 10:
 //     solid all   
      analogWrite(led_uv_left, value);
      analogWrite(led_oj_left, value2); 
      analogWrite(led_pk_left, value3);     
      analogWrite(led_uv_right, value);
      analogWrite(led_oj_right, value2); 
      analogWrite(led_pk_right, value3);   
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
//      Solid ("uv")  
      analogWrite(led_uv_left, 255);
      analogWrite(led_pk_left, 0);
      analogWrite(led_oj_left, 0);
      analogWrite(led_uv_right, 255);
      analogWrite(led_pk_right, 0);
      analogWrite(led_oj_right, 0);
      break;
      case 3:
//      Solid ("oj")
      analogWrite(led_oj_left, 255);
      analogWrite(led_uv_left, 0);
      analogWrite(led_pk_left, 0);
      analogWrite(led_oj_right, 255);
      analogWrite(led_uv_right, 0);
      analogWrite(led_pk_right, 0);
      break;
      case 4:
//      Solid ("pk")
      analogWrite(led_pk_left, 255);
      analogWrite(led_uv_left, 0);
      analogWrite(led_oj_left, 0);
      analogWrite(led_pk_right, 255);
      analogWrite(led_uv_right, 0);
      analogWrite(led_oj_right, 0);
      break;
      case 5:
 //     Breathe ("uv")   
 // put breath code here scrub
      analogWrite(led_pk_left, 0);
      analogWrite(led_oj_left, 0); 
      analogWrite(led_pk_right, 0);
      analogWrite(led_oj_right, 0); 
      time = millis();
      value = 128+127*cos(2*PI/periode*time);
      analogWrite(led_uv_left, value);           // sets the value (range from 0 to 255) 
      analogWrite(led_uv_right, value); 
      break;
      case 6:
 //     Breathe ("oj")  
      analogWrite(led_pk_left, 0);
      analogWrite(led_uv_left, 0); 
      analogWrite(led_pk_right, 0);
      analogWrite(led_uv_right, 0); 
       time = millis();
      value = 128+127*cos(2*PI/periode*time);
      analogWrite(led_oj_left, value);   
      analogWrite(led_oj_right, value);  
      break;
      case 7:
 //     Breathe ("pk") 
      analogWrite(led_uv_left, 0);
      analogWrite(led_oj_left, 0);  
      analogWrite(led_uv_right, 0);
      analogWrite(led_oj_right, 0);  
       time = millis();
      value = 128+127*cos(2*PI/periode*time);
      analogWrite(led_pk_left, value);   
      analogWrite(led_pk_right, value); 
      break;
     case 8:
 //     Breathe ("complex")   
 // put something cool here scrub
      time = millis();
      value = 128+127*cos(2*PI/periode*time);
      analogWrite(led_uv_left, value);
      analogWrite(led_oj_left, value); 
      analogWrite(led_pk_left, value);     
      analogWrite(led_uv_right, value);
      analogWrite(led_oj_right, value); 
      analogWrite(led_pk_right, value);  
      break;
     case 9:
 //     Breathe ("complex chase")   
 // put something cool here scrub
      time = millis();
      value = 128+127*cos(2*PI/periode*time);
      value2 = 128+127*cos(2*PI/periode*(displace-time));
      value3 = 128+127*cos(2*PI/periode*(displace2-time));
      analogWrite(led_uv_left, value);
      analogWrite(led_oj_left, value2); 
      analogWrite(led_pk_left, value3);     
      analogWrite(led_uv_right, value);
      analogWrite(led_oj_right, value2); 
      analogWrite(led_pk_right, value3);   
      break;
     case 10:
 //     solid all   
      analogWrite(led_uv_left, 255);
      analogWrite(led_oj_left, 255); 
      analogWrite(led_pk_left, 255);     
      analogWrite(led_uv_right, 255);
      analogWrite(led_oj_right, 255); 
      analogWrite(led_pk_right, 255);   
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
  analogWrite(led_uv_left, 0);
  analogWrite(led_pk_left, 0);
  analogWrite(led_oj_left, 0);
  analogWrite(led_uv_right, 0);
  analogWrite(led_pk_right, 0);
  analogWrite(led_oj_right, 0);
}