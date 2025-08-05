/*

Finding X
[ Memory: 64 MB, CPU: 1 sec ]

On the island of cowland, there is a cult of N cows (1 ≤ N ≤ 1000) worshiping a holy number, X. All the cows know the number. Each cow is either a liar or a truth teller, they will either always lie or always tell the truth when asked a question. You are a tourist visiting cowland. You want to find out the value of X. Each cow gives you a hint about X, each hint of the form “L y” or “G y”. In the first, the cow says that X is less than or equal to y and the second, the cow says that X is greater than or equal to y. Count the minimum number of cows that must be liars.

INPUT FORMAT:

The first line contains N.

The next N lines each contain either L or G, followed by an integer pi (0 ≤ pi ≤ 109). L means that the i-th cow says that X is less than or equal to pi, and G means that i th cow says that X is greater than or equal to pi.

OUTPUT FORMAT:

The minimum number of cows that must be liars.

SAMPLE INPUT:

2
G 3
L 4
SAMPLE OUTPUT:

0
It is possible that no cow is lying.

SAMPLE INPUT:

2
G 35
L 15
SAMPLE OUTPUT:

1
At least one of the cows must be lying.
 */

import java.util.*;

class Interval {
    double start; 
    double end;
    
    Interval(char direction, int num) {
        if (direction == 'G') {
            this.start = num;
            this.end = Double.POSITIVE_INFINITY;
        } else {
            this.end = num + 1;
            this.start = 0;
        }
    }
}

public class FindingX {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        
        Interval[] intervals = new Interval[n];
        int max_end = 0;
        TreeMap<Integer, Integer> critical_points = new TreeMap<>();
        
        for (int i = 0; i < n; i++) {
            char dir = scanner.next().charAt(0);
            int point = scanner.nextInt();
            intervals[i] = new Interval(dir, point);
            max_end = Math.max(max_end, point);
            
            critical_points.putIfAbsent(point, 0);
        }
        
        for (Interval cur : intervals) {
            if (cur.end == Double.POSITIVE_INFINITY) {
                cur.end = max_end + 2;
            }

            int s = (int) cur.start;
            int e = (int) cur.end;

            critical_points.put(s, critical_points.getOrDefault(s, 0) + 1);
            critical_points.put(e, critical_points.getOrDefault(e, 0) - 1);
        }

        int max_sum = 0;
        int pref_sum = 0;
        for (Integer key : critical_points.navigableKeySet()) {
            pref_sum += critical_points.get(key);
            max_sum = Math.max(max_sum, pref_sum);
        }

        int min_liars = n - max_sum;
        System.out.println(min_liars);
    }
}
