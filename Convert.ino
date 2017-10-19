int convertToInt(char c){
  //Serial.println(c-'0');
  return c = c-'0';  
  }
int getComand(char a []){
  return (convertToInt(a[1])*100)+
         (convertToInt(a[2])*10)+
         convertToInt(a[3]);
}
long getValue(char a []){
  return (convertToInt(a[4])*100)+
          (convertToInt(a[5])*10)+
          convertToInt(a[6]);
}

