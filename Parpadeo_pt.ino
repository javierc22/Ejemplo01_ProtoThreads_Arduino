#include <pt.h>

struct pt hilo1;
struct pt hilo2;
struct pt hilo3;

void setup() {
  // put your setup code here, to run once:
  PT_INIT(&hilo1); // Inicia función parpadeo1();
  PT_INIT(&hilo2);
  PT_INIT(&hilo3);
}

void loop() {
  // put your main code here, to run repeatedly:
  parpadeo1(&hilo1);
  parpadeo2(&hilo2);
  parpadeo3(&hilo3);
}

void parpadeo1(struct pt *pt) {
  PT_BEGIN(pt); // Aquí inicia mi ProtoThreads

  static long tiempo = 0;
  pinMode(8, OUTPUT);

  do {
     digitalWrite(8, HIGH);
     tiempo = millis();
     PT_WAIT_WHILE(pt, (millis()-tiempo) < 1000); // Esperar por 1 segundo (1era forma)

     digitalWrite(8, LOW);
     tiempo = millis();
     PT_WAIT_UNTIL(pt, (millis()-tiempo) >= 1000); // Esperar hasta 1 segundo (2da forma)
  } while (true);
      
  PT_END(pt); // Aquí finaliza mi ProtoThreads
}

void parpadeo2(struct pt *pt) {
  PT_BEGIN(pt); // Aquí inicia mi ProtoThreads

  static long tiempo = 0;
  pinMode(9, OUTPUT);
  
  do {
    digitalWrite(9, HIGH);
    tiempo = millis();
    PT_WAIT_WHILE(pt, (millis()-tiempo) < 500); // Esperar por 500 milisegundos (1era forma)
    
    digitalWrite(9, LOW);
    tiempo = millis();
    PT_WAIT_UNTIL(pt, (millis()-tiempo) >= 500); // Esperar hasta 500 milisegundos (2da forma)
  } while(true);
  
  PT_END(pt); // Aquí finaliza mi ProtoThreads
}

void parpadeo3(struct pt *pt) {
  PT_BEGIN(pt); // Aquí inicia mi ProtoThreads

  static long tiempo = 0;
  pinMode(10, OUTPUT);
  
  do {
    digitalWrite(10, HIGH);
    tiempo = millis();
    PT_WAIT_WHILE(pt, (millis()-tiempo) < 250); // Esperar por 250 milisegundos (1era forma)
    
    digitalWrite(10, LOW);
    tiempo = millis();
    PT_WAIT_UNTIL(pt, (millis()-tiempo) >= 250); // Esperar hasta 250 milisegundos (2da forma)
  } while(true);
  
  PT_END(pt); // Aquí finaliza mi ProtoThreads
}
