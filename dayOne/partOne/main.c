#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define FILEREAD "archive.txt"
#define MAXSIZEREAD 4096

int countSumOfLine(const char *line, int *pointerCounter);

int main() 
{
    FILE *fPtr;
    char line[MAXSIZEREAD];
    int sum_of_all = 0, readLines = 0, *ptrReadLines = &readLines;

    fPtr = fopen(FILEREAD, "r");

    // reading lines and adding the value of each line to the sum of every line
    while(fgets(line, MAXSIZEREAD, fPtr))
        sum_of_all += countSumOfLine(line, ptrReadLines);
    
    printf("Quantity of read lines: %d\n", *ptrReadLines);
    printf("Sum of all lines: %d\n", sum_of_all);
    fclose(fPtr);
    return 0;
}

int countSumOfLine(const char *line, int *pointerLineCounter)
{
    int first_number = 0, last_number, number_obtained;
    int i = 0;
    char charac, str_number[3];

    while(1)
    {
        charac = line[i];

        if(isdigit(charac))
        {
            if(first_number == 0)
                first_number = charac - 48;

            last_number = charac - 48;
            //printf("it's a digit: %d\n", charac - 48);
        }    

        if(charac == '\n' || charac == '\0')
        {
            str_number[0] = first_number + '0';
            str_number[1] = last_number + '0';
            str_number[2] = '\n';
            number_obtained = atoi(str_number);

            *pointerLineCounter += 1;
            printf("Line read: %s", line);
            //printf("Quantity of lines read: %d\n", *pointerLineCounter);
            //printf("First number: %d\tLast number: %d\n", first_number, last_number);
            //printf("number obtained in this line: %d\n", number_obtained);

            return number_obtained;
        }

        i++;
    }
}