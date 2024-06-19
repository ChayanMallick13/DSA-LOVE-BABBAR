/*

      https://www.naukri.com/code360/problems/dijkstra-s-shortest-path_920469?leftPanelTab=0

*/



#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {

    //DATA STRUCTURES REQ
    //->SET
    //->ADJ LIST
    //->ANS VECTOR

    //SET
    set<pair<int,int>> s;

    //ANSWER VECTOR
    vector<int> dis(vertices,INT_MAX);

    //ADJ LIST IN MAKING
    unordered_map<int,vector< pair<int,int> > > adj;
    for(auto i : vec){

        adj[i[0]].push_back({i[1],i[2]});
        adj[i[1]].push_back({i[0],i[2]});

    }

    //SOURCE KA DIS 0 SET KARO KHUD SE
    dis[source]=0;

    //KHUD SE INITIATE KARO 0,SRC KA PAIR DALKE
    s.insert({0,source});

    //JAB TAK SET EMPTY NA HO 
    while(!s.empty()){

        //LEAST DIS WALA NIKALO AND USKO HATA DO
        pair<int,int> top = *(s.begin());
        s.erase(s.begin());

        //TOP WALA NODE AND WAHA TAK POHUCH NE KA TARIKA
        int node = top.second;
        int node_dis = top.first;

        //BADME KAM AYEGA
        set<pair<int,int>> :: iterator f;

        //ISKE NEIGHBOURS KO DEKHO
        for(auto i : adj[node]){

            //SRC SE IS NODE VIA THIS NODE DIS
            int dist = node_dis+i.second;

            //AGAR YE LEAST DIS HAIN TO MODIFY KARO VALUE
            if(dist<dis[i.first]){

                //DALNE SE PEHLE CHECK KARLO KI IS SAME ELEMENT KA ZYADA DIS KA CALL 
                //PADA HAIN KI NAHI
                f = s.find({dis[i.first],i.first});

                //AGAR PADA HAIN TO
                if(f!=s.end()){

                    //USSE HATA DO
                    s.erase(f);

                }

                //IS NAYA WALA DALO AND DIS MODIFY KARO
                dis[i.first]=dist;
                s.insert({dist,i.first});

            }

        }
        
    }

    //RETURN ANS
    return dis;
    
}

