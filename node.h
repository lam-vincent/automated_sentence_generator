#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H
#include <stdbool.h>

typedef struct forme_flechie
{
	char *forme;
	char *base;
	char **code;
	int nb_code;
} FF;

typedef struct s_node
{
	char letter;
	struct s_node **next;  // array of pointer
	int next_current_size; // current size of the array
						   // 					   //(char** flechies ; //array of other forms
						   // 					   // char** code ; //array of the corresponding codes, "+" split character for each string)
						   // bool is_end;
						   // FF *flechies;
						   // int current_flechies_size;
} NODE;

NODE *createNode(char letter, bool is_end_of_word);
void update_next_array(NODE *previous);
void add_node(NODE *previous, char letter, bool is_end_of_word);

NODE *end_of_word(NODE *node, char *base, int cpt);

void add_flechies();

#endif // UNTITLED_NODE_H
