class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefsum=0;
        int n=nums.size();
        int ans=0;
        unordered_map<int ,int>prevoccurcount;
        
        prevoccurcount[0]=1;
        for(int i=0;i<n;i++){
            prefsum=(prefsum+nums[i]%k +k)%k;
            ans=ans+prevoccurcount[prefsum];
            prevoccurcount[prefsum]++;
        }
        return ans;
    }
};