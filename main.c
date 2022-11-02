#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "node.h"
#include "tree.h"
#include "file_management.h"

int main()
{

    TREE *verb = (TREE *)malloc(sizeof(TREE));
    verb->root = createNode('A', false);
    add_node(verb->root, 'B', false);
    add_node(verb->root->next[0], 'C', false);
    add_node(verb->root, 'D', false);
    printf("%c\n", verb->root->letter);
    printf("%c\n", verb->root->next[0]->letter);
    printf("%c\n", verb->root->next[0]->next[0]->letter);
    printf("%c\n", verb->root->next[1]->letter);
    char *string1 = "ABC";
    char *string2 = "ADE";
    NODE *node1 = end_of_word(verb->root, string1, 0);
    NODE *node2 = end_of_word(verb->root, string2, 0);
    printf("It works: %c and %c\n", node1->letter, node2->letter);

    /*
        FILE* DICO = fopen("mini_dico.txt", "r");
        char line[255];
        fgets(line,255, DICO);
        printf("%s test\n", line);
        remove_end_line(line);
        printf("%s test\n", line);
        fgets(line,255, DICO);
        printf("%s test\n", line);
        remove_end_line(line);
        printf("%s test\n", line);
        char** sep_line = line_separator(line);
        for (size_t i = 0; i < 3; i++)
        {
            printf("%s\n", sep_line[i]);
        }
        int ls = 0;
        char** code = code_separator_collin(sep_line[2], &ls);
        for (size_t i = 0; i < ls; i++)
        {
            printf("%s\n", code[i]);
        }
        printf("forme fléchie ?: %d\n", is_flechie(sep_line)); */

    return 0;
}