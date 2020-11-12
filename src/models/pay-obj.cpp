#include <iostream>

using namespace std;

class Payment
{
private:
    double price;
    string methodPayment;
public:
    Payment(double valuePrice, string methodPay);
    //Get Method
    double getPrice();
    string getMethodPayment();
};

Payment::Payment(double valuePrice, string methodPay)
{
    this->price = valuePrice;
    this->methodPayment = methodPay;
};

double Payment::getPrice()
{
    return this->price;
};

string Payment::getMethodPayment()
{
    return this->methodPayment;
};