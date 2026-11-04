class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto val:nums){
            s.insert(val); 
        }

        int max_count = 0;
        for(auto val:s){
            if(s.find(val-1) == s.end()){
                int current_num = val;
                int current_count = 1;

                while(s.find(current_num + 1) != s.end()){
                    current_num++;
                    current_count++;
                }

                max_count = max(max_count,current_count); 
            }
        }

        return max_count;
    }
};