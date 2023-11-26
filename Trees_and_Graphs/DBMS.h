//
// Created by ansarimn on 11/25/23.
//

#ifndef TREES_AND_GRAPHS_DBMS_H
#define TREES_AND_GRAPHS_DBMS_H

#endif //TREES_AND_GRAPHS_DBMS_H


#include "BST.h"




int convert (char* str) {
    int i, id;
    i = 0;
    id = 0;

    while (str[i] != '\0') {
        id = id + str [i];
        i++;
    }

    return id;
}


struct elle* inputelle (int sign) {
    char name[10], email[10];
    int phone, i;
    struct elle* te0;


    printf ("\nPatient name: ");
    scanf (" %9[^\n]", name);
    printf ("Appointment date: ");
    scanf (" %9[^\n]", email);
    printf ("Bill: ");
    scanf (" %d", &phone);


    te0 = create (sign);
    for (i = 0; i < 10; i++) {
        te0 -> name [i] = name [i];
    }
    for (i = 0; i < 10; i++) {
        te0 -> email [i] = email [i];
    }
    te0 -> phone = phone;
    te0 -> id = convert (name);

    return te0;
}




void insertrecord (struct tree* tree, struct elle* record) {
    /* Inserts elle into BST;
     * Compares value of id of root elle
     * with value of id of record elle;
     */

    struct elle * root;

    if (tree -> root == NULL) {
        tree -> root = record;
        return;
    }

    else {
        root = tree -> root;
        while (root != NULL) {
            if (record->id == root->id) {
                /*
                 * Duplicate elles are not allowed in BST,
                 * So print "not possible" and return;
                 */
                printf("Cannot insert %s; already in BST", record -> name);
                return;
            } else if (record->id < root->id) {
                root->BF++;
                // Value is to be inserted in the left subtree;
                // If the left child is not NULL,
                //      the left child becomes root;
                // Else
                //      value to be inserted becomes the left child
                //      of current root;

                if (root->link[0] != NULL) {
                    root = root->link[0];
                } else {
                    root->link[0] = record;
                    record -> link [2] = root;
                    return;
                }
            } else if (record->id > root->id) {
                root->BF--;
                // Value is to be inserted in the right subtree;
                // If the right child is not NULL,
                //      the right child becomes root;
                // Else
                //      value to be inserted becomes the right child
                //      of current root;

                if (root->link[1] != NULL) {
                    root = root->link[1];
                } else {
                    root->link[1] = record;
                    record -> link [2] = root;
                    return;
                }
            }
        }
    }
}


struct elle * searchidinBST (struct tree* tree, int key){
    /*
     * Searches for a value in BST;
     *
     */

    struct elle* root;
    root = tree -> root;


    while (root != NULL) {
        if (key == root -> id){
            // Root is the required elle;
            return root;
        }
        else if (key < root -> id) {
            // Value is in the left subtree;
            // Left child becomes root;
            // The left subtree now becomes the tree;
            root = root -> link[0];
        }
        else if (key > root -> id){
            // Value is in the right subtree;
            // Right child becomes root;
            // The right subtree now becomes the tree;
            root = root -> link[1];
        }
    }


    // Value not found, so returns NULL;
    //printf ("\nValue not found!!\n");
    return NULL;
}





void DBMSinsert (struct tree* tree, int sign) {
    struct elle* new;

    new = inputelle (sign);

    insertrecord (tree, new);
}


void DBMSsearch (struct tree* tree, int key) {
    struct elle* te0;

    te0 = searchidinBST (tree, key);

    if (te0 != NULL) {
        printf ("\nMedical history found!!");
        printone (te0);
    }

    else {
        printf ("Medical history not found!!");
    }
}


void DBMSdelete (struct tree* tree) {
    char name [10];
    int id;
    struct elle* te0;

    printf ("Enter name to be deleted:");
    scanf (" %9[^\n]", name);

    id = convert (name);

    te0 = searchidinBST (tree, id);
    if (te0 != NULL){
        deleteinBST(tree, te0->data);
    }
}


void DBMSprintall (struct tree* tree) {
    struct linear * qu, * in;
    int i = 0;
    qu = init_st();
    in = init_st();

    if (tree -> root == NULL) {
        printf ("empty records!!");
    }

    else {
        DFS_inorder(tree, qu, in);

        for (i = 0; i <= in->lastin; i++) {
            printone(in->arr[i]);
        }

        printf("\n\n");
    }
}




void DBMSmenu () {
    int op = 0, signature = 0, i = 0;
    char name [10];
    struct tree* tree;
    struct elle* te0;

    tree = inittree();
    te0 = (struct elle*) malloc (sizeof (struct elle));


    for (;;)
    {

        printf("\n\n1. Start operation\n");
        printf("2. Exit\n");
        printf("3. Add new record\n");
        printf("4. Delete by name\n");
        printf("5. Print all records\n");
        printf("6. Search by medical history\n");

        scanf("%d[^\n]", &op);

        switch (op) {
            case 1:
                break;

            case 2:
                exit (0);

            case 3:
                DBMSinsert (tree, signature);
                signature ++;
                break;

            case 4:
                DBMSdelete (tree);
                signature --;
                break;

            case 5:
                DBMSprintall (tree);
                break;

            case 6:
                printf ("Search medical history: ");
                scanf (" %9[^\n]", name);
                i = convert (name);

                DBMSsearch (tree, i);
        }
    }
}