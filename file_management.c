#include "node.h"
#include "tree.h"
#include  "file_management.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

//Removes th \n that's at the end of every line
void remove_end_line(char* line)
{
    int length = strlen(line);
    line[length-1] = line[length];
    return;
}

//Separate a line in 3 strings
char** line_separator(char* line)
{
    char** separated_line = (char**)malloc(sizeof(char*)*3);
    separated_line[0] = strtok(line, "\t");
    for (size_t i = 1; i < 3; i++)
    {
        separated_line[i] = strtok(NULL, "\t");
    }
    
    return separated_line;
}

char** code_separator_collin(char*full_code, int*i)
{
    char** separated_code = (char**)malloc(sizeof(char*));
    char* tmp = strtok(full_code,":");
    *i = 0;
    while (tmp != NULL)
    {
        separated_code = (char**)realloc(separated_code, sizeof(char*)*(*i+1));
        separated_code[(*i)++] = tmp;
        tmp = strtok(NULL, ":");
    }
    
    return separated_code;
}
//separate codes into different strings
char** code_separator_plus(char*full_code, int* i)
{
    char** separated_code = (char**)malloc(sizeof(char*));
    char* tmp = strtok(full_code,"+");
    *i = 0;
    while (tmp != NULL)
    {
        separated_code = (char**)realloc(separated_code, sizeof(char*)*(*i+1));
        separated_code[(*i)++] = tmp;
        tmp = strtok(NULL, "+");
    }
    
    return separated_code;
}

//Indicates wether or not a word is flechie
bool is_flechie(char** sep_line)
{
    return  !(!strcmp(sep_line[0], sep_line[1]) && !strcmp(sep_line[1], sep_line[0]));
}

