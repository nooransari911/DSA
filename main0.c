//
// Created by moham on 05-11-2023.
//


#include "src0.h"




int main() {
    struct linear* qu, * in;
    struct tree * tree;


    qu = init_st();
    in = init_st();


    tree = generate_tree();


    BFS (tree, qu, in);


    printall(in);
}
