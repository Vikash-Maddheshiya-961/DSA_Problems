class Solution {
public:
    unordered_map<string,int> mp;
    vector<vector<string>> ans;
    string b;
    void dfs(string word,vector<string> seq){
        if(word == b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }

        int steps = mp[word];
        for(int i=0;i<word.length();i++){
            int original = word[i];

            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i]= ch;
                if(mp.find(word) != mp.end() && mp[word] + 1 == steps){
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
                word[i] = original;
            }
        }

        return;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());

        b = beginWord;

        queue<string> q;
        q.push(beginWord);
        mp[beginWord] = 1;
        s.erase(beginWord);
        int shortest_dist = 0;
        while(!q.empty()){
            string str = q.front();
            int steps = mp[str];
            q.pop();

            if(str == endWord) break;

            for(int i=0;i<str.size();i++){
                char original = str[i];
                for(char ch = 'a';ch <= 'z'; ch++){
                    str[i] = ch;
                    if(s.count(str)){
                        q.push(str);
                        mp[str] = steps + 1;
                        s.erase(str);
                    }
                }
                str[i] = original;
            }
        }

        if(mp.find(endWord) != mp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }

        return ans;
    }
};