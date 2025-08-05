/*


The Tree
[ Memory: 16 MB, CPU: 1 sec ]

Harry currently has N (1≤𝑁≤100,000) acorns, each with a height of 𝐻𝑖 (1≤𝐻𝑖≤10,000). The total height of all his acorns added together is S. He has found a tree that has a trunk height of B (1≤𝐵≤𝑆≤2,000,000,007). In order for Harry to reach the top of the tree, he has to stack all of his acorns so that their total height is no less than the height of the trunk. Since Harry wants to save as many acorns as possible, calculate the least number of acorns needed for Harry to reach the top of the tree. 

INPUT FORMAT

Line 1: Two integers N and B separated by a space
Lines 2..N+1: Line i +1 is a single integer of 𝐻𝑖

OUTPUT FORMAT

Line 1: A single integer of the fewest number of acorns needed for Harry to reach the top of the tree.

SAMPLE INPUT

5 20
5
6
3
7
11
There are 5 acorns. The tree trunk’s height is 20. The acorns are of height 5, 6, 3, 7, and 11.

SAMPLE OUTPUT

3
The acorns used are 7+11+3 (There may be more than one correct way). 

*/

#include <vector>
#include <algorithm>
#include <iostream> 

using ll = long long;

int main() {
    int n_acorns, b_height;
    std::cin >> n_acorns >> b_height;
    std::vector<int> acorns(n_acorns);
    
    for (int i = 0; i < n_acorns; i++) {
        std::cin >> acorns[i];
    }
    
    std::sort(acorns.begin(), acorns.end(), std::greater<int>());
    
    int cur_height = 0;
    int total_acorns = 0;
    int i = 0;
    while (cur_height < b_height) {
        cur_height += acorns[i++];
        total_acorns++;
    }
    
    std::cout << total_acorns;
}