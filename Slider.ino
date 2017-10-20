int dir = 1;
long countStep = 0;
long maxStep = 0;
boolean d = true;
long rpm = 0;

void setRPM(long r){
  myStepper.setSpeed(r); 
  Serial.print("rpm: ");
  Serial.println(r,DEC);
}
void setDir(){
  if (d){
    dir=-1;
    d=false;  
  }
    else{
      dir=1;
      d=true;
    }
 Serial.print("dir: ");
 Serial.println(dir,DEC);
    
}
void movSlide(long steps){
 long s=0;
  while(init_f ==false && final_f == false && s<=steps){
   myStepper.step(dir*1);
   countStep=countStep+(dir*1);
   s++; 
  }
  freePaP(); 
}
long getCountStep(){
  Serial.println (countStep);
}
void freePaP(){
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
  }
void goHome(){
  if(digitalRead(initSw)){
    dir=-1; 
    while(init_f == false){
      movSlide(100000);
    } 
    countStep=0;
  }
   
}
void calibrate(){
    setRPM(100);
    while(init_f == false && final_f == false){
      movSlide(100000);
    }
    maxStep=countStep;
  }
  
