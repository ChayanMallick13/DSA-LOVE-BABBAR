/*

      QUESTION LINK :-   https://www.naukri.com/code360/problems/rat-in-a-maze_1215030?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM

*/



#include <bits/stdc++.h> 

//TO CHECK IF IS IT SAFE TO MOVE TO THAT POSITION CAN WE MOVE TO THAT POSTION??
bool issafe(int i,int j,int n,vector<vector<bool>> & v,vector<vector<int>> & m){

    return (i>=0) && (i<n) && (j>=0) && (j<n) && (!v[i][j]) && (m[i][j]);

}

//MAIN FUNCTION WHICH WE CALL RECURSIVELY
void solve(vector<string> & ans,int i,int j,int n,vector<vector<bool>> & v,string path,vector < vector < int >> & arr){
    
    //DESTINATION REACHED
    if(i==n-1 && j == n-1){

        ans.push_back(path);
        return;

    }

    //YAHA AGAY TO MARK THIS POSITION AS VISITED
    v[i][j]=1;

    //READY THE ARRAYS TO MAKE CALL FOR D L R U
    vector<int> calls={i+1,j,i,j-1,i,j+1,i-1,j};
    vector<string> call2 = {"D","L","R","U"};

    //IF IT IS SAFE TO MOVE TO THAT POSITION THEN MAKE A CALL FOR THAT
    for(int i = 0;i<7;i+=2){

        if(issafe(calls[i], calls[i+1], n, v,arr)){
            solve(ans, calls[i], calls[i+1], n, v, path+call2[i/2],arr);
        }

    }

    //NOW YAHA SE WAPAS JARAHA HAIN TO YE VISITED NAHI HOGA NA TO RESET KARO
    v[i][j]=0;

}

//DRIVER FUNCTION
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    
    //CREATING A VECTOR FOR STORING ANS
    vector<string> ans;

    //HANDLING A EDGE CASE IF THE FIRST ELEMENT IS 0 NO POSSIBLE MOVE
    if(arr[0][0]==0){
        return ans;
    }

    //VISITED ARRAY
    vector<vector<bool>> v;
    for(int i = 0;i<n;i++){
        vector<bool> temp(n,0);
        v.push_back(temp);
    }

    //FOR STORING THE PATH AS WE MOVE
    string path = "";

    //DRIVER FUNCTION FOR THE SOLUTION
    solve(ans,0,0,n,v,path,arr);

    //RETURN THE ANSWER FINALLY
    return ans;

}
