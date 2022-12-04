#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readInputFile(void)
{
    FILE *textfile;
    char *text;
    long numbytes;
     
    textfile = fopen("input.txt", "r");
    fseek(textfile, 0L, SEEK_END);
    numbytes = ftell(textfile);
    fseek(textfile, 0L, SEEK_SET);  
 
    text = (char*)calloc(numbytes, sizeof(char));    
    fread(text, sizeof(char), numbytes, textfile);
    fclose(textfile);

    return text;
}

int outcome1(char a, char b)
{
    int result = 0;

    if(b == 'X')
    {
        result += 1;

        if(a == 'A')
        {
            result += 3;
        }
        else if(a == 'C')
        {
            result += 6;
        }
    }
    else if(b == 'Y')
    {
        result += 2;

        if(a == 'B')
        {
            result += 3;
        }
        else if(a == 'A')
        {
            result += 6;
        }
    }
    else if(b == 'Z')
    {
        result += 3;

        if(a == 'C')
        {
            result += 3;
        }
        else if(a == 'B')
        {
            result += 6;
        }
    }

    return result;
}

int outcome2(char a, char b)
{
    int result = 0;

    if(b == 'X')
    {
        if(a == 'A')
        {
            result += 3;
        }
        else if(a == 'B')
        {
            result += 1;
        }
        else if(a == 'C')
        {
            result += 2;
        }
    }
    else if(b == 'Y')
    {
        result += 3;

        if(a == 'A')
        {
            result += 1;
        }
        else if(a == 'B')
        {
            result += 2;
        }
        else if(a == 'C')
        {
            result += 3;
        }
    }
    else if(b == 'Z')
    {
        result += 6;
        
        if(a == 'A')
        {
            result += 2;
        }
        else if(a == 'B')
        {
            result += 3;
        }
        else if(a == 'C')
        {
            result += 1;
        }
    }
    
    return result;
}

int main(int argc, char *argv[]) 
{
    char *inputFile = readInputFile();
    char *token;
    int total = 0;
    
    token = strtok(inputFile, "\n");
    while(token != NULL)
    {
        char opponent = token[0];
        char you = token[2];

        total += outcome2(opponent, you);
        
        token = strtok(NULL, "\n");
    }

    printf("result %i", total);
    free(inputFile);

    return 0;
}

