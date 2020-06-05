class Solution {
public:
    vector<int> s;
    Solution(vector<int>& w) {
        for (int i=0; i<w.size(); i++)
            s.push_back(i==0 ? w[i] : (w[i] + s.back()));
    }
    
    int pickIndex() {
        int m = s.back();
        int r = rand() % m;
        auto it = upper_bound(s.begin(), s.end(), r);
        return it - s.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */