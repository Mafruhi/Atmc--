#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

class Bank {
private:
    string name;
    long long accnumber;
    char type[10];
    double amount = 0;
    double tot = 0;
    int pin;

public:
    void setvalue() {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Account number: ";
        cin >> accnumber;

        cout << "Enter Account type: ";
        cin >> type;

        cout << "Set PIN: ";
        cin >> pin;

        cout << "Enter Initial Balance: ";
        cin >> tot;
    }

    void showdata() {
        cout << "Name: " << name << endl;
        cout << "Account No: " << accnumber << endl;
        cout << "Account type: " << type << endl;
        cout << "Balance: " << fixed << setprecision(2) << tot << endl;
    }

    void deposit() {
        cout << "\nEnter amount to be Deposited: ";
        cin >> amount;

        // Validate amount
        if (amount > 0) {
            tot += amount;
            recordTransaction("Deposit", amount);
            cout << "Deposit successful.\n";
        } else {
            cout << "Invalid amount.\n";
        }
    }

    void showbal() {
        cout << "\nTotal balance is: " << fixed << setprecision(2) << tot << endl;
    }

    void withdrawl() {
        int enteredPin;
        cout << "Enter your PIN: ";
        cin >> enteredPin;

        if (enteredPin == pin) {
            double withdrawalAmount;
            cout << "Enter amount to withdraw: ";
            cin >> withdrawalAmount;

            // Validate amount and balance
            if (withdrawalAmount > 0 && withdrawalAmount <= tot) {
                tot -= withdrawalAmount;
                recordTransaction("Withdrawal", withdrawalAmount);
                cout << "Withdrawal successful.\n";
            } else {
                cout << "Invalid amount or insufficient balance.\n";
            }
        } else {
            cout << "Incorrect PIN. Withdrawal cancelled.\n";
        }
    }

    void recordTransaction(const string& type, double amount) {
        time_t now = time(0);
        char* dt = ctime(&now);
        cout << type << " of $" << fixed << setprecision(2) << amount << " on " << dt;
    }
};

int main() {
    Bank b;
    int choice;

    while (1) {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~WELCOME~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~\n\n";
        cout << "Enter Your Choice\n";
        cout << "\t1. Enter name, Account number, Account type\n";
        cout << "\t2. Balance Enquiry\n";
        cout << "\t3. Deposit Money\n";
        cout << "\t4. Show Total balance\n";
        cout << "\t5. Withdraw Money\n";
        cout << "\t6. Cancel\n";
        cin >> choice;

        switch (choice) {
            case 1:
                b.setvalue();
                break;
            case 2:
                b.showdata();
                break;
            case 3:
                b.deposit();
                break;
            case 4:
                b.showbal();
                break;
            case 5:
                b.withdrawl();
                break;
            case 6:
                exit(1);
                break;
            default:
                cout << "\nInvalid choice\n";
        }
    }
}
