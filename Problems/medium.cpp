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
bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> colors(n, -1);

    for (int i = 0; i < n; ++i)
    {
        if (colors[i] == -1)
        {
            if (!isBipartiteDFS(graph, i, colors))
            {
                return false;
            }
        }
    }

    return true;
}
bool isBipartiteDFS(vector<vector<int>> &graph, int vertex, vector<int> &colors)
{
    stack<int> stk;
    stk.push(vertex);
    colors[vertex] = 0;

    while (!stk.empty())
    {
        int current = stk.top();
        stk.pop();

        for (int neighbor : graph[current])
        {
            if (colors[neighbor] == -1)
            {
                colors[neighbor] = 1 - colors[current];
                stk.push(neighbor);
            }
            else if (colors[neighbor] == colors[current])
            {
                return false;
            }
        }
    }

    return true;
}
vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    unordered_map<string, unordered_map<string, double>> graph;
    int n = equations.size();
    for (int i = 0; i < n; ++i)
    {
        const string &numerator = equations[i][0];
        const string &denominator = equations[i][1];
        double value = values[i];

        graph[numerator][denominator] = value;
        graph[denominator][numerator] = 1.0 / value;
    }

    int m = queries.size();
    vector<double> results(m, -1.0);
    for (int i = 0; i < m; ++i)
    {
        const string &start = queries[i][0];
        const string &end = queries[i][1];

        if (graph.count(start) == 0 || graph.count(end) == 0)
        {
            continue;
        }

        if (start == end)
        {
            results[i] = 1.0;
            continue;
        }

        queue<pair<string, double>> q;
        unordered_set<string> visited;
        q.push({start, 1.0});
        visited.insert(start);

        while (!q.empty())
        {
            string current = q.front().first;
            double valueSoFar = q.front().second;
            q.pop();

            for (const auto &neighbor : graph[current])
            {
                const string &next = neighbor.first;
                double edgeValue = neighbor.second;

                if (next == end)
                {
                    results[i] = valueSoFar * edgeValue;
                    break;
                }

                if (visited.count(next) == 0)
                {
                    q.push({next, valueSoFar * edgeValue});
                    visited.insert(next);
                }
            }

            if (results[i] != -1.0)
            {
                break;
            }
        }
    }

    return results;
}