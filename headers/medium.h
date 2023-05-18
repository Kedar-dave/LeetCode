#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <stack>
#include "structures.h"
using namespace std;

#ifndef MEDIUM_H
#define MEDIUM_H

// Structures

struct TreeNode;
struct ListNode;

// Functions
ListNode *swapPairs(ListNode *head);
int pairSum(ListNode *head); // Twin Pair Sum

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges); // Minimum Vertices(Graph)
#endif