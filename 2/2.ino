  #define ROW1 13
  #define ROW2 12
  #define ROW3 11
  #define ROW4 10
  #define ROW5 9
  #define ROW6 8
  #define ROW7 7
  #define ROW8 6
  #define COL1 5
  #define COL2 4
  #define COL3 3
  #define COL4 A4
  #define COL5 A3
  #define COL6 A2
  #define COL7 A1
  #define COL8 A0
  #define BUTTON 2
  const int row[]={ROW1,ROW2,ROW3,ROW4,ROW5,ROW6,ROW7,ROW8};
  const int col[]={COL1,COL2,COL3,COL4,COL5,COL6,COL7,COL8};

  byte scan[8][8]={
    {1,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0},
    {0,0,0,1,0,0,0,0},
    {0,0,0,0,1,0,0,0},
    {0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,1}
  };
    byte circle[8][8]={
    {1,1,0,0,0,0,1,1},
    {1,0,1,1,1,1,0,1},
    {0,1,1,1,1,1,1,0},
    {0,1,1,1,1,1,1,0},
    {0,1,1,1,1,1,1,0},
    {0,1,1,1,1,1,1,0},
    {1,0,1,1,1,1,0,1},
    {1,1,0,0,0,0,1,1}
  };
    byte heart[8][8]={
    {1,0,0,1,1,0,0,1},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,1},
    {1,1,0,0,0,0,1,1},
    {1,1,1,0,0,1,1,1},
    {1,1,1,1,1,1,1,1}
  };
    byte plus[8][8]={
    {1,1,1,0,0,1,1,1},
    {1,1,1,0,0,1,1,1},
    {1,1,1,0,0,1,1,1},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {1,1,1,0,0,1,1,1},
    {1,1,1,0,0,1,1,1},
    {1,1,1,0,0,1,1,1}
  };

  byte previousState=1,presentState=1,patternNumber=0;
  byte incomingbyte;
  void setup() {
  // put your setup code here, to run once:

  for(byte i=0;i<sizeof(row);i++)
  {
    pinMode(row[i],OUTPUT);
  }
    for(byte i=0;i<sizeof(col);i++)
  {
    pinMode(col[i],OUTPUT);
  }
  pinMode(BUTTON,INPUT_PULLUP);

  Serial.begin(9600);
  
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
//  presentState=digitalRead(BUTTON);
//  if(presentState==0&&previousState==1)
//  {
//    patternNumber++;
//    if(patternNumber>2)
//    {
//      patternNumber=0;
//    }
//  }
//  if(patternNumber==0)
//  {
//    showPattern(circle);
//  }
//  else if(patternNumber==1)
//  {
//    showPattern(heart);
//  }
//    else if(patternNumber==2)
//  {
//    showPattern(plus);
//  }
//  delay(2);
//  previousState=presentState;


    if(Serial.available()>0){
      incomingbyte=Serial.read();
    }
    if(incomingbyte=='c')
    {
      patternNumber=0;
    }
    else if(incomingbyte=='h')
    {
      patternNumber=1;
    }
    else if(incomingbyte=='p')
    {
      patternNumber=2;
    }
    else
    {
      patternNumber=previousState;
    }
    if(patternNumber==0){
      showPattern(circle);
    }
    if(patternNumber==1){
      showPattern(heart);
    }
    if(patternNumber==2){
      showPattern(plus);
    }
    previousState=patternNumber;
  
}

void showPattern(byte matrix[8][8])
{
    for(byte i=0;i<8;i++)
    {
      for(byte j=0;j<8;j++)
      {
        digitalWrite(row[7-j],1-scan[i][j]);
        digitalWrite(col[j],1-matrix[i][j]);
      }
      for(byte j=0;j<8;j++)
      {
        digitalWrite(row[j],HIGH);
        digitalWrite(col[j],LOW);
      }
    }
}
