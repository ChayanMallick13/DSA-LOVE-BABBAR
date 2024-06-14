/*

    QUESTION -    https://www.naukri.com/code360/problems/sudoku-solver_699919?leftPanelTabValue=PROBLEM

*/





#include <bits/stdc++.h> 

//TO CHECK IF WE CAN PUT A CERTAIN VALUE IN THE SUDOKU
bool is_safe(vector<vector<int>> & grid,int target,int row,int col){
    
    //check row if same element already exists
    for(int i = 0;i<9;i++){
        if(grid[row][i]==target){
            return false;
        }
    }

    //check  col if same element already exists
    for(int i = 0;i<9;i++){
        if(grid[i][col]==target){
            return false;
        }
    }

    //check sub 3x3 grid  if same element already exists
    int nrow = (row/3)*3;
    int ncol = (col/3)*3;
    for(int i = nrow;i<nrow+3;i++){
        for(int j = ncol;j<ncol+3;j++){
            if(grid[i][j]==target){
                return false;
            }
        }
    }

    //passed all CASES
    return true;

}

//MAIN SOLVING FUNCTION
bool solve(vector<vector<int>> & grid){

    //SEARCH FOR AN EMPTY POSITION
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){

            //EMPTY POSITION FOUND
            if(grid[i][j]==0){

                //FOR ALL NINE POSSIBLE 1-9 CHECK WHETHER IT CAN BE PLACED THERE USING IS_SAFE
                for(int k = 1;k<=9;k++){

                    //IF ITS SAFE
                    if(is_safe(grid,k,i,j)){

                        //PLACE THE VALUE
                        grid[i][j]=k;

                        //CHECK FOR THE REST POSTIONS WE GET A SOL
                        bool f = solve(grid);

                        //IF SO THEN THAT IS THE SOL
                        if(f){  
                            return true;
                        }
                        
                    }

                }

                //AGAR 1-9 ME KOI BHI SOL SATISFY NAHI KARA TO GAAT FILL KARDIYA BACKTRACK KARO
                return false;

            }

        }
    }

    //KOI BLANK SPACE NAHI TO SOL MIL GAYA
    return true;

}

//DRIVER FUNC
void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
}
