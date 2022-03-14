// include the library code:
#include <LiquidCrystal.h>

// include the bluetooth library:
#include <SoftwareSerial.h>
SoftwareSerial BTserial(10, 11); // RX | TX.
String BT_input;                          // to store input character received via BT.
// inizializate var with 0
int var = 0;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// define the green led to pin 8
#define led_verde 8

void setup()
{
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // set led_verde to output:
    pinMode(led_verde, OUTPUT);
    Serial.begin(9600);
}

void Titulo()
{
    while (var = 0)
    {
  		String text = "Gana y Juega";
    	int i, j=0;
    	for (i =0; i<text.length(); i++)
    	{
        	if(i<15)
        	{
            	lcd.setCursor(i,0);
            	lcd.print(text.charAt(i));
            	delay(150);
        	}
        	else
        	{
            	for(i=16;i<text.length();i++)
            	{   
                	j++;
                	lcd.setCursor(0,0);
                	lcd.print(text.substring(j,j+16));
                	delay(250);
            	}
        	}
    	}
    	break;
    }
} 

void correcta()
{
  digitalWrite(led_verde, HIGH);
  Serial.println(BT_input);
  Serial.println("La pregunta es correcta");
}

void incorrecta()
{
  digitalWrite(led_verde, LOW);
  Serial.println(BT_input);
  Serial.println("La pregunta es incorrecta");
}
void pregunta_1()
{
  	while (var = 0)
    {
      String text = "Quien descubrio America?";
      BTserial.print("A = Cristobal Colon");
      BTserial.print("\n");
      BTserial.print("B = Ibai Llanos");
      int i, j=0;
      for (i =0; i<text.length(); i++)
      {
          if(i<15)
          {
              lcd.setCursor(i,0);
              lcd.print(text.charAt(i));
              delay(150);
          }
          else
          {
              for(i=16;i<text.length();i++)
              {   
                  j++;
                  lcd.setCursor(0,0);
                  lcd.print(text.substring(j,j+16));
                  delay(250);
              }
          }
      }
      if (Serial.available())
      {   
          BT_input = Serial.readString();   // read input string from bluetooth 
        
          if (BT_input=="A")                
          {
            correcta();
          }
          else if (BT_input=="B")
          {
            incorrecta();
          }
          else 
          {
            Serial.println(BT_input);        
            Serial.println("Send 'A' to get LED ON");
            Serial.println("Send 'B' to get LED OFF");
          }
      }
      var++;
    }
} 

void pregunta_2()
{
  	while (var = 1)
    {
      String text = "Cuando termino la Segunda Guerra Mundial?";
      BTserial.print("A = 1645");
      BTserial.print("\n");
      BTserial.print("B = 2000");
      int i, j=0;
      for (i =0; i<text.length(); i++)
      {
          if(i<15)
          {
              lcd.setCursor(i,0);
              lcd.print(text.charAt(i));
              delay(150);
          }
          else
          {
              for(i=16;i<text.length();i++)
              {   
                  j++;
                  lcd.setCursor(0,0);
                  lcd.print(text.substring(j,j+16));
                  delay(250);
              }
          }
      }
      if (Serial.available())
      {   
          BT_input = Serial.readString();   // read input string from bluetooth 
        
          if (BT_input=="A")                
          {
            correcta();
          }
          else if (BT_input=="B")
          {
            incorrecta();
          }
          else 
          {
            Serial.println(BT_input);        
            Serial.println("Send 'A' to get LED ON");
            Serial.println("Send 'B' to get LED OFF");
          }
      }
      var++;
    }
} 

void pregunta_3()
{
  	while (var = 2)
    {
      String text = "Cuantas especies de perros hay?";
      BTserial.print("A = 343");
      BTserial.print("\n");
      BTserial.print("B = 50");
      int i, j=0;
      for (i =0; i<text.length(); i++)
      {
          if(i<15)
          {
              lcd.setCursor(i,0);
              lcd.print(text.charAt(i));
              delay(150);
          }
          else
          {
              for(i=16;i<text.length();i++)
              {   
                  j++;
                  lcd.setCursor(0,0);
                  lcd.print(text.substring(j,j+16));
                  delay(250);
              }
          }
      }
      if (Serial.available())
      {   
          BT_input = Serial.readString();   // read input string from bluetooth 
        
          if (BT_input=="A")                
          {
            correcta();
          }
          else if (BT_input=="B")
          {
            incorrecta();
          }
          else 
          {
            Serial.println(BT_input);        
            Serial.println("Send 'A' to get LED ON");
            Serial.println("Send 'B' to get LED OFF");
          }
      }
      var++;
    }
} 

