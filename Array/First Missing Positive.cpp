#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        // i will check, ki kya mere array mai 1 hai, fir 2, fir 3... jo first positive nhi milega wo answer

        // do the rearrangement first
        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            bool flag = false;
            if (nums[i] != i + 1 and nums[i] <= n and nums[i] > 0)
            {
                if (nums[i] == nums[nums[i] - 1])
                    flag = true; // if both swaping numbers are equal then also skip

                swap(nums[i], nums[nums[i] - 1]);
                if (flag)
                    i++;
            }
            else
                i++;
        }

        // now check for non fixed points
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    return 0;
}
