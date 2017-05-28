typedef struct HASH_TABLE *hashTable;
typedef struct BINDER_ *binder;

#define TABSIZE 1024

//creat a new empty hash table
hashTable hashEmpty(void);

//push item
void hashPush(hashTable t, void *key, void *value);

//look for the value according to the key
void *hashLook(hashTable t, void *key);

// delete the latest item
void *hashPop(hashTable t);

//print the whole table
void hashDump(hashTable t, void (*show)(void *key, void *value));

//hash function
int hashFun(void* key);

void myPrint(void* value);

void show(void *key, void *value);

//item of key to value
struct BINDER_ 
{
    void *key; 
    void *value; 
    binder next; 
    void *preTop;
};

//hash table
struct HASH_TABLE 
{
  binder table[TABSIZE];
  void *top;
};