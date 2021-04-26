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
// g++ -std=c++14 motor.cpp -o motor -lwiringPi
int main(void){
    
    wiringPiSetup();
    pinMode(enablePin,OUTPUT);//set mode for the pin
    pinMode(motorPin1,OUTPUT);
    pinMode(motorPin2,OUTPUT);
    pinMode(1,INPUT);
    pinMode(4,INPUT);

    softPwmCreate(enablePin,0,100);//define PMW pin
    int sp = 0;
    int start = 0;
    int count_clock = 0;
    while(1){
        if (digitalRead(1))
        {
            if (start==0)
            {
                cout<<"start"<<endl;
                start = 1;
                delay(500);
            }
            else{
                start = 0;
                cout<<"stop"<<endl;
                delay(200);
            }
        }
        if (digitalRead(4)&& start == 1)
        {
            sp = sp + 5;
            if (sp>100)
                sp = 100;
            cout<<"sp: "<<sp<<endl;
            delay(200);
        }
         
        if (start == 1)
        {   
            digitalWrite(motorPin1,HIGH);
            digitalWrite(motorPin2,LOW);
            // softPwmWrite(enablePin,sp);
            softPwmWrite(enablePin,sp);
            // cout<<"in run"<<endl;
            // delay(100);
        }
        else 
        {
            sp =0;
            digitalWrite(motorPin1,LOW);
            digitalWrite(motorPin2,LOW);
            softPwmWrite(enablePin,sp);
        }
        delay(10);
    }

    return 0;
}

