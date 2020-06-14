class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // Subset h subsequence nhi
        if(nums.empty())
        {
            vector<int> v;
            return v;
        }
        sort(nums.begin(), nums.end());
        vector<int> divCount(nums.size(), 1);
        vector<int> prev(nums.size(), -1);
        int maxi = 0;
        for(int i=1; i<nums.size(); i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[i]%nums[j]==0 && divCount[i]<1+divCount[j])
                {
                    divCount[i] = 1+divCount[j];
                    prev[i] = j;
                }
            }
            if(divCount[i]>divCount[maxi])
                maxi = i;
        }
        divCount.clear();
        int p = maxi;
        while(p>=0)
        {
            divCount.insert(divCount.begin(), nums[p]);
            p = prev[p];
        }
        return divCount;
    }
};
