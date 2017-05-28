#include <stdio.h>
#include "util.h"
#include "table.h"

//creat a item
static binder Binder(void *key, void *value, binder next, void *preTop)
{
 binder b = checked_malloc(sizeof(*b));
 b->key = key; 
 b->value=value; 
 b->next=next; 
 b->preTop = preTop; 
 return b;
}


//creat a new empty hash table
hashTable hashEmpty(void)
{ 
 hashTable t = checked_malloc(sizeof(*t));
 int i;
 t->top = NULL;
 for (i = 0; i < TABSIZE; i++)
   t->table[i] = NULL;
 return t;
}

//my hash function
int hashFun(void* key)
{
    key=(char*)key;
    unsigned int hashVal=0;
    while((*key)!='\0')
    {
        hashVal=(hashVal<<5)+(*key)
        key++;
    }
    return hashVal%TABSIZE;
}

//push a new item 
void hashPush(hashTable t, void *key, void *value)
{
 int index;
 assert(t && key);
 index = hashFun(key);
 t->table[index] = Binder(key, value,t->table[index], t->top);
 t->top = key;
}

//look for the value according to the key
void *hashLook(hashTable t, void *key)
{
    int index;
    binder b;
    assert(t && key);
    index=hashFun(key);
    for(b=t->table[index]; b; b=b->next)
        if (b->key==key) 
            return b->value;
    return NULL;
}

// delete the latest item
void *hashPop(hashTable t) 
{
  void *k; 
  binder b; 
  int index;
  assert (t);
  k = t->top;
  assert (k);
  index = hashFun(k);
  b = t->table[index];
  assert(b);
  t->table[index] = b->next;
  t->top=b->preTop;
  return b->key;
}

//print the whole hash table
void hashDump(hashTable t, void (*show)(void *key, void *value)) 
{
  void *k = t->top;
  int index = hashFun(k);
  binder b = t->table[index];
  if (b==NULL) 
    return;
  t->table[index]=b->next;
  t->top=b->preTop;
  show(b->key,b->value);
  hashDump(t,show);
  assert(t->top == b->preTop && t->table[index]==b->next);
  t->top=k;
  t->table[index]=b;
}

//the print fomula
void show(void *key, void *value)
{
    key=(char*)key;
    while((*key)!='\0')
    {
        printf("%c",(*key));
        key++;
    }
    printf(" : ");
    myPrint(value);
    printf("\n");

}

void myPrint(void* value)
{

}