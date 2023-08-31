#include <iostream>
#include <climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

int maxPathSumUtil(TreeNode* root, int& result) {
    if (!root)
        return 0;

    int left = maxPathSumUtil(root->left, result);
    int right = maxPathSumUtil(root->right, result);

    // Calculate the maximum sum that can be achieved considering the current node as the root of the path
    int max_single = std::max(std::max(left, right) + root->val, root->val);

    // Calculate the maximum sum path that passes through the current node
    int max_top = std::max(max_single, left + right + root->val);

    // Update the result if the current path's sum is greater
    result = std::max(result, max_top);

    // Return the maximum sum that can be extended further
    return max_single;
}

int maxPathSum(TreeNode* root) {
    if (!root)
        return 0;

    int result = INT_MIN;
    maxPathSumUtil(root, result);
    return result;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(-10);
    root->left->right = new TreeNode(4);

    int maxSum = maxPathSum(root);
    std::cout << "Maximum path sum: " << maxSum << std::endl;

    // Clean up memory
    // You might want to implement a proper memory deallocation function
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
