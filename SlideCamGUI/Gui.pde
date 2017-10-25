import g4p_controls.*;//importamos libreria

GLabel lbTipeVehicule;//objeto tipo label
GButton bStart;
GToggleGroup togG1Options;
GCheckbox cbx;
GTextField txfStep,txfRPM;


boolean flag_Dir = false;

void initGui( ) {
  G4P.setGlobalColorScheme(GCScheme.BLUE_SCHEME);
  G4P.setCursor(ARROW);
  surface.setTitle("Control Slider");
  createControlGruop();
}
void createControlGruop( ) {
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
  //  if(flag_Dir){
  //    myPort.write("%101000%");
    //}else myPort.write("%101000%");
    String s = "%102"+txfStep.getText()+"%";
    myPort.write(s);
  }
}
public void handleToggleControlEvents(GToggleControl option, GEvent event) {
  if(option == cbx && event == GEvent.SELECTED){
    myPort.write("%101000%");
    println("Me Selecionaron !! ");
  }else if (event == GEvent.DESELECTED ) myPort.write("%101001%");
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
