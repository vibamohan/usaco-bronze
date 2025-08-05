/*

The Spy
[ Memory: 16 MB, CPU: 1 sec ]

Farmer John is trying to spy on his greatest competitor: Farmer Nhoj. He has noticed that Farmer Nhoj is frequently sending exactly 10 bits of information to the dreaded Farming Commission. To work out Farmer Nhoj's evil plan, Farmer John has hired Bessie the Cow as a spy. Her job is to read Farmer Nhoj's 10 bit message and report it back to Farmer John.

Sadly, Bessie the Cow recently received a cowcussion while participating in the USA Cow Skiing Olympiad. As a result, Bessie can only remember a single bit of information and its position each time she reads Farmer Nhoj's message. To avoid disappointing Farmer John, Bessie decides to analyze her data to work out a pattern. She wants to report back the total number of times each bit flipped in her data:

A bit flip is a bit recorded at 0 later appearing as 1 or vice versa
A single bit may flip multiple times in the data
Unfortunately, due to her injury, Bessie the Cow is in no state to program. She has asked her closest friend, you, to help her analyze the data.

INPUT FORMAT:

Line 1: one integer: the number of bits recorded in Bessie's log
Line 2...N+1: two integers: the position of a bit and its current state (0 or 1)
OUTPUT FORMAT:

Line 1: one integer: total number of bits flipped
SAMPLE INPUT:

9
1 0
2 1
3 1
10 0
1 1
1 0
2 0
3 1
2 0
SAMPLE OUTPUT:

3
Bit 1 flips 2 times (it starts at 0, then goes to 1, then goes back to 0). Bit 2 flips 1 time (it starts at 1, then goes to 0). No other bits flip. Observe that while Bit 3 appears twice in the data, its value is 1 both times.

MODE: normal

*/

#include <vector>
#include <string> 
#include <iostream> 

using ll = long long;

int main() {
    int n; std::cin >> n;
    int flips = 0;
    std::vector<int> data_state(10, 3);
    
    for (int i = 0; i < n; i++) {
        int pos, num;
        std::cin >> pos >> num;
        
        if (data_state[pos - 1] != 3 && data_state[pos - 1] != num) {
            flips++;
        }
        
        data_state[pos - 1] = num;
    }
    
    std::cout << flips << std::endl;
}