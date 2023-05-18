#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <stack>
#include "structures.h"
using namespace std;

struct TreeNode;
struct ListNode;
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
vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
{

    vector<int> res, visited(n);
    for (vector<int> &e : edges)
        visited[e[1]] = 1;

    for (int i = 0; i < n; ++i)
        if (visited[i] == 0)
            res.push_back(i);

    return res;
}