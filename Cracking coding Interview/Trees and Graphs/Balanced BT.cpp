    bool isBalanced(TreeNode* root) {
        bool result = true;
        check(root, result);
        return result;
    }
    
    int check(TreeNode *root, bool &result) {
        if(!root || !result) return 0;
        int l = check(root->left, result) + 1;
        int r = check(root->right, result) + 1;
        if(abs(l-r) > 1) {result = false;return 0;}
        return max(l, r);
    }
