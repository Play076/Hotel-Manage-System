#include <iostream>
#include <exception>
#include <conio.h>
#include <fstream>
#include <vector>
#include "../../obj/client-obj.cpp"

using namespace std;

bool returnValueControllerClient = false;

class ClientController
{
public:
    int registerClient(Client newclient);
};

int ClientController::registerClient(Client newclient)
{
    fstream clientHost;

    try
    {
        clientHost.open("C:/Users/user/Documents/hotelsystem/database/clientdb.txt", ios::out|ios::app);

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