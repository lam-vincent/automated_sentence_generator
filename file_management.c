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

//separates codes by ":"
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
//separate codes by "+"
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

//Translate the type of a word from a string to an index for tha dico_tree
int transfer_type(char* type)
{
    int type_tree;
    if(strcmp(type,"Ver")==0)
            type_tree = 0;
        else if(strcmp(type,"Nom")==0)
            type_tree = 1;
        else if(strcmp(type, "Adj")==0)
            type_tree = 2;
        else if(strcmp(type, "Adv")==0)
            type_tree = 3;
        else
            type_tree = -1;
    return type_tree;
    }

//From a line returns the type of a word(verb,adj,adv or noun)
int get_type(char** sep_line)
{
    int cpt = strlen(sep_line[2])+1;
    char* tmp = (char*)malloc(cpt* sizeof(char));
    strcpy(tmp, sep_line[2]);
    code_separator_collin(tmp, &cpt);
    return transfer_type(tmp);
}
