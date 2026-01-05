/*
 * ============================================
 * ROCK PAPER SCISSORS GAME IN C
 * Terminal Games Vault - Episode 3
 * ============================================
 * 
 * WHAT THIS PROGRAM TEACHES:
 * - Random number generation (srand, rand, time)
 * - Character input validation
 * - Function design and modular programming
 * - Multi-round game loop logic
 * - Score tracking across iterations
 * 
 * RULES:
 * - Rock (R) beats Scissors (S)
 * - Scissors (S) beats Paper (P)
 * - Paper (P) beats Rock (R)
 * - Best of 3 rounds wins
 */

#include <stdio.h>   // Standard input/output functions (printf, scanf)
#include <stdlib.h>  // For rand() and srand() functions
#include <time.h>    // For time() function to seed randomness
#include <ctype.h>   // For tolower() function to handle uppercase input

// ============================================
// FUNCTION: getComputerChoice()
// PURPOSE: Generate computer's random choice
// RETURNS: 'r' for Rock, 'p' for Paper, 's' for Scissors
// ============================================
char getComputerChoice() {
    // rand() generates a random integer
    // % 3 gives remainder: 0, 1, or 2 (three possible outcomes)
    int random = rand() % 3;
    
    if (random == 0) 
        return 'r';      // Rock
    else if (random == 1) 
        return 'p';      // Paper
    else 
        return 's';      // Scissors
}

// ============================================
// FUNCTION: displayChoice()
// PURPOSE: Convert single character to full word
// PARAMETER: choice - 'r', 'p', or 's'
// ============================================
void displayChoice(char choice) {
    // Simple mapping: character → full word
    if (choice == 'r') 
        printf("ROCK");
    else if (choice == 'p') 
        printf("PAPER");
    else 
        printf("SCISSORS");
}

// ============================================
// FUNCTION: determineWinner()
// PURPOSE: Decide who wins based on game rules
// PARAMETERS: 
//   - player: player's choice
//   - computer: computer's choice
// RETURNS: 
//   1  = Player wins
//   0  = Computer wins
//  -1  = Draw (both chose same)
// ============================================
int determineWinner(char player, char computer) {
    // First check: If both chose the same, it's a draw
    if (player == computer) 
        return -1;
    
    // Check all winning conditions for player:
    // Rock beats Scissors
    // Scissors beats Paper
    // Paper beats Rock
    if ((player == 'r' && computer == 's') ||
        (player == 's' && computer == 'p') ||
        (player == 'p' && computer == 'r')) {
        return 1;  // Player wins
    }
    
    // If not a draw and player didn't win, computer must have won
    return 0;
}

// ============================================
// MAIN FUNCTION: Game execution starts here
// ============================================
int main() {
    // Variable declarations
    char playerChoice;       // Stores player's input
    char computerChoice;     // Stores computer's random choice
    int playerScore = 0;     // Tracks player wins
    int computerScore = 0;   // Tracks computer wins
    int rounds = 3;          // Total rounds to play
    
    // ============================================
    // CRITICAL: Seed the random number generator
    // ============================================
    // time(NULL) returns current time in seconds since 1970
    // This ensures different random numbers each time you run the program
    // Without this, rand() would generate the same sequence every time!
    srand(time(NULL));
    
    // Display game header
    printf("\n=== ROCK PAPER SCISSORS ===\n");
    printf("Best of 3 rounds!\n");
    printf("Enter: R/r (Rock) | P/p (Paper) | S/s (Scissors)\n\n");
    
    // ============================================
    // GAME LOOP: Play 3 rounds
    // ============================================
    for (int i = 1; i <= rounds; i++) {
        printf("--- ROUND %d ---\n", i);
        printf("Your choice: ");
        
        // Read player input
        // Space before %c skips any leftover newline characters
        scanf(" %c", &playerChoice);
        
        // ============================================
        // INPUT NORMALIZATION: Convert to lowercase
        // ============================================
        // tolower() converts 'R' → 'r', 'P' → 'p', 'S' → 's'
        // This allows both uppercase and lowercase input
        playerChoice = tolower(playerChoice);
        
        // ============================================
        // INPUT VALIDATION: Check if input is valid
        // ============================================
        if (playerChoice != 'r' && playerChoice != 'p' && playerChoice != 's') {
            printf("❌ Invalid choice! Use R/r, P/p, or S/s\n\n");
            i--;  // Subtract 1 from loop counter to repeat this round
            continue;  // Skip rest of loop and start next iteration
        }
        
        // Get computer's random choice
        computerChoice = getComputerChoice();
        
        // Display both choices
        printf("You chose: ");
        displayChoice(playerChoice);
        printf("\nComputer chose: ");
        displayChoice(computerChoice);
        printf("\n");
        
        // Determine winner using our function
        int result = determineWinner(playerChoice, computerChoice);
        
        // ============================================
        // UPDATE SCORES based on result
        // ============================================
        if (result == 1) {
            printf("✅ You WIN this round!\n\n");
            playerScore++;  // Increment player score
        } else if (result == 0) {
            printf("❌ Computer WINS this round!\n\n");
            computerScore++;  // Increment computer score
        } else {
            printf("🤝 It's a DRAW! (No points awarded)\n\n");
            // Note: Draws don't increment either score
        }
    }
    
    // ============================================
    // DISPLAY FINAL RESULTS
    // ============================================
    printf("\n=== FINAL SCORE ===\n");
    printf("YOU: %d | COMPUTER: %d\n\n", playerScore, computerScore);
    
    // Determine overall winner
    if (playerScore > computerScore) {
        printf("🎉 YOU WIN THE GAME! 🎉\n");
    } else if (playerScore < computerScore) {
        printf("💀 COMPUTER WINS! Try again! 💀\n");
    } else {
        printf("🤝 IT'S A TIE! Rematch? 🤝\n");
    }
    
    printf("\n");  // Extra line for clean output
    return 0;      // Signal successful program termination
}
