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
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    if (n == 1 and grid[0][0] == 0)
        return 1;
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        return -1;
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
    while (!q.empty())
    {
        int len = q.size();
        while (len--)
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int z = q.front().second;
            q.pop();

            for (int i = 0; i < 8; i++)
            {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                if (nx >= 0 and nx < n and ny >= 0 and ny < n)
                {
                    if (nx == n - 1 and ny == n - 1)
                        return z + 1;
                    if (grid[nx][ny] == 0)
                    {
                        grid[nx][ny] = 1;
                        q.push({{nx, ny}, z + 1});
                    }
                }
            }
        }
    }
    return -1;
}
int TimeToInformDFS(int current, vector<vector<int>> &adjList, vector<int> &informTime)
{
    int maxTime = 0;
    for (int subordinate : adjList[current])
    {
        maxTime = max(maxTime, TimeToInformDFS(subordinate, adjList, informTime));
    }
    return maxTime + informTime[current];
}

int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> adjList(n);
    for (int i = 0; i < n; i++)
    {
        if (manager[i] != -1)
        {
            adjList[manager[i]].push_back(i);
        }
    }
    return TimeToInformDFS(headID, adjList, informTime);
}
// Number of Provinces
int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    vector<bool> visited(n, false);
    int provinces = 0;
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            provinces++;
            q.push(i);
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                visited[cur] = true;
                for (int j = 0; j < n; j++)
                {
                    if (isConnected[cur][j] == 1 && !visited[j])
                    {
                        q.push(j);
                    }
                }
            }
        }
    }

    return provinces;
}
bool checkStraightLine(vector<vector<int>> &coordinates)
{
    int n = coordinates.size();
    if (n <= 2)
    {
        return true;
    }

    int dx = coordinates[1][0] - coordinates[0][0];
    int dy = coordinates[1][1] - coordinates[0][1];

    for (int i = 2; i < n; i++)
    {
        int cur_dx = coordinates[i][0] - coordinates[i - 1][0];
        int cur_dy = coordinates[i][1] - coordinates[i - 1][1];

        if (dx * cur_dy != dy * cur_dx)
        {
            return false;
        }
    }

    return true;
}

bool canMakeArithmeticProgression(vector<int> &arr)
{
    int n = arr.size();
    if (n <= 2)
    {
        return true;
    }

    sort(arr.begin(), arr.end());
    int diff = arr[1] - arr[0];

    for (int i = 2; i < n; i++)
    {
        if (arr[i] - arr[i - 1] != diff)
        {
            return false;
        }
    }

    return true;
}
int minFlips(int a, int b, int c)
{
    int flips = 0;
    for (int i = 0; i < 32; i++)
    {
        int bit_a = (a >> i) & 1;
        int bit_b = (b >> i) & 1;
        int bit_c = (c >> i) & 1;

        if (bit_c == 0)
        {
            flips += bit_a + bit_b;
        }
        else
        {
            flips += 1 - (bit_a | bit_b);
        }
    }
    return flips;
}

long long int test(int a, int index, int n)
{
    long long int b = max(0, a - index);
    long long int res = (a + b) * (a - b + 1) / 2;
    b = max(0, (a - ((n - 1) - index)));
    res = res + (a + b) * (a - b + 1) / 2;

    return res - a;
}

int maxValue(int n, int index, int maxSum)
{

    maxSum = maxSum - n;
    int l = 0, r = maxSum;

    while (l < r)
    {
        int m = (l + r + 1) / 2;
        if (test(m, index, n) > maxSum)
        {
            r = m - 1;
        }
        else
        {
            l = m;
        }
    }
    return l + 1;
}
class SnapshotArray { // SnapShot Array Problem
public:
    int snapId;
    vector<vector<pair<int, int>>> snaps;
    SnapshotArray(int length) {
        snapId = 0;
        snaps.resize(length);
        for (int i = 0; i < length; ++i) {
            snaps[i].push_back(make_pair(0, 0));
        }
    }
    
    void set(int index, int val) {
        snaps[index].push_back(make_pair(snapId, val));
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(snaps[index].begin(), snaps[index].end(), make_pair(snap_id,INT_MAX));
        return prev(it)->second;
    }
};