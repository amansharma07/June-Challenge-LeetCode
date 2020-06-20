class Solution {
public:
    void nextPerm(string &nums) {
        int i,j;
        for(i=nums.size()-1; i>0; i--)
        {
            if(nums[i]>nums[i-1])
                break;
        }
        if(i==0)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        int small = i-1;
        int big=i;
        int temp=big;
        for(int i=nums.size()-1; i>big; i--)
        {
            if(nums[i] > nums[small] && nums[i]<nums[temp])
                temp=i;
        }
        swap(nums[small], nums[temp]);
        sort(nums.begin()+small+1, nums.end());
        return;
    }
    string getPermutation(int n, int k) {
        string p="";
        for(int i=1; i<=n; i++)
        {
            p+=to_string(i);
        }
        while(k-->1)
            nextPerm(p);  // Could have also used next_permutation(p.begin(), p.end()) ---> STL
        return p;
    }
};
