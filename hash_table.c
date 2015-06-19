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

    for (int i = 0; i < size; ++i) {
        table->node_list[i] = NULL;
    }

    return table;
}

int HashTable_hash(char *key, int size)
{
    int total = 0;
    size_t length = strlen(key);
    for (int i = 0; i < length; ++i) {
        total += key[i];
    }
    return total % size;
}

void HashTable_createNode(HashNode *target, const char *key, const char *value)
{
    target = malloc(sizeof(HashNode));
    target->key = strdup(key);
    target->value = strdup(value);
    target->next = NULL;
}

void HashTable_set(HashTable *table, char *key, char *value)
{
    int hash = HashTable_hash(key, table->size);
    HashNode *target = table->node_list[hash];
    if (target == NULL) {
        HashTable_createNode(target, key, value);
        return;
    }

    HashNode *tmp = target;
    while (tmp->next != NULL) {
        if(strcmp(tmp->key, key) == 0) {
            free(tmp->value);
            tmp->value = strdup(value);
            return;
        }

        tmp = tmp->next;
    }
    HashTable_createNode(tmp->next, key, value);
}

char *HashTable_get(HashTable *table, char *key)
{
    int hash = HashTable_hash(key, table->size);
    HashNode *target = table->node_list[hash];
    if (target == NULL) {

        return NULL;
    }

    while (target->next != NULL) {
        if(strcmp(target->key, key) == 0) {
            return  strdup(target->value);
        }

        target = target->next;
    }
    printf("Key not found");
    return NULL;
}