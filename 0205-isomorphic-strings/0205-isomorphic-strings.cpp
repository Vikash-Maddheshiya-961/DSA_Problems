class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int l1 = s.length();
        int l2 = t.length();
        if(l1!=l2) return false;
        vector<int> sv(150,500); // special array
        // checking wrt to string s
        for(int i=0;i<l1;i++){
            int idx = int(s[i]);
            if(sv[idx] == 500) sv[idx] = s[i] - t[i];
            else{
                if(sv[idx] != (s[i]-t[i])) return false;
            }
        }
        // now again reset the sv
        for(int i=0;i<sv.size();i++) sv[i] = 500;
        // checking wrt to string t
        for(int i=0;i<l2;i++){
            int idx = int(t[i]);
            if(sv[idx] == 500) sv[idx] = t[i] - s[i];
            else{
                if(sv[idx] != (t[i]-s[i])) return false;
            }
        }
        return true;
    }
};