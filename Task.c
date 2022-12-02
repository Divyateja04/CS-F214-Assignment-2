// For scanning and printing data
#include <stdio.h>
// For using string functions
#include <string.h>

/**
 * @brief Define a constant to change max length of input
 *
 */
#define max 100000

/**
 * @brief AND INTRODUCTION
 *
 * @param inputLines is the inputLine exactly
 * @param statements is the statement i.e. without the rule
 * @param i line number
 * @param j character number
 */
int andIntroduction(char inputLines[max][max], char statements[max][max], int i, int j)
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

    char inputForStrCat[max];
    inputForStrCat[0] = '(';
    int newStatementTracker = 1;
    for (int m = 0; m < strlen(statements[lineNo1 - 1]); m++)
    {
        inputForStrCat[newStatementTracker] = statements[lineNo1 - 1][m];
        newStatementTracker++;
    }
    inputForStrCat[newStatementTracker++] = '^';
    for (int m = 0; m < strlen(statements[lineNo2 - 1]); m++)
    {
        inputForStrCat[newStatementTracker] = statements[lineNo2 - 1][m];
        newStatementTracker++;
    }
    inputForStrCat[newStatementTracker] = ')';
    printf("\n::> Comparing %s and %s", statements[i], inputForStrCat);
    return strcmp(statements[i], inputForStrCat) == 0;
}

/**
 * @brief AND ELIMINATION
 * Here also we have two cases
 * If it's and elimination 1,
 * Here we loop until the bigger line goes to the start
 * and keep comparing i.e. if we have (a^b) and we get b(this is i)
 * using and elimination we compare from start till the
 * smaller string goes to the start
 *
 * Otherwise, case 2
 * Here we go until the current line ends
 * and keep comparing i.e. if we have (a^b) and we get a
 * using and elimination we compare from start till the
 * smaller string ends
 *
 * @param inputLines is the inputLine exactly
 * @param statements is the statement i.e. without the rule
 * @param i line number
 * @param j character number
 */
int andElimination(char inputLines[max][max], char statements[max][max], int i, int j)
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

    // @brief Here lineNo-1 gives the sentence from which we are eliminating
    // and i gives the one after elimination
    if (eliminationMode == 1)
    {
        int andFinder = 0;
        int validity = 1;

        while (statements[i][andFinder] != '\0')
        {
            // printf("\n%c %c", statements[lineNo - 1][andFinder+1], statements[i][andFinder]);
            if (statements[lineNo - 1][andFinder + 1] != statements[i][andFinder])
                validity = 0;
            andFinder++;
        }

        return validity == 1;
    }
    else if (eliminationMode == 2)
    {

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

        return validity == 1;
    }
}

/**
 * @brief OR INTRODUCTION
 * In or introduction also we have 2 modes, one for left introduction
 * and one for right introduction
 *
 * If mode is 1, Here we go until the current line ends
 * and keep comparing i.e. if we have a and we want (avb)
 * using or introduction we compare from start till the
 * smaller string ends
 *
 * If mode is 2
 * Here we loop until the bigger line goes to the start
 * and keep comparing i.e. if we have b and (avb)(this is i)
 * using and elimination we compare from start till the
 * smaller string goes to the start
 *
 * @param inputLines is the inputLine exactly
 * @param statements is the statement i.e. without the rule
 * @param i line number
 * @param j character number
 */
int orIntroduction(char inputLines[max][max], char statements[max][max], int i, int j)
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

        if (introductionMode == 1)
        {
            int orFinder = 0;
            int validity = 1;

            while (statements[lineNo - 1][orFinder] != '\0')
            {
                if (statements[i][orFinder + 1] != statements[lineNo - 1][orFinder])
                    validity = 0;
                orFinder++;
            }

            return validity == 1;
        }
        else if (introductionMode == 2)
        {
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

            return validity == 1;
        }
    }
}

/**
 * @brief IMPLICATION ELIMINATION
 * Here if i is the current line which is a
 * and lineNo1 gives is (a>b) and lineNo2 gives b
 * We make the string (a>b) and compare it with (a>b)
 *
 * @param inputLines is the inputLine exactly
 * @param statements is the statement i.e. without the rule
 * @param i line number
 * @param j character number
 */
