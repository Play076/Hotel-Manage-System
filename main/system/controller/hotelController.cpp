#include <iostream>
#include <exception>
#include <conio.h>
#include <fstream>
#include <vector>
#include "../../obj/hosting.cpp"
#include "../../utils/hexaid.cpp"

using namespace std;

bool returnValueControllerHotel;

class HotelController
{
public:
    int removeHosting(int numberhost);
    int finishHostandPay(int numberhost, string clientnickname);
    int hostingClinet(int numberhost, string clientnickname, string dataHosting);
    int indexHost();
    int createNewHost(Hosting createHost);
};

int HotelController::removeHosting(int numberhost)
{
    try
    {
        fstream fileHost;
        fstream tmpFileHost;

        int countHost;

        int tmpNumberHost;
        int tmpNumberFloor;
        string tmpKeyHost;
        string tmpIdClient;
        string tmpDataHosting;

        vector<int> vectorHotelNumber;
        vector<string> vectorKeyHost;
        vector<string> vectorIdClient;
        vector<string> vectorDataHosting;
        vector<int> vectorFloorHosting;

        fileHost.open("YOUR_DIRECTORY_FILE/database/hostdb.txt", ios::in|ios::app);

        if(fileHost.is_open())
        {  
            while (!fileHost.eof()) 
            {
                fileHost >> tmpNumberHost >> tmpNumberFloor >> tmpIdClient >> tmpKeyHost >> tmpDataHosting;
                vectorHotelNumber.push_back(tmpNumberHost);
                vectorFloorHosting.push_back(tmpNumberFloor);
                vectorIdClient.push_back(tmpIdClient);
                vectorKeyHost.push_back(tmpKeyHost);
                vectorDataHosting.push_back(tmpDataHosting);
                countHost++;
            }
            
        }else
        {
            system("COLOR 06");
            cout << "\n\t\t\tError the file don't was found...";
            returnValueControllerHotel = false;
        }

        fileHost.close();

        remove("YOUR_DIRECTORY_FILE/database/hostdb.txt");

        for(int i = 0; i < countHost; i++)
        {
            if(vectorHotelNumber[i] == numberhost)
            {
                tmpFileHost.open("YOUR_DIRECTORY_FILE/database/hostdb.txt", ios::out|ios::app);

                if(tmpFileHost.is_open())
                {  
                    tmpFileHost << " " << vectorHotelNumber[i] << " " << vectorFloorHosting[i] << " " << "0" << " " << "0" << " " << "00/00/0000" << endl;
                    returnValueControllerHotel = true;
                    break;
                }else
                {
                    system("COLOR 06");
                    cout << "\n\t\t\tError the file don't was found...";
                    returnValueControllerHotel = false;
                }

                tmpFileHost.close();
                break;
            }
        }
    }
    catch(const std::exception& ex)
    {
        system("COLOR 04");
        cout << "\n\t\t\tSome error in system\n\t\t\t" << endl;
        cerr << ex.what() << endl;

        returnValueControllerHotel = false;
    }
    
    return returnValueControllerHotel;
};

int HotelController::finishHostandPay(int numberhost, string clientnickname)
{
    try
    {
        fstream fileHost;
        fstream tmpFileHost;
        fstream fileClient;
        fstream tmpFileClient;

        bool clientFind = false;

        int countHost;
        int countClient;

        int tmpNumberHost;
        int tmpNumberFloor;
        string tmpKeyHost;
        string tmpIdClient;
        string tmpClientNickname;
        string tmpDataHosting;

        string clientName;
        string clientContact;
        string clientEmail;

        vector<int> vectorHotelNumber;
        vector<string> vectorKeyHost;
        vector<string> vectorIdClient;
        vector<string> vectorclientnickname;
        vector<string> vectorclientId;
        vector<string> vectorDataHosting;

        fileHost.open("YOUR_DIRECTORY_FILE/database/hostdb.txt", ios::in|ios::app);

        if(fileHost.is_open())
        {  
            while (!fileHost.eof())
            {
                fileHost >> tmpNumberHost >> tmpNumberFloor >> tmpIdClient >> tmpKeyHost >> tmpDataHosting;
                vectorHotelNumber.push_back(tmpNumberHost);
                vectorIdClient.push_back(tmpIdClient);
                vectorKeyHost.push_back(tmpKeyHost);
                vectorDataHosting.push_back(tmpDataHosting);
                countHost++;
            }
            
        }else
        {
            system("COLOR 06");
            cout << "\n\t\t\tError the file don't was found...";
            returnValueControllerHotel = false;
        }

        fileHost.close();

        fileClient.open("YOUR_DIRECTORY_FILE/database/clientdb.txt", ios::in|ios::app);

        if(fileClient.is_open())
        {
            while (!fileClient.eof())
            {
                fileClient >> tmpIdClient >> clientName >> tmpClientNickname >> clientContact >> clientEmail;

                vectorclientId.push_back(tmpIdClient);
                vectorclientnickname.push_back(tmpClientNickname);
            }
            
        }else
        {
            system("COLOR 06");
            cout << "\n\t\t\tError the file don't was found...";
            returnValueControllerHotel = false;
        }

        fileClient.close();

        for(int i = 0; i < countClient; i++)
        {
            if(vectorclientnickname[i] == clientnickname)
            {
                tmpIdClient = vectorclientId[i];
                break;
            }
        }

        for(int i = 0; i < countHost; i++)
        {
            if(vectorHotelNumber[i] == numberhost)
            {
                tmpDataHosting = vectorDataHosting[i];
                clientFind = true;
                break;
            }
        }

        if(clientFind)
        {
            system("COLOR 02");
            cout << "\n\t\t\tThe client: " << clientnickname << endl;
            cout << "\n\t\t\tHost number: " << numberhost << endl;
            cout << "\n\t\t\tHosting in: [" << tmpDataHosting << "]\n" << endl;
            returnValueControllerHotel = true;
        }else
        {
            system("COLOR 06");
            cout << "\n\t\t\tNot was find nothing..\n\t\t\t" << endl;
            returnValueControllerHotel = false;
        }
    }
    catch(const std::exception& ex)
    {
        system("COLOR 04");
        cout << "\n\t\t\tSome error in system\n\t\t\t" << endl;
        cerr << ex.what() << endl;

        returnValueControllerHotel = false;
    }
    
    return returnValueControllerHotel;
};