void pregunta_4()
{
  	while (var = 3)
    {
      String text = "Quien salvo al pueblo hebreo del faraon egipcio?";
      BTserial.print("A = Abraham");
      BTserial.print("\n");
      BTserial.print("B = Moises");
      int i, j=0;
      for (i =0; i<text.length(); i++)
      {
          if(i<15)
          {
              lcd.setCursor(i,0);
              lcd.print(text.charAt(i));
              delay(150);
          }
          else
          {
              for(i=16;i<text.length();i++)
              {   
                  j++;
                  lcd.setCursor(0,0);
                  lcd.print(text.substring(j,j+16));
                  delay(250);
              }
          }
      }
      if (Serial.available())
      {   
          BT_input = Serial.readString();   // read input string from bluetooth 
        
          if (BT_input=="A")                
          {
            incorrecta();
          }
          else if (BT_input=="B")
          {
            correcta();
          }
          else 
          {
            Serial.println(BT_input);        
            Serial.println("Send 'A' to get LED ON");
            Serial.println("Send 'B' to get LED OFF");
          }
      }
      var++;
    }
}

void pregunta_5()
{
  	while (var = 4)
    {
      String text = "Quien es el tenista con mas Grand Slam?";
      BTserial.print("A = Rafael Nadal");
      BTserial.print("\n");
      BTserial.print("B = Tomas Palma");
      int i, j=0;
      for (i =0; i<text.length(); i++)
      {
          if(i<15)
          {
              lcd.setCursor(i,0);
              lcd.print(text.charAt(i));
              delay(150);
          }
          else
          {
              for(i=16;i<text.length();i++)
              {   
                  j++;
                  lcd.setCursor(0,0);
                  lcd.print(text.substring(j,j+16));
                  delay(250);
              }
          }
      }
      if (Serial.available())
      {   
          BT_input = Serial.readString();   // read input string from bluetooth 
        
          if (BT_input=="A") // A               
          {
            correcta();
          }
          else if (BT_input=="B") // B
          {
            incorrecta();
          }
          else // indefinido
          {
            Serial.println(BT_input);        
            Serial.println("Send 'A' to get LED ON");
            Serial.println("Send 'B' to get LED OFF");
          }
      }
      var++;
    }
}

void pregunta_6()
{
  	while (var = 5)
    {
      String text = "Como se llama el actor de harry Potter?";
      BTserial.print("A = Daniel Radcliffe");
      BTserial.print("\n");
      BTserial.print("B = Tom Holland");
      int i, j=0;
      for (i =0; i<text.length(); i++)
      {
          if(i<15)
          {
              lcd.setCursor(i,0);
              lcd.print(text.charAt(i));
              delay(150);
          }
          else
          {
              for(i=16;i<text.length();i++)
              {   
                  j++;
                  lcd.setCursor(0,0);
                  lcd.print(text.substring(j,j+16));
                  delay(250);
              }
          }
      }
      if (Serial.available())
      {   
          BT_input = Serial.readString();   // read input string from bluetooth 
        
          if (BT_input=="A") // A               
          {
            correcta();
          }
          else if (BT_input=="B") // B
          {
            incorrecta();
          }
          else // indefinido
          {
            Serial.println(BT_input);        
            Serial.println("Send 'A' to get LED ON");
            Serial.println("Send 'B' to get LED OFF");
          }
      }
      var++;
    }
}

