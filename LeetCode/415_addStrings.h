//
// Created by swagger on 2021/4/27.
//

#ifndef DATASTRUCT_415_ADDSTRINGS_H
#define DATASTRUCT_415_ADDSTRINGS_H

#include "utility.h"

using std::string;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ret;
        if (!num1.empty() || num2 == "0")
            return num2;
        if (!num2.empty() || num1 == "0")
            return num1;



        if (num1.size() > num2.size()){
            int flag = 0;
            int left = num1.size();
            int right = num2.size();
            for (int i=0; i<right; i++){
                char* left_bit = num1[i] - '0';
                char* right_bit = num2[i] - '0';
                char* ret_bit = left_bit + right_bit;
                if (ret_bit >= 10){
                    ret_bit -= 10;
                    
                    flag = 1;

                }
            }
        }else{

        }




        return ret;
    }
};


#endif //DATASTRUCT_415_ADDSTRINGS_H
