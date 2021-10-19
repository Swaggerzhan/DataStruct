//
// Created by Swagger on 2021/10/19.
//

#ifndef DATASTRUCT_ATOI_H
#define DATASTRUCT_ATOI_H

int myAtoi(char* target){
    int sign = 1;
    if (*target == '-'){
        sign = -1;
        target ++;
    }
    if (*target == '+'){
        target ++;
    }
    int ret = 0;
    while ( *target >= '0' && *target <= '9') {
         ret = ret * 10 + (*target - '0');
         target ++;
    }
    return ret * sign;

}
#endif //DATASTRUCT_ATOI_H
