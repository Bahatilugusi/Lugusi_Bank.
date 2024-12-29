#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Account
{
    int id;
    string name;
    string password;
    double amount;

    void display()
    {
        cout << "\nID: " << id << "\nName: " << name << "\nBalance: $" << amount << endl;
    }
};

void createAccount();
void loginAccount();
void checkAccounts();
void saveAccounts(vector<Account> &accounts);
vector<Account> loadAccounts();
void simBanking();
void displayM();
void service();

const string filename = "banker.txt";

int main()
{
    system("cls");
    displayM();

    return 0;
}

// ACCOUNT DEFINITIONS

void displayM()
{
    system("cls");
    int choice;
    do
    {
        cout << "\n\t\tWELCOME TO BANK ACCOUNT MANAGEMENT SYSTEM";
        cout << "\n\t\t__________________________________________";
        cout << "\n1. Create an Account.";
        cout << "\n2. Login to Account.";
        cout << "\n3. Check Accouts";
        cout << "\n4. Exit.";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createAccount();
            break;
        case 2:
            loginAccount();
            break;
        case 3:
            checkAccounts();
            break;
        case 4:
            cout << "\nExiting..!";
        default:
            cout << "invalid Choice, Please try again!";
            break;
        }

           } while (choice != 4);
}

void createAccount()
{
    vector<Account> accounts = loadAccounts();
    Account a;

    cout << "\nEnter your ID: ";
    cin >> a.id;
    cin.ignore();
    cout << "\nEnter your Name: ";
    getline(cin, a.name);
    cin.ignore();
    cout << "\nEnter Your Password";
    getline(cin, a.password);

      service();

    accounts.push_back(a);
    saveAccounts(accounts);
}

void loginAccount()
{
    vector<Account> accounts = loadAccounts();

    int id;
    string password;
    bool found = false;

    cout << "\nEnter Account DI to Login: ";
    cin >> id;


