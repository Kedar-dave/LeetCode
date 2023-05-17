#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <stack>
using namespace std;
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

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<int> plusOne(vector<int> &digits); // Plus One Problem

string longestCommonPrefix(vector<string> &strs);// Find (Prefix)

int rabinKarp(string pattern, string text);// Find Substring

int romanToInt(string s);// Roman to Integer

ListNode *mergeTwoListsIterative(ListNode *list1, ListNode *list2);// Merge two linked list (sorted)
ListNode *mergeTwoListsRecursive(ListNode *l1, ListNode *l2);

ListNode *swapPairs(ListNode *head);

vector<int> twoSum(vector<int> &nums, int target);
vector<int> twoSumFast(vector<int> &nums, int target);

bool isValid(string s); // Valid Parenthesis

int removeDuplicates(vector<int> &nums); // Remove duplicates

int mySqrt(int x); //Square root function
int mySqrtUsingBinarySearch(int x);

int climbStairsFibonacci(int n); // Making Change Problem
int climbStairsDynamicProgramming(int n);

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n);// Merge two sorted array

vector<int> inorderTraversalRecursive(TreeNode *root); // Tree traversal Inorder 
void inorderTraversalRecurser(TreeNode *node, vector<int> &res);
vector<int> inorderTraversalIterative(TreeNode *root);

bool isSymmetric(TreeNode *root); // Check is tree is symmetric
bool treeCheck(TreeNode *left, TreeNode *right);

int maxDepth(TreeNode *root); // Tree depth checker
int maxDepthChecker(TreeNode *node, int depth);

TreeNode *sortedArrayToBST(vector<int> &nums); // Sorted array to binary search tree
TreeNode *BST(vector<int> &nums, int start, int end); 

vector<vector<int>> generatePascalsTriangle(int numRows); // Pascals Triangle

int maxProfit(vector<int>& prices); // Buy and Sell Stocks

bool isPalindrome(string s); //Palindrome

int pairSum(ListNode *head); // Twin Pair Sum

#endif