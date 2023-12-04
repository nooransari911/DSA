//
// Created by ansarimn on 11/14/23.
//


#include "AVL.h"




int main() {
    /*
     * char arr[10] = {0};
        foo(arr, 10);
     */


    /*
     * char *p = foo(10);
     */
    /*
    struct stack * dates;

    dates = init_stack();
    insert_stack(dates);
    insert_stack(dates);
    insert_stack(dates);
    insert_stack(dates);
    print_stack(dates);
    */


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

    te0 = searchdatainBST(tree1, 20);
    printf ("Item found;\nvalue: %d,\naddress: 0x%u", te0 -> data, te0);
    printinorder(tree1);

    deleteinBST (tree1, 10);
    /*
    deleteinBST (tree1, 40);
    deleteinBST (tree1, 40);
    deleteinBST (tree1, 22);
    deleteinBST (tree1, 1);
    deleteinBST (tree1, 2);
    */
    printinorder(tree1);




    Traversal_any (tree1, qu, in, 0);
    Traversal_any (tree1, qu, in, 1);
    Traversal_any (tree1, qu, in, 2);
    Traversal_any (tree1, qu, in, 3);
    Traversal_any (tree1, qu, in, 4);



    struct tree * tree2;
    te0 = create (20);
    tree2 = (struct tree *) malloc (sizeof (struct tree));
    tree2 -> root = te0;

    insertinBST(tree2, 18);
    insertinBST(tree2, 16);
    insertinBST(tree2, 10);
    insertinBST(tree2, 17);


    printpostorder(tree2);
    tree2 -> root = rightrotate (tree2 -> root);
    printpostorder(tree2);




    struct tree * tree3;
    te0 = create (10);
    tree3 = (struct tree *) malloc (sizeof (struct tree));
    tree3 -> root = te0;

    insertinBST(tree3, 16);
    insertinBST(tree3, 18);
    insertinBST(tree3, 20);
    insertinBST(tree3, 17);


    printpostorder(tree3);
    tree3 -> root = leftrotate (tree3 -> root);
    printpostorder(tree3);
}
