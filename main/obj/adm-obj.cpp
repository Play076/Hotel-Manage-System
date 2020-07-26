#include <iostream>
#include <string>

using namespace std;

class Adm
{
private:
    string adminuser;
    string adminpswd;
public:
    Adm(string useradmin, string pswdadmin);
    //Get Method
    string getAdminUser();
    string getAdminPswd();
};

Adm::Adm(string useradmin, string pswdadmin)
{
    this->adminuser = useradmin;
    this->adminpswd = pswdadmin;
};

string Adm::getAdminUser()
{
    return this->adminuser;
};

string Adm::getAdminPswd()
{
    return this->adminpswd;
};