/*
Given the root of a binary tree, construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way, and return it.

Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.

 

Example 1:


Input: root = [1,2,3,4]
Output: "1(2(4))(3)"
Explanation: Originally, it needs to be "1(2(4)())(3()())", but you need to omit all the unnecessary empty parenthesis pairs. And it will be "1(2(4))(3)"
Example 2:


Input: root = [1,2,3,null,4]
Output: "1(2()(4))(3)"
Explanation: Almost the same as the first example, except we cannot omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-1000 <= Node.val <= 1000

*/




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
  string tree2str(TreeNode* t) {
    return dfs(t);
  }

 private:
  string dfs(TreeNode* root) {
    if (root == nullptr)
      return "";

    const string& rootStr = to_string(root->val);
    if (root->right)
      return rootStr + "(" + dfs(root->left) + ")(" + dfs(root->right) + ")";
    if (root->left)
      return rootStr + "(" + dfs(root->left) + ")";
    return rootStr + "";
  }
};


Runtime
15ms
Beats 57.95% of users with C++
Memory
26.74MB
Beats 47.94% of users with C++










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
    void dfs(TreeNode* root, string& s){
        if(!root) return;
        s+=to_string(root->val);
        if(root->left || root->right){
            s+="(";
            dfs(root->left,s);
            s+=")";
        }
        if(root->right){
            s+="(";
            dfs(root->right,s);
            s+=")";
        }
    }
    string tree2str(TreeNode* root) {
        string s="";
        dfs(root,s);
        return s;
    }
};




Runtime
11ms
Beats 79.87% of users with C++
Memory
23.86MB
Beats 73.63% of users with C++



