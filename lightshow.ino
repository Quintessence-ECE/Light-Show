
 
#include <FastLED.h>
 
// Sets the maximum number of LEDs that this code will handle to avoid running out of memory
#define NUM_LEDS 1800   //Total leds of strip A+B+C+D
#define NUM_LEDS_A 353   //Strip A
#define NUM_LEDS_B 405  //Strip B
#define NUM_LEDS_C 352   //Strip C
#define NUM_LEDS_D 403   //Strip D


// Sets the pin which is used to connect to the LED pixel strip
#define DATA_PIN_A 6
#define DATA_PIN_B 7
//#define DATA_PIN_C 8
//#define DATA_PIN_D 13

CRGB ledsA[NUM_LEDS_A];
CRGB ledsB[NUM_LEDS_B];
CRGB ledsC[NUM_LEDS_C];
CRGB ledsD[NUM_LEDS_D];

int seg = 9;
int eyestop = 5;
int eyesbottom = 11;
int mouthtop = 9;
int mouthcorner = 8;
int mouthmid = 10;
int mouthbottom = 12;
int mouthsides = 3;
int mouthcurves = 13;
int moutho = 4;
 int moutho_l = 45;
int mouthbottom_l = 24;
int eyestop_l = 36;
int eyesbottom_l = 30;
int moutho_top_l = 22;
int mouthcorner_l = 28;
int mouthmid_l = 26;
int moutho_bottom_l = 34;

int mouthsides_l = 32;
//int mouthcurves = 11;
//int moutho = 4;

int flash_top_r = 53;
int flash_top_l = 51;
int flash_mid_r = 49;
int flash_mid_l = 47;
int flash_bottom_r = 45;
int flash_bottom_l = 43;

void setup() {
  // Define the speed of the serial port
  Serial.begin(1048576);
  pinMode(eyestop,OUTPUT);
  pinMode(eyesbottom,OUTPUT);
  pinMode(mouthtop,OUTPUT);
  pinMode(mouthcorner,OUTPUT);
  pinMode(mouthmid,OUTPUT);
  pinMode(mouthbottom,OUTPUT);
  pinMode(mouthsides,OUTPUT);
  pinMode(mouthcurves,OUTPUT);
  pinMode(moutho,OUTPUT);

  pinMode(mouthbottom_l,OUTPUT);
  pinMode(eyestop_l,OUTPUT);
  pinMode(eyesbottom_l,OUTPUT);
  pinMode(moutho_top_l,OUTPUT);
  pinMode(mouthcorner_l,OUTPUT);
  pinMode(mouthmid_l,OUTPUT);
  pinMode(moutho_bottom_l,OUTPUT);
  pinMode(mouthsides_l,OUTPUT);
  
  pinMode(flash_top_r,OUTPUT);
  pinMode(flash_top_l,OUTPUT);
  pinMode(flash_mid_r,OUTPUT);
  pinMode(flash_mid_l,OUTPUT);
  pinMode(flash_bottom_r,OUTPUT);
  pinMode(flash_bottom_l,OUTPUT);
}
 
