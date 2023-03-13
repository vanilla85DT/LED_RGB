#define DELAY_TIME 200
int led_pin[ ]={2,3,4};
int count;
int red = 2;
int green = 3;
int blue = 4;
int X = 0;
int redValue;
int greenValue;
int blueValue;
int redPin = 2;
int greenPin = 3;
int bluePin = 4;
int r = 0;
int g = 0;
int b = 0;
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

   pinMode(redPin, OUTPUT);
   pinMode(greenPin, OUTPUT);
   pinMode(bluePin, OUTPUT);
}
void start(int count)  //สีม่วงวิบวับวิบวับไว้เริ่มต้นวงจร
{
for (count=1;count<=20;count++)
  {
   digitalWrite(2,HIGH);       //maion_color_red
   digitalWrite(4,count%8/4);  //red+blue_purple
   delay(20);
  }
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
void We_wish_you_amerrychristmas(int r,int g,int b)
{
  int x,y,z;
  for(z=1;z<=500;z++)
  {
     x=z;
     for(y=1;y<=x;y++)
      {
       digitalWrite(2,r);
       digitalWrite(3,g);
       digitalWrite(4,b);  
      }
     for(y=x;y<=(600-x);y++)
     {
       digitalWrite(2,0);
       digitalWrite(3,0);
       digitalWrite(4,0);
     }
    }
  delay(5);
    for (count=1;count<=10;count++)
  {
   digitalWrite(2,HIGH);       //maion_color_red
   digitalWrite(2,count%2);  //red
   delay(100);
   digitalWrite(3,HIGH);     //main_color_green
   digitalWrite(3,count%3);  //green
   delay(100);
  }
}
void christmas_evePB(int count)
{
  for (count=1;count<=20;count++)
  {
   digitalWrite(2,HIGH);       //maion_color_red
   digitalWrite(4,count%8/4);  //red+blue_purple
   delay(100);
   
   digitalWrite(4,HIGH);       //main_color_blue
   digitalWrite(3,count%4/2);  //biue+green_light blue
   delay(100);
  }
}
void flashinglolypop(int count)
{
   for (count=1;count<=10;count++)
  {
   digitalWrite(2,HIGH);       //maion_color_red
   digitalWrite(4,count%8/4);  //red+blue_purple
   delay(100);
   digitalWrite(4,HIGH);       //main_color_blue
   digitalWrite(3,count%4/2);  //biue+green_light blue
   delay(100);
   digitalWrite(3,HIGH);     //main_color_green
   digitalWrite(2,count%2);  //green+red_yellow
   delay(100);
  }
    for (count=10;count>=1;count--)
  {
   digitalWrite(2,HIGH);       //maion_color_red
   digitalWrite(4,count%8/4);  //red+blue_purple
   delay(100);
   digitalWrite(4,HIGH);       //main_color_blue
   digitalWrite(3,count%4/2);  //biue+green_light blue
   delay(100);
   digitalWrite(3,HIGH);     //main_color_green
   digitalWrite(2,count%2);  //green+red_yellow
   delay(100);
  }
}
void setColor(int red, int green, int blue)
{
    while ( r != red || g != green || b != blue )
    {
    if ( r < red ) r += 1;
    if ( r > red ) r -= 1;

    if ( g < green ) g += 1;
    if ( g > green ) g -= 1;

    if ( b < blue ) b += 1;
    if ( b > blue ) b -= 1;

    setColor();
    delay(10);
    }
}

void setColor()
{
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}

void loop()
{
   start(1); //เริ่มไฟRainbow_Boom //1
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
   start(1);  //เริ่มไฟup_and_down_preview_color  //2
     up_down(0,0,1);  //blue
     digitalWrite(4,1);
     delay(100);
     digitalWrite(4,0);
     delay(50);
     up_down(0,1,0);  //green
     digitalWrite(3,1);
     delay(100);
     digitalWrite(3,0);
     delay(50);
     up_down(1,0,0);  //red
     digitalWrite(2,1);
     delay(100);
     digitalWrite(2,0);
     delay(50);
    start(1);  //เริ่มไฟflashing_lolypop  //3
      flashinglolypop(1);
      up_down(1,0,1);  //purple
      flashinglolypop(1);
      up_down(0,1,1);  //light_blue
      flashinglolypop(1);
      up_down(1,1,0);  //yellow
    start(1);  //เริ่มไฟLED_RUN_ONETWOTHREE  //4
       for(count=0; count<4; count++)
     {
        digitalWrite(led_pin[count],HIGH);   //Turn on LED
        delay(DELAY_TIME);         //wait 0.5 second(500 ms)
        digitalWrite(led_pin[count],LOW);   //Turn off LED
        delay(DELAY_TIME);
     }
    start(1);  //เริ่มไฟMixing_up_and_down_wonder  //5
       int count;
       digitalWrite(4,1);   //blue
       digitalWrite(3,1);   //green
       delay(DELAY_TIME);
       digitalWrite(4,0);
       digitalWrite(3,0);
       delay(50);
       
       digitalWrite(4,1);   //blue
       delay(100);
       digitalWrite(4,0);
       delay(100);
       digitalWrite(3,1);   //green
       delay(100);
       digitalWrite(3,0);
       delay(100);
       up_down(0,0,1);  //blue
       up_down(0,1,0);  //green
       up_down(0,1,1);  //light blue
       for (count=1;count<=10;count++)
        {
           digitalWrite(4,HIGH);       //main_color_blue
           digitalWrite(3,count%4/2);  //biue+green_light blue
           delay(100);
        }
           digitalWrite(4,1);   //blue
           digitalWrite(2,1);   //red
           delay(DELAY_TIME);
           digitalWrite(4,0);
           digitalWrite(2,0);
           delay(50);
 
       digitalWrite(2,1);   //red
       delay(100);
       digitalWrite(2,0);
       delay(100);
       digitalWrite(4,1);   //blue
       delay(100);
       digitalWrite(4,0);
       delay(100);
       up_down(1,0,0);  //red
       up_down(0,0,1);  //blue
       up_down(1,0,1);  //purple
       for (count=1;count<=10;count++)
        {
           digitalWrite(2,HIGH);       //maion_color_red
           digitalWrite(4,count%8/4);  //red+blue_purple
           delay(100);
        }
     
           digitalWrite(3,1);   //green
           digitalWrite(2,1);   //red
           delay(DELAY_TIME);
           digitalWrite(3,0);
           digitalWrite(2,0);
           delay(50);

       digitalWrite(3,1);   //green
       delay(100);
       digitalWrite(3,0);
       delay(100);
       digitalWrite(2,1);   //red
       delay(100);
       digitalWrite(2,0);
       delay(100);
       up_down(0,1,0);  //green
       up_down(1,0,0);  //red
       up_down(1,1,0);  //yellow
       for (count=1;count<=10;count++)
        {
           digitalWrite(3,HIGH);     //main_color_green
           digitalWrite(2,count%2);  //green+red_yellow
           delay(100);
        }
           digitalWrite(4,1);   //blue
           digitalWrite(2,1);   //red
           digitalWrite(3,1);   //green
           delay(DELAY_TIME);
           digitalWrite(4,0);
           digitalWrite(2,0);
           digitalWrite(3,0);
           delay(50);

        digitalWrite(4,1);   //blue
        delay(100);
        digitalWrite(4,0);
        delay(100);
        digitalWrite(2,1);   //red
        delay(100);
        digitalWrite(2,0);
        delay(100);  
        digitalWrite(3,1);   //green
        delay(100);
        digitalWrite(3,0);
        delay(100);
        up_down(1,1,1);   //white  //mixed_color
        for (count=1;count<=10;count++)
         {
            digitalWrite(2,HIGH);  //main_color_red
            digitalWrite(3,HIGH);  //main_color_green
            digitalWrite(4,HIGH);  //main_color_blue
            digitalWrite(2,count%2);
            digitalWrite(3,count%4/2);
            digitalWrite(4,count%8/4);
            delay(100);
         }
    start(1);  //เริ่มไฟPOK_POK_POK_POK_POK  //6
    for (count=1;count<=2;count++)
     {
       digitalWrite(4,HIGH);
       digitalWrite(3,count%4/2);  
       delay(150);
       digitalWrite(3,HIGH);
       digitalWrite(4,count%8/4);
       delay(150);
       digitalWrite(4,HIGH);
       digitalWrite(4,count%8/4);
       delay(150);
   
       digitalWrite(2,HIGH);
       digitalWrite(4,count%8/4);
       delay(150);
       digitalWrite(3,HIGH);
       digitalWrite(2,count%2);
       delay(150);
       digitalWrite(2,HIGH);
       digitalWrite(2,count%2);
       delay(150);

       digitalWrite(3,HIGH);
       digitalWrite(2,count%2);
       delay(150);
       digitalWrite(4,HIGH);
       digitalWrite(3,count%4/2);
       delay(150);
       digitalWrite(3,HIGH);
       digitalWrite(3,count%4/2);
       delay(150);
     }
    start(1);  //เริ่มไฟPOP_PI_POP_PI_POP_PEEP  //7
    for (count=1;count<=2;count++)
     {
       digitalWrite(4,HIGH);       //main_color_blue
       digitalWrite(3,count%4/2);  //biue+green_light blue
       delay(150);
       up_down(0,1,1);  //mixed_color_light blue

       digitalWrite(2,HIGH);
     
       digitalWrite(4,HIGH);       //main_color_blue
       digitalWrite(3,count%4/2);  //biue+green_light blue
       delay(150);


       digitalWrite(2,HIGH);       //maion_color_red
       digitalWrite(4,count%8/4);  //red+blue_purple
       delay(150);
       up_down(1,0,1);   //mixed_color_purple

       digitalWrite(4,HIGH);

       digitalWrite(2,HIGH);       //maion_color_red
       digitalWrite(4,count%8/4);  //red+blue_purple
       delay(150);
 

       digitalWrite(3,HIGH);     //main_color_green
       digitalWrite(2,count%2);  //green+red_yellow
       delay(150);
       up_down(1,1,0);   //mixed_color_yellow

       digitalWrite(2,HIGH);

       digitalWrite(3,HIGH);     //main_color_green
       digitalWrite(2,count%2);  //green+red_yellow
       delay(150);


       digitalWrite(4,HIGH);       //main_color_blue
       digitalWrite(3,count%4/2);  //biue+green_light blue
       delay(150);

       digitalWrite(3,HIGH);

       digitalWrite(4,HIGH);       //main_color_blue
       digitalWrite(3,count%4/2);  //biue+green_light blue
       delay(150);

       digitalWrite(2,HIGH);       //maion_color_red
       digitalWrite(4,count%8/4);  //red+blue_purple
       delay(150);

       digitalWrite(3,HIGH);     //main_color_green
       digitalWrite(2,count%2);  //green+red_yellow
       delay(150);
       up_down(1,1,1);   //white  //mixed_color
     }
     //digitalWrite(2,HIGH);
     //digitalWrite(2,count%2);
     //digitalWrite(3,count%4/2);
     //digitalWrite(4,count%8/4);
     //delay(DELAY_TIME);
    start(1);  //เริ่มไฟWe wish you a merry Christmas  //8
       //We wish you a merry Christmas
       We_wish_you_amerrychristmas(1,0,0);
         christmas_evePB(1);
         christmas_evePB(1);
       //We wish you a merry Christmas
       We_wish_you_amerrychristmas(0,1,0);
         christmas_evePB(1);
         christmas_evePB(1);
       //We wish you a merry Christmas and a happy new year
       We_wish_you_amerrychristmas(1,0,0);
         christmas_evePB(1);
         christmas_evePB(1);
         christmas_evePB(1);
    start(1);  //เริ่มไฟWhiteday_and_HNY  //9
      digitalWrite(2,1);
      digitalWrite(3,1);
      digitalWrite(4,1);
      delay(100);
      digitalWrite(2,0);
      digitalWrite(3,0);
      digitalWrite(4,0);
      delay(100);
      digitalWrite(2,1);
      digitalWrite(3,1);
      digitalWrite(4,1);
      delay(100);
      digitalWrite(2,0);
      digitalWrite(3,0);
      digitalWrite(4,0);
      delay(100);
      digitalWrite(2,1);
      digitalWrite(3,1);
      digitalWrite(4,1);
      delay(100);
      digitalWrite(2,0);
      digitalWrite(3,0);
      digitalWrite(4,0);
      delay(100);
     
      digitalWrite(2,1);
      digitalWrite(3,0);
      delay(100);
      digitalWrite(2,0);
      digitalWrite(3,1);
      delay(100);
      digitalWrite(2,1);
      digitalWrite(3,0);
      delay(100);
      digitalWrite(2,0);
      digitalWrite(3,1);
      delay(100);
      digitalWrite(2,1);
      digitalWrite(3,0);
      delay(100);
      digitalWrite(2,0);
      digitalWrite(3,1);
      delay(100);
      digitalWrite(2,1);
      digitalWrite(3,0);
      delay(100);
      digitalWrite(2,0);
      digitalWrite(3,1);
      delay(100);
      digitalWrite(2,1);
      digitalWrite(3,0);
      delay(100);
      digitalWrite(2,0);
      digitalWrite(3,1);
      delay(100);
   
      digitalWrite(2,0);
      digitalWrite(3,0);
      digitalWrite(4,0);
      delay(100);
    start(1);  //เริ่มไฟ  //10
      setColor(255, 0, 0);    //red
      setColor(0, 255, 0);    //green
      setColor(0, 0, 255);    //blue
      setColor(255, 255, 0);  //yellow
      setColor(255, 0, 255);  //purple
      setColor(0, 255, 255);  //light_blue
}

