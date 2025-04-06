#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

int option;

void header(){
    printf(BOLD CYAN
        " $$$$$$\\                                    $$\\       \n"
        "$$  __$$\\                                   $$ |      \n"
        "$$ /  \\__|$$\\   $$\\ $$$$$$$\\       $$$$$$$\\ $$$$$$$\\  \n"
        "$$$$\\     $$ |  $$ |$$  __$$\\     $$  _____|$$  __$$\\ \n"
        "$$  _|    $$ |  $$ |$$ |  $$ |    \\$$$$$$\\  $$ |  $$ |\n"
        "$$ |      $$ |  $$ |$$ |  $$ |     \\____$$\\ $$ |  $$ |\n"
        "$$ |      \\$$$$$$  |$$ |  $$ |$$\\ $$$$$$$  |$$ |  $$ |\n"
        "\\__|       \\______/ \\__|  \\__|\\__|\\_______/ \\__|  \\__|\n"
        "                                                     \n"
        "                                                     \n" RESET);
}

void clearScreen(){
    printf("\033[2J\033[H");
    header();
}

void menu(){
    printf(BOLD GREEN "\n---==={ Fun Time Menu }===---\n" RESET);
    printf(YELLOW "\n1. Dark Joke");
    printf("\n2. Fun Fact");
    printf("\n3. Check the Weather");
    printf("\n0. Exit\n" RESET);
    printf(BOLD BLUE "\nEnter your choice [0-3]: " RESET);

    scanf("%d", &option);
}

int main(){   
    bool loop = true;
    
    header();
    
    while(loop){
        menu();
        srand(time(NULL));
        switch(option){
            case 0: {
                loop = false;
                break;
            }
            case 1: {
                clearScreen();
                printf(YELLOW "\nJoke:\n\n" RESET);
                
                system("curl -s https://v2.jokeapi.dev/joke/Dark?format=txt");

                printf("\n\nPress enter to go back ");
                getchar();
                getchar();
                clearScreen();
                break;
            }
            case 2: {
                clearScreen();
                printf(MAGENTA BOLD"\nFun Fact:\n" RESET);
                
                const char* facts[] = {
                    "In 2006, someone tried to sell New Zealand on eBay.",
                    "There's a town in Norway where it's illegal to die.",
                    "The Guinness World Record for the longest hiccuping spree is 68 years.",
                    "The 'French' in French fries has nothing to do with France — it's about the way they’re cut.",
                    "In Japan, letting a sumo wrestler make your baby cry is considered good luck.",
                    "There's a McDonald's in every continent except Antarctica.",
                    "You can hire people in China to stand in line for you.",
                    "A cloud can weigh more than a million pounds.",
                    "The inventor of the Pringles can is buried in one.",
                    "Some cats are allergic to humans." 
                };                
                
                int totalFacts = sizeof(facts) / sizeof(facts[0]); // total size ÷ size of one thing = number of things
                int randomIndex = rand() % totalFacts;
                printf("%s\n", facts[randomIndex]);
                
                printf("\nPress enter to go back ");
                getchar();
                getchar();
                clearScreen();
                
                break;
            }
            case 3: {
                char city[100];
                char command[200];

                clearScreen();
                
                printf(CYAN "\nCheck the Weather:\n" RESET);
                printf("\nName of city: ");
                
                // using fgets instead of scanf("%s", city); bcz it manages spaces well
                getchar(); // eat leftover lines
                fgets(city, sizeof(city), stdin);
                city[strcspn(city, "\n")] = 0; // remove trailing from fgets

                snprintf(command, sizeof(command), "curl wttr.in/~%s", city);
                system(command);

                printf("\nPress enter to go back ");
                getchar();
                
                clearScreen();
                break;
            }
            default: {
                clearScreen();
                printf(RED "\nInvalid option, try again\n" RESET);
            }
        }
    }
    return 0;
}
