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
     * @brief Create a file pointer to open the text file
     * 
     */
    FILE *file = fopen("./input.txt", "r");

    /**
     * @brief Take a constant to take care of number of lines of input
     * 
     */
    int noOfLines;
    fscanf(file, "%d\n", &noOfLines);
    printf("Found %d lines\n\n", noOfLines);

    /**
     * @brief Creating an array of strings to store input and the statements
     * 
     */
    char lines[noOfLines][max];
    char statements[noOfLines][max];

    // Taking input
    for(int i=0; i<noOfLines; i++){
        //Getting input into the array of strings
        fgets(lines[i], max, file);
    }

    /**
     * @brief Part 1: Analyzing Input, We have 2 Possibilities
     * If last character is P it is a premise, Otherwise it's a statement
     * 
     */
    for(int i=0; i<noOfLines; i++){
        // Replace every \n with \0
        if(lines[i][strlen(lines[i]) - 1] == '\n') lines[i][strlen(lines[i]) - 1] = '\0';

        // Add only the statement to statements
        int statementCursorTracker = 0;
        while(lines[i][statementCursorTracker] != '/'){
            statements[i][statementCursorTracker] = lines[i][statementCursorTracker];
            statementCursorTracker++;
        }

        // Case for if we found a premise
        if(lines[i][strlen(lines[i])-1] == 'P'){
            printf("#%d: Found a Premise %s --> VALID\n", i+1, lines[i]);

        }

        // Otherwise we check the number of / it has
        else{
            printf("#%d: Found a Statement %s --> ", i+1, lines[i]);

            int j = 0;
            int slashes = 0;

            // Here we are waiting until the end of the sentence
            while(lines[i][j] != '\0'){
                //Once it reaches the first slash
                if(lines[i][j] == '/' && slashes == 0){
                    j++;

                    /**
                     * @brief Construct a new if object for ^
                     * 
                     */
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
                            printf("And Introduction - Lines %d %d ", lineNo1, lineNo2);
                            printf("%s^%s", statements[lineNo1-1], statements[lineNo2-1]);
                        }
                        else if(lines[i][j] == 'e'){
                            j++;
                            // Find if it's e1 or e2
                            int eliminationMode = (lines[i][j]) - 48;

                            // Go forward to find the line number
                            j += 2;

                            int lineNo = 0;
                            while(((int) lines[i][j]) > 48 && ((int) lines[i][j]) < 58){
                                lineNo = lineNo*10 + ((int) (lines[i][j])) - 48;
                                j++;
                            }

                            printf("And Elimination - Mode %d - Line %d", eliminationMode, lineNo);
                        }
                    }
                    /**
                     * @brief Construct a new if object for v
                     * 
                     */
                    else if(lines[i][j] == 'v'){
                        j++;
                        if(lines[i][j] == 'i'){
                            j++;
                            // Find if it's i1 or i2
                            int eliminationMode = (lines[i][j]) - 48;

                            // Go forward to find the line number
                            j += 2;

                            int lineNo = 0;
                            while(((int) lines[i][j]) > 48 && ((int) lines[i][j]) < 58){
                                lineNo = lineNo*10 + ((int) (lines[i][j])) - 48;
                                j++;
                            }

                            printf("Or Elimination - Mode %d - Line %d", eliminationMode, lineNo);
                        }
                    }
                    /**
                     * @brief Construct a new if object for >
                     * 
                     */
                    else if(lines[i][j] == '>' || lines[i][j] == 'M'){
                        printf("MT or > Elimination");
                    }
                }
                j++;
            }
        }
    }
}