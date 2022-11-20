#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "stdbool.h"
#include "string.h"
#include "file_management.h"

//Creates a node
NODE* createNode(char letter, bool is_end_of_word)
{
    NODE* new = (NODE*)malloc(sizeof(NODE));
    new->letter = letter;
    new->next = NULL;
    new->next_current_size = 0;
    new->is_end = is_end_of_word;
    new->flechies = NULL;
    new->current_flechies_size = 0;
    return new;
}

//creates a flechie form
FF* createFlechie(char** sep_line)
{
    FF* new = (FF*)malloc(sizeof(FF));
    new->forme = (char*)malloc(sizeof(char)*(strlen(sep_line[0])+1));
    strcpy(new->forme, sep_line[0]);
    new->base = (char*)calloc(sizeof(char),strlen(sep_line[1])+1);
    strcpy(new->base, sep_line[1]);
    int tmp_ls;
    char** tmp = code_separator_collin(sep_line[2], &tmp_ls);
    new->code = (char**)calloc(sizeof(char*), tmp_ls-1);
    for (int i = 1; i < tmp_ls; i++)
    {
        new->code[i-1] = (char*)calloc(sizeof(char), strlen(tmp[i])+1);
        strcpy(new->code[i-1],tmp[i]);
    }
    new->nb_code = tmp_ls-1;
    return new;
}

//Updates array of sons
void update_next_array(NODE* previous)
{
    if(previous->next == NULL)
        previous->next = (NODE**)calloc(sizeof(NODE*), 1);
    else{
        previous->next = (NODE**)realloc(previous->next, sizeof(NODE*)*(previous->next_current_size+1));
    }
    return;
}

//Updates array of flechie form pointers
void update_flechies_array(NODE* node)
{
    if(node->flechies == NULL)
        node->flechies = (FF**)calloc(sizeof(FF*), 1);
    else
        node->flechies = (FF**)realloc(node->flechies, sizeof(FF*)*(node->current_flechies_size+1));
    return;
}

//Add a new node to a tree
void add_node(NODE* previous, char letter, bool is_end_of_word)
{
    NODE* new = createNode(letter, is_end_of_word);
    update_next_array(previous);
    previous->next[previous->next_current_size++] = new;
    return;
}

//Adds base of a word then add the form at the end
//If base has already been added, goes to the end and adds the new form
void create_word_node(NODE* node, char** sep_line, int cpt)
{
    char* base = sep_line[1];
    if (base[cpt+1] == '\0')
        {
            add_flechies(node,sep_line);
            node->is_end = true;
            return;
        }
    int i = 0;
    while(i < node->next_current_size && node->next[i]->letter != base[cpt+1])
        i++;
    if(i == node->next_current_size)
    {
        add_node(node, base[cpt+1], base[cpt+2] == '\0');
    }
    create_word_node(node->next[i], sep_line, cpt+1);
}

//Goes to the end of a given base
NODE* rand_go_to_end_node(NODE* node)
{
    int random;
    
    if (node->is_end)
        {
            random = rand()%2;
            if(node->next_current_size == 0 || random){
                return node;}
            else
            {
                random = rand()%node->next_current_size;
                return rand_go_to_end_node(node->next[random]);
            }
        }
    else
        {
            
            random = rand()%node->next_current_size;
            return rand_go_to_end_node(node->next[random]);
        }
}

//Adds all flechie forms to a node
void add_flechies(NODE* node, char** sep_line)
{

    
        FF* new = createFlechie(sep_line);
        update_flechies_array(node);
        node->flechies[node->current_flechies_size++] = new;
    
    return;
}

//NEVER USED
bool is_leaf(NODE* node)
{
    return node->next_current_size == 0;
}
//NEVER USED
NODE* go_to_end(NODE* node, char** sep_line, int cpt)
{
    char* base = sep_line[1];
    if (base[cpt+1] == '\0')
        {
            return node;
        }
    int i = 0;
    while(i < node->next_current_size && node->next[i]->letter != base[cpt+1])
        i++;
    go_to_end(node->next[i], sep_line, cpt+1);
}


NODE* search_to_end(NODE* node, char* word, int cpt)
{
    if (word[cpt+1] == '\0' && node->is_end)
        {
            return node;
        }
    int i = 0;
    while(i < node->next_current_size && node->next[i]->letter != word[cpt+1])
        i++;
    if(i==node->next_current_size)
    {
        return NULL;
    }
    search_to_end(node->next[i], word, cpt+1);
}

NODE* search_to_end_flechies(NODE* node, char* word)
{
    if(node->is_end)
    {
        int i=0;
        while(i<node->current_flechies_size && strcmp(word,node->flechies[i]->forme)!=0)
            i++;
        if(i==node->current_flechies_size)
            {
                NODE* found;
                for (int i = 0; i < node->next_current_size; i++)
                {
                    found = search_to_end_flechies(node->next[i], word);
                    if(found != NULL)
                        return found;
                }
            }
        else
        {
            return node;
        }
            
    }
    else
    {
        NODE* found;
        for (int i = 0; i < node->next_current_size; i++)
        {
            found = search_to_end_flechies(node->next[i], word);
            if(found != NULL)
                return found;
        }
    
    }
    return NULL;

}   