#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H

struct s_node
{
    int value;
    struct s_node *left, *right;
    int depth;
};

typedef struct s_node t_node, *p_node;

p_node createNode(int val);

int nodeHeight(p_node pn);

#endif // UNTITLED_NODE_H
