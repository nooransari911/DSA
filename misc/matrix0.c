#include <stdio.h>
#include "malloc.h"


/*
matrix as a structure;
functions:
1. Create a matrix
2. Print matrix
*/


typedef struct matrix {
    int n;
    int a [4] [4];
} matrix;


matrix * scanm () {
    struct matrix * m0;
    int i, j;
    
    m0 = (struct matrix *) malloc (sizeof (struct matrix));
    
    m0 -> n = 4;
    
    for (i = 0; i < m0 -> n; i++) {
        for (j = 0; j < m0 -> n; j++) {
            printf ("enter <i>, <j>: ");
            scanf ("%d", &m0 -> a [i] [j]);
        }
    }
    
    return m0;
}


void printm (struct matrix * m0) {
    int i, j;
  
    
    for (i = 0; i < m0 -> n; i++) {
        for (j = 0; j < m0 -> n; j++) {
            printf ("%d\t", m0 -> a [i] [j]);
        }
        printf ("\n");
    }
}




int main()
{
    int i, j, k;
    int te0, te1;
    matrix* m0;
    

    m0 = scanm ();
    
    
    printf ("\nMatrix is:\n");
    printm (m0);
    
    
    

    return 0;
}
