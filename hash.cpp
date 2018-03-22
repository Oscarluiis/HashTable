//
// Created by @Oscarluiis on 3/20/18.
//

#include <cstdlib>
#include <iostream>
#include <string>
#include "hash.h"
using namespace std;

_hash::_hash() {

    for (int i = 0; i < tableSize; i++){

        HashTable[i] = new item;
        HashTable[i]->name = "empty";
        HashTable[i]->drink = "empty";
        HashTable[i]->next = NULL;

    }


}

void _hash::AddItem(string name, string drink) {

    int index = Hash(name);

    if(HashTable[index]->name == "empty"){

        HashTable[index]->name = name;
        HashTable[index]->drink = drink;

    }else{
        item* Ptr = HashTable[index];
        item* n = new item;
        n->name=name;
        n->drink=drink;
        n->next=NULL;

        while (Ptr->next != NULL){

            Ptr = Ptr->next;
        }
        Ptr->next=n;
    }
}

int _hash::NumerOfItemInIndex(int index) {

    int count = 0;

    if(HashTable[index]->name == "empty"){

        return count;
    }
    else{
        count++;
        item* Ptr = HashTable[index];
        while(Ptr->next != NULL){

            count++;
            Ptr = Ptr->next;
        }
    }

    return count;
}


void _hash::PrintTable() {

    int number;

    for(int i = 0; i < tableSize; i++){

        number = NumerOfItemInIndex(i);
        cout<<"= = = = = = = = = = = = = = = \n";
        cout<<"Index = " << i << endl;
        cout<< HashTable[i]->name<<endl;
        cout<< HashTable[i]->drink<<endl;
        cout << "# Of Items = " << number << endl;
        cout<<"= = = = = = = = = = = = = = = \n";

    }

}


void _hash::PrintItemInIndex(int index) {

    item* Ptr = HashTable[index];

    if(Ptr->name == "empty"){

        cout << "Index " << index << " Is empty";
    }else{

        cout << "Index " << index << " contains the following items\n";

        while(Ptr != NULL){

            cout << "= = = = = = = = = = =\n";
            cout << Ptr->name << endl;
            cout << Ptr->drink<< endl;
            cout << "= = = = = = = = = = =\n";
            Ptr = Ptr -> next;

        }
    }

}

int _hash::Hash(string key){

    int _hash=0;
    int index;


    for(int i = 0; i < key.length(); i++){

        _hash = (_hash + (int)key[i]) * 17;

    }

    index = _hash % tableSize;
    return index;


}

void _hash::RemoveItem(string name) {

    int index = Hash(name);
    item* delPtr;
    item* P1;
    item* P2;

    /*
     *
     * Case 0 - Bucket is empty
     *
     * Case 1 - Only 1 item contained in bucket n' that item has matching name
     *
     * Case 2 - Match is located in the first item in the bucket but there are more items in the bucket
     *
     * Case 3 - Bucket  contains items but first item isn't a match
     *      3.1 -   ≠ match
     *      3.2 -   Found!
     *
     *
     *
     * */

    //Case 0 ==========

    if(HashTable[index]->name == "empty" && HashTable[index]->drink == "empty"){

        cout << name << " Wasn't found in the HashTable\n";

    }

    //Case 1 =========

    else if(HashTable[index] -> name == name && HashTable[index] -> next== NULL){

        HashTable[index]->name == "empty";
        HashTable[index]->drink == "empty";

        cout<< name<< " Was removed from the Hash Table\n";

    }

    //Case 2 =======

    else if(HashTable[index] -> name == name ){

        delPtr = HashTable[index];
        HashTable[index] = HashTable[index]->next;
        delete delPtr;

        cout<< name << " Was removed from the Hash Table\n";

    }

    // Case 3 ============

    else{

        P1 = HashTable[index]->next;
        P2 = HashTable[index];

        while(P1 != NULL && P1->name != name){

            P2 = P1;
            P1 = P1->next;

        }

        // Case 3.1 =============

        if(P1 == NULL){

            cout << name << " Wasn't found in the HashTable\n";

        }

        else{

            delPtr = P1;
            P1 = P1->next;
            P2->next = P1;

            delete delPtr;
            cout<< name << " Was removed from the Hash Table\n";
        }

    }
}

/*void _hash::FindDrink(string name) {

    int index = Hash(name);
    bool foundName = false;
    string drink;
    item* Ptr = HashTable[index];

    while (Ptr != NULL){

        if(Ptr->name == name){

            foundName = true;
            drink = Ptr->drink;

        }
        Ptr = Ptr->next;
    }
    if(foundName == true){

        cout << "Favorite drink = " << drink << endl;

    }else{

        cout << name << "'s info wasn't found in the Hash Table\n";

    }

}

*/