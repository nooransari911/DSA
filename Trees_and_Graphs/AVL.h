//
// Created by ansarimn on 11/19/23.
//

#ifndef TREES_AND_GRAPHS_AVL_H
#define TREES_AND_GRAPHS_AVL_H

#endif //TREES_AND_GRAPHS_AVL_H


#include "BST.h"


struct elle * leftrotate (struct elle * disturbed) {
    struct elle * X, * T1, * T2;
    struct elle * parent;
    int j;


    /*
     *           parent
     *              |
     *              |
     *              |  j
     *              |
     *          disturbed
     *          /       \
     *         /         \
     *        /           \
     *       /             \
     *                      X
     *                     /
     *                    /
     *                   /
     *                  /
     *                 T1
     */


    X = disturbed -> link [1];
    T1 = X -> link [0];
    T2 = X -> link [1];


    // X's parent is now disturbed's parent
    X -> link [2] = disturbed -> link [2];
    if (disturbed -> link [2] != NULL) {
        parent = disturbed -> link [2];

        j = whichchild (parent, disturbed);
        // parent's child is now X
        parent -> link [j] = X;
    }

    // disturbed is now left child of X
    X -> link [0] = disturbed;
    // T1 is now left child of disturbed
    disturbed -> link [1] = T1;

    // X is now parent of disturbed
    disturbed -> link [2] = X;


    // If T1 exists,
    // then disturbed becomes parent of T1;
    if (T1 != NULL) {
        T1->link[2] = disturbed;
    }


    return X;
}




struct elle * rightrotate (struct elle * disturbed) {
    struct elle * X, * T1, * T2;
    struct elle * parent;
    int j;

    /*
     *           parent
     *              |
     *              |
     *              |  j
     *              |
     *          disturbed
     *          /       \
     *         /         \
     *        /           \
     *       /             \
     *      X
     *       \
     *        \
     *         \
     *          \
     *          T2
     */


    X = disturbed -> link [0];
    T1 = X -> link [0];
    T2 = X -> link [1];



    // X's parent is now disturbed's parent
    X -> link [2] = disturbed -> link [2];
    if (disturbed -> link [2] != NULL) {
        parent = disturbed -> link [2];
        j = whichchild (parent, disturbed);
        // parent's child is now X
        parent -> link [j] = X;
    }


    // disturbed is now right child of X
    X -> link [1] = disturbed;
    // T2 is now left child of disturbed
    disturbed -> link [0] = T2;

    // X is now parent of disturbed
    disturbed -> link [2] = X;

    // If T2 exists,
    // then disturbed becomes parent of T2;
    if (T2 != NULL) {
        T2->link[2] = disturbed;
    }

    return X;
}




struct elle * converged_rotations (struct tree * tree, struct elle * disturbed, int a) {
    struct elle * te0, * te1;

    switch (a) {
        case 0:
            // purely left rotate;
            te0 = leftrotate (disturbed);
            break;

        case 1:
            // purely right rotate;
            te0 = rightrotate (disturbed);
            break;

        case 2:
            // RL;
            // right wrt child of disturbed,
            // then left wrt disturbed;
            tree -> root = rightrotate (disturbed -> link [1]);
            te0 = leftrotate (disturbed);
            break;

        case 3:
            // LR;
            // left wrt child of disturbed,
            // then right wrt disturbed;
            tree -> root = leftrotate (disturbed -> link [1]);
            te0 = rightrotate (disturbed);
            break;
    }
}




struct elle * balanceAVL (struct elle * disturbed, struct elle * created) {
    /*
     * takes unbalanced elle as input;
     */

    int i, j;
    struct elle * te0;

    // i: for first operation;
    // j: for second operation;
    // 0: left, 1: right;
    i = whichchild (created -> link [2], created);
    j = whichchild (disturbed, created -> link [2]);


    if (i == 0 && j == 0) {
        // LL
        leftrotate (disturbed);
    }

    if (i == 1 && j == 1) {
        // RR
        rightrotate (disturbed);
    }

    if (i == 0 && j == 1) {
        // RL
        rightrotate (disturbed -> link [1]);
        leftrotate (disturbed);
    }

    if (i == 1 && j == 0) {
        // LR
        leftrotate (disturbed -> link [0]);
        rightrotate (disturbed);
    }
}