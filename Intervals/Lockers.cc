/*

Locker Room Reservations
[ Memory: 64 MB, CPU: 1 sec ]

Farmer John's league of athletic cows often do not know where to store their sports equipment during the day. As a result, Farmer John wants to help build a new locker room.

In order to determine how many lockers he needs, he surveys his 𝑁 cows (1≤𝑁≤100), conveniently numbered 1…𝑁. Cow 𝑖 tells Farmer John that he will need to use the locker room from time 𝑠𝑖 to 𝑡𝑖, and will store equipment in 𝑏𝑖 different lockers (1≤𝑠𝑖<𝑡𝑖≤1000, 1≤𝑏𝑖≤10). Conveniently, all 𝑠𝑖 and 𝑡𝑖 values are distinct. When a cow puts her equipment in the locker room, she chooses the lowest numbered 𝑏𝑖 vacant lockers and stores her equipment there (these do not have to be consecutive). If there are not enough lockers, the cow will need to store her equipment out in the lawn, which will be bad. When she is done using the lockers, she leaves with all of her equipment, and another cow can use the now vacant lockers.

Help Farmer John determine the minimum number of lockers in the locker room so that no cow needs to store her equipment on the lawn.

INPUT FORMAT

Line 1: The single integer 𝑁
Lines 2..N+1: Line 𝑖+1 contains three space-separated integers 𝑠𝑖, 𝑡𝑖, and 𝑏𝑖, describing the survey result of cow 𝑖
OUTPUT FORMAT

Print a single integer, the answer to the problem.

SAMPLE INPUT

4
5 7 1
3 10 2
1 4 1
8 12 3
SAMPLE OUTPUT

5
OUTPUT DETAILS

Farmer John needs 5 lockers. At times 1-4, cow 3 uses locker 1. At times 3-10, cow 2 uses lockers 2 and 3. At times 5-7 cow 1 uses locker 1. At times 8-12, cow 4 uses lockers 1, 4, and 5.
*/

#include <iostream>
#include <vector> 

int main() {
    std::vector<int> timestamps(1001);
    int n; std::cin >> n;
    int max_usage = -1;
    
    for (int i = 0; i < n; i++) {
        int start_time; std::cin >> start_time;
        int end_time; std::cin >> end_time;
        int num_spots; std::cin >> num_spots;
        
        for (int t = start_time; t <= end_time; t++) {
            timestamps[t] += num_spots;
            
            max_usage = std::max(timestamps[t], max_usage);
        }
    }
    
    std::cout << max_usage << std::endl;
}
