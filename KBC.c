#include <stdio.h>

#define WHITE   "\033[1;37m"
#define YELLOW  "\033[1;33m"
#define GREEN   "\033[1;32m"
#define RED     "\033[1;31m"
#define BLUE    "\033[1;34m"
#define RESET   "\033[0m"

int askQuestion(char *question, char *a, char *b, char *c, char *d, char correct) {
    char choice;
    int lifelineUsed = 0;

    while (1) {
        printf("\n" WHITE "%s\n" RESET, question);

        if (!lifelineUsed) {
            printf(YELLOW "A. %s\nB. %s\nC. %s\nD. %s\n" RESET, a, b, c, d);
            printf(WHITE "Press A/B/C/D or L = 50-50: " RESET);
        } else {
            printf(YELLOW "Lifeline applied! Two options removed.\n" RESET);

            if (correct == 'A' || correct == 'B')
                printf(YELLOW "A. %s\nB. %s\n" RESET, a, b);
            else
                printf(YELLOW "C. %s\nD. %s\n" RESET, c, d);

            printf(WHITE "Choose your answer: " RESET);
        }

        scanf(" %c", &choice);

        // Lifeline logic
        if (choice == 'L' || choice == 'l') {
            if (!lifelineUsed) {
                lifelineUsed = 1;
                continue;
            } else {
                printf(RED "Lifeline already used!\n" RESET);
                continue;
            }
        }

        // Correct / Wrong check (case insensitive)
        if (choice == correct || choice == correct + 32) {
            printf(GREEN "Correct Answer!\n" RESET);
            return 1;
        } else {
            printf(RED "Wrong Answer!\n" RESET);
            return 0;
        }
    }
}

int main() {
    int score = 0;

    printf("\n" BLUE "***** WELCOME TO KAUN BANEGA CROREPATI (C Version) *****\n" RESET);

    score += askQuestion(
        "Q1. Who developed the C programming language?",
        "Bjarne Stroustrup",
        "Dennis Ritchie",
        "James Gosling",
        "Ken Thompson",
        'B'
    );

    score += askQuestion(
        "Q2. What is the correct extension of C files?",
        ".java",
        ".py",
        ".c",
        ".exe",
        'C'
    );

    score += askQuestion(
        "Q3. Which header file is needed for printf()?",
        "<math.h>",
        "<string.h>",
        "<stdio.h>",
        "<stdlib.h>",
        'C'
    );

    score += askQuestion(
        "Q4. Which symbol is used to comment a single line in C?",
        "#",
        "//",
        "/*",
        "--",
        'B'
    );

    score += askQuestion(
        "Q5. Which data type stores whole numbers?",
        "float",
        "char",
        "int",
        "double",
        'C'
    );

    score += askQuestion(
        "Q6. What does ASCII stand for?",
        "American Standard Code for Information Interchange",
        "Advanced System Code for Internet Interaction",
        "American School Code Internal Interface",
        "Automatic System Code Internal Integration",
        'A'
    );

    score += askQuestion(
        "Q7. Which loop runs at least once even if condition is false?",
        "while",
        "if",
        "do-while",
        "for",
        'C'
    );

    score += askQuestion(
        "Q8. Which operator is used to access memory address?",
        "& (ampersand)",
        "* (asterisk)",
        "%",
        "@",
        'A'
    );

    // ✅ FIXED LINE (no more garbage value)
    printf(WHITE "\nYour Final Score: %d/8\n" RESET, score);

    if (score == 8)
        printf(GREEN "🥳 SUPERSTAR! You answered ALL correctly!\n" RESET);
    else if (score >= 5)
        printf(GREEN "👍 Good job! Keep learning!\n" RESET);
    else
        printf(RED "Keep practicing, you're improving!\n" RESET);

    return 0;
}