int HotelController::hostingClinet(int numberhost, string clientnickname, string dataHosting)
{
    fstream fileClient;
    fstream filetmp_host;
    fstream filehost;

    int tmpNumberHost;
    int tmpNumberFloor;
    int countHost = 0;
    int countClient = 0;

    bool ownerClient=false;
    bool checkbusy=true;

    string tmpIdClient;
    string tmpIdKeyHost;
    string tmpDataHosting;

    string currentIdClient;
    string clientId;
    string clientName;
    string clientNickname;
    string clientContact;
    string clientEmail;

    string newKeyHosting;

    vector<int> vectorNumberHost;
    vector<int> vectorNumberFloor;
    vector<string> vectorIdHost;
    vector<string> vectorIdkeyHost;
    vector<string> vectorDataHosting;
    vector<string> vectorClientId;
    vector<string> vectorClientNickname;

    try
    {
        filehost.open("YOUR_DIRECTORY_FILE/database/hostdb.txt", ios::in|ios::app);

        if(filehost.is_open())
        {
            while (!filehost.eof())
            {
                filehost >> tmpNumberHost >> tmpNumberFloor >> tmpIdClient >> tmpIdKeyHost >> tmpDataHosting;

                vectorNumberHost.push_back(tmpNumberHost);
                vectorNumberFloor.push_back(tmpNumberFloor);
                vectorIdHost.push_back(tmpIdClient);
                vectorIdkeyHost.push_back(tmpIdKeyHost);
                vectorDataHosting.push_back(tmpDataHosting);
                countHost++;
            }
        }else
        {
            system("COLOR 06");
            cout << "\n\t\t\tError the file don't was found...\n\t\t\t";
            returnValueControllerHotel = false;
        }

        filehost.close();

        fileClient.open("YOUR_DIRECTORY_FILE/database/clientdb.txt", ios::in|ios::app);

        if(fileClient.is_open())
        {
            while(!fileClient.eof())
            {
                fileClient >> clientId >> clientName >> clientNickname >> clientContact >> clientEmail;
            
                vectorClientId.push_back(clientId);
                vectorClientNickname.push_back(clientNickname);
                countClient++;
            }
        }else
        {
            system("COLOR 06");
            cout << "\n\t\t\tError the file don't was found...\n\t\t\t";
            returnValueControllerHotel = false;
        }

        fileClient.close();

        for(int i = 0; i < countHost; i++)
        {
            if(vectorNumberHost[i] == numberhost)
            {
                if(vectorIdHost[i] == "0")
                {
                    tmpNumberFloor = vectorNumberFloor[i];
                    system("COLOR 03");
                    cout << "\n\t\t\tThe hotel with number: " << numberhost << " are free, ready for new client\n" << endl; 
                    checkbusy = false;
                    break;
                }
                break;
            }
        }

        for(int i = 0; i < countClient; i++)
        {
            if(vectorClientNickname[i] == clientNickname)
            {
               clientId = vectorClientId[i];
               break;
            }
        }
        
        countHost = -1;

        if(checkbusy)
        {
            vectorClientId.clear();
            vectorClientNickname.clear();
            vectorIdHost.clear();
            vectorIdkeyHost.clear();
            vectorNumberFloor.clear();
            vectorNumberHost.clear();
            system("COLOR 03");
            cout << "\n\t\t\tThe hotel with number: " << numberhost <<" are Busy\n" << endl;
            returnValueControllerHotel = true;
        }else
        {
            filetmp_host.open("YOUR_DIRECTORY_FILE/database/hostdbtmp.txt", ios::out|ios::app);
            
            newKeyHosting = generateUniqueHexaId();

            Hosting *hosting = new Hosting(numberhost, tmpNumberFloor, clientId, newKeyHosting, dataHosting);
            
            if(filetmp_host.is_open())
            {
                for(int i = 0; i < countHost; i++)
                {
                    filetmp_host << vectorNumberHost[i] << " " << vectorNumberFloor[i] << " " << vectorIdHost[i] << " " << vectorIdkeyHost[i] << endl;
                }
                
                filetmp_host << hosting->getNumberHosting() << " "  << hosting->getFloorHosting() << " " << hosting->getIdClient() << " " << hosting->getKeyHosting() << " " << hosting->getDataHosting() << endl;
            }

            filetmp_host.close();
        }

        remove("YOUR_DIRECTORY_FILE/database/hostdb.txt");
        rename("YOUR_DIRECTORY_FILE/database/hostdbtmp.txt", "YOUR_DIRECTORY_FILE/database/hostdb.txt");

        vectorClientId.clear();
        vectorClientNickname.clear();
        vectorIdHost.clear();
        vectorIdkeyHost.clear();
        vectorNumberFloor.clear();
        vectorNumberHost.clear();

        system("COLOR 02");
        cout << "\n\t\t\tThe client: " << clientNickname << ", are registed now in host number: " << numberhost << ", the key is: " << newKeyHosting << ", an floor: " << tmpNumberFloor << endl;

        returnValueControllerHotel = true;
    }
    catch(const exception& ex)
    {
        system("COLOR 04");
        cout << "\n\t\t\tSome error in system\n\t\t\t" << endl;
        cerr << ex.what() << endl;

        returnValueControllerHotel = false;
    }
    
    return returnValueControllerHotel;
}

