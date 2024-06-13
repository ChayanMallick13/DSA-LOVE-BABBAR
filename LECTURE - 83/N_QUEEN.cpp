/*

    QUESTION LINK :-   https://www.naukri.com/code360/problems/the-n-queens-puzzle_981286?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

*/


/******************************************************   APPROACH - 1  ************************************************************************/


#include <bits/stdc++.h> 

//TO CHECK WHETHER WE CAN PLACE A QUEEN AT THAT POSITION IN BOARD WITHOUT BEING ATTACKED
bool can_palce(vector<vector<int>> & board,int col,int row,int n){

	//CHECK FOR ROW ATTACK FROM THAT COL TO 0 RIGHT ME PLACE HI NAHI KIYA 
	for(int j = col;j>=0;j--){
		if(board[row][j]==1){
			return false;
		}
	}


	//CHECK FOR LOWER DIA
	int i=row,j=col;
	while(i<n&&j<n&&i>=0&&j>=0){
		if(board[i][j]==1){
			return false;
		}
		i++;
		j--;
	}

	//NO NEED FOR LOWER DIA NEXT PART BECAUSE RIGHT ME PLACE NAHI KIYA


	//CHECK FOR THE UPPER DIA
	i=row,j=col;
	while(i<n&&j<n&&i>=0&&j>=0){
		if(board[i][j]==1){
			return false;
		}
		i--;
		j--;
	}

	//NO NEED FOR UPPER DIA NEXT PART BECAUSE RIGHT ME PLACE NAHI KIYA
	return true;

}

//MAIN SOLVE FUNCTION
void solve(vector<vector<int>> & board,vector<vector<int>> & ans,int currcol,int n,vector<int> & path){

	//BASE CONDITION ALL N QUEENS PLACED NOW
	if(currcol>=n){

		//ANS STORE KARDO
		ans.push_back(path);
		return;

	}

	//CHECK WHERE WE CAN PLACE THE NEW QUEEN IN THIS COL
	for(int i = 0;i<n;i++){

		//IF WE CAN PLACE PLACE IT AND CHECK FOR PLACING FURTHER
		if(can_palce(board, currcol, i,n)){

			//PLACE QUEENS
			board[i][currcol]=1;
			path[i*n+currcol]=1;

			//CHECK FURTHER CALL
			solve(board, ans, currcol+1, n, path);

			//RESET THE VALUES
			path[i*n+currcol]=0;
			board[i][currcol]=0;

		}

	}

}

//DRIVER FUNCTION 
vector<vector<int>> nQueens(int n)
{

	//DENOTES THE BOARD
	vector<vector<int>> board(n,vector<int>(n,0));

	//TO RETURN THE ANS
	vector<vector<int>> ans;

	//TO STORE THE ANS
	vector<int> path(n*n,0);

	//CALL TH SOLVE
	solve(board,ans,0,n,path);

	//RETURN ANS
	return ans;
	
}


/***********************************************************************************************************************************************/







/******************************************************   APPROACH - 2  ************************************************************************/


#include <bits/stdc++.h> 

//TO CHECK WHETHER WE CAN PLACE A QUEEN AT THAT POSITION IN BOARD WITHOUT BEING ATTACKED
bool can_palce(unordered_map<int,bool> & r,unordered_map<int,bool> & upper,unordered_map<int,bool> & lower,int col,int row,int n){

	//FOR THE ROW
	if(r[row]){
		return false;
	}

	//FOR THE UPPER 
	if(upper[n-1+col-row]){
		return false;
	}

	//FOR THE LOWER
	if(lower[col+row]){
		return false;
	}

	return true;
}

//MAIN SOLVE FUNCTION
void solve(vector<vector<int>> & board,vector<vector<int>> & ans,int currcol,int n,vector<int> & path,unordered_map<int,bool> & r,unordered_map<int,bool> & upper,unordered_map<int,bool> & lower){

	//BASE CONDITION ALL N QUEENS PLACED NOW
	if(currcol>=n){

		//ANS STORE KARDO
		ans.push_back(path);
		return;

	}

	//CHECK WHERE WE CAN PLACE THE NEW QUEEN IN THIS COL
	for(int i = 0;i<n;i++){

		//IF WE CAN PLACE PLACE IT AND CHECK FOR PLACING FURTHER
		if(can_palce(r,upper,lower,currcol,i,n)){

			//PLACE QUEENS
			board[i][currcol]=1;
			path[i*n+currcol]=1;

			//SET ALLL THE PRECAUTIONS TO CHECK FOR ATTACK
			r[i]=1;
			upper[n-1+currcol-i]=1;
			lower[currcol+i]=1;

			//CHECK FURTHER CALL
			solve(board, ans, currcol+1, n, path,r,upper,lower);

			//RESET THE VALUES
			path[i*n+currcol]=0;
			board[i][currcol]=0;

			//SET THE PLACING PARAMETERS TO RESET
			r[i]=0;
			upper[n-1+currcol-i]=0;
			lower[currcol+i]=0;
			
		}

	}

}

//DRIVER FUNCTION 
vector<vector<int>> nQueens(int n)
{
	unordered_map<int,bool>  r;
	unordered_map<int,bool>  upper;
	unordered_map<int,bool>  lower;

	//DENOTES THE BOARD
	vector<vector<int>> board(n,vector<int>(n,0));

	//TO RETURN THE ANS
	vector<vector<int>> ans;

	//TO STORE THE ANS
	vector<int> path(n*n,0);

	//CALL TH SOLVE
	solve(board,ans,0,n,path,r,upper,lower);

	//RETURN ANS
	return ans;
	
}


/***********************************************************************************************************************************************/
