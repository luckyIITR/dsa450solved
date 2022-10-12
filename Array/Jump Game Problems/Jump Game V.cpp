#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(vector<int> &arr, int idx, int d, int n, vector<int> &max_jump)
    {
        if (max_jump[idx] != -1)
            return max_jump[idx];

        int maxi = 1;
        for (int i = 1; i <= d; i++)
        {
            if (idx + i < n and arr[idx] > arr[idx + i])
            {
                // valid jump
                maxi = max(maxi, solve(arr, idx + i, d, n, max_jump) + 1);
            }
            else
            {
                break; // i dont want to continue if once above condition is failed
            }
        }

        // check for other side
        for (int i = 1; i <= d; i++)
        {
            if (idx - i >= 0 and arr[idx] > arr[idx - i])
            {
                // valid jump
                maxi = max(maxi, solve(arr, idx - i, d, n, max_jump) + 1);
            }
            else
            {
                break; // i dont want to continue if once above condition is failed
            }
        }

        max_jump[idx] = maxi;
        return (maxi);
    }

    int maxJumps(vector<int> &arr, int d)
    {
        int n = arr.size();
        vector<int> max_jump;
        max_jump.assign(n, -1);
        for (int i = 0; i < n; i++)
        {
            solve(arr, i, d, n, max_jump);
        }

        // find the max of all
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, max_jump[i]);
        }
        return ans;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        arr.push_back(val);
    }
    int d;
    cin >> d;
    Solution obj;
    cout << obj.maxJumps(arr, d) << endl;
    return 0;
}
