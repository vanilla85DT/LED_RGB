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
///////////////////1(rainbow)/////////////////////////
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
/////////////////////2(up_down)//////////////////////
     up_down(0,0,1);  //blue
     up_down(0,1,0);  //green 
     up_down(1,0,0);  //red
/////////////////////3(flashing)/////////////////////
    for (count=1;count<=7;count++)
  {
   digitalWrite(2,HIGH);       //maion_color_red
   digitalWrite(4,count%8/4);  //red+blue_purple
   delay(100);
  }
    for (count=1;count<=7;count++)
  {
   digitalWrite(4,HIGH);       //main_color_blue
   digitalWrite(3,count%4/2);  //biue+green_light blue
   delay(100);
  }
   for (count=1;count<=7;count++)
  {
   digitalWrite(3,HIGH);     //main_color_green
   digitalWrite(2,count%2);  //green+red_yellow
   delay(100);
  }
//////////////////////4(LED RUN)////////////////////
   for(count=0; count<4; count++)
  {
   digitalWrite(led_pin[count],HIGH);   //Turn on LED
   delay(DELAY_TIME);         //wait 0.5 second(500 ms)
   digitalWrite(led_pin[count],LOW);   //Turn off LED
   delay(DELAY_TIME);
  }
/////////5(Mixing up and down colors)//////////////
  int  count;
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
  //up_down(0,0,1);   //blue //main_color
  //up_down(1,0,0);   //red  //main_color
  //up_down(0,1,0);   //green  //main_color
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
//////////////////////6(POK POK POK POK POK)////////////////////////
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
//////////////////////6(POP PI POP PEEP)////////////////////////
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
//////////////////////7()////////////////////////
}
