/*
Michael Connors
UVA Problem 10189
11/10/19
*/
#include <iostream>

using namespace std;

int main(){
	int n,m;
	int caseNo = 1;
	while(scanf("%d %d",&n,&m) && n != 0){//scans input until n = 0
		char input[n][m];
		int field[n][m];
		//puts input int an array
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				char inp;
				cin >> inp;
				input[i][j] = inp;
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				//Checks if that space is a mine
				if(input[i][j] == '*'){
					field[i][j] = 9;
				}
				else{
					//Otherwise checks how many mines are surrounding it
					int adjacent = 0;
					if(input[i+1][j] == '*'){
						if(i != n-1){
							adjacent++;
						}
					}
					if(input[i-1][j] == '*'){
						if(i != 0){
							adjacent++;
						}
					}
					if(input[i][j+1] == '*'){
						if(j != m-1){
							adjacent++;
						}
					}
					if(input[i][j-1] == '*'){
						if(j != 0){
							adjacent++;
						}
					}
					if(input[i+1][j+1] == '*'){
						if(i != n-1 && j != m-1){
							adjacent++;
						}
					}
					if(input[i+1][j-1] == '*'){
						if(i != n-1 && j != 0){
							adjacent++;
						}
					}
					if(input[i-1][j+1] == '*'){
						if(i != 0 && j != m-1){
							adjacent++;
						}
					}
					if(input[i-1][j-1] == '*'){
						if(i != 0 && j != 0){
							adjacent++;
						}
					}
					field[i][j] = adjacent;
				}
			}
		}
		if(caseNo != 1){
			printf("\n");
		}
		printf("Field #%d:\n",caseNo);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(field[i][j] == 9){
					printf("*");
				}
				else{
					printf("%d",field[i][j]);
				}
				if(j == m-1){
					printf("\n");
				}
			}
			if(i == n-1){
				//printf("\n");
			}
		}
		caseNo++;
	}	
}
