#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Hosting
{
private:
    int numberHosting;
    int floorHosting;
    string idClient;
    string keyHosting;
    string dataHosting;

public:
    Hosting(int number, int floor, string idclient, string keyhosting, string data);

    //Set Method
    int setNumberHosting(int hostNumber);
    int setNumberFloor(int hostFloor);
    string setIdClient(string id);
    string setKeyHosting(string key);
    string setDataHosting(string data);
    //Get Method
    int getNumberHosting();
    int getFloorHosting();
    string getIdClient();
    string getKeyHosting();
    string getDataHosting();
};

Hosting::Hosting(int number, int floor, string idclient, string keyhosting, string data)
{
    this->numberHosting = number;
    this->floorHosting = floor;
    this->idClient = idclient;
    this->keyHosting = keyhosting;
    this->dataHosting = data;
};

//Set Method
int Hosting::setNumberHosting(int hostNumber)
{
    return this->numberHosting = hostNumber;
};
int Hosting::setNumberFloor(int hostFloor)
{
    return this->floorHosting = hostFloor;
};
string Hosting::setIdClient(string id)
{
    return this->idClient = id;
};
string Hosting::setKeyHosting(string key)
{
    return this->keyHosting = key;
}; 
string Hosting::setDataHosting(string data)
{
    return this->dataHosting = data;
};
//Get Method
int Hosting::getNumberHosting()
{
    return this->numberHosting;
};
int Hosting::getFloorHosting()
{
    return this->floorHosting;
};
string Hosting::getIdClient()
{
    return this->idClient;
};
string Hosting::getKeyHosting()
{
    return this->keyHosting;
};
string Hosting::getDataHosting()
{
    return this->dataHosting;
};