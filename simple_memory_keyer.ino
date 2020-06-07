 // Simple Iambic Keyer v1.00
// by Ernest PA3HCM
// Simple Iambic Keyer, added memory keyer function
// by JJ1VCJ/AJ6MM Jun 2020.

#define P_DOT    2   // Connects to the dot lever of the paddle
#define P_DASH   3   // Connects to the dash lever of the paddle
#define P_AUDIO 12   // Audio output
#define P_CW    13   // Output of the keyer, connect to your radio
#define P_SPEED A0   // Attached to center pin of potmeter, allows you
                     // to set the keying speed.
#define key_sens 5

#define f_1 6
#define f_2 8
#define f_3 10
#define f_4 A2
#define f_5 7
#define f_6 9

int speed;
boolean m_flag;
///////////////////////////change to your favorite message//////////////////////
char msg1[]="= cq dx cq dx de ab1cde ab1cde ab1cde pse + k";
char msg2[]="cq eu cq eu de ab1cde ab1cde pse k";
char msg3[]="= cq jp cq jp de ab1cde ab1cde ab1cde pse + k";
char msg4[]="qrz? qrz? de ab1cde agn pse k";
char msg5[]="= cq test cq test de ab1cde ab1cde pse k";
char msg6[]="this is a tiny electric keyer with memory function. message can be easily modifed by arduino sketch. try this one.";


// Initializing the Arduino
void setup()
{
  pinMode(P_DOT, INPUT);
  pinMode(P_DASH, INPUT); 
  pinMode(P_AUDIO, OUTPUT);
  pinMode(P_CW, OUTPUT);
  pinMode(key_sens, OUTPUT);  
  digitalWrite(P_CW, LOW);      // Start with key up
  analogWrite(key_sens, 255);
  for(int i=6;i<11;i++){
  pinMode(i, INPUT_PULLUP);
  }
  pinMode(f_4, INPUT_PULLUP);
  m_flag=0;
  speed = analogRead(P_SPEED)/2;

}

// Main routine
void loop()
{
  if(m_flag==0){
  speed = analogRead(P_SPEED)/2; // Read the keying speed from potmeter
  if(!digitalRead(P_DOT))        // If the dot lever is presssed..
  {
    keyAndBeep(speed);           // ... send a dot at the given speed
    delay(speed);                //     and wait before sending next
  }
  if(!digitalRead(P_DASH))       // If the dash lever is pressed...
  {
    keyAndBeep(speed*3);         // ... send a dash at the given speed
    delay(speed);                //     and wait before sending next
  }
  }
  if(digitalRead(f_1)==0){
  for(int i=0; i< sizeof(msg1);i++){
    if(!digitalRead(P_DOT)){
      i=sizeof(msg1);
    }
    scs(msg1[i]);
  }    
  }
  if(digitalRead(f_2)==0){
  for(int i=0; i< sizeof(msg2);i++){
    if(!digitalRead(P_DOT)){
      i=sizeof(msg2);
    }
    scs(msg2[i]);
  }    
  }
  if(digitalRead(f_3)==0){
  for(int i=0; i< sizeof(msg3);i++){
    if(!digitalRead(P_DOT)){
      i=sizeof(msg3);
    }
    scs(msg3[i]);
  }    
  }
  if(digitalRead(f_4)==0){
  for(int i=0; i< sizeof(msg4);i++){
    if(!digitalRead(P_DOT)){
      i=sizeof(msg4);
    }
    scs(msg4[i]);
  }    
  }
  if(digitalRead(f_5)==0){
  for(int i=0; i< sizeof(msg5);i++){
    if(!digitalRead(P_DOT)){
      i=sizeof(msg5);
    }
    scs(msg5[i]);
  }    
  }
  if(digitalRead(f_6)==0){
  for(int i=0; i< sizeof(msg6);i++){
    if(!digitalRead(P_DOT)){
      i=sizeof(msg6);
    }
    scs(msg6[i]);
  }    
  }
}

// Key the transmitter and sound a beep
void keyAndBeep(int speed)
{
  digitalWrite(P_CW, HIGH);            // Key down
  for (int i=0; i < (speed/2); i++)    // Beep loop
  {
    digitalWrite(P_AUDIO, HIGH);
    delayMicroseconds(600);
    digitalWrite(P_AUDIO, LOW);
    delayMicroseconds(600);
  }
  digitalWrite(P_CW, LOW);             // Key up
}

void s_dot(){
  keyAndBeep(speed);
  delay(speed);
}

void s_dash(){
  keyAndBeep(speed*3);
  delay(speed);
}

