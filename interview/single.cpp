//
// Created by Swagger on 2021/10/22.
//
#include "single.h"


Single::Single() {
    std::cout << "Single" << std::endl;
}


Single* Single::instance_ = new Single;

Single* Single::Instance() {
    return instance_;
}

