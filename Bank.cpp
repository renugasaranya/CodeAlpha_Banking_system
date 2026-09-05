#include<iostream>
#include<iomanip>
using namespace std;
class Customer
{
public:
int customerId;
string name;
void createCustomer()
{
cout<<"Enter Customer ID:"; 
cin>>customerId;
cout<<"Enter Customer Name:";
cin>>name;
}
void displayCustomer()
{
cout<<"Customer ID:"<<customerId<<"\nCustomer Name:"<<name<< endl;
}
};
class Transaction
{
public:
string type;
float amount;
float balance;
void addTransaction(string t,float a,float b)
{
type=t; 
amount=a; 
balance=b;
}
void displayTransaction()
{
cout<<left<<setw(15)<<type<<setw(12)<<amount<<setw(12)<<balance <<endl;
}
};
class Account
{
public:
int accountNumber;
float balance;
Customer customer;
Transaction transactions[50];
int transactionCount;
void createAccount()
{
cout<<"Enter Account Number:"; 
cin>>accountNumber;
cout<<"Enter Initial Balance:"; 
cin>>balance;
transactionCount=0;
}
void deposit(float amount)
{
balance+=amount;        
cout<<"Amount deposited successfully.\n";
}
void withdraw(float amount)
{
if(amount>balance) {
cout<<"Insufficient balance.\n";
return;
}
balance-=amount;
transactions[transactionCount++]={ "Withdrawal",amount, balance};
cout<<"Amount withdrawn successfully.\n";
}
void displayAccount()
{
cout<<"\nACCOUNT INFORMATION\n";
customer.displayCustomer();
cout<<"Account Number:"<<accountNumber<<"\nBalance:"<< fixed<<setprecision(2)<< balance<<endl;
}
void displayTransactions()
{
cout<<"\nTRANSACTION HISTORY\n";
if(!transactionCount) { 
cout<<"No transactions available.\n";
return;
}
cout<<left<<setw(15)<<"Type"<<setw(12)<<"Amount"<<setw(12)<< "Balance"<<endl;
for(int i=0;i<transactionCount;i++) {
transactions[i].displayTransaction();
}
}
};
int main()
{
Account accounts[50];
int accountCount=0;
int choice,accountNumber,fromAccount,toAccount;
float amount;
while (true)
{
cout<<"\nBANKING SYSTEM\n1.Create Customer and Account\n2. Deposit\n3.Withdraw\n4.Transfer Funds\n5.Display Account Information\n6.View Transactions\n7.Exit\nEnter your choice:";
cin>>choice;
if(choice==7) {
cout<<"Thank you for using Banking System.\n";
break;
}
switch(choice)
{
case 1:
if(accountCount>=50) {
cout<<"Account limit reached.\n";
break;
}
cout<<"\nCREATE CUSTOMER\n";
accounts[accountCount].customer.createCustomer();
cout<<"\nCREATE ACCOUNT\n";
accounts[accountCount].createAccount();
accountCount++;
cout<<"Customer and Account created successfully.\n";
break;
case 2:
cout<<"Enter Account Number:"; 
cin>>accountNumber;
for(int i=0;i<accountCount;i++) {
if(accounts[i].accountNumber==accountNumber) {
cout<<"Enter amount to deposit:"; 
cin>>amount;
accounts[i].deposit(amount);
break;
                }
            }
            break;

case 3:
cout<<"Enter Account Number:"; 
cin>>accountNumber;
for(int i=0;i<accountCount;i++) {
if(accounts[i].accountNumber==accountNumber) {
cout<<"Enter amount to withdraw: "; 
cin>>amount;
accounts[i].withdraw(amount);
break;
}
}
break;
case 4:
cout<<"Enter Sender Account Number:"; 
cin>>fromAccount;
cout<<"Enter Receiver Account Number:"; 
cin>>toAccount;
cout<<"Enter amount to transfer:"; 
cin>>amount;
{
                int sender = -1, receiver = -1;
                for (int i = 0; i < accountCount; i++) {
if(accounts[i].accountNumber==fromAccount) 
sender=i;
if(accounts[i].accountNumber==toAccount)
receiver=i;
}
if(sender==-1||receiver==-1) {
cout<<"Account not found.\n";
} 
else if(amount>accounts[sender].balance)
{
cout<<"Insufficient balance.\n";
} 
else
{
accounts[sender].balance-=amount;
accounts[receiver].balance+=amount;
accounts[sender].transactions[accounts[sender].transactionCount++]={"Transfer Out",amount,accounts[sender].balance};
accounts[receiver].transactions[accounts[receiver].transactionCount++]={ "Transfer In",amount,accounts[receiver].balance};                   
cout<<"Fund transferred successfully.\n";
}
}
break;
case 5:
cout <<"Enter Account Number:";
cin>>accountNumber;
for(int i=0;i<accountCount;i++)
{
if(accounts[i].accountNumber==accountNumber)
{
accounts[i].displayAccount();
break;
}
}
break;
case 6:
cout<<"Enter Account Number:"; 
cin>>accountNumber;
for(int i=0;i<accountCount;i++)
{
if(accounts[i].accountNumber==accountNumber) 
{
accounts[i].displayTransactions();
break;
}
}
break;
default:
cout << "Invalid choice.\n";
}
}
return 0;
}