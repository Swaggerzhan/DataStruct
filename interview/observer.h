//
// Created by Swagger on 2021/10/22.
//

#ifndef DATASTRUCT_OBSERVER_H
#define DATASTRUCT_OBSERVER_H
#include <vector>
#include <iostream>


class Person{
public:
    virtual seeNews(){
        std::cout << "see News" << std::endl;
    }
};

class News{
public:

    News(){

    }
    virtual subscribe(Person* person){
        subscriber_.push_back(person);
    }
    virtual notifyAll(){
        for (auto person: subscriber_){
            person->seeNews();
        }
    }
    ~News(){
    }

private:
    std::vector<Person*> subscriber_;

};

#endif //DATASTRUCT_OBSERVER_H
