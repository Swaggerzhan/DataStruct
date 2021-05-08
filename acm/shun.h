//
// Created by swagger on 2021/5/8.
//

#ifndef DATASTRUCT_SHUN_H
#define DATASTRUCT_SHUN_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <ctime>


class Docker{

private:

    struct Node{
        int data_;
        int count_;
        Node(int data): data_(data), count_(1){}
    };

    std::list<Node*> list;

public:

    void insert(std::vector<int>& input_data){
       for (int i=0; i<input_data.size(); i++){
           if (list.back() != nullptr && list.back()->data_ == input_data[i])
               list.back()->count_ ++;
           else
               list.push_back(new Node(input_data[i]));
       }
    }


    bool find_remove(int target){
        for (auto it = list.begin(); (*it)->data_ < target+1; it ++){
            if ((*it)->data_ == target){
                if ( (*it)->count_ == 1){
                    list.erase(it);
                    return true;
                }
                (*it)->count_ --;
                return true;
            }
        }
        return false;
    }

    int pop(){
        if (list.empty())
            return -1;

        int ret;
        if (list.front()->count_ == 1){
            ret = list.front()->data_;
            list.pop_front();
            return ret;
        }
        ret = list.front()->data_;
        list.front()->count_ --;
        return ret;
    }

};


bool solve(std::vector<int>& target, int k) {

    if (target.size() % k != 0)
        return false;

    std::sort(target.begin(), target.end());
    Docker docker;
    docker.insert(target);
    for (int i=0; i< (target.size() / k); i++){
        int base = docker.pop();
        for (int j=1; j<k; j++){
            if (!docker.find_remove(base + 1))
                return false;
            base ++;
        }
    }
    return true;
}



void getOutput(){

    int loop;
    std::cin >> loop;

    for (int i=0; i<loop; i++){
        std::vector<int> data;
        int k;
        std::cin >> k;
        int tmp;
        while (true){
            std::cin >> tmp;
            if (tmp == -1)
                break;
            data.push_back(tmp);
        }
        std::cout << solve(data, k) << std::endl;

    }
}


void getInputOnce(int seed, int count, int k){
    srand(seed);
    vector<int> output;
    for (int i=0; i<count; i++){
        int base = rand() % 5000;
        for (int idx=0; idx < k; idx ++){
            output.push_back(base);
            base ++;
        }
    }
    for (int i=0; i<output.size(); i++){
        int a = rand() % output.size();
        int b = rand() % output.size();
        swap(output[a], output[b]);
    }


    for (int tmp: output){
        std::cout << tmp << " ";
    }
    std::cout << "-1" << std::endl;


}






#endif //DATASTRUCT_SHUN_H
