#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // flyod's cycle detection and reseting of pointers
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int slow = 0, fast = 0;
        while (true)
        {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
            if (slow == fast)
                break;
        }
        cout << slow << endl;
        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<int> nums{1, 3, 4, 2, 2};
    Solution obj;
    cout << obj.findDuplicate(nums) << endl;
    return 0;
}
