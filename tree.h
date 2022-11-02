#ifndef UNTITLED_TREE_H
#define UNTITLED_TREE_H

#include "node.h"
#include "file_management.h"

typedef struct s_tree
{
	NODE *root;
} TREE;

// nos prototypes
void display_tree(TREE tree);

#endif