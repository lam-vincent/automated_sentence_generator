#include "node.h"
#include "tree.h"
#include  "file_management.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
#include "time.h"
#include "program_functions.h"

int main()
{
    srand(time(NULL));
    TREE*** dico_tree = create_dico_trees();
    TREE** Verb = dico_tree[0];
    TREE** Nom = dico_tree[1];
    TREE** Adj = dico_tree[2];
    TREE** Adv = dico_tree[3];
    FILE* DICO = fopen("dictionnaire_non_accentue.txt", "r");
    char line[255];
    int i =0;

    while(fgets(line,255, DICO) != NULL)
    {
        remove_end_line(line);
        char** sep_line = line_separator(line);
        create_tree_from_dico(dico_tree, sep_line);
        i++;
    }
    fclose(DICO);
    char* model_1[]= {"Nom", "Adj", "Ver", "Nom"};
    char* model_2[]= {"Nom", "Ver", "Ver", "Nom", "Adj"};
    char* model_3[]= {"Ver", "Adv", "Nom", "Ver", "Nom", "Adv"};
    char*** models = (char***)malloc(3*sizeof(char**));
    models[0]=model_1;
    models[1]=model_2;
    models[2]=model_3;

    bool run = true;
    while(run)
    {
        int choice;
        printf("Welcome!\n\t1.Randomly generated sentences (bases)\n\t2.Randomly generated sentences (conjugated)\n\t3.Research from base\n\t4.Research from flechies\n\t\t0.Exit\n");
        do
        {
            scanf("%d", &choice);
        } while (choice<0 || choice > 4);
        switch (choice)
        {
            case 0:
            {
                run = false;
                printf("Bye!");
                break;
            }
            case 1:
            {
                sentence_model(&choice);
                char** model = models[choice-1];
                int ls_model = 3+ choice;
                for(int i =0; i<ls_model;i++)
                {
                    if(i == 1 && choice == 2)
                        printf("qui ");
                    else if (i == 3 && choice ==3)
                        printf("c'est comme ");
                NODE* word = rand_go_to_end(dico_tree[transfer_type(model[i])]);
                printf("%s ", word->flechies[0]->base);
                }
                printf("\n\n");
                break;
            }
            case 2:
            {
                sentence_model(&choice);
                printf("Missing flechies are noted by '*':\n\n");
                char** model = models[choice-1];
                int ls_model = 3+ choice;
                char sep_code_1[20];
                char sep_code_2[20];
                int sep_code_ls;
                for(int i =0; i<ls_model;i++)
                {
                    if(i == 1 && choice == 2)
                        printf("qui ");
                    else if (i == 3 && choice ==3)
                        printf("c'est comme ");
                NODE* word = rand_go_to_end(dico_tree[transfer_type(model[i])]);
                    if(choice==3)
                    {
                       switch (transfer_type(model[i]))
                        {
                        case 1:
                            {
                                char* noun = random_noun(word, sep_code_1, sep_code_2, &sep_code_ls);
                                
                                if(strcmp("SG", sep_code_2)!=0)
                                    printf("des %s ", noun);
                                else if(strcmp("Fem", sep_code_1)==0)
                                    printf("une %s ", noun);
                                else
                                    printf("un %s ", noun);

                                break;
                            }
                        
                        default:
                            {
                                printf("%s ", word->flechies[0]->base);
                                break;
                            }
                        }
                    }
                    else
                    {
                        switch (transfer_type(model[i]))
                        {
                        case 1:
                            {
                                 char* noun = random_noun(word, sep_code_1, sep_code_2, &sep_code_ls);
                                
                                if(strcmp("SG", sep_code_2)!=0)
                                    printf("des %s ", noun);
                                else if(strcmp("Fem", sep_code_1)==0)
                                    printf("une %s ", noun);
                                else
                                    printf("un %s ", noun);

                                break;
                            }
                        
                        case 2:
                            {
                                printf("%s ",accord_adj(word, sep_code_1, sep_code_2));
                                break;
                            }
                        default:
                        {
                            printf("%s ", accord_verb(word, sep_code_2));
                            break;
                        }
                        }
                    }
                }
                printf("\n\n");
                break;
            }
            case 3:
            {
                search_from_base(dico_tree);
                break;
            }
            case 4:
            {
                search_from_flechies(dico_tree);
                break;
            }
            default:
                break;
        }
    }
    return 0;
}