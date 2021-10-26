//
// Created by Swagger on 2021/10/22.
//

#ifndef DATASTRUCT_SINGLE_H
#define DATASTRUCT_SINGLE_H
#include <iostream>

class Single{
public:
    static Single* Instance();

private:
    Single();
private:
    static Single* instance_;
};

#endif //DATASTRUCT_SINGLE_H
