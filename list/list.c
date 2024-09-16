// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Allocate memory for a new list
list_t *list_alloc() {
    list_t *new_list = (list_t *)malloc(sizeof(list_t));
    if (!new_list) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    new_list->head = NULL;
    return new_list;
}

// Free all nodes in the list
void list_free(list_t *L) {
    node_t *current = L->head;
    node_t *next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    free(L);
}

// Print all elements in the list
void list_print(list_t *L) {
    node_t *current = L->head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

// Convert list to string
char* listToString(list_t *L) {
    char* buffer = (char *)malloc(sizeof(char) * 1024);
    char temp[20];
    buffer[0] = '\0';

    node_t *current = L->head;
    while (current != NULL) {
        sprintf(temp, "%d -> ", current->value);
        strcat(buffer, temp);
        current = current->next;
    }
    strcat(buffer, "NULL");
    return buffer;
}

// Return the length of the list
int list_length(list_t *L) {
    int length = 0;
    node_t *current = L->head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

// Add a node to the back of the list
void list_add_to_back(list_t *L, elem value) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (!new_node) return;
    new_node->value = value;
    new_node->next = NULL;

    if (L->head == NULL) {
        L->head = new_node;
    } else {
        node_t *current = L->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Add a node to the front of the list
void list_add_to_front(list_t *L, elem value) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (!new_node) return;
    new_node->value = value;
    new_node->next = L->head;
    L->head = new_node;
}

// Add a node at a specific index in the list
void list_add_at_index(list_t *L, elem value, int index) {
    if (index == 0) {
        list_add_to_front(L, value);
        return;
    }

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (!new_node) return;
    new_node->value = value;

    node_t *current = L->head;
    for (int i = 0; i < index - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        free(new_node);
        return; // index is out of bounds
    }

    new_node->next = current->next;
    current->next = new_node;
}

// Remove a node from the back of the list
elem list_remove_from_back(list_t *L) {
    if (L->head == NULL) {
        return -1; // List is empty
    }

    node_t *current = L->head;
    node_t *previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    elem value = current->value;
    if (previous == NULL) {
        L->head = NULL; // Only one element
    } else {
        previous->next = NULL;
    }

    free(current);
    return value;
}

// Remove a node from the front of the list
elem list_remove_from_front(list_t *L) {
    if (L->head == NULL) {
        return -1; // List is empty
    }

    node_t *current = L->head;
    elem value = current->value;
    L->head = current->next;

    free(current);
    return value;
}

// Remove a node at a specific index
elem list_remove_at_index(list_t *L, int index) {
    if (index == 0) {
        return list_remove_from_front(L);
    }

    node_t *current = L->head;
    node_t *previous = NULL;

    for (int i = 0; i < index && current != NULL; i++) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        return -1; // Index out of bounds
    }

    previous->next = current->next;
    elem value = current->value;
    free(current);
    return value;
}

// Check if a value is in the list
bool list_is_in(list_t *L, elem value) {
    node_t *current = L->head;
    while (current != NULL) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Get the element at a specific index
elem list_get_elem_at(list_t *L, int index) {
    node_t *current = L->head;
    for (int i = 0; i < index && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        return -1; // Index out of bounds
    }

    return current->value;
}

// Get the index of a specific value
int list_get_index_of(list_t *L, elem value) {
    node_t *current = L->head;
    int index = 0;

    while (current != NULL) {
        if (current->value == value) {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1; // Value not found
}
