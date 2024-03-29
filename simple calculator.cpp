#include <iostream>
using namespace std;
int main()
{
float num1, num2 ;
cout<<"Enter the first number:";
cin>>num1;
cout<<"Enter the second number:";
cin>>num2;
char op;
double sum, diff , product , quotient ;
cout<<"Choose an operation (+, - , * , /) : ";
cin>>op;

if (op=='+')
{sum = num1 + num2 ;
 cout<<"The sum of "<<num1<<" and "<<num2<<" is :" <<sum; }
else if ( op== '-')
{ diff = num1 - num2 ;
cout<<"The difference of "<<num1<<" and "<<num2<<" is :"<<diff; }
else if ( op=='*')
 { product = num1 * num2 ;
 cout<<"The product  of "<<num1<<" and "<<num2<<" is :"<<product; }
 else if ( op=='/')
 { quotient= num1 / num2 ;
 cout<<"The division of "<<num1<<" and "<<num2<<" is :"<<quotient; }
  else 
{
cout<<"Invalid operation";	} 
	
	return 0;
}
