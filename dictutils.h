#ifndef DICTUTILS_H
#define DICTUTILS_H

typedef struct Record {
    char *key;
    void *val;
} Record;

typedef struct Collection {
    int size;
    Record *area;    
} Collection;

Collection* initdict (); // Constructor-like function
int addrec (char *key, void *val, Collection *col); // Adds a new record into a collection
int locrec (char *key, Collection *col); // Locates the index of a record using a given key
void* getrec (char *key, Collection *col); // Gets the record value using a given key 
int delrec (char *key, Collection *col); // Deletes a record using a given key
void freedict (Collection *col); // Clean all records of a dictionary

#endif