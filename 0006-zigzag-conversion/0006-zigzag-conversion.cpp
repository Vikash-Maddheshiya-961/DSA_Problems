class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> arr(numRows);
        for(int i=0;i<numRows;i++){
            arr[i]="";
        }
        int i=0;
        while(i<s.size()){
            for(int row=0;row<numRows && i<s.size();row++){
                arr[row]+=s[i++];
            }
            for(int rev=numRows-2;rev>0 && i<s.size();rev--){
                arr[rev]+=s[i++];
            }
        }
        string ans;
        for(string c:arr){
            ans+=c;
        }
        return ans;
    }
};