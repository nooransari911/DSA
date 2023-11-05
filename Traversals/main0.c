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
    printall(in);

    //reset_tree(tree, in);

    qu = init_st();
    in = init_st();
    DFS (tree, qu, in);
    printall(in);
}
