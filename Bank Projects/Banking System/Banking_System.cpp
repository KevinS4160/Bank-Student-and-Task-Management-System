#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class BankAccount {
public:
    int accountNumber;
    string name;
    double balance;

    BankAccount(int accNum, string n, double bal) {
        accountNumber = accNum;
        name = n;
        balance = bal;
    }

    void displayAccount() {
        cout << "Account No: " << accountNumber << " | Name: " << name << " | Balance: $" << balance << endl;
    }
};

class Bank {
private:
    vector<BankAccount> accounts;
    string filename = "accounts.txt";

    void loadAccounts() {
        ifstream file(filename);
        if (!file) return;

        int accNum;
        string name;
        double balance;
        while (file >> accNum) {
            file.ignore();
            getline(file, name);
            file >> balance;
            accounts.push_back(BankAccount(accNum, name, balance));
        }
        file.close();
    }

    void saveAccounts() {
        ofstream file(filename);
        for (BankAccount acc : accounts) {
            file << acc.accountNumber << endl << acc.name << endl << acc.balance << endl;
        }
        file.close();
    }

public:
    Bank() { loadAccounts(); }

    void createAccount(string name, double initialDeposit) {
        int accNum = accounts.size() + 1;
        accounts.push_back(BankAccount(accNum, name, initialDeposit));
        saveAccounts();
        cout << "Account Created Successfully!\n";
    }

    void showAccounts() {
        if (accounts.empty()) {
            cout << "No accounts available.\n";
            return;
        }
        for (BankAccount acc : accounts) {
            acc.displayAccount();
        }
    }
};

int main() {
    Bank bank;
    int choice;
    string name;
    double deposit;

    while (true) {
        cout << "\n1. Open Account\n2. Show Accounts\n3. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter Initial Deposit: ";
                cin >> deposit;
                bank.createAccount(name, deposit);
                break;
            case 2:
                bank.showAccounts();
                break;
            case 3:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid Choice! Try Again.\n";
        }
    }
}
