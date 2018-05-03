/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> allNodeValues;
        preorderTrav(root, allNodeValues);
        return allNodeValues;
    }
    
    void preorderTrav(TreeNode *root, vector<int> &allNodeValues) {
        if(!root) return;
        allNodeValues.push_back(root->val);
        preorderTrav(root->left, allNodeValues);
        preorderTrav(root->right, allNodeValues);
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> allNodeValues;
        TreeNode *cur = root;
        stack<TreeNode*> s;
        
        while(cur || !s.empty()) {
            if(!cur) {
                cur = s.top();
                s.pop();
            }
            allNodeValues.push_back(cur->val);
            if(cur->right) s.push(cur->right);
            cur = cur->left;
        }
        
        return allNodeValues;
    }
};