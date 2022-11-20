#include <stdio.h>
#include"stdlib.h"
#include "program_functions.h"
#include "tree.h"
#include "string.h"
#include "node.h"
#include "file_management.h"

//Initialization of the 3 different models
char*** load_models()
{
    char** model_1 = (char**)malloc(4*sizeof(char*));
    model_1[0] = "Nom"; model_1[1] = "Adj"; model_1[2] = "Ver"; model_1[3] = "Nom"; 

    char** model_2 = (char**)malloc(5*sizeof(char*));
    model_2[0] = "Nom"; model_2[1] = "Ver"; model_2[2] = "Ver"; model_2[3] = "Nom"; model_2[4]="Adj";

    char** model_3 = (char**)malloc(6*sizeof(char*));
    model_3[0] = "Ver"; model_3[1] = "Adv"; model_3[2] = "Nom"; model_3[3] = "Ver"; model_3[4]="Nom"; model_3[5]="Adv"; 

    char*** models = (char***)malloc(3*sizeof(char**));
    models[0]=model_1;
    models[1]=model_2;
    models[2]=model_3;
    return models;
}

//Generation menu
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

//Chooses a random form of a noun stored in node. Stores codes of the form
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

//Accords an Adjective to its noun
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

//Accords a verb to its subject
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

//Reserch among bases
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
        printf("\nThe base doesn't exist.\n\n");
    }
    else
    {
        printf("\nHere are all the form corresponding to the given base :\n");
        for(int j = 0; j<4;j++)
        {
            if(found[j]!=NULL)
            {
                switch (j)
                {
                case 0:
                    printf("Verb:\n");
                    break;
                case 1:
                    printf("Noun:\n");
                    break;
                case 2:
                    printf("Adjective:\n");
                    break;
                case 3:
                    printf("Adverb:\n");
                    break;
                default:
                    break;
                }
                for (int i = 0; i < found[j]->current_flechies_size; i++)
                {
                    printf("| %s ", found[j]->flechies[i]->forme);
                }
                printf("|\n\n");
            }
        }
    }
}


//Research among flechies
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
        printf("\nThis word doesn't exist in the trees.\n\n");
    }
    else
    {
        printf("\nInformations:\n");
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