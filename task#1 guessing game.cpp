//guessing game 
#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));

    int randomNumber = rand() % 50 +1 ;
    int guess;
    bool correctguess = false;

    while (correctguess==false) 
	{   cout << "Guess the number (between 1 and 50): ";
        cin >> guess;

        if (guess == randomNumber) {
         cout << "Congratulations! You guessed the correct number." <<endl;
            correctguess = true;
        } else if (guess < randomNumber) {
         cout << "Too low! Try again." <<endl;
        } else {
         cout << "Too high! Try again." <<endl;
        }
    }

    return 0;
}

