#include <stdlib.h>
#include <stdio.h>
#include "node.h"

p_node createNode(int val)
{
    p_node nouv;

    nouv = (p_node)malloc(sizeof(t_node));
    nouv->value = val;
    nouv->left = nouv->right = NULL;

    return nouv;
}

int nodeHeight(p_node pn)
{
    if (pn == NULL)
    {
        return -1;
    }
    else
    {
        int heightLeft = nodeHeight(pn->left);
        int heightRight = nodeHeight(pn->right);
        if (heightLeft < heightRight)
        {
            return heightRight + 1;
        }
        else
        {
            return heightLeft + 1;
        }
    }
}