void pregunta_7()
{
  	while (var = 6)
    {
      String text = "En que continente se encuentran las Islas del Caribe?";
      BTserial.print("A = Europa");
      BTserial.print("\n");
      BTserial.print("B = Ameria");
      int i, j=0;
      for (i =0; i<text.length(); i++)
      {
          if(i<15)
          {
              lcd.setCursor(i,0);
              lcd.print(text.charAt(i));
              delay(150);
          }
          else
          {
              for(i=16;i<text.length();i++)
              {   
                  j++;
                  lcd.setCursor(0,0);
                  lcd.print(text.substring(j,j+16));
                  delay(250);
              }
          }
      }
      if (Serial.available())
      {   
          BT_input = Serial.readString();   // read input string from bluetooth 
        
          if (BT_input=="A") // A               
          {
            incorrecta();
          }
          else if (BT_input=="B") // B
          {
            correcta();
          }
          else // indefinido
          {
            Serial.println(BT_input);        
            Serial.println("Send 'A' to get LED ON");
            Serial.println("Send 'B' to get LED OFF");
          }
      }
      var++;
    }
}

void pregunta_8()
{
  	while (var = 7)
    {
      String text = "Quien invento la bombilla?";
      BTserial.print("A = Thomas Edison");
      BTserial.print("\n");
      BTserial.print("B = Abraham Mateo");
      int i, j=0;
      for (i =0; i<text.length(); i++)
      {
          if(i<15)
          {
              lcd.setCursor(i,0);
              lcd.print(text.charAt(i));
              delay(150);
          }
          else
          {
              for(i=16;i<text.length();i++)
              {   
                  j++;
                  lcd.setCursor(0,0);
                  lcd.print(text.substring(j,j+16));
                  delay(250);
              }
          }
      }
      if (Serial.available())
      {   
          BT_input = Serial.readString();   // read input string from bluetooth 
        
          if (BT_input=="A") // A               
          {
            correcta();
            
          }
          else if (BT_input=="B") // B
          {
            incorrecta();
          }
          else // indefinido
          {
            Serial.println(BT_input);        
            Serial.println("Send 'A' to get LED ON");
            Serial.println("Send 'B' to get LED OFF");
          }
      }
      var++;
    }
}

void pregunta_9() // sin terminar
{
  	while (var = 8)
    {
      String text = "En que a?";
      BTserial.print("A = Thomas Edison");
      BTserial.print("\n");
      BTserial.print("B = Abraham Mateo");
      int i, j=0;
      for (i =0; i<text.length(); i++)
      {
          if(i<15)
          {
              lcd.setCursor(i,0);
              lcd.print(text.charAt(i));
              delay(150);
          }
          else
          {
              for(i=16;i<text.length();i++)
              {   
                  j++;
                  lcd.setCursor(0,0);
                  lcd.print(text.substring(j,j+16));
                  delay(250);
              }
          }
      }
      if (Serial.available())
      {   
          BT_input = Serial.readString();   // read input string from bluetooth 
        
          if (BT_input=="A") // A               
          {
            correcta();
            
          }
          else if (BT_input=="B") // B
          {
            incorrecta();
          }
          else // indefinido
          {
            Serial.println(BT_input);        
            Serial.println("Send 'A' to get LED ON");
            Serial.println("Send 'B' to get LED OFF");
          }
      }
      var++;
    }
}

void pregunta_10()
{
  	while (var = 9)
    {
      String text = "En que ciudad esta el estadio conocido como Wanda Metropolitano?";
      BTserial.print("A = Madrid");
      BTserial.print("\n");
      BTserial.print("B = Barcelona");
      int i, j=0;
      for (i =0; i<text.length(); i++)
      {
          if(i<15)
          {
              lcd.setCursor(i,0);
              lcd.print(text.charAt(i));
              delay(150);
          }
          else
          {
              for(i=16;i<text.length();i++)
              {   
                  j++;
                  lcd.setCursor(0,0);
                  lcd.print(text.substring(j,j+16));
                  delay(250);
              }
          }
      }
      if (Serial.available())
      {   
          BT_input = Serial.readString();   // read input string from bluetooth 
        
          if (BT_input=="A") // A               
          {
            correcta();
            
          }
          else if (BT_input=="B") // B
          {
            incorrecta();
          }
          else // indefinido
          {
            Serial.println(BT_input);        
            Serial.println("Send 'A' to get LED ON");
            Serial.println("Send 'B' to get LED OFF");
          }
      }
      var++;
    }
}

