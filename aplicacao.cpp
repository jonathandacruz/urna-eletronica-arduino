#include <LiquidCrystal.h>

#define botaoLula A3
#define botaoDilma A2
#define botaoBolsonaro A1
#define botaoTemer A0
#define som 9

#define amarelo 10
#define verde 7

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //pinos usados para comunicação com lcd

char entradaSerial;

int Lula = 0;
int Dilma = 0;
int Bolsonaro = 0;
int Temer = 0;

int tom1 = 1437;
int tom2 = 1337;

int controle = 0;//controle de votação


void setup()
{
  
	lcd.begin(16, 2); //tamanho display
	Serial.begin(9600);

	pinMode(botaoLula, INPUT_PULLUP);
	pinMode(botaoDilma, INPUT_PULLUP);
	pinMode(botaoBolsonaro, INPUT_PULLUP);
	pinMode(botaoTemer, INPUT_PULLUP);
	pinMode(som, OUTPUT);
  	pinMode(amarelo, OUTPUT);
  	pinMode(verde, OUTPUT);
}


void loop()
{

	entradaSerial = Serial.read();
 
	switch(entradaSerial)
	{

	case 'V':
      	
      	digitalWrite(amarelo, LOW);
      	digitalWrite(verde, HIGH);
		lcd.clear();
		lcd.setCursor(3, 0);
		lcd.print("SELECIONE");
		lcd.setCursor(3, 1);
		lcd.print("CANDIDATO");
		controle = 1;
		break;


	case 'A':
      	digitalWrite(verde, LOW);
      	digitalWrite(amarelo, HIGH);
		lcd.clear();
		lcd.setCursor(4, 0) ;
		lcd.print("AGUARDE...");
		break;
	}


	if( digitalRead(botaoLula) == LOW && (controle) == 1)
	{
		Serial.println("VOTO1");
		lcd.clear();
		lcd.setCursor(6, 0);
		lcd.print("VOTO");
		lcd.setCursor(1, 1);
		lcd.print("CONTABILIZADO.");
		delay(2000);
		lcd.clear();
		lcd.setCursor(4, 0);
		lcd.print("AGUARDE...");
      	digitalWrite(verde, LOW);
      	digitalWrite(amarelo, HIGH);
		controle = 0;
		Lula = Lula + 1;
		tocar(tom1, tom2);

	}
	if(digitalRead(botaoDilma) == LOW && (controle) == 1)
	{
		Serial.println("VOTO2");
		lcd.clear();
		lcd.setCursor(6, 0);
		lcd.print("VOTO");
		lcd.setCursor(1, 1);
		lcd.print("CONTABILIZADO.");
		delay(2000);
		lcd.clear();
		lcd.setCursor(4, 0);
		lcd.print("AGUARDE...");
      	digitalWrite(verde, LOW);
      	digitalWrite(amarelo, HIGH);
		Dilma = Dilma + 1;
		controle = 0;
        tocar(tom1, tom2);
	}
	if(digitalRead(botaoBolsonaro) == LOW && (controle) == 1)
	{
		Serial.println("VOTO3");
		lcd.clear();
		lcd.setCursor(6, 0);
		lcd.print("VOTO");
		lcd.setCursor(1, 1);
		lcd.print("CONTABILIZADO.");
		delay(2000);
		lcd.clear();
		lcd.setCursor(4, 0);
		lcd.print("AGUARDE...");
     	digitalWrite(verde, LOW);
      	digitalWrite(amarelo, HIGH);
		Bolsonaro = Bolsonaro + 1;
		controle = 0;
        tocar(tom1, tom2);
	}
	if(digitalRead(botaoTemer) == LOW && (controle) == 1)
	{
		Serial.println("VOTO4");
		lcd.clear();
		lcd.setCursor(6, 0);
		lcd.print("VOTO");
		lcd.setCursor(1, 1);
		lcd.print("CONTABILIZADO.");
		delay(2000);
		lcd.clear();
		lcd.setCursor(4, 0);
		lcd.print("AGUARDE...");
		digitalWrite(verde, LOW);
      	digitalWrite(amarelo, HIGH);
		Temer = Temer + 1;
		controle = 0;
        tocar(tom1, tom2);
	}

	switch(entradaSerial)
	{

	case 'C':  //INICIA CONTAGEM DOS VOTOS
      	digitalWrite(verde, LOW);
      	digitalWrite(amarelo, LOW);
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("CONTAGEM DOS");
		lcd.setCursor(0, 1);
		lcd.print("VOTOS:");
		delay(1200);
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("Lula:");
		lcd.setCursor(0, 1);
		lcd.print(Lula);
		delay(1200);
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("Dilma:");
		lcd.setCursor(0, 1);
		lcd.print(Dilma);
		delay(1200);
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("Bolsonaro:");
		lcd.setCursor(0, 1);
		lcd.print(Bolsonaro);
		delay(1200);
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("Temer:");
		lcd.setCursor(0, 1);
		lcd.print(Temer);
		zerar(&Lula, &Dilma, &Bolsonaro, &Temer);
		break;

	case 'R':
      	digitalWrite(verde, HIGH);
      	digitalWrite(amarelo, HIGH);
		lcd.clear();
		lcd.setCursor(1, 0);
		lcd.print("Reiniciando...");
		delay(2500);
		zerar(&Lula, &Dilma, &Bolsonaro, &Temer);
		lcd.clear();
		lcd.setCursor(4, 0);
		lcd.print("Pronto");
      	digitalWrite(verde, LOW);
      	digitalWrite(amarelo, LOW);
		delay(1500);
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("Pressione VOTAR para");
      	lcd.setCursor(0, 1);
      	lcd.print("iniciar votacao");
		break;


	default:
		lcd.print(" ");
		break;


	}
}


void tocar(int tom1, int tom2)
{
  int i;
  delay(300);
  
  for(i=0;i<5;i++)
  {
    tone(som, tom2);
    delay(90);
    tone(som, tom1);
    delay(90);
  }
  tone(som, tom2);
  delay(120);
  noTone(som);
}

void zerar(int *a, int *b, int *c, int *d)
{
	*a = 0;
  	*b = 0;
  	*c = 0;
   	*d = 0;
}
