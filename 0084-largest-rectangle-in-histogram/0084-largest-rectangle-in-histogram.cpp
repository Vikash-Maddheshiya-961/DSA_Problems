class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        nse[n-1] = n;
        stack<int> st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            if(st.empty()){
                nse[i] = n;
            }
            else{
                nse[i] = st.top();
            }

            st.push(i);
        }

        stack<int> gt;

        vector<int> pse(n);
        pse[0] = -1;
        gt.push(0);

        for(int i=1;i<n;i++){
            while(!gt.empty() && arr[gt.top()] >= arr[i]) gt.pop();

            if(gt.empty()){
                pse[i] = -1;
            }
            else{
                pse[i] = gt.top();
            }

            gt.push(i);
        }

        int max_area = 0;


        for(int i=0;i<n;i++){
            int height = arr[i];
            int breadth = nse[i] - pse[i] - 1;
            int area = height * breadth;
            max_area = max(area,max_area);
        }

        return max_area;
    }
};