void pregunta_11()
{
  	while (var = 10)
    {
      String text = "Cual es el rio mas caudaloso del mundo?";
      BTserial.print("A = Amazonas");
      BTserial.print("\n");
      BTserial.print("B = Duero");
      int i, j=0;
      for (i =0; i<text.length(); i++)
      {
          if(i<15)
          {
              lcd.setCursor(i,0);
              lcd.print(text.charAt(i));
              delay(150);
          }
          else
          {
              for(i=16;i<text.length();i++)
              {   
                  j++;
                  lcd.setCursor(0,0);
                  lcd.print(text.substring(j,j+16));
                  delay(250);
              }
          }
      }
      if (Serial.available())
      {   
          BT_input = Serial.readString();   // read input string from bluetooth 
        
          if (BT_input=="A") // A               
          {
            correcta();
            
          }
          else if (BT_input=="B") // B
          {
            incorrecta();
          }
          else // indefinido
          {
            Serial.println(BT_input);        
            Serial.println("Send 'A' to get LED ON");
            Serial.println("Send 'B' to get LED OFF");
          }
      }
      var++;
    }
}

void pregunta_12()
{
  	while (var = 11)
    {
      String text = "Quienes fueron los dos hermanos fundadores de Roma?";
      BTserial.print("A = Romulo y Remo");
      BTserial.print("\n");
      BTserial.print("B = Pomulo y Rema");
      int i, j=0;
      for (i =0; i<text.length(); i++)
      {
          if(i<15)
          {
              lcd.setCursor(i,0);
              lcd.print(text.charAt(i));
              delay(150);
          }
          else
          {
              for(i=16;i<text.length();i++)
              {   
                  j++;
                  lcd.setCursor(0,0);
                  lcd.print(text.substring(j,j+16));
                  delay(250);
              }
          }
      }
      if (Serial.available())
      {   
          BT_input = Serial.readString();   // read input string from bluetooth 
        
          if (BT_input=="A") // A               
          {
            correcta();
            
          }
          else if (BT_input=="B") // B
          {
            incorrecta();
          }
          else // indefinido
          {
            Serial.println(BT_input);        
            Serial.println("Send 'A' to get LED ON");
            Serial.println("Send 'B' to get LED OFF");
          }
      }
      var++;
    }
}

void pregunta_13() // sin terminar
{
  	while (var = 12)
    {
      String text = "Cual es la ?";
      BTserial.print("A = Romulo y Remo");
      BTserial.print("\n");
      BTserial.print("B = Pomulo y Rema");
      int i, j=0;
      for (i =0; i<text.length(); i++)
      {
          if(i<15)
          {
              lcd.setCursor(i,0);
              lcd.print(text.charAt(i));
              delay(150);
          }
          else
          {
              for(i=16;i<text.length();i++)
              {   
                  j++;
                  lcd.setCursor(0,0);
                  lcd.print(text.substring(j,j+16));
                  delay(250);
              }
          }
      }
      if (Serial.available())
      {   
          BT_input = Serial.readString();   // read input string from bluetooth 
        
          if (BT_input=="A") // A               
          {
            incorrecta();
            
          }
          else if (BT_input=="B") // B
          {
            correcta();
          }
          else // indefinido
          {
            Serial.println(BT_input);        
            Serial.println("Send 'A' to get LED ON");
            Serial.println("Send 'B' to get LED OFF");
          }
      }
      var++;
    }
}

void pregunta_14() 
{
  	while (var = 13)
    {
      String text = "Quien fue el famoso cantante del grupo musical Queen?";
      BTserial.print("A = Freddy Mercury");
      BTserial.print("\n");
      BTserial.print("B = John Lennon");
      int i, j=0;
      for (i =0; i<text.length(); i++)
      {
          if(i<15)
          {
              lcd.setCursor(i,0);
              lcd.print(text.charAt(i));
              delay(150);
          }
          else
          {
              for(i=16;i<text.length();i++)
              {   
                  j++;
                  lcd.setCursor(0,0);
                  lcd.print(text.substring(j,j+16));
                  delay(250);
              }
          }
      }
      if (Serial.available())
      {   
          BT_input = Serial.readString();   // read input string from bluetooth 
        
          if (BT_input=="A") // A               
          {
            correcta();
            
          }
          else if (BT_input=="B") // B
          {
            incorrecta();
          }
          else // indefinido
          {
            Serial.println(BT_input);        
            Serial.println("Send 'A' to get LED ON");
            Serial.println("Send 'B' to get LED OFF");
          }
      }
      var++;
    }
}

