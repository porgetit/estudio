#include <iostream>
#include "../../utilities.h"

using namespace std;

int main() {
    StringTools tools;
    string input = "Hello, World!";
    vector<char> allowed_chars = {'H', 'l', 'o', ','};
    tools.filterString(input, allowed_chars);
    cout << input << endl;

    string input2 = "this,is,a,test";
    vector<string> result = tools.splitString(input2, ',');
    for (auto& str : result) {
        cout << str << endl;
    }

    string input3 = "123.45";
    if (tools.isNumber(input3)) {
        cout << "Input is a number" << endl;
    } else {
        cout << "Input is not a number" << endl;
    }

    string input4 = "&&";
    if (tools.isBinaryOperator(input4)) {
        cout << "Input is a binary operator" << endl;
    } else {
        cout << "Input is not a binary operator" << endl;
    }

    string input5 = "hello world";
    tools.toUpperCase(input5);
    cout << input5 << endl;

    string input6 = "HELLO WORLD";
    tools.toLowerCase(input6);
    cout << input6 << endl;

    return 0;
}
