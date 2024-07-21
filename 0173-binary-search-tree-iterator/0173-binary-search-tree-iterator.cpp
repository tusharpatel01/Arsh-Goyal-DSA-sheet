/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class BSTIterator {

private:
    stack<TreeNode*> nodeStack;

    void pushAllLeft(TreeNode* node) {
        while (node != NULL) {
            nodeStack.push(node);
            node = node->left;
        }
    }

    public:
        BSTIterator(TreeNode * root) { pushAllLeft(root); }

        bool hasNext() { return !nodeStack.empty(); }

        int next() {
            TreeNode* topNode = nodeStack.top();
            nodeStack.pop();
            if (topNode->right != NULL) {
                pushAllLeft(topNode->right);
            }
            return topNode->val;
        }
    };

    TreeNode* insert(TreeNode* root, int key) {
        if (root == NULL) {
            return new TreeNode(key);
        }
        if (key < root->val) {
            root->left = insert(root->left, key);
        } else if (key > root->val) {
            root->right = insert(root->right, key);
        }
        return root;
    }



/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */