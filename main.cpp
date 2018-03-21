#include <cstdlib>
#include <iostream>
#include <string>

#include "hash.h"

using namespace std;

int main() {

    int index;
    _hash hashObj;

    index =  hashObj.Hash("Oscar");

    cout <<"Index = " << index << endl;




    return 0;
}