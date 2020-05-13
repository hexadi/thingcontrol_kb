#ifndef __THINGCONTROL_CPP__
#define __THINGCONTROL_CPP__

#include "thingcontrol.h"

static const char *TAG = "ThingControl";

const char *server = "thingcontrol.io";
WiFiClientSecure client;

ThingControl::ThingControl() {}

bool check(char *str)
{
	bool value = false;
	int len = strlen(str);
	int x = atoi(str);
	for (int i = 0; i < len; i++)
	{
		if (isdigit(str[i]) == 1 || str[i] == '.')
		{
		}
		else
		{
			value = false;
			break;
		}
		value = true;
	}
	return value;
}

void ThingControl::setAccessToken(char *token)
{
	Serial.begin(115200);
	memset(this->access_token, 0, TOKEN_SIZE);
	strcpy(this->access_token, token);
}

void ThingControl::setKey(String key)
{
	strcpy(this->key, key.c_str());
}

void ThingControl::setMessage(String msg)
{
	strcpy(this->message, msg.c_str());
}

void ThingControl::setMessage(int number)
{
	itoa(number, this->message, 10);
}

void ThingControl::setMessage(double number)
{
	sprintf(this->message, "%f", number);
}

void ThingControl::setMessage(bool boolean)
{
	strcpy(this->message, boolean ? "true" : "false");
}

void ThingControl::sendM()
{
	char *data = (char *)malloc(DATA_SIZE);
	char *url = (char *)malloc(200);
	memset(url, 0, 200);
	Serial.println(url);

	memset(data, 0, DATA_SIZE);
	if (check(this->message) == false)
	{
		sprintf(data, "{\"%s\":\"%s\"}", this->key, this->message);
	}
	else
	{
		sprintf(data, "{\"%s\":%s}", this->key, this->message);
	}

	if (!client.connect(server, 443))
		Serial.println("Connection failed!");
	else
	{
		Serial.println("Connected to server!");
		// Make a HTTP request:
		char *url = (char *)malloc(200);
		sprintf(url, "/api/v1/%s/telemetry", this->access_token);
		client.print("POST ");
		client.print(url);
		client.println(" HTTP/1.1");
		client.print("Host: ");
		client.println(server);
		client.println("Content-type: application/json");
		client.print("Content-Length: ");
		client.println(String(strlen(data)));
		client.println();
		client.println(data);
		while (client.connected())
		{
			String line = client.readStringUntil('\n');
			Serial.println(line);
			if (line == "\r")
			{
				Serial.println("headers received");
				break;
			}
		}
		while (client.available())
		{
			char c = client.read();
			Serial.write(c);
		}
		client.stop();
	}
	free(url);
	free(data);
	memset(key, 0, sizeof key);
	memset(message, 0, sizeof message);
}

bool ThingControl::checkAttr(char *client_key)
{
	char *data = (char *)malloc(DATA_SIZE);

	if (!client.connect(server, 443))
		Serial.println("Connection failed!");
	else
	{
		Serial.println("Connected to server!");
		// Make a HTTP request:
		char *url = (char *)malloc(200);
		sprintf(url, "/api/v1/%s/attributes?clientKeys=%s", this->access_token, client_key);
		client.print("GET ");
		client.print(url);
		client.println(" HTTP/1.1");
		client.print("Host: ");
		client.println(server);
		client.println("Content-type: application/json");
		client.println();
		bool isSuccess = false;
		while (client.connected())
		{
			String line = client.readStringUntil('\n');
			Serial.println(line.c_str());
			if (line == "\r")
			{
				Serial.println("headers received");
				break;
			}
		}
		while (client.available())
		{
			char c = client.read();
			Serial.print(c);
			if (c == '{')
			{
				isSuccess = true;
			}
			if (isSuccess)
			{
				sprintf(data,"%s%c",data,c);
			}
		}
		Serial.println("");
		free(url);
		client.stop();
		if (isSuccess)
		{
			StaticJsonBuffer<50> jb;
			JsonObject &root = jb.parseObject(data);
			const char *test = root[client_key];
			Serial.println(test);
			strcpy(this->attr_message, test);
			free(data);
			return true;
		}
		else
		{
			free(data);
			return false;
		}
	}
}

char *ThingControl::AttrValue()
{
	return this->attr_message;
}

#endif