#ifndef UNTITLED_FILE_MANAGEMENT_H
#define UNTITLED_FILE_MANAGEMENT_H

//#define DICO_NAME "mini_dico.txt"


void remove_end_line(char* line);
char** line_separator(char* line);
char** code_separator_collin(char*full_code, int* i);
char** code_separator_plus(char*full_code, int* i);
bool is_flechie(char** sep_line);

char* get_type(char** sep_line);



#endif