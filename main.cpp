#include "Tree/Tree_test.h"
#include "Sort/SortTestHelper.h"
#include "acm/shun.h"

void you_shang(int **arr, int row, int col){

    for (int i=row; i<10; i--){
        for (int j=col; j < 10; j++){
            std::cout << arr[i][j] << "   ";
        }
        std::cout << std::endl;
    }
}



int main(int argc, char** args) {

    int seed = atoi(args[1]);
    int loop = atoi(args[2]);
    int count = atoi(args[3]);
    int k = atoi(args[4]);
    std::cout << loop << std::endl;
    for (int i=0; i<loop; i++){
        getInputOnce(seed, count, k);
        seed ++;
    }


}
