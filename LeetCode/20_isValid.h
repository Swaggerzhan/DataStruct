//
// Created by Swagger on 2021/7/26.
//

#ifndef DATASTRUCT_20_ISVALID_H
#define DATASTRUCT_20_ISVALID_H
#include <iostream>
#include <stack>
using std::string;
using std::stack;

class Solution {
public:
    bool isValid(string s) {

        if ( s.size() % 2 == 1)
            return false;

        stack<char> tmp;
        for (int i=0; i<s.size(); i++){
            if ( s[i] == '['){
                tmp.push(']');
            }else if ( s[i] == '{'){
                tmp.push('}');
            }else if ( s[i] == '('){
                tmp.push(')');
            }else {
                std::cout << "stack: " << tmp.top() << std::endl;
                std::cout << "s[i]: " << s[i] << std::endl;
                if ( tmp.empty() || (tmp.top() != s[i]) ){
                    return false;
                }
                else
                    tmp.pop();
            }
        }
        return tmp.empty();
    }
};

#endif //DATASTRUCT_20_ISVALID_H
