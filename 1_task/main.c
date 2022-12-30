#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NADSTROPIJ 10
#define MAX_STRING_LENGHT 5


void TakeInput(char nadstropja[][MAX_STRING_LENGHT],char* trenutnoNadstropje[]);
void AvailableFloors(char nadstropja[][MAX_STRING_LENGHT],char *trenutnoNadstropje[]);

int main() {


    char nadstropja[10][5]={
                   "-3",
                   "-2",
                   "-1",
                   "P",
                   "1",
                   "2",
                   "3",
                   "4",
                   "5"
                 };
    char trenutnoNadstropje[5]="P"; // to bo nadstropje , ki se bo spreminjalo, odvisno kje je oseba
    char *ptr = trenutnoNadstropje;
    char iskanoNadstropje[MAX_STRING_LENGHT]; // to bo nadstropje ki ga bo uporabnik vpisal

        AvailableFloors(nadstropja,&ptr);


        TakeInput(nadstropja,&ptr);

        AvailableFloors(nadstropja,&ptr);
}


void TakeInput(char nadstropja[][MAX_STRING_LENGHT],char* trenutnoNadstropje[]){

    char input[MAX_STRING_LENGHT];

    


   fgets(input,sizeof(input),stdin);
    char selectedIndex[MAX_STRING_LENGHT];
    
    bool FalseInput = false;
   for (int i = 0; i < 9; i++) {
        if (strcmp(nadstropja[i], *trenutnoNadstropje) != 0) {
            FalseInput=true;
        }
    }
    if (FalseInput== true)
    {
        printf("Vnešeno nadstropje ne obstaja\n prosim poskusi še enkrat ali pa iztopi iz dvigala\n");
        AvailableFloors(nadstropja,trenutnoNadstropje);
        TakeInput(nadstropja,trenutnoNadstropje);
    }
    
    
    *trenutnoNadstropje = selectedIndex;
    printf("trenutno nadstropje je %s \n", *trenutnoNadstropje);
    AvailableFloors(nadstropja,trenutnoNadstropje);
    TakeInput(nadstropja,trenutnoNadstropje);
    
}
}

void AvailableFloors(char nadstropja[][MAX_STRING_LENGHT], char *trenutnoNadstropje[]) {
    printf("Available floors : \n");

    for (int i = 0; i < 9; i++) {
        if (strcmp(nadstropja[i], *trenutnoNadstropje) != 0) {
            printf("%s \n", nadstropja[i]);
        }
    }
}