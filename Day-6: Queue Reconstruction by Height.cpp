class Solution {
public:
    static bool comp(vector<int> &v1, vector<int> &v2)
    {
        return v1[0]>v2[0]||(v1[0]==v2[0] && v1[1]<v2[1]);
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), comp);
        vector<vector<int>> res;
        for(auto p: people)
            res.insert(res.begin()+p[1], p);
        return res;
    }
};