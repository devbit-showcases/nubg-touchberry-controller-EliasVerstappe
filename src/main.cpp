
using namespace std;
#include "lib/qt1070.h"
#include "lib/tlc59116.h"

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


int main(void) {

    std::cout << "\n\n\033[7m+-------------------------------+" << std::endl;
    std::cout << "|Starting touchberry application|" << std::endl;
    std::cout << "+-------------------------------+\033[0m\n" << std::endl; 
    

  //QT1070 touch;
  TLC59116 led;
  // Key button;



  // cout << "REGISTER 0x00 (before led brightness): " << led.readRegister(0x00) << endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  led.setLed(10, 0.5);



  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  led.setGroupBrightness(0.1);


  


  // cout << "REGISTER 0x12: " << led.readRegister(0x12) << endl; 

  // cout << "ERROR REGISTER 1: " << led.readRegister(0x1D) << endl;
  // cout << "ERROR REGISTER 2: " << led.readRegister(0x1E) << endl;
  
  // cout << "REGISTER 0x00 (after led brightness): " << led.readRegister(0x00) << endl;

  // while (1) {
  // button = (Key)touch.button_pressed();
  //   if (button != NONE) {
  //       cout << "Button pressed: " << KeyConverter::key_to_string(button) << endl;
  //       std::this_thread::sleep_for(std::chrono::milliseconds(100));
  //   }

      

  // }

  return 0;
}


