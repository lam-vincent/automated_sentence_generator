#include <stdlib.h>
#include <stdio.h>
#include "node.h"

p_node createNode(char letter)
{
    p_node nouv;

    nouv = (p_node)malloc(sizeof(t_node));
    nouv->letter = letter;

    return nouv;
}