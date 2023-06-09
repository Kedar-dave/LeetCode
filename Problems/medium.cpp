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
class SnapshotArray
{ // SnapShot Array Problem
public:
    int snapId;
    vector<vector<pair<int, int>>> snaps;
    SnapshotArray(int length)
    {
        snapId = 0;
        snaps.resize(length);
        for (int i = 0; i < length; ++i)
        {
            snaps[i].push_back(make_pair(0, 0));
        }
    }

    void set(int index, int val)
    {
        snaps[index].push_back(make_pair(snapId, val));
    }

    int snap()
    {
        return snapId++;
    }

    int get(int index, int snap_id)
    {
        auto it = upper_bound(snaps[index].begin(), snaps[index].end(), make_pair(snap_id, INT_MAX));
        return prev(it)->second;
    }
};

int equalPairs(vector<vector<int>> &grid)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    map<vector<int>, int> r;
    map<vector<int>, int> c;
    for (int i = 0; i < grid.size(); i++)
    {
        if (r.count(grid[i]))
        {
            r[grid[i]]++;
        }
        else
        {
            r[grid[i]] = 1;
        }
        vector<int> t;
        for (int j = 0; j < grid.size(); j++)
        {
            t.push_back(grid[j][i]);
        }
        if (c.count(t))
        {
            c[t]++;
        }
        else
        {
            c[t] = 1;
        }
    }
    int ans = 0;
    for (auto ele : r)
    {
        if (c.count(ele.first))
        {
            ans += ele.second * c[ele.first];
        }
    }
    return ans;
}
int maxLevelSum(TreeNode *root)
{
    int maxSum = INT_MIN;
    int ans = 0, level = 0;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        level++;
        int sumAtCurrentLevel = 0;
        // Iterate over all the nodes in the current level.
        for (int sz = q.size(); sz > 0; --sz)
        {
            TreeNode *node = q.front();
            q.pop();
            sumAtCurrentLevel += node->val;

            if (node->left != nullptr)
            {
                q.push(node->left);
            }
            if (node->right != nullptr)
            {
                q.push(node->right);
            }
        }

        if (maxSum < sumAtCurrentLevel)
        {
            maxSum = sumAtCurrentLevel;
            ans = level;
        }
    }

    return ans;
}
vector<int> getAverages(vector<int> &nums, int k) // K Radius Subarray Averages
{
    // When a single element is considered then its averafge will be the number itself only.
    if (k == 0)
    {
        return nums;
    }

    int n = nums.size();
    vector<int> averages(n, -1);

    // Any index will not have 'k' elements in it's left and right.
    if (2 * k + 1 > n)
    {
        return averages;
    }

    // First get the sum of first window of the 'nums' arrray.
    long long windowSum = 0;
    for (int i = 0; i < (2 * k + 1); ++i)
    {
        windowSum += nums[i];
    }
    averages[k] = windowSum / (2 * k + 1);

    // Iterate on rest indices which have atlest 'k' elements
    // on its left and right sides.
    for (int i = (2 * k + 1); i < n; ++i)
    {
        // We remove the discarded element and add the new element to get current window sum.
        // 'i' is the index of new inserted element, and
        // 'i - (window size)' is the index of the last removed element.
        windowSum = windowSum - nums[i - (2 * k + 1)] + nums[i];
        averages[i - k] = windowSum / (2 * k + 1);
    }

    return averages;
}
int longestArithSeqLength(vector<int> &nums)
{
    vector<vector<int>> dp(nums.size(), vector<int>(1001, 0));
    int ret = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            int diff = nums[j] - nums[i] + 500;
            dp[j][diff] = max(2, dp[i][diff] + 1);
            ret = max(ret, dp[j][diff]);
        }
    }
    return ret;
}
long long totalCost(vector<int> &costs, int k, int candidates)
{
    int i = 0;
    int j = costs.size() - 1;
    priority_queue<int, vector<int>, greater<int>> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;

    long long ans = 0;
    while (k--)
    {
        while (pq1.size() < candidates && i <= j)
        {
            pq1.push(costs[i++]);
        }
        while (pq2.size() < candidates && i <= j)
        {
            pq2.push(costs[j--]);
        }

        int t1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
        int t2 = pq2.size() > 0 ? pq2.top() : INT_MAX;

        if (t1 <= t2)
        {
            ans += t1;
            pq1.pop();
        }
        else
        {
            ans += t2;
            pq2.pop();
        }
    }
    return ans;
}

vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    vector<vector<int>> resV; // Result vector to store the pairs
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // Priority queue to store pairs with smallest sums, sorted by the sum

    // Push the initial pairs into the priority queue
    for (int x : nums1)
    {
        pq.push({x + nums2[0], 0}); // The sum and the index of the second element in nums2
    }

    // Pop the k smallest pairs from the priority queue
    while (k-- && !pq.empty())
    {
        int sum = pq.top().first;  // Get the smallest sum
        int pos = pq.top().second; // Get the index of the second element in nums2

        resV.push_back({sum - nums2[pos], nums2[pos]}); // Add the pair to the result vector
        pq.pop();                                       // Remove the pair from the priority queue

        // If there are more elements in nums2, push the next pair into the priority queue
        if (pos + 1 < nums2.size())
        {
            pq.push({sum - nums2[pos] + nums2[pos + 1], pos + 1});
        }
    }

    return resV; // Return the k smallest pairs
}
double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
{

    // Adjacency list
    vector<vector<pair<int, double>>> adj(n);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back({v, succProb[i]});
        adj[v].push_back({u, succProb[i]});
    }

    // ans will be in dist[end]
    vector<double> dist(n, 0.0);
    dist[start] = 1.0;

    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (auto x : adj[curr])
        {
            int node = x.first;
            double prob = x.second;
            double newProb = dist[curr] * prob;

            if (newProb > dist[node])
            {
                dist[node] = newProb;
                q.push(node);
            }
        }
    }

    return dist[end];
}