//Number guessing game

#include <iostream>
#include <cstdlib>      // for randomizing
#include <ctime>        // for accessing curent time
using namespace std;
int main()
{
	srand((unsigned int) time(NULL));   // using current time to get a random value
	int num = (rand() % 100) + 1;  // setting the range to (1-100)
    int guess = 0;  //setting the guessed value to be zero
    
    do
    {
        cout << "Enter the guess(1-100):";
        cin >> guess;
        if(guess > num)  // condition to state that the user has guessed a number greater than random value and has to go lower
        {
            cout << "Go lower!\n";
        }
        else if(guess < num)  // condition to state that the user has guessed a number less than rnadom value and has to go higher
        {
            cout << "Go higher!\n";
        }
        else    // condition to state that the user has guessed right
        {
            cout << "Congrats you have won!\n";  
        }
    }
    while (guess != num);  // condition to run the loop until the guessed value is equal to the random value
    
}
