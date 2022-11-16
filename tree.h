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
#endif