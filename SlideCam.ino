#include <Stepper.h>
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor
#define lengthComand 8 //defino tamaño de los comando a recibir

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

char arrayComand [lengthComand];
int p=0;
void setup() {
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

}
