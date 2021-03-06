//
// Created by @Oscarluiis on 3/20/18.
//
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef HASHTABLE_HASH_H
#define HASHTABLE_HASH_H


class _hash{

private:
    static  const int tableSize = 4;

    struct item{

        string name;
        string drink;
        item* next;
    };

    item* HashTable[tableSize];


public:
    _hash();
    int Hash(string key);
    void AddItem(string name, string drink);
    int NumerOfItemInIndex (int index);
    void PrintTable();
    void PrintItemInIndex(int index);
    //void FindDrink(string name);
    void RemoveItem(string name);

};


#endif //HASHTABLE_HASH_H
