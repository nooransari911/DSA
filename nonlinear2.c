//
// Created by moham on 10-10-2023.
//


#include "nonlinear1.h"


int main () {
    struct list* te;
    struct elle * te1;


    te = create_nonli();


    //insert at beginning
    create_nonli_elle0 (te, 4, -1);
    printf ("%d\n", te -> firstin -> data);
    create_nonli_elle0(te, 2, -1);
    printf ("%d\n\n", te -> firstin -> data);

    printf ("%d\n", te -> firstin -> data);
    printf ("%d\n", te -> firstin -> link_into_new -> data);


    //insert at end
    create_nonli_elle0 (te, 8, -2);
    printf ("%d\n", te -> lastin -> data);
    create_nonli_elle0 (te, 16, -2);
    printf ("%d\n\n", te -> lastin -> data);

    //printf ("%d\n", te -> firstin -> data);


    //insert at position
    create_nonli_elle0 (te, 32, -2);
    create_nonli_elle0 (te, 64, -2);


    //insert operations
    //stack, queue
    insert_stack (te, 128);
    insert_queue (te, 256);

    //printf ("%d\n", te -> lastin -> link_into_new -> data);


    print_all_firstin(te);
    printf ("%d\n", peek_stack(te));
    printf ("%d\n", peek_queue(te));
    printf ("%d\n", access_stack(te));
    printf ("%d\n", access_queue(te));
    printf ("\n\n");


    te1 = search_firstin(te, 16);
    printf ("%d\n", te1 -> data);
    te1 = search_lastin(te, 16);
    printf ("%d\n", te1 -> data);


    //delete key
    delete_by_value(te, 8);
    print_all_firstin(te);

    //delete at position
    delete_by_position(te, 3);
    print_all_firstin(te);
    print_all_lastin(te);

    //delete all
    dell_all (te);
    //print_all_firstin (te);
    return 0;
}
