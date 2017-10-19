int dir = 0;
long countStep = 0;
boolean d = true;

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
  myStepper.step(dir*steps);
  countStep=countStep+(dir*steps);
}
long getCountStep(){
  Serial.println (countStep);
}

