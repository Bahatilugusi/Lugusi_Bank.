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