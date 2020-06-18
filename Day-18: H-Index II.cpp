class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n<1)
            return 0;
        int l = 0, h=n-1, mid;
        while(l<=h)
        {
            mid = l+(h-l)/2;
            if(citations[mid]>=(n-mid))
                h = mid-1;
            else
                l = mid+1;
        }
        return n-l;
    }
};
