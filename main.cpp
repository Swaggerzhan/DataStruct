#include "Tree/Tree_test.h"
#include "Sort/SortTestHelper.h"
#include "LeetCode/101_isSymmetric.h"

int main() {

    Solution s;
    TreeNode* root = test_case_101();

    cout << s.isSymmetric(root) << endl;

}
