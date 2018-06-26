#include "dictutils.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Collection* initdict () {
    Collection *aux = (Collection*)malloc(sizeof(struct Collection));
    if (aux == NULL)
        return aux;
    aux->size = 0;
    aux->area = NULL;
    return aux;
}

// For now, the library just accepts data to be "passed by reference" or
// just creating a new pointer pointing out to a previously allocated data
// To make the library more complete, data to be "passed by value" or
// beyond creating a new pointer, additional memory will be allocated in
// order to store a copy of the passed value (same as backing up the data into a new place)

// This function can be greatly improved
// Using quick sort after every insertion and deletion
// And then using binary search over the sequential
int locrec (char *key, Collection *col) {
    int i = 0;
    for (; i < col->size; i++) {
        if (strcmp((col->area + i)->key, key) == 0) 
            return i;
    }
    return -1;
}

int addrec (char *key, void *val, Collection *col) {
    if (col->area == NULL)
        col->area = (Record*)malloc(sizeof(struct Record));
    else
        col->area = (Record*)realloc(col->area, sizeof(struct Record) * (col->size + 1));
    
    if (col->area == NULL)
        return 1;

    (col->area + col->size)->key = key;
    (col->area + col->size)->val = val;
    col->size++;
    return 0;
}

void* getrec (char *key, Collection *col) {
	int i = locrec(key, col);
    // Default failure code
    if (i == -1)
        return NULL;
    else
        return (col->area + i)->val;
}

// inline void* printallrec (Collection *col) {
// 	int i = 0;
// 	for (; i < col->size; i++) {
//         printf("%s : %s\n", (col->area + i)->key, (col->area + i)->val);
// 	}

//     return NULL;
// }

int delrec (char *key, Collection *col) {
    int aux = locrec(key, col);
    // Default failure code
    if (aux == -1) return 1;

    int i = aux;
    for(; i < (col->size - 1); i++) {
        (col->area + i)->key = (col->area + i + 1)->key;
        (col->area + i)->val = (col->area + i + 1)->val;
    }
    // Security measures
    (col->area + i)->key = NULL;
    (col->area + i)->val = NULL;

    // Pair deleted by override, memory block has to be shrunk
    col->area = (Record*)realloc(col->area, sizeof(struct Record) * (--col->size));

    return (col->area == NULL) ? 1 : 0;
}

void freedict (Collection *col) {
    // Test for emptiness
    if (col->area != NULL) {
        int i = 0;
        for(; i < col->size; i++) {
            (col->area + i)->key = NULL;
            (col->area + i)->val = NULL;
        }
        col->size = 0;
        free(col->area);
        col->area = NULL;
    }
}