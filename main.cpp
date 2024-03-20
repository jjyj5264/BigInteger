#include <iostream>
#include <cstring>
#include <string>
using namespace std;

/**
 * Returns sum of two BigInteger(std:string type).
*/
std::string sum(std::string first, std::string second) {
    std::string result = "";

    // Make sure first is longer(bigger).
    if (first.length() < second.length()) { // swap
        std::string tmp = "";
        tmp = first;
        first = second;
        second = tmp;
    }

    int carry = 0;

    // Calculation for necessary fields.
    // char - '0': char to int
    // int + '0': int to char.
    for (int i = 0; i < second.length(); i++) { // runs second.length times
        int a = first[first.length() - 1 - i] - '0'; // Converts first's last element to int type.
        int b = second[second.length() - 1 - i] - '0'; // Same one.
        int c = a + b + carry; // At first loop, carry equals to zero.
        carry = c / 10; // 0 or 1.
        c = c % 10; // Cuts second digit of a + b.

        result.insert(0, std::to_string(c));
    }
    
    // Rest
    for (int i = second.length(); i < first.length(); i++) { // runs first.len - second.len
        int a = first[first.length() - 1 - i] - '0';
        int c = a + carry;
        carry = c / 10;
        c %= 10;

        result.insert(0, std::to_string(c));
    }

    // Last carry.
    if (carry > 0) {
        result.insert(0, "1");
    }

    return result;
}

/**
 * Returns subtraction of two BigInteger(std:string type).
*/
std::string sub(std::string first, std::string second) {
    std::string result = "";
    bool isNegative = false;
    int carry = 0;
    
    // Make sure first is longer(bigger).
    if (first.length() < second.length() || (first.length() == second.length() && first < second)) { // swap
        std::string tmp = "";
        tmp = first;
        first = second;
        second = tmp;
        
        isNegative = true;
    }

    // Calculation for necessary fields.
    for (int i = 0; i < second.length(); i++) { // runs second.length times
        int a = first[first.length() - 1 - i] - '0';
        int b = second[second.length() - 1 - i] - '0';
        int c = a - b - carry;

        if (c < 0) {
            carry = 1;
            c += 10; // if, a = 0, b = 9, carry = 1; 0 - 9 - 1 + 10 = 0.
        } else {
            carry = 0;
        }

        result.insert(0, std::to_string(c));
    }

    // Rest
    for (int i = second.length(); i < first.length(); i++) { // runs first.len - second.len
        int a = first[first.length() - 1 - i] - '0';
        int c = a - carry;

        if (c < 0) {
            carry = 1;
            c += 10;
        } else {
            carry = 0;
        }

        result.insert(0, std::to_string(c));
    }

    // Erase the annoying '0'.
    while (result[0] == '0') {
        result.erase(0, 1);
    }

    // Add '-' if isNegative is true.
    if (isNegative) {
        result.insert(0, "-");
    }

    return result;
}

int main() {
    string first = "";
    string second = "";
    
    cout << "First Number: ";
    cin >> first;
    cout << "Second Number: ";
    cin >> second;

    cout << "Sum of two numbers: " << sum(first, second) << endl;
    cout << "Sub of two numbers: " << sub(first, second) << endl;
}