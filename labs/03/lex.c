#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

int isKeyword(char ch)
{
    int i, flag = 0;
    char keywords[3] = {'i', 'f', 'p'};

    for (i = 0; i < 3; i++)
    {
        if (keywords[i] == ch)
        {
            flag = 1;
            break;
        }
    }

    return flag;
}

int main(int argc, char *argv[])
{
    char ch;
    char operators[] = {'+', '-', '*', '/', '='};
    FILE *fp;
    int i, j = 0;
    regex_t regex;
    int reti;

    // reti = regcomp(&regex, "^[0-9]*\.?[0-9]{0,5}$", 0);
    // if( reti ){ fprintf(stderr, "Could not compile regex\n"); exit(1); }

    fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        printf("Error opening the file\n");
        exit(0);
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        for (i = 0; i < 5; i++)
        {
            if (ch == operators[i])
            {
                if (ch == '+')
                {
                    printf("plus ");
                }
                else if (ch == '-')
                {
                    printf("minus ");
                }
                else if (ch == '*')
                {
                    printf("mult ");
                }
                else if (ch == '/')
                {
                    printf("div ");
                }
                else if (ch == '=')
                {
                    printf("assign ");
                }
            }
        }
        if (isalnum(ch))
        {
            if ((ch == ' ' || ch == '\n') && (j != 0))
            {
                continue;
            }
            if (isKeyword(ch) == 1)
            {
                if (ch == 'i')
                {
                    printf("intdcl ");
                }
                else if (ch == 'f')
                {
                    printf("floatdcl ");
                }
                else if (ch == 'p')
                {
                    printf("print ");
                }
            }
            else if (isdigit(ch)) {
                printf("num ");
            }
            
            else{
                printf("id ");
            }
        }
    }
    fclose(fp);
    return 0;
    
}