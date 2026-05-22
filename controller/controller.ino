typedef enum{
  Idle,
  Up,
  UpRight,
  Right,
  DownRight,
  Down,
  DownLeft,
  Left,
  UpLeft
} control;

control readController(){
  int x,y;
  x = analogRead(10);
  y = analogRead(11);

  if(x < 2500 && x > 1500 && y < 500){return Up;}
  if(x < 2500 && x > 1500 && y > 2500){return Down;}
  
  if(y < 2500 && y > 1500 && x < 500){return Left;}
  if(y < 2500 && y > 1500 && x > 2500){return Right;}

  
  if(x < 500 && y < 500){return UpLeft;}
  if(x < 500 && y > 2500){return DownLeft;}

  if(x > 2500 && y < 500){return UpRight;}
  if(x > 2500 && y > 2500){return DownRight;}

  return Idle;
}

void setup() {
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  Serial.begin(115200);
}

control state;
control previous = Idle;

void loop() {
  state = readController();
  if(state != previous){
    previous = state;
    switch(state){
      case Idle: break;
      case Up: Serial.println("Up"); break;
      case UpRight: Serial.println("UpRight"); break;
      case Right: Serial.println("Right"); break;
      case DownRight: Serial.println("DownRight"); break;
      case Down: Serial.println("Down"); break;
      case DownLeft: Serial.println("DownLeft"); break;
      case Left: Serial.println("Left"); break;
      case UpLeft: Serial.println("UpLeft"); break;
      default: break;
    }
  }
  delay(5);
}
