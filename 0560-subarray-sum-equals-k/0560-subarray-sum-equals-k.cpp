class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      map<int,int>mpp;
        mpp[0]=1;
        int n=nums.size();
        int presum=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            presum=presum+nums[i];
            int remove = presum-k;
            cnt=cnt+mpp[remove];
            mpp[presum]+=1;
        }
        return cnt;
    }
};
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         int cnt = 0;
//         for (int i = 0; i < n; i++) {
//             int sum = 0;
//             for (int j = i; j < n; j++) {
//                 sum += nums[j];

//                 if (sum == k)
//                     cnt++;
//             }
//         }
//         return cnt;
//     }
// };
