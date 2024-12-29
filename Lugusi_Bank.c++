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