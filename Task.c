// For scanning and printing data
#include <stdio.h>
// For using string functions
#include <string.h>

/**
 * @brief Define a constant to change max length of input
 *
 */
#define max 100000

int main()
{
    /**
     * @brief Create a file pointer to open the text file
     *
     */
    FILE *file = fopen("./Inputs/mt.txt", "r");

    /**
     * @brief Take a constant to take care of number of lines of input
     *
     */
    int noOfLines;
    fscanf(file, "%d\n", &noOfLines);
    printf("Found %d lines\n", noOfLines);

    /**
     * @brief Creating an array of strings to store input and the statements
     *
     */
    char inputLines[noOfLines][max];
    char statements[noOfLines][max];

    /**
     * @brief Getting input into the array of strings
     *
     */
    for (int i = 0; i < noOfLines; i++)
    {
        fgets(inputLines[i], max, file);
    }

    /**
     * @brief Part 1: Analyzing Input, We have 2 Possibilities
     * If last character is P it is a premise, Otherwise it's a statement
     *
     */
    for (int i = 0; i < noOfLines; i++)
    {
        // Replace every \n with \0
        if (inputLines[i][strlen(inputLines[i]) - 1] == '\n')
            inputLines[i][strlen(inputLines[i]) - 1] = '\0';

        // Add only the statement without the after / parts to statements
        int statementCursorTracker = 0;
        while (inputLines[i][statementCursorTracker] != '/')
        {
            statements[i][statementCursorTracker] = inputLines[i][statementCursorTracker];
            statementCursorTracker++;
        }

        // Case for if we found a premise
        if (inputLines[i][strlen(inputLines[i]) - 1] == 'P')
        {
            printf("\n#%d: Found a Premise %s --> VALID\n", i + 1, inputLines[i]);
        }
        // Otherwise we check the number of / it has
        else
        {
            printf("\n#%d: Found a Statement %s", i + 1, inputLines[i]);

            int j = 0;
            int slashes = 0;

            // Here we are waiting until the end of the sentence
            while (inputLines[i][j] != '\0')
            {
                // Once it reaches the first slash
                if (inputLines[i][j] == '/' && slashes == 0)
                {
                    // Make /
                    j++;

                    /**
                     * @brief Construct a new if object for ^
                     *
                     */
                    if (inputLines[i][j] == '^')
                    {
                        j++;
                        // We check if it's Introduction or Elimination
                        if (inputLines[i][j] == 'i')
                        {
                            // Go forward to find the line numbers
                            j += 2;

                            int lineNo1 = 0;
                            while (inputLines[i][j] != '/')
                            {
                                lineNo1 = lineNo1 * 10 + ((int)(inputLines[i][j])) - 48;
                                j++;
                            }
                            j++;
                            int lineNo2 = 0;
                            while (((int)inputLines[i][j]) > 48 && ((int)inputLines[i][j]) < 58)
                            {
                                lineNo2 = lineNo2 * 10 + ((int)(inputLines[i][j])) - 48;
                                j++;
                            }
                            printf("\n::> And Introduction - Lines %d %d ", lineNo1, lineNo2);

                            strcmp(statements[i], strcat(strcat(statements[lineNo1 - 1], "^"), statements[lineNo2 - 1])) == 0 ? printf("--> VALID\n") : printf("--> INVALID\n");
                        }
                        else if (inputLines[i][j] == 'e')
                        {
                            j++;
                            // Find if it's e1 or e2
                            int eliminationMode = (inputLines[i][j]) - 48;

                            // Go forward to find the line number
                            j += 2;

                            int lineNo = 0;
                            while (((int)inputLines[i][j]) > 48 && ((int)inputLines[i][j]) < 58)
                            {
                                lineNo = lineNo * 10 + ((int)(inputLines[i][j])) - 48;
                                j++;
                            }

                            printf("\n::> And Elimination - Mode %d - Line %d", eliminationMode, lineNo);

                            /**
                             * @brief Here lineNo-1 gives the sentence from which we are eliminating
                             * and i gives the one after elimination
                             *
                             */
                            if (eliminationMode == 1)
                            {
                                /**
                                 * @brief Here we go until the current line ends
                                 * and keep comparing i.e. if we have (a^b) and we get a
                                 * using and elimination we compare from start till the
                                 * smaller string ends
                                 *
                                 */
                                int andFinder = 0;
                                int validity = 1;

                                while (statements[i][andFinder] != '\0')
                                {
                                    if (statements[lineNo - 1][andFinder] != statements[i][andFinder - 1])
                                        validity = 0;
                                    andFinder++;
                                }

                                validity == 1 ? printf("--> VALID\n") : printf("--> INVALID\n");
                            }
                            else if (eliminationMode == 2)
                            {
                                /**
                                 * @brief Here we loop until the bigger line goes to the start
                                 * and keep comparing i.e. if we have (a^b) and we get b(this is i)
                                 * using and elimination we compare from start till the
                                 * smaller string goes to the start
                                 *
                                 */
                                int andFinderForEliminatedString = strlen(statements[i]) - 1;
                                int andFinderForFullString = strlen(statements[lineNo - 1]) - 2;

                                int validity = 1;

                                while (andFinderForEliminatedString >= 0)
                                {
                                    if (statements[lineNo - 1][andFinderForFullString] != statements[i][andFinderForEliminatedString])
                                        validity = 0;
                                    andFinderForEliminatedString--;
                                    andFinderForFullString--;
                                }

                                validity == 1 ? printf("--> VALID\n") : printf("--> INVALID\n");
                            }
                        }
                    }
                    /**
                     * @brief Construct a new if object for v Introduction
                     *
                     */
                    else if (inputLines[i][j] == 'v')
                    {
                        j++;
                        if (inputLines[i][j] == 'i')
                        {
                            j++;
                            // Find if it's i1 or i2
                            int introductionMode = (inputLines[i][j]) - 48;

                            // Go forward to find the line number
                            j += 2;

                            int lineNo = 0;
                            while (((int)inputLines[i][j]) > 48 && ((int)inputLines[i][j]) < 58)
                            {
                                lineNo = lineNo * 10 + ((int)(inputLines[i][j])) - 48;
                                j++;
                            }

                            printf("\n::> Or Introduction - Mode %d - Line %d", introductionMode, lineNo);

                            /**
                             * @brief In or introduction also we have 2 modes, one for left introduction
                             * and one for right introduction
                             *
                             */
                            if (introductionMode == 1)
                            {
                                /**
                                 * @brief Here we go until the current line ends
                                 * and keep comparing i.e. if we have a and we want (avb)
                                 * using or introduction we compare from start till the
                                 * smaller string ends
                                 *
                                 */
                                int orFinder = 0;
                                int validity = 1;

                                while (statements[lineNo - 1][orFinder] != '\0')
                                {
                                    if (statements[i][orFinder] != statements[lineNo - 1][orFinder - 1])
                                        validity = 0;
                                    orFinder++;
                                }

                                validity == 1 ? printf("--> VALID\n") : printf("--> INVALID\n");
                            }
                            else if (introductionMode == 2)
                            {
                                /**
                                 * @brief Here we loop until the bigger line goes to the start
                                 * and keep comparing i.e. if we have b and (avb)(this is i)
                                 * using and elimination we compare from start till the
                                 * smaller string goes to the start
                                 *
                                 */
                                int orFinderForEliminatedString = strlen(statements[lineNo - 1]) - 1;
                                int orFinderForFullString = strlen(statements[i]) - 2;

                                int validity = 1;

                                while (orFinderForEliminatedString >= 0)
                                {
                                    if (statements[i][orFinderForFullString] != statements[lineNo - 1][orFinderForEliminatedString])
                                        validity = 0;
                                    orFinderForEliminatedString--;
                                    orFinderForFullString--;
                                }

                                validity == 1 ? printf("--> VALID\n") : printf("--> INVALID\n");
                            }
                        }
                    }
                    /**
                     * @brief Construct a new if object for >
                     *
                     */
                    else if (inputLines[i][j] == '>')
                    {
                        j++;
                        if (inputLines[i][j] == 'e')
                        {
                            // Go forward to find the line numbers
                            j += 2;

                            int lineNo1 = 0;
                            while (inputLines[i][j] != '/')
                            {
                                lineNo1 = lineNo1 * 10 + ((int)(inputLines[i][j])) - 48;
                                j++;
                            }
                            j++;
                            int lineNo2 = 0;
                            while (((int)inputLines[i][j]) > 48 && ((int)inputLines[i][j]) < 58)
                            {
                                lineNo2 = lineNo2 * 10 + ((int)(inputLines[i][j])) - 48;
                                j++;
                            }
                            printf("\n::> Implication Elimination - Lines %d %d ", lineNo1, lineNo2);

                            char inputForStrCat[max];
                            inputForStrCat[0] = '(';
                            strcmp(statements[lineNo1 - 1], strcat(inputForStrCat, strcat(strcat(strcat(statements[lineNo2 - 1], ">"), statements[i]), ")"))) == 0 ? printf("--> VALID\n") : printf("--> INVALID\n");
                        }
                    }
                    else if(inputLines[i][j] == 'M'){
                        j++;
                        if (inputLines[i][j] == 'T')
                        {
                            // Go forward to find the line numbers
                            j += 2;

                            int lineNo1 = 0;
                            while (inputLines[i][j] != '/')
                            {
                                lineNo1 = lineNo1 * 10 + ((int)(inputLines[i][j])) - 48;
                                j++;
                            }
                            j++;
                            int lineNo2 = 0;
                            while (((int)inputLines[i][j]) > 48 && ((int)inputLines[i][j]) < 58)
                            {
                                lineNo2 = lineNo2 * 10 + ((int)(inputLines[i][j])) - 48;
                                j++;
                            }
                            printf("\n::> MT - Lines %d %d ", lineNo1, lineNo2);
                        }
                    }
                }

                j++;
            }
        }
    }
}