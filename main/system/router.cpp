#include <exception>
#include <conio.h>
#include <fstream>
#include "controller/hotelController.cpp"
#include "controller/clientController.cpp"
#include "controller/paymentController.cpp"
#include "controller/AuthController.cpp"

bool returnValueRouter;

HotelController *hotelController = new HotelController();
ClientController *clientController = new ClientController();
PaymentController *paymentController = new PaymentController();
Authentication *authentication = new Authentication();

class Router
{
public:
    int authenticationMethod(string adminName, string adminPswd);
    int createHost(vector<int> arrnumber);
    int checkHost();
    int registerClient(vector<string> arrname);
    int hostingClient(int numberhost, string clientnickname, string datahosintg);
    int hostingClientCheckPay(int numberhost, string clientnickname);
    int PaymentClient(double priceValue, string method, string clientNickanemPay);
    int removeHostingHotel(int numberhost);
};

int Router::authenticationMethod(string adminName, string adminPswd)
{
    returnValueRouter = authentication->LoginAuth(adminName, adminPswd);

    return returnValueRouter;
}

int Router::createHost(vector<int> arrnumber)
{
    if(authentication->Auth())
    {
        Hosting *newhosting = new Hosting(arrnumber[0], arrnumber[1], "0", "0", "00/00/0000");

        returnValueRouter = hotelController->createNewHost(*newhosting);

        return returnValueRouter;
    }else
    {
        return false;
    }
    
}

int Router::checkHost()
{
    if(authentication->Auth())
    {
        system("COLOR 01");
        returnValueRouter = hotelController->indexHost();

        return returnValueRouter;
    }else
    {
        return false;
    }
}

int Router::registerClient(vector<string> arrname)
{
    if(authentication->Auth())
    {
        system("COLOR 01");
        Client *client = new Client(generateUniqueHexaId(), arrname[0], arrname[1], arrname[2], arrname[3]);

        returnValueRouter = clientController->registerClient(*client);

        return returnValueRouter;
    }else
    {
        return false;
    }
    
}

int Router::hostingClient(int hotelNumber, string clientName, string dataHosting)
{
    if(authentication->Auth())
    {
        system("COLOR 01");
        returnValueRouter = hotelController->hostingClinet(hotelNumber, clientName, dataHosting);

        return returnValueRouter;
    }else
    {
        return false;
    }
}

int Router::hostingClientCheckPay(int numberhost, string clientnickname)
{
    if(authentication->Auth())
    {
        system("COLOR 01");
        returnValueRouter = hotelController->finishHostandPay(numberhost, clientnickname);

        return returnValueRouter;
    }else
    {
        return false;
    }
}

int Router::PaymentClient(double priceValue, string method, string clientNickanemPay)
{
    if(authentication->Auth())
    {
        system("COLOR 01");

        Payment *payment = new Payment(priceValue, method);
        returnValueRouter = paymentController->PaymentHotelMethod(payment, clientNickanemPay);

        return returnValueRouter;
    }else
    {
        return false;
    }
    
};

int Router::removeHostingHotel(int numberhost)
{
    if(authentication->Auth())
    {
        system("COLOR 01");

        returnValueRouter = hotelController->removeHosting(numberhost);

        return returnValueRouter;
    }else
    {
        return false;
    }
};