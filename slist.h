#ifndef SLIST_H
#define SLIST_H

#include <stdint.h>

struct Node {
    int32_t data;
    struct Node* next;
};


typedef struct List {
    struct Node* head;
} List;


List* slist_add_head(List* list, int32_t new_data);
List* slist_add_tail(List* list, int32_t new_data);
List* slist_add_after(List* list, int32_t key, int32_t new_data);
List* slist_delete_head(List* list);
List* slist_delete_tail(List* list);
List* slist_reverse(List* list);


#endif /* SLIST_H */

