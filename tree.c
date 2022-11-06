#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "node.h"
#include "file_management.h"

// Creates an array of pointers to trees
TREE **create_array_tree()
{
    TREE **new_tree = (TREE **)calloc(sizeof(TREE *), 26);
    for (int i = 0; i < 26; i++)
    {
        new_tree[i] = (TREE *)malloc(sizeof(TREE));
        new_tree[i]->root = createNode('a' + i, false);
    }
    return new_tree;
}

// Creates an array that stores the 4 types of trees
TREE ***create_dico_trees()
{
    TREE ***dico_tree = (TREE ***)malloc(sizeof(TREE **) * 4);
    for (int i = 0; i < 4; i++)
        dico_tree[i] = create_array_tree();
    return dico_tree;
}

// adds a line from the dico to the dico_tree
void create_tree_from_dico(TREE ***dico_tree, char **sep_line)
{
    char *type = get_type(sep_line);
    int type_tree;
    switch (type[2])
    {
    case 'r': // Ver
        type_tree = 0;
        break;
    case 'm': // Nom
        type_tree = 1;
        break;
    case 'j': // Adj
        type_tree = 2;
        break;
    case 'v': // Adv
        type_tree = 3;
        break;
    default:
        break;
    }
    create_word_node(dico_tree[type_tree][(int)sep_line[1][0] - 97]->root, sep_line, 0);
}

void display_tree(TREE tree)
{

    return;
}