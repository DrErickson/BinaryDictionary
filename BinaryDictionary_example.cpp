//
// Created by we7289 on 2/18/2021.
//

#include <iostream>
#include "BinaryDictionary.h"

int main(void) {

    BinaryDictionary binDictionary;

    binDictionary.Add("0010110");
    binDictionary.Add("1101001");
    binDictionary.Add("111");
    binDictionary.Add("001");

    binDictionary.SaveDictionary("saved_dictionary.txt");

    BinaryDictionary binDict2;
    binDict2 = binDictionary;
    binDictionary.SaveDictionary("save_check.txt");

    return 0;
}
