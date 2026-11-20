class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int , int> mp;
        for( int& x : arr){
            mp[x]++;
        }

        unordered_set<int> st;
        for(auto& it : mp){
             int freq = it.second ;  // it.first mein number hoga
                if(st.find(freq) != st.end())//freq jo h set mei present hai
     return false ;
     st.insert(freq);
                }
                return true;
    }
};