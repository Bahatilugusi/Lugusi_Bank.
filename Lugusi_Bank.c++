#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Account
{
    int an;
    string name;
    string password;
    double balance;

    void display() const
    {
        cout << "\nAccount No: " << an << "\nUser Name: " << name << "\nAccount Balance: $" << balance << endl;
    }
};

void displayM(vector<Account> &accounts);
void createAccount(vector<Account> &accounts);
void loginAccount(vector<Account> &accounts);
void readAccounts(const vector<Account> &accounts);
void service(vector<Account> &accounts);
void simBanking(vector<Account> &accounts);



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

    for (auto &a : accounts)
    {
        if (a.id == id)
        {
            found = true;
            cin.ignore();
            cout << "Enter your password: ";
            getline(cin, password);

            if (a.password == password)
            {

                service();
                saveAccounts(accounts);
            }
            else
            {
                cout << "Invalid Password, Try again.";
            }
        }
    }

    if (!found)
    {
        cout << "An Account with ID: " << id << " not found!";
    }
}

void checkAccounts()
{
    vector<Account> accounts = loadAccounts();
    if (accounts.empty())
    {
        cout << "\nNo Account Found";
    }
    else
    {
        cout << "\n\t\t-------ACCOUNT LIST-------\n";
        for (auto &a : accounts)
        {
            a.display();
        }
    }
}

void saveAccounts(const vector<Account> &accounts)
{
    ofstream file(filename, ios::trunc);

    if (file.is_open())
    {
        for (const auto &a : accounts)
        {
            file << a.id << "\n"
                 << a.name << "\n"
                 << a.password << "\n"
                 << a.amount << "\n";
        }
        file.close();
    }
}

vector<Account> loadAccounts()
{
    vector<Account> accounts;
    ifstream file(filename);

    if (file.is_open())
    {
        Account a;
        for (auto &a : accounts)
        {
            while (file >> a.id)
            {
                file.ignore();
                getline(file, a.name);
                file.ignore();
                getline(file, a.password);
                file >> a.amount;

                accounts.push_back(a);
                saveAccounts(accounts);
            }
        }
        file.close();
    }
    return accounts;
}

void simBanking()
{
    vector<Account> accounts = loadAccounts();
    Account a;
    system("cls");
    int choice;

// double amount;
m:
    cout << "\n\n\t-------SIMBANKING--------\n";
    cout << "\n1. EirtelMoney";
    cout << "\n2. HaloPesa";
    cout << "\n3. TigoPesa";
    cout << "\n4. AzamPesa";
    cout << "\n5. Back to Main Menu";
    cout << "\n\tPlease select your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Enter Amout of Money You want to transfer: ";
        cin >> a.amount;
        cout << "\nTransaction of $" << a.amount << " to EirtelMoney is succefully.\n\n";
        break;

    case 2:
        cout << "Enter Amout of Money You want to transfer: ";
        cin >> a.amount;
        cout << "\nTransaction of $" << a.amount << " to HaloPesa is succefully.\n\n";
        break;

    case 3:
        cout << "Enter Amout of Money You want to transfer: ";
        cin >> a.amount;
        cout << "\nTransaction of $" << a.amount << " to GigoPesa is succefully.\n\n";
        break;

    case 4:
        cout << "Enter Amout of Money You want to transfer: ";
        cin >> a.amount;
        cout << "\nTransaction of $" << a.amount << " to AzamPesa is succefully.\n\n";
        break;

    case 5:
        displayM();
        break;

    default:
        cout << "\n\tInvalid choice!, please select from the Menu\n\n";
        break;
    }
    goto m;
}

void service()
{
    vector<Account> accounts = loadAccounts();
    Account a;
    double amount;
    int choice;

    do
    {
        cout << "\n1. Deposite Money";
        cout << "\n2. Withdraw Money";
        cout << "\n3. Account Balance";
        cout << "\n4. Sim Banking.";
        cout << "\n5. Back to Main Menu";
        cout << "\n6. Exit.!";
        cout << "\nSelect Your choice";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter amount of Money to Depose: ";
            cin >> amount;
            a.amount += amount;
            cout << "\n\t Your new Balance is $" << a.amount;
            break;

        case 2:
            cout << "\nEnter amount of Money to Withdraw: ";
            cin >> amount;

            if (a.amount >= amount)
            {
                a.amount -= amount;
                cout << "\n\tYour new balance is $" << a.amount;
            }
            else
            {
                cout << "\nYou do not have enough Balance!";
            }
            break;

        case 3:
            cout << "\n\t\tYour initial balance is $" << a.amount;
            break;

        case 4:
            simBanking();
            break;

        case 5:
            displayM();
            break;

            saveAccounts(accounts);
        }

    } while (choice != 6);
}
