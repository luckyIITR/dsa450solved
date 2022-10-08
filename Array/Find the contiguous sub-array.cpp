//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr: input array
    // n: size of array
    // Function to find the sum of contiguous subarray with maximum sum.
    // long long maxSubarraySum(int arr[], int n)
    // {
    // 	int i = 0, j = 0;
    // 	long long height = 0;
    // 	long long max_so_far = INT_MIN;
    // 	for (int i = 0; i < n; i++)
    // 	{
    // 		height += arr[i];
    // 		max_so_far = max(max_so_far, height);
    // 		if (height < 0)
    // 			height = 0;
    // 	}
    // 	return max_so_far;
    // }

    long long maxSubarraySum(int arr[], int n)
    {
        int start = 0, end = 0, temp_start = 0;
        long long height = 0;
        long long max_so_far = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            height += arr[i];
            if (max_so_far < height)
            {
                max_so_far = height;
                start = temp_start;
                end = i;
            }
            if (height < 0)
            {
                height = 0;
                temp_start = i + 1;
            }
        }
        cout << "start : " << start << "  end : " << end << endl;

        return max_so_far;
    }
};

//{ Driver Code Starts.

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, n;

    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {

        cin >> n; // input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; // inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends