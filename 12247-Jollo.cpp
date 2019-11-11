//10/11/19
//UVA Problem 12247

#include <bits/stdc++.h>

using namespace std;

int sister[3],prince[2];
int set[5];
int main(){
	int a,b,c,x,y;
	while(cin >> sister[0] && sister[0] != 0){
		cin >> sister[1] >> sister[2] >> prince[0] >> prince[1];
		sort(sister,sister+3);
		sort(prince,prince+2);
		int set[5] = {sister[0],sister[1],sister[2],prince[0],prince[1]};
		int smallest = 1;
		if(prince[0] > sister[2]){
			for(int i = 0;i < 5;i++){
				if(smallest == set[i]){
					smallest++;
				}
			}
		}
		else if(prince[0] > sister[1]){
			for(int i = 0;i < 2;i++){
				if(smallest < sister[i]){
					smallest = sister[i] + 1;
				}
			}
			for(int i = 0;i < 5;i++){
				if(smallest == set[i]){
					smallest++;
				}
			}
			
		}
		else if(prince[1] > sister[2]){
			for(int i = 0;i < 3;i++){
				if(smallest < sister[i]){
					smallest = sister[i] + 1;
				}
			}
			for(int i = 0;i < 5;i++){
				if(smallest == set[i]){
					smallest++;
				}
			}
		}
		else{//Can't win
			smallest = -1;
		}
		for(int i = 0;i < 5;i++){
			if(smallest == set[i]){ //Checks if card is already dealt
				smallest++;
			}
		}
		if(smallest > 52){ //Edge Case
			smallest = -1;
		}
		cout << smallest << endl;
	}
}
