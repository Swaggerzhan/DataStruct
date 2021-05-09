//
// Created by swagger on 2021/5/9.
//

#ifndef DATASTRUCT_ISBN_H
#define DATASTRUCT_ISBN_H



#include <iostream>



void solve(std::string& target){

    int idx = 1;
    int data = 0;
    for (int i=0; i<11; i++){
        if (target[i] == '-')
            continue;
        data = data + (idx * (target[i] - '0'));
        idx ++;
        //printf("%d * %d = %d\n", idx, (target[i]-'0'), (idx * (target[i] - '0')));
    }
    int val = data % 11;
    char val_string;
    if (val == 10)
        val_string = 'x';
    else
        val_string = '0' + val;

    if (val_string == target[target.size()-1]){
        std::cout << "Right" << std::endl;
        return;
    }

    target[target.size()-1] = val_string;
    std::cout << target << std::endl;

}

#endif //DATASTRUCT_ISBN_H
