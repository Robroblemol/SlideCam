#include <Stepper.h>
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
const byte initSw = 2;
const byte finalSw =3;
// for your motor
#define lengthComand 8 //defino tamaño de los comando a recibir

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

char arrayComand [lengthComand];
int p=0;
volatile boolean init_f = false;
volatile boolean final_f = false;

void setup() {
  pinMode(initSw,INPUT);// set initial position sw
  pinMode(finalSw,INPUT);//set final position sw
  attachInterrupt(digitalPinToInterrupt(initSw),swInit,FALLING);
  attachInterrupt(digitalPinToInterrupt(finalSw),swFinal,FALLING);
  // set the speed at 60 rpm:
  myStepper.setSpeed(25);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
   if (Serial.available()) {
      if(p<=lengthComand){
        arrayComand[p]=Serial.read();
        Serial.print(p,DEC);
        Serial.println(arrayComand[p]);
        p++; 
      }  
  }
  if(arrayComand[0]=='%'&&arrayComand[lengthComand-1]=='%'){
      DriverSlide(getComand(arrayComand),getValue(arrayComand));
      Serial.println("ACK");
   }
   if(p==lengthComand){
    p=0;
      memset(arrayComand, 0,sizeof(arrayComand));
   }
   if(init_f){
    Serial.println("Home");
    init_f=false;
   }
   
   if(final_f){
    Serial.println("End");
    final_f=false;
   }
}

void swInit(){
    init_f = true;
  }
void swFinal(){
    final_f = true;
  }

