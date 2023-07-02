
// q1 next greater element
vector<int> nextGreaterElements(vector<int> &nums){
    stack<int> s;
    vector<int> nge(nums.size());
    nge[nums.size()-1]=-1;
    for(int i=nums.size()-2;i>=0;i--){
        while(!s.empty() && nums[S.top()]<nums[i])  s.pop();
        if(s.empty())   nge[i]=-1;
        else    nge[i]=nums(s.top());
        s.push(i);
    }
    return nge;
}

// q2 next greater element II
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        stack<int> s;
        vector<int> nge(a.size());
        for(int i=a.size()-1;i>=0;i--){
            while(!s.empty() && a[s.top()]<a[i])    s.pop();
            s.push(i);
        }
        nge[a.size()-1]=-1;
        for(int i=a.size()-2;i>=0;i--){
            while(!s.empty() && a[s.top()]<a[i]){
                s.pop();
            }
            if(s.empty())   nge[i]=-1;
            else    nge[i]=a[s.top()];
            s.push(i);
        }
        return nge;
    }
};

// 84. Largest Rectangle in Histogram
class Solution {
public:
    vector<int> nextSmallerElementToTheLeft(vector<int> & heights){
        int len = heights.size();
        vector<int> nsl(len);
        stack<int> s;
        for(int i = 0; i < len; i++){
            while(!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            nsl[i] = (s.empty()? -1 : s.top());
            s.push(i);
        }
        return nsl;
    }

    vector<int> nextSmallerElementToTheRight(vector<int> & heights){
        int len = heights.size();
        vector<int> nsr(len);
        stack<int> s;
        for(int i = len - 1; i >= 0; i--){
            while(!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            nsr[i] = (s.empty()? len : s.top());
            s.push(i);
        }
        return nsr;
    }

    int largestRectangleArea(vector<int> &heights){
        vector<int> left = nextSmallerElementToTheLeft(heights);
        vector<int> right = nextSmallerElementToTheRight(heights);
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++){
            int j = left[i];
            int k = right[i];
            int width = (k - 1) - (j + 1) + 1;
            maxArea = max(maxArea, width * heights[i]);
        }
        return maxArea;
    }
};