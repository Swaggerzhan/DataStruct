//
// Created by swagger on 2021/5/8.
//

#ifndef DATASTRUCT_PERMU_H
#define DATASTRUCT_PERMU_H

#include <iostream>
#include <vector>


void print(std::vector<int>& tmp){
    for (int i: tmp){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}


void findCombiation(std::vector<int>&nums, std::vector<int>&tmp_ans, std::vector<bool>& used){

    if (tmp_ans.size() == nums.size()){
        print(tmp_ans);
        return;
    }


    for (int i=0; i<nums.size(); i++){

        /* 进行剪枝操作 */
        if ( i > 0 && nums[i] == nums[i-1] && used[i-1] == false)
            continue;

        if ( used[i] == false){
            tmp_ans.push_back(nums[i]);
            used[i] = true;
            findCombiation(nums, tmp_ans, used);
            used[i] = false;
            tmp_ans.pop_back();
        }
    }
}



void solve(){
    int loop;
    std::cin >> loop;
    std::vector<int> nums;
    for (int i=0; i<loop; i++){
        int tmp;
        nums.clear();
        while (true){
            std::cin >> tmp;
            if (tmp == -1)
                break;
            nums.push_back(tmp);
        }
        std::vector<bool> used = std::vector<bool>(nums.size(), false);
        std::vector<int> tmp_ans;
        findCombiation(nums, tmp_ans, used);
    }


}


void getInput(int seed, int loop, int count){
    srand(seed);
    std::cout << loop << std::endl;
    for (int i=0; i< loop; i++){
        for (int j=0; j<count; j++){
            std::cout << (rand() % 20) + 1 << " ";
        }
        std::cout << -1 << std::endl;
    }
}




#endif //DATASTRUCT_PERMU_H
