#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAX_NADSTROPIJ = 10;
const int MAX_STRING_LENGHT = 3;


void TakeInput(char nadstropja[][MAX_STRING_LENGHT],char *trenutnoNadstropje[]);
void AvailableFloors(char nadstropja[][MAX_STRING_LENGHT],char *trenutnoNadstropje[]);

int main() {

    char nadstropja[9][3]={
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
    char trenutnoNadstropje[3]="P"; // to bo nadstropje , ki se bo spreminjalo, odvisno kje je oseba
    char *ptr = trenutnoNadstropje;
    char iskanoNadstropje[MAX_STRING_LENGHT]; // to bo nadstropje ki ga bo uporabnik vpisal

    
    AvailableFloors(nadstropja,&ptr);
    ptr = "P";







}


void TakeInput(char nadstropja[][MAX_STRING_LENGHT],char *trenutnoNadstropje[]){

    char input[MAX_STRING_LENGHT];

    printf("You are currently on the %s flor. \n ",trenutnoNadstropje); 
    printf("Insert <number/P> to go to that floor. \n ");
    printf(" Or press [enter] to exit the floor.\n");

   fgets(input,sizeof(input),stdin);
    int selected_index;

   if (sscanf(input, "%s", &selected_index) == 1) {
   *trenutnoNadstropje=input;
    AvailableFloors(nadstropja,trenutnoNadstropje);
    TakeInput(nadstropja,trenutnoNadstropje);
    }
}

void AvailableFloors(char nadstropja[][MAX_STRING_LENGHT],char *trenutnoNadstropje[]){
   
    
    printf("Available floors : \n");
    for (int i = 0; i < 9; i++)
    {
        if (strcmp(nadstropja[i],*trenutnoNadstropje)!=0)
        {
            printf("%s\n",nadstropja[i]);
        }
    }

    printf("%p",&trenutnoNadstropje);

    
}

