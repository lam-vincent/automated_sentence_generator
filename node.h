#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H
#include "stdbool.h"

typedef struct forme_flechie
{
	char* forme;
	char* base;
	char** code;
    int nb_code;
}FF;

typedef struct s_node
{
	char letter;
	struct s_node** next ; //array of pointer
	int next_current_size ; //current size of this array
    bool is_end; //Indicates that a node is at the end of a base
	FF** flechies; //Array of every form that have the same base
    int current_flechies_size ; //Current size of this array
}NODE;


NODE* createNode(char letter, bool is_end_of_word);
FF* createFlechie(char** sep_line);
void update_next_array(NODE* previous);
void update_flechies_array(NODE* node);
void add_node(NODE* previous, char letter, bool is_end_of_word);
void add_flechies(NODE* node, char** sep_line);
void create_word_node(NODE* node, char** sep_line, int cpt);


NODE* rand_go_to_end_node(NODE* node);
NODE* search_to_end(NODE* node, char* word, int cpt);
NODE* search_to_end_flechies(NODE* node, char* word);


#endif // UNTITLED_NODE_H
