class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=0;
        int median=n/2;
        for(int i=0;i<n;i++){
            if(nums[i]>=nums[median]){
                count=count+(nums[i]-nums[median]);
            }
            else{
                count=count+(nums[median]-nums[i]);
            }
            
        }
        return count;
        
    }
};