//
// Created by ansarimn on 11/16/23.
//

#ifndef JSON_TREES_0_H
#define JSON_TREES_0_H

#endif //JSON_TREES_0_H


#include "force_multiplier.h"



/*
 * Printing and traversals begins here;
 * Functions for printing inorder, preorder, postorder traversals
 * All functions here take tree as arguments;
 * All functions here call another internal function to print tree;
 */

void internalprintinorder (struct elle * root) {
    if (root != NULL) {
        internalprintinorder (root->link [0]);
        printf("%d\t", root->data);
        internalprintinorder (root->link [1]);
    }
}


void internalprintpreorder (struct elle * root) {
    if (root != NULL) {
        printf("%d\t", root->data);
        internalprintpreorder (root->link [0]);
        internalprintpreorder (root->link [1]);
    }
}


void internalprintpostorder (struct elle * root) {
    if (root != NULL) {
        internalprintpostorder (root->link [0]);
        internalprintpostorder (root->link [1]);
        printf("%d\t", root->data);
    }
}




void printinorder (struct tree * tree){
    printf ("\n\nThe inorder traversal is:\n");
    internalprintinorder (tree -> root);
}


void printpreorder (struct tree * tree){
    printf ("\n\nThe preorder traversal is:\n");
    internalprintpreorder (tree -> root);
}


void printpostorder (struct tree * tree){
    printf ("\n\nThe postorder traversal is:\n");
    internalprintpostorder (tree -> root);
}


/*
 * Printing and traversals ends here;
 *
 */





/*
 * Binary search tree begins here;
 * Functions for searching, inserting in a BST;
 * All functions here take tree as arguments;
 * 1. Searching for a value in a BST;
 *      Returns ptr to the elle if found;
 * 2. Inserting any value in a BST;
 *      Returns void;
 */

struct elle * searchdatainBST (struct tree* tree, int key){
    /*
     * Searches for a value in BST;
     *
     */

    struct elle* root;
    root = tree -> root;


    while (root != NULL) {
        if(key == root->data){
            // Root is the required elle;
            return root;
        }
        else if (key < root->data) {
            // Value is in the left subtree;
            // Left child becomes root;
            // The left subtree now becomes the tree;
            root = root->link[0];
        }
        else if (key > root->data){
            // Value is in the right subtree;
            // Right child becomes root;
            // The right subtree now becomes the tree;
            root = root->link[1];
        }
    }


    // Value not found, so returns NULL;
    return NULL;
}




void insertinBST (struct tree * tree, int key) {
    /* Inserts a value into BST;
     *
     */



    struct elle * root, * te0;
    root = tree -> root;
    te0 = root;


    while (root != NULL) {
        te0 = root;


        if (key == root->data) {
            /*
             * Duplicate elles are not allowed in BST,
             * So print "not possible" and return;
             */
            printf("Cannot insert %d, already in BST", key);
            return;
        }

        else if (key < root->data) {
            // Value is to be inserted in the left subtree;
            // If the left child is not NULL,
            //      the left child becomes root;
            // Else
            //      value to be inserted becomes the left child
            //      of current root;

            root -> BF ++;
            root = root->link[0];
        }

        else if (key > root->data) {
            // Value is to be inserted in the right subtree;
            // If the right child is not NULL,
            //      the right child becomes root;
            // Else
            //      value to be inserted becomes the right child
            //      of current root;

            root -> BF --;
            root = root->link[1];

        }
    }


    if (te0 -> data > key) {
        insert_elle (te0, 0, key);
    }

    else {
        insert_elle (te0, 1, key);
    }


}




