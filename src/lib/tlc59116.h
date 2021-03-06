#pragma once

#include <iostream>
#include <unistd.h>   // close
#include <fcntl.h>    // O_RDWR
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>  // I2C_SLAVE
#include <string>
#include <thread>
#include <stdlib.h>
#include "rgb.h"
#include "hsl.h"


class TLC59116 {

    public:
        TLC59116();
        void setGroupBrightness(float brightness);
        void enable();
        int readRegister(char address);
        void setLed(int index, float brightness);
        void setLedNr(int ledNumber, int red, int green, int blue);
        void setAllLeds(int red, int green, int blue);
        void clearLeds();
        void disableLed(int ledNumber);
        
        
        void randomAll();
        void insideOut();
        void outsideIn();
        void left();
        void right();
        void colorLoop();
        void randomWhite();
        void prettyColors();


    protected:
        void initialize();
        void setOutputState(int ledout0, int ledout1, int ledout2, int ledout3);


    private:
        const static int I2CADDRESS = 0x60;
        const static std::string DEVICE;

        int i2cfile;

    private:
        void setRegister(char reg, char value);


        static const int GRPPWM = 0x12;
        static const int FIRSTLED = 0x02;
        
        


};
