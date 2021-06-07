//
// Created by swagger on 2021/6/7.
//

#ifndef DATASTRUCT_3_LENGTHOFLONGESTSUBSTRING_H
#define DATASTRUCT_3_LENGTHOFLONGESTSUBSTRING_H

#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using std::set;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> set_;
        int lt = 0;
        int len = 0;
        for (int i=0; i<s.length(); i++){
            while ( set_.find( s[i] ) != set_.end() ){
                set_.erase( s[lt] );
                lt ++;
            }
            set_.insert( s[i] );
            len = len > set_.size() ? len : set_.size();
        }
        return len;
    }
};

#endif //DATASTRUCT_3_LENGTHOFLONGESTSUBSTRING_H