int implicationElimination(char inputLines[max][max], char statements[max][max], int i, int j)
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

        char inputForElStrCat[max];
        inputForElStrCat[0] = '(';
        int elNewStatementTracker = 1;
        for (int m = 0; m < strlen(statements[lineNo2 - 1]); m++)
        {
            inputForElStrCat[elNewStatementTracker] = statements[lineNo2 - 1][m];
            elNewStatementTracker++;
        }
        inputForElStrCat[elNewStatementTracker++] = '>';
        for (int m = 0; m < strlen(statements[i]); m++)
        {
            inputForElStrCat[elNewStatementTracker] = statements[i][m];
            elNewStatementTracker++;
        }
        inputForElStrCat[elNewStatementTracker] = ')';
        printf("\n::> Comparing %s and %s", statements[lineNo1 - 1], inputForElStrCat);
        return strcmp(statements[lineNo1 - 1], inputForElStrCat) == 0;
    }
}

/**
 * @brief MODUS TOLLENS
 * Here if i is the current line which is (~a)
 * and lineNo1 gives is a>b and lineNo2 gives (~b)
 *
 * @param inputLines is the inputLine exactly
 * @param statements is the statement i.e. without the rule
 * @param i line number
 * @param j character number
 */
int MT(char inputLines[max][max], char statements[max][max], int i, int j)
{
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

        char temporaryInput[max];
        temporaryInput[0] = '(';
        int counter = 0;
        int temp = 1;
        while (statements[i][counter + 3] != '\0')
        {
            temporaryInput[temp] = statements[i][counter + 2];
            counter++;
            temp++;
        }
        temporaryInput[temp] = '>';
        temp++;
        counter = 0;
        while (statements[lineNo2 - 1][counter + 3] != '\0')
        {
            temporaryInput[temp] = statements[lineNo2 - 1][counter + 2];
            counter++;
            temp++;
        }
        temporaryInput[temp] = ')';

        return strcmp(temporaryInput, statements[lineNo1 - 1]) == 0;
    }
}

int main()
{
    /**
     * @brief Create a file pointer to open the text file
     *
     */
    FILE *file = fopen("./Inputs/and.txt", "r");

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

    // Getting input into the array of strings
    for (int i = 0; i < noOfLines; i++)
    {
        fgets(inputLines[i], max, file);
    }

    // Part 1: Analyzing Input, We have 2 Possibilities
    // If last character is P it is a premise, Otherwise it's a statement

    int proofValidity = 1;

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

            // Here we are waiting until the end of the sentence
            while (inputLines[i][j] != '\0')
            {
                // Once it reaches the first slash
                if (inputLines[i][j] == '/')
                {
                    j++; // Move forward and skip one character

                    if (inputLines[i][j] == '^')
                    {
                        j++;
                        // We check if it's Introduction or Elimination
                        if (inputLines[i][j] == 'i')
                        {
                            if (andIntroduction(inputLines, statements, i, j) == 1)
                            {
                                printf("--> VALID");
                            }
                            else
                            {
                                printf("--> INVALID");
                                proofValidity = 0;
                            }
                        }
                        else if (inputLines[i][j] == 'e')
                        {
                            andElimination(inputLines, statements, i, j);
                        }
                    }
                    else if (inputLines[i][j] == 'v')
                    {
                        if (orIntroduction(inputLines, statements, i, j) == 1)
                        {
                            printf("--> VALID");
                        }
                        else
                        {
                            printf("--> INVALID");
                            proofValidity = 0;
                        }
                    }
                    else if (inputLines[i][j] == '>')
                    {
                        if (implicationElimination(inputLines, statements, i, j) == 1)
                        {
                            printf("--> VALID");
                        }
                        else
                        {
                            printf("--> INVALID");
                            proofValidity = 0;
                        }
                    }
                    else if (inputLines[i][j] == 'M')
                    {
                        if (MT(inputLines, statements, i, j) == 1)
                        {
                            printf("--> VALID");
                        }
                        else
                        {
                            printf("--> INVALID");
                            proofValidity = 0;
                        }
                    }
                }
                j++;
            }
            if (proofValidity == 1)
            {
                printf("\n\nTHE PROOF IS VALID");
            }
            else
            {
                printf("\n\nTHE PROOF IS INVALID");
            }
        }
    }
}