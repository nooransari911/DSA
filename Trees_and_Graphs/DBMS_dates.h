//
// Created by ansarimn on 12/4/23.
//

#ifndef TREES_AND_GRAPHS_DBMS_DATES_H
#define TREES_AND_GRAPHS_DBMS_DATES_H

#endif //TREES_AND_GRAPHS_DBMS_DATES_H
#include "malloc.h"
#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"





/*
 *
    struct timespec initial0, final0;
    struct timespec initial1, final1;

    timespec_get (&initial1, TIME_UTC);
    clock_gettime (CLOCK_PROCESS_CPUTIME_ID, &initial0);


    timespec_get(&final1, TIME_UTC);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &final0);

    print_time (&initial0, &final0, 0);
    print_time (&initial1, &final1, 1);
 */



typedef struct stack {
    char a [10] [10];
    int lastin;
} stack;


struct stack * init_stack () {
    struct stack * te0;

    te0 = (stack *) malloc (sizeof (struct stack));
    te0 -> lastin = -1;

    return te0;
}


void insert_stack (struct stack * dates) {
    int te;
    printf ("Appointment date: ");

    dates -> lastin ++;
    scanf (" %9[^\n]", &(dates -> a [(dates -> lastin)][10]));

    /*
    fgets (&(dates -> a [(dates -> lastin)][10]), 9, stdin);
    te = strcspn (&(dates -> a [(dates -> lastin)][10]), "\n");
    dates -> a [(dates -> lastin)] [te] = 0;
    */

}


void print_stack (struct stack * dates) {
    int i = 0;

    printf ("\nAppointment dates are: \n");

    if (dates -> lastin == -1) {
        printf ("No dates have been added");
    }


    else {
        while (i <= dates->lastin) {
            printf("%s\n", &(dates->a[i][10]));
            i++;
        }
    }
}


void print_stack_latest (struct stack * dates) {
    if (dates -> lastin == -1) {
        printf ("No dates have been added");

    }

    else {
        printf("\nLatest date is: %s\n", &(dates->a[dates->lastin][10]));
    }
}


void delete_stack (struct stack * dates) {
    dates -> lastin --;
}