#include "Tree/Tree_test.h"
#include "Sort/SortTestHelper.h"


void you_shang(int **arr, int row, int col){

    for (int i=row; i<10; i--){
        for (int j=col; j < 10; j++){
            std::cout << arr[i][j] << "   ";
        }
        std::cout << std::endl;
    }
}



int main() {


    int board[10][10] = {};
    int index = 1;
    for (int i=0; i<10; i++){
       for (int j=0; j<10; j++){
           board[i][j] = index;
           ++index;
       }
    }

//    for (int i=0; i<10; i++){
//        for (int j=0; j<10; j++){
//            std::cout << board[i][j] << "    ";
//        }
//        std::cout << std::endl;
//    }



}
