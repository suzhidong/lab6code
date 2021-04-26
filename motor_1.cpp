#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>
#include <math.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>
using namespace std;
#define motorPin1    2        //define the pin connected to L293D
#define motorPin2    3
#define enablePin    26
// g++ -std=c++14 motor_1.cpp -o motor_1 -lwiringPi
int main(void){
    
    wiringPiSetup();
    pinMode(enablePin,OUTPUT);//set mode for the pin
    pinMode(motorPin1,OUTPUT);
    pinMode(motorPin2,OUTPUT);
    

    softPwmCreate(enablePin,0,100);//define PMW pin

    while(1){
        digitalWrite(motorPin1,HIGH);
        digitalWrite(motorPin2,LOW);
        softPwmWrite(enablePin,50);
        delay(10);
    }

    return 0;
}