void insertinBST_alt (struct tree * tree, int key) {
    /* Inserts a value into BST;
     *
     */




    struct elle * root;
    root = tree -> root;


    while (root != NULL) {
        if (key == root->data) {
            /*
             * Duplicate elles are not allowed in BST,
             * So print "not possible" and return;
             */
            printf("Cannot insert %d, already in BST", key);
            return;
        }

        else if (key < root->data) {
            // Value is to be inserted in the left subtree;
            // If the left child is not NULL,
            //      the left child becomes root;
            // Else
            //      value to be inserted becomes the left child
            //      of current root;

            if (root->link[0] != NULL) {
                root -> BF ++;
                root = root->link[0];
            }

            else {
                insert_elle (root, 0, key);
                return;
            }
        }

        else if (key > root->data) {
            // Value is to be inserted in the right subtree;
            // If the right child is not NULL,
            //      the right child becomes root;
            // Else
            //      value to be inserted becomes the right child
            //      of current root;

            if (root->link[1] != NULL) {
                root -> BF --;
                root = root->link[1];
            }

            else {
                insert_elle (root, 1, key);
                return;
            }
        }
    }
}




void deleteinBSTinternal (struct linear * in, int i) {
    // For every element in arr,

    // shifts by 1 position
    // towards given index i
    // if they have 2 child;
    // i.e., arr [i] -> data = arr [i + 1] -> data;
    // (initially i is given as argument);

    // else if connects their parent
    // if they have only 1 child;

    // else makes link from their parent to them
    // NULL if they have no child;


    int j, k = i;
    struct elle * parent;


    while (k > -1) {
        if (in -> arr [k] -> link [2] == NULL) {
            parent = in -> arr [k - 1];
        }

        else {
            parent = in->arr[k]->link[2];
            j = whichchild (parent, in->arr[k]);
        }





        if (in -> arr [k] -> link [0] == NULL
            &&
            in -> arr [k] -> link [1] == NULL) {
            parent -> link [j] = NULL;

            if (j == 0) {
                parent -> BF --;
            }

            else if (j == 1) {
                parent -> BF ++;
            }

            //free (in -> arr [k]);
            break;
        }


        else if (in -> arr [k] -> link [0] != NULL
                 &&
                 in -> arr [k] -> link [1] != NULL) {
            in -> arr [k] -> data = in -> arr [k - 1] -> data;
            k --;
        }


        else {
            //parent -> link [j] = in -> arr [k - 1];

            if (in -> arr [k] -> link [0] != NULL) {
                parent -> link [j] = in -> arr [k] -> link [0];
            }

            else if (in -> arr [k] -> link [1] != NULL) {
                parent -> link [j] = in -> arr [k] -> link [1];
            }


            if (j == 0) {
                parent -> BF --;
            }

            else if (j == 1) {
                parent -> BF ++;
            }

            //free (in -> arr [k]);
            break;
        }


        /*
        free (by -> arr [i]);
        free (this -> arr [i]);
         */
    }
}




void deleteinBST (struct tree * tree, int key) {
    struct linear * qu, * in;
    struct elle* root = tree -> root;
    int i, flag0 = 0;


    qu = init_st();
    in = init_st();


    DFS_inorder (tree, qu, in);

    i = searchinlinear (in, key);
    printf ("\n%d\n", i);


    if (in -> arr [i] == root) {
        flag0 = 1;
    }


    if (flag0 == 1) {

        if (root -> link [0] == NULL
            &&
            root -> link [1] != NULL) {
            tree -> root = tree -> root -> link [1];
        }

        else if (root -> link [0] == NULL
            &&
            root -> link [1] == NULL
            ) {
            tree -> root = NULL;
        }

    }


    else {
        deleteinBSTinternal(in, i);
    }
}




void deleteinBST_alt (struct tree * tree, int key) {
    struct elle * root, * pre;
    struct linear * this, * by;
    int i;

    this = init_st();
    by = init_st ();
    root = tree -> root;
    pre = NULL;


    while (root != NULL) {
        root = searchdatainBST(tree, key);
        insert_st (this, root);
        pre = inorderpredecessor (tree, root);
        insert_st (by, pre);

        if (pre != NULL) {
            key = pre->data;
        }
        else {
            break;
        }
    }


    deleteinBSTinternal(this, 0);


}








/*
 * Functions on BST ends here;
 */