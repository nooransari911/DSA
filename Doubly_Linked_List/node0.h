/*
h file for creating any node;

fields in node:
  int
  2 pointers to node
*/




//
// Created by moham on 10-10-2023.
//

#ifndef UNTITLED1_NONLINEAR0_H
#define UNTITLED1_NONLINEAR0_H

#endif //UNTITLED1_NONLINEAR0_H


#include "malloc.h"
#include "stdio.h"
#include "stdbool.h"


typedef struct elle {
    int data;  // data to be processed by program
    struct elle* link_into_new;  // ptr to new instance of type (struct elle)
    struct elle* link_into_exis;  // ptr to new instance of type (struct elle)
}elle;




elle* create_elle (int a) {
    struct elle* ptrnew;
    // declares existence of ptr to a
    // new instance of type (struct elle)


    ptrnew = (elle*) malloc (sizeof (elle));
    // creates a
    // new instance of type (struct elle);
    // initializes ptrnew


    if (!ptrnew) {
        printf ("\nnot possible");
        return NULL;  // if malloc was unsuccessful
    }

    else {
        ptrnew -> data = a;
        // data
        ptrnew -> link_into_new = NULL;
        ptrnew -> link_into_exis = NULL;
        return ptrnew;
        // returns ptr to newly created
        // instance of type (struct elle)
    }
}
