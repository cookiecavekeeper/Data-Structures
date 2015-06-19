//
// Created by md55 on 19.06.2015.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_table.h"

HashTable *HashTable_create(int size)
{
    HashTable *table = malloc(sizeof(HashTable));
    table->size = size;
    table->node_list = malloc(size * sizeof(HashNode));
    int i;
    for (i = 0; i < size; ++i) {
        table->node_list[i] = NULL;
    }

    return table;
}

int HashTable_hash(char *key, int size)
{
    int total = 0;
    size_t length = strlen(key);
    int i;
    for (i = 0; i < length; ++i) {
        total += key[i];
    }
    return total % size;
}

HashNode *HashTable_createNode(const char *key, const char *value)
{
    HashNode *target = malloc(sizeof(HashNode));
    target->key = strdup(key);
    target->value = strdup(value);
    target->next = NULL;
    return target;
}

void HashTable_set(HashTable *table, char *key, char *value)
{
    int hash = HashTable_hash(key, table->size);
    if (table->node_list[hash] == NULL) {
        table->node_list[hash] = HashTable_createNode(key, value);
        return;
    }

    HashNode *tmp = table->node_list[hash];
    do {
        if(strcmp(tmp->key, key) == 0) {
            free(tmp->value);
            tmp->value = strdup(value);
            return;
        }

    } while (tmp->next != NULL && (tmp = tmp->next));

    tmp->next = HashTable_createNode(key, value);
}

char *HashTable_get(HashTable *table, char *key)
{
    int hash = HashTable_hash(key, table->size);
    HashNode *target = table->node_list[hash];
    if (target == NULL) {

        return NULL;
    }

    do {
        if(strcmp(target->key, key) == 0) {
            return  strdup(target->value);
        }

    } while ((target->next != NULL && (target = target->next)));
    printf("Key not found");
    return NULL;
}