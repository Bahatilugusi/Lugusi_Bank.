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
    vector<Account> accounts;
    displayM(accounts);
}

// FUNCTION DEFINITION
void displayM(vector<Account> &accounts)
{
    int choice;
    do
    {
        cout << "\n\t\t\tBANK SYSTEM MANAGEMENT.";
        cout << "\n\t\t\t************************";
        cout << "\n1. Create New Account.";
        cout << "\n2. Login Account.";
        cout << "\n3. Read Account.";
        cout << "\n4. Exit.";
        cout << "\n\t Select your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createAccount(accounts);
            break;
            break;
        case 2:
            loginAccount(accounts);
            break;
        case 3:
            readAccounts(accounts);
            break;
        case 4:
            cout << "\nExiting.!";
            break;
        default:
            cout << "\nInvalid Choice. Try again!";
            break;
        }

    } while (choice != 4);
}


void createAccount(vector<Account> &accounts)
{
    Account a;

    cout << "\nEnter Account No: ";
    cin >> a.an;
    cin.ignore();
    cout << "\nEnter User name: ";
    getline(cin, a.name);

  cout << "\nEnter Account Password: ";
    cin.ignore();
    getline(cin, a.password);
    service(accounts);
    accounts.push_back(a);
    cout << "\nCreating Account Successfully!";
    return;
}

   

void loginAccount(vector<Account> &accounts)
{
    Account a;
    int an;
    string password;

     cout << "\nEnter Account Number to login Account: ";
    cin >> an;

    for (auto &a : accounts)
    {
        if (a.an == an)
        {
            cin.ignore();
            cout << "\nEnter Your Password: ";
            getline(cin, password);
            if (a.password == password)
            {
                service(accounts);
                accounts.push_back(a);
            }
        }
    }
               cout << "\nAccount with Account No: " << an << " is not found!";

}  

void readAccounts(const vector<Account> &accounts)
{
    if (accounts.empty())
    {
        cout << "\nNo Account Found!";
    }
    else
    {
        for (const auto &a : accounts)
        {
            cout << "\n\t\t  ACCOUNT LIST";
            cout << "\n\t\t*****************";
            a.display();
        }
    }
}

void service(vector<Account> &accounts)
{
      Account a;
    double amount;
    int choice;

    m:
    cout << "\n1. Deposite Money.";
    cout << "\n2. Withdraw Money.";
    cout << "\n3. Balance.";
    cout << "\n4. Sim Banking.";
    cout << "\n5. Back(MENU).";
    cout << "\nSelect Your choice: ";
    cin >> choice;

     switch (choice)
    {
         case 1:
        cout << "\nEnter amount of Money to Depose: ";
        cin >> amount;
        a.balance += amount;
        cout << "\n\t Your new Balance is $" << a.balance;
        break;

        case 2:
        cout << "\nEnter amount of Money to Withdraw: ";
        cin >> amount;
        if (a.balance >= amount)
        {
            a.balance -= amount;
            cout << "\n\tYour new balance is $" << a.balance;
        }
        else
        {
            cout << "\nYou do not have enough Balance!";
        }
        break;

         case 3:
        cout << "\n\t\tYour initial balance is $" << a.balance;
        break;

         case 4:
        simBanking(accounts);
        break;

        case 5:
        displayM(accounts);
        break;

            default:
        cout << "\nInvalid choice, Try again!";
        break;
    }

    goto m;
}




void simBanking(vector<Account> &accounts)
{
   

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
