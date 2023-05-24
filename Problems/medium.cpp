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
// Shortest Bridge
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
bool isValid(int i, int j, int r, int c)
{
    return (i < r && j < c && i >= 0 && j >= 0);
}

void changeIslandType(int i, int j, int r, int c, vector<vector<int>> &grid)
{

    if (i >= r || j >= c || i < 0 || j < 0 || grid[i][j] == 0 || grid[i][j] == 2)
        return;
    grid[i][j] = 2;
    for (int x = 0; x < 4; ++x)
    {
        int nr = i + dx[x];
        int nc = j + dy[x];
        changeIslandType(nr, nc, r, c, grid);
    }
}

int shortestBridge(vector<vector<int>> &grid)
{

    int r = grid.size();
    int c = grid[0].size();
    queue<pair<int, int>> q;

    int change = 0;
    bool check = false;
    // change the islands
    for (int i = 0; i < r; ++i)
    {

        for (int j = 0; j < c; ++j)
        {

            if (grid[i][j])
            {
                changeIslandType(i, j, r, c, grid);
                check = true;
                break;
            }
        }

        if (check)
            break;
    }

    // get the new islands in queue
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (grid[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        change++;
        int sz = q.size();

        while (sz--)
        {
            auto node = q.front();
            q.pop();
            // 4 directions
            for (int x = 0; x < 4; ++x)
            {
                int nr = node.first + dx[x];
                int nc = node.second + dy[x];

                if (isValid(nr, nc, r, c))
                {

                    if (grid[nr][nc] == 0)
                    {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }

                    if (grid[nr][nc] == 1)
                        return change - 1;
                }
            }
        }
    }
    return 0;
}

vector<int> unique;
map<int, int> count_map;

int partition(int left, int right, int pivot_index)
{
    int pivot_frequency = count_map[unique[pivot_index]];

    swap(unique[pivot_index], unique[right]);

    int store_index = left;
    for (int i = left; i <= right; i++)
    {
        if (count_map[unique[i]] < pivot_frequency)
        {
            swap(unique[store_index], unique[i]);
            store_index += 1;
        }
    }

    swap(unique[right], unique[store_index]);

    return store_index;
}
// Top K Frequent
void quickselect(int left, int right, int k_smallest)
{

    if (left == right)
        return;

    int pivot_index = left + rand() % (right - left + 1);

    pivot_index = partition(left, right, pivot_index);

    if (k_smallest == pivot_index)
    {
        return;
    }
    else if (k_smallest < pivot_index)
    {
        quickselect(left, pivot_index - 1, k_smallest);
    }
    else
    {
        quickselect(pivot_index + 1, right, k_smallest);
    }
}

vector<int> topKFrequent(vector<int> &nums, int k)
{
    for (int n : nums)
    {
        count_map[n] += 1;
    }

    int n = count_map.size();
    for (pair<int, int> p : count_map)
    {
        unique.push_back(p.first);
    }

    quickselect(0, n - 1, n - k);
    vector<int> top_k_frequent(k);
    copy(unique.begin() + n - k, unique.end(), top_k_frequent.begin());
    return top_k_frequent;
}
