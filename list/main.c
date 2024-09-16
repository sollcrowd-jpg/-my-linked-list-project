#include <stdio.h>
#include <string.h>
#include "list.h"

int main() {
    // Initialize the list
    list_t *myList = list_alloc();

    printf("=== Basic Tests for Linked List ===\n");

    // Add elements to the front
    list_add_to_front(myList, 10);
    list_add_to_front(myList, 20);
    list_add_to_front(myList, 30);
    printf("After adding 30 -> 20 -> 10 to the front:\n");
    list_print(myList);

    // Add elements to the back
    list_add_to_back(myList, 40);
    printf("After adding 40 to the back:\n");
    list_print(myList);

    // Check list length
    int length = list_length(myList);
    if (length != 4) {
        printf("Test failed for list_length. Expected 4, got %d\n", length);
    }

    // Edge case: Remove from an empty list
    list_t *emptyList = list_alloc();
    elem removedFromEmpty = list_remove_from_back(emptyList);
    if (removedFromEmpty != -1) {
        printf("Test failed: Removing from empty list should return -1\n");
    }

    // Edge case: Add to an empty list
    list_add_to_front(emptyList, 100);
    list_print(emptyList); // Expected output: 100 -> NULL

    // Edge case: Removing from the front of an empty list
    removedFromEmpty = list_remove_from_front(emptyList); // Should remove 100
    if (removedFromEmpty != 100) {
        printf("Test failed: Expected to remove 100, got %d\n", removedFromEmpty);
    }
    removedFromEmpty = list_remove_from_front(emptyList); // Now the list is empty again
    if (removedFromEmpty != -1) {
        printf("Test failed: Removing from empty list should return -1\n");
    }

    // Edge case: Access invalid index (negative)
    elem invalidElem = list_get_elem_at(myList, -1);
    if (invalidElem != -1) {
        printf("Test failed: Accessing negative index should return -1\n");
    }

    // Edge case: Access out-of-bounds index
    invalidElem = list_get_elem_at(myList, 10);
    if (invalidElem != -1) {
        printf("Test failed: Accessing out-of-bounds index should return -1\n");
    }

    // Edge case: Remove at an invalid index
    elem removedInvalid = list_remove_at_index(myList, 10);
    if (removedInvalid != -1) {
        printf("Test failed: Removing at out-of-bounds index should return -1\n");
    }

    // Add elements back and test removal again
    list_add_to_back(myList, 50);
    list_add_to_back(myList, 60);
    list_print(myList); // Expected: 30 -> 20 -> 10 -> 40 -> 50 -> 60 -> NULL

    // Test removing at a valid index
    elem removedAtIndex = list_remove_at_index(myList, 3); // Removes 40
    printf("After removing element at index 3 (removed %d):\n", removedAtIndex);
    list_print(myList); // Expected: 30 -> 20 -> 10 -> 50 -> 60 -> NULL

    // Free the list and ensure it handles being freed multiple times
    list_free(myList);
    list_free(emptyList); // Free the previously allocated empty list

    printf("All tests completed.\n");

    return 0;
}
