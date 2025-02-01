#include<stdio.h>

typedef struct player{
	int score[2];
	char name[50];
	int total;
}Player;

int validateScore(int score){
	if(score < 0 || score > 6){
		return -1;
	}
	else{
		return score;
	}
}

void playGame(Player *player, int ball){
	int score;
	
	printf("%s, enter score for ball %d: ", player->name, ball + 1);
	scanf("%d", &score);
	
	if(validateScore(score) != -1){
		player->score[ball] = score;
	}
	else{
		player->score[ball] = 0;
	}
	
	player->total += player->score[ball];
}

void findWinner(Player p1,Player p2){
	if(p1.score > p2.score){
		printf("Winner is %s with a score of %d.\n", p1.name, p1.total);
	}
	else{
		printf("Winner is %s with a score of %d.\n", p2.name, p2.total);
	}
}

void displayMatchScoreboard(Player p1, Player p2){
	printf("\nScoreBoard\n");
	for(int i = 0; i < 12; i++){
		printf("Score for ball %d:\n", i+1);
		printf("%s = %d\n", p1.name, p1.score[i]);
		printf("%s = %d\n", p2.name, p2.score[i]);
	}
	
	printf("\n%s:", p1.name);
	printf("\nTotal score: %d", p1.total);
	printf("\nAverage score: %f", (float)p1.total / 2);
	printf("\n%s:", p2.name);
	printf("\nTotal score: %d", p2.total);
	printf("\nAverage score: %f", (float)p2.total / 2);
}

main(){
	Player p1;
	Player p2;
	
	printf("Enter name for player 1: ");
	scanf("%s", p1.name);
	printf("Enter name for player 2: ");
	scanf("%s", p2.name);
	
	for(int i = 0; i < 12; i++){
		playGame(&p1, i);
		playGame(&p2, i);	
	}
	
	findWinner(p1, p2);
	displayMatchScoreboard(p1, p2);
}