# Bank Management System with User Authentication

## Overview
This C++ banking system allows users to register, log in, and perform transactions such as deposits, withdrawals, and balance inquiries. User data is securely stored in a file for persistent access.

## Features
- User Registration
- User Login
- Deposit Money
- Withdraw Money
- Check Balance
- Secure File Storage

## Installation
1. Compile the program using g++:
   ```bash
   g++ bank_management.cpp -o bank_management
   ```
2. Run the executable:
   ```bash
   ./bank_management
   ```

## Multi-User Banking System

### Overview
The Multi-User Banking System expands on the single-user system by allowing multiple users to have separate accounts with unique credentials. This enables concurrent access and personalized transactions for each user.

### Features
- User Registration and Authentication
- Multi-User Account Management
- Deposit, Withdraw, and Balance Inquiry
- Transaction History
- Secure Data Storage

### Installation
1. Compile the program:
   ```bash
   g++ multi_user_bank.cpp -o multi_user_bank
   ```
2. Run the executable:
   ```bash
   ./multi_user_bank
   ```

### Usage
1. Register a new user or log in with an existing account.
2. Perform transactions like deposits, withdrawals, or balance inquiries.
3. View transaction history.
4. Log out to allow another user to access their account.

## File Storage
User information and transactions are stored in `bank_data.txt` to ensure persistent records across sessions.

## Contributions
Feel free to contribute by improving security, adding new features, or optimizing performance!
