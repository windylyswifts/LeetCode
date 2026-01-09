/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

typedef struct {
    int depth;
    struct TreeNode* node;
} Result;

Result dfs(struct TreeNode* node) {
    if (node == NULL) {
        Result r = {0, NULL};
        return r;
    }
    
    Result leftResult = dfs(node->left);
    Result rightResult = dfs(node->right);
    if (leftResult.depth > rightResult.depth) {
        Result res = {leftResult.depth + 1, leftResult.node};
        return res;
    }
    else if (rightResult.depth > leftResult.depth) {
        Result res = {rightResult.depth + 1, rightResult.node};
        return res;
    }
    else {
        Result res = {leftResult.depth + 1, node};
        return res;
    }
}

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
    return dfs(root).node;
}