void pregunta_15() 
{
  	while (var = 14)
    {
      String text = "Quien es el YouTuber con mas suscriptores?";
      BTserial.print("A = Pewdiepie");
      BTserial.print("\n");
      BTserial.print("B = Djmariio");
      int i, j=0;
      for (i =0; i<text.length(); i++)
      {
          if(i<15)
          {
              lcd.setCursor(i,0);
              lcd.print(text.charAt(i));
              delay(150);
          }
          else
          {
              for(i=16;i<text.length();i++)
              {   
                  j++;
                  lcd.setCursor(0,0);
                  lcd.print(text.substring(j,j+16));
                  delay(250);
              }
          }
      }
      if (Serial.available())
      {   
          BT_input = Serial.readString();   // read input string from bluetooth 
        
          if (BT_input=="A") // A               
          {
            correcta();
            
          }
          else if (BT_input=="B") // B
          {
            incorrecta();
          }
          else // indefinido
          {
            Serial.println(BT_input);        
            Serial.println("Send 'A' to get LED ON");
            Serial.println("Send 'B' to get LED OFF");
          }
      }
      var++;
    }
}

void pregunta_16() 
{
  	while (var = 15)
    {
      String text = "Que gran artista pinto la Capilla Sixtina?";
      BTserial.print("A = Miguel Angel");
      BTserial.print("\n");
      BTserial.print("B = Beethoven");
      int i, j=0;
      for (i =0; i<text.length(); i++)
      {
          if(i<15)
          {
              lcd.setCursor(i,0);
              lcd.print(text.charAt(i));
              delay(150);
          }
          else
          {
              for(i=16;i<text.length();i++)
              {   
                  j++;
                  lcd.setCursor(0,0);
                  lcd.print(text.substring(j,j+16));
                  delay(250);
              }
          }
      }
      if (Serial.available())
      {   
          BT_input = Serial.readString();   // read input string from bluetooth 
        
          if (BT_input=="A") // A               
          {
            correcta();
            
          }
          else if (BT_input=="B") // B
          {
            incorrecta();
          }
          else // indefinido
          {
            Serial.println(BT_input);        
            Serial.println("Send 'A' to get LED ON");
            Serial.println("Send 'B' to get LED OFF");
          }
      }
      var++;
    }
}

void pregunta_17() 
{
  	while (var = 16)
    {
      String text = "Quien descubrio los satelites de jupiter?";
      BTserial.print("A = Mozart");
      BTserial.print("\n");
      BTserial.print("B = Galileo");
      int i, j=0;
      for (i =0; i<text.length(); i++)
      {
          if(i<15)
          {
              lcd.setCursor(i,0);
              lcd.print(text.charAt(i));
              delay(150);
          }
          else
          {
              for(i=16;i<text.length();i++)
              {   
                  j++;
                  lcd.setCursor(0,0);
                  lcd.print(text.substring(j,j+16));
                  delay(250);
              }
          }
      }
      if (Serial.available())
      {   
          BT_input = Serial.readString();   // read input string from bluetooth 
        
          if (BT_input=="A") // A               
          {
            incorrecta();
            
          }
          else if (BT_input=="B") // B
          {
            correcta();
          }
          else // indefinido
          {
            Serial.println(BT_input);        
            Serial.println("Send 'A' to get LED ON");
            Serial.println("Send 'B' to get LED OFF");
          }
      }
      var++;
    }
}

void pregunta_18() 
{
  	while (var = 17)
    {
      String text = "Que pais tiene mas copas del mundo de futbol?";
      BTserial.print("A = Francia");
      BTserial.print("\n");
      BTserial.print("B = Brasil");
      int i, j=0;
      for (i =0; i<text.length(); i++)
      {
          if(i<15)
          {
              lcd.setCursor(i,0);
              lcd.print(text.charAt(i));
              delay(150);
          }
          else
          {
              for(i=16;i<text.length();i++)
              {   
                  j++;
                  lcd.setCursor(0,0);
                  lcd.print(text.substring(j,j+16));
                  delay(250);
              }
          }
      }
      if (Serial.available())
      {   
          BT_input = Serial.readString();   // read input string from bluetooth 
        
          if (BT_input=="A") // A               
          {
            incorrecta();
            
          }
          else if (BT_input=="B") // B
          {
            correcta();
          }
          else // indefinido
          {
            Serial.println(BT_input);        
            Serial.println("Send 'A' to get LED ON");
            Serial.println("Send 'B' to get LED OFF");
          }
      }
      var++;
    }
}

