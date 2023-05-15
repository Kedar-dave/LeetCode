#include<bits/stdc++.h>
#ifndef LEETCODE_H
#define LEETCODE_H

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> plusOne(vector<int>& digits);

string longestCommonPrefix(vector<string>& strs);

int rabinKarp(string pattern, string text);

int romanToInt(string s);

ListNode* mergeTwoListsIterative(ListNode* list1, ListNode* list2);
ListNode* mergeTwoListsRecursive(ListNode* l1, ListNode* l2);

vector<int> twoSum(vector<int> &nums, int target);
vector<int> twoSumFast(vector<int> &nums, int target);

bool isValid(string s);

int removeDuplicates(vector<int>& nums);

int mySqrt(int x);
int mySqrtUsingBinarySearch(int x);

int climbStairsFibonacci(int n);
int climbStairsDynamicProgramming(int n);

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n);

vector<int> inorderTraversalRecursive(TreeNode *root);
void inorderTraversalRecurser(TreeNode *node, vector<int> &res);
vector<int> inorderTraversalIterative(TreeNode *root);

bool isSymmetric(TreeNode *root);
bool treeCheck(TreeNode *left, TreeNode *right);

int maxDepth(TreeNode *root);
int maxDepthChecker(TreeNode *node, int depth);
#endif