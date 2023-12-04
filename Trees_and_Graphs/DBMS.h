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
    /*
     * Takes input from user
     */

    char name[10], email[10];
    int phone, i;
    struct elle* te0;


    printf ("\nPatient name: ");
    scanf (" %9[^\n]", name);
    printf ("Bill: ");
    scanf (" %d", &phone);


    te0 = create (sign);
    for (i = 0; i < 10; i++) {
        te0 -> name [i] = name [i];
    }
    te0 -> phone = phone;
    // converts name string into int;
    te0 -> id = convert (name);

    return te0;
}




void insertrecord (struct tree* tree, struct elle* record) {
    /* Inserts elle into BST;
     * Compares value of id of root elle
     * with value of id of record elle;
     */

    struct timespec initial0, final0;
    struct timespec initial1, final1;

    timespec_get (&initial1, TIME_UTC);
    clock_gettime (CLOCK_PROCESS_CPUTIME_ID, &initial0);




    struct elle * root, * te0;

    te0 = root;
    root = tree -> root;


    if (tree -> root == NULL) {
        tree -> root = record;
    }


    else {


        while (root != NULL) {
            te0 = root;

            if (record->id == root->id) {
                /*
                 * Duplicate elles are not allowed in BST,
                 * So print "not possible" and return;
                 */
                printf("Cannot insert %s; already in BST", record -> name);
                return;
            }


            else if (record->id < root->id) {
                // Value is to be inserted in the left subtree;
                // If the left child is not NULL,
                //      the left child becomes root;
                // Else
                //      value to be inserted becomes the left child
                //      of current root;

                root->BF++;
                root = root->link[0];


            }


            else if (record->id > root->id) {
                // Value is to be inserted in the right subtree;
                // If the right child is not NULL,
                //      the right child becomes root;
                // Else
                //      value to be inserted becomes the right child
                //      of current root;

                root->BF--;
                root = root->link[1];

            }
        }


        if (te0 -> id > record -> id) {
            te0 -> link[0] = record;
            record -> link [2] = te0;
        }

        else {
            te0 -> link[1] = record;
            record -> link [2] = te0;
        }
    }


    timespec_get(&final1, TIME_UTC);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &final0);

    print_time (&initial0, &final0, 0);
    print_time (&initial1, &final1, 1);
}




void insertrecord_alt (struct tree* tree, struct elle* record) {
    /* Inserts elle into BST;
     * Compares value of id of root elle
     * with value of id of record elle;
     */


    struct elle * root;


    if (tree -> root == NULL) {
        tree -> root = record;
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


struct elle * DBMSsearch (struct tree* tree, int key) {
    struct elle* te0;

    te0 = searchidinBST (tree, key);

    if (te0 != NULL) {
        printf ("\nMedical history found!!");
        printone (te0);
    }

    else {
        printf ("Medical history not found!!");
    }

    return te0;
}


void DBMSdelete (struct tree* tree) {
    char name [10];
    int id;
    struct elle* te0;

    printf ("Enter name to be deleted: ");
    scanf (" %9[^\n]", name);

    id = convert (name);

    te0 = searchidinBST (tree, id);
    if (te0 != NULL){
        deleteinBST(tree, te0->data);
    }
}


void DBMSlatestdate (struct tree * tree, int sign) {
    struct elle *te0;
    int i = 0;

    te0 = DBMSsearch(tree, sign);

    if (te0 != NULL) {
        print_stack_latest(te0->dates);
    }
}


void DBMSinsertdate (struct tree * tree, int sign) {
    struct elle * te0;
    int i = 0;

    te0 = DBMSsearch (tree, sign);

    if (te0 != NULL)
    {
        while (true) {
            printf("\nDo you want to add date?\n");
            printf("Enter 1 to add date, enter 0 to cancel ");
            scanf("%d", &i);

            if (i == 1) {
                insert_stack(te0->dates);
            } else if (i == 0) {
                printf("\nOperation has been cancelled; returning\n");
                return;
            } else {
                printf("enter valid option");
            }
        }
    }
}


void DBMSdeletedate (struct tree * tree, int sign) {
    struct elle * te0;
    int i = 0;

    te0 = DBMSsearch (tree, sign);

    if (te0 != NULL) {
        while (true) {
            printf("\nDo you want to delete date: %s?\n", &(te0->dates->a[te0->dates->lastin][10]));
            printf("Enter 1 to delete latest date, enter 0 to cancel ");
            scanf("%d", &i);

            if (i == 1) {
                delete_stack(te0->dates);
            } else if (i == 0) {
                printf("\nOperation has been cancelled; returning\n");
                return;
            } else {
                printf("enter valid option");
            }
        }
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
        printf("7. Add appointment date\n");
        printf("8. Delete latest appointment date\n");
        printf("9. Get latest appointment date\n");


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
                break;

            case 7:
                printf ("Insert dates; enter name: ");
                scanf (" %9[^\n]", name);
                i = convert (name);

                DBMSinsertdate (tree, i);
                break;

            case 8:
                printf ("Delete dates; enter name: ");
                scanf (" %9[^\n]", name);
                i = convert (name);

                DBMSdeletedate (tree, i);
                break;

            case 9:
                printf ("Get latest date; enter name: ");
                scanf (" %9[^\n]", name);
                i = convert (name);

                DBMSlatestdate (tree, i);
                break;
        }
    }
}