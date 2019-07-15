// VALORES PADROES ====================================
#define ledR 6
#define ledG 3
#define ledB 5
#define botao 7
#define maximo 3
// ====================================

// VARIAVEIS
int btup = 0, btdown = 0,ciclo = 0 ;
// ====================================

// FUNÇÕES DE CORES ====================================
void ledr(){ // FUNÇÂO VERMELHO
  digitalWrite(ledR,HIGH);
  digitalWrite(ledG,LOW);
  digitalWrite(ledB,LOW);
}
void ledg(){
  digitalWrite(ledR,LOW);
  digitalWrite(ledG,HIGH);
  digitalWrite(ledB,LOW);
}
void ledb(){
  digitalWrite(ledR,LOW);
  digitalWrite(ledG,LOW);
  digitalWrite(ledB,HIGH);
}
// ====================================

// FUNÇÃO TROCAR COR DE LED====================================
void trocaled(){
  if(ciclo == 0){
  ledr();
  }else if(ciclo == 1){
  ledg(); 
  }else if(ciclo == 2){
  ledb(); 
  }
  ciclo++;
  if(ciclo > maximo - 1){
  ciclo=0; 
  }
}
// ====================================

// FUNÇÃO VERIFICAR BUTÃO APERTADO====================================
void btv(){
  if(digitalRead(botao) == HIGH){
    btup = 1;
    btdown = 0;
  }else{
    btdown = 1; 
  }
  if((btup == 1) and (btdown == 1)){
    btup = 0;
    btdown = 0;
    trocaled();
  }
}
// ====================================


// DEFINIR PORTAS DE ENTRADA OU SAIDA ====================================
void setup()
{
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(botao, INPUT);
}
// ====================================

// CHAMADA DE FUNÇÃO PARA INICIALIZAÇÃO====================================
void loop()
{
  btv();
}
// ====================================
