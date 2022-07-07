#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <string>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int height(TreeNode *root) {
    if (!root) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
        return -1;
    } else {
        return std::max(leftHeight, rightHeight) + 1;
    }
}

// * O(n): height 为有效高度
bool isBalanced(TreeNode *root) {
    return height(root) >= 0;
}

// * O(n^2): 重复计算高度
// int getTreeHight(TreeNode *root) {
//     if (!root) return 0;
//     else return max(getTreeHight(root->left), getTreeHight(root->right)) + 1;
// }

// bool isBalanced(TreeNode* root) {
//     if (!root) return true;
//     return abs(getTreeHight(root->left) - getTreeHight(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);
// }



int main() {
    return 0;
}
