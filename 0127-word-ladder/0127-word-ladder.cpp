class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_set<string> s(wordList.begin(),wordList.end());

        queue<pair<string,int>> q;
        q.push({beginWord,1});
        s.erase(beginWord);

        while(!q.empty()){
            string str = q.front().first;
            int dist = q.front().second;
            q.pop();
            if(str == endWord){
                return dist;
            }

            for(int i=0;i<str.size();i++){
                char original = str[i];
                for(char ch = 'a';ch <= 'z'; ch++){
                    str[i] = ch;
                    if(s.count(str)){
                        q.push({str,dist+1});
                        s.erase(str);
                    }
                }
                str[i] = original;
            }
        }

        return 0;
    }
};