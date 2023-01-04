#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void drawHangman(int *chances);
void choseLetter(char *chosenLetter, int *countTries, char GuessedLetters[]);
bool checkLetterIfInWord(char *, char chosenWord[], int *chances);
void printWord(char chosenWord[], char *chosenLetter, char hiddenChosenWord[]);

int main()
{
    // Seed the random number generator with the current time kar smo delali u soli da bo zbralo vedno drugo besedo
    srand(time(0));

    // Generate a random number from 0 to 7
    int rand_num = rand() % 8;

    // random words to chose from
    char words[7][20] = {
        "banana",
        "letalo",
        "kapa",
        "parfum",
        "skleda",
        "medalja",
        "skodelica"};
    char chosenWord[20];

    char hiddenChosenWord[20];

    // number of tries he inputed
    int countTries = 0;

    // letters he guesed #ce ne das u prazne narekovaje ti da cudne znake
    char GuessedLetters[20] = "";

    // give the chosen word a word from matrix words.
    strcpy(chosenWord, words[rand_num]);

    for (int i = 0; i < 20; i++)
    {
        hiddenChosenWord[i] = '_';
        if (chosenWord[i] == '\0')
        {
            hiddenChosenWord[i] = '\0';
            break;
        }
    }


    // number of tries they have
    int chances = 7;

    // letter that will be chosen and will latter change
    char chosenLetter[5] = "";
    printWord(chosenWord, chosenLetter,hiddenChosenWord);
    drawHangman(&chances);


    while (chances!=0)
    {
        choseLetter(chosenLetter, &countTries, GuessedLetters); // chosen letter se bo spremenu,,,count tries bo sou gor plus 1 in guessed letter se bo dodala crka ku si jo uganu
        if (checkLetterIfInWord(chosenLetter, chosenWord,&chances)) // vrne true ce je chosen letter v besedi ki je bla dolocena random
        {
            printWord(chosenWord, chosenLetter,hiddenChosenWord);  
              
        }
        else
        {
            printf("chances %i",chances);
        }
    printWord(chosenWord, chosenLetter,hiddenChosenWord);

    printf("guesed letters are :  %s\n", GuessedLetters);
    drawHangman(&chances);

    }


    return 0;
}

void printWord(char HiddenWord[], char *chosenLetter, char hiddenChosenWord[])
{


    for (int i = 0; i < strlen(hiddenChosenWord); i++)
    {
        if (HiddenWord[i]==*chosenLetter)
        {
            hiddenChosenWord[i]=*chosenLetter;
        }
    }
    printf(" Your word is : %s \n",hiddenChosenWord);
    bool konecIgre=true; // predpostavi da je ugotovil use crke
    for (int i = 0; i < strlen(hiddenChosenWord); i++) //  poglej ce je  uganu use crke... ce ni  je konecIgre false
    {
        if (hiddenChosenWord[i]=='_')
        {
            konecIgre=false;
        }
        
    }
    if(konecIgre==true){
            printf("bravo zmagou si");
            
            exit(0);
        }
    
}

// Function definition
void choseLetter(char *chosenLetter, int *countTries, char GuessedLetters[])
{
    char input[5];

    printf("Vpisi crko ki jo zelis uganiti [letter]\n");
    fgets(input, sizeof(input), stdin);
    char selectedIndex[5];

    if (sscanf(input, "%s", &selectedIndex) == 1) // pogleda če ni kliknjen enter
    {
        strcpy(chosenLetter, selectedIndex);
    }
    GuessedLetters[*countTries] = selectedIndex[0];
    // increment number of tries he tried
    *countTries = *countTries + 1;
}

bool checkLetterIfInWord(char *chosenLetter, char chosenWord[], int* chances)
{

    for (int i = 0; i < 20; i++)
    {
        if (chosenWord[i] == *chosenLetter)
        {
            return true;
        }
    }
    *chances= *chances-1;
    return false;
}

void drawHangman(int *chances)
{
    if (*chances == 7)
    {
        printf(" _______\n");
        printf(" |/   | \n");
        printf(" |      \n");
        printf(" |      \n");
        printf(" |  _____  \n");
        printf(" | |     | \n");
        printf(" | |     | \n");
        printf("_|_|     |\n");
    }else if (*chances == 6)
    {
        printf(" _______\n");
        printf(" |/   | \n");
        printf(" |    O \n");
        printf(" |      \n");
        printf(" |  _____  \n");
        printf(" | |     | \n");
        printf(" | |     | \n");
        printf("_|_|     |\n");
    }
    else if (*chances == 5)
    {
        printf(" _______\n");
        printf(" |/   | \n");
        printf(" |    O \n");
        printf(" |    | \n");
        printf(" |  _____  \n");
        printf(" | |     | \n");
        printf(" | |     | \n");
        printf("_|_|     |\n");
    }
    else if (*chances == 4)
    {
        printf(" _______\n");
        printf(" |/   | \n");
        printf(" |    O \n");
        printf(" |   /| \n");
        printf(" |  _____  \n");
        printf(" | |     | \n");
        printf(" | |     | \n");
        printf("_|_|     |\n");
    }
    else if (*chances == 3)
    {
        printf(" _______\n");
        printf(" |/   | \n");
        printf(" |    O \n");
        printf(" |   /|\\ \n");
        printf(" |  _____  \n");
        printf(" | |     | \n");
        printf(" | |     | \n");
        printf("_|_|     |\n");
    }
    else if (*chances == 2)
    {
        printf(" _______\n");
        printf(" |/   | \n");
        printf(" |    O \n");
        printf(" |   /|\\ \n");
        printf(" |  _/___\n");
        printf(" | |     | \n");
        printf(" | |     | \n");
        printf("_|_|     |\n");
    }
    else if (*chances == 1)
    {
        printf(" _______\n");
        printf(" |/   | \n");
        printf(" |    O \n");
        printf(" |   /|\\ \n");
        printf(" |  _/_\\_ \n");
        printf(" | |      | \n");
        printf(" | |      | \n");
        printf("_|_|      |\n");
    }
    else if (*chances == 0)
    {
        printf(" _______\n");
        printf(" |/   | \n");
        printf(" |    | \n");
        printf(" |    O \n");
        printf(" |   /|\\ \t \t hihi hanged \n");
        printf(" | | / \\ |\n");
        printf(" | |    /| \n");
        printf("_|_|   / |\n");
    }
}

