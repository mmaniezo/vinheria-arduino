#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Variáveis
#define DHTPIN 12
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
int ledTemp = 8;
int ledUmid = 9;
int buzzer = 10;
int ledR = 4; // Pino para o LED vermelho
int ledY = 7; // Pino para o LED amarelo
int ledG = 2; // Pino para o LED verde

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  dht.begin();
  lcd.begin(16,2);
  pinMode(ledTemp, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(A0, INPUT);
  // Inicialização da comunicação serial
  Serial.begin(9600);
  // Configuração dos pinos como entrada ou saída
  pinMode(ledR, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledG, OUTPUT);
}

void loop() {
    // Cria uma variável tanto para a temperatura do DHT quanto da umidade
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();

   lcd.clear();

  // Temperatura na linha 1
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(temperatura);
  lcd.print(" C");
  

  // Umidade na linha 2
  lcd.setCursor(0, 1);
  lcd.print("Umidade:");
  lcd.print(umidade);
  lcd.print("%");
  
  delay(1000);
  // Leitura do valor do sensor de luminosidade
  int sensorValue = analogRead(A0);
  // Impressão do valor lido serialmente para fins de depuração
  Serial.println(sensorValue);
  // Ajuste da intensidade do LED
  analogWrite(ledR, map(sensorValue, 0, 1023, 0, 255));
  
  // Verificação do valor lido do sensor e controle dos LEDs e do buzzer
  if (sensorValue < 500) {
    // Se a luminosidade estiver baixa, acende o LED verde e desliga os outros LEDs e o buzzer
    digitalWrite(ledR, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledG, HIGH);
    digitalWrite(buzzer, LOW); // Desliga o buzzer
  } 
  else if (sensorValue > 500 && sensorValue < 1000) {
    // Se a luminosidade estiver em nível de alerta, acende o LED amarelo e desliga os outros LEDs
    digitalWrite(ledR, LOW);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledG, LOW);
    tone(buzzer, 50, 3000);
    delay(3000); // Espera 3 segundos antes de repetir o loop
  } 
  else {
    // Se a luminosidade estiver alta, acende o LED vermelho e ativa o buzzer por 3 segundos
    digitalWrite(ledR, HIGH);
    digitalWrite(ledY, LOW);
    digitalWrite(ledG, LOW);
    tone(buzzer, 150, 3000);
    delay(3000); // Espera 3 segundos antes de repetir o loop
  }

  // Verificação de condições de temperatura e umidade
  if (temperatura > 15) {
    lcd.setCursor(0, 0);
    lcd.print("Temp. alta!     ");
    digitalWrite(ledTemp, HIGH);
    tone(buzzer, 300, 2000);
    delay(2000);
  }

  if (temperatura < 10) {
    lcd.setCursor(0, 0);
    lcd.print("Temp. baixa!    ");
    digitalWrite(ledTemp, HIGH);
    tone(buzzer, 300, 2000);
    delay(2000);
  }

  if (umidade > 80) {
    lcd.setCursor(0, 1);
    lcd.print("Umidade alta!    ");
    digitalWrite(ledUmid, HIGH);
    tone(buzzer, 100, 2000);
    delay(2000);
  }

  if (umidade < 60) {
    lcd.setCursor(0, 1);
    lcd.print("Umidade baixa!  ");
    digitalWrite(ledUmid, HIGH);
    tone(buzzer, 100, 2000);
    delay(2000);
  }
  
  // Desativa ambos leds
  digitalWrite(ledTemp, LOW);
  digitalWrite(ledUmid, LOW);
  delay(3000);
}
