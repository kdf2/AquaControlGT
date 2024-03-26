
#include <WiFi.h>
#include <FirebaseESP32.h>
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>

#define WIFI_SSID "KarlitaFF"
#define WIFI_PASSWORD "MaxNene03."
#define FIREBASE_HOST "https://aquacontrol-d620c-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "ExvXHNKvGmwegXSbczY7wPdNNgDgehO4pcbP25S9"
#define API_KEY "AIzaSyAdREvpKzqBRQqR5IJFm9BquBoNpS_fvBc"
#define DATABASE_URL "aquacontrol-d620c-default-rtdb.firebaseio.com" 
#define USER_EMAIL "fuentes_kd@hotmail.com"
#define USER_PASSWORD "41812101"
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;


String nodo ="/Cantidadagua/Cantagua";

const int pinEntrada1 = 36;
const int pinEntrada2 = 39;
const int pinEntrada3 = 34;
const int pinEntrada4 = 35;
const int pinEntrada5 = 32;
const int pinEntrada6 = 33;
const int pinEntrada7 = 25;
const int pinEntrada8 = 26;
const int pinEntrada9 = 27;
const int pinEntrada10 = 14;
int porcentaje=0;

int Funcion_porcentaje_agua(int nvl1, int nvl2, int nvl3, int nvl4, int nvl5, int nvl6, int nvl7, int nvl8, int nvl9, int nvl10) {

   if(nvl1==1 && nvl2==0 && nvl3==0 && nvl4==0 && nvl5==0 && nvl6==0 && nvl7==0 && nvl8==0 && nvl9==0 && nvl10==0 )
  {
    porcentaje=10;
  }

  else if(nvl1==1 && nvl2==1 && nvl3==0 && nvl4==0 && nvl5==0 && nvl6==0 && nvl7==0 && nvl8==0 && nvl9==0 && nvl10==0 )
  {
    porcentaje=20;
  }

  else if(nvl1==1 && nvl2==1 && nvl3==1 && nvl4==0 && nvl5==0 && nvl6==0 && nvl7==0 && nvl8==0 && nvl9==0 && nvl10==0)
  {
    porcentaje=30;
  }

  else if(nvl1==1 && nvl2==1 && nvl3==1 && nvl4==1 && nvl5==0 && nvl6==0 && nvl7==0 && nvl8==0 && nvl9==0 && nvl10==0 )
  {
    porcentaje=40;
  }

  else if(nvl1==1 && nvl2==1 && nvl3==1 && nvl4==1 && nvl5==1 && nvl6==0 && nvl7==0 && nvl8==0 && nvl9==0 && nvl10==0 )
  {
    porcentaje=50;
  }

   else if(nvl1==1 && nvl2==1 && nvl3==1 && nvl4==1 && nvl5==1 && nvl6==1 && nvl7==0 && nvl8==0 && nvl9==0 && nvl10==0 )
  {
    porcentaje=60;
  }

   else if(nvl1==1 && nvl2==1 && nvl3==1 && nvl4==1 && nvl5==1 && nvl6==1 && nvl7==1 && nvl8==0 && nvl9==0 && nvl10==0 )
  {
    porcentaje=70;
  }

   else if(nvl1==1 && nvl2==1 && nvl3==1 && nvl4==1 && nvl5==1 && nvl6==1 && nvl7==1 && nvl8==1 && nvl9==0 && nvl10==0 )
  {
    porcentaje=80;
  }

   else if(nvl1==1 && nvl2==1 && nvl3==1 && nvl4==1 && nvl5==1 && nvl6==1 && nvl7==1 && nvl8==1 && nvl9==1 && nvl10==0 )
  {
    porcentaje=90;
  }

   else if(nvl1==1 && nvl2==1 && nvl3==1 && nvl4==1 && nvl5==1 && nvl6==1 && nvl7==1 && nvl8==1 && nvl9==1 && nvl10==1 )
  {
    porcentaje=100;
  }

  else{
    porcentaje=0;
  }

  return porcentaje;
}


void setup() {
  
  Serial.begin(9600);
  pinMode(pinEntrada1, INPUT);
  pinMode(pinEntrada2, INPUT);
  pinMode(pinEntrada3, INPUT);
  pinMode(pinEntrada4, INPUT);
  pinMode(pinEntrada5, INPUT);
  pinMode(pinEntrada6, INPUT);
  pinMode(pinEntrada7, INPUT);
  pinMode(pinEntrada8, INPUT);
  pinMode(pinEntrada9, INPUT);
  pinMode(pinEntrada10, INPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("[Wi-Fi]...Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  config.api_key = API_KEY;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  config.database_url = DATABASE_URL;
  config.token_status_callback = tokenStatusCallback; 
  Firebase.reconnectNetwork(true);
  fbdo.setBSSLBufferSize(4096 /* Rx buffer size in bytes from 512 - 16384 */, 1024 /* Tx buffer size in bytes from 512 - 16384 */);
  Firebase.begin(&config, &auth);
  Firebase.setDoubleDigits(5);
  Firebase.reconnectWiFi(true);
  //Firewall that allows only GET and POST requests
  //Firebase.enableClassicRequest(firebaseData, true);
 
}

void loop() {
  FirebaseData firebaseData;
  int entrada1 = digitalRead(pinEntrada1);
  int entrada2 = digitalRead(pinEntrada2);
  int entrada3 = digitalRead(pinEntrada3);
  int entrada4 = digitalRead(pinEntrada4);
  int entrada5 = digitalRead(pinEntrada5);
  int entrada6 = digitalRead(pinEntrada6);
  int entrada7 = digitalRead(pinEntrada7);
  int entrada8 = digitalRead(pinEntrada8);
  int entrada9 = digitalRead(pinEntrada9);
  int entrada10 = digitalRead(pinEntrada10);
   
  if(Firebase.setInt(firebaseData, nodo, Funcion_porcentaje_agua(entrada1, entrada2, entrada3, entrada4, entrada5, entrada6, entrada7, entrada8, entrada9, entrada10))) {
    Serial.println("Envío exitoso");
  } else {
    Serial.println(firebaseData.errorReason());
  }
  Serial.print("el porcentaje es: ");
  Serial.println(Funcion_porcentaje_agua(entrada1, entrada2, entrada3, entrada4, entrada5, entrada6, entrada7, entrada8, entrada9, entrada10));
  delay(1000);

}