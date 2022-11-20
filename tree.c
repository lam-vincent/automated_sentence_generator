#include <stdio.h>
#include"stdlib.h"
#include "tree.h"
#include "node.h"
#include "file_management.h"


//Creates an array of pointers to trees
TREE** create_array_tree()
{
    TREE** new_tree = (TREE**)calloc(sizeof(TREE*),26);
    for(int i = 0; i<26;i++)
    {
        new_tree[i]=(TREE*)malloc(sizeof(TREE));
        new_tree[i]->root=createNode('a'+i,false);
    }
    return new_tree;
}

//Creates an array that stores the 4 types of trees
TREE*** create_dico_trees()
{
    TREE*** dico_tree = (TREE***)malloc(sizeof(TREE**)*4);
    for(int i=0; i<4;i++)
        dico_tree[i] = create_array_tree();
    return dico_tree;
}

//adds a line from the dico to the dico_tree
void create_tree_from_dico(TREE*** dico_tree, char**sep_line)
{
    int type_tree = get_type(sep_line);
    if(type_tree == -1)
        return;
    create_word_node(dico_tree[type_tree][(int)sep_line[1][0]-97]->root, sep_line, 0);
}

//Goes randomly to the end of a type of word
NODE* rand_go_to_end(TREE** word_type)
{
    int random = rand()%26;
    while(word_type[random]->root->next_current_size == 0)
        random = rand()%26;
    NODE* tmp = rand_go_to_end_node(word_type[random]->root);
    while(tmp->flechies[0]->base[1] == '\0')
        
        tmp = rand_go_to_end_node(word_type[random]->root);

    return tmp;
}

//Checks whether the base can be found in a given type_tree
//Returns NULL if it can't, a pointer to the last node of the word otherwise
NODE*search_to_end_tree(char* word,TREE**type_tree)
{
    int i = 0;
    NODE* found;
    
        found = search_to_end(type_tree[(int)word[0]-97]->root, word,0);
        
    return found;
}

//Returns the location of a given base among all type_trees
NODE** search_to_end_dico_tree(char* word, TREE*** dico_tree)
{
    NODE** found = (NODE**)malloc(4*sizeof(NODE*));
    for(int i = 0; i<4;i++)
    {
        found[i] = search_to_end_tree(word,dico_tree[i]);
    }
    return found;
}

//Checks whether the flechie can be found in a given type_tree
//Returns NULL if it can't, a pointer to the last node of the base that contains it otherwise
NODE* search_to_end_flechies_tree(char* word,TREE** type_tree)
{
    int i = 0;
    NODE* found;
    do
    {
        found = search_to_end_flechies(type_tree[i]->root, word);
        i++;
    } while (i<26 && found == NULL);
    return found;
}


//Returns the locations of a given flechie among all type_trees
NODE** search_to_end_flechies_dico_tree(char* word, TREE*** dico_tree)
{
    NODE** found = (NODE**)malloc(4*sizeof(NODE*));
    for(int i = 0; i<4;i++)
    {
        found[i] = search_to_end_flechies_tree(word,dico_tree[i]);
    }
    return found;
}