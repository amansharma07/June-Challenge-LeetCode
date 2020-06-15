class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int,unordered_map<int,int>> mp;
        for(const vector<int>& flight : flights)   mp[flight[0]][flight[1]] = flight[2];
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minheap;
        minheap.push({0,src,K+1});
        while(!minheap.empty()){
            vector<int> top = minheap.top();
            minheap.pop();
            int price = top[0];
            int city = top[1];
            int stops = top[2];
            if (city == dst) return price;
            if(stops>0) for(auto &t: mp[city] ) minheap.push({price+t.second, t.first, stops-1});
            }
        return -1;   
    }
};
