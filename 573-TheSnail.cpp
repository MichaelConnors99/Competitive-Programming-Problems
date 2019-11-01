//19/08/19
/*
UVA problem 573
*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int H, U, D, F;
	while(scanf("%d %d %d %d", &H, &U, &D, &F) && H != 0){
		int day=1;
		double climb =(double)U;
		double progress=0;
		double fatigue=(double)F/100;
		double loss=fatigue*climb;
		while(true){
			progress += climb;
			if(progress > H){
				printf("success on day %d\n", day);
				break;
			}
			progress -= D;
			if(progress < 0){
				printf("failure on day %d\n", day);
				break;
			}

			if(climb >= loss){
				climb -= loss;
			}

			else{
				climb = 0;
			}
			day++;
		}
	}
}
