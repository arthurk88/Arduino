// CONSTANTES ===============================
#define led1 11 
#define led2 10 
#define led3 9 
#define led4 6 
#define led5 5 
#define led6 3 
#define pot A0
//===========================================

//DEFINIÇÕES de ENTRADA E SAIDA =============
void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(A0, INPUT);
}

// LEITURA PORT ANALOGIVA COM CONVERSÃO MAP PARA ~PWN ==========
void loop()
{
 int v = map(analogRead(pot),0,1023,0,255); 
  if((v >= 0) and (v <= 43)){
   int i1 = map(v,0,43,0,255);
   analogWrite(led1,i1);
   analogWrite(led2,LOW);     
  }else if((v >= 43) and (v <= 86)){
   int i2 = map(v,43,86,0,255);
   analogWrite(led2,i2);
   analogWrite(led3,LOW);  
  }else if((v >= 86) and (v <= 129)){
   int i3 = map(v,86,129,0,255);
   analogWrite(led3,i3);
   analogWrite(led4,LOW);  
  }else if((v >= 129) and (v <= 172)){
   int i4 = map(v,129,172,0,255);
   analogWrite(led4,i4);
   analogWrite(led5,LOW);  
  }else if((v >= 172) and (v <= 225)){
   int i5 = map(v,172,225,0,255);
   analogWrite(led5,i5);
   analogWrite(led6,LOW);  
  }else if((v >= 225) and (v <= 255)){
   int i6 = map(v,225,255,0,255);
   analogWrite(led6,i6);  
  }
}
//===========================================
