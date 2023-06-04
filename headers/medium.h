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
int dy,dx;
// Functions
ListNode *swapPairs(ListNode *head);
int pairSum(ListNode *head); // Twin Pair Sum

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges); // Minimum Vertices(Graph)

bool isBipartite(vector<vector<int>> &graph);
bool isBipartiteDFS(vector<vector<int>> &graph, int vertex, vector<int> &colors);

vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries);

bool isValid(int i, int j, int r, int c)
void changeIslandType(int i, int j, int r, int c, vector<vector<int>> &grid)
int shortestBridge(vector<vector<int>> &grid)

int partition(int left, int right, int pivot_index)
void quickselect(int left, int right, int k_smallest); // Top K Frequent
vector<int> topKFrequent(vector<int> &nums, int k);

int shortestPathBinaryMatrix(vector<vector<int>>& grid); 

int TimeToInformDFS(int current, vector<vector<int>> &adjList, vector<int> &informTime); // Time to Inform All Employees
int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime);

int findCircleNum(vector<vector<int>> &isConnected); // Number of Provinces
#endif