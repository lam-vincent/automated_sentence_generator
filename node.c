#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include <stdbool.h>
#include "file_management.h"

// Creates a node
NODE *createNode(char letter, bool is_end_of_word)
{
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    newnode->letter = letter;
    newnode->next = NULL;
    newnode->next_current_size = 0;
    // newnode->is_end = is_end_of_word;
    // newnode->flechies = NULL;
    // newnode->current_flechies_size = 0;
    // if (is_end_of_word)
    // {
    //     // add_flechies();
    // }
    return newnode;
}

// Updates array of sons
void update_next_array(NODE *previous)
{
    if (previous->next == NULL)
        previous->next = (NODE **)calloc(sizeof(NODE *), 1);
    else
    {
        previous->next = (NODE **)realloc(previous->next, sizeof(NODE *) * (previous->next_current_size + 1));
    }
    return;
}

// Add a new node to a tree
void add_node(NODE *previous, char letter, bool is_end_of_word)
{
    NODE *new = createNode(letter, is_end_of_word);
    update_next_array(previous);
    previous->next[previous->next_current_size++] = new;
    return;
}

// Goes to the last letter of a base and return the pointer to that node.
// If it has yet to be added, adds it
NODE *end_of_word(NODE *node, char *base, int cpt)
{
    if (base[cpt + 1] == '\0')
        return node;
    int i = 0;
    while (i < node->next_current_size && node->next[i]->letter != base[cpt + 1])
        i++;
    if (i == node->next_current_size)
        add_node(node, base[cpt + 1], base[cpt + 2] == '\0');
    end_of_word(node->next[i], base, cpt + 1);
}

// Adds all flechie forms to a node
void add_flechies(NODE *node, char **sep_line)
{

    /*
    cas flechies_size =0:
    malloc et size++
    autre cas:
    realloc et size++

    ajouter forme (index:0)
    ajouter base (index: 1)
    ajouter code (d'abord vérifier si plusieurs code avec séparateur puis ajouter tous les codes):
        cas nb_code =0:
        malloc size++
        autre cas:
        realloc size++
    */
    return;
}
