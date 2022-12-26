#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAX_NADSTROPIJ = 10;

void mainMenu(int nadstropje);

int main() {

    char line[2] = "0";
    int x = atoi(line);

    if (atoi(line)==0)
    {
    printf(" to je moja cifra v tem stringu %d\n",x);
        
    }
    

    mainMenu(3);

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
