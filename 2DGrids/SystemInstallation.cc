/*

LANGUAGE: multi-language
System Installation
[ Memory: 16 MB, CPU: 1 sec ]

Farmer John wants to install a new sprinkler system on his farm. However, because new sprinkler systems are expensive, Farmer John can only afford to have new sprinklers on part of his farm. To figure out where on his farm he will install the system, he divides his farm up into a grid with NR (3 <= NR <= 100) rows and NC (3 <= NC <= 100) columns, determines the number of cows graze on each square of the grid Prc, and decides to put the new sprinklers on the 3 x 3 grid with the most cows so the grass will grow better on those squares.

Determine the 3 x 3 grid whose squares sum to the greatest number and then output its upper left corner. If multiple grids have the same total, output the grid with the smallest row number. The multiple grids are on the same row, output the grid with the smallest column number.

For example, say Farmer John divides his field into a 6 x 7 grid as follows:


In this example, the largest sum is 61, found in 2 grids: the one on row 1 column 3, and the one on row 2 column 3. Since the first grid has a smaller row number, Farmer John will install the sprinkler system on the grid on row 1 column 3.

INPUT FORMAT

* Line 1: Two space-separated integers NR and NC
* Line 2 … NR + 1: NC space separated integers that depict a row of the grid

OUTPUT FORMAT

* Line 1: A single integer that is the largest total of a 3 x 3 grid.
* Line 2: Two space-separated integers that indicate the row and column of the 3 x 3 grid that Farmer John will install his sprinklers on.


SAMPLE INPUT

6 7
1 2 6 5 7 3 4
2 4 8 7 8 6 6
3 5 7 8 5 4 1
4 6 5 9 4 5 7
3 7 4 3 5 3 2
4 3 2 6 7 8 9
SAMPLE OUTPUT

61
1 3

*/

#include <iostream>
#include <vector>

int main() {
    int nr, nc;
    std::cin >> nr >> nc;
    
    std::vector<std::vector<int>> grid(nr, std::vector<int>(nc));
    for (int r = 0; r < nr; r++) {
        for (int c = 0; c < nc; c++) {
            std::cin >> grid[r][c];
        }
    }

    std::vector<std::vector<int>> prefixs(nr + 1, std::vector<int>(nc + 1));
    for (int r = 1; r <= nr; r++) {
        for (int c = 1; c <= nc; c++) {
            prefixs[r][c] = grid[r-1][c-1] + prefixs[r-1][c] 
                          + prefixs[r][c-1] - prefixs[r-1][c-1];
        }
    }

    int max_sum = -1;
    int mr = 0, mc = 0;

    for (int r = 1; r <= nr - 2; r++) {
        for (int c = 1; c <= nc - 2; c++) {
            int r2 = r + 2;
            int c2 = c + 2;
            int cur = prefixs[r2][c2] - prefixs[r-1][c2] 
                             - prefixs[r2][c-1] + prefixs[r-1][c-1];
            if (cur > max_sum) {
                max_sum = cur;
                mr = r;
                mc = c;
            }
        }
    }

    std::cout << max_sum << std::endl;
    std::cout << mr << " " << mc << std::endl;

    return 0;
}
