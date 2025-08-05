/*

Acorn Shuffle
[ Memory: 16 MB, CPU: 1 sec ]

Harry the squirrel wants to perform a party trick of shuffling his acorns. He wants the other forest animals to guess the acorns’ original positions after the shuffles. He will have N (1 <= N <= 100) acorns and shuffle them 3 times in a row. The initial position of the acorns will be marked as position 1, position 2, position 3...etc. for the first acorn, second acorn, third acorn, etc. up to N. 

When a shuffle is performed, the acorns will be moved from their previous position (i) to the new position (ai). Each i is in range (1...N). All acorns will move to the new position after a shuffle. There are no overlapping new positions. For example, two acorns will not be moved to the same position.

Each acorn has a unique 7-digit ID number. Given the new position of each acorn after 3 shuffles, calculate the acorns’ original position. 

INPUT FORMAT

Line 1: N (number of acorns)
Line 2: N integers of the acorns’ positions (a1, a2,..aN)
Line 3: The acorns’ positions after 3 shuffles have been performed, followed by their ID numbers.

OUTPUT FORMAT

N lines consisting of the acorns’ ID number per line. Each line represents the position of the acorns. For example, the first line is position 1.

SAMPLE INPUT

4
2 3 4 1
6737369 2966167 7234338 8672432
SAMPLE OUTPUT

8672432 
6737369 
2966167 
7234338
The output after each shuffle:

original positions        : 8672432    6737369    2966167    7234338    => expected output
after the first shuffle   : 7234338    8672432    6737369    2966167
after the second shuffle  : 2966167    7234338    8672432    6737369 
after the third shuffle   : 6737369    2966167    7234338    8672432    => the given input  

*/

#include <vector>
#include <iostream>

using ll = long long;

int main() {
    int n; std::cin >> n;
    std::vector<int> after_swap(n);
    std::vector<int> ids(n);
    std::vector<int> ids_before_swap(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> ids_before_swap[i];
        ids_before_swap[i]--;
    }
    
    for (int i = 0; i < n; i++) {
        std::cin >> ids[i];
    }
    
    for (int rep = 1; rep <= 3; rep++) {
        for (int i = 0; i < n; i++) {
             after_swap[i] = ids[ids_before_swap[i]];
        }
        ids = after_swap;
    }
    
    for (int i : after_swap) {
        std::cout << i << std::endl;
    }
    
    return 0;
}