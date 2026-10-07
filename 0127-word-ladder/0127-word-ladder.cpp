class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        set<string> s;
        for(string str: wordList){
            s.insert(str);
        }

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
                string temp = str;
                for(char ch = 'a';ch <= 'z'; ch++){
                    temp[i] = ch;
                    if(s.count(temp)){
                        q.push({temp,dist+1});
                        s.erase(temp);
                    }
                }
            }
        }

        return 0;
    }
};