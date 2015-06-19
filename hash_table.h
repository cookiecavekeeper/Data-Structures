//
// Created by md55 on 19.06.2015.
//

#ifndef DATASTRUCTURES_HASH_TABLE_H
#define DATASTRUCTURES_HASH_TABLE_H

typedef struct HashNode {
    char *key;
    char *value;
    struct HashNode *next;
} HashNode;

typedef struct HashTable {
    int size;
    HashNode **node_list;
} HashTable;

HashTable *HashTable_create(int size);

void HashTable_set(HashTable *table, char *key, char *value);

char *HashTable_get(HashTable *table, char *key);

#endif //DATASTRUCTURES_HASH_TABLE_H
