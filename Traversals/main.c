//
// Created by ansarimn on 11/14/23.
//


#include "BST.h"




int main() {
    struct linear* qu, * in;
    struct tree * tree, * tree1;
    struct elle * te0, * te1;

    tree = generate_tree();


    te0 = create (10);
    tree1 = (struct tree *) malloc (sizeof (struct tree));
    tree1 -> root = te0;


    insertinBST(tree1, 2);
    insertinBST(tree1, 20);
    insertinBST(tree1, 4);
    insertinBST(tree1, 40);
    insertinBST(tree1, 1);
    insertinBST(tree1, 25);
    insertinBST(tree1, 13);
    insertinBST(tree1, 22);
    te0 = searchinBST (tree1, 20);
    printf ("Item found;\nvalue: %d,\naddress: 0x%u", te0 -> data, te0);
    printinorder(tree1);
    deleteinBST (tree1, 10);
    printinorder(tree1);




    Traversal_any (tree1, qu, in, 0);
    Traversal_any (tree1, qu, in, 1);
    Traversal_any (tree1, qu, in, 2);
    Traversal_any (tree1, qu, in, 3);
    Traversal_any (tree1, qu, in, 4);
}
