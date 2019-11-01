// 8/7/2019
/*
This code takes in an x y coordinate and the centre point of the border lines
Then outputs which region the point lies on
*/
#include <iostream>
using namespace std;
int main(){
	int K, x, y, M, N;
	while(scanf("%d", &K) != EOF){
		scanf("%d %d", &M, &N);
		while(K--){
			scanf("%d %d", &x, &y);
			if(x == M || y == N){
				printf("divisa\n");
			}
			else if(x>M && y>N){
				printf("NE\n");
			}
			else if(x<M && y>N){
				printf("NO\n");
			}
			else if(x>M && y<N){
				printf("SE\n");
			}
			else if(x<M && y<N){
				printf("SO\n");
			}
		}
	}
}
