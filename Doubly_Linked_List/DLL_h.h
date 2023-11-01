/*
h file for creating and using doubly linked list;

functions for inserting, deleting, searching, printing doubly linked list
*/




//
// Created by moham on 10-10-2023.
//

#ifndef UNTITLED1_NONLINEAR1_H
#define UNTITLED1_NONLINEAR1_H

#endif //UNTITLED1_NONLINEAR1_H


#include "nonlinear0.h"


typedef struct list {
    int size;
    //current size of list

    struct elle *lastin;
    //ptr to last created
    //elle

    struct elle *firstin;
    //ptr to first created
    //elle

    int pos;
    //position of whatever
} list;


/*create begins here*/
/*possible operations::
 1. insert before firstin
 2. insert after lastin
 3. insert anywhere that is not firstin/lastin;
    insert immediately after given index;
    index starts from firstin;
    firstin = (index 0)
 */


list *create_nonli() {
    struct list *temp;
    //temporary variable

    temp = (list *) malloc(sizeof(list));
    //creates a
    //new instance of type (struct list)


    temp->size = 0;
    temp->lastin = NULL;
    temp->firstin = NULL;
    //initializes everything

    return temp;
}


bool create_nonli_elle(list *list, elle *pre, int a, int op) {
    //private function
    //to create a new element
    //in list list;

    //create new element at position pre
    //with integer a

    struct elle *te;
    int flag0 = 0;


    //op = 1:
    //create a new element
    //at beginning (firstin)

    //op = -2:
    //create a new element
    //at end (lastin)


    if (op == -1) {
        te = create_elle(a);
        //creates a
        //new instance of type (struct elle);
        //stores ptr that
        //in te;

        if (list->size == 0) {
            list->lastin = te;
            list->firstin = te;

            te->link_into_exis = NULL;
            te->link_into_new = NULL;

            //if list does not
            //currently have any elle,
            //then sets
            //list->firstin to new elle
        } else {
            list->firstin->link_into_exis = te;
            //link_into_exis in
            //current firstin
            //now points to
            //te

            te->link_into_exis = NULL;
            //link_new in te
            //points to NULL
            //(redundant)


            te->link_into_new = (list->firstin);
            //link_into_new in
            //new instance of type (struct elle)
            //now points to elle that
            //link_into_new of list->firstin
            //points to;

            list->firstin = te;
            //link_into_new in
            //current list->firstin
            //now points to
            //new elle

        }


        list->size++;
        //increases size
    } else if (op == -2) {
        te = create_elle(a);
        //creates a
        //new instance of type (struct elle);
        //stores ptr that
        //in te;


        te->link_into_exis = list->lastin;
        //link_exis in
        //te now points to
        //current lastin

        te->link_into_new = NULL;
        //link_new in
        //te now points to
        //NULL
        //(redundant)


        list->lastin->link_into_new = te;
        //link_into_new in
        //current list->lastin
        //now points
        //new elle

        list->lastin = te;
        //new elle is now
        //the lastin


        list->size++;
        //return true;
    } else {
        //inserts immediately after pre

        te = create_elle(a);
        //creates a
        //new instance of type (struct elle);
        //stores ptr that
        //in te;

/*
        if (pre->link_into_new == NULL) {
            flag0 = 1;
        }
*/

        te->link_into_exis = pre;
        //link_exis in
        //te now points to
        //pre

        pre->link_into_new->link_into_exis = te;
        //link_exis in
        //link_new in pre
        //now points to
        //te;


        te->link_into_new = pre->link_into_new;
        //link_into_new in
        //new instance of type (struct elle)
        //now points to elle that
        //link_into_new of pre
        //points to;

        pre->link_into_new = te;
        //link_into_new in
        //current pre
        //now points to
        //new elle


        if (flag0 == 1) {
            list->lastin = te;
            //if position happens to the last,
            //then modify lastin as well
        }

        list->size++;
        //return true;
    }

    return true;
}


bool create_nonli_elle0(struct list *list, int a, int op) {
    struct elle *te, *pre;
    int i;

    //op = 1:
    //create a new element
    //at beginning (firstin)

    //op = -2:
    //create a new element
    //at end (lastin)

    if ((op == -1) || (op == -2)) {
        create_nonli_elle(list, list->firstin, a, op);
        //parameter passed to function:
        //list, ..., a, op;
        //list->firstin is redundant here
    } else {
        pre = list->firstin;
        //initializes pre;

        for (i = 0; i < op; i++) {
            pre = pre->link_into_new;
            //pointer chasing till
            //required location is reached
        }

        create_nonli_elle(list, pre, a, 4);
        //parameter passed to function:
        //list, pre, a, ...;
        //op is redundant here
    }


    return true;
}








/*print begins here*/
/*possible operations::
 1. print from firstin
 2. print from lastin
 */

