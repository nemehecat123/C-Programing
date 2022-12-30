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
    bool enakoNadstropje= false;//ce je vpisalo enako nadstropje

    if (sscanf(input, "%s", &selectedIndex) == 1) // pogleda če ni kliknjen enter
    {

        for (int i = 0; i < 9; i++) // ta for loop pogleda samo če vnos ustreza kakšnemu od elementov
        {
            if (strcmp(nadstropja[i], selectedIndex) == 0) 
            {
                FalseInput = false; //če enmu ustreza pol pove da je kul in se nardi false
            }
            if (strcmp(*trenutnoNadstropje, selectedIndex) == 0) 
            {
                printf("to je enako nadstropje se enkraz upisano\n");
                enakoNadstropje = true; //če enmu ustreza pol pove da je kul in se nardi false
            }
        }
        if (enakoNadstropje==true)
        {
             printf("vnesel si enako nadstropje v katerem se že\n UPORABA : premik dvigala [Number/P] | exit [enter]\n");
            AvailableFloors(nadstropja, trenutnoNadstropje);
            TakeInput(nadstropja, trenutnoNadstropje);
        }
        
        if (FalseInput == true) // če je vnos uporabnika napačen oz ni enak podanim možnostim bo prašalo še enkrat kaj je to
        {
            printf("Vneseno nadstropje ne obstaja\n UPORABA : premik dvigala [Number/P] | exit [enter]\n");
            AvailableFloors(nadstropja, trenutnoNadstropje);
            TakeInput(nadstropja, trenutnoNadstropje);
        }
         // če pravilen vnos pol spremeni trenutno nadstropje da je vnečen vnos
        *trenutnoNadstropje = selectedIndex;
        printf("trenutno nadstropje je %s \n", *trenutnoNadstropje);
        AvailableFloors(nadstropja, trenutnoNadstropje);
        TakeInput(nadstropja, trenutnoNadstropje); // in ponovi proces dokler ne stisne exita
    }
}

void AvailableFloors(char nadstropja[][MAX_STRING_LENGHT], char *trenutnoNadstropje[])
{
    printf("Available floors : \n");

    for (int i = 0; i < 9; i++) // izpiše vsa možna nadstropja ki niso pouhna.
    {
        if (strcmp(nadstropja[i], *trenutnoNadstropje) != 0)
        {
            printf("%s \n", nadstropja[i]);
        }
    }
}