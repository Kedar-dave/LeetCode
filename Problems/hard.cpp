#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <stack>
#include "structures.h"
using namespace std;

struct TreeNode;
struct ListNode;

class NumofWays
{
public:
    int numOfWays(vector<int> &nums)
    {
        int m = nums.size();
        table.resize(m + 1);
        for (int i = 0; i < m + 1; ++i)
        {
            table[i] = vector<long long>(i + 1, 1);
            for (int j = 1; j < i; ++j)
            {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
            }
        }

        return (dfs(nums) - 1) % mod;
    }

private:
    vector<vector<long long>> table;
    long long mod = 1e9 + 7;

    long long dfs(vector<int> &nums)
    {
        int m = nums.size();
        if (m < 3)
        {
            return 1;
        }

        vector<int> leftNodes, rightNodes;
        for (int i = 1; i < m; ++i)
        {
            if (nums[i] < nums[0])
            {
                leftNodes.push_back(nums[i]);
            }
            else
            {
                rightNodes.push_back(nums[i]);
            }
        }

        long long leftWays = dfs(leftNodes) % mod;
        long long rightWays = dfs(rightNodes) % mod;

        return (((leftWays * rightWays) % mod) * table[m - 1][leftNodes.size()]) % mod;
    }
};
class MakeArrayStrictlyIncreasing
{
public:
    int dp[2001][2001];
    int solve(vector<int> &arr1, vector<int> &arr2, int i, int j, int prev)
    {
        if (i == arr1.size())
            return 0;
        j = (upper_bound(arr2.begin() + j, arr2.end(), prev) - arr2.begin());
        if (dp[i][j] != -1)
            return dp[i][j];
        if (arr1[i] <= prev && j == arr2.size())
            return 2001;
        int take = 2001, nottake = 2001;
        if (j != arr2.size())
            take = 1 + solve(arr1, arr2, i + 1, j + 1, arr2[j]);
        if (arr1[i] > prev)
            nottake = solve(arr1, arr2, i + 1, j, arr1[i]);
        return dp[i][j] = min(take, nottake);
    }
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        memset(dp, -1, sizeof(dp));
        sort(arr2.begin(), arr2.end());
        int ans = solve(arr1, arr2, 0, 0, -1);
        if (ans > arr1.size())
            return -1;
        return ans;
    }
};
int tallestBillboard(vector<int> &rods)
{
    int sum = 0;
    for (int rod : rods)
    {
        sum += rod;
    }

    int dp[sum + 1];
    dp[0] = 0;

    // Initialize all other elements in dp[] to -1
    for (int i = 1; i <= sum; i++)
    {
        dp[i] = -1;
    }

    for (int rod : rods)
    {
        int dpCopy[sum + 1];
        // Copy the current state of dp[] to dpCopy[]
        copy(dp, dp + (sum + 1), dpCopy);

        for (int i = 0; i <= sum - rod; i++)
        {
            if (dpCopy[i] < 0)
                continue;

            // Case 1: Place the current rod on the same height billboard
            dp[i + rod] = max(dp[i + rod], dpCopy[i]);

            // Case 2: Place the current rod on the taller billboard
            // Calculate the absolute difference between current height and rod length
            dp[abs(i - rod)] = max(dp[abs(i - rod)], dpCopy[i] + min(i, rod));
        }
    }

    // Return the maximum height of the billboard stored at dp[0]
    return dp[0];
}
class CountAllPossibleRoutes
{
public:
    int solve(vector<int> &locations, int currCity, int finish, int remainingFuel,
              vector<vector<int>> &memo)
    {
        if (remainingFuel < 0)
        {
            return 0;
        }
        if (memo[currCity][remainingFuel] != -1)
        {
            return memo[currCity][remainingFuel];
        }

        int ans = currCity == finish ? 1 : 0;
        for (int nextCity = 0; nextCity < locations.size(); nextCity++)
        {
            if (nextCity != currCity)
            {
                ans = (ans + solve(locations, nextCity, finish,
                                   remainingFuel - abs(locations[currCity] - locations[nextCity]),
                                   memo)) %
                      1000000007;
            }
        }

        return memo[currCity][remainingFuel] = ans;
    }

    int countRoutes(vector<int> &locations, int start, int finish, int fuel)
    {
        int n = locations.size();
        vector<vector<int>> memo(n, vector<int>(fuel + 1, -1));

        return solve(locations, start, finish, fuel, memo);
    }
};