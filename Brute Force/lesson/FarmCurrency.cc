/*

Farm Currency
[ Memory: 16 MB, CPU: 1 sec ]

Farmer John has surveyed his customers and the maximum number of Moonies they are willing to pay for his hay bales is M (1 <= M <= 1000). Unfortunately, the Moonies currency only comes in two denominations: a coin worth X Moonies and a coin with Y Moonies. To reduce administrative overhead, Farmer John wants his customers to be able to pay the price of a hay bale without requiring change.

Farmer John realizes that he may or may not be able to charge a price of M Moonies and has asked you to complete the following task: determine the maximum amount of Moonies that he can charge for a bale of hay such that his customers can pay the exact price using only coins with values X and Y.

You may assume that each customer has access to an unlimited amount of each type of coin, but do not have access to any other denominations. Your answer should be some integer less than or equal to M, the maximum amount customers are willing to pay.

INPUT FORMAT:

Line 1: Three integers: X, Y, M

OUTPUT FORMAT:

Line 1: The maximum price less than or equal to M that FJ can charge.

SAMPLE INPUT:

13 24 51
SAMPLE OUTPUT:

50
In this example, Farmer John can charge a price of 50 which can be paid using 2 copies of the coin with value 13 and 1 copy of the coin with value 24.

*/


#include <vector>
#include <iostream>

using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int x, y, m;
    std::cin >> x >> y >> m;
    
    int cost = 1;
    for (cost = m; cost >= 1; cost--) {
        
        bool ok = false;
        for (int x_coins = 0; x_coins * x <= cost; x_coins++) {
            int remaining = cost - x_coins * x;
            if (remaining % y == 0) {
                ok = true;
                break;
            }
        }
        
        if (ok) break;
    }
    
    std::cout << cost << std::endl;
    return 0;
}