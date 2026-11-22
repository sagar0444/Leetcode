class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26 , 0);
        for( char& ch : tasks){
             mp[ch -'A']++;
        }

        sort(mp.begin(), mp.end());

        int maxFreq = mp[25];
        int gadhhe = maxFreq - 1;

        int idlespot = n * gadhhe;
        for(int i = 24 ; i >= 0; i--){
             idlespot = idlespot - min(mp[i] , gadhhe);
        }

        if( idlespot > 0){
            return tasks.size() + idlespot;
        }

        return tasks.size();
    }
};