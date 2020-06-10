#include "mbed.h"

#include "bbcar.h"


Ticker servo_ticker;

PwmOut pin8(D8), pin9(D9);
// left->8->testing->0, right->9, 

BBCar car(pin8, pin9, servo_ticker);


int main() {

    // please contruct you own calibration table with each servo

    double pwm_table0[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};

    double speed_table0[] = {-16.587, -16.269, -14.993, -11.643, -5.184, 0.000, 6.220, 12.202, 15.152, 16.349, 16.827};

    double pwm_table1[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};

    double speed_table1[] = {-16.348, -16.109, -15.232, -12.361, -6.539, 0.000, 5.024, 11.005, 14.514, 15.870, 16.348};


    // first and fourth argument : length of table

    car.setCalibTable(11, pwm_table0, speed_table0, 11, pwm_table1, speed_table1);


    while (1) {

        car.goStraightCalib(5);

        wait(5);

        car.stop();

        wait(5);

    }

}