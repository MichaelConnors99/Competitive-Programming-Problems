//19/08/19
/*
UVA Problem 11799
*/
#include <iostream>

using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int i = 1;i <= T;i++){
		int N;
		int max=0;
		scanf("%d", &N);
		while(N--){
			int speed;
			scanf("%d", &speed);
			if(speed > max){
				max=speed;
			}
		}
		printf("Case %d: %d\n", i, max);
	}
}
