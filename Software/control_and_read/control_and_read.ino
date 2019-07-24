unsigned int CLK = 5; // verde ccd 
unsigned int ROG = 4;  //azul ccd
unsigned int t = 30; //meio periodo de clock //T=2*t +5 us
//unsigned long time1,time2;
int a[2089];
//unsigned int leitura=0;
unsigned int tint,time1,time2;
TaskHandle_t Task1;
TaskHandle_t Task2;



void setup() {
  Serial.begin(115200); 
  pinMode(ROG,OUTPUT);
  pinMode(CLK,OUTPUT);


  //create a task that will be executed in the Task1code() function, with priority 1 and executed on core 0
  xTaskCreatePinnedToCore(
                    Task1code,   /* Task function. */
                    "Task1",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task1,      /* Task handle to keep track of created task */
                    0);          /* pin task to core 0 */                  
  delay(500); 

  //create a task that will be executed in the Task2code() function, with priority 1 and executed on core 1
  xTaskCreatePinnedToCore(
                    Task2code,   /* Task function. */
                    "Task2",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task2,      /* Task handle to keep track of created task */
                    1);          /* pin task to core 1 */
    delay(500); 
}

//Controle de Pulsos e tempo de integração
void Task1code( void * pvParameters ){
  //Serial.print("Task1 running on core ");
  //Serial.println(xPortGetCoreID());

  for(;;){
time1 = micros();
  delayMicroseconds(18*t); //t9 rog pulse low
  digitalWrite(ROG, HIGH);
  delayMicroseconds(12*t); //t11
//  leitura = 1;
  for(int i=0; i<2088; i++)
    {
        digitalWrite(CLK, HIGH);
        delayMicroseconds(t);
        digitalWrite(CLK, LOW);
        a[i]=analogRead(A0);
        delayMicroseconds(t-11);
    }
    
  //leitura=0;
  delay(1000);
  digitalWrite(CLK, HIGH);     
  delayMicroseconds(20*t); //t7
  digitalWrite(ROG, LOW);
  //delay(200);
  time2 = micros();
  tint = time2-time1; 
  //Serial.println(time2 - time1); 
  } 
}

//Leitura do sensor
void Task2code( void * pvParameters ){
  //Serial.print("Task2 running on core ");
  //Serial.println(xPortGetCoreID());

  for(;;){
    if(Serial.available()){
      char n;
      n=Serial.read();
      if (n=='a'){
        
        for(int x=1; x<=2086;x++){
              //a[i]=analogRead(A0); 
              //delayMicroseconds(2*t -1);
              delayMicroseconds(3); 
              Serial.print(a[x]);
              Serial.print(" ");
              }   
        Serial.println();

      }
         if (n=='t') {
        Serial.println(tint);
        }
      n=0;
    }
  }
}

void loop() {
}
