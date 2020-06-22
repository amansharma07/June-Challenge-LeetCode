class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto i=0; i<32; i++)
        {
            int s=0;
            for(auto j=0; j<nums.size(); j++)
            {
                if((nums[j]>>i)&1)
                {
                    s++;
                    s%=3;
                }
            }
            if(s==1)
                res |= s<<i;
        }
        return res;
    }
};
