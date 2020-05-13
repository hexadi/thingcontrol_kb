#ifndef __THINGCONTROL_H__
#define __THINGCONTROL_H__

#include <Arduino.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "ArduinoJson.h"
#include <WiFiClientSecure.h>
#include <esp_system.h>

#define TOKEN_SIZE 50
#define MESSAGE_SIZE 200
#define KEY_SIZE 50
#define DATA_SIZE 100

class ThingControl
{
private:
    char access_token[TOKEN_SIZE];
    char message[MESSAGE_SIZE];
    char key[KEY_SIZE];
    char attr_message[MESSAGE_SIZE];
    //char *attr_message;

public:
    ThingControl();

    void setAccessToken(char *);

    void setKey(String);

    void setMessage(String);
    void setMessage(int);
    void setMessage(double);
    void setMessage(bool);

    void sendM();
    bool checkAttr(char *);
    char *AttrValue();
    //void gTest();
};

#endif