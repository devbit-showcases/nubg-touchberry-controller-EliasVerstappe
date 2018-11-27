
using namespace std;
#include "lib/qt1070.h"
#include "lib/tlc59116.h"
#include <simple_mqtt_client/simple_mqtt_client.h>


using namespace BiosSimpleMqttClient;

enum Key {
  NONE = 0,
  LEFT = 1,
  RIGHT = 2,
  UP = 4,
  DOWN = 8,
  B = 16,
  A = 32,
  X = 64
  };

class KeyConverter {

    public:
    static std::string key_to_string(Key key) {
      switch (key) {
        case UP:
          return "UP";
        case DOWN:
          return "DOWN";
        case LEFT:
          return "LEFT";
        case RIGHT:
          return "RIGHT";
        case X:
          return "X";
        case B:
          return "B";
        case A:
          return "A";
        case NONE:
          return "NONE";  
      }
      return "";     // Unknown key? Should never happen
    }
};

const std::string SERVER_ADDRESS("tcp://mqtt.labict.be:1883");
const std::string CLIENT_ID("eeltbal123456");
const std::string TOPIC("test/hello");

int main(void) {

  std::cout << "\n\n\033[7m+-------------------------------+" << std::endl;
  std::cout << "|Starting touchberry application|" << std::endl;
  std::cout << "+-------------------------------+\033[0m\n" << std::endl; 

  QT1070 touch;
  TLC59116 led;
  Key button;

  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  led.clearLeds();

  SimpleMQTTClient simpleClient(SERVER_ADDRESS, CLIENT_ID);
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));

  MQTTMessage message(TOPIC, "Hello @ ALL from Elias");
  simpleClient.publish(message);


  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  while (1) {
  button = (Key)touch.button_pressed();
    if (button != NONE) {
      cout << "Button pressed: " << KeyConverter::key_to_string(button) << endl;

      switch(button) {
        case RIGHT :
          led.right();
          break;
        
        case LEFT :
          led.left();
          break;

        case UP :
          led.insideOut();
          break;
        
        case DOWN :
          led.outsideIn();
          break;

        case B :
          led.colorLoop();
          break;
        
        case X :
          for (int i = 0; i < 50; i++) {
            led.randomAll();
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
          }
          led.clearLeds();
          break;

        case A :
          for (int i = 0; i < 50; i++) {
            led.prettyColors();
          }
          led.clearLeds();
          break;
        
      }
        
    }

  }


  return 0;
}


