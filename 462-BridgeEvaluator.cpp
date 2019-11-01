//01/10/19
//UVA problem 462

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
using namespace std;

int main(){
	//maps to convert suits and ranks to array positions
	map<char,int> rank_convert;
	rank_convert['A'] = 4;
	rank_convert['K'] = 3;
	rank_convert['Q'] = 2;
	rank_convert['J'] = 1;

	map<char,int> suit_convert;
	suit_convert['S'] = 0;
	suit_convert['H'] = 1;
	suit_convert['D'] = 2;
	suit_convert['C'] = 3;
	
	map<int,char> suit_convert_reverse;
	suit_convert_reverse[0] = 'S';
	suit_convert_reverse[1] = 'H';
	suit_convert_reverse[2] = 'D';
	suit_convert_reverse[3] = 'C';

	string input;
	while(getline(cin,input)){
		int rank_amounts[] = {0,0,0,0,0};
		int suit_amounts[] = {0,0,0,0};
		bool stopped[] = {false,false,false,false};
		int score = 0;
		char rank, suit;
		vector< pair<char,char> > hand;
		for(int i = 0;i < 38;i += 3){
			rank = input[i];
			suit = input[i+1];
			hand.push_back(make_pair(rank,suit));
			//Record all cards in hand and apply rule 1
			switch(rank){
				case 'A': score +=4; rank_amounts[4]++;stopped[suit_convert[suit]]=true; break;
				case 'K': score +=3; rank_amounts[3]++; break;
				case 'Q': score +=2; rank_amounts[2]++; break;
				case 'J': score +=1; rank_amounts[1]++; break;
			}
			switch(suit){
				case 'S': suit_amounts[0]++; break;
				case 'H': suit_amounts[1]++; break;
				case 'D': suit_amounts[2]++; break;
				case 'C': suit_amounts[3]++; break;
				default: printf("Error\n");
			}
		}
		//Rules 2,3 and 4
		for(int i = 0;i < 12;i++){
			if(hand[i].first == 'K'){
				if(suit_amounts[suit_convert[hand[i].second]] == 0){
					score --;
				}
				if(suit_amounts[suit_convert[hand[i].second]] >= 1){
					stopped[suit_convert[suit]]=true;
				}
			}
			if(hand[i].first == 'Q'){
				if(suit_amounts[suit_convert[hand[i].second]] < 2){
					score --;
				}
				if(suit_amounts[suit_convert[hand[i].second]] >= 2){
					stopped[suit_convert[suit]]=true;
				}
			}
			if(hand[i].first == 'J' && suit_amounts[suit_convert[hand[i].second]] < 3){
				if(suit_amounts[suit_convert[hand[i].second]] < 3){
					score --;
				}
			}
		}
		//Checks for bid no trump
		bool all_stopped = false;
		if(stopped[0] == true && stopped[1] == true && stopped[2] == true && stopped[3] == true){
			all_stopped = true;
		}
		if(score >= 16 && all_stopped){
			printf("BID NO_TRUMP\n");
		}
		else{
			//applies rule 5,6 and 7
			for(int i = 0;i < 4;i++){
				if(suit_amounts[i] == 2){
					score++;
				}
				else if(suit_amounts[i] < 2){
					score += 2;
				}
			}
			//check for pass
			if(score < 14){
				printf("PASS\n");
			}
			//calculates what to bid
			else{
				int largest = 0;
				int pos = 0;
				for(int i = 0;i < 4;i++){
					if(suit_amounts[i] > largest){
						largest = suit_amounts[i];
						pos = i;
					}						
				}
				printf("BID %c\n",suit_convert_reverse[pos]);
			}
		}
	}
}
