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
        return 1;}

    int grid[size][size];
    for (r = 0; r < size; r++) {
        for (c = 0; c < size; c++) {
            grid[r][c] = 0;}} ///grid 3*3

    totalNumbers = size * size;
    row = 1;
    col = 2;
    for (currentNumber = 1; currentNumber <= totalNumbers; currentNumber++) {
        grid[row - 1][col - 1] = currentNumber;///grid[0][1]=1

        nextRow = row - 1;///row=1, col=2,nextRow=0
        nextCol = col + 1;///row=1, col=2,nextRow=0 ,nextCol=3
        if (nextRow < 1) nextRow = size;///row=1, col=2, (nextRow=3) ,nextCol=3
        if (nextCol > size) nextCol = 1;

        if (grid[nextRow - 1][nextCol - 1] != 0) {///g[2][2]!=0
            //row++
            nextRow = row + 1;///row=1, col=2,nextRow=2 ,nextCol=3
            nextCol = col;///row=1, col=2,nextRow=2 ,nextCol=2
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
