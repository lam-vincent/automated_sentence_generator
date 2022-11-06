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
						   //(char** flechies ; //array of other forms
						   // char** code ; //array of the corresponding codes, "+" split character for each string)
	bool is_end;
	FF **flechies;
	int current_flechies_size;
} NODE;

NODE *createNode(char letter, bool is_end_of_word);
FF *createFlechie(char **sep_line);
void update_next_array(NODE *previous);
void update_flechies_array(NODE *node);
void add_node(NODE *previous, char letter, bool is_end_of_word);
void add_flechies(NODE *node, char **sep_line);
void create_word_node(NODE *node, char **sep_line, int cpt);

NODE *go_to_end(NODE *node, char **sep_line, int cpt);

#endif // UNTITLED_NODE_H
