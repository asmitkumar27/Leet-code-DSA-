class Solution {
public:
    int currCount = 0;
    int maxCount = 0;
    TreeNode* prev = NULL;
    vector<int> result;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        // Process current node
        if (prev && prev->val == root->val) {
            currCount++;
        } else {
            currCount = 1;
        }

        if (currCount > maxCount) {
            maxCount = currCount;
            result = {root->val}; // reset
        } else if (currCount == maxCount) {
            result.push_back(root->val);
        }

        prev = root;

        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return result;
    }
};