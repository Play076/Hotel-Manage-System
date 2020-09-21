#include <iostream>
#include <exception>
#include <conio.h>
#include <fstream>
#include <vector>
#include "../../obj/hosting.cpp"
#include "../../utils/hexaid.cpp"
#include "../../utils/vectors.cpp"

bool returnValueControllerHotel;

int tmpNumberHost;
int tmpNumberFloor;
    
string tmpIdClient;
string tmpKeyHost;
string tmpIdKeyHost;
string tmpClientNickname;
string tmpDataHosting;

fstream fileClient;
fstream fileHost;
fstream tmpFileClient;
fstream tmpFileHost;

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
    int countHost = 0;
    try
    {
        fileHost.open("YOUR_DIRECTORY_FILE/database/hostdb.txt", ios::in|ios::app);

        if(fileHost.is_open())
        {
            while (!fileHost.eof())
            {
                fileHost >> tmpNumberHost >> tmpNumberFloor >> tmpIdClient >> tmpIdKeyHost >> tmpDataHosting;
                vectorHotelNumber.push_back(tmpNumberHost);
                vectorFloorHosting.push_back(tmpNumberFloor);
                vectorIdClient.push_back(tmpIdClient);
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

        fileHost.close();

        countHost--;

        remove("YOUR_DIRECTORY_FILE/database/hostdb.txt");

        tmpFileHost.open("YOUR_DIRECTORY_FILE/database/hostdb.txt", ios::out|ios::app);

        if(tmpFileHost.is_open())
        {
            for(int i = 0; i < countHost; i++)
            {
                if(vectorHotelNumber[i] == numberhost)
                {
                    tmpFileHost << " " << vectorHotelNumber[i] << " " << vectorFloorHosting[i] << " " << "0" << " " << "0" << " " << "00/00/0000" << endl;
                    returnValueControllerHotel = true;
                }else
                {
                    tmpFileHost << " " << vectorHotelNumber[i] << " " << vectorFloorHosting[i] << " " << vectorIdClient[i] << " " << vectorIdkeyHost[i] << " " << vectorDataHosting[i] << endl;
                }
            }
        }else
        {
            system("COLOR 06");
            cout << "\n\t\t\tError the file don't was found...";
            returnValueControllerHotel = false;
        }
        tmpFileHost.close();
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
        bool clientFind = false;

        int countHost;
        int countClient;

        int tmpNumberHost;
        int tmpNumberFloor;

        string clientName;
        string clientContact;
        string clientEmail;

        fileHost.open("YOUR_DIRECTORY_FILE/database/hostdb.txt", ios::in|ios::app);

        if(fileHost.is_open())
        {  
            while (!fileHost.eof())
            {
                fileHost >> tmpNumberHost >> tmpNumberFloor >> tmpIdClient >> tmpKeyHost >> tmpDataHosting;
                vectorHotelNumber.push_back(tmpNumberHost);
                vectorIdClient.push_back(tmpIdClient);
                vectorIdkeyHost.push_back(tmpKeyHost);
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

                vectorClientId.push_back(tmpIdClient);
                vectorClientNickname.push_back(tmpClientNickname);
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
            if(vectorClientNickname[i] == clientnickname)
            {
                tmpIdClient = vectorClientId[i];
                break;
            }
        }

        for(int i = 0; i < countHost; i++)
        {
            if(vectorHotelNumber[i] == numberhost && vectorIdkeyHost[i] != "0")
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
    int countHost = 0;
    int countClient = 0;

    bool ownerClient=false;
    bool checkbusy=true;

    string currentIdClient;
    string clientId;
    string clientName;
    string clientNickname;
    string clientContact;
    string clientEmail;

    string newKeyHosting;

    try
    {
        fileHost.open("YOUR_DIRECTORY_FILE/database/hostdb.txt", ios::in|ios::app);

        if(fileHost.is_open())
        {
            while (!fileHost.eof())
            {
                fileHost >> tmpNumberHost >> tmpNumberFloor >> tmpIdClient >> tmpIdKeyHost >> tmpDataHosting;

                vectorHotelNumber.push_back(tmpNumberHost);
                vectorFloorHosting.push_back(tmpNumberFloor);
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

        fileHost.close();

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
            if(vectorHotelNumber[i] == numberhost)
            {
                if(vectorIdHost[i] == "0")
                {
                    tmpNumberFloor = vectorFloorHosting[i];
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
        
        countHost--;

        if(checkbusy)
        {
            vectorClientId.clear();
            vectorClientNickname.clear();
            vectorIdHost.clear();
            vectorIdkeyHost.clear();
            vectorFloorHosting.clear();
            vectorHotelNumber.clear();
            system("COLOR 03");
            cout << "\n\t\t\tThe hotel with number: " << numberhost <<" are Busy\n" << endl;
            returnValueControllerHotel = true;
        }else
        {
            remove("YOUR_DIRECTORY_FILE/database/hostdb.txt");

            tmpFileHost.open("YOUR_DIRECTORY_FILE/database/hostdb.txt", ios::out|ios::app);

            newKeyHosting = generateUniqueHexaId();

            Hosting *hosting = new Hosting(numberhost, tmpNumberFloor, clientId, newKeyHosting, dataHosting);
            
            if(tmpFileHost.is_open())
            {
                for(int i = 0; i < countHost; i++)
                {
                    if (vectorHotelNumber[i] == hosting->getNumberHosting())
                    {
                        tmpFileHost << hosting->getNumberHosting() << " "  << hosting->getFloorHosting() << " " << hosting->getIdClient() << " " << hosting->getKeyHosting() << " " << hosting->getDataHosting() << endl;
                    }else
                    {
                        tmpFileHost << vectorHotelNumber[i] << " " << vectorFloorHosting[i] << " " << vectorIdHost[i] << " " << vectorIdkeyHost[i] << " " << vectorDataHosting[i] << endl;
                    } 
                }
            }else
            {
                system("COLOR 06");
                cout << "\n\t\t\tError the file don't was found...\n\t\t\t";
                returnValueControllerHotel = false;
            }
            tmpFileHost.close();
        }

        vectorClientId.clear();
        vectorClientNickname.clear();
        vectorIdHost.clear();
        vectorIdkeyHost.clear();
        vectorFloorHosting.clear();
        vectorHotelNumber.clear();

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
    int getHostNumber = 0;
    int getHostFlooor = 0;
    int count = 0;
    string idClientekey;
    string idKeyAcess;
    string dataHosting;

    try
    {
        fileHost.open("YOUR_DIRECTORY_FILE/database/hostdb.txt", ios::in|ios::app);

        if(fileHost.is_open())
        {
            while(!fileHost.eof())
            {
                fileHost >> getHostNumber >> getHostFlooor >> idClientekey >> idKeyAcess >> dataHosting;
                vectorHotelNumber.push_back(getHostNumber);
                vectorFloorHosting.push_back(getHostFlooor);
                vectorIdClient.push_back(idClientekey);
                vectorIdkeyHost.push_back(idKeyAcess);
                vectorDataHosting.push_back(dataHosting);
                count++;
            }
            count--;
            for(int i = 0; i < count; i++)
            {
                cout << "\n\t\t\tHost Number: " << vectorHotelNumber[i] << endl;
                cout << "\t\t\tHost Floor: " << vectorFloorHosting[i] << endl;
                if(vectorIdClient[i] == "0" || vectorIdClient[i] == " ")
                {
                    cout << "\t\t\tStatus: Free\n" << endl;
                }else
                {
                    cout << "\t\t\tStatus: Busy\n" << endl;
                }
                
            }

            vectorHotelNumber.clear();
            vectorFloorHosting.clear();
            vectorIdClient.clear();
            vectorIdkeyHost.clear();
            vectorDataHosting.clear();

            returnValueControllerHotel = true;
        }else
        {
            system("COLOR 06");
            cout << "\n\t\t\tError the file don't was found...\n\t\t\t";
            returnValueControllerHotel = false;
        };

        fileHost.close();
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
        fileHost.open("YOUR_DIRECTORY_FILE/database/hostdb.txt", ios::out|ios::app);   

        if(fileHost.is_open())
        {
            fileHost << createHost.getNumberHosting() << " " << createHost.getFloorHosting() << " " << createHost.getIdClient() << " " << createHost.getKeyHosting() << " " << createHost.getDataHosting() << endl;

            cout << "\n\t\t\tNew hosting with number: " << createHost.getNumberHosting() << " was created with success\n" << endl;

            returnValueControllerHotel = true;
        }else
        {
            system("COLOR 06");
            cout << "\n\t\t\tError the file don't was found...\n\t\t\t";
            returnValueControllerHotel = false;
        };

        fileHost.close();
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