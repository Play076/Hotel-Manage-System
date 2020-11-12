#include <fstream>
#include <exception>

bool authorization = false;
static bool authorizationSession = false;

class Authentication
{
public:
    int LoginAuth(string adminUser, string adminPswd);
    int Auth();
};

int Authentication::LoginAuth(string adminUser, string adminPswd)
{
    fstream fileAuth;

    string tmpUser;
    string tmpPswd;

    fileAuth.open("YOUR_DIRECTORY_FILE/authentication.txt", ios::in | ios::app);

    if (fileAuth.is_open())
    {
        try
        {
            while (!fileAuth.eof())
            {
                fileAuth >> tmpUser >> tmpPswd;

                vectorUserAdmin.push_back(tmpUser);
                vectorPswdAdmin.push_back(tmpPswd);
            }
        }
        catch (exception &ex)
        {
            system("COLOR 04");
            cout << "\n\t\tError to read data administration" << endl;
            authorization = false;
        }
    }
    else
    {
        system("COLOR 06");
        cout << "\n\t\t\tSome error with tried open file\n\t\t\t" << endl;

        authorization = false;
    }

    fileAuth.close();

    if (vectorUserAdmin[0] == adminUser && vectorPswdAdmin[0] == adminPswd)
    {
        authorization = true;
        authorizationSession = true;
    }

    if (authorization)
    {
        system("COLOR 02");
        cout << "\n\t\t\tAuthentication authorize with success" << endl;
    }else
    {
        system("COLOR 06");
        cout << "\n\t\t\tHave some error a authentication, please try again" << endl;
        exit(0);
    }

    return authorization;
};

int Authentication::Auth()
{
    if (authorizationSession)
    {
        return true;
    }
    else
    {
        return false;
    }
};