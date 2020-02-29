//28/2/20
//UVA problem 10920
#include <bits/stdc++.h>

using namespace std;

int main(){
	long size,query;
	while(cin >> size && size != 0){
		cin  >> query;
		long yDirection = 1,xDirection = -1;
		long xPos = (size/2)+1;
		long yPos = xPos;
		long num = 1;
		while(num < query){
			if(num == query){
				break;
			}
			yPos += yDirection;
			num+= abs(yDirection);
			if(yDirection > 0){
				yDirection++;
			}
			else{
				yDirection--;
			}
			yDirection *= -1;
			if(num == query){
				break;
			}
			//if we passed the query go back
			else if(num > query){
				if(yDirection <= -1){
					yPos -= (num-query);	
				}
				else{
					yPos += (num-query);
				}
				break;
			}
			//update x position
			xPos += xDirection;
			num+= abs(xDirection);
			if(xDirection > 0){
				xDirection++;
			}
			else{
				xDirection--;
			}
			xDirection *= -1;
			if(num == query){
				break;
			}
			//if we passed the query go back
			else if(num > query){
				if(xDirection <= -1){
					xPos -= (num-query);	
				}
				else{
					xPos += (num-query);
				}	
				break;
			}
		}
		cout << "Line = " << yPos << ", column = " << xPos << ".\n";
	}
}
