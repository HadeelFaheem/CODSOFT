#include <iostream>
#include<conio.h>
#include <ctime>
using namespace std;
string arr1[20],arr2[20],arr3[20],arr4[20];
int y[20],m[20],d[20],cy[20],cm[20],cd[20];
int total=0;
int date(int);
int due_date(int);
int fine(string);
void add()
 {
 	int choice;
 	cout<<"How many books do you want to add: ";
 	cin>>choice;
 	if(total==0)
 	{

 	total=total+choice;
 	for(int i=0; i<choice ; i++)
 	{
    arr4[i]="Yes";
 	cout<<"Enter data of book:"<<i+1<<endl<<endl; cin.ignore();
 	cout<<"Enter Book Name :";  getline(cin, arr1[i]);
 	cout<<"Enter Author Name : "; getline(cin, arr2[i]);;
	cout<<"Enter Book ISBN: "; getline(cin, arr3[i]);
		 }
	} else{
		for(int i=total; i<total+choice ; i++)
 	{
    arr4[i]="Yes";
 	cout<<"Enter data of book:"<<i+1<<endl<<endl; cin.ignore();
 	cout<<"Enter Book Name :"; getline(cin, arr1[i]);
 	cout<<"Enter Author Name : "; getline(cin, arr2[i]);;
	cout<<"Enter Book ISBN: "; getline(cin, arr3[i]);
		 }
		 total=total+choice;
	}
}
void show()
{           if (total==0)
           {
           cout<<"Record is empty!!"<<endl;

            }
            else {

	for(int i=0; i<total; i++)
	{
	cout<<"\nData of book:"<<i+1<<endl<<endl;
	cout<<"Name:" <<arr1[i]<<endl;
	cout<<"Author:" <<arr2[i]<<endl;
	cout<<"ISBN :"<<arr3[i]<<endl;
	cout<<"Availability: "<<arr4[i]<<endl;
	}
	getch(); }
}
void searche()
{    int i,k=1;  if (total==0)
           {
           cout<<"Record is empty!!"<<endl;
            }
            else {
	string isbn;
	cout<<"Enter ISBN of book which you want to search:"; cin>>isbn;
	for(i=0; i<total; i++)
	{
       if(isbn==arr3[i])
       {
        	cout<<"Data of book:"<<i+1<<endl<<endl;
        	cout<<"Name:" <<arr1[i]<<endl;
        	cout<<"Author:" <<arr2[i]<<endl;
        	cout<<"ISBN :"<<arr3[i]<<endl;
        	k=0;
	   }
	}
	if(k){
         cout<<"No Book Data found with this ISBN";
	} }
	getch();
}
void checkout()
{       int i; char t;
        string isbn;
	cout<<"Enter ISBN of book which you want to checkout: "; cin>>isbn;
	for(i=0; i<total; i++)
	{
       if(isbn==arr3[i])
       {
        	cout<<"Data of book:"<<i+1<<endl<<endl;
        	cout<<"Name:" <<arr1[i]<<endl;
        	cout<<"Author:" <<arr2[i]<<endl;
        	cout<<"ISBN :"<<arr3[i]<<endl;
	   }
	}
            cout<<"\nDo you want to Checkout/Borrow this book?(y/n):\t";
        	cin>>t;
        	if(t=='y'||t=='Y')
            {   system("CLS");
                cout<<"\n\t\t\t=============================\n\n\t\t\t\tTransaction Slip\n\n\t\t\t=============================\n";
                cout<<"\t\t\tName:" <<arr1[i-1]<<endl;
                cout<<"\t\t\tAuthor:" <<arr2[i-1]<<endl;
                cout<<"\t\t\tISBN :"<<arr3[i-1]<<endl;
                cout<<"\t\t\tDate of Issuance: ";
                date(i);
                cout<<"\n\t\t\tDue Date: "; due_date(i-1);
                cout<<"\n\n\t\t\tIf Book returned after due date\n\t\t\tFine of PKR 10 per day will be\n\t\t\tcharged\n";
                arr4[i-2]="No";
                getch();
            }

}
void returnbook()
 { int i;
     string isbn;
	cout<<"Enter ISBN of book which you want to return: "; cin>>isbn;
	i=fine(isbn);
	cout<<"\nPlease Pay Your Fine(If Any) at the counter. ";
	arr4[i-1]="Yes";
	getch();
}
int fine(string isbn)
{   int finee=0, i;
   for(i=0; i<total; i++)
	{
       if(isbn==arr3[i])
       {
        	 int daysOverdue = 0;
    if (cy[i] > y[i] || (cy[i] == y[i] && cm[i] > m[i]) || (cy[i] == y[i] && cm[i] == m[i] && cd[i] > d[i])) {
        daysOverdue = (cy[i] - y[i]) * 365 + (cm[i] - m[i]) * 30 + (cd[i] - d[i]);
    }

    // Calculate and display the fine
    double fineRate = 10.0;
    double fine = fineRate * daysOverdue;
    if (fine > 0) {
        cout << "Fine: Rs. " << fine << endl;
    } else {
        cout << "No fine." << endl;
    }
             } } getch();
    return i-1;
}

int date(int j){
    time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    cy[j]=(now->tm_year + 1900);
    cm[j]=now->tm_mon + 1;
    cd[j]=now->tm_mday;
    cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << "\n";    }
int due_date(int j){
    time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    y[j]=(now->tm_year + 1900);
    m[j]=now->tm_mon + 2;
    d[j]=now->tm_mday;
    cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 2) << '-'
         <<  now->tm_mday;
}

 int main()

{   string is;
int value;
while(true)
{  cout<<     "\t LIBRARY MANAGEMENT SYSTEM \t " ;
  cout <<    "\n-----Menu-----:" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Show Books" << endl;
        cout << "3. Search Book"<< endl;
        cout << "4. Check Out Book" << endl; //will also define the borrower plus transaction
        cout << "5. Return Book" << endl;
        cout << "6. Calculate Fine" << endl;
        cout << "7. Exit "<<endl ;
        cout<<"Enter choice (1-7): ";cin>>value;
        switch(value)
        {
          case 1:
            add();
            system("CLS");
            break;
          case 2:
            show();
            system("CLS");
            break;
          case 3:
            searche();
            system("CLS");
            break;
          case 4:
            checkout();
            system("CLS");
            break;
		  case 5:
            returnbook();
            system("CLS");
            break;
          case 6:
            cout<<"Enter ISBN of book which you want to return: "; cin>>is;
          	fine(is);
          	system("CLS");
          	break;
          case 7:
          	exit(0);
          	system("CLS");
          	break;
         default:
         	cout<<"Invalid value. Try again"<<endl;


		}

    }
}