void print_all_firstin(list *list) {
    struct elle *temp;

    temp = list->firstin;

    printf("\n\n");

    while (temp) {
        printf("%d\n", temp->data);
        temp = temp->link_into_new;
        //print and pointer chasing till
        //NULL
    }
}


void print_all_lastin(list *list) {
    struct elle *temp;

    temp = list->lastin;

    printf("\n\n");

    while (temp) {
        printf("%d\n", temp->data);
        temp = temp->link_into_exis;
        //print and pointer chasing till
        //NULL
    }
}








/*search begins here*/
/*possible operations::
 1. search for a given key;
    start from firstin
 2. search for a given key;
    start from lastin
 */

elle *search_firstin(list *list, int key) {
    //returns elle that
    //points to key
    //by link_new;
    //starts frorm firstin;

    struct elle *pre;

    pre = list->firstin;


    while (pre) {
        if (pre->link_into_new->data == key) {
            break;
        }

        pre = pre->link_into_new;
        //pointer chasing till key
        //is found
    }


    return pre;
}


elle *search_lastin(list *list, int key) {
    //returns elle that
    //points to key
    //by link_exis;
    //starts frorm lastin;

    struct elle *post;

    post = list->lastin;


    while (post) {
        if (post->link_into_exis->data == key) {
            break;
        }

        post = post->link_into_exis;
        //pointer chasing till key
        //is found
    }


    return post;
}




/*create double*/
/*possible operations:
 1. convert existing DLL to
    circular DLL;
 2. convert existing DLL to
    non-circular DLL;
*/

void create_circular_DLL (list* list) {
    list -> lastin -> link_into_new = list ->firstin;
    list -> firstin -> link_into_exis = list -> lastin;
}

void cancel_circular_DLL (list* list) {
    list -> lastin -> link_into_new = NULL;
    list -> firstin -> link_into_exis = NULL;
}








/*traditional stack/queue*/
/*possible operations:
 1. insert to stack
 2. insert to queue

 3. access from stack;
    modifies stack;
 4. access from queue;
    modifies queue;

 5. peek stack;
    does not modify;
 6. peek queue;
    does not modify;
 */

void insert_stack (list* list, int a) {
    create_nonli_elle0 (list, a, -2);
}

void insert_queue (list* list, int a) {
    insert_stack (list, a);
}


int access_stack (list* list) {
    int a;
    struct elle* te, * te1;
    te = list -> lastin -> link_into_exis;
    te1 = te -> link_into_new;


    a = te -> link_into_new -> data;
    te -> link_into_new = NULL;
    list -> lastin = te;


    free (te1);
    return a;
}


int access_queue (list* list) {
    int a;
    struct elle* te, * te1;
    te = list -> firstin -> link_into_new;
    te1 = te -> link_into_exis;


    a = te -> link_into_exis -> data;
    te -> link_into_exis = NULL;
    list -> firstin = te;


    free (te1);
    return a;
}


int peek_stack (list* list) {
    return (list -> lastin -> data);
}

int peek_queue (list* list) {
    return (list -> firstin -> data);
}








/*delete begins here*/
/*possible operations::
 1. delete a given key;
    start from firstin
 2. delete elle immediately after a given index;
    index starts from firstin;
    firstin = (index 0)
 3. delete all elements
 */

void delete_by_value(list *list, int key) {
    //deletes element of key
    struct elle *te, *te1;

    te = search_firstin(list, key);
    //to delete elle
    //that te points to

    te1 = te->link_into_new;
    //saves elle that this key
    //points to
    //in te1;
    //saves elle to be deleted
    //in te1


    te1->link_into_new->link_into_exis = te;
    //link_exis in
    //te1 now points to
    //te;

    te->link_into_new = te1->link_into_new;
    //te now points to
    //next-to-next elle

    free(te1);
    //frees elle

    list->size--;
}


void delete_by_position(list *list, int op) {
    //deletes elle at
    //position op

    struct elle *pre, *te, *te1;
    int i;

    pre = list->firstin;

    for (i = 0; i < (op - 1); i++) {
        pre = pre->link_into_new;
        //pointer chasing
    }

    te1 = pre->link_into_new;
    //saves elle that this key
    //points to
    //in te1;
    //saves elle to be deleted
    //in te1


    te1->link_into_new->link_into_exis = pre;
    //link_exis in
    //te1 now points to
    //te;

    pre->link_into_new = te1->link_into_new;
    //te now points to
    //next-to-next elle

    free(te1);
    //frees elle

    list->size--;
}


void dell_all(list *list) {
    struct elle *pre, *te;
    int i;

    pre = list->firstin;
    i = list->size;

    while (i > 0) {
        te = pre;
        pre = pre->link_into_new;
        //skips elle to be deleted

        free(te);
        //deletes required elle

        i--;
    }

    free(list);
}
