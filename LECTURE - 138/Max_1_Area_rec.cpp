// https://leetcode.com/problems/maximal-rectangle/description/


class Solution {
    void banao(vector<int> & arr,vector<int>  & next,vector<int> & pre){
        stack<int> s,st;
        int n = arr.size();
        (n,0);
        (n,0);
        s.push(n);
        st.push(-1);

        for(int i = n-1;i>=0;i--){
            while( s.size()!=1 && arr[s.top()] >= arr[i]){
                s.pop();
            }
            next[i] = s.top();
            s.push(i);
        }

        for(int i = 0;i<n;i++){
            while(st.size()!=1 && arr[st.top()] >= arr[i]){
                st.pop();
            }
            pre[i] = st.top();
            st.push(i);
        }

    }

    int find_area(vector<int> & next,vector<int> & pre,vector<int> & arr){
        int n = arr.size();
        int max_area = 0;
        for(int i = 0;i<n;i++){

            max_area= max(max_area,(next[i]-pre[i]-1 ) * arr[i]);
        }
        return max_area;
    }


public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int max_ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m,0);
        for(int i = 0;i<n;i++){

            vector<int> histo(m,0);

            for(int j = 0;j<m;j++){
                histo[j]+=(prev[j]);
                if(matrix[i][j]=='1')
                    histo[j]++;
                else
                    histo[j] = 0;

            }

            prev = histo;

            vector<int> pre(m,0);
            vector<int> next(m,0);
            banao(histo,next,pre);

            max_ans = max(max_ans,find_area(next,pre,histo));
        }
        return max_ans;
    }
};
