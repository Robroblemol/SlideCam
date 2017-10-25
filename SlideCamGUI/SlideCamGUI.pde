

import processing.serial.*;
Serial myPort;

void setup() {
    size(250,200 );
    printArray(Serial.list());
    myPort = new Serial(this, Serial.list()[4], 9600,'N',8,1);
    myPort.write("%102100%");
    initGui();
 }
void draw(){
  background(213, 245, 213);
  if(myPort.available() > 0) {
    String inByte = myPort.readString();
    println(inByte);
  }
}
