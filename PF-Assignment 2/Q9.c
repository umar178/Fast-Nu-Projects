#include <stdio.h>
#include <conio.h>

#define SIZE 5

void displayGrid(char grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void movePlayer(char grid[SIZE][SIZE], int *x, int *y, int dx, int dy, int *itemsCollected) {
    int newX = *x + dx;
    int newY = *y + dy;

    if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE) {
        if (grid[newX][newY] == 'X') {
            printf("Obstacle! Can't move there.\n");
        } else {
            if (grid[newX][newY] == 'I') {
                (*itemsCollected)++;
                printf("Item collected! Total items: %d\n", *itemsCollected);
            }
            grid[*x][*y] = ' ';
            *x = newX;
            *y = newY;
            grid[*x][*y] = 'P';
        }
    } else {
        printf("Out of bounds!\n");
    }
}

int main() {
    char grid[SIZE][SIZE] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };

    int playerX = 4, playerY = 4; 
    int itemsCollected = 0;
    char move;

    while (1) {
        displayGrid(grid);
        printf("Enter move (W=up, S=down, A=left, D=right, Q=quit): ");
        scanf(" %c", &move);

        if (move == 'Q' || move == 'q') {
            printf("Game exited. Total items collected: %d\n", itemsCollected);
            break;
        }

        switch (move) {
            case 'W': case 'w': movePlayer(grid, &playerX, &playerY, -1, 0, &itemsCollected); break;
            case 'S': case 's': movePlayer(grid, &playerX, &playerY, 1, 0, &itemsCollected); break;
            case 'A': case 'a': movePlayer(grid, &playerX, &playerY, 0, -1, &itemsCollected); break;
            case 'D': case 'd': movePlayer(grid, &playerX, &playerY, 0, 1, &itemsCollected); break;
            default: printf("Invalid input!\n");
        }
    }
    return 0;
}
