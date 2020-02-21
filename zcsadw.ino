#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
byte black[8]{
  255,255,255,255,255,255,255,255,};

bool J1=0,K1=0,Q1=0;
bool J0=0,K0=0,Q0=0;
bool X=0,Y=0;
bool Z1=0,Z0=0;
int i=0,h=0;
int j=0;//12 11 10 K9
char P[100];
unsigned long millist;

void setup() {
  lcd.createChar(0,black);
  lcd.begin(40,2);
  pinMode(12,INPUT);
  pinMode(11,INPUT);
  pinMode(10,INPUT);
  pinMode(9,INPUT);
  pinMode(8,INPUT);
  pinMode(0,OUTPUT);
  digitalWrite(0,LOW);
  pinMode(1,OUTPUT);
  digitalWrite(1,LOW);}

void loop() {
  elevatorprint();
  if(digitalRead(9)==1){
    millist=millis();j=0;
    while(millis()-millist<=250){
      delay(1);
      setlvl();
      if (digitalRead(8)==0){delay(500);break;}}} 
    if (j<i){X=0;Y=0;}
    if (j>i){X=0;Y=1;}
    if (i==j){X=1;Y=0;}
    equff();ff0();ff1();equz();
    if(Z1==0 && Z0==0){i=i;digitalWrite(1,LOW);digitalWrite(0,LOW);}
    if(Z1==1 && Z0==0){i++;digitalWrite(1,HIGH);digitalWrite(0,LOW);}
    if(Z1==0 && Z0==1){i--;digitalWrite(1,LOW);digitalWrite(0,HIGH);}}
    
void ff0(){
  if (J0==0 && K0==0){Q0=Q0;}
  if (J0==0 && K0==1){Q0=0;}
  if (J0==1 && K0==0){Q0=1;}
  if (J0==1 && K0==1){Q0=!(Q0);}}
void ff1(){
  if (J1==0 && K1==0){Q1=Q1;}
  if (J1==0 && K1==1){Q1=0;}
  if (J1==1 && K1==0){Q1=1;}
  if (J1==1 && K1==1){Q1=!(Q1);}}
void equff(){
  J1=(!X)&&(!Y)&&!(Q0);
  K1=X||Y||Q0;
  J0=Y&&(!X)&&!(Q1);
  K0=(!Y)||X||Q1;}
void equz(){
  Z1=Q0&&!(Q1);
  Z0=!(Q0)&&Q1;}
void setlvl(){
  if (digitalRead(12)==0){j=4;}
  if (digitalRead(12)==1){j=0;}
  if (digitalRead(11)==0){j=j+2;}
  if (digitalRead(11)==1){j=j+0;}
  if (digitalRead(10)==0){j=j+1;}
  if (digitalRead(10)==1){j=j+0;}}
void elevatorprint(){
  if(i!=h){delay(500);lcd.clear();h=i;}  
  lcd.setCursor(5*i,0);
  lcd.write(byte(0));
  lcd.write(byte(0));
  lcd.write(byte(0));
  lcd.write(byte(0));
  lcd.write(byte(0));
  lcd.setCursor(5*i,1);
  lcd.write(byte(0));
  lcd.write(byte(0));
  lcd.write(byte(0));
  lcd.write(byte(0));
  lcd.write(byte(0));}
