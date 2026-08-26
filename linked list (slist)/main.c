#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

void print_list(const List* list) {
    if (list == NULL || list->head == NULL) {
        printf("NULL\n");
        return;
    }
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Allocate and initialize the list container
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;

    printf("--- Testing Add Operations ---\n");
    slist_add_head(list, 20);
    slist_add_head(list, 10);
    slist_add_tail(list, 30);
    slist_add_tail(list, 40);

    printf("Initial List: ");
    print_list(list);

    printf("\n--- Testing Delete Head ---\n");
    slist_delete_head(list);
    print_list(list);

    printf("\n--- Testing Delete Tail ---\n");
    slist_delete_tail(list);
    print_list(list);

    printf("\n---- Testing Adding after Key element ---\n");
    list = slist_add_after(list, 20, 25);
    print_list(list);

    printf("\n--- Testing Reversing Linked List ---\n");
    list = slist_reverse(list);
    print_list(list);


    // Clean up  remaining nodes and list container memory
    while (list->head != NULL) {
        slist_delete_head(list);
    }
    free(list);

    return 0;
}
\
