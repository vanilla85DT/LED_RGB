void setup()
{
  Serial.begin(115200);
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
  delay(50);
  
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
 delay(50);
}

void loop()
{ 
  int  count;
  up_down(0,0,1);  //blue
  up_down(0,1,0);  //green 
  up_down(0,1,1);  //light blue 
   for (count=1;count<=20;count++)
  {
   digitalWrite(4,HIGH);       //main_color_blue
   digitalWrite(3,count%4/2);  //biue+green_light blue
   delay(100);
  }
  
  up_down(1,0,0);  //red 
  up_down(0,0,1);  //blue
  up_down(1,0,1);  //purple
   for (count=1;count<=20;count++)
  {
   digitalWrite(2,HIGH);       //maion_color_red
   digitalWrite(4,count%8/4);  //red+blue_purple
   delay(100);
  }
  
  up_down(0,1,0);  //green
  up_down(1,0,0);  //red
  up_down(1,1,0);  //yellow
   for (count=1;count<=20;count++)
  {
   digitalWrite(3,HIGH);     //main_color_green
   digitalWrite(2,count%2);  //green+red_yellow
   delay(100);
  }
  
  up_down(0,0,1);   //blue //main_color
  up_down(1,0,0);   //red  //main_color
  up_down(0,1,0);   //green  //main_color
  up_down(1,1,1);   //white  //mixed_color
   for (count=1;count<=20;count++)
  {
   digitalWrite(2,HIGH);  //main_color_red
   digitalWrite(3,HIGH);  //main_color_green
   digitalWrite(4,HIGH);  //main_color_blue
   digitalWrite(2,count%2);
   digitalWrite(3,count%4/2);
   digitalWrite(4,count%8/4);
   delay(100);
  }
  
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

   //digitalWrite(2,HIGH);
   //digitalWrite(2,count%2);
   //digitalWrite(3,count%4/2);
   //digitalWrite(4,count%8/4);
   //delay(50);
   
  }
  
  
}
