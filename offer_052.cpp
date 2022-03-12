#include "headl.h" 
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> ans;
    TreeNode* increasingBST(TreeNode* root) {
        get(root);
        TreeNode* cur = new TreeNode(-1);
        TreeNode* b = cur;
        for (int i = 0; i < ans.size() ; i++)
        {
            TreeNode* a = new TreeNode(ans[i]->val);
            cur->right = a;
            cur = cur->right;
        }
        return b->right;
    }
    void get(TreeNode* root)
    {
        if (not root) return;
        get(root->left);
        ans.push_back(root);
        get(root->right);
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
