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