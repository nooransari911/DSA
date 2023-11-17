//
// Created by moham on 16-11-2023.
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
    struct elle * link [3];  // ptr to previous instance of type (struct elle)
    int mark; // marks elle
} elle;


typedef struct tree {
    struct elle * root; // root to the entire tree
    int size; // size of tree;
} tree;


typedef struct linear {
// a general linear data structure;
// can be accessed as stack or queue;

    struct elle * arr [20];

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
    te -> link [2] = NULL;
    te -> mark = 0;

    return te;
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

    // Makes new elle the [r]th child of given root;
    root -> link [r] = ptrnew;
    ptrnew -> link [2] = root;
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




// 1. printing all elements in linear
// 2. inserting a new element into linear
// 3. access linear as queue [firstin]
// 4. access linear as stack [lastin]
// 5. access linear as stack [read-only]
// 6. Returns int for left or right child
// 7. Shifting all items in given linear by 1 position
// begins here;

void printall (struct linear* in) {
    int i;

    printf ("\n");

    for (i = 0; i <= in -> lastin; i++) {
        printf("%d\t", (in -> arr[i] -> data));
    }
}


void insert_st (struct linear* qu, struct elle*  a) {
    // inserts in a in linear as stack;
    // updates mark of a;
    if (a == NULL) {
        return;
    }

    qu -> arr [qu->lastin + 1] = a;

    a -> mark ++;
    qu -> lastin++;
    qu -> size++;
}


void insert_master (struct linear* qu, struct linear* in, struct elle* a) {
    // inserts a into two given linears as a stack;

    insert_st(qu, a);
    insert_st(in, a);
}


struct elle * access_qu (struct linear* qu) {
    // accesses linear as a queue;
    struct elle* te;
    te = create(0);

    te = qu -> arr [qu -> firstin];
    qu -> firstin ++;
    qu -> size -- ;
    te -> mark ++;

    return te;
}


struct elle * access_st (struct linear* qu) {
    // access linear as a stack;
    struct elle* te;
    te = create(0);

    te = qu -> arr [qu -> lastin];
    qu -> lastin --;
    qu -> size -- ;
    te -> mark ++;

    return te;
}


struct elle * peek_st (struct linear* qu) {
    // access linear as a stack [read-only];
    // does nothing other than returning the lastin in
    // given linear;

    struct elle* te;
    te = create(0);

    te = qu -> arr [qu -> lastin];

    return te;
}


int whichchild (struct elle * root, struct elle * child) {
    // returns int as per the child;
    // returns 0 if given child is left child;
    // returns 1 if given child is right child;

    int i;
    i = 0;

    while (i < 2) {
        if (root->link[i] == child) {
            return i;
        }
        i++;
    }
}


void shiftlinear (struct linear * this) {
    // Shifts all data in all elements in linea arr
    // by 1 position
    // towards index 0;
    // i.e., arr [i] -> data = arr [i + 1] -> data;

    int i, j;
    struct elle * parent;
    i = 0;

    while (i < ((this -> size) - 1)) {
        this -> arr [i] -> data = this -> arr [i + 1] -> data;
        i ++;
        /*
        free (by -> arr [i]);
        free (this -> arr [i]);
         */
    }

    parent = this -> arr [i] -> link [2];
    j = whichchild (parent, this -> arr [i]);
    parent -> link [j] = NULL;

    free (this -> arr [i]);
}
// linear ends here;








// 1. breadth-first traversal
// 2. depth first-traversal
// begins here;

/*
 * iterative implementations begins here;
 */

void BFS_iterative (struct tree* tree, struct  linear* qu, struct  linear* in) {
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




void DFS_preorder_iterative (struct tree* tree, struct linear* qu, struct linear* in) {
    struct elle* te0;
    te0 = create(0);
    int i, j, flag0;
    flag0 = 0;

    te0 = tree -> root;
    insert_master(qu, in, te0);


    while (qu -> size != 0) {
        te0 = access_st(qu);

        for (i = 0; i < 2; i ++) {
            if (te0 -> link [i] != NULL && te0 -> link [i] -> mark == 0) {
                insert_master(qu, in, te0 -> link [i]);
                flag0 = 1;
                break;
            }
        }

        if (flag0 == 0) {
            insert_st (qu, te0 -> link [2]);
        }

        flag0 = 0;
    }

    reset_tree(tree, in);
}


void DFS_preorder_iterative_alt (struct tree* tree, struct linear* qu, struct linear* in) {
    //older version;
    //newer version is DFS_preorder_iterative;

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

/*
 * iterative implementations ends here;
 */




/*
 * recursive implementations begins here;
 */


void DFS_preorder_internal (struct elle * root, struct linear * in) {
    if (root != NULL) {
        insert_st (in, root);
        DFS_preorder_internal (root->link [0], in);
        DFS_preorder_internal (root->link [1], in);
    }
}


void DFS_postorder_internal (struct elle * root, struct linear * in) {
    if (root != NULL) {
        DFS_postorder_internal (root->link [0], in);
        DFS_postorder_internal (root->link [1], in);
        insert_st (in, root);
    }
}

void DFS_inorder_internal (struct elle * root, struct linear * in) {
    if (root != NULL) {
        DFS_inorder_internal (root->link [0], in);
        insert_st (in, root);
        DFS_inorder_internal (root->link [1], in);
    }
}

void DFS_preorder (struct tree* tree, struct linear* qu, struct linear* in) {
    DFS_preorder_internal (tree -> root, in);
    reset_tree(tree, in);
}


void DFS_postorder (struct tree* tree, struct linear* qu, struct linear* in) {
    DFS_postorder_internal (tree -> root, in);
    reset_tree(tree, in);
}


void DFS_inorder (struct tree* tree, struct linear* qu, struct linear* in) {
    DFS_inorder_internal (tree -> root, in);
    reset_tree(tree, in);
}


/*
 * recursive implementations ends here;
 */




/*
 * Functions that build upon traversals begins here;
 */


void Traversal_any (struct tree * tree, struct linear * qu, struct linear * in, int a) {
    // For easily accessing all traversal implementations;
    // 0. BFS
    // 1. DFS preorder, iterative
    // 2. DFS preorder, recursive
    // 3. DFS postorder, recursive
    // 4. DFS inorder, recursive


    qu = init_st();
    in = init_st();

    switch (a) {
        case 0:
            BFS_iterative (tree, qu, in);
            printf ("\n\nThe BFS iterative traversal is:");
            break;

        case 1:
            DFS_preorder_iterative (tree, qu, in);
            printf ("\n\nThe DFS preorder iterative traversal is:");
            break;

        case 2:
            DFS_preorder (tree, qu, in);
            printf ("\n\nThe DFS preorder recursive traversal is:");
            break;

        case 3:
            DFS_postorder (tree, qu, in);
            printf ("\n\nThe DFS postorder recursive traversal is:");
            break;

        case 4:
            DFS_inorder (tree, qu, in);
            printf ("\n\nThe DFS inorder recursive traversal is:");
            break;
    }

    printall (in);
}


struct elle * inorderpredecessor (struct tree * tree, struct elle * root) {
    // returns the predecessor in
    // DFS inorder traversal
    // of given elle;
    // returns NULL if this does not exist;

    struct linear * qu, * in;
    int i = 0;

    qu = init_st();
    in = init_st();

    DFS_inorder (tree, qu, in);

    if (in -> arr [i] == root) {
        return NULL;
    }


    while (in -> arr [i + 1] != root) {
        i ++;
    }

    return in -> arr [i];
}




// BFS_iterative, DFS_preorder_alt ends here;
