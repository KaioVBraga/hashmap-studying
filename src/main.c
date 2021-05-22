#include <stdio.h>

typedef struct Node
{
    int number;
    struct Node *address;
} Node;

void showLinkedList(Node *headPointer)
{
    Node *pointer = headPointer;

    while (pointer)
    {
        printf("%d \n", pointer->number);
        pointer = pointer->address;
    }
}

Node *invertLinkedList(Node *headPointer)
{
    Node *pointer = headPointer;
    Node *next = 0;
    Node *previous = 0;

    while (pointer)
    {
        next = pointer->address;
        pointer->address = previous;
        previous = pointer;

        if (!next)
        {
            break;
        }

        pointer = next;
    }

    return pointer;
}

int main()
{
    Node head = {number : 1};
    Node node1 = {number : 2};
    Node node2 = {number : 3};
    Node node3 = {number : 3};
    Node tail = {number : 100};
    Node *newHead = 0;

    head.address = &node1;
    node1.address = &node2;
    node2.address = &node3;
    node3.address = &tail;

    showLinkedList(&head);

    printf("\n");

    newHead = invertLinkedList(&head);

    printf("\n");

    showLinkedList(newHead);

    printf("\n");

    newHead = invertLinkedList(newHead);

    printf("\n");

    showLinkedList(newHead);

    return 0;
}