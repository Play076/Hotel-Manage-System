#include <iostream>
#include <exception>
#include <fstream>
#include <vector>
#include "../../obj/pay-obj.cpp"

using namespace std;

bool returnValuePayment;

class PaymentController
{
public:
    int PaymentHotelMethod(Payment *payment, string clientNickanemPay);
};

int PaymentController::PaymentHotelMethod(Payment *payment, string clientNickanemPay)
{
    try
    {
        fstream fileClient;

        int countClient;
        bool paymentClient=false;

        string clientId;
        string clientName;
        string clientNickname;
        string clientContact;
        string clientEmail;

        vector<string> vectorIdClient;
        vector<string> vectorClientName;
        vector<string> vectorClientNickname;
        vector<string> vectorContact;
        vector<string> vectorEmail;
        

        fileClient.open("YOUR_DIRECTORY_FILE/database/clientdb.txt", ios::in|ios::app);

        if(fileClient.is_open())
        {
            while(!fileClient.eof())
            {
                fileClient >> clientId >> clientName >> clientNickname >> clientContact >> clientEmail;

                vectorIdClient.push_back(clientId);
                vectorClientName.push_back(clientName);
                vectorClientNickname.push_back(clientNickname);
                vectorContact.push_back(clientContact);
                vectorEmail.push_back(clientEmail);
                countClient++;
            }
        }else
        {
            system("COLOR 06");
            cout << "\n\t\t\tSome error with tried open file\n\t\t\t" << endl;
            
            returnValuePayment = false;
        }

        fileClient.close();

        for(int i = 0; i < countClient; i++)
        {
            if(vectorClientNickname[i] == clientNickanemPay)
            {
                cout << "\t\t\t==========================================" << endl;
                cout << "\n\t\t\tClient" << endl;
                cout << "\t\t\tName: " << vectorClientName[i] << endl;
                cout << "\t\t\tNickName: " << vectorClientNickname[i] << endl;
                cout << "\t\t\tContact: " << vectorContact[i] << endl;
                cout << "\t\t\tEmail: " << vectorContact[i] << endl;
                cout << "\t\t\t==========================================" << endl;
                cout << "\t\t\tPrice Total: $" << payment->getPrice() << endl;
                cout << "\t\t\tPayment Method: " << payment->getMethodPayment() << endl;
                cout << "\t\t\t==========================================" << endl;
                cout << "\t\t\tThank you so much, back ever!\n\t\t\t" << endl;
                paymentClient = true;
                break;
            }
        }

        if(paymentClient)
        {
            returnValuePayment = true;
        }else
        {
            system("COLOR 06");
            cout << "\n\t\t\tHave some error with payment method\n\t\t\t" << endl;
            
            returnValuePayment = false;
        }
    }
    catch(const std::exception& ex)
    {
        system("COLOR 04");
        cout << "\n\t\t\tSome error in system\n\t\t\t" << endl;
        cerr << ex.what() << endl;

        returnValuePayment = false;
    }
    return returnValuePayment;
};