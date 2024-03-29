/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool checkInorder(TreeNode *root)
    {
        stack<TreeNode*>st;
        
        TreeNode *prev = NULL;
        while(root != NULL || !st.empty())   
        {
            
            while(root != NULL)
            {
                st.push(root);
                root = root->left;
            }
            
            root = st.top();
            st.pop();
            if(prev != NULL && prev->val >= root->val) return false;
            prev = root;
            root = root->right;
        }
        return true;
    }
    
    
    
    bool isValidBST(TreeNode* root) {
     
        if(!root) return true;
        
        return checkInorder(root);
        
    }
};