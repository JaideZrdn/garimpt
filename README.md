# [Garimpando Profundidades Tecnológicas](https://garimgpt.wordpress.com/)
## UFAM-Eng. da Computação
### Projeto de Laboratório de Física I

Neste repositório está o código utilizado na realização do projeto.

### Objetivo

Nosso projeto tem como principal objetivo determinar o valor da aceleração
da gravidade usando __Arduino__ como foi proposto pela professora em sala de aula.

### Materiais e Orçamento

    1 Arduino Uno R3 – R$60,00 un.
    LDR – R$2,00 un.
    LED – R$1,00 un.
    2 resistores – R$1,00 un.
    1 protoboard – R$15,00 un.
    5 jumpers – R$1,00 un.
    1 régua – R$6,00 un.
    1 rolo de fita isolante – R$3,00 un.
    1 pacote de palitos – R$8,00
    1 placa de isopor – R$5,00 un.
    Tesoura
    Estilete
    Total – R$104

### Fundamentação Física
A força gravitacional é definida mecanicamente como a força que corpos
massivos aplicam uns aos outros devido exclusivamente suas massas.

Nesse experimento determinaremos o valor da aceleração da gravidade
à partir da mecânica Newtoniana, nela podemos aproximar o valor da
aceleração sendo duas vezes a distância percorrida dividido pelo
quadrado do tempo. Definiremos as distâncias na régua e o tempo de
queda será detectado pelo LDR.

Faremos de um jeito que nos leve à
minimizar a velocidade inicial para que haja uma maior precisão na
determinação do valor.

### Justificativa
O projeto, apesar de simples, é bem completo e traz uma abordagem
diferente no estudo da física. Então, essa construção poderia ser
utilizada em escolas públicas usando os kits de Arduino que foram
fornecidos à elas para fomentar o estudo da física e tecnologias.


## Código

### Base
Inicialmente, definimos as variáveis:
```C
const int ldrPin = A0;
const int limiar = 475; 
const int limiar2 = 490;
unsigned long startTime = 0;  
unsigned long totalTime = 0;  
void setup() {
    pinMode(ldrPin, INPUT);
    Serial.begin(9600);
```

### Limiares
Sobre os limiares definidos na secção anterior, eles são o alicerce do nosso programa, pois, 
o Arduino não detectará quando estiver claro ou escuro e sim a transição entre essas condições.
Para isso, definimos um limiar, quando o LDR detectar que está dentro deste limiar
o Arduino retornará o tempo que ficou na faixa anterior, tendo assim o tempo de queda
de uma das faixas.

### Contando o tempo
Após isso, programamos um sistema para contar esse tempo, onde ele inicia no momento da transição
e para quando vier a próxima, por isso, é necessário que a régua comece com
uma faixa preta e termine também com uma.
```C
void loop() {
  int valorldr = analogRead(ldrPin); // Lendo o Valor do LDR
    if (valorldr >= limiar && valorldr<= limiar2) {
    unsigned long endTime = millis();
    unsigned long duration = (endTime - startTime) / 1; // Printando o tempo do anterior
    if (duration>65){
    	Serial.println("Tempo de faixa " + String(duration) + " milissegundos.");
		startTime = 0; // Resetando o Timer
    	startTime = millis(); // Iniciando um novo Timer
    }
  }
```
