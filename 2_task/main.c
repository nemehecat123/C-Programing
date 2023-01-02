#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


void drawHangman(int *chances);
void choseLetter(char*);

int main()
{
    // Seed the random number generator with the current time kar smo delali u soli da bo zbralo vedno drugo besedo
    srand(time(0));

    // Generate a random number from 0 to 7
    int rand_num = rand() % 8;

     // random words to chose from
    char words[7][20] = {
        "Banana",
        "Letalo",
        "Kapa",
        "Parfum",
        "Skleda",
        "Medalja",
        "Skodelica"};
    char chosenWord[20]; 

    // give the chosen word a word from matrix words.
    strcpy(chosenWord, words[rand_num]);

    // number of tries they have
    int chances =7;

    // letter that will be chosen and that letter will change
    char chosenLetter[5]="";
   

      choseLetter(chosenLetter);

      while (true)
      {
     choseLetter(chosenLetter);

      }
      

    return 0;
}

// Function definition
void choseLetter(char* chosenLetter) {
    char input[5];

    printf("Vpisi crko ki jo zelis uganiti [letter]\n");
    fgets(input, sizeof(input), stdin);
    char selectedIndex[5];

    if (sscanf(input, "%s", &selectedIndex) == 1) // pogleda če ni kliknjen enter
    {
        printf("zbral si crko %s\n",selectedIndex);
        strcpy(chosenLetter, selectedIndex);
    }
    return;
}


void drawHangman(int *chances)
{
    if (*chances == 6)
    {
        printf(" _______\n");
        printf(" |/   | \n");
        printf(" |    O \n");
        printf(" |      \n");
        printf(" |      \n");
        printf(" |      \n");
        printf("_|___   \n");
    }
    else if (*chances == 5)
    {
        printf(" _______\n");
        printf(" |/   | \n");
        printf(" |    O \n");
        printf(" |    | \n");
        printf(" |      \n");
        printf(" |      \n");
        printf("_|___   \n");
    }
    else if (*chances == 4)
    {
        printf(" _______\n");
        printf(" |/   | \n");
        printf(" |    O \n");
        printf(" |   /| \n");
        printf(" |      \n");
        printf(" |      \n");
        printf("_|___   \n");
    }
    else if (*chances == 3)
    {
        printf(" _______\n");
        printf(" |/   | \n");
        printf(" |    O \n");
        printf(" |   /|\\ \n");
        printf(" |      \n");
        printf(" |      \n");
        printf("_|___   \n");
    }
    else if (*chances == 2)
    {
        printf(" _______\n");
        printf(" |/   | \n");
        printf(" |    O \n");
        printf(" |   /|\\ \n");
        printf(" |   /   \n");
        printf(" |      \n");
        printf("_|___   \n");
    }
    else if (*chances == 1)
    {
        printf(" _______\n");
        printf(" |/   | \n");
        printf(" |    O \n");
        printf(" |   /|\\ \n");
        printf(" |   / \\ \n");
        printf(" |      \n");
        printf("_|___   \n");
    }
    else if (*chances == 0)
    {
        printf(" _______\n");
        printf(" |/   | \n");
        printf(" |/   | \n");
        printf(" |    O \n");
        printf(" |   /|\\ \t \t hihi hanged \n");
        printf(" |   / \\ \n");
        printf("_|___   \n");
    }
}