#include <iostream>
#include "LeetCode/93_restoreIpAddresses.h"
#include "interview/atoi.h"

using std::endl;
using std::cout;
using std::string;



int main(int argc, char** args) {
    char target[] = "123";
    char target2[] = "-123";
    cout << atoi(target) << endl;
    cout << atoi(target2) << endl;
    cout << myAtoi(target) << endl;
    cout << myAtoi(target2) << endl;

}
