// Check balance
// Deposit money
// Withdraw money
// Exit

#include <iostream>
using namespace std;

int main()
{
    double balance = 1000.0;
    int choice;
    double amount;

    cout << "Welcome to the Simple Banking System!\n";
    cout << "-------------------------------------\n";

    while (true)
    {
        // Display menu options
        cout << "\nPlease select an option:\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Check balance
            cout << "\nYour current balance is: $" << balance << "\n";
            break;

        case 2:
            // Deposit money
            cout << "\nEnter the amount to deposit: $";
            cin >> amount;
            if (amount > 0)
            {
                balance += amount;
                cout << "\n$" << amount << " deposited successfully.\n";
                cout << "Your new balance is: $" << balance << "\n";
            }
            else
            {
                cout << "\nInvalid deposit amount. Please enter a positive amount.\n";
            }
            break;

        case 3:
            // Withdraw money
            cout << "\nEnter the amount to withdraw: $";
            cin >> amount;
            if (amount > 0 && amount <= balance)
            {
                balance -= amount;
                cout << "\n$" << amount << " withdrawn successfully.\n";
                cout << "Your new balance is: $" << balance << "\n";
            }
            else if (amount > balance)
            {
                cout << "\nInsufficient funds! Your balance is: $" << balance << "\n";
            }
            else
            {
                cout << "\nInvalid withdrawal amount. Please enter a positive amount.\n";
            }
            break;

        case 4:
            // Exit
            cout << "\nThank you for using the Simple Banking System. Goodbye!\n";
            return 0;

        default:
            cout << "\nInvalid choice. Please select a valid option.\n";
            break;
        }
    }

    return 0;
}
