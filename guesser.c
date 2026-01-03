#include <stdio.h>   // Standard input/output functions (printf, scanf)
#include <stdlib.h>  // rand, srand
#include <time.h>    // time for random seed

int main() {
    // Seed the random number generator with the current time
    srand(time(0));

    int secret, guess, tries = 0;  // secret = target number, guess = user input, tries = attempts

    // Generate a random number between 1 and 100
    secret = rand() % 100 + 1;

    // Keep asking for guesses until the user finds the secret number
    while (guess != secret) {
        printf("Enter your guess (1-100): ");
        scanf("%d", &guess);   // Read user guess from input

        tries++;               // Count this attempt

        if (guess < secret) {
            printf("Too low! Try again.\n");
        } else if (guess > secret) {
            printf("Too high! Try again.\n");
        } else {
            // User guessed correctly
            printf("Congratulations! You guessed the number %d in %d tries.\n", secret, tries);
        }
    }

    return 0;   // Indicate successful program end
}
