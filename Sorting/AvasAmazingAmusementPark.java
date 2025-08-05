/*
 
Ava’s Amazing Amusement Park
[ Memory: 64 MB, CPU: 2 sec ]

Ava's Amazing Amusement Park is introducing a new annual pass! There are N thrill-seekers (1 ≤ N ≤ 10,000) interested in purchasing the pass, and each is willing to pay a maximum amount C_i (1 ≤ C_i ≤ 1,000,000). Ava wants to set the annual pass price to maximize her revenue. If the price is higher than a thrill-seeker's maximum willingness to pay, they won't buy the pass. What's the optimal price for the annual pass, and what's the total revenue Ava can generate?

Your program should print the maximum revenue and the price which achieves it. If multiple prices achieve the same maximum revenue, print the smallest one. 

INPUT FORMAT:

Line 1: One integer: N
Line 2: N space separated integers: The values C_1, C_2, …, C_N where each C_i is the maximum amount a customer is willing to pay.

OUTPUT FORMAT:

Line 1: Two integers: The maximum revenue and the smallest price which achieves the maximum revenue.

SAMPLE INPUT:

4
1 2 7 4 3
SAMPLE OUTPUT:

9 3
Explanation: If Ava sets the price at 3 dollars, then three customers are willing to buy the annual pass leading to a total revenue of 9 dollars. There is no way for Ava to earn more than 9 dollars.


 */

import java.util.*;

public class AvasAmazingAmusementPark {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] prices = new int[n];
        
        for (int i = 0; i < n; i++) {
            prices[i] = scanner.nextInt();
        }
        
        Arrays.sort(prices);
        
        int optimal_price = -1;
        long optimal_revenue = -1;
        for (int i = 0; i < n; i++) {
            long cur_revenue = (long) prices[i] * (n - i);
            if (optimal_revenue < cur_revenue) {
                optimal_revenue = cur_revenue;
                optimal_price = prices[i];
            }
        }
        
        System.out.println(optimal_revenue + " " + optimal_price);
    }
}