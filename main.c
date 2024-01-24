#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//struct of the list, for each node
typedef struct Node
{
    //the data what you want to store
    int data;
    //the next node
    struct Node *next;
}Node;

//adding nodes to a linked list
Node *add_node(Node *first_node, int input)
{
    //memory allocation for the new node
    Node *new_node = (Node*) malloc(sizeof(Node));
    //check the memory allocation was succesful
    if(new_node == NULL)
    {
        printf("\n  !!! Memory allocation failed !!!  \n");
        //return with an empty node
        return NULL;
    }
    //implement the input
    new_node->data = input;
    if(first_node == NULL)
    {
        first_node = new_node;
        new_node->next = NULL;
        return new_node;
    }
    new_node->next = first_node;
    return new_node;
}

void print_list(Node *linked_list)
{
    //go through on the list
    Node *iter;
    for(iter = linked_list; iter != NULL; iter = iter->next)
        printf("%d\n", iter->data);
}

Node delete_specific_number(Node *linked_list, int condition)
{
    Node *current = linked_list;
    Node *previous = NULL;
    while(current != NULL)
    {
        if(current->data == condition)
        {
            if(previous == NULL)
            {
                Node *temp = current->next;
                free(current);
                linked_list = temp;
                current = temp;
            }
            else
            {
                Node *temp = current->next;
                free(current);
                previous->next = temp;
                current = temp;
            }
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
}

bool prime_number(int number)
{
    for (int i = 1; i <= number / 2; ++i)
    {
        if (number % i != 0)
            continue;
        else
            return false;
    }
    return true;
}

Node delete_specific_nodes(Node *linked_list)
{
    Node *current = linked_list;
    Node *previous = NULL;
    while(current != NULL)
    {
        if(prime_number(current->data))
        {
            if(previous == NULL)
            {
                Node *temp = current->next;
                free(current);
                linked_list = temp;
                current = temp;
            }
            else
            {
                Node *temp = current->next;
                free(current);
                previous->next = temp;
                current = temp;
            }
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
}

void free_linked_list(Node *linked_list)
{
    Node *erase;
    while(erase != NULL)
    {
        Node *next_node = erase->next;
        free(erase);
        erase = next_node;
    }
}

int main()
{
    //create an empty linked list
    Node *first_node = NULL;
    //add nodes to it
    for(int i = 1; i < 11; ++i)
    {
        first_node = add_node(first_node, i);
        //check the memory allocation was succesful
        if(first_node == NULL)
        {
            //if its failed, return from main
            printf("\nThe node adder function failed!\n");
            return 1;
        }
    }

    //print your numbers
    print_list(first_node);

    //you always have to free your list!
    free_linked_list(first_node);
    //if not, it cause memory leak!
}
