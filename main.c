#include "node.h"
#include "tree.h"
#include  "file_management.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

int main()
{
/*
    TREE* verb;
    verb->root = createNode('A', false);
    add_node(verb->root, 'B', false);
    add_node(verb->root->next[0], 'C', false);
    add_node(verb->root, 'D', false);
    printf("%c\n", verb->root->letter);
    printf("%c\n", verb->root->next[0]->letter);
    printf("%c\n", verb->root->next[0]->next[0]->letter);
    printf("%c\n", verb->root->next[1]->letter);
    char* string1 = "ABC"; char* string2 = "ADE";
    NODE* node1 = end_of_word(verb->root, string1, 0);
    NODE* node2 = end_of_word(verb->root, string2, 0);
    printf("It works: %c and %c\n", node1->letter, node2->letter);
*/

    /*FILE* DICO = fopen("mini_dico.txt", "r");
    char line[255];
    fgets(line,255, DICO);
    fgets(line,255, DICO);
    fgets(line,255, DICO);
    remove_end_line(line);
    char** sep_line = line_separator(line);
    for (size_t i = 0; i < 3; i++)
    {
        printf("%s\n", sep_line[i]);
    }

    get_type(sep_line);

    NODE* tmp = createNode('A', false, sep_line);
    printf("%c", tmp->letter);
    add_node(tmp, 'B', false, sep_line);
    printf("%c", tmp->next[0]->letter);
    add_node(tmp->next[0], 'C', true, sep_line);
    printf("%c\n", tmp->next[0]->next[0]->letter);
    NODE* node1 = tmp->next[0]->next[0]; 
    printf("%s\n", node1->flechies[0]->forme);
    printf("%s\n", node1->flechies[0]->base);
    for(int i =0; i<node1->flechies[0]->nb_code;i++)
    {
        printf("%s\n", node1->flechies[0]->code[i]);
    }
    
    TREE* verb;
    verb->root = 
    printf("%c\n", verb->root->next_current_size);
    printf("%c\n", verb->root->next[0]->letter);
   
   
    int cpt = strlen(sep_line[2])+1;
    char* tmp = (char*)malloc(cpt* sizeof(char));
    strcpy(tmp, sep_line[2]);

    add_flechies(node1, sep_line);
    printf("%s\n", node1->flechies[0]->forme);
    printf("%s\n", node1->flechies[0]->base);
    for(int i =0; i<node1->flechies[0]->nb_code;i++)
    {
        printf("%s\n", node1->flechies[0]->code[i]);
    }*/

    //printf("%s", tmp);

    /*int ls = 0;
    char** code = code_separator_collin(sep_line[2], &ls);
    for (size_t i = 0; i < ls; i++)
    {
        printf("%s\n", code[i]);
    } 
    printf("forme fléchie ?: %d\n", is_flechie(sep_line)); */
    TREE*** dico_tree = create_dico_trees();
    TREE** Verb = dico_tree[0];
    TREE** Nom = dico_tree[1];
    TREE** Adj = dico_tree[2];
    TREE** Adv = dico_tree[3];
    //printf("%c", Verb[(int)'o'-97]->root->letter);
    //for(int i =0; i<26;i++){
    //    printf("%c", Verb[i]->root->letter);
    //}
    FILE* DICO = fopen("mini_dico.txt", "r");
    char line[255];
    /*fgets(line,255, DICO);
    remove_end_line(line);
    char** sep_line = line_separator(line);
    for (size_t i = 0; i < 3; i++)
    {
        printf("%s\n", sep_line[i]);
    }
    NODE* tmp = create_tree_from_dico(Verb, sep_line);
    printf("\t%s\t", tmp->flechies[0]->forme);

    fgets(line,255, DICO);
    fgets(line,255, DICO);
    remove_end_line(line);
    sep_line = line_separator(line);
    tmp = create_tree_from_dico(Verb, sep_line);
    printf("\t%s\t", tmp->flechies[0]->forme);*/
    int i =0;
    while(i<10)
    {
        fgets(line,255, DICO);
        remove_end_line(line);
        char** sep_line = line_separator(line);
        create_tree_from_dico(dico_tree, sep_line);
        i++;
    }
    fclose(DICO);
    DICO = fopen("mini_dico.txt", "r");
    fgets(line,255, DICO);
    fgets(line,255, DICO);
    fgets(line,255, DICO);
    fgets(line,255, DICO);
    fgets(line,255, DICO);
    fgets(line,255, DICO);
    //fgets(line,255, DICO);
    remove_end_line(line);
    char** sep_line = line_separator(line);
    /*for (size_t i = 0; i < 3; i++)
    {
        printf("%s\n", sep_line[i]);
    }*/
    NODE*tmp=go_to_end(Verb['s'-97]->root,sep_line,0);

    for(i=0; i < tmp->current_flechies_size;i++)
    {
        printf("%s: ", tmp->flechies[i]->forme);
        for (int j = 0; j < tmp->flechies[i]->nb_code; j++)
        {
            printf("\t%s\t", tmp->flechies[i]->code[j]);
        }
        printf("\n");
    }
    return 0;
}