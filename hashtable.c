#include <stdio.h>
#include <stdlib.h>

// Define a node for the linked list
typedef struct Node {
    int key;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a key into the hash table
void insert(Node* hashTable[], int size, int key) {
    int index = key % size; // Hash function (modulo)
    Node* newNode = createNode(key);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Function to search for a key and count comparisons
int search(Node* hashTable[], int size, int key, int* comparisons) {
    int index = key % size; // Hash function (modulo)
    Node* current = hashTable[index];
    while (current) {
        (*comparisons)++;
        if (current->key == key) {
            return 1; // Successful search
        }
        current = current->next;
    }
    return 0; // Unsuccessful search
}

// Function to initialize hash table
void initializeHashTable(Node* hashTable[], int size) {
    for (int i = 0; i < size; i++) {
        hashTable[i] = NULL;
    }
}

// Function to display the hash table
void displayHashTable(Node* hashTable[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Index %d: ", i);
        Node* current = hashTable[i];
        while (current) {
            printf("%d -> ", current->key);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    // Variables for hash table size and number of keys
    int sizes[] = {10, 20, 50, 100}; // Different hash table sizes (m)
    int keys[] = {50, 100, 200}; // Number of keys (n)

    for (int s = 0; s < 4; s++) { // Loop through hash table sizes
        int size = sizes[s];
        printf("\nHash Table Size: %d\n", size);

        for (int k = 0; k < 3; k++) { // Loop through number of keys
            int n = keys[k];
            printf("\nNumber of Keys: %d\n", n);

            // Initialize the hash table
            Node* hashTable[size];
            initializeHashTable(hashTable, size);

            // Insert keys into the hash table
            for (int i = 1; i <= n; i++) {
                insert(hashTable, size, i);
            }

            // Count key comparisons
            int comparisons = 0;
            int successful = search(hashTable, size, n / 2, &comparisons); // Search for a middle key
            printf("Successful Search Comparisons: %d\n", comparisons);

            comparisons = 0; // Reset comparisons
            int unsuccessful = search(hashTable, size, n + 1, &comparisons); // Search for a non-existent key
            printf("Unsuccessful Search Comparisons: %d\n", comparisons);

            displayHashTable(hashTable, size);
        }
    }

    return 0;
}
