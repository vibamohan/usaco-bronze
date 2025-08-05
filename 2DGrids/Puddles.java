/*
 
LANGUAGE: multi-language
Puddles
[ Memory: 16 MB, CPU: 1 sec ]

It has rained for the past two days, and Bessie notices that the rain has formed some puddles on Farmer John’s field, which has R (1 <= R <= 100) rows and C (1 <= C <= 100) columns. She wants to count the number of puddles in the field.

Since it has not been raining very long, the puddles can be shown on a diagram of the field as either one ‘#’ symbol or two adjacent ‘#’ symbols (not including diagonals). All parts of the field with no puddles are shown as a ‘.’ symbol. Using a diagram of the field, help Bessie determine the number of puddles in the field.

For example, Bessie has this diagram of a field with R = 6 rows and C = 8 columns:

......#.
.#...#..
.#.....#
...##..#
#.......
.#..#.##
This field has a total of 9 puddles as shown below: one on the row 1 column 7, one on rows 2 and 3 of column 2, one on row 2 column 6, one on rows 3 and 4 of column 8, one on row 4 columns 4 and 5, one on row 5 column 1, one on row 6 column 2, one on row 6 column 5, and one on row 6 columns 7 and 8.

......1.
.2...3..
.2.....4
...55..4
6.......
.7..8.99
INPUT FORMAT

* Line 1: Two space-separated integers: R and C
* Line 2…. R + 1: Line i + 1 has C characters that are either a ‘.’ or a ‘#’, which describe the i th row of the field.

OUTPUT FORMAT

* Line 1: A single integer representing the number of puddles on the field

SAMPLE INPUT

6 8
......#.
.#...#..
.#.....#
...##..#
#.......
.#..#.##
SAMPLE OUTPUT

9

 */

 import java.util.*;

enum Directions {
    UP(-1, 0), DOWN(1, 0),
    LEFT(0, -1), RIGHT(0, 1);
    
    int dx; int dy;
    Directions(int dx, int dy) {
        this.dx = dx;
        this.dy = dy;
    }
}

class Point {
    int x, y;
    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Puddles {
    static boolean isValid(int x, int y, boolean[][] visited, char[][] arr) {
        return (x >= 0 && x < arr.length) &&
               (y >= 0 && y < arr[0].length) &&
               (arr[x][y] == '#') && (!visited[x][y]);
    }
    
    private static void bfs(char[][] arr, int startX, 
                            int startY, boolean[][] visited) {
        Queue<Point> q = new LinkedList<>();
        q.offer(new Point(startX, startY));
        visited[startX][startY] = true;
        
        while (!q.isEmpty()) {
            Point cur = q.poll();
            for (Directions dir : Directions.values()) {
                Point next = new Point(cur.x + dir.dx, 
                                       cur.y + dir.dy);
                if (isValid(next.x, next.y, visited, arr)) {
                    q.offer(next);
                    visited[next.x][next.y] = true;
                }
            }
        }
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int r = scanner.nextInt();
        int c = scanner.nextInt();
        
        char[][] arr = new char[r][c];
        boolean[][] visited = new boolean[r][c]; 
        for (int i = 0; i < r; i++) {
            arr[i] = scanner.next().toCharArray();
        }
        
        int cc = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (arr[i][j] == '#' && !visited[i][j]) {
                    bfs(arr, i, j, visited);
                    cc++;
                }
            }
        }
        
        System.out.println(cc);
    }
}