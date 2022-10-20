#include <stdio.h>

#include "tree.h"
#include "node.h"

int treeHeight(t_tree t)
{
    return nodeHeight(t.root);
}

/*
int count(t_tree *tree)
{
    int c=0;

    if (tree ==NULL)
        return 0;

    else
    {
        c += count(tree->left);
        c += count(tree->right);
        return c;
    }
}
*/

int isPerfectRec(p_node pn, int d, int level)
{
    int res;
    // An empty tree is perfect
    if (pn == NULL)
        return 1;

    // If leaf node, then its depth must be same as
    // depth of all other leaves.
    if (pn->left == NULL && pn->right == NULL)
        return (d == level + 1);

    // If internal node and one child is empty
    if (pn->left == NULL || pn->right == NULL)
        return 0;

    // Left and right subtrees must be perfect.
    res = isPerfectRec(pn->left, d, level + 1);
    res = isPerfectRec(pn->right, d, level + 1);
    return res;
}

// Wrapper over isPerfectRec()
int isPerfectTree(t_tree t)
{
    p_node tmp = t.root;
    int d = 0;
    while (tmp != NULL)
    {
        d++;
        tmp = tmp->left;
    }
    return isPerfectRec(t.root, d, 0);
}

int isDegeneratedTreeRec(p_node pn)
{
    if (pn->left != NULL)
    {
        if (pn->right != NULL)
        {
            return 0; // not degenerate, has two children
        }
        else
        {
            return isDegeneratedTreeRec(pn->left);
        }
    }
    else
    {
        if (pn->right != NULL)
        {
            return isDegeneratedTreeRec(pn->right);
        }
        else
        {
            return 1; // we arrived at the bottom without seeing any node with two children
        }
    }
}

int isDegeneratedTree(t_tree tree)
{
    return isDegeneratedTreeRec(tree.root);
}