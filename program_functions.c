#include <stdio.h>
#include"stdlib.h"
#include "program_functions.h"
#include "tree.h"
#include "node.h"
#include "file_management.h"

void sentence_model(int* choice)
{
    printf("Select a model:\n");
    printf("\t1.{NOM} {ADJ} {VER} {NOM}\n");
    printf("\t2.{NOM} 'qui' {VER} {VER} {NOM} {ADJ}\n");
    printf("\t3.{VER} {ADV} {NOM} 'c'est comme' {VER} {NOM} {ADV}\n");
    
    do
    {
        scanf("%d", choice);
    } while (*choice < 1 || *choice > 3);
    
}

