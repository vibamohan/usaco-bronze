/*


Cow Vacation
[ Memory: 16 MB, CPU: 1 sec ]

Farmer John is always on the lookout for new revenue streams. Recently, he booked an amazing vacation package with N (1 <= N <= 1,000) spots for his M (1 <= M <= 1,000) cows. Rather than letting the cows go for free, Farmer John has set up an auction where each cow tells FJ how much she is willing to pay P_i (1 <= P_i <= 1,000,000) for a spot on the vacation.

To reduce potential conflicts on the farm, Farmer John has decided that he will charge a fixed price for the vacation spots. He will sell a spot for this fixed price to each cow willing to pay at least his price (until he runs out of spots). Determine the smallest price Farmer John can set to maximize the amount of money he earns.

INPUT FORMAT:

Line 1: Two integers: N, M
Lines 2…M+1: One integer: The prices P_i that each cow is willing to pay.

OUTPUT FORMAT:

Line 1: The minimum price Farmer John can charge that maximizes his revenue

SAMPLE INPUT:

3 5
8
3
4
7
3
SAMPLE OUTPUT:

7
In this example, Farmer John should charge a price of $7 (which two cows are willing to pay). This yields a total revenue of $14. While 5 cows are willing to pay a price of $3, the revenue from this price would only be $9 as there are only 3 spots available for the vacation.  

*/

#include <iostream> 
#include <vector>
#include <algorithm>

using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int spots, cows;
    std::cin >> spots >> cows;
    
    std::vector<int> prices(cows);

    for (int i = 0; i < cows; i++) {
        std::cin >> prices[i];
    }
    
    std::sort(prices.begin(), prices.end(), std::greater<int>());
    
    ll optimal_price = -1;
    ll optimal_revenue = -1; 
    
    for (int i = 0; i < cows; i++) {
        int cur_price = prices[i];
        ll cur_revenue = std::min((i + 1), spots) * cur_price;
        
        if (optimal_revenue < cur_revenue) {
            optimal_revenue = cur_revenue;
            optimal_price = cur_price;
        }
    }
    
    std::cout << optimal_price << " " << optimal_revenue;
    
}