#include <cstdlib>
#include <iostream>
#include <string>

#include "hash.h"

using namespace std;

int main() {

    _hash Hashy;
    string name = "";

    //* Random names... Only for example, u can try it with differents names, results will be the same.
    Hashy.AddItem("Paul", "Locha");
    Hashy.AddItem("Kim", "Iced Mocha");
    Hashy.AddItem("Emma", "Strawberry Smoothy");
    Hashy.AddItem("Annie", "Hot Chocolate");
    Hashy.AddItem("Sarah", "Passion Tea");
    Hashy.AddItem("Pepper", "Caramel Mocha");
    Hashy.AddItem("Mike", "Chai Tea");
    Hashy.AddItem("Steve", "Apple Cider");
    Hashy.AddItem("Bill", "Root Beer");
    Hashy.AddItem("Marrie", "Skinny Late");
    Hashy.AddItem("Susan", "Water");
    Hashy.AddItem("Joe", "Green Tea");

    Hashy.PrintItemInIndex(2); //* Only to print the table.

   // Hashy.PrintItemInIndex(1); //* To print the items that are contains in index, u can change the value into ().

   /* while (name != "exit"){ //* That's to find in the Hash Table...

        cout << "Search for :";
        cin>> name;

        if(name != "exit"){

            Hashy.FindDrink(name);
        }
    }

*/

    while (name != "exit"){ //* That's to find in the Hash Table...

        cout << "Remove :";
        cin>> name;

        if(name != "exit"){

            Hashy.RemoveItem(name);
        }
    }

    Hashy.PrintItemInIndex(2);

    return 0;
}