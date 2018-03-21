#include <cstdlib>
#include <iostream>
#include <string>

#include "hash.h"

using namespace std;

int main() {

    _hash Hashy;


    Hashy.AddItem("Oscar", "Water");
    Hashy.AddItem("Victor", "Wine");
    Hashy.AddItem("Juan", "Tea");
    Hashy.AddItem("Carlos", "Hot Chocolate");
    Hashy.AddItem("Sarah", "Strawberry Smoothy");
    Hashy.AddItem("Cortana", "Apple Juice");
    Hashy.AddItem("Baby", "Green Tea");
    Hashy.AddItem("Andy", "Cola");
    Hashy.AddItem("Miguel", "Beer");
    Hashy.AddItem("Marrie", "Orange Juice");
    Hashy.AddItem("Stephen", "Coffe");
    Hashy.AddItem("Jane", "Iced Mocha");

    Hashy.PrintTable();





    return 0;
}