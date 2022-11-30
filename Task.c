//For scanning and printing data
#include <stdio.h> 
//For using string functions
#include <string.h>

/**
 * @brief Define a constant to change max length of input
 * 
 */
#define max 100000
/**
 * @brief Define a constant to keep track of letters
 * 
 */
#define letters 30

int main(){
    /**
     * @brief Take a constant to take care of number of lines of input
     * 
     */
    int noOfLines;
    scanf("%d", &noOfLines);

    /**
     * @brief Creating an array of strings to store input
     * 
     */
    char lines[noOfLines][max];

    // Taking input
    for(int i=0; i<noOfLines; i++){
        //To ensure we do not read the new ilne
        fflush(stdin);
        //Getting input into the array of strings
        fgets(lines[i], max, stdin);
    }

    /**
     * @brief Create an array to keep track of premises and every true statement
     * 
     */
    int premises[letters];
    for(int i=0; i<letters; i++){
        premises[i] = 0;
    }

    /**
     * @brief Part 1: Analyzing Input, We have 2 Possibilities
     * If last character is P it is a premise, Otherwise it's a statement
     * 
     */
    for(int i=0; i<noOfLines; i++){
        // Case for if we found a premise
        if(lines[i][strlen(lines[i])- 2] == 'P'){
            printf("#%d: Found a Premise %s", i+1, lines[i]);
        }

        // Otherwise we check the number of / it has
        else{
            printf("#%d: Found a Statement %s", i+1, lines[i]);

            int j = 0;
            int slashes = 0;

            // Here we are waiting until the end of the sentence
            while(lines[i][j] != '\0'){
                //Once it reaches the first slash
                if(lines[i][j] == '/' && slashes == 0){
                    j++;
                    // If the next character is ^
                    if(lines[i][j] == '^'){
                        j++;
                        // We check if it's Introduction or Elimination
                        if(lines[i][j] == 'i'){
                            // Go forward to find the line numbers
                            j += 2;

                            int lineNo1 = 0;
                            while(lines[i][j] != '/'){
                                lineNo1 = lineNo1*10 + ((int) (lines[i][j])) - 48;
                                j++;
                            }
                            j++;
                            int lineNo2 = 0;
                            while(((int) lines[i][j]) > 48 && ((int) lines[i][j]) < 58){
                                lineNo2 = lineNo2*10 + ((int) (lines[i][j])) - 48;
                                j++;
                            }

                            printf("And Introduction - Lines %d %d", lineNo1, lineNo2);
                        }
                        else if(lines[i][j] == 'e'){
                            j++;
                            // Find if it's e1 or e2
                            int eliminationMode = (lines[i][j]) - 48;

                            // Go forward to find the line number
                            j += 2;

                            int lineNo1 = 0;
                            while(((int) lines[i][j]) > 48 && ((int) lines[i][j]) < 58){
                                lineNo1 = lineNo1*10 + ((int) (lines[i][j])) - 48;
                                j++;
                            }

                            printf("And Elimination - Mode %d - Line %d", eliminationMode, lineNo1);
                        }
                    }
                    // If the next character is v
                    else if(lines[i][j] == 'v'){
                        j++;
                        if(lines[i][j] == 'i'){
                            j++;
                            // Find if it's i1 or i2
                            int eliminationMode = (lines[i][j]) - 48;

                            // Go forward to find the line number
                            j += 2;

                            int lineNo1 = 0;
                            while(((int) lines[i][j]) > 48 && ((int) lines[i][j]) < 58){
                                lineNo1 = lineNo1*10 + ((int) (lines[i][j])) - 48;
                                j++;
                            }

                            printf("Or Elimination - Mode %d - Line %d", eliminationMode, lineNo1);
                        }
                    }
                    // If the next character is >
                    else if(lines[i][j] == '>' || lines[i][j] == 'M'){
                        printf("MT or > Elimination");
                    }
                }
                j++;
            }
        }
    }
}