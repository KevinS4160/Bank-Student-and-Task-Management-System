#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

class BankAccount {
public:
    string username;
    string password;
    double balance;
    
    BankAccount(string u, string p, double b = 0.0) {
        username = u;
        password = p;
        balance = b;
    }
};

class Bank {
private:
    unordered_map<string, BankAccount> accounts;
    string filename = "accounts.txt";

    void loadAccounts() {
        ifstream file(filename);
        if (!file) return;

        string username, password;
        double balance;
        while (file >> username >> password >> balance) {
            accounts[username] = BankAccount(username, password, balance);
        }
        file.close();
    }

    void saveAccounts() {
        ofstream file(filename);
        for (auto &acc : accounts) {
            file << acc.second.username << " " << acc.second.password << " " << acc.second.balance << endl;
        }
        file.close();
    }

public:
    Bank() { loadAccounts(); }

    bool registerUser(string username, string password) {
        if (accounts.find(username) != accounts.end()) {
            cout << "Username already exists!" << endl;
            return false;
        }
        accounts[username] = BankAccount(username, password);
        saveAccounts();
        cout << "Account registered successfully!" << endl;
        return true;
    }

    bool loginUser(string username, string password) {
        if (accounts.find(username) == accounts.end() || accounts[username].password != password) {
            cout << "Invalid username or password!" << endl;
            return false;
        }
        cout << "Login successful!" << endl;
        return true;
    }

    void deposit(string username, double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount!" << endl;
            return;
        }
        accounts[username].balance += amount;
        saveAccounts();
        cout << "Deposited successfully! New Balance: " << accounts[username].balance << endl;
    }

    void withdraw(string username, double amount) {
        if (amount <= 0 || accounts[username].balance < amount) {
            cout << "Invalid withdrawal amount or insufficient balance!" << endl;
            return;
        }
        accounts[username].balance -= amount;
        saveAccounts();
        cout << "Withdrawal successful! New Balance: " << accounts[username].balance << endl;
    }

    void checkBalance(string username) {
        cout << "Current Balance: " << accounts[username].balance << endl;
    }
};

int main() {
    Bank bank;
    int choice;
    string username, password;
    double amount;
    
    while (true) {
        cout << "\n1. Register\n2. Login\n3. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter Username: ";
                cin >> username;
                cout << "Enter Password: ";
                cin >> password;
                bank.registerUser(username, password);
                break;
            case 2:
                cout << "Enter Username: ";
                cin >> username;
                cout << "Enter Password: ";
                cin >> password;
                if (bank.loginUser(username, password)) {
                    int userChoice;
                    do {
                        cout << "\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Logout\nEnter choice: ";
                        cin >> userChoice;
                        switch (userChoice) {
                            case 1:
                                cout << "Enter deposit amount: ";
                                cin >> amount;
                                bank.deposit(username, amount);
                                break;
                            case 2:
                                cout << "Enter withdrawal amount: ";
                                cin >> amount;
                                bank.withdraw(username, amount);
                                break;
                            case 3:
                                bank.checkBalance(username);
                                break;
                            case 4:
                                cout << "Logging out...\n";
                                break;
                            default:
                                cout << "Invalid choice!\n";
                        }
                    } while (userChoice != 4);
                }
                break;
            case 3:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}