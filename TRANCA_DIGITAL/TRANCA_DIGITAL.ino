// INCLUSÃO DE BIBLIOTECAS
#include <Wire.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// DEFINIÇÕES
#define endereco  0x27 // Endereços comuns: 0x27, 0x3F
#define colunas   16
#define linhas    2

#define BUZ 8 // SOM
#define LEDRED 7 // Define o pino 7 com PWM como RED
#define LEDGREEN 6 // Define o pino 6 com PWM como GREEN
#define LEDBLUE 5 // Define o pino 5 com PWM como BLUE
#define TRANCA 10 // Trava
#define BTN 11 // Trava
// INSTANCIANDO OBJETOS
LiquidCrystal_I2C lcd(endereco, colunas, linhas);


const byte LINHAS = 4; //número de linhas do teclado
const byte COLUNAS = 4; //número de colunas do teclado

//define uma matriz com os símbolos que deseja ser lido do teclado
char SIMBOLOS[LINHAS][COLUNAS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte PINOS_LINHA[LINHAS] = {22,24,26,28}; //pinos que indicam as linhas do teclado
byte PINOS_COLUNA[COLUNAS] = {30,32,34,36}; //pinos que indicam as colunas do teclado

//instancia de Keypad, responsável por capturar a tecla pressionada
Keypad customKeypad = Keypad( makeKeymap(SIMBOLOS), PINOS_LINHA, PINOS_COLUNA, LINHAS, COLUNAS);


const String SENHA = "123456";
String digitado = "";
int i = 0;

int red = 255, green = 255, blue = 255;

/*==============================================================================================================*/
/*==============================================================================================================*/

void setup() {
  
  lcd.init(); // INICIA A COMUNICAÇÃO COM O DISPLAY
  lcd.backlight(); // LIGA A ILUMINAÇÃO DO DISPLAY
  lcd.clear(); // LIMPA O DISPLAY

  pinMode(BUZ, OUTPUT); // SOM SAIDA
  pinMode (LEDRED, OUTPUT); // Pino 7 declarado como saída
  pinMode (LEDGREEN, OUTPUT); // Pino 6 declarado como saída
  pinMode (LEDBLUE, OUTPUT); // Pino 5 declarado como saída 
  pinMode(TRANCA, INPUT);
  pinMode(BTN, INPUT_PULLUP);

  lcd.print("Aguarde.");
  delay(500); // DELAY DE 5 SEGUNDOS
  lcd.clear(); // LIMPA O DISPLAY
  lcd.print("Aguarde..");
  delay(500); // DELAY DE 5 SEGUNDOS
  lcd.clear(); // LIMPA O DISPLAY
  lcd.print("Aguarde...");
  delay(500); // DELAY DE 5 SEGUNDOS
  lcd.clear(); // LIMPA O DISPLAY
  
  Serial.begin(9600);
  Serial.println("teclado 4x4");
  Serial.println("Aguardando...");
  
  lcd.print("Senha :");
  lcd.setCursor(0, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 2
 

 
}

/*==============================================================================================================*/
/*==============================================================================================================*/
void loop() {

  if (digitalRead(BTN) == LOW){
               digitalWrite(BUZ, HIGH); // ativa o SOM
              analogWrite (LEDBLUE, 255);
              delay(500);            // espera por um segundo
              digitalWrite(BUZ, LOW); // Desativa o SOM
              analogWrite (LEDBLUE, 0);
              Serial.println("BTN!!!!");
             
                digitado = "";
                i = 0;

                  
                pinMode(TRANCA, OUTPUT);
                
                digitalWrite(BUZ, HIGH); // ativa o SOM
                analogWrite (LEDGREEN, 255);
                delay(500);            // espera por um segundo
                digitalWrite(BUZ, LOW); // Desativa o SOM
                analogWrite (LEDGREEN, 0);
               
                lcd.clear(); // LIMPA O DISPLAY
                lcd.print("Liberado!");
                delay(5000); // DELAY DE 5 SEGUNDOS
                pinMode(TRANCA, INPUT);
                //chama o comando para limpar a tela
                lcd.clear(); // LIMPA O DISPLAY
                lcd.print("Senha :");
                lcd.setCursor(0, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 2
    
  }
  
  char teclado = customKeypad.getKey();    
  
    if (teclado){
     
        switch(teclado)
      {
        //caso alguma das teclas imprimíveis foi pressionada
        case 'A':
                digitalWrite(BUZ, HIGH); // ativa o SOM
                analogWrite (LEDBLUE, 255);
                delay(500);            // espera por um segundo
                digitalWrite(BUZ, LOW); // Desativa o SOM
                analogWrite (LEDBLUE, 0);
              
                if(digitado == SENHA){
                  digitado = "";
                  i = 0;
  
                    
                  pinMode(TRANCA, OUTPUT);
                  
                  digitalWrite(BUZ, HIGH); // ativa o SOM
                  analogWrite (LEDGREEN, 255);
                  delay(500);            // espera por um segundo
                  digitalWrite(BUZ, LOW); // Desativa o SOM
                  analogWrite (LEDGREEN, 0);
                 
                  lcd.clear(); // LIMPA O DISPLAY
                  lcd.print("Liberado!");
                  delay(5000); // DELAY DE 5 SEGUNDOS
                  pinMode(TRANCA, INPUT);
                  //chama o comando para limpar a tela
                  lcd.clear(); // LIMPA O DISPLAY
                  lcd.print("Senha :");
                  lcd.setCursor(0, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 2
                
                }else{
                  digitado = "";
                  i = 0;
                  digitalWrite(BUZ, HIGH); // ativa o SOM
                  analogWrite (LEDRED, 255);
                  delay(500);            // espera por um segundo
                  digitalWrite(BUZ, LOW); // Desativa o SOM
                  analogWrite (LEDRED, 0);
                  lcd.clear(); // LIMPA O DISPLAY
                  lcd.print("Senha Incorreta!!!");
                  delay(2000); // DELAY DE 5 SEGUNDOS
                  lcd.clear(); // LIMPA O DISPLAY
                  lcd.print("Senha :");
                  lcd.setCursor(0, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 
                }
                break;
        case 'B':
              digitalWrite(BUZ, HIGH); // ativa o SOM
              analogWrite (LEDBLUE, 255);
              delay(500);            // espera por um segundo
              digitalWrite(BUZ, LOW); // Desativa o SOM
              analogWrite (LEDBLUE, 0);
      
                  if(i <= 0 ){
                  i = 0;
                  lcd.clear();
                  lcd.print("Corrigindo");
                  delay(1000); // DELAY DE 5 SEGUNDOS
                  //digitado.remove(index, count);
                  
                  lcd.clear();
                  lcd.print("Senha: ");
                  lcd.setCursor(0, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 2
                  lcd.print(digitado);
                   Serial.println("Digitado: "+digitado+" I: "+i);
                  }else{
                  i--;
                  digitado.remove(i,1);
                   lcd.clear();
                  lcd.print("Corrigindo");
                  delay(1000); // DELAY DE 5 SEGUNDOS
                  //digitado.remove(index, count);
                  
                  lcd.clear();
                  lcd.print("Senha: ");
                  lcd.setCursor(0, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 2
                  lcd.print(digitado);
                  Serial.println("Digitado: "+digitado+" I: "+i);
                  }
                break;
        case 'C':
              digitalWrite(BUZ, HIGH); // ativa o SOM
              analogWrite (LEDBLUE, 255);
              delay(500);            // espera por um segundo
              digitalWrite(BUZ, LOW); // Desativa o SOM
              analogWrite (LEDBLUE, 0);
                 //limpa a variável que guarda a senha que está sendo digitada
                digitado = "";
                i = 0;
                lcd.clear(); // LIMPA O DISPLAY
                lcd.print("Limpando");
                 delay(1000); // DELAY DE 5 SEGUNDOS
                //chama o comando para limpar a tela
                lcd.clear(); // LIMPA O DISPLAY
                lcd.print("Senha :");
                lcd.setCursor(0, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 2
                //configura a mensagem para digitar a senha
                break;
        case 'D':
              digitalWrite(BUZ, HIGH); // ativa o SOM
              analogWrite (LEDBLUE, 255);
              delay(500);            // espera por um segundo
              digitalWrite(BUZ, LOW); // Desativa o SOM
              analogWrite (LEDBLUE, 0);
                digitado = "";
                i = 0;
                lcd.clear(); // LIMPA O DISPLAY
                lcd.print("INFO:");
                delay(3000); // DELAY DE 5 SEGUNDOS
                lcd.setCursor(0, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 2
                lcd.print("UniFacemp TRA-01");
                lcd.clear(); // LIMPA O DISPLAY
                lcd.print("Senha: ");
                lcd.setCursor(0, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 2
                lcd.print(digitado);
                
                break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '*':
        case '#':
              //concatena o novo símbolo a senha que estamos digitando
              digitado+=teclado;
              Serial.println("Digitado: "+digitado+" I: "+i);
              //imrpime na tela o símbolo pressionado
              
              digitalWrite(BUZ, HIGH); // ativa o SOM
              analogWrite (LEDRED, 255);
              delay(100);            // espera por um segundo
              digitalWrite(BUZ, LOW); // Desativa o SOM
              analogWrite (LEDRED, 0);
              
              lcd.setCursor(0, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 2
              lcd.print(digitado);
  
              i += 1;
              
              break;
        
    
      }
    }
  }
