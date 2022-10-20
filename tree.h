#ifndef UNTITLED_TREE_H
#define UNTITLED_TREE_H

#include "node.h"

typedef struct s_tree
{
    p_node root;
} t_tree, *p_tree;

// vos prototypes

int treeHeight(t_tree t);
// int count(t_tree *tree);
int isPerfectRec(p_node pn, int d, int level);
int isPerfectTree(t_tree);
int isDegeneratedTreeRec(p_node pn);
int isDegeneratedTree(t_tree);

// pour utiliser l'affichage d'arbres
#define LINE_SIZE 1024
#define MAX_NB_LINES 24

int _print_t(p_node, int, int, int, char s[MAX_NB_LINES][LINE_SIZE]);
void print_t(p_node);
void displayTree(t_tree);

t_tree createEmptyTree();
#endif