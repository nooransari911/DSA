//
// Created by moham on 05-11-2023.
//

#ifndef UNTITLED1_SRC0_H
#define UNTITLED1_SRC0_H

#endif //UNTITLED1_SRC0_H




#include "malloc.h"
#include "stdio.h"
#include "stdbool.h"








// structure definitions begins here;

typedef struct elle {
    int data;  // data to be processed by program
    struct elle * link [2];  // ptr to previous instance of type (struct elle)
    int mark; // marks elle
} elle;


typedef struct tree {
    struct elle * root; // root to the entire tree
    int size; // size of tree;
} tree;


typedef struct linear {
// a general linear data structure;
// can be accessed as stack or queue;

    struct elle * arr [100];

    int firstin;
    int lastin;
    int size;
} linear;

// structure definitions ends here;








// creates and initializes a new instance
// of all type begins here;

struct linear* init_st () {
    // creates and initializes a new instance
    // of type linear;
    
    struct linear* a;

    a = (struct linear*) malloc (sizeof (struct linear));
    a -> firstin = 0;
    a -> lastin = -1;
    a -> size = 0;

    return a;
}


struct elle* create (int a) {
    // creates and initializes a new instance
    // of type elle;

    struct elle* te;

    te = (struct elle *) malloc (sizeof (struct elle));
    te -> data = a;
    te -> link [0] = NULL;
    te -> link [1] = NULL;
    te -> mark = 0;
}

// init_all types ends here;




// 1. inserting a node into tree
// 2. generating a new tree
// 3. reset mark of all elle in tree
// begins here;

void insert_elle (struct elle* root, int r, int a) {
    // creates and initializes a new instance
    // of type linear;
    // makes this as the child of given root;
    
    struct elle *ptrnew;
    // declares existence of ptr to a
    // new instance of type (struct elle)

    ptrnew = create(a);
    root -> link [r] = ptrnew;
}


struct tree * generate_tree() {
    // generates a new tree;
    
    struct tree* tree;
    struct elle* te0, * root;
    int i, j, k;

    root = create(0);
    te0 = create(0);

    tree = (struct tree *) malloc (sizeof (struct tree));
    tree -> root = root;
    tree -> size = 1;

    insert_elle(root, 0, 1);
    insert_elle(root, 1, 2);

    k = 3;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            te0 = root -> link [i];
            insert_elle(te0, j, k);
            k ++;
        }
    }
    
    k = 7;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            te0 = root -> link [i] -> link [j];
            insert_elle(te0, j, k);
            k ++;
        }
    }

    tree -> size = 11;

    return tree;
}


void reset_tree (struct tree* tree, struct linear* in) {
    int i = 0;

    for (i = 0; i <= in -> lastin; i++) {
        in -> arr [i] -> mark = 0;
    }
}

// modifying tree
// ends here;




// 1. printing all eolements in linear
// 2. inserting a new element into linear
// 3. access linear as queue [firstin]
// 4. access linear as stack [lastin]
// begins here;

void printall (struct linear* in) {
    int i;

    printf ("\n");

    for (i = 0; i <= in -> lastin; i++) {
        printf("%d\t", (in -> arr[i] -> data));
    }
}


void insert_st (struct linear* qu, struct elle*  a) {
    qu -> arr [qu->lastin + 1] = a;

    a -> mark ++;
    qu -> lastin++;
    qu -> size++;
}


void insert_master (struct linear* qu, struct linear* in, struct elle* a) {
    insert_st(qu, a);
    insert_st(in, a);
}


struct elle * access_qu (struct linear* qu) {
    struct elle* te;
    te = create(0);

    te = qu -> arr [qu -> firstin];
    qu -> firstin ++;
    qu -> size -- ;
    te -> mark ++;

    return te;
}


struct elle * access_st (struct linear* qu) {
    struct elle* te;
    te = create(0);

    te = qu -> arr [qu -> lastin];
    qu -> lastin --;
    qu -> size -- ;
    te -> mark ++;

    return te;
}

// linear ends here;








// 1. breadth-first traversal
// 2. depth first-traversal
// begins here;

void BFS (struct tree* tree, struct  linear* qu, struct  linear* in) {
    struct elle* te0;
    te0 = create(0);
    int i, j;

    te0 = tree -> root;
    insert_master(qu, in, te0);


    while (qu -> size != 0) {
        te0 = access_qu(qu);

        for (i = 0; i < 2; i ++) {
            if (te0 -> link [i] != NULL) {
                insert_master(qu, in, te0 -> link [i]);
            }
        }
    }

    reset_tree(tree, in);
}




void DFS (struct tree* tree, struct linear* qu, struct linear* in) {
    struct elle* te0;
    te0 = create(0);
    int i, j, k, flag0;
    k = 1;
    flag0 = 0;

    te0 = tree -> root;
    insert_master(qu, in, te0);


    while (qu -> size != 0) {
        te0 = access_st(qu);

        for (i = 0; i < 2; i ++) {
            if (te0 -> link [i] != NULL && te0 -> link [i] -> mark == 0) {
                insert_master(qu, in, te0 -> link [i]);
                flag0 = 1;
                k = 1;
                break;
            }
        }

        if (flag0 == 0 && (k <= in -> lastin)) {
                insert_st (qu, in -> arr [in -> lastin - k]);
                k ++;
        }

        flag0 = 0;
    }

    reset_tree(tree, in);
}

// BFS, DFS ends here;
