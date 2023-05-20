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

bool isBipartite(vector<vector<int>> &graph);
bool isBipartiteDFS(vector<vector<int>> &graph, int vertex, vector<int> &colors);

vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries);

#endif