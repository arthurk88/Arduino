#define ledR 6
#define ledG 3
#define ledB 5
#define botao 7

// class modo classico 
class Bt{
  public:
  int btup,btdown,pino;
  
  Bt(int p){
    pino=p;
    btup=btdown=0;
  }
  bool press(){
    if(digitalRead(pino) == HIGH){
     btup=1;
     btdown=0;
    }else{
     btdown=1; 
    }
    if((btup==1)and(btdown==1)){
      btup=0;
      btdown=0;
      return true;
    }else{
      return false;
    } 
  }
};
// class moderna com lista de inicialização

class Cor{
public:
  int pinoR,pinoG,pinoB,ciclo,maximo;
  
  Cor(int pr,int pg,int pb):pinoR(pr),pinoG(pg),pinoB(pb){
    ciclo = 0;
    maximo = 3;
  }
  void trocaLed(){
    if(ciclo == 0){
     corLed(1,0,0); 
    }else if(ciclo == 1){
     corLed(0,1,0); 
    }else if(ciclo == 2){
     corLed(0,0,1); 
    }
    ciclo++;
    if (ciclo>maximo -1){
     ciclo = 0; 
    }
  }
private:
  void corLed(int r, int g, int b){
    digitalWrite(pinoR,r); //HIGH ==1 | LOw == 0
    digitalWrite(pinoG,g);
    digitalWrite(pinoB,b);
  }
};


Bt bt(botao);  //intaciando objeto
Cor cor(ledR,ledG,ledB); //instanciando leds


void setup()
{
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(botao, INPUT);
} 
// Verificar botão precionado e chama função
void loop() {
  if(bt.press()){
    cor.trocaLed();
  }
}
