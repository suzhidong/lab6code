
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
#define motorPin1    2        //define the pin connected to L293D
#define motorPin2    3
#define enablePin    26

// g++ -std=c++14 Lab7EX1.cpp -o Lab7EX1 -lwiringPi

int main(void){
    
    wiringPiSetup();
    pinMode(enablePin,PWM_OUTPUT);//set mode for the pin
    pinMode(motorPin1,OUTPUT);
    pinMode(motorPin2,OUTPUT);

    int sp = 300;
    
    while(1){
            digitalWrite(motorPin1,HIGH);
            digitalWrite(motorPin2,LOW);
            pwmWrite(enablePin, sp);
    }
    return 0;
}

