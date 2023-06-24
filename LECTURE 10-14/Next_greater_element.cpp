#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int len = nums.size();

        for(int i=0; i<len; i++)
        {
            int rem = i%len;
            int j=i+1;
            int rem2 = j%len;
            bool found=false;
            while(rem != rem2)
            {
                if(nums[i]<nums[rem2])
                {
                    ans.push_back(nums[rem2]);
                    found = true;
                    break;
                }
                j++;
                rem2 = j%len;
            }
            if(found==false)
            {
                ans.push_back(-1);
            }

        }
        return ans;
    }
};