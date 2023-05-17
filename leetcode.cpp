#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <stack>
#include "leetcode.h"
using namespace std;
// Definition for a binary tree node.
struct TreeNode;
struct ListNode;
vector<int> plusOne(vector<int> &digits)
{
    int n = digits.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (digits[i] < 9)
        {
            digits[i]++;
            return digits;
        }
        else
        {
            digits[i] = 0;
        }
    }
    vector<int> new_digits(n + 1, 0);
    new_digits[0] = 1;
    return new_digits;
}
string longestCommonPrefix(vector<string> &strs)
{
    string res = strs[0];
    int len = res.length();
    for (auto i = 0; i < strs.size(); i++)
    {
        while (strs[i].find(res) != 0)
        {
            res = res.substr(0, len - 1);
            len--;

            if (res.empty())
            {
                return "";
            }
        }
    }
    return res;

    return "";
}
int rabinKarp(string needle, string haystack)
{
    int m = needle.length();
    int n = haystack.length();
    int window_start = 0;

    for (window_start = 0; window_start <= n - m; window_start++)
    {
        int i;
        for (i = 0; i < m; i++)
        {
            if (needle[i] != haystack[window_start + i])
            {
                break;
            }
        }
        if (i == m)
        {
            return window_start;
        }
    }
    return -1;
}
int romanToInt(string s)
{
    int sum = 0;
    unordered_map<char, int> conv = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};
    for (int i = 0; i < s.size(); i++)
    {
        if (conv[s[i]] < conv[s[i + 1]])
        {
            sum += conv[s[i + 1]] - conv[s[i]];
            i++;
        }
        else
            sum += conv[s[i]];
    }
    return sum;
}
ListNode *mergeTwoListsIterative(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }
    ListNode *list3 = new ListNode();
    ListNode *curr = list3;
    // The first node is initialized with 0 value
    // change the first node
    if (list1->val <= list2->val)
    {
        curr->val = list1->val;
        list1 = list1->next;
    }
    else
    {
        curr->val = list2->val;
        list2 = list2->next;
    }
    // append merged sorted list until n-2 size
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val <= list2->val)
        {
            curr->next = new ListNode(list1->val);
            list1 = list1->next;
        }
        else
        {
            curr->next = new ListNode(list2->val);
            list2 = list2->next;
        }
        curr = curr->next;
    }
    // append last element
    if (list1 != NULL)
    {
        curr->next = list1;
    }
    if (list2 != NULL)
    {
        curr->next = list2;
    }
    return list3;
}
ListNode *mergeTwoListsRecursive(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL)
        return l2;

    if (l2 == NULL)
        return l1;

    if (l1->val <= l2->val)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }

    else
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> Index;
    int flag = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (i == j)
                continue;
            else if ((nums.at(i) + nums.at(j)) == target)
            {
                Index.push_back(i);
                Index.push_back(j);
                flag = 1;
                break;
            }
        }
        if (flag)
            break;
    }
    return Index;
}
vector<int> twoSumFast(vector<int> &nums, int target)
{
    unordered_map<int, int> visited;
    int len = nums.size();
    for (int i = 0; i < len; ++i)
    {
        int n = nums[i];
        int complement = target - n;
        if (visited.count(complement))
        {
            return {visited[complement], i};
        }
        visited[n] = i; // assume that each input would have exactly one solution
    }
    return {};
}
bool isValid(string s)
{
    stack<char> S;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
            S.push(c);
        else
        {
            if (S.empty())
            {
                return false;
            }
            if (S.top() == '(' && c == ')')
            {
                S.pop();
            }
            else if (S.top() == '[' && c == ']')
            {
                S.pop();
            }
            else if (S.top() == '{' && c == '}')
            {
                S.pop();
            }
            else
                return false;
        }
    }
    return S.empty();
}
int removeDuplicates(vector<int> &nums)
{
    vector<int> V;
    for (int i = 0; i < nums.size(); i++)
    {
        if (V.empty() || V.back() != nums[i])
        {
            V.push_back(nums[i]);
        }
    }
    int i = 0;
    while (!V.empty())
    {
        nums[i++] = V.front();
        V.erase(V.begin());
    }
    return i;
}
int mySqrt(int x)
{
    if (x == 0 || x == 1)
        return x;
    long long i = 1;
    long long res = 1;
    while (res <= x)
    {
        i++;
        res = i * i;
    }
    return i - 1;
}
int mySqrtUsingBinarySearch(int x)
{
    if (x == 0 || x == 1)
    {
        return 0;
    }
    int left = 1, right = x;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (mid > x / mid)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return right;
}
int climbStairsFibonacci(int n)
{
    double phi = (1 + sqrt(5)) / 2;
    return round(pow(phi, n + 1) / sqrt(5));
}
int climbStairsDynamicProgramming(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
    while (j >= 0)
    {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

vector<int> inorderTraversalRecursive(TreeNode *root)
{
    vector<int> res;
    inorderTraversalRecurser(root, res);
    return res;
}
void inorderTraversalRecurser(TreeNode *node, vector<int> &res)
{
    if (node == NULL)
    {
        return;
    }
    inorderTraversalRecurser(node->left, res);
    res.push_back(node->val);
    inorderTraversalRecurser(node->right, res);
}
vector<int> inorderTraversalIterative(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> s;
    TreeNode *curr = root;
    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        res.push_back(curr->val);
        curr = curr->right;
    }
    return res;
}
bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }
    return treeCheck(root->left, root->right);
}
bool treeCheck(TreeNode *left, TreeNode *right)
{
    if (left == NULL && right == NULL)
        return true;
    if (left == NULL || right == NULL || left->val != right->val)
        return false;
    return treeCheck(left->left, right->right) && treeCheck(left->right, right->left);
}
int maxDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return maxDepthChecker(root, 0);
}
int maxDepthChecker(TreeNode *node, int depth)
{
    if (node == NULL)
    {
        return depth;
    }
    int leftDepth = maxDepthChecker(node->left, depth + 1);
    int rightDepth = maxDepthChecker(node->right, depth + 1);
    return max(leftDepth, rightDepth);
}
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    return BST(nums, 0, nums.size() - 1);
}
TreeNode *BST(vector<int> &nums, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }
    int mid = start + (end - start) / 2;
    TreeNode *node = new TreeNode(nums[mid]);
    node->left = BST(nums, start, mid - 1);
    node->right = BST(nums, mid + 1, end);

    return node;
}
vector<vector<int>> generatePascalsTriangle(int numRows)
{
    vector<vector<int>> triangle(numRows);

    if (numRows == 0)
        return triangle;

    for (int i = 0; i < numRows; i++)
    {
        triangle[i].resize(i + 1, 1);
        for (int j = 1; j < i; j++)
        {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    return triangle;
}
ListNode *swapPairs(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *nextNode = head->next;
    head->next = swapPairs(nextNode->next);
    nextNode->next = head;

    return nextNode;
}
int maxProfit(vector<int> &prices)
{
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < minPrice)
        {
            minPrice = prices[i];
        }
        else if (prices[i] - minPrice > maxProfit)
        {
            maxProfit = prices[i] - minPrice;
        }
    }

    return maxProfit;
}
bool isPalindrome(string s)
{
    string s1;
    for (auto ele : s)
    {
        if (isalnum(ele))
        {
            if (isupper(ele))
            {
                s1.push_back(tolower(ele));
            }
            else
            {
                s1.push_back(ele);
            }
        }
    }
    string reversed = s1;
    reverse(reversed.begin(), reversed.end());
    return s1 == reversed;
}
int pairSum(ListNode *head)
{
    ListNode *current = head;
    vector<int> values;

    while (current)
    {
        values.push_back(current->val);
        current = current->next;
    }

    int i = 0, j = values.size() - 1;
    int maximumSum = 0;
    while (i < j)
    {
        maximumSum = max(maximumSum, values[i] + values[j]);
        i++;
        j--;
    }

    return maximumSum;
}
