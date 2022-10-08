//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        // Your code here
        if (n == 1)
            return 0;
        if (arr[0] == 0 and n > 1)
            return -1;

        int max_reachable = arr[0];
        int jump = 1;
        int step = arr[0];

        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
                break;
            step--;
            max_reachable = max(max_reachable, i + arr[i]);

            if (step == 0)
            {
                if (max_reachable <= i)
                    return -1;
                jump++;
                step = max_reachable - i;
            }
        }
        return jump;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends