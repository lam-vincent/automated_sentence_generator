#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H

struct s_node
{
    int letter;
    struct s_node *next;
    int current_size;
};

typedef struct s_node t_node, *p_node;

p_node createNode(char letter);

#endif // UNTITLED_NODE_H
