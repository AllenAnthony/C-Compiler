#include <stdio.h>
#include "util.h"
#include "hashtable.h"


//creat a item
Binder Binder_create(void *key, void *value, Binder next, void *preTop) {
    Binder b = checked_malloc(sizeof(*b));
    b->key = key;
    b->value = value;
    b->next = next;
    b->preTop = preTop;
    return b;
}


//creat a new empty hash table
HashTable HASH_create(void) {
    HashTable t = checked_malloc(sizeof(*t));
    int i;
    t->top = NULL;
    for (i = 0; i < TABSIZE; i++)
        t->table[i] = NULL;
    return t;
}

//my hash function
int HASH_func(void *key) {
    int hashVal = 0;
    char *temp = (char *) key;

    while ((*temp) != '\0') {
        hashVal = (hashVal << 5) + (*temp);
        temp++;
    }
    return hashVal % TABSIZE;
}

//push a new item
void HASH_push(HashTable t, void *key, void *value) {
    unsigned index;
    assert(t && key);
    index = HASH_func(key);
    t->table[index] = Binder_create(key, value, t->table[index], t->top);
    t->top = key;
}

//look for the value according to the key
void *HASH_look(HashTable t, void *key) {
    int index;
    Binder b;
    assert(t && key);
    index = HASH_func(key);
    for (b = t->table[index]; b; b = b->next)
        if (b->key == key)
            return b->value;
    return NULL;
}

// delete the latest item
void *HASH_pop(HashTable t) {
    void *k;
    Binder b;
    int index;
    assert(t);
    k = t->top;
    assert(k);
    index = HASH_func(k);
    b = t->table[index];
    assert(b);
    t->table[index] = b->next;
    t->top = b->preTop;
    return b->key;
}

//print the whole hash table
void HASH_dump(HashTable t, void (*show)(void *key, void *value)) {
    void *k = t->top;
    int index = HASH_func(k);
    Binder b = t->table[index];
    if (b == NULL)
        return;
    t->table[index] = b->next;
    t->top = b->preTop;
    show(b->key, b->value);
    HASH_dump(t, show);
    assert(t->top == b->preTop && t->table[index] == b->next);
    t->top = k;
    t->table[index] = b;
}

//the print fomula
void HASH_show(void *key, void *value) {
    char *temp = (char *) key;
    while ((*temp) != '\0') {
        printf("%s", temp);
        key++;
    }
    printf(" : ");
    HASH_print(value);
    printf("\n");

}

void HASH_print(void *value) {
    char *temp = (char *) value;
    printf("%s", temp);
}


//#define HASH_TABLE_SIZE 1024
//
//enum ABS_T {
//    TYPE_INT, TYPE_FLOAT, TYPE_CHAR
//};
//
//typedef struct {
//    char *key;
//    enum ABS_T type;
//} Entry;
//
//typedef struct {
//    int size;
//    Entry *top;
//} Binder;
//
//typedef Binder *Hashtable;
//
//Hashtable HASH_create() {
//    Hashtable hashtable = (Hashtable) malloc(sizeof(Binder) * HASH_TABLE_SIZE);
//    memset(hashtable, 0, sizeof(Binder) * HASH_TABLE_SIZE);
//    return hashtable;
//}
//
//void HASH_func(char *key){
//
//}
//
//void HASH_insert(Entry entry){
//
//}




