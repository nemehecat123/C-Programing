#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAX_NADSTROPIJ = 10;
const int MAX_STRING_LENGHT = 3;

void mainMenu(int nadstropje);

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



    

    char iskanoNadstropje[MAX_STRING_LENGHT];





   char str2[] = {"-3"};
   if (strcmp(nadstropja[0],str2)==0)
   {
    printf("okej to dela ");
   }
   


    //mainMenu(3);

}

void mainMenu(int nadstropje){

    char input[2];
     
    printf("Insert <number> to go to that floor. \n %s",input);
    printf(" Or press [enter] to exit the floor.\n");

   fgets(input,sizeof(input),stdin);
    int selected_index;

   if (sscanf(input, "%i", &selected_index) == 1) {
        mainMenu(nadstropje);
    }

}


