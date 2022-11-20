#include "node.h"
#include "tree.h"
#include  "file_management.h"
#include "program_functions.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
#include "time.h"

int main()
{
    srand(time(NULL));

    //Creation of tree from dictionnary
    printf("Creating trees from file...\n\n");
    TREE*** dico_tree = create_dico_trees();
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
    printf("Trees created!\n\n");

    //Loading models for sentece
    char*** models = load_models();

    //Loop for program
    bool run = true;
    while(run)
    {
        int choice;
        printf("Welcome!\n\t1.Randomly generated sentences (bases)\n\t2.Randomly generated sentences (conjugated)\n\t3.Research from a base\n\t4.Research from a flechie\n\t\t0.Exit\n");
        do
        {
            scanf("%d", &choice);
        } while (choice<0 || choice > 4);
        switch (choice)
        {
            //Exit program
            case 0:
            {
                run = false;
                printf("\nBye!\n\n");
                break;
            }
            //Randomly generated sentences with bases
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
            //Randomly generated conjugated sentences
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
                    //Model 3
                    if(choice==3)
                    {
                       switch (transfer_type(model[i]))
                        {
                        //Process nouns
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
                        //Process others
                        default:
                                printf("%s ", word->flechies[0]->base);
                                break;
                        
                        }
                    }
                    //Models 1 & 2
                    else
                    {
                        switch (transfer_type(model[i]))
                        {
                        //Process nouns
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
                        //Process adjectives
                        case 2:
                            printf("%s ",accord_adj(word, sep_code_1, sep_code_2));
                            break;
                        //Process verbs
                        default:
                            printf("%s ", accord_verb(word, sep_code_2));
                            break;
                        }
                    }
                }
                printf("\n\n");
                break;
            }
            //Reserch among bases
            case 3:
            {
                search_from_base(dico_tree);
                break;
            }
            //Research among flechies
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