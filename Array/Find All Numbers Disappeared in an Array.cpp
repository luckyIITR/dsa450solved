#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i< n ; i++)
        {
            int idx = abs(nums[i]);
            if(nums[idx-1] > 0)
                nums[idx-1] = nums[idx-1]*-1; 
            
        }
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i]>0) ans.push_back(i+1);
        }
        
        return ans;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    return 0;
} 
