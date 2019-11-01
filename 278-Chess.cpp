// UVA 278 Chess
//Michael Connors
// 7/10/19
#include <iostream>

using namespace std;

int main(){
	int cases;
	scanf("%d", &cases);
	for(int i = 0;i < cases;i++){
		char piece;
		int rows, columns;
		cin >> piece >> rows >> columns;
		int area = rows * columns;
		int answer = 0;

		if(piece == 'r'){
			if(rows <= columns){
				answer = rows;
			}
			else if(rows > columns){
				answer = rows;
			}	
		}

		if(piece == 'k'){
			if(area % 2 == 0){
				answer = area/2;
			}
			else{
				answer = area/2 + 1; 
			}
		}

		if(piece == 'K'){
			if(rows % 2 == 1){
				rows = rows / 2 +1;
			}
			else{
				rows /= 2;
			}
			if(columns % 2 == 1){
				columns = columns / 2 + 1;
			}
			else{
				columns /= 2;
			}
			answer = rows * columns;
		}

		if(piece == 'Q'){
			if(rows <= columns){
				answer = rows;
			}
			else if(rows > columns){
				answer = columns;
			}
		}

		printf("%d\n", answer);
	}
}
