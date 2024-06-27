  //  https://www.naukri.com/code360/problems/cut-into-segments_1214651?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0



#include<limits.h>

//    RECURSION ONLY
int solve(int n,int x,int y,int z){
	if(n==0){
		// Agar n zero ho, to humne segment ko pura cut kar diya hai,
		// isliye return 0 karte hain.
		return 0;
	}
	if(n<0){
		// Agar n zero se chhota ho, iska matlab yeh hai ki segment ko hum
		// is tarike se nahi cut kar sakte, isliye return INT_MIN karte hain.
		return INT_MIN;
	}

	int a = solve(n-x, x, y, z);
	int b = solve(n-y, x, y, z);
	int c = solve(n-z, x, y, z);
	// Teenon possibilities ke results ko compare karke maximum value choose karte hain.
	int ans =  max(a,max(b,c));
	// Kyunki humne ek segment cut kar liya hai, isliye result mein 1 add karte hain.
	return ans+1;
}



//     RECURSION + MEMORISATION
int solve1(int n,int x,int y,int z,vector<int> & dp){
	if(n==0){
		// Agar n zero ho, to humne segment ko pura cut kar diya hai,
		// isliye return 0 karte hain.
		return 0;
	}
	if(n<0){
		// Agar n zero se chhota ho, iska matlab yeh hai ki segment ko hum
		// is tarike se nahi cut kar sakte, isliye return INT_MIN karte hain.
		return INT_MIN;
	}
	if(dp[n]!=-1){
		// Agar dp array mein n ke liye already value store ho, to wahi return karte hain.
		return dp[n];
	}

	int a = solve1(n-x, x, y, z,dp);
	int b = solve1(n-y, x, y, z,dp);
	int c = solve1(n-z, x, y, z,dp);
	// Teenon possibilities ke results ko compare karke maximum value choose karte hain.
	int ans =  max(a,max(b,c))+1;
	// Result ko dp array mein store karte hain taaki future calls mein use kar sakein.
	dp[n]=ans;
	return dp[n];
}


//     TABULATION
int tabu(int n,int x,int y,int z){
	// x, y, z ko ek array mein store karte hain.
	vector<int> ifo = {x,y,z};
	// Tabulation ke liye ek array create karte hain aur usse INT_MIN se initialize karte hain.
	vector<int> tab(n+1,INT_MIN);
	tab[0]=0; // Base case: agar n zero ho, to 0 return karte hain.
	for(int i = 1;i<=n;i++){
		for(auto j : ifo){
			if(i-j>=0){
				// Agar current index par segment cut possible ho, to tab array ko update karte hain.
				tab[i] = max(tab[i-j]+1,tab[i]);
			}
		}
	}
	if(tab[n]<0){
		// Agar final result negative ho, iska matlab segment cut possible nahi hai, to 0 return karte hain.
		return 0;
	}
	// Final result return karte hain.
	return tab[n];
}



//SPACE OPTI NOT POSSIBLE 


//DRIVER
int cutSegments(int n, int x, int y, int z) {
	// Yeh function sabse efficient approach ko use karta hai (tabulation).
	// solve1 aur tab ke beech choose karne ka option diya gaya hai.
	// vector<int> dp(n+1,-1);
	// int ans = solve1(n, x, y, z,dp);
	// if(ans < 0){
	// 	return 0;
	// }
	// return ans;
	return tabu(n, x, y, z);
}

