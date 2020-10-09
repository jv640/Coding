/*
  Description : : Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth 
                  (e.g., if you have a tree with depth 0, you'll have 0 linked lists). 
*/

// code
  /**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return a lists of linked list
     */
    vector<ListNode*> binaryTreeToLists(TreeNode* root) {
        // Write your code here;
        vector<ListNode*> result;
        if(!root)return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            ListNode* list = new ListNode(0);
            ListNode* temp = list;
            for(int i = 0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                temp->next = new ListNode(node->val);
                temp = temp->next;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            result.push_back(list->next);
        }
        return result;
    }
};
