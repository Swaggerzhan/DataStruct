//
// Created by Swagger on 2021/8/11.
//

#ifndef DATASTRUCT_93_RESTOREIPADDRESSES_H
#define DATASTRUCT_93_RESTOREIPADDRESSES_H

#include <vector>
#include <iostream>

using std::endl;
using std::cout;
using std::vector;
using std::string;

class Solution{
public:

    vector<string> restoreIpAddresses(string s) {
        vector<string> ip;
        dfs(s, 0, ip);
        return ret;
    }


    void dfs(string& target, int index, vector<string>& ip){
        /* ip已经满，或者字符串全部用光 */
        if ( ip.size() == 4 || index == target.size()){
            if ( ip.size() == 4 && index == target.size() ){
                // 同时满足才可
                toRet(ip);
            }
            return;
        }


        for (int i=1; i<=3; i++){
            if (index + i > target.size() )
                break;
            string tmp = target.substr(index, i);
            int tmp_val = atoi(tmp.c_str());
            if ( tmp_val > 255 || (tmp[0] == '0' && tmp.size() > 1))
                continue;
            ip.push_back(tmp);
            dfs(target, index+i, ip);
            ip.pop_back();
        }

    }

    void toRet(vector<string>& target){
        string res;
        for (int i=0; i<target.size()-1; i++){
            res += target[i] + ".";
        }
        res += target[target.size()-1];
        ret.push_back(res);
    }

    vector<string> ret;

};

#endif //DATASTRUCT_93_RESTOREIPADDRESSES_H
