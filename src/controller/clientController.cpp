#include <iostream>
#include <exception>
#include <conio.h>
#include <fstream>
#include "../models/client-obj.cpp"

using namespace std;

bool returnValueControllerClient = false;

int countClient = 0;

string idClient;
string clientName;
string clientNickName;
string clientContact;
string clientEmail;

fstream clientHost;

class ClientController
{
public:
    int registerClient(Client newclient);
    int findRegistedClient(string clientNickname);
};

int ClientController::registerClient(Client newclient)
{
    try
    {
        clientHost.open("YOUR_DIRECTORY_FILE/clientdb.txt", ios::out|ios::app);

        if(clientHost.is_open())
        {
            clientHost << newclient.getClientId() << " " << newclient.getClientName() << " " << newclient.getClientNickname() << " " << newclient.getClientContact() << " " << newclient.getClientEmail() << endl;
    
            cout << "\n\t\t\tThe new client, the Mr. " << newclient.getClientNickname() << ", was registed with successs!." << endl;

            returnValueControllerClient = true;
        }else
        {
            system("COLOR 06");
            cout << "\n\t\t\tSome error with tried open file\n\t\t\t" << endl;
            
            returnValueControllerClient = false;
        };

        clientHost.close();
    }
    catch(const exception& ex)
    {
        system("COLOR 04");
        cout << "\n\t\t\tSome error in system\n\t\t\t" << endl;
        cerr << ex.what() << endl;

        returnValueControllerClient = false;
    }
    
    return returnValueControllerClient;
};

int ClientController::findRegistedClient(string clientNickname)
{
    clientHost.open("YOUR_DIRECTORY_FILE/clientdb.txt", ios::in|ios::app);

    if(clientHost.is_open())
    {
        try
        {
            while (!clientHost.eof())
            {
                clientHost >> idClient >> clientName >> clientNickName >> clientContact >> clientEmail;
                
                vectorClientId.push_back(idClient);
                vectorClientName.push_back(clientName);
                vectorClientNickname.push_back(clientNickName);
                vectorClientPhoneContact.push_back(clientContact);
                vectorClientEmail.push_back(clientEmail);
                countClient++;
            }
        }catch(exception &ex)
        {
            system("COLOR 04");
            cout << "\n\t\tError to open file\t\t" << endl;
            returnValueControllerClient = false;
        }
    }else
    {
        system("COLOR 06");
        cout << "\n\t\tSome error with tried open file\t\t" << endl;

        returnValueControllerClient = false;
    }
    countClient--;
    try
    {
        for(int i = 0; i < countClient; i++)
        {
            if(vectorClientNickname[i] == clientNickname)
            {
                cout << "\n\t\tClient Infor " << endl;
                cout << "\n\t\tClient Name: " << vectorClientName[i] << endl;
                cout << "\n\t\tClient Nickname: " << vectorClientNickname[i] << endl;
                cout << "\n\t\tClient Phone Number: " << vectorClientPhoneContact[i] << endl;
                cout << "\n\t\tClient Email: " << vectorClientEmail[i] << endl;
                returnValueControllerClient = true;
            }
        }
    }catch(exception &ex)
    {
        system("COLOR 04");
        cout << "\n\t\tSome error to find the client: " << clientNickname << " in system\t\t" << endl;
        returnValueControllerClient = false; 
    }

    if(!returnValueControllerClient)
    {
        system("COLOR 06");
        cout << "\n\t\tNo client with " << clientNickname << " was found, please try other...\t\t" << endl;
        returnValueControllerClient = false;
    }

    return returnValueControllerClient;
};