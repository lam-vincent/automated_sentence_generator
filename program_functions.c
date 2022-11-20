#include <stdio.h>
#include"stdlib.h"
#include "program_functions.h"
#include "tree.h"
#include "string.h"
#include "node.h"
#include "file_management.h"

void sentence_model(int* choice)
{
    printf("Select a model:\n");
    printf("\t1.{NOM} {ADJ} {VER} {NOM}\n");
    printf("\t2.{NOM} 'qui' {VER} {VER} {NOM} {ADJ}\n");
    printf("\t3.{VER} {ADV} {NOM} 'c'est comme' {VER} {NOM} {ADV}\n");
    
    do
    {
        scanf("%d", choice);
    } while (*choice < 1 || *choice > 3);
    
}


char* random_noun(NODE* node, char* code_1, char* code_2, int* sep_code_ls)
{
    int random = rand()%node->current_flechies_size;
    int random2 = rand()%node->flechies[random]->nb_code;
    char code[50];
    strcpy(code, node->flechies[random]->code[random2]);
    char**sep_code = code_separator_plus(code, sep_code_ls);
    strcpy(code_1, sep_code[0]);
    strcpy(code_2, sep_code[1]);
    return node->flechies[random]->forme;
}


char* accord_adj(NODE* word, char* sep_code_1, char* sep_code_2)
{
    int i = 0;
    bool found = false;
    while(i<word->current_flechies_size && !found)
    {
        int j =0;
        while(j<word->flechies[i]->nb_code && (  strstr(word->flechies[i]->code[j], "InvGen")==NULL && strstr(word->flechies[i]->code[j], sep_code_1)==NULL  || strstr(word->flechies[i]->code[j], sep_code_2)==NULL ))
           { j++;
           }
        if(j==word->flechies[i]->nb_code)
            i++;
        else
            found = true;
    }
    if(!found)
        {
            char* concat = (char*)malloc(50*sizeof(char));
            strcpy(concat,word->flechies[0]->base);
            strcat(concat,"*");
            return concat;
        }
    else
    {
        return word->flechies[i]->forme;
    }
}


char* accord_verb(NODE* word, char* sep_code_2)
{
    int i = 0;
    bool found = false;
    while(i<word->current_flechies_size && !found)
    {
        int j =0;
        while(j<word->flechies[i]->nb_code && (  strstr(word->flechies[i]->code[j], "P3")==NULL || strstr(word->flechies[i]->code[j], sep_code_2)==NULL ))
           { j++;
           }
        if(j==word->flechies[i]->nb_code)
            i++;
        else
            found = true;
    }
    if(!found)
        {
            char* concat = (char*)malloc(50*sizeof(char));
            strcpy(concat,word->flechies[0]->base);
            strcat(concat,"*");
            return concat;
        }
    else
    {
        return word->flechies[i]->forme;
    }
}


void search_from_base(TREE ***dico_tree)
{
    char word[100];
    printf("Which base do you want to search ?\n");
    scanf("%s", &word);
    if(word[0] < 'a' || word[0]>'z')
    {
        printf("Words only contain lowercase letters.\n");
        while (word[0] < 'a' || word[0]>'z')
        {
            scanf("%s", &word);
        }
        
    }
    NODE **found = search_to_end_dico_tree(word, dico_tree);
    if (found[0] == NULL && found[1] == NULL && found[2] == NULL && found[3] == NULL)
    {
        printf("The base doesn't exist.\n");
    }
    else
    {
        printf("Here are all the form corresponding to the given base :\n");
        for(int j = 0; j<4;j++)
        {
            if(found[j]!=NULL)
            {
                for (int i = 0; i < found[j]->current_flechies_size; i++)
                {
                    printf("%s\n", found[j]->flechies[i]->forme);
                }
                printf("\n");
            }
        }
    }
}


void search_from_flechies(TREE*** dico_tree)
{
    char word[100];
    printf("Which word do you want to search ?\n");
    scanf("%s", &word);
    if(word[0] < 'a' || word[0]>'z')
    {
        printf("Words only contain lowercase letters.\n");
        while (word[0] < 'a' || word[0]>'z')
        {
            scanf("%s", &word);
        }
    }
    NODE **found = search_to_end_flechies_dico_tree(word, dico_tree);
    if (found[0] == NULL && found[1] == NULL && found[2] == NULL && found[3] == NULL)
    {
        printf("This word doesn't exist in the trees.\n");
    }
    else//TEMPORARY CHANGE IT AFTER CODE INTERPRETATION IS CREATED
    {
        printf("Informations:\n");
        for(int j = 0; j<4;j++)
        {
            if(found[j]!=NULL)
            {
                int i =0;
                while (strcmp(found[j]->flechies[i]->forme,word)!=0)
                {
                    i++;
                }
                printf("word: %s\ntype: ", word);
                switch (j)
                {
                case 0:
                    printf("Verb\n");
                    break;
                case 1:
                    printf("Noun\n");
                    break;
                case 2:
                    printf("Adjective\n");
                    break;
                case 3:
                    printf("Adverb\n");
                    break;
                default:
                    break;
                }
                printf("code: || ");
                if(j==3)
                    printf("none ||");
                else
                {
                char code[20];
                char** sep_code;
                int sep_code_ls;
                for(int k=0; k< found[j]->flechies[i]->nb_code; k++)
                {
                    strcpy(code, found[j]->flechies[i]->code[k]);
                    sep_code = code_separator_plus(code, &sep_code_ls);
                    for(int z=0; z<sep_code_ls;z++)
                        printf("%s ", sep_code[z]);
                    printf("|| ");
                }
                }
                printf("\n\n");
            }
        }
    }
}