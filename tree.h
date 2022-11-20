#ifndef UNTITLED_TREE_H
#define UNTITLED_TREE_H

#include "node.h"
#include "file_management.h"


typedef struct s_tree
{
	NODE* root;
}TREE;

// nos prototypes

TREE** create_array_tree();
TREE*** create_dico_trees();
NODE* rand_go_to_end(TREE** word_type);
void create_tree_from_dico(TREE*** dico_tree, char**sep_line);
NODE*search_to_end_tree(char* word,TREE**type_tree);
NODE** search_to_end_dico_tree(char* word, TREE*** dico_tree);
NODE* search_to_end_flechies_tree(char* word,TREE** type_tree);
NODE** search_to_end_flechies_dico_tree(char* word, TREE*** dico_tree);
#endif