#include <iostream>
#include <string>

using namespace std;

class Client
{
private:
    string clientId;
    string clientName;
    string clientNickname;
    string clientContact;
    string clientEmail;

public:
    Client(string id, string name, string nickname, string contact, string email);

    //getmethod
    string getClientId();
    string getClientName();
    string getClientNickname();
    string getClientContact();
    string getClientEmail();
};

Client::Client(string id, string name, string nickname, string contact, string email)
{
    this->clientId = id;
    this->clientName = name;
    this->clientNickname = nickname;
    this->clientContact = contact;
    this->clientEmail = email;
};

string Client::getClientId()
{
    return this->clientId;
};

string Client::getClientName()
{
    return this->clientName;
};

string Client::getClientNickname()
{
    return this->clientNickname;
};

string Client::getClientContact()
{
    return this->clientContact;
};

string Client::getClientEmail()
{
    return this->clientEmail;
};
