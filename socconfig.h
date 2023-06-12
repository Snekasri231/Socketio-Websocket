//uart pins
#define RXD2 16
#define TXD2 17
unsigned long previousMillis = 0;
int interval;
const char* ssid     = "CEET 2.4";
const char* password = "WeLoveIndia";
char host[] = "121.242.232.202"; // Socket.IO Server Address
int port = 5001; // Socket.IO Port Address
char path[] = "/socket.io/?transport=websocket"; // Socket.IO Base Path
bool useSSL = false; // Use SSL Authentication
const char * sslFingerprint = "";  // SSL Certificate Fingerprint
bool useAuth = false; // use Socket.IO Authentication
const char * serverUsername = "socketIOUsername";
const char * serverPassword = "socketIOPassword";
const char * emitTopic = "commandCompleted";
const char * onTopic = "commandToRun";
//const char* startidTopic = "";
