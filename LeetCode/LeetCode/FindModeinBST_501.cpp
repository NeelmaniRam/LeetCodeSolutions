
/*
Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [1,null,2,2]
Output: [2]
Example 2:

Input: root = [0]
Output: [0]
 


*/
class Solution {
public:
    unordered_map<int, int> mp;
    
    void dfs(TreeNode* root) {
        if(!root)
            return;
        
        dfs(root->left);
        mp[root->val]++;
        dfs(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        
        vector<int> result;
        int maxFreq = 0;
        
        for(auto &it : mp) {
            if(it.second > maxFreq) {
                maxFreq = it.second;
                result = {};
                result.push_back(it.first);
            } else if (it.second == maxFreq) {
                result.push_back(it.first);
            }
        }
        
        return result;
        
    }
};


Runtime
20ms
Beats 34.10%of users with C++
Memory
25.64MB
Beats 44.12%of users with C++



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

private:
    int last = INT_MIN;
    int count = 0;
    int max = 0;
    std::vector<int> modes;

    void traverse(TreeNode* node) {

        if (!node) return;

        traverse(node->left);

        if (last == node->val) {
            count++;
        } else {
            count = 1;
        }

        if (count > max) {
            max = count;
            modes.clear();
            modes.push_back(node->val);
        } else if (count == max) {
            modes.push_back(node->val);
        }

        last = node->val;

        traverse(node->right);

    }

public:
    vector<int> findMode(TreeNode* root) {
        traverse(root);
        return modes;
    }
};

Runtime
12ms
Beats 84.62%of users with C++
Memory
24.38MB
Beats 82.92%of users with C++