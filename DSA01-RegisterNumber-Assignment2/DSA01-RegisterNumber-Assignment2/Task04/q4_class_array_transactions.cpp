#include <iostream>
#include <string>

// Q4: Specifying a Class with an Array Inside It (Savings Account Mini-Statement)

class SavingsAccount {
private:
    std::string accountNumber;
    double balance;
    double transactions[10]; // Fixed array of last 10 transactions
    int count;

public:
    SavingsAccount(std::string accNo, double initialBalance) 
        : accountNumber(accNo), balance(initialBalance), count(0) {
        for(int i = 0; i < 10; ++i) transactions[i] = 0.0;
    }

    void deposit(double amount);
    void withdraw(double amount);
    void miniStatement() const;
};

// Defining member functions outside using scope resolution operator (::)
void SavingsAccount::deposit(double amount) {
    if (amount <= 0) return;
    balance += amount;
    
    // Handling 11th transaction using circular index or shifting
    if (count < 10) {
        transactions[count++] = amount;
    } else {
        // Shift array elements left (discard oldest at index 0)
        for (int i = 0; i < 9; ++i) {
            transactions[i] = transactions[i + 1];
        }
        transactions[9] = amount;
    }
}

void SavingsAccount::withdraw(double amount) {
    if (amount <= 0 || amount > balance) return;
    balance -= amount;
    double signedAmount = -amount;
    
    if (count < 10) {
        transactions[count++] = signedAmount;
    } else {
        for (int i = 0; i < 9; ++i) {
            transactions[i] = transactions[i + 1];
        }
        transactions[9] = signedAmount;
    }
}

void SavingsAccount::miniStatement() const {
    std::cout << "--- Mini-Statement for Account: " << accountNumber << " ---\n";
    std::cout << "Current Balance: Rs " << balance << "\nRecent Transactions:\n";
    int start = (count < 10) ? 0 : 0;
    int limit = (count < 10) ? count : 10;
    for (int i = 0; i < limit; ++i) {
        std::cout << "  [" << (i + 1) << "] Rs " << transactions[i] << '\n';
    }
}

int main() {
    std::cout << "=== Q4: SAVINGS ACCOUNT MINI-STATEMENT ===\n";
    SavingsAccount acc("SA-5001", 5000.0);
    acc.deposit(1000.0);
    acc.withdraw(500.0);
    acc.deposit(250.0);
    acc.miniStatement();
    return 0;
}
