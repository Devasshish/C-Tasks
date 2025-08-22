#include <iostream>
using namespace std;

// ---------------- Base Class ----------------
class BankAccount{
public:
    int accountNumber;
    string accountHolderName;
    double balance;
    // Constructor
    BankAccount(int accNo, string name, double bal){
        accountNumber=accNo;
        accountHolderName=name;
        balance=bal;
    }

    // Display account details
    void displayAccountInfo(){
        cout<<"\n----------------------------\n";
        cout<<"Account Number : "<<accountNumber<<endl;
        cout<<"Holder Name    : "<<accountHolderName<<endl;
        cout<<"Balance        : "<<balance<<endl;
        cout<<"----------------------------\n";
    }

    // Deposit function
    void deposit(double amount){
        if(amount>0){
            balance+=amount;
            cout<<"Amount Deposited Successfully! New Balance: "<<balance<<endl;
        }
		else{
            cout<<"Invalid Deposit Amount!"<<endl;
        }
    }

    // Withdraw function
    void withdraw(double amount){
        if(amount>0 && amount<=balance){
            balance-=amount;
            cout<<"Withdrawal Successful. Remaining Balance: "<<balance<<endl;
        }
		else{
            cout<<"Insufficient Balance!"<<endl;
        }
    }

    // Base interest function
    void calculateInterest(){
        cout<<"This account type has no specific interest calculation.\n";
    }
};

// ------- Derived Class : Savings ----------
class SavingsAccount:public BankAccount{
public:
    double interestRate;

    SavingsAccount(int accNo, string name, double bal, double rate)
        :BankAccount(accNo,name,bal){
        interestRate=rate;
    }

    void calculateInterest(){
        double interest=balance*(interestRate/100);
        cout<<"Savings Interest for this year: "<<interest<<endl;
    }

    void displayAccountInfo(){
        BankAccount::displayAccountInfo();
        cout<<"Account Type   : Savings"<<endl;
        cout<<"Interest Rate  : "<<interestRate<<"%"<<endl;
        cout<<"----------------------------\n";
    }
};

// ------- Derived Class : Checking ----
class CheckingAccount:public BankAccount{
public:
    double overdraftLimit;

    CheckingAccount(int accNo,string name,double bal,double limit)
        : BankAccount(accNo, name, bal){
        overdraftLimit=limit;
    }

    void withdraw(double amount){
        if(amount<=balance+overdraftLimit){
            balance-=amount;
            cout<<"Withdrawal Successful (Overdraft Used if Needed). New Balance: "<<balance<<endl;
        }
		else{
            cout<<"Overdraft Limit Exceeded!"<<endl;
        }
    }

    void displayAccountInfo(){
        BankAccount::displayAccountInfo();
        cout<<"Account Type   : Checking"<<endl;
        cout<<"Overdraft Limit: "<< overdraftLimit<<endl;
        cout<<"----------------------------\n";
    }
};

// -------- Derived Class : Fixed Deposit -------
class FixedDepositAccount : public BankAccount {
public:
    int term; // months
    double interestRate;
    FixedDepositAccount(int accNo, string name, double bal, int t, double rate)
        : BankAccount(accNo, name, bal) {
        term = t;
        interestRate = rate;
    }
    void calculateInterest(){
        double interest =balance * (interestRate / 100.0) * (term / 12.0);
        cout << "FD Interest for " << term << " months: " << interest << endl;
        cout << "Maturity Amount will be: " << balance + interest << endl;
    }
    void displayAccountInfo(){
        BankAccount::displayAccountInfo();
        cout << "Account Type   : Fixed Deposit" << endl;
        cout << "Term           : " << term << " months" << endl;
        cout << "Interest Rate  : " << interestRate << "%" << endl;
        cout << "----------------------------\n";
    }
};

// ------- Main Function --------
int main() {
    int choice;

    cout << "=============== SBI Bank Management System =============\n";
    cout << "--------------------------------------------------------\n";
    cout << "1. Create Savings Account\n";
    cout << "2. Create Checking Account\n";
    cout << "3. Create Fixed Deposit Account\n";
    cout << "--------------------------------------------------------\n";
    cout << "Enter choice: ";
    cin >> choice;

    int accNo;
    string name;
    double bal;

    cout << "\nEnter Account Number: ";
    cin >> accNo;
    cout << "Enter Holder Name: ";
    cin >> name;
    cout << "Enter Initial Balance: ";
    cin >> bal;

    // Savings Account
    if (choice == 1) {
        double rate;
        cout << "Enter Interest Rate (%): ";
        cin >> rate;
        SavingsAccount account(accNo, name, bal, rate);

        int option;
        do {
        	// Menu
            cout << "\n=== Savings Account Menu ===\n";
            cout << "1. Display Account Info\n";
            cout << "2. Deposit Money\n";
            cout << "3. Withdraw Money\n";
            cout << "4. Calculate Interest\n";
            cout << "5. Exit\n";
            cout << "Enter Option: ";
            cin >> option;

			//Options 
            switch (option) {
                case 1: account.displayAccountInfo(); break;
                case 2: {
                    double amt;
                    cout << "Enter Deposit Amount: ";
                    cin >> amt;
                    account.deposit(amt);
                    break;
                }
                case 3: {
                    double amt;
                    cout << "Enter Withdrawal Amount: ";
                    cin >> amt;
                    account.withdraw(amt);
                    break;
                }
                case 4: account.calculateInterest(); break;
                case 5: cout << "Exiting Program... Thank you!" << endl; break;
                default: cout << "Invalid Option!" << endl;
            }
        } while (option != 5);
    }
    // check account
    else if (choice == 2) {
        double limit;
        cout << "Enter Overdraft Limit: ";
        cin >> limit;
        CheckingAccount account(accNo, name, bal, limit);

        int option;
        do {
        	// Menu
            cout << "\n=== Checking Account Menu ===\n";
            cout << "1. Display Account Info\n";
            cout << "2. Deposit Money\n";
            cout << "3. Withdraw Money\n";
            cout << "4. Exit\n";
            cout << "Enter Option: ";
            cin >> option;
			//	Options
            switch (option) {
                case 1: account.displayAccountInfo(); break;
                case 2: {
                    double amt;
                    cout << "Enter Deposit Amount: ";
                    cin >> amt;
                    account.deposit(amt);
                    break;
                }
                case 3: {
                    double amt;
                    cout << "Enter Withdrawal Amount: ";
                    cin >> amt;
                    account.withdraw(amt);
                    break;
                }
                case 4: cout << "Exiting Program... Thank you!" << endl; break;
                default: cout << "Invalid Option!" << endl;
            }
        } while (option != 4);
    }
    // Fixed Deposit Account
    else if (choice == 3) {
        int term;
        double rate;
        cout << "Enter Term (in months): ";
        cin >> term;
        cout << "Enter Interest Rate (%): ";
        cin >> rate;
        FixedDepositAccount account(accNo, name, bal, term, rate);

        int option;
        do {
            cout << "\n=== Fixed Deposit Account Menu ===\n";
            cout << "1. Display Account Info\n";
            cout << "2. Calculate Interest & Maturity\n";
            cout << "3. Exit\n";
            cout << "Enter Option: ";
            cin >> option;

            switch (option) {
                case 1: account.displayAccountInfo(); break;
                case 2: account.calculateInterest(); break;
                case 3: cout << "Exiting Program... Thank you!" << endl; break;
                default: cout << "Invalid Option!" << endl;
            }
        } while (option != 3);
    }
    else {
        cout << "Invalid Choice!" << endl;
    }
}

