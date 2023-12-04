//
// Created by moham on 16-11-2023.
//

#ifndef UNTITLED1_SRC0_H
#define UNTITLED1_SRC0_H

#endif //UNTITLED1_SRC0_H




#include "DBMS_dates.h"









// structure definitions begins here;

typedef struct elle {
    int data;  // data to be processed by program

    /* FOR DBMS ::
     * data is signature;
     * signature is unique for every node created;
     * id is integer form of name string;
     * id is not necessarily unique;
     *
     * user data is inserted in BST
     * based on id (effectively name)
     * bill is phone;
     */

    char name [10];
    int phone, id;

    struct elle * link [3];  // ptr to previous instance of type (struct elle)
    int mark; // marks elle
    int BF;   // balance factor of elle;
    // defined as height of left - height of right;


    //implemented appointment dates as a stack;
    struct stack * dates;
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




void foo (char *buf, int count) {
    /*
     * Passing character arrays [strings]
     * to function
     */

    int i;

    for(i = 0; i < count; ++i) {
        buf[i] = i;
    }
}


char* foo_x (int count) {
    /*
     * Returning character arrays [strings]
     * from function
     */

    // take input for string of length 10 ::
    // scanf (" %9[^\n]", name);


    char *ret = malloc(count);
    if(!ret)
        return NULL;

    for(int i = 0; i < count; ++i)
        ret[i] = i;

    return ret;
}




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
    te -> BF = 0;
    te -> dates = init_stack();
    return te;
}

struct tree * inittree () {
    struct tree* tree;
    tree = (struct tree*) malloc (sizeof (struct tree));
    tree -> root = NULL;
}
// init_all types ends here;




/*
 * Printing one elle;
 *  Printing time taken;
 */

void printone (struct elle* one) {
    printf ("\n");

    if (one != NULL) {
        printf("Hospital name: I2IT");
        printf("\nWard no.: %d", one -> data);
        printf("\nRecord id: %d", one -> id);
        printf("\nPatient name: %s", one->name);
        printf("\nBill: %d", one->phone);
        print_stack(one -> dates);
    }

    else {
        printf ("Record not exist;");
    }

    printf ("\n");
}


void print_time (struct timespec * initial, struct timespec * final, int op) {
    double diff;

    diff = (final -> tv_sec - initial -> tv_sec) + ((final -> tv_nsec - initial -> tv_nsec)
                                                    / 1000.0);


    if (op == 0) {
        printf ("\n\nPROCESS TIME IS: %lf us\n\n", diff);
    }

    else if (op == 1) {
        printf ("\n\nWALL TIME IS: %lf us\n\n", diff);
    }
}


/*
 * print ends here
 */




// 1. inserting a node into tree
// 2. generating a new tree
// 3. reset mark of all elle in tree
// 4. Returns int for left or right child
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

    if (r == 0) {
        root -> BF ++;
    }
    else if (r == 1) {
        root -> BF --;
    }
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
        in -> arr [i] -> BF = 0;
    }
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
// modifying tree
// ends here;




// 1. printing all elements in linear
// 2. inserting a new element into linear
// 3. access linear as queue [firstin]
// 4. access linear as stack [lastin]
// 5. access linear as stack [read-only]
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




int searchinlinear (struct linear * in, int key) {
    int i = 0;

    while (in -> arr [i] -> data != key) {
        i ++;
    }

    return i;
}


// linear ends here;








// 1. breadth-first traversal
// 2. depth first-traversal
// begins here;

/*
 * iterative implementations begins here;
 */

void BFS_iterative (struct tree* tree, struct  linear* qu, struct  linear* in) {

    struct timespec initial0, final0;
    struct timespec initial1, final1;

    timespec_get (&initial1, TIME_UTC);
    clock_gettime (CLOCK_PROCESS_CPUTIME_ID, &initial0);



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





    timespec_get(&final1, TIME_UTC);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &final0);

    print_time (&initial0, &final0, 0);
    print_time (&initial1, &final1, 1);


}




void DFS_preorder_iterative (struct tree* tree, struct linear* qu, struct linear* in) {

    struct timespec initial0, final0;
    struct timespec initial1, final1;

    timespec_get (&initial1, TIME_UTC);
    clock_gettime (CLOCK_PROCESS_CPUTIME_ID, &initial0);





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



    timespec_get(&final1, TIME_UTC);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &final0);

    print_time (&initial0, &final0, 0);
    print_time (&initial1, &final1, 1);

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
    struct timespec initial0, final0;
    struct timespec initial1, final1;

    timespec_get (&initial1, TIME_UTC);
    clock_gettime (CLOCK_PROCESS_CPUTIME_ID, &initial0);


    DFS_preorder_internal (tree -> root, in);
    reset_tree(tree, in);



    timespec_get(&final1, TIME_UTC);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &final0);

    print_time (&initial0, &final0, 0);
    print_time (&initial1, &final1, 1);
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
