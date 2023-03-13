#define DELAY_TIME 500
int led_pin[ ]={2,3,4};
int count;
int red = 2;
int green = 3;
int blue = 4;
int X = 0;

void setup()
{
   Serial.begin(115200);
   for(count=0; count<4; count++)
   pinMode(led_pin[count],OUTPUT);
   
//function pinMode to set Digital pin 2,3,4 as OUTPUT 
//pinMode(2,OUTPUT)_RED_r 
//pinMode(3,OUTPUt)_GREEN_g
//pinMode(4,OUTPUT)_BLUE_b
   pinMode(2,OUTPUT);
   pinMode(3,OUTPUT);
   pinMode(4,OUTPUT);

}
void up_down(int r,int g,int b) 
{ 
  int x,y,z;
  for(z=1;z<=600;z++)    //dim_lights_to_bright
  {
     x=z;
     for(y=1;y<=x;y++)
      {
       digitalWrite(2,r); //red
       digitalWrite(3,g); //green
       digitalWrite(4,b); //blue  
      }
     for(y=x;y<=(1000-x);y++)
     {
       digitalWrite(2,0); 
       digitalWrite(3,0);
       digitalWrite(4,0);
     }
  }
  delay(20);
  
  for(z=600;z>=1;z--)    //bright_to_dim_lights
  {
      x=z;
     for(y=1;y<=x;y++)  
      {
       digitalWrite(2,r); 
       digitalWrite(3,g);
       digitalWrite(4,b);  
      }
     for(y=x;y<=(1000-x);y++)
     {
       digitalWrite(2,0); 
       digitalWrite(3,0);
       digitalWrite(4,0);
     }
  }
 delay(20);
}

   int redValue;
   int greenValue;
   int blueValue;

void loop()
{
    for(int i = 0; i < 255; i+=1)
  {
    redValue -= 1;
    greenValue+= 1;
    digitalWrite(red, redValue);
    digitalWrite(green, greenValue);
    delay(10);
  }

    redValue = 0;
    greenValue= 255;
    blueValue=0;

  for(int i = 0; i < 255; i+=1)
  {
    greenValue -= 1;
    blueValue += 1;
    digitalWrite(green, greenValue);
    digitalWrite(blue, blueValue);
    delay(10);
  }
    redValue = 0;
    greenValue= 0;
    blueValue=255;

  for(int i = 0; i < 255; i+=1)
  {
    blueValue -= 1;
    redValue += 1;
    digitalWrite(blue, blueValue);
    digitalWrite(red, redValue);
    delay(10);
  }
 
}
