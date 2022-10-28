#include "hashTable.h"

HashTable::HashTable(int cap)
{
    totalElements = cap;
    table = new list<string>[totalElements];
}

HashTable::~HashTable()
{
    
}

void HashTable::insert(string key, int value)
{
    value = getHash(key);
    table[value].push_back(key);
    
}

void HashTable::remove(string key)
{
    int x = getHash(key);
    list<string>::iterator it;
    for(it = table[x].begin(); it != table[x].end(); it++)
    {
        if(*it == key)
            break;
    }

    if(it != table[x].end())
        table[x].erase(it);
}

bool HashTable::containsKey(string key) const
{
    int x = getHash(key);
    list<string>::iterator it;

    for(it = table[x].begin(); it != table[x].end(); it++)
    {
        if(*it == key)
        {
            return true;
        }
    }
    return false;
}

 int HashTable::getHash(string key) const
   {
      int total = 0;
      int l = key.length();
      for(int i = 0; i < l; i++)
      {
         total += key[i];
      }

      return total % totalElements;
   }

int &HashTable::operator[](string key)
{
    list<string>::iterator it;
    int temp = 0;

    int x = getHash(key);
    table[x].push_back(key);

    for(it = table[x].begin(); it != table[x].end(); it++)
    {
        temp++;
    }

    return temp;
}