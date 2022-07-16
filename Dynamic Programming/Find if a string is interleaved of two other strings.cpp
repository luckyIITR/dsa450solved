// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    /*You are required to complete this method */
    unordered_map<string, bool> mp;
    bool solve(string A, string B, string C, int n1, int n2, int n3, int p1, int p2, int p3)
    {
        if (p3 == n3)
            return ((p1 == n1) and (p2 == n2));
        string key = to_string(p1) + "*" + to_string(p2) + "*" + to_string(p3);
        if (mp.find(key) != mp.end())
            return mp[key];
        if (p1 == n1)
        {
            if (B[p2] == C[p3])
                return mp[key] = solve(A, B, C, n1, n2, n3, p1, p2 + 1, p3 + 1);
            else
                return mp[key] = false;
        }
        if (p2 == n2)
        {
            if (A[p1] == C[p3])
                return mp[key] = solve(A, B, C, n1, n2, n3, p1 + 1, p2, p3 + 1);
            else
                return mp[key] = false;
        }
        bool check_A = false, check_B = false;
        if (A[p1] == C[p3])
            check_A = solve(A, B, C, n1, n2, n3, p1 + 1, p2, p3 + 1);
        if (B[p2] == C[p3])
            check_B = solve(A, B, C, n1, n2, n3, p1, p2 + 1, p3 + 1);
        return mp[key] = check_A or check_B;
    }

    bool isInterleave(string A, string B, string C)
    {
        // Your code here
        int n1 = A.size(), n2 = B.size(), n3 = C.size();
        if (n1 + n2 != n3)
            return false;
        return solve(A, B, C, n1, n2, n3, 0, 0, 0);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;
        Solution obj;
        cout << obj.isInterleave(a, b, c) << endl;
    }
    // your code goes here
    return 0;
} // } Driver Code Ends