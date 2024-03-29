
#include "helpers.h"


void clear(int disp[LENGTH][WIDTH]){
	printf("\e[1;1H\e[2J");
}

void display(int disp[LENGTH][WIDTH]) {
	for (int y = 0; y < LENGTH; y++){
		for (int x = 0; x < WIDTH; x++){
			printf("%4d", disp[y][x]);
		}
		for (int x = 0; x < WIDTH/2; x++){
			printf("\n");   
		}
	}
}

void addValues(int disp[LENGTH][WIDTH], int* score) { 
	int* zeroes[LENGTH*WIDTH] = {0}; // array of addresses of display where the value is 0
	int c = 0;
	memset(zeroes, -1, sizeof zeroes);
	for(int y = 0; y < LENGTH; y++){
		for(int x = 0; x < WIDTH; x++){
			if (disp[y][x] == 0) {
				zeroes[c] = &disp[y][x];
				c++;
			}
		}
	}
	if (c == 0) {
		//check if there is a possible move if none, lose
	   *score = 0; 
	   memset(disp, 0, sizeof(disp[0][0])*LENGTH*WIDTH);
	} else {
		*zeroes[rand() % c] = (rand() % (2) + 1) * 2;
	}

}

void getInput(char* ptr) {
	printf("Enter a value: ");
	scanf(" %c", ptr);
	// fflush(stdin);
}

void shiftLeft(int disp[LENGTH][WIDTH], int* score) {
	int c;
	int l;
	for (int y = 0; y < LENGTH; y++){
		//merge all pairs
		c = 0;
		l = -1;
		while(c < WIDTH) {
			if (disp[y][c] != 0) {
				if (l == -1 || disp[y][c] != disp[y][l]) {
					l = c; 
				} else {
					disp[y][l] = disp[y][l]*2;
					*score += disp[y][l];
					disp[y][c] = 0; 
					l = -1;
				}
			}
			c++;
		}
		// move all non zeros left
		c = 0;
		for (int x = 0; x < WIDTH; x++){
			if (disp[y][x] != 0)
				disp[y][c++] = disp[y][x];
		}
		while (c < WIDTH) {
			disp[y][c++] = 0;
		}       
	}
}

void shiftRight(int disp[LENGTH][WIDTH], int* score) {
	int c;
	int r;
	for (int y = 0; y < LENGTH; y++){
		//merge all pairs
		c = WIDTH - 1;
		r = -1;
		while(c >= 0) {
			if (disp[y][c] != 0) {
				if (r == -1 || disp[y][c] != disp[y][r]) {
					r = c; 
				} else {
					disp[y][r] = disp[y][r]*2;
					*score += disp[y][r];
					disp[y][c] = 0; 
					r = -1;
				}
			}
			c--;
		}
		// move all non zeros right
		c = WIDTH-1;
		for (int x = WIDTH - 1; x >= 0; x--){
			if (disp[y][x] != 0)
				disp[y][c--] = disp[y][x];
		}
		while (c >= 0) {
			disp[y][c--] = 0;
		}       
	}
}

void shiftUp(int disp[LENGTH][WIDTH], int* score) {
	int c;
	int u;
	for (int x = 0; x < WIDTH; x++){
		//merge all pairs
		c = 0;
		u = -1;
		while(c < LENGTH) {
			if (disp[c][x] != 0) {
				if (u == -1 || disp[c][x] != disp[u][x]) {
					u = c; 
				} else {
					disp[u][x] = disp[u][x]*2;
					*score += disp[u][x];                   
					disp[c][x] = 0; 
					u = -1;
				}
			}
			c++;
		}
		// move all non zeros down
		c = 0;
		for (int y = 0; y < LENGTH; y++){
			if (disp[y][x] != 0)
				disp[c++][x] = disp[y][x];
		}
		while (c < LENGTH) {
			disp[c++][x] = 0;
		}       
	}
}

void shiftDown(int disp[LENGTH][WIDTH], int* score) {
	int c;
	int d;
	for (int x = 0; x < WIDTH; x++){
		//merge all pairs
		c = LENGTH - 1;
		d = -1;
		while(c >= 0) {
			if (disp[c][x] != 0) {
				if (d == -1 || disp[c][x] != disp[d][x]) {
					d = c; 
				} else {
					disp[d][x] = disp[d][x]*2;
					*score += disp[d][x];
					disp[c][x] = 0; 
					d = -1;
				}
			}
			c--;
		}
		// move all non zeros down
		c = LENGTH;
		for (int y = LENGTH; y >= 0; y--){
			if (disp[y][x] != 0)
				disp[c--][x] = disp[y][x];
		}
		while (c >= 0) {
			disp[c--][x] = 0;
		}       
	}
}
