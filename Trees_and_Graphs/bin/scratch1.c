// C program for the above operation
/*#include <stdio.h>
#include <stdlib.h>

// Structure of a linked list node
struct node {
    int info;
    struct node* next;
};

// Pointer to last node in the list
struct node* last = NULL;



// Function to add a new node at the
// end of the list
void addatlast(int data)
{
    // Initialize a new node
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));

    // If the new node is the
    // only node in the list
    if (last == NULL) {
        temp->info = data;
        temp->next = temp;
        last = temp;
    }

        // Else the new node will be the
        // last node and will contain
        // the reference of head node
    else {
        temp->info = data;
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}



// Function to insert a node in the
// starting of the list
void insertAtFront(int data)
{
    // Initialize a new node
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));

    // If the new node is the only
    // node in the list
    if (last == NULL) {
        temp->info = data;
        temp->next = temp;
        last = temp;
    }

        // Else last node contains the
        // reference of the new node and
        // new node contains the reference
        // of the previous first node
    else {
        temp->info = data;
        temp->next = last->next;

        // last node now has reference
        // of the new node temp
        last->next = temp;
    }
}


// Function to insert after any
// specified element
void insertafter (int value, int data)
{
    // Stores data and element after
    // which new node is to be inserted

    // Initialize a new node
    struct node *temp, *n;


    temp = last->next;

    do {

        // Element after which node is
        // to be inserted is found
        if (temp->info == value) {
            n = (struct node*)malloc(sizeof(struct node));

            n->info = data;
            n->next = temp->next;
            temp->next = n;

            // If temp is the last node
            // so now n will become the
            // last node
            if (temp == last)
                last = n;
            break;
        }
        else
            temp = temp->next;
    } while (temp != last->next);
}





// Function to delete the first
// element of the list
void deletefirst()
{
    struct node* temp;

    // If list is empty
    if (last == NULL)
        printf("\nList is empty.\n");

        // Else last node now contains
        // reference of the second node
        // in the list because the
        // list is circular
    else {
        temp = last->next;
        last->next = temp->next;
        free(temp);
    }
}



// Function to delete the last node
// in the list
void deletelast()
{
    struct node* temp;

    // If list is empty
    if (last == NULL)
        printf("\nList is empty.\n");

    temp = last->next;

    // Traverse the list till
    // the second last node
    while (temp->next != last)
        temp = temp->next;

    // Second last node now contains
    // the reference of the first
    // node in the list
    temp->next = last->next;
    last = temp;
}


// Function to delete an element
// at a specified index in the list
void deleteAtIndex (int pos)
{
    pos --;
    // Stores the index at which
    // the element is to be deleted
    int i = 0;
    struct node *temp, *position;
    temp = last->next;

    // If list is empty
    if (last == NULL)
        printf("\nList is empty.\n");

        // Else
    else {

        // Traverse till the node to
        // be deleted is reached
        while (i <= pos - 1) {
            temp = temp->next;
            i++;
        }

        // After the loop ends, temp
        // points at a node just before
        // the node to be deleted

        // Reassigning links
        position = temp->next;
        temp->next = position->next;

        free(position);
    }
}




// Function to print the list
void viewList()
{
    printf ("\n");
    // If list is empty
    if (last == NULL)
        printf("\nList is empty\n");

        // Else print the list
    else {
        struct node* temp;
        temp = last->next;

        // While first node is not
        // reached again, print,
        // since the list is circular
        do {
            printf("%d\t", temp->info);
            temp = temp->next;
        } while (temp != last->next);
    }
}





// Driver Code
int main2()
{
    // Function Call
    insertAtFront(10);
    insertAtFront(20);

    addatlast(40);
    addatlast(50);

    viewList();


    insertafter (10, 52);
    viewList();


    deletefirst();
    viewList();
    deletelast();
    viewList();
    addatlast(140);
    addatlast(150);
    deleteAtIndex (1);
    viewList();


    return 0;
}
*/