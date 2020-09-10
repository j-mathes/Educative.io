// Part 1
void withdraw(double* balance, double amount) 
{
    if(amount <= *balance)
        *balance = *balance - amount;
    else
        cout << "You are broke. You don’t have enough money. Go away" << endl;
}

void deposit(double* balance, double amount) 
{
    *balance = *balance + amount;
}

// Part 2
void(*pDeposit)(double*, double);
void(*pWithdraw)(double*, double);

int main() 
{
    double* balance;
    double harry_account_balance = 0;
    balance = &harry_account_balance;

    cout << "Harry's Balance at start is: " << *balance;
    cout <<endl;
    double amount  = 1000.00;
    pDeposit = &deposit;
    pDeposit(balance, amount);

    cout << "Balance in harry account is: " << *balance;
    cout<<endl;
    amount = 500;
    pWithdraw = &withdraw;
    pWithdraw(balance, amount);

    cout << "Balance after withdrawing cash is: " << *balance;
    cout<<endl;
    amount = 3000;
    
    cout << "Withdrawing "<< amount << " now" <<endl; 
    pWithdraw(balance, amount);
}