void loop() {
  // Set some counter / temporary storage variables
///  int cnt;
  int cnt_A;
  int cnt_B;
  int cnt_C;
  int cnt_D;
  
  unsigned int num_leds;     ///Total leds named in the HEADER(vixen software)
  unsigned int d1, d2, d3;
  
  int NLA;
  int NLB;
  int NLC;
  int NLD;
     
 
  // Begin an endless loop to receive and process serial data
  for(;;) {
    // Set a counter to 0.  This couter keeps track of the pixel colors received.
///  cnt = 0;
cnt_A = 0;
cnt_B = 0;
cnt_C = 0;
cnt_D = 0;
    
NLA=NUM_LEDS_A;
NLB=NUM_LEDS_B;
NLC=NUM_LEDS_C;
NLD=NUM_LEDS_D;    
    
    
    
    //Begin waiting for the header to be received on the serial bus
    //1st character
    while(!Serial.available());
      if(Serial.read() != '>') {
        continue;
        }
    //second character
    while(!Serial.available());
      if(Serial.read() != '>') {
        continue;
        }
    //get the first digit from the serial bus for the number of pixels to be used
    while(!Serial.available());
      d1 = Serial.read();
    //get the second digit from the serial bus for the number of pixels to be used
    while(!Serial.available());
      d2 = Serial.read();
    //get the third digit from the serial bus for the number of pixels to be used
    while(!Serial.available());
      d3 = Serial.read();
    //get the end of the header
    while(!Serial.available());
      if(Serial.read() != '<') {
        continue;
        }
    while(!Serial.available());
      if(Serial.read() != '<') {
        continue;
        }
    // calculate the number of pixels based on the characters provided in the header digits
    num_leds = (d1-'0')*100+(d2-'0')*10+(d3-'0');
    // ensure the number of pixels does not exceed the number allowed
    if(num_leds > NUM_LEDS) {
      continue;
      }
      
    // Let the FastLED library know how many pixels we will be addressing
    FastLED.addLeds<WS2811, DATA_PIN_A, GRB>(ledsA, NUM_LEDS_A);
    FastLED.addLeds<WS2811, DATA_PIN_B, RGB>(ledsB, NUM_LEDS_B);
    //FastLED.addLeds<WS2811, DATA_PIN_C, GRB>(ledsC, NUM_LEDS_C);
    //FastLED.addLeds<WS2811, DATA_PIN_D, GRB>(ledsD, NUM_LEDS_D);
    
    
    // Loop through each of the pixels and read the values for each color
    do {
      while(!Serial.available());
        ledsA[cnt_A].r = Serial.read();
      while(!Serial.available());
        ledsA[cnt_A].g = Serial.read();
      while(!Serial.available());
        ledsA[cnt_A++].b = Serial.read();
        
        --num_leds; 
      } 
    while(--NLA);
    
      /////// Loop through each of the pixels and read the values for each color
    do {
      while(!Serial.available());
        ledsB[cnt_B].r = Serial.read();
      while(!Serial.available());
        ledsB[cnt_B].g = Serial.read();
      while(!Serial.available());
        ledsB[cnt_B++].b = Serial.read();    
       --num_leds; 
        
      } 
    while(--NLB);
    
    
    //   ////// Loop through each of the pixels and read the values for each color
    // do {
    //   while(!Serial.available());
    //     ledsC[cnt_C].r = Serial.read();
    //   while(!Serial.available());
    //     ledsC[cnt_C].g = Serial.read();
    //   while(!Serial.available());
    //     ledsC[cnt_C++].b = Serial.read();
        
    //     --num_leds; 
    //   } 
    // while(--NLC);
   
    // //  // Loop through each of the pixels and read the values for each color
    // do {
    //   while(!Serial.available());
    //     ledsD[cnt_D].r = Serial.read();
    //   while(!Serial.available());
    //     ledsD[cnt_D].g = Serial.read();
    //   while(!Serial.available());
    //     ledsD[cnt_D++].b = Serial.read();
        
    //     --num_leds; 
    //   } 
    // while(--NLD); 
    


      while(!Serial.available());
      digitalWrite(mouthsides_l,map(Serial.read(),0,255,0,1));
      while(!Serial.available());
      int o = map(Serial.read(),0,255,0,1);
      digitalWrite(moutho_l,o);
      //digitalWrite(moutho_bottom_l,o);
      while(!Serial.available());
      digitalWrite(eyestop_l,map(Serial.read(),0,255,0,1));
      while(!Serial.available());
      digitalWrite(mouthcorner_l,map(Serial.read(),0,255,0,1));
      while(!Serial.available());
      int l_top = map(Serial.read(),0,255,0,1);
      digitalWrite(moutho_top_l,l_top);
      while(!Serial.available());
      int l_mid = map(Serial.read(),0,255,0,1);
      digitalWrite(moutho_bottom_l,l_mid);
      while(!Serial.available());
      digitalWrite(eyesbottom_l,map(Serial.read(),0,255,0,1));
      while(!Serial.available());
      digitalWrite(mouthbottom_l,map(Serial.read(),0,255,0,1));
      while(!Serial.available());
      digitalWrite(mouthmid_l,map(Serial.read(),0,255,0,1)); 
          
    
      while(!Serial.available());
      digitalWrite(mouthsides,map(Serial.read(),0,255,0,1));
      while(!Serial.available());
      digitalWrite(moutho,map(Serial.read(),0,255,0,1));
      while(!Serial.available());
      digitalWrite(eyestop,map(Serial.read(),0,255,0,1));
      while(!Serial.available());
      digitalWrite(mouthcorner,map(Serial.read(),0,255,0,1));
      while(!Serial.available());
      digitalWrite(mouthtop,map(Serial.read(),0,255,0,1));
      while(!Serial.available());
      digitalWrite(mouthmid,map(Serial.read(),0,255,0,1));
      while(!Serial.available());
      digitalWrite(eyesbottom,map(Serial.read(),0,255,0,1));
      while(!Serial.available());
      digitalWrite(mouthcurves,map(Serial.read(),0,255,0,1)); 
      while(!Serial.available());
      digitalWrite(mouthbottom,map(Serial.read(),0,255,0,1));
    

      while(!Serial.available());
      digitalWrite(flash_top_r,map(Serial.read(),0,255,0,1));
      while(!Serial.available());
      digitalWrite(flash_top_l,map(Serial.read(),0,255,0,1)); 
      while(!Serial.available());
      digitalWrite(flash_mid_r,map(Serial.read(),0,255,0,1));
      while(!Serial.available());
      digitalWrite(flash_mid_l,map(Serial.read(),0,255,0,1));
      while(!Serial.available());
      digitalWrite(flash_bottom_r,map(Serial.read(),0,255,0,1)); 
      while(!Serial.available());
      digitalWrite(flash_bottom_l,map(Serial.read(),0,255,0,1));
    
    // Tell the FastLED Library it is time to update the strip of pixels
    FastLED.show();

      
    
    // WOO HOO... We are all done and are ready to start over again!
    }
}
