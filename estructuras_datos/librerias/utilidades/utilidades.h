#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <iostream>
#include <string>
#include <vector>

class string_tools {
public:
    static vector<string> splitString(string, char);
    static bool isNumber(string);
    static bool isBinaryOperator(string);
};

// splitString(string, char) devuelve el vector de las subcadenas separadas por el caracter indicado.
vector<string> string_tools::splitString(string input, char spliter) {
    vector<string> output;
    string temp = "";

    for (int index = 0; index < input.size(); index++) {
        if (input[index] == spliter) {
            output.push_back(temp);
            temp = "";
        } else {
            temp += input[index];
        }
    }

    output.push_back(temp);

    return output;
}

bool string_tools::isNumber(string input) {
    for (int i = 0; i < input.length(); i++) { // Aplicar reg_exp para validar todo el conjunto R
        if (!isdigit(input[i])) {
            return false;
        }
    }

    return true;
}

bool string_tools::isBinaryOperator(string input) {
    int i = 0;
    if (input[i] == '+' || input[i] == '-') {
        return true;
    } else if (input[i] == '*' || input[i] == '/') {
        return true;
    } else if (input[i] == '^') {
        return true;
    }
    
    return false;
}

#endif