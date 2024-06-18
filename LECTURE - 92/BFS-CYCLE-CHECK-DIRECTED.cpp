/*

        https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0&leftPanelTabValue=PROBLEM

*/



#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

  //INDEGREE WALA BHI BANALO
  vector<int> in(n+1,0);

  //CREATE ADJ LIST
  vector<int> adj[n+1];
  for(auto i : edges){
    adj[i.first].push_back(i.second);
    in[i.second]++;
  }

  //JISKA INDEGREE 0 HAIN USKO QUEUE ME DALO
  queue<int> q;
  for(int i = 1;i<=n;i++){

    if(in[i]==0){
      q.push(i);
    }

  }

  //ANSWER CHECK HOGA
  int cnt = 0;

  //DO BFS
  while(!q.empty()){

    //FRONT NODE
    int node = q.front();
    q.pop();

    //IS NODE KO ANS ME ADD KARO
    cnt++;

    //ISKE NEIGBOURS KE INDEGREE KAM KARDO ISKO HATA DIYA
    for(auto i : adj[node]){

      //INDEGREE KAM KARO
      in[i]--;

      //AGAR ZERO HOGAYA TO DALDO
      if(in[i]==0){
        q.push(i);
      }

    }

  }

  //CHECK IF THE TS IS VALID
  return cnt!=n;
}
