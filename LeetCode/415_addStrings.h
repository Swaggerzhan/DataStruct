//
// Created by swagger on 2021/4/27.
//

#ifndef DATASTRUCT_415_ADDSTRINGS_H
#define DATASTRUCT_415_ADDSTRINGS_H

#include "utility.h"
#include <iostream>

using std::string;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ret;
        if (num2.size() > num1.size())
            std::swap(num1, num2);
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        bool flag = false;
       for (int i=0; i<num1.size(); i++){
           if (i >= num2.size()){
               char tmp = num1[i] + flag - '0';
               flag = tmp >= 10;
               tmp %= 10;
               ret += tmp + '0';
               continue;
           }
           char tmp = num1[i] + num2[i] - '0' - '0' + flag;
           flag = tmp >= 10;
           tmp %= 10;
           ret += tmp + '0';
       }
       if (flag)
           ret += "1";
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};


#endif //DATASTRUCT_415_ADDSTRINGS_H
