#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    // Seed the random number generator with current time
    srand(static_cast<unsigned int>(time(nullptr)));
    
    // Generate random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;
    bool guessedCorrectly = false;
    
    cout << "==================================" << endl;
    cout << "   WELCOME TO THE GUESSING GAME   " << endl;
    cout << "==================================" << endl;
    cout << "I have generated a random number between 1 and 100." << endl;
    cout << "Can you guess what it is?" << endl;
    cout << "----------------------------------" << endl;
    
    // Game loop
    while (!guessedCorrectly) {
        cout << "\nEnter your guess: ";
        
        // Input validation - ensure user enters a valid integer
        if (!(cin >> guess)) {
            cout << "Invalid input! Please enter a number between 1 and 100." << endl;
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            continue;
        }
        
        // Validate guess range
        if (guess < 1 || guess > 100) {
            cout << "Please guess a number between 1 and 100!" << endl;
            continue;
        }
        
        attempts++;
        
        // Provide feedback
        if (guess > secretNumber) {
            cout << "📈 Too high! Try again." << endl;
        } 
        else if (guess < secretNumber) {
            cout << "📉 Too low! Try again." << endl;
        } 
        else {
            guessedCorrectly = true;
            cout << "\n🎉 CONGRATULATIONS! 🎉" << endl;
            cout << "You guessed the correct number: " << secretNumber << endl;
            cout << "Total attempts: " << attempts << endl;
            
            // Provide performance feedback
            if (attempts <= 5) {
                cout << "Excellent! You're a natural at this!" << endl;
            } 
            else if (attempts <= 10) {
                cout << "Good job! You got it!" << endl;
            } 
            else {
                cout << "You got there in the end! Keep practicing!" << endl;
            }
        }
    }
    
    cout << "\n==================================" << endl;
    cout << "Thanks for playing!" << endl;
    cout << "==================================" << endl;
    
    return 0;
}