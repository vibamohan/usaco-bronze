/*
 Fence Posts
[ Memory: 64 MB, CPU: 1 sec ]

Farmer John is attempting to build a fence with N (2 <= N <= 100) fence posts. He hired an architectural firm to design a post-modern fence concept: a fence whose height increases monotonically (in other words, never decreases) for the entire length of the fence. The firm recently shipped out all N fence posts to Farmer John and he has spent all week setting them up!

As soon as he finished setting up the last fence post, Bessie the Cow pointed out that one of the fence posts was placed in the wrong spot and all but one of the posts were correctly ordered from smallest to tallest!

To finish assembling the fence, Farmer John needs to fix this error. His plan is as follows: he will swap pairs of fence posts one by one until all fence posts are in sorted order. Farmer John may swap any two of the fence posts, but he wants to do the minimum amount of work possible. What is the minimum number of swaps Farmer John needs to make?

INPUT FORMAT:

Line 1: one integer: N, the number of fence posts
Lines 2...N+1: one integer: the height of the ith fence post, as they are currently arranged in Farm John’s field
OUTPUT FORMAT:

One integer: the minimum number of swaps to return the fence posts to sorted order
SAMPLE INPUT:

5
1
3
3
7
2
SAMPLE OUTPUT:

2
The fence post of height 2 is the one out of order. To obtain sorted order, we can use the following sequence of steps:

original order              : 1 3 3 7 2
swap 4th and 5th fence posts: 1 3 3 2 7
swap 2nd and 4th fence posts: 1 2 3 3 7
Total swaps: 2.
 */

 import java.util.*;

public class FencePosts {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        
        int[] sortedArr = arr.clone();
        Arrays.sort(sortedArr);

        int s = 0;
        for (int i = 0; i < n; i++) {
            if (sortedArr[i] != arr[i]) s++;
        }
        
        System.out.println(s - 1);
    }
}