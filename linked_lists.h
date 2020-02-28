//**********************************************************************************************************************
// Linked Lists Helper Library
// author - Aashish Kumar
//**********************************************************************************************************************

//**********************************************************************************************************************
//                                                  INCLUDED FILES
//**********************************************************************************************************************
#include <stdlib.h>
#include <iostream>

using namespace std;

//**********************************************************************************************************************
//                                          SINGLE LINKED LIST STRUCTURE
//**********************************************************************************************************************
struct linked_list_single
{
    int data = 0;
    struct linked_list_single * next;
};
//**********************************************************************************************************************

//**********************************************************************************************************************
//                                          DISPLAYING THE LINKED LIST
//**********************************************************************************************************************
void print_linked_list_single (struct linked_list_single * s)
{
    while (s -> next != NULL) {
        cout << s -> data << " " << endl;
        s = s -> next;
    }
    cout << s -> data;
}
//**********************************************************************************************************************

//**********************************************************************************************************************
//          ADDING A NODE AT THE END OF THE LINKED LIST, ADDS AS FIRST NODE IF THE LINKED LIST IS EMPTY
//**********************************************************************************************************************
void add_node_end_single (struct linked_list_single * s, int x)
{
    // checking if the linked list is an empty linked list
    if (s == NULL) {
        s -> data = x;
        s -> next = NULL;
    } 
    // if the linked list is not empty, adds the node to the end of the linked list
    else {
        while (s -> next != NULL)
            s = s -> next;

        struct linked_list_single * p = (struct linked_list_single *) malloc (sizeof(struct linked_list_single));

        s -> next = p;
        p -> data = x;
        p -> next = NULL;

        cout << "Node added at end: " << p -> data << endl;
    }
}
//**********************************************************************************************************************

//**********************************************************************************************************************
//                          ADDING A NEW NODE WITH DATA 'Y' BEFORE THE NODE WITH DATA 'X'
//**********************************************************************************************************************
void add_node_before_data_x_single (struct linked_list_single * s, int x, int y)
{
    // checking if the linked list is empty and adding x to that node if empty
    if (s == NULL) {
        s -> data = y;
        s -> next = NULL;
    } 
    // if the linked list is not empty, adds the node before the node with data 'x'
    else {
        struct linked_list_single * q = s;
        while (s -> next != NULL && s -> data != x) {
            q = s;
            s = s -> next;
        }
        if (s -> data == x) {
            struct linked_list_single * p = (struct linked_list_single *) malloc (sizeof (struct linked_list_single));

            p -> next = s -> next;
            p -> data = y;
            q -> next = p;
        } else {
            cout << "The node with data: " << x << " is not there in the linked list. Can not replace with value: " << y << endl;
        }
    }
}
//**********************************************************************************************************************

//**********************************************************************************************************************
//                                  DELETING THE LAST NODE IN THE LINKED LIST
//**********************************************************************************************************************
void delete_last_node_single (struct linked_list_single * s)
{
    if (s == NULL)
        cout << "Error: The linked list is empty. Can not delete any more nodes." << endl;
    else {
        while (s -> next != NULL) {
            s = s -> next;
        }
        
        int x = s -> data;
        free (s);
        // preventing dangling pointer problem
        s = NULL;

        cout << "Deleted the node: " << x << endl;
    }
}
//**********************************************************************************************************************

//**********************************************************************************************************************
//**********************************************************************************************************************