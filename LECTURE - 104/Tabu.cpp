

#include <bits/stdc++.h> 
int minimumElements(vector<int> &num, int x)
{
    vector<int> tabu(x+1,INT_MAX);
    tabu[0]=0;
    for(int i = 1;i<=x;i++){
        for(auto j : num){
            if((i-j>=0) && tabu[i-j]!=INT_MAX){
                tabu[i]=min(tabu[i],tabu[i-j]+1);
            }
        }
    }
    if(tabu[x]==INT_MAX){
        return -1;
    }
    return tabu[x];
}
