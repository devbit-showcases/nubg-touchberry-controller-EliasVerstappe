#pragma once


#include <iostream>
#include <unistd.h>   // close
#include <fcntl.h>    // O_RDWR
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>  // I2C_SLAVE
#include <string>




class QT1070 {

   public:
     QT1070();
     int get_chip_id();

   private:
     const static int I2CADDRESS = 0x1B;
     const static std::string DEVICE;

     int i2cfile;

};

