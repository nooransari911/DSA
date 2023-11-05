//
// Created by moham on 05-11-2023.
//


#include "src0.h"




int main() {
    struct linear* qu, * in;
    struct tree * tree;

    tree = generate_tree();


    qu = init_st();
    in = init_st();
    BFS (tree, qu, in);
    printf ("Breadth-first traversal of graph is:");
    printall(in);

    //reset_tree(tree, in);

    qu = init_st();
    in = init_st();
    DFS (tree, qu, in);
    printf ("\n\nDepth-first traversal of graph is:");
    printall(in);
}
