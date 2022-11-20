#ifndef UNTITLED_PROGRAM_FUNCTIONS_H
#define UNTITLED_PROGRAM_FUNCTIONS_H

#include "stdio.h"
#include "stdlib.h"
#include "node.h"
#include "file_management.h"
#include "tree.h"


char*** load_models();
void sentence_model(int* choice);
void search_from_base(TREE ***dico_tree);
void search_from_flechies(TREE*** dico_tree);
char* random_noun(NODE* node,char*, char*, int* sep_code_ls);
char* accord_adj(NODE* word, char* sep_code, char*);
char* accord_verb(NODE* word, char* sep_code_2);


#endif