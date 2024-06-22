/*

https://www.naukri.com/code360/problems/bellmon-ford_2041977?leftPanelTab=0&leftPanelTabValue=PROBLEM

*/



vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {

    //  BELLMANS FORD ALGORITHM
    vector<int> dis(n+1,1e8);

    //DISTANCE OF SRC KO PEHLE KHUD SE 0 KARO
    dis[src]=0;

    // SAARE EDGES KO N-1 BAR CHECK KARO 
    for(int j = 1;j<n;j++){

        //CHECK FOR EVERY EDGE
        for(auto i : edges){

            //APPLY FORMULA FOR BELLMANS
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            if(  (dis[u]+wt<dis[v])){
                dis[v]=dis[u]+wt;
            }

        }
    }

    
    //return ans
    return dis;
}
