#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NADSTROPIJ 10
#define MAX_STRING_LENGHT 5

void TakeInput(char nadstropja[][MAX_STRING_LENGHT], char *trenutnoNadstropje[]);
void AvailableFloors(char nadstropja[][MAX_STRING_LENGHT], char *trenutnoNadstropje[]);

int main()
{

    char nadstropja[9][5] = {
        "-3",
        "-2",
        "-1",
        "P",
        "1",
        "2",
        "3",
        "4",
        "5"};
    char trenutnoNadstropje[5] = "P"; // to bo nadstropje , ki se bo spreminjalo, odvisno kje je oseba
    char *ptr = trenutnoNadstropje;
    char iskanoNadstropje[MAX_STRING_LENGHT]; // to bo nadstropje ki ga bo uporabnik vpisal

    AvailableFloors(nadstropja, &ptr);

    TakeInput(nadstropja, &ptr);
}

void TakeInput(char nadstropja[][MAX_STRING_LENGHT], char *trenutnoNadstropje[])
{

    char input[MAX_STRING_LENGHT];

    printf("vpisi stevilo nadstropja v katero hoces it. [number/P]\n");
    fgets(input, sizeof(input), stdin);
    char selectedIndex[MAX_STRING_LENGHT];

    bool FalseInput = true;
    

    if (sscanf(input, "%s", &selectedIndex) == 1)
    {



        for (int i = 0; i < 9; i++)
    {
        printf("TEST INSIDE LOOP : %s\n",selectedIndex);
        if (strcmp(nadstropja[i], selectedIndex) == 0)
        {
            FalseInput = false;
        }
    }
    if (FalseInput == true) // če je vnos uporabnika napačen oz ni enak podanim možnostim bo prašalo še enkrat kaj je to
    {
        printf("Vneseno nadstropje ne obstaja\n UPORABA : premik dvigala [Number/P] | exit [enter]\n");
        AvailableFloors(nadstropja, trenutnoNadstropje);
        TakeInput(nadstropja, trenutnoNadstropje);
    }
        
        
        *trenutnoNadstropje = selectedIndex;
        printf("trenutno nadstropje je %s \n", *trenutnoNadstropje);
        AvailableFloors(nadstropja, trenutnoNadstropje);
        TakeInput(nadstropja, trenutnoNadstropje);
    }
}

void AvailableFloors(char nadstropja[][MAX_STRING_LENGHT], char *trenutnoNadstropje[])
{
    printf("Available floors : \n");

    for (int i = 0; i < 9; i++)
    {
        if (strcmp(nadstropja[i], *trenutnoNadstropje) != 0)
        {
            printf("%s \n", nadstropja[i]);
        }
    }
}