int HotelController::indexHost()
{
    fstream filehost;

    int getHostNumber = 0;
    int getHostFlooor = 0;
    int count = 0;
    string idClientekey;
    string idKeyAcess;
    string dataHosting;

    vector<int> vectorNumberHost;
    vector<int> vectorNumberFloor;
    vector<string> vectorIdClient;
    vector<string> vectorIdkey;
    vector<string> vectorData;

    try
    {
        filehost.open("YOUR_DIRECTORY_FILE/database/hostdb.txt", ios::in|ios::app);

        if(filehost.is_open())
        {
            while(!filehost.eof())
            {
                filehost >> getHostNumber >> getHostFlooor >> idClientekey >> idKeyAcess >> dataHosting;
                vectorNumberHost.push_back(getHostNumber);
                vectorNumberFloor.push_back(getHostFlooor);
                vectorIdClient.push_back(idClientekey);
                vectorIdkey.push_back(idKeyAcess);
                vectorData.push_back(dataHosting);
                count++;
            }

            for(int i = 0; i < count; i++)
            {
                cout << "\n\t\t\tHost Number: " << vectorNumberHost[i] << endl;
                cout << "\t\t\tHost Floor: " << vectorNumberFloor[i] << endl;
                if(vectorIdClient[i] == "0")
                {
                    cout << "\t\t\tStatus: Free\n" << endl;
                }else
                {
                    cout << "\t\t\tStatus: Busy\n" << endl;
                }
                
            }

            vectorNumberHost.clear();
            vectorNumberFloor.clear();
            vectorIdClient.clear();
            vectorIdkey.clear();
            vectorData.clear();

            returnValueControllerHotel = true;
        }else
        {
            system("COLOR 06");
            cout << "\n\t\t\tError the file don't was found...\n\t\t\t";
            returnValueControllerHotel = false;
        };

        filehost.close();
    }catch(const exception& ex)
    {
        system("COLOR 04");
        cout << "\n\t\t\tSome error in system\n\t\t\t" << endl;
        cerr << ex.what() << endl;

        returnValueControllerHotel = false;
    }

    return returnValueControllerHotel;
};

int HotelController::createNewHost(Hosting createHost)
{
    try
    {
        fstream filehost;

        filehost.open("YOUR_DIRECTORY_FILE/database/hostdb.txt", ios::out|ios::app);   

        if(filehost.is_open())
        {
            filehost << createHost.getNumberHosting() << " " << createHost.getFloorHosting() << " " << createHost.getIdClient() << " " << createHost.getKeyHosting() << " " << createHost.getDataHosting() << endl;

            cout << "\n\t\t\tNew hosting with number: " << createHost.getNumberHosting() << " was created with success\n" << endl;

            returnValueControllerHotel = true;
        }else
        {
            system("COLOR 06");
            cout << "\n\t\t\tError the file don't was found...\n\t\t\t";
            returnValueControllerHotel = false;
        };

        filehost.close();
    }
    catch(const exception& ex)
    {
        system("COLOR 04");
        cout << "\n\t\t\tSome error in system\n\t\t\t" << endl;
        cerr << ex.what() << endl;

        returnValueControllerHotel = false;
    }
    

    return returnValueControllerHotel;
};