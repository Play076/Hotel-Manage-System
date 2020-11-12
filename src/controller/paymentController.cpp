#include <exception>
#include <fstream>
#include "../models/pay-obj.cpp"

using namespace std;

bool returnValuePayment;

class PaymentController
{
public:
    int PaymentHotelMethod(Payment *payment, string clientNickanemPay);
};

int PaymentController::PaymentHotelMethod(Payment *payment, string clientNickanemPay)
{
    fstream fileClient;

    int countClient;
    bool paymentClient = false;

    string clientId;
    string clientName;
    string clientNickname;
    string clientContact;
    string clientEmail;

    fileClient.open("YOUR_DIRECTORY_FILE/clientdb.txt", ios::in | ios::app);

    if (fileClient.is_open())
    {
        try
        {
            while (!fileClient.eof())
            {
                fileClient >> clientId >> clientName >> clientNickname >> clientContact >> clientEmail;

                vectorIdClient.push_back(clientId);
                vectorClientName.push_back(clientName);
                vectorClientNickname.push_back(clientNickname);
                vectorClientPhoneContact.push_back(clientContact);
                vectorClientEmail.push_back(clientEmail);
                countClient++;
            }
        }
        catch (exception &ex)
        {
            system("COLOR 04");
            cout << "\n\t\tError to read data client" << endl;
            returnValuePayment = false;
        }
    }else
    {
        system("COLOR 06");
        cout << "\n\t\t\tSome error with tried open file\n\t\t\t" << endl;

        returnValuePayment = false;
    }

    fileClient.close();

    for (int i = 0; i < countClient; i++)
    {
        if (vectorClientNickname[i] == clientNickanemPay)
        {
            cout << "\t\t\t==========================================" << endl;
            cout << "\n\t\t\tClient" << endl;
            cout << "\t\t\tName: " << vectorClientName[i] << endl;
            cout << "\t\t\tNickName: " << vectorClientNickname[i] << endl;
            cout << "\t\t\tContact: " << vectorClientPhoneContact[i] << endl;
            cout << "\t\t\tEmail: " << vectorClientEmail[i] << endl;
            cout << "\t\t\t==========================================" << endl;
            cout << "\t\t\tPrice Total: $" << payment->getPrice() << endl;
            cout << "\t\t\tPayment Method: " << payment->getMethodPayment() << endl;
            cout << "\t\t\t==========================================" << endl;
            cout << "\t\t\tThank you so much, back ever!\n\t\t\t" << endl;
            paymentClient = true;
            break;
        }
    }

    if (paymentClient)
    {
        returnValuePayment = true;
    }
    else
    {
        system("COLOR 06");
        cout << "\n\t\t\tHave some error with payment method\n\t\t\t" << endl;

        returnValuePayment = false;
    }

    return returnValuePayment;
};