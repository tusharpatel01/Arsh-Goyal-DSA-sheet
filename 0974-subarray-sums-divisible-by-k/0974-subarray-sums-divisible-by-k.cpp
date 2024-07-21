class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
    prefixCount[0] = 1; 
    
    int currentSum = 0;
    int count = 0;
    
    for (int num : nums) {
        currentSum += num;
        int modSum = ((currentSum % k) + k) % k; 
        
        if (prefixCount.find(modSum) != prefixCount.end()) {
            count += prefixCount[modSum];
        }
        
        prefixCount[modSum]++;
    }
    
    return count;
    }
};