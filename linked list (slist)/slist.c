#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

//  Add to Head
List* slist_add_head(List* list, int32_t new_data) {
    if (list == NULL) return NULL;

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) return list;

    node->data = new_data;
    node->next = list->head;
    list->head = node;

    return list;
}

//  Add to Tail
List* slist_add_tail(List* list, int32_t new_data) {
    if (list == NULL) return NULL;

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    if (node == NULL) return list;

    node->data = new_data;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        return list;
    }

    struct Node* last = list->head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = node;

    return list;
}


// Delete Head
List* slist_delete_head(List* list) {
    if (list == NULL || list->head == NULL) {
        printf("List is already empty, nothing to delete from head.\n");
        return list;
    }

    struct Node* temp = list->head;
    list->head = list->head->next;
    free(temp);

    return list;
}

// Delete Tail
List* slist_delete_tail(List* list) {
    if (list == NULL || list->head == NULL) {
        printf("List is already empty, nothing to delete from tail.\n");
        return list;
    }

    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        return list;
    }

    struct Node* second_last = list->head;
    while (second_last->next->next != NULL) {
        second_last = second_last->next;
    }

    free(second_last->next);
    second_last->next = NULL;

    return list;
}

List* slist_add_after(List* list, int32_t key, int32_t new_data) {
    if (list == NULL || list->head == NULL) {
        printf("List is empty or NULL. Cannot insert after key %d.\n", key);
        return list;
    }

    // Traverse to locate the node containing the key
    struct Node* current = list->head;
    while (current != NULL && current->data != key) {
        current = current->next;
    }

    // Key was not found in the list
    if (current == NULL) {
        printf("Key %d not found in the list.\n", key);
        return list;
    }

    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return list;
    }

    // Insert new_node after current
    new_node->data = new_data;
    new_node->next = current->next;
    current->next = new_node;

    return list;
}

List* slist_reverse(List* list) {
    if (list == NULL || list->head == NULL) {
        return list;
    }

    struct Node* prev = NULL;
    struct Node* current = list->head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse pointer
        prev = current;       // Move prev forward
        current = next;       // Move current forward
    }

    list->head = prev; // Update head to point to the new first node
    return list;
}

