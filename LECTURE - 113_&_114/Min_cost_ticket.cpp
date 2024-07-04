//       https://leetcode.com/problems/minimum-cost-for-tickets/



class Solution {
private:

int solve(int ind,vector<int>& days, vector<int>& costs){
    if(ind>=days.size()){
        return 0;
    }

    int op1 = costs[0] + solve(ind+1,days,costs);
    int h = days.size();
    for(int i = ind;i<days.size();i++){
        if(days[ind]+7<=days[i]){
            h = i;

            break;
        }
    }
    int op2 = costs[1] + solve(h,days,costs);
    h = days.size();
    for(int i = ind;i<days.size();i++){
        if(days[ind]+30<=days[i]){
            h = i;

            break;
        }
    }
    int op3 = costs[2] + solve(h,days,costs);

    return min(op1,min(op2,op3));
}


int solve_mem(int ind,vector<int>& days, vector<int>& costs,vector<int> & dp){
    if(ind>=days.size()){
        return 0;
    }
    if(dp[ind]!=-1){
        return dp[ind];
    }

    int op1 = costs[0] + solve_mem(ind+1,days,costs,dp);
    int h = days.size();
    for(int i = ind;i<days.size();i++){
        if(days[ind]+7<=days[i]){
            h = i;

            break;
        }
    }
    int op2 = costs[1] + solve_mem(h,days,costs,dp);
    h = days.size();
    for(int i = ind;i<days.size();i++){
        if(days[ind]+30<=days[i]){
            h = i;

            break;
        }
    }
    int op3 = costs[2] + solve_mem(h,days,costs,dp);

   dp[ind] = min(op1,min(op2,op3));
   return dp[ind];
}


int tabu(vector<int>& days, vector<int>& cost){
    int n = days.size();
    vector<int> tab(n,INT_MAX);
    tab[n-1] = min(cost[0],min(cost[1],cost[2]));
    for(int i = n-2;i>=0;i--){
        tab[i] = min(tab[i],tab[i+1]+cost[0]);


        int h = days.size();
        for(int j = i;j<days.size();j++){
            if(days[i]+7<=days[j]){
                h = j;

                break;
            }
        }
        if(h<n){
            tab[i] = min(tab[i],cost[1] + tab[h]);
        }
        else{
            tab[i] = min(tab[i],cost[1]);
        }

        h = days.size();
        for(int j = i;j<days.size();j++){
            if(days[i]+30<=days[j]){
                h = j;

                break;
            }
        }

        if(h<n){
            tab[i] = min(tab[i],cost[2] + tab[h]);
        }
        else{
            tab[i] = min(tab[i],cost[2]);
        }

    }

    return tab[0];
}


int sp_opti(vector<int>& days, vector<int>& cost){
    queue<pair<int,int>> mon,week;
    int n = days.size();
    mon.push({days[n-1]+30,0});
    week.push({days[n-1]+7,0});

    int ans = INT_MAX;
    for(int i = days.size()-1;i>=0;i--){

        //step 1
        int day = days[i];
        while(!mon.empty() && mon.front().first>day+30){
            mon.pop();
        }
        while(!week.empty() && week.front().first>day+7){
            week.pop();
        }


        //step 2
        int op1 = INT_MAX;
        if(ans!=INT_MAX)
            op1 = ans + cost[0];
        mon.push({day,cost[1]+mon.front().second});
        week.push({day,cost[2]+week.front().second});

        // step3 
        ans = min(op1,min(mon.front().second,week.front().second));
    }
    return ans;
}


int more_op(vector<int>& days, vector<int>& cost){
    int ans = 0;
    queue<pair<int,int>> week,month;

    for(int day : days){

        while(!week.empty() && week.front().first + 7 <= day){
            week.pop();
        }

        while(!month.empty() && month.front().first + 30 <= day){
            month.pop();
        }

        week.push({day,ans+cost[1]});
        month.push({day,ans+cost[2]});

        ans = min(ans+cost[0],min(week.front().second,month.front().second));

    }

    return ans;
}

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // return solve(0,days,costs);
        vector<int> dp(days.size(),-1);
        // return solve_mem(0,days,costs,dp);
        // return tabu(days,costs);
        // return sp_opti(days,costs);

        return more_op(days,costs);
    }
};
