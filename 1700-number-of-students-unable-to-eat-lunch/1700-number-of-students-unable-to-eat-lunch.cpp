class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        int idx=0;
        queue<int> q;
        for(int val:students) q.push(val);

        while(!q.empty()){
            int size = q.size();

            bool flag = false;
            for(int i=0;i<size;i++){
                int s = q.front();
                if(s == sandwiches[idx]){
                    q.pop();
                    idx++;
                    flag = true;
                }
                else{
                    q.pop();
                    q.push(s);
                }
            }

            if(flag == false) break;
        }

        return q.size();
    }
};