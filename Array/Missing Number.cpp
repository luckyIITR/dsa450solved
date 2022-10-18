#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        bool check_n = false;    // since it has number n.. marking visited using variable
        bool check_zero = false; // since it has number 0.. it wouldn't hold any information
        for (int i = 0; i < n; i++)
        {
            int idx = abs(nums[i]);
            if (idx == n)
                check_n = true;
            else if (nums[idx] > 0)
                nums[idx] = nums[idx] * -1;
            else if (nums[idx] == 0)
                check_zero = true;
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                return i;
            else if (nums[i] == 0 and check_zero == false)
                return i;
        }
        return n;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    return 0;
}
