#include <stdio.h>
int main() {
    int size;
    int totalNumbers;
    int row, col;
    int currentNumber;
    int nextRow, nextCol;
    int r, c;
    printf("Enter the size of the magic square (odd positive integer): ");
    scanf("%d", &size);

    if (size <= 0 || size % 2 == 0) {
        printf("Error: Size must be an odd positive integer.\n");
        return 1;
    }
    totalNumbers = size * size;
    row = 1;
    col = (size + 1) / 2;
    int grid[size][size];
    for (r = 0; r < size; r++) {
        for (c = 0; c < size; c++) {
            grid[r][c] = 0;
        }
    }
    for (currentNumber = 1; currentNumber <= totalNumbers; currentNumber++) {
        grid[row - 1][col - 1] = currentNumber;
        nextRow = row - 1;
        nextCol = col + 1;
        if (nextRow < 1) nextRow = size;
        if (nextCol > size) nextCol = 1;
        if (grid[nextRow - 1][nextCol - 1] != 0) {
            nextRow = row + 1;
            nextCol = col;
        }
        row = nextRow;
        col = nextCol;
    }
    printf("\nMagic Square of size %d:\n\n", size);
    for (r = 0; r < size; r++) {
        for (c = 0; c < size; c++) {
            printf("%4d", grid[r][c]);
        }
        printf("\n");
    }
    printf("\nMagic square generation complete.\n");
    return 0;
}
