#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "FTN_wifi"; //podesiti
const char* password = "ftn12345"; //podesiti

WebServer server(80);

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

int controllerCode = 0;

void handleCtrl() {
  server.send(200, "text/plain", String(controllerCode));
}

control readController(){
  int x,y;
  x = analogRead(4);
  y = analogRead(5);

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
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  } 
  Serial.println();
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/ctrl");

  server.on("/ctrl", handleCtrl);
  server.begin();
}

control state;
control previous = Idle;

void loop() {
  state = readController();
  controllerCode = (int) state;
  //Serial.println(controllerCode);

  server.handleClient();
  /*if(state != previous){
    previous = state;
    (switch(state){
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
  }*/
}