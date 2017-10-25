import g4p_controls.*;//importamos libreria

GLabel lbTipeVehicule;//objeto tipo label
GButton bStart;
GToggleGroup togG1Options;
GCheckbox cbx;
GTextField txf1;


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

  cbx=new GCheckbox(this,5,15,110,40,"Antiorario");

  txf1 = new GTextField(this, 10, 60, 60, 20);
  txf1.tag = "txf1";
  txf1.setPromptText("Set Steps");

}
public void handleButtonEvents(GButton button, GEvent event) {
  if(button==bStart&&event==GEvent.PRESSED){
    println("Me presionaron!! ");
    if(flag_Dir){
      
    }
  }
}
public void handleToggleControlEvents(GToggleControl option, GEvent event) {
  if(option == cbx){
    if(flag_Dir)
      flag_Dir = false;
    else  flag_Dir = true;
    println("Me Selecionaron !! ");
  }
}
public void handleTextEvents(GEditableTextControl textcontrol, GEvent event) {
  if(textcontrol == txf1){
    println(txf1.getText());
  }
}
