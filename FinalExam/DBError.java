/*

Database Error
[ Memory: 64 MB, CPU: 2 sec ]

Farmer John has been storing a ranking of his N (2 <= N <= 100) cows labeled from 1 to N on his old farm computer. The ith cow in the ranking has the label Ai. Every cow appears in the ranking exactly once. Unfortunately, when Farmer John went to retrieve the rankings, he found they had been corrupted!

Instead of storing the N values Ai, the database is now storing N-1 values Bi where Bi = Ai + Ai+1 for i from 1 to N-1. Bessie recognizes that it might be possible to recover the original values from the sequence B1,...,BN-1. However, she also recognizes there may be multiple solutions. Hoping to increase her own ranking, Bessie recommends that Farmer John chooses the lexicographically smallest ranking A1,...,AN which could have produced the observed sequence B1,...,BN-1.

A ranking X = (X1,...,XN) is lexicographically smaller than a ranking Y = (Y1,...,YN) there exists a value j such that Xj < Yj and Xi = Yi for all i < j. In other words, the first value of Xi that differs from Yi must be smaller. It is guaranteed that at least one valid ranking exists.

SCORING:

Test cases 1-4: N <= 8
Test cases 5-10: no additional constraints
INPUT FORMAT:

Line 1: A single integer: N
Line 2: N-1 space separated integers: B1, ..., BN-1
OUTPUT FORMAT:

N space separated integers: A1,...,AN

SAMPLE INPUT:

5
6 8 5 6
SAMPLE OUTPUT:

1 5 3 2 4
We can see the ranking A produces B as 1+5=6, 5+3=8, 3+2=5, 2+4=6.
 */

import java.util.*;

public class DBError {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        final int n = scanner.nextInt();
        
        int[] arr = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            arr[i] = scanner.nextInt();
        }
        
        List<Integer> construction = new ArrayList<>();
        Set<Integer> used = new HashSet<>();
        for (int start = 1; start <= n; start++) {
            construction = new ArrayList<>();
            used = new HashSet<>();
            
            if (((arr[0] - start) <= 0)) {
                break;
            } else if ((start == (arr[0] - start))) {
                continue;
            }
            
            construction.add(start);
            construction.add(arr[0] - start);
            used.add(start);
            used.add(arr[0] - start);
            
            boolean ok = true;
            for (int i = 1; i < n - 1; i++) {
                int newAddition = arr[i] - construction.get(construction.size() - 1);
                if (newAddition <= 0 || used.contains(newAddition)) {
                    ok = false;
                    break;
                }
                
                construction.add(newAddition);
                used.add(newAddition);
            }
            
            if (ok) break;
        }
        
        for (int i : construction) {
            System.out.print(i + " ");
        }
    }
}