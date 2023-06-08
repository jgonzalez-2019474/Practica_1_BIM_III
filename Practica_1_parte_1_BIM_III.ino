/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Javier Andre Gonzalez Barrera
 * Carnet: 2019474
 * Proyecto: Practica #3
*/

//defino los pines de los pulsadores
#define btn_rising 2
#define btn_falling 3

//Configuracion de los botones
void funcion_ISR_rising();
void funcion_ISR_falling();

//variables
volatile static bool f_print = false;
volatile static bool r_print = false;
volatile static byte i = 0;
int digito = 0;
bool estado;

//Configuracion de entradas
void ConfigPinesInput();

//Configuracion de salidas
void ConfigPinesOutput();
 
//Configuracion de los diplays
void Config_diplay_1_segments(int a, int b, int c, int d, int e, int f, int g);
void Config_diplay_2_segments(int a2, int b2, int c2, int d2, int e2, int f2, int g2);

void setup(){
  Serial.begin(19200);
  ConfigPinesInput();
  ConfigPinesOutput();
  attachInterrupt(digitalPinToInterrupt(btn_rising), funcion_ISR_rising, RISING);
  attachInterrupt(digitalPinToInterrupt(btn_falling), funcion_ISR_falling, FALLING);
}
void loop() {
  f_print = false; //limpio la variable
  r_print = false; //limpio la variable
  Serial.println(i); //imprimo el valor de I
  
   if(digito == 0)   {
   Config_diplay_2_segments(1,1,1,1,1,1,0); //muestra 0
   Config_diplay_1_segments(1,1,1,1,1,1,0); //muestra 0
  }
  if(digito == 1) {
   Config_diplay_2_segments(1,1,1,1,1,1,0); //muestra 0
   Config_diplay_1_segments(0,1,1,0,0,0,0); //muestra 1      
  }
  if(digito == 2) {
   Config_diplay_2_segments(1,1,1,1,1,1,0); //muestra 0
   Config_diplay_1_segments(1,1,0,1,1,0,1); //muestra 2  
  }
  if(digito == 3)  {
   Config_diplay_2_segments(1,1,1,1,1,1,0); //muestra 0  
   Config_diplay_1_segments(1,1,1,1,0,0,1); //muestra 3
  }
  if(digito == 4) {
   Config_diplay_2_segments(1,1,1,1,1,1,0); //muestra 0
   Config_diplay_1_segments(0,1,1,0,0,1,1); //muestra 4
  }
  if(digito == 5) {
   Config_diplay_2_segments(1,1,1,1,1,1,0); //muestra 0  
   Config_diplay_1_segments(1,0,1,1,0,1,1); //muestra 5
  }  
   if(digito == 6) {
   Config_diplay_2_segments(1,1,1,1,1,1,0); //muestra 0  
   Config_diplay_1_segments(1,0,1,1,1,1,1); //muestra 6
  }  
   if(digito == 7)  {
   Config_diplay_2_segments(1,1,1,1,1,1,0); //muestra 0  
   Config_diplay_1_segments(1,1,1,0,0,0,0); //muestra 7
  }
   if(digito == 8) {
   Config_diplay_2_segments(1,1,1,1,1,1,0); //muestra 0  
   Config_diplay_1_segments(1,1,1,1,1,1,1); //muestra 8
  }
  if(digito == 9) {
   Config_diplay_2_segments(1,1,1,1,1,1,0); //muestra 0
   Config_diplay_1_segments(1,1,0,1,1,1,1); //muestra 9
  }
  if(digito == 10) {
   Config_diplay_2_segments(1,1,1,1,1,1,0); //muestra 1
   Config_diplay_1_segments(1,1,0,1,1,1,1); //muestra 0
  }
  if(digito == 11)  {
   Config_diplay_2_segments(0,1,1,0,0,0,0); //muestra 1
   Config_diplay_1_segments(1,1,1,1,1,1,0); //muestra 1
  }
  if(digito == 12) {
   Config_diplay_2_segments(0,1,1,0,0,0,0); //muestra 1
   Config_diplay_1_segments(1,1,1,1,1,1,0); //muestra 2
  }
  if(digito == 13) {
   Config_diplay_2_segments(0,1,1,0,0,0,0); //muestra 1
   Config_diplay_1_segments(1,1,1,1,1,1,0); //muestra 3
  }
  if(digito == 14) {
   Config_diplay_2_segments(0,1,1,0,0,0,0); //muestra 1
   Config_diplay_1_segments(0,1,1,0,0,1,1); //muestra 4
  }
  if(digito == 15)  {
    Config_diplay_2_segments(0,1,1,0,0,0,0); //muestra 1
    Config_diplay_1_segments(1,0,1,1,0,1,1); //muestra 5
  }
  if(digito == 16) {
    Config_diplay_2_segments(0,1,1,0,0,0,0); //muestra 1
    Config_diplay_1_segments(1,0,1,1,1,1,1); //muestra 6
  }
  if(digito == 17) {
    Config_diplay_2_segments(0,1,1,0,0,0,0); //muestra 1
    Config_diplay_1_segments(1,1,1,0,0,0,0); //muestra 7
  }
  if(digito == 18) {
    Config_diplay_2_segments(0,1,1,0,0,0,0); //muestra 1
    Config_diplay_1_segments(1,1,1,1,1,1,1); //muestra 8
  }
  if(digito == 19) {
    Config_diplay_2_segments(0,1,1,0,0,0,0); //muestra 1
    Config_diplay_1_segments(1,1,1,0,0,1,1); //muestra 9
  }
  if(digito == 20) {
    Config_diplay_2_segments(1,1,0,1,1,0,1); //muestra 2
    Config_diplay_1_segments(1,1,1,1,1,1,0); //muestra 0
  }
  if(digito == 21) {
    Config_diplay_2_segments(1,1,0,1,1,0,1); //muestra 2
    Config_diplay_1_segments(0,1,1,0,0,0,0); //muestra 1
  }
  if(digito == 22) {
    Config_diplay_2_segments(1,1,0,1,1,0,1); //muestra 2
    Config_diplay_1_segments(1,1,0,1,1,0,1); //muestra 2
  }
  if(digito == 23) {
    Config_diplay_2_segments(1,1,0,1,1,0,1); //muestra 2
    Config_diplay_1_segments(1,1,1,1,0,0,1); //muestra 3
  }
  if(digito == 24) {
    Config_diplay_2_segments(1,1,0,1,1,0,1); //muestra 2
    Config_diplay_1_segments(0,1,1,0,0,1,1); //muestra 4
  }
  if(digito == 25) {
    Config_diplay_2_segments(1,1,0,1,1,0,1); //muestra 2
    Config_diplay_1_segments(1,0,1,1,0,1,1); //muestra 5
  }
  if(digito == 26) {
    Config_diplay_2_segments(1,1,0,1,1,0,1); //muestra 2
    Config_diplay_1_segments(1,0,1,1,1,1,1); //muestra 6
  }
  if(digito == 27) {
    Config_diplay_2_segments(1,1,0,1,1,0,1); //muestra 2
    Config_diplay_1_segments(1,1,1,0,0,0,0); //muestra 7
  }
  if(digito == 28) {
    Config_diplay_2_segments(1,1,0,1,1,0,1); //muestra 2
    Config_diplay_1_segments(1,1,1,1,1,1,1); //muestra 8
  }
  if(digito == 29) {
    Config_diplay_2_segments(1,1,0,1,1,0,1); //muestra 2
    Config_diplay_1_segments(1,1,1,0,0,1,1); //muestra 9
  }
  if(digito == 30) {
    Config_diplay_2_segments(1,1,1,1,0,0,1); //muestra 3
    Config_diplay_1_segments(1,1,1,1,1,1,0); //muestra 0
  }
  if(digito == 31){
    Config_diplay_2_segments(1,1,1,1,0,0,1); //muestra 3  
    Config_diplay_1_segments(0,1,1,0,0,0,0); //muestra 1
  }
  if(digito == 32) {
    Config_diplay_2_segments(1,1,1,1,0,0,1); //muestra 3  
    Config_diplay_1_segments(1,1,0,1,1,0,1); //muestra 2
  }
  if(digito == 33) {
    Config_diplay_2_segments(1,1,1,1,0,0,1); //muestra 3  
    Config_diplay_1_segments(1,1,1,1,0,0,1); //muestra 3
  }
  if(digito == 34) {
    Config_diplay_2_segments(1,1,1,1,0,0,1); //muestra 3  
    Config_diplay_1_segments(0,1,1,0,0,1,1); //muestra 4      
  }
  if(digito == 35) {
    Config_diplay_2_segments(1,1,1,1,0,0,1); //muestra 3  
    Config_diplay_1_segments(1,0,1,1,0,1,1); //muestra 5
  }
  if(digito == 36)  {
    Config_diplay_2_segments(1,1,1,1,0,0,1); //muestra 3  
    Config_diplay_1_segments(1,0,1,1,1,1,1); //muestra 6
  }
  if(digito == 37) {
    Config_diplay_2_segments(1,1,1,1,0,0,1); //muestra 3  
    Config_diplay_1_segments(1,1,1,0,0,0,0); //muestra 7
  }
  if(digito == 38)  {
    Config_diplay_2_segments(1,1,1,1,0,0,1); //muestra 3  
    Config_diplay_1_segments(1,1,1,1,1,1,1); //muestra 8
  }
  if(digito == 39)  {
    Config_diplay_2_segments(1,1,1,1,0,0,1); //muestra 3  
    Config_diplay_1_segments(1,1,1,0,0,1,1); //muestra 9
  }
  if(digito == 40) {
    Config_diplay_2_segments(0,1,1,0,0,1,1); //muestra 4
    Config_diplay_1_segments(1,1,1,1,1,1,0); //muestra 0  
  }
  if(digito == 41) {
    Config_diplay_2_segments(0,1,1,0,0,1,1); //muestra 4
    Config_diplay_1_segments(0,1,1,0,0,0,0); //muestra 1  
  }
  if(digito == 42){
    Config_diplay_2_segments(0,1,1,0,0,1,1); //muestra 4
    Config_diplay_1_segments(1,1,0,1,1,0,1); //muestra 2  
  }
  if(digito == 43){
    Config_diplay_2_segments(0,1,1,0,0,1,1); //muestra 4
    Config_diplay_1_segments(1,1,1,1,0,0,1); //muestra 3  
  }
  if(digito == 44) {
    Config_diplay_2_segments(0,1,1,0,0,1,1); //muestra 4
    Config_diplay_1_segments(0,1,1,0,0,1,1); //muestra 4  
  }
  if(digito == 45){
    Config_diplay_2_segments(0,1,1,0,0,1,1); //muestra 4
    Config_diplay_1_segments(1,0,1,1,0,1,1); //muestra 5  
  }
  if(digito == 46){
    Config_diplay_2_segments(0,1,1,0,0,1,1); //muestra 4
    Config_diplay_1_segments(1,0,1,1,1,1,1); //muestra 6
  }
  if(digito == 47) {
    Config_diplay_2_segments(0,1,1,0,0,1,1); //muestra 4
    Config_diplay_1_segments(1,1,1,0,0,0,0); //muestra 7  
  }
  if(digito == 48) {
    Config_diplay_2_segments(0,1,1,0,0,1,1); //muestra 4
    Config_diplay_1_segments(1,1,1,1,1,1,1); //muestra 8  
  }
  if(digito == 49) {
    Config_diplay_2_segments(0,1,1,0,0,1,1); //muestra 4
    Config_diplay_1_segments(1,1,1,0,0,1,1); //muestra 9  
  }
  if(digito == 50) {
    Config_diplay_2_segments(1,0,1,1,0,1,1); //muestra 5
    Config_diplay_1_segments(1,1,1,1,1,1,0); //muestra 0  
  }
    
}
void ConfigPinesInput() {
    pinMode(btn_rising, INPUT);
    pinMode(btn_falling, INPUT);
  }
void ConfigPinesOutput()
  {
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(14, OUTPUT);
    pinMode(15, OUTPUT);
    pinMode(16, OUTPUT);
    pinMode(17, OUTPUT);
    pinMode(18, OUTPUT);
  }
void Config_diplay_1_segments(int a, int b, int c, int d, int e, int f, int g) {
    digitalWrite(4,a);
    digitalWrite(5,b);
    digitalWrite(6,c);
    digitalWrite(7,d);
    digitalWrite(8,e);
    digitalWrite(9,f);
    digitalWrite(10,g);
  }
void Config_diplay_2_segments(int a2, int b2, int c2, int d2, int e2, int f2, int g2) {
    digitalWrite(11, a2);
    digitalWrite(12, b2);
    digitalWrite(14, c2);
    digitalWrite(15, d2);
    digitalWrite(16, e2);
    digitalWrite(17, f2);
    digitalWrite(18, g2);
  }
   
void funcion_ISR_rising(){
   if( digito > 50) {
      digito = 0;
      digito++;
      }
    
}
void funcion_ISR_falling(){
    if( digito < 0) {
      digito = 50;
      digito--;
      }
}  
 
