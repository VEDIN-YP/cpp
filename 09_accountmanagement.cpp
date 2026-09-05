#include <iostream>
using namespace std;

class BankAccount
{
private:
    string name;
    double balance;

public:

    BankAccount(string accountName, double startingBalance)
    {
        name = accountName;
        balance = startingBalance;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Money deposited successfully.\n";
        }
        else
        {
            cout << "Invalid amount.\n";
        }
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid amount.\n";
        }
        else if (amount > balance)
        {
            cout << "Not enough money.\n";
        }
        else
        {
            balance -= amount;
            cout << "Money withdrawn successfully.\n";
        }
    }

    void showAccount()
    {
        cout << "\nAccount Holder: " << name << endl;
        cout << "Balance: $" << balance << endl;
    }
};

int main()
{
    BankAccount account("Vedin", 1000);

    int choice;
    double amount;

    do
    {
        cout << "\n===== BANK MENU =====\n";
        cout << "1. Show Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                account.showAccount();
                break;

            case 2:
                cout << "Enter amount: ";
                cin >> amount;
                account.deposit(amount);
                break;

            case 3:
                cout << "Enter amount: ";
                cin >> amount;
                account.withdraw(amount);
                break;

            case 4:
                cout << "Goodbye.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}