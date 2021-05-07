#include <iostream>
#include <vector>



class Solution {
public:

	vector<vector<string>> board;

	int N;

	vector<vector<string>> ret;

	void backTrack(vector<string>& tmp_ans, int rows){


		for (int i=0; i<N; i++){


			board[rows][i] = 'Q';
			backTrack(tmp_ans, i);
		}
	}




    vector<vector<string>> solveNQueens(int n) {

    	N = n;
    	for (int i=0; i<n; i++)
    		board.push_back(vector<string>(n, "."));
    	






    }
};