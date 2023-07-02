// 56. Merge Intervals


// Solution 1:

class Solution {
public:
    static bool comparator(const pair<int,int> &a,const pair<int,int> &b){
        return (a.first<b.first);
        // or
        // if(a.first<b.first) return true;
        // else if(a.first==b.first)   return a.second<b.second;
        // else    return false;
    }
    static bool areOverlapping(const pair<int,int> &a,const pair<int,int> &b){
        return a.second>=b.first;
    }
    pair<int,int> mergeOverlappingIntervals(const pair<int,int> &a,const pair<int,int> &b){
        return {min(a.first,b.first),max(a.second,b.second)};
    }
    vector<pair<int,int>> merge(vector<pair<int,int>>& intervals) {
        if(intervals.size()<=1)  return intervals;
        vector<pair<int,int>> result;
        sort(intervals.begin(),intervals.end(),comparator);
        result.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(areOverlapping(result.back(),intervals[i])){
                pair<int,int> overlapped=mergeOverlappingIntervals(result.back(),intervals[i]);
                result.pop_back();
                result.push_back(overlapped);
            }
            else result.push_back(intervals[i]);
        }
        return result;
    }
};

// solution 2:
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        for(auto interval : intervals){
            if(output.empty() || output.back()[1] < interval[0]){
                output.push_back(interval);
            }
            else{
                output.back()[1] = max(output.back()[1], interval[1]);
            }
        }
        return output;
    }
};

// 347. Top K Frequent Elements
class comparator{
    public:
    bool operator(const pair<int,int> &a,const pair<int,int> &b){
        return a.second > b.second;
    }
};

vector<int> topKFrequent(vector<int> &vec,int k){
    unordered_map<int,int> hash;
    for(int i=0;i<vec.size();i++)   hash[vec[i]]++;
    priority_queue<pair<int,int>,vector<pair<int,int>>,comparator> pq;
    for(auto it=hash.begin();it!=hash.end();it++){
        if(pq.size()<k){
            pq.push(pair<int,int>{it->first,it->second});
        }
        else{
            if(pq.top().second<it->second){
                pq.pop();
                pq.push(pair<int,int>{it->first,it->second});
            }
        }
    }
    vector<int> result(k);
    int i=0;
    while(!pq.empty()){
        result[i++]=pq.top().first;
        pq.pop();
    }
    return result;
}