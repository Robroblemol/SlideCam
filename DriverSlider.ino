void DriverSlide(int p,long v){
  Serial.print("p: ");
  Serial.println(p,DEC);
  switch (p){
    case 100:
      setRPM (v);
      break;
    case 101:
      setDir();
      break;
    case 102:
      movSlide(v);
      break;
    case 103:
      getCountStep();
    default:
      break;
  }
  
}

