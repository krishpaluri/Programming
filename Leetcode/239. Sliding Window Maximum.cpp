class Solution {
public:
    struct compare {
     bool operator()(pair<int,int> p1,pair<int,int> p2)       {  return p1.first < p2.first;}
    };


    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if(k == 0)
            return ans;
        priority_queue<pair<int,int>, std::vector<pair<int,int>>, compare> pq;
        int i=0,j=0;
        int sum =0,maxsum=0;
        for(j=0;j<k;j++)
        {
            pq.push(make_pair(nums[j],j));
        }
        ans.push_back(pq.top().first);
        cout<<pq.top().first<<" ";
        while(j<nums.size())
        {
            pq.push(make_pair(nums[j],j));
            pair<int,int> pr = pq.top();

            while(pr.second <= i )
            {
                pq.pop();
                pr = pq.top();
            }
            cout<<pq.top().first<<" ";
            i++;
            ans.push_back(pq.top().first);
            j++;
        }
        return ans;
    }
};
