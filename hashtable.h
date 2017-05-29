typedef struct HASH_TABLE *HashTable;
typedef struct BINDER *Binder;

#define TABSIZE 1024

//creat a new empty hash table
HashTable HASH_create(void);

//push item
void HASH_push(HashTable t, void *key, void *value);

//look for the value according to the key
void *HASH_look(HashTable t, void *key);

// delete the latest item
void *HASH_pop(HashTable t);

//print the whole table
void HASH_dump(HashTable t, void (*show)(void *key, void *value));

//hash function
int HASH_func(void *key);

void HASH_print(void *value);

void HASH_show(void *key, void *value);

//item of key to value
struct BINDER {
    void *key;
    void *value;
    Binder next;
    void *preTop;
};

//hash table
struct HASH_TABLE {
    Binder table[TABSIZE];
    void *top;
};
