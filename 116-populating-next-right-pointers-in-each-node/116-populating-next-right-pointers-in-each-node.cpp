/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    void populateRight(Node *root)
    {
        if(!root) return;
        
        if(root->left != NULL) root->left->next = root->right;
        if(root->right != NULL && root->next != NULL) 
                               root->right->next = root->next->left;
        populateRight(root->left);
        populateRight(root->right);
    }
    
    Node* connect(Node* root) {
        populateRight(root);
        return root;
    }
};