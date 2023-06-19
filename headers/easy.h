#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <stack>
#include "structures.h"
using namespace std;

#ifndef EASY_H
#define EASY_H
struct TreeNode;
struct ListNode;
class HappyNumber;

int minDifference = INT_MAX;
TreeNode *prevNode; // Minimum Difference in BST

vector<int> plusOne(vector<int> &digits); // Plus One Problem

string longestCommonPrefix(vector<string> &strs); // Find (Prefix)

int rabinKarp(string pattern, string text); // Find Substring

int romanToInt(string s); // Roman to Integer

ListNode *mergeTwoListsIterative(ListNode *list1, ListNode *list2); // Merge two linked list (sorted)
ListNode *mergeTwoListsRecursive(ListNode *l1, ListNode *l2);
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);

vector<int> twoSum(vector<int> &nums, int target);
vector<int> twoSumFast(vector<int> &nums, int target);

bool isValid(string s); // Valid Parenthesis

int removeDuplicates(vector<int> &nums); // Remove duplicates

int mySqrt(int x); // Square root function
int mySqrtUsingBinarySearch(int x);

int climbStairsFibonacci(int n); // Making Change Problem
int climbStairsDynamicProgramming(int n);

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n); // Merge two sorted array

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

int maxProfit(vector<int> &prices); // Buy and Sell Stocks

bool isPalindrome(string s); // Palindrome

int singleNumber(vector<int> &nums); // Single Number

bool hasCycle(ListNode *head); // Linked List Cycle

int majorityElement(vector<int> &nums); // Majority Element using Boyer-Moore Voting method

int titleToNumber(string columnTitle); // Excel Sheet Column Number

uint32_t reverseBits(uint32_t n); // Reverse Bits

int hammingWeight(uint32_t n); // Hamming Distance

vector<string> summaryRanges(vector<int> &nums); // Summary Ranges

void inorderTraversalBST(TreeNode *node); // Minimum Absolute Difference in BST
int getMinimumDifference(TreeNode *root); // Minimum Absolute Difference in BST

int largestAltitude(vector<int> &gain); // Find the Highest Altitude
#endif