void scs(char m){

switch (m) {
  case 'a':
  s_dot();
  s_dash();
  delay(speed);   
  break;
  case 'b':
  s_dash(); 
  s_dot();
  s_dot();
  s_dot(); 
  delay(speed);    
  break;
  case 'c':
  s_dash(); 
  s_dot();
  s_dash(); 
  s_dot();
  delay(speed);     
  break;
  case 'd':
  s_dash(); 
  s_dot(); 
  s_dot();
  delay(speed);     
  break;
  case 'e': 
  s_dot();
  delay(speed);     
  break;
  case 'f': 
  s_dot();
  s_dot();
  s_dash();
  s_dot();
  delay(speed);     
  break;
  case 'g': 
  s_dash();
  s_dash();
  s_dot();
  delay(speed);     
  break;
  case 'h': 
  s_dot();
  s_dot();
  s_dot();
  s_dot();
  delay(speed);     
  break;
  case 'i': 
  s_dot();
  s_dot();
  delay(speed);     
  break;
  case 'j': 
  s_dot();
  s_dash();
  s_dash();
  s_dash();
  delay(speed);     
  break;
  case 'k': 
  s_dash();
  s_dot();
  s_dash();
  delay(speed);     
  break;
  case 'l': 
  s_dot();
  s_dot();
  s_dash();
  s_dot();
  delay(speed);     
  break;
  case 'm': 
  s_dash();
  s_dash();
  delay(speed);     
  break;
  case 'n': 
  s_dash();
  s_dot();
  delay(speed);     
  break;
  case 'o': 
  s_dash();
  s_dash();
  s_dash();
  delay(speed);     
  break;
  case 'p':
  s_dot(); 
  s_dash();
  s_dash();
  s_dot(); 
  delay(speed);     
  break;          
  case 'q':
  s_dash();
  s_dash(); 
  s_dot();
  s_dash();
  delay(speed);    
  break;
  case 'r':
  s_dot();
  s_dash();
  s_dot();
  delay(speed);    
  break;
  case 's':
  s_dot();
  s_dot();
  s_dot();
  delay(speed);    
  break;
  case 't':
  s_dash();
  delay(speed);    
  break;
  case 'u':
  s_dot();
  s_dot();
  s_dash();
  delay(speed);    
  break;
  case 'v':
  s_dot();
  s_dot();
  s_dot();
  s_dash();
  delay(speed);    
  break;
  case 'w':
  s_dot();
  s_dash();
  s_dash();
  delay(speed);    
  break;
  case 'x':
  s_dash();
  s_dot();
  s_dot();  
  s_dash();
  delay(speed);    
  break;
  case 'y':
  s_dash();
  s_dot();
  s_dash();
  s_dash();
  delay(speed);    
  break;
  case 'z':
  s_dash();
  s_dash();
  s_dot();
  s_dot();
  delay(speed);    
  break;
  case '0':
  s_dash();
  s_dash();
  s_dash();
  s_dash();
  s_dash();
  delay(speed);    
  break;
  case '1':
  s_dot();
  s_dash();
  s_dash();
  s_dash();
  s_dash();
  delay(speed);    
  break;
  case '2':
  s_dot();
  s_dot();
  s_dash();
  s_dash();
  s_dash();
  delay(speed);    
  break;
  case '3':
  s_dot();
  s_dot();
  s_dot();
  s_dash();
  s_dash();
  delay(speed);    
  break;
  case '4':
  s_dot();
  s_dot();
  s_dot();
  s_dot();
  s_dash();
  delay(speed);    
  break;
  case '5':
  s_dot();
  s_dot();
  s_dot();
  s_dot();
  s_dot();
  delay(speed);    
  break;
  case '6':
  s_dash();
  s_dot();
  s_dot();
  s_dot();
  s_dot();
  delay(speed);    
  break;
  case '7':
  s_dash();
  s_dash();
  s_dot();
  s_dot();
  s_dot();
  delay(speed);    
  break;
  case '8':
  s_dash();
  s_dash();
  s_dash();
  s_dot();
  s_dot();
  delay(speed);    
  break;   
  case '9':
  s_dash();
  s_dash();
  s_dash();
  s_dash();
  s_dot();
  delay(speed);    
  break;                    
  case ' ':
  delay(2*speed);
  break;
  case '?':
  s_dot();
  s_dot();
  s_dash();
  s_dash();
  s_dot();
  s_dot();
  delay(speed);    
  break;
  case '.':
  s_dot();
  s_dash();
  s_dot();
  s_dash();
  s_dot();
  s_dash();
  delay(speed);    
  break;
  case '=':
  s_dash();
  s_dot();
  s_dot();
  s_dot();
  s_dash();
  delay(speed);    
  break;
  case ',':
  s_dash();
  s_dash();
  s_dot();
  s_dot();
  s_dash();
  s_dash();
  delay(speed);    
  break; 
  case '!':
  s_dash();
  s_dot();  
  s_dash();
  s_dot();
  s_dash();
  s_dash();
  delay(speed);    
  break;
  case '"':
  s_dot(); 
  s_dash();
  s_dot(); 
  s_dot(); 
  s_dash();
  s_dot(); 
  delay(speed);    
  break;
  case '(':
  s_dash();
  s_dot(); 
  s_dash();
  s_dash();
  s_dot(); 
  delay(speed);    
  break;
  case ')':
  s_dash();
  s_dot(); 
  s_dash();
  s_dash();
  s_dot();
  s_dash(); 
  delay(speed);    
  break;
  case '&':
  s_dot();
  s_dash();
  s_dot(); 
  s_dot();
  s_dot();
  delay(speed);    
  break;
  case ':':
  s_dash();
  s_dash();
  s_dash();
  s_dot(); 
  s_dot();
  s_dot();
  delay(speed);    
  break;
  case ';':
  s_dash();
  s_dot(); 
  s_dash();
  s_dot();
  s_dash();
  s_dot();
  delay(speed);    
  break;
  case '/':
  s_dash();
  s_dot();
  s_dot(); 
  s_dash();
  s_dot();
  delay(speed);    
  break;
  case '_':
  s_dot();
  s_dot(); 
  s_dash();
  s_dot();
  s_dash();
  delay(speed);    
  break;
  case '+':
  s_dot();
  s_dash();
  s_dot(); 
  s_dash();
  s_dot();
  delay(speed);    
  break; 
  case '-':
  s_dash();
  s_dot(); 
  s_dot();
  s_dot();
  s_dot();
  s_dash();
  delay(speed);    
  break;
  case '$':
  s_dot(); 
  s_dot();
  s_dot();
  s_dash();
  s_dot();
  s_dot();
  s_dash();
  delay(speed);    
  break;
  case '@':
  s_dot();
  s_dash();
  s_dash(); 
  s_dot();
  s_dash(); 
  s_dot();
  delay(speed);    
  break;                     
}
  

  
}
