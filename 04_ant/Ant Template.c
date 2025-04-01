#include <stdio.h>
#include <stdlib.h>
#define N 20

typedef struct Ant {
	int pi, pj;
	int direction;
} Ant;

int rnd(const int min, const int max) {
	return (rand() % (max - min)) + min;
}

void print_board(int** board, const int n) {
}

void print_ant(const Ant ant) {
}

void init_board(int*** board, const int n) {
}

void free_board(int** board, const int n) {
}

void ant_move(int** board, const int n, Ant* ant) {
}

void ant_simulation(int** board, const int n, Ant* ant, const int steps) {
}

int main(void) {
	int** board;
	int n, steps;
	unsigned seed;
	Ant ant;

	scanf("%d %d %d", &n, &seed, &steps);
	srand(seed);
	init_board(&board, n);
	ant_simulation(board, n, &ant, steps);
	print_board(board, n);
	print_ant(ant);

	free_board(board, n);

	return 0;
}

