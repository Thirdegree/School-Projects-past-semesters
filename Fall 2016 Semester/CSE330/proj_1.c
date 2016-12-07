#include "q.h"

void printQueue(struct Queue* head) {
    struct Queue *nextItem = DelQueue(head); 
    while (nextItem != NULL) {
        printf("%d, ", nextItem->payload);
        nextItem = DelQueue(head);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    struct Queue* head = newQueue();
    struct Queue* newItem = NewItem();
    newItem->payload = 6;
    AddQueue(head, newItem);
    newItem = NewItem();
    newItem->payload = 7;
    AddQueue(head, newItem);
    newItem = NewItem();
    newItem->payload = 8;
    AddQueue(head, newItem);

    struct Queue* head2 = newQueue();
    newItem = NewItem();
    newItem->payload = 9;
    AddQueue(head2, newItem);
    newItem = NewItem();
    newItem->payload = 10;
    AddQueue(head2, newItem);
    newItem = NewItem();
    newItem->payload = 11;
    AddQueue(head2, newItem);

    printQueue(head);
    printQueue(head2);

    return 0;
}