void pregunta_19() 
{
  	while (var = 18)
    {
      String text = "De que pais es Lionel Andres Messi?";
      BTserial.print("A = Francia");
      BTserial.print("\n");
      BTserial.print("B = Argentina");
      int i, j=0;
      for (i =0; i<text.length(); i++)
      {
          if(i<15)
          {
              lcd.setCursor(i,0);
              lcd.print(text.charAt(i));
              delay(150);
          }
          else
          {
              for(i=16;i<text.length();i++)
              {   
                  j++;
                  lcd.setCursor(0,0);
                  lcd.print(text.substring(j,j+16));
                  delay(250);
              }
          }
      }
      if (Serial.available())
      {   
          BT_input = Serial.readString();   // read input string from bluetooth 
        
          if (BT_input=="A") // A               
          {
            incorrecta();
            
          }
          else if (BT_input=="B") // B
          {
            correcta();
          }
          else // indefinido
          {
            Serial.println(BT_input);        
            Serial.println("Send 'A' to get LED ON");
            Serial.println("Send 'B' to get LED OFF");
          }
      }
      var++;
    }
}

void pregunta_20() 
{
  	while (var = 19)
    {
      String text = "Donde jugo en la mayoria de su carrera Kobe Bryant?";
      BTserial.print("A = Barcelona");
      BTserial.print("\n");
      BTserial.print("B = Lakers");
      int i, j=0;
      for (i =0; i<text.length(); i++)
      {
          if(i<15)
          {
              lcd.setCursor(i,0);
              lcd.print(text.charAt(i));
              delay(150);
          }
          else
          {
              for(i=16;i<text.length();i++)
              {   
                  j++;
                  lcd.setCursor(0,0);
                  lcd.print(text.substring(j,j+16));
                  delay(250);
              }
          }
      }
      if (Serial.available())
      {   
          BT_input = Serial.readString();   // read input string from bluetooth 
        
          if (BT_input=="A") // A               
          {
            incorrecta();
            
          }
          else if (BT_input=="B") // B
          {
            correcta();
          }
          else // indefinido
          {
            Serial.println(BT_input);        
            Serial.println("Send 'A' to get LED ON");
            Serial.println("Send 'B' to get LED OFF");
          }
      }
      var++;
    }
}


void loop()
{
    Titulo();
    pregunta_1(); // 1
    digitalWrite(led_verde, LOW);
    pregunta_2(); // 2
    digitalWrite(led_verde, LOW);
    pregunta_3(); // 3
    digitalWrite(led_verde, LOW);
    pregunta_4(); // 4
    digitalWrite(led_verde, LOW);
    pregunta_5(); // 5
    digitalWrite(led_verde, LOW);
    pregunta_6(); // 6
    digitalWrite(led_verde, LOW);
    pregunta_7(); // 7
    digitalWrite(led_verde, LOW);
    pregunta_8(); // 8
    digitalWrite(led_verde, LOW);
    pregunta_9(); // 9
    digitalWrite(led_verde, LOW);
    pregunta_10(); // 10
    digitalWrite(led_verde, LOW);
    pregunta_11(); // 11
    digitalWrite(led_verde, LOW);
    pregunta_12(); // 12
    digitalWrite(led_verde, LOW);
    pregunta_13(); // 13
    digitalWrite(led_verde, LOW);
    pregunta_14(); // 14
    digitalWrite(led_verde, LOW);
    pregunta_15(); // 15
    digitalWrite(led_verde, LOW);
    pregunta_16(); // 16
    digitalWrite(led_verde, LOW);
    pregunta_17(); // 17 
    digitalWrite(led_verde, LOW);
    pregunta_18(); // 18
    digitalWrite(led_verde, LOW);
    pregunta_19(); // 19
    digitalWrite(led_verde, LOW);
    pregunta_20(); // 20

    delay(50);
}
