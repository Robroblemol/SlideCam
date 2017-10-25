import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 
import g4p_controls.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class SlideCamGUI extends PApplet {




Serial myPort;

public void setup() {
    
    printArray(Serial.list());
    myPort = new Serial(this, Serial.list()[4], 9600,'N',8,1);
    myPort.write("%102100%");
    initGui();
 }
public void draw(){
  background(213, 245, 213);
  if(myPort.available() > 0) {
    String inByte = myPort.readString();
    println(inByte);
  }
}
//importamos libreria

GLabel lbTipeVehicule;//objeto tipo label
GButton bStart;
GToggleGroup togG1Options;
GCheckbox cbx;
GTextField txfStep,txfRPM;


boolean flag_Dir = false;

public void initGui( ) {
  G4P.setGlobalColorScheme(GCScheme.BLUE_SCHEME);
  G4P.setCursor(ARROW);
  surface.setTitle("Control Slider");
  createControlGruop();
}
public void createControlGruop( ) {
  bStart = new GButton(this,80,130,100,35,"Ejecutar");
  bStart.fireAllEvents(true);//Habilitamos toda las clases dissparos

  lbTipeVehicule = new GLabel(this, 73, 5, 159, 25);
  lbTipeVehicule.setText("Control Slide Cam");

  cbx=new GCheckbox(this,5,15,110,40,"Anti-Horario");

  txfStep = new GTextField(this, 10, 60, 60, 20);
  txfStep.tag = "txfStep";
  txfStep.setPromptText("Set Steps");
  txfRPM = new GTextField(this,130,60,60,20);
  txfRPM.tag = "txfRPM";
  txfRPM.setPromptText("Set RMP");


}
public void handleButtonEvents(GButton button, GEvent event) {
  if(button==bStart&&event==GEvent.PRESSED){
    println("Me presionaron!! ");
    if(flag_Dir){
      myPort.write("%101000%");
    }else myPort.write("%101000%");
    String s = "%102"+txfStep.getText()+"%";
    myPort.write(s);
  }
}
public void handleToggleControlEvents(GToggleControl option, GEvent event) {
  if(option == cbx && event == GEvent.SELECTED){
    if(flag_Dir)
      flag_Dir = false;
    else  flag_Dir = true;
    println("Me Selecionaron !! ");
  }
}
public void handleTextEvents(GEditableTextControl textcontrol, GEvent event) {
  if(textcontrol == txfStep && event == GEvent.ENTERED){
    println(txfStep.getText());
  }
  if(textcontrol == txfRPM && event == GEvent.ENTERED){
    println(txfRPM.getText());
    myPort.write("%100"+txfRPM.getText()+"%");
  }
}
  public void settings() {  size(250,200 ); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "SlideCamGUI" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
