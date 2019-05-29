#include <iostream>
#include "brass.h"

int main127() {
    using std::cout;
    using std::endl;

    Brass piggy("Porcelot Pigg", 381299, 4000.00);
    BrassPlus hoggy("Horatio Hogg", 382299, 3000.00);

    piggy.viewAcct();
    cout << endl;

    hoggy.viewAcct();
    cout << endl;

    cout << "Depositing $1000 into the hogg Account:\n";
    hoggy.deposit(1000.00);
    cout << "New balance: $" << hoggy.getBalance() << endl;

    cout << "Withdrawing $4200 from the pigg account: \n";
    piggy.withdraw(4200.00);
    cout << "Pigg account balance: $" << piggy.getBalance() << endl;

    cout << "Withdrawing $4200 from the hogg account: \n";
    hoggy.withdraw(4200.00);
    hoggy.viewAcct();

}