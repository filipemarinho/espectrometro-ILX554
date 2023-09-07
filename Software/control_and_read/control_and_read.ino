unsigned int CLK = 5;     //Verde 
unsigned int ROG = 4;     //Azul
unsigned int t = 30; //meio periodo de clock tint = (2*t +5) us
unsigned int integra = 1000;
int a[2089];
unsigned int tint,time1,time2;
TaskHandle_t Task1;
TaskHandle_t Task2;



void setup() {
  Serial.begin(115200); 
  pinMode(ROG,OUTPUT);
  pinMode(CLK,OUTPUT);

  //cria a task que será executada na fução Task1code()
  xTaskCreatePinnedToCore(Task1code, "Task1", 10000     , NULL, 1         , &Task1, 0   );
//xTaskCreatePinnedToCore(funcao   ,  nome  , Stack size,     , prioridade, handle, core);                  
  delay(500); 

  //cria a task que será executada na fução Task2code()
  xTaskCreatePinnedToCore(Task2code, "Task2", 10000     , NULL, 1         , &Task2, 1   );
//xTaskCreatePinnedToCore(funcao   ,  nome  , Stack size,     , prioridade, handle, core);
  delay(500); 
}

//Controle de Pulsos e tempo de integração
void Task1code( void * pvParameters ){
  //Serial.println(xPortGetCoreID());  //retorna o core atual

 for(;;){
  time1 = micros();
  delayMicroseconds(18*t);          //t9 rog pulse low
  digitalWrite(ROG, HIGH);
  delayMicroseconds(12*t);          //t11
  
  for(int i=0; i<2088; i++) {
    digitalWrite(CLK, HIGH);
    delayMicroseconds(t);
    digitalWrite(CLK, LOW);
    a[i]=analogRead(A0);
    delayMicroseconds(t-11);        // 11uS = adc read time
  }

  delay(integra + 10);
  digitalWrite(CLK, HIGH);     
  delayMicroseconds(20*t); //t7
  digitalWrite(ROG, LOW);
  time2 = micros();
  tint = time2-time1;
 } 
}

//No segundo core:
void Task2code( void * pvParameters ){
  //Serial.println(xPortGetCoreID());  //retorna o core atual

  for(;;){
    if(Serial.available()){
      char n;
      n=Serial.read();
        
      if (n=='m'){
        leitura();
      }
      
      if (n=='x'){
        for (int j=0;j<10;j++) {
          leitura();
          delay(tint);
        }
      }
      if (n=='t') {
        Serial.println(tint/1000);
      }
      
      if (n=='w') {
        integra += 500;
      }
      
      if (n=='s') {
        integra -= 500;
      }
      
      if (n=='d') {
        integra += 100;
      }
      
      if (n=='a') {
        integra -= 100;
      }
      
      n='';
   }
  }
}

//função auxiliar para leitura
void leitura() {
  for(int x=1; x<=2086;x++){
    delayMicroseconds(3); 
    Serial.print(a[x]);
    Serial.print(" ");
  }   
  Serial.println(); 
}

void loop() {
  delay(100);
}
