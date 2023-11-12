#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE *file;
    int i = 0;
    char c;
    char* result = NULL;

    file = fopen("message02.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    result = malloc(sizeof(char));
    if (result == NULL)
    {
        printf("Error allocating memory\n");
        fclose(file);
        return 1;
    } 

    while (1)
    {
        c = fgetc(file);
        if (c == EOF)
        {
            break;
        }
        
        switch (c)
        {
            case '#':
                i += 1;
                break;
            case '@':
                i -= 1;
                break;
            case '*':
                i *= i;
                break;
            case '&':
                {
                    char temp[sizeof(int)];
                    snprintf(temp, sizeof(temp), "%d", i);
                    
                    result = realloc(result, strlen(result) + strlen(temp) + 1);    
                    if (result == NULL)
                    {
                        printf("Error reallocating memory\n");
                        fclose(file);
                        return 1;
                    }

                    strncat(result, temp, sizeof(int));
                }
                break;
        }
        
    }

    fclose(file);
    printf("Result: %s\n", result);
    free(result);

    return 0;
}