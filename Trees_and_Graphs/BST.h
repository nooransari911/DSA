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
    printf ("\n\nThe inorder traversal is:\n");
    internalprintpreorder (tree -> root);
}


void printpostorder (struct tree * tree){
    printf ("\n\nThe inorder traversal is:\n");
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

struct elle * searchinBST (struct tree* tree, int key){
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
                root = root->link[1];
            }

            else {
                insert_elle (root, 1, key);
                return;
            }
        }
    }
}




void deleteinBST (struct tree * tree, int key) {
    struct elle * root, * pre;
    struct linear * this, * by;
    int i;

    this = init_st();
    by = init_st ();
    root = tree -> root;
    pre = NULL;


    while (root != NULL) {
        root = searchinBST (tree, key);
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


    shiftlinear (this);


}








/*
 * Functions on BST ends here;
 */