// include the library code:
#include <LiquidCrystal.h>

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
  	
}

void scrolling_loop()
{
  	var = 0;
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

void pregunta_1()
{
  	var = 0;
  	while (var = 0);
    String text = "¿Quién descubrió América?";
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
    // if ("Boton_a = HIGH")
        // error()
        // break;
    // else()
        // correcto()
        // break;
    
    break;
} 

void loop()
{
    scrolling_loop();
    pregunta_1();
    // set led_verde to high
    digitalWrite(led_verde, HIGH);
}
