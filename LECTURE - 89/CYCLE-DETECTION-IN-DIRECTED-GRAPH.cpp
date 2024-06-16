/*

https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0&leftPanelTabValue=PROBLEM

*/


// DFS SE




#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//DFS KA MODIFICATION HAIN BHAI OR KUCH NAHI
bool dfs(unordered_map<int,bool>& visited,unordered_map<int,bool>&dfscalls,
  unordered_map<int,list<int>> &adj,int curr_node  ){
  
  //VISI KAR LO GUYS
  visited[curr_node]=1;

  ///NEIGHBOURS KE LIYE CHECK KARO FROM LIST
  for( auto i : adj[curr_node] ){

    //VISITED NAHI HAIN TO CALL KARO JARA CHECK KARO
    if(!visited[i]){

      //CALL GAYA HAIN NA TO TRUE MARK KARO
      dfscalls[i]=1;

      //US PART ME CYCLE HAIN TO THIK ANS RETURN KARO NAHITO BAKI NEIGHBORS KA KHABAR LO
      bool ans = dfs(visited,dfscalls,adj,i);
      if(ans)
        return ans;

    }

    //AGAR VISITED HAIN AND USKA CALL BHI PADA HUA HAIN TO ANS MIL GAYA BHAI
    else if(dfscalls[i]){
      return true;
    }

  }

  //WAPAS JATE HUYE CALLL BHI TO MAR JAYE GA NA
  dfscalls[curr_node]=false;

  //ANSWER RETURN KARDENA
  return false;
  
}


//DRIVER HAIN BHAI
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

  //YOHI ADJ LIST BANANA
  unordered_map<int,list<int>> adj;
  for(auto i : edges){
    int u = i.first;
    int v = i.second;
    adj[u].push_back(v);
  }

  //KONSA NODE VISIT KARLIYA HAIN
  unordered_map<int,bool> visited;

  //KISKE KE LIYE DFS CALL GAYA HAIN
  unordered_map<int,bool> dfscalls;

  //CHECK FOR ALL POSSIBLE NODES IF CYCLE IS PRESENT
  for(int i = 0;i<n;i++){

    //IF NOT VISITED THEN TRAVERSE IT BY USING THE DFS
    if(!visited[i]){

      //ISKA CALL GAYA TO TRUE HOGA
      dfscalls[i]=1;

      //AGAR CUCLE HAIN TO THIK NAHI TO BAKI KE NODES KE LIYE CALL KARO 
      bool have_cycle = dfs(visited,dfscalls,adj,i);
      if(have_cycle){
        return true;
      }

    }

  }

  //NAHI MIAL KOI BHI NODE ME CYCLE
  return false;

}

int main(){

  return 0;
}
