#include <iostream>
using namespace std;
char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
int checkwin();
void board();

int main()
{
char playAgain;
do
{ int player = 1,i,choice;
  char mark;
	do{
	
board();
if(player % 2)
player = 1;
else
player = 2;
cout <<"Player "<< player <<", enter a number: "; cin >> choice;
if(player == 1){
mark = 'X';
}
else
{
mark = 'O';
}
if (choice == 1&& square[1] == '1')
square[1] = mark;
else if(choice==2&& square[2]== '2')
square[2] =mark;
else if(choice==3&& square[3]=='3')
square[3] =mark;
else if (choice== 4 && square[4] == '4')
square[4] =mark;
else if (choice== 5 && square[5] == '5')
square[5] =mark;
else if (choice== 6 && square[6] == '6')
square[6] =mark;
else if (choice== 7 && square[7] == '7')
square[7] =mark;
else if (choice== 8 && square[8] == '8')
square[8] =mark;
else if (choice== 9 && square[9] == '9')
square[9] =mark;
else
{
cout<<"Invalid move because u entered an invalid number ";
player--;
cin.ignore();
cin.get();
}
i=checkwin();
player++;
}while(i==-1);
board();
if(i==1)
cout<<"==>\aPlayer "<<--player<<" win ";
else
cout<<"==>\aGame draw";
cin.ignore();
cin.get();
  cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;
        for (int i = 1; i < 10; i++)
           {
			 square[i] = char(i + '0');

    }
	}  while (playAgain == 'y' || playAgain == 'Y');
 cout << "Thanks for playing!\n";
 
return 0;
}
int checkwin()
{
if (square[1] == square[2] && square[2] == square[3])
return 1;
else if (square[4] == square[5] && square[5] == square[6])
return 1;
else if (square[7] == square[8] && square[8] == square[9])
return 1;

else if (square[1] == square[4] && square[4] == square[7])
return 1;

else if (square[2] == square[5] && square[5] == square[8])

return 1;
else if (square[3] == square[6] && square[6] == square[9])
return 1;
else if (square[1] == square[5] && square[5] == square[9])
return 1;
else if (square[3] == square[5] && square[5] == square[7])
return 1;
else if (square[1] != '1'&& square[2] != '2'&& square[3] != '3' && square[4] != '4'&& square[5] != '5'&& square[6] != '6' && square[7] != '7'&& square[8] != '8'&& square[9] != '9')

return 0;
else
return -1;
}
void board()
{
system("cls");
cout<<"\n==========================";
cout <<"\n\tTic Tac Toe\n";
cout<<"\n==========================\n";
cout <<"Player 1 (X) - Player 2 (O)"<< endl << endl; cout << endl;
 cout<< "   |    |  \n";
cout<< " "<<square[1]<<" | "<<square[2]<<"  | "<<square[3]<<"  \n " ; 
cout<< "__|____|__\n";
cout<< "   |    | \n";
cout<< " "<<square[4]<<" | "<<square[5]<<"  | "<<square[6]<<"  \n " ; 
cout<< "__|____|__\n"; 
cout<< "   |    | \n";
cout<< " "<<square[7]<<" | "<<square[8]<<"  | "<<square[9]<<"  \n " ; 
cout<< "  |    |  \n";}

