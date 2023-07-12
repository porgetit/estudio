#include <iostream>
#include <string.h>

using namespace std;

bool XO(const std::string& sentence) {
    string strCopy = sentence; int amountOhs = 0, amountExes = 0;
    int len = strCopy.length();


    for (int i = 0; i < len; i++) {
        amountOhs += tolower(strCopy[i]) == 'o' ? 1 : 0;
        amountExes += tolower(strCopy[i]) == 'x' ? 1 : 0;
    }


    return amountExes == amountOhs;
}

