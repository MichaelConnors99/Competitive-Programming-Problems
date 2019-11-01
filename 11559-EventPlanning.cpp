//19/08/19
/*
UVA problem 11559
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N,B,H,W;
	while(scanf("%d %d %d %d", &N, &B, &H, &W) != EOF){
		int maxPrice=B/N;
		int cheapestPrice=500001;
		for(int i = 0;i < H;i++){
			int p;
			scanf("%d", &p);
			for(int j = 0;j < W;j++){
				int bedsAvailable;
				scanf("%d", &bedsAvailable);
				if(bedsAvailable > N && p < maxPrice){
					cheapestPrice = p*N;
					maxPrice=p;
				}
			}
		}
		if(cheapestPrice==500001){
			cout << "stay home" << endl;
		}
		else{
			cout << cheapestPrice <<endl;
		}
	}	
}
