/*


Three Card Monte
[ Memory: 64 MB, CPU: 1 sec ]

Bessie the cow has taken up magic as a hobby and one of her favorite games to play is three-card monte. In the game there are three face down cards lined up in positions 1, 2, and 3. The face of one of these cards is marked with a unique symbol. It is unknown which position contains the marked card.

On each turn Bessie will select two of the three cards and swap their positions. Following Bessie’s turn, another player, Elsie, will guess the location of the marked card. The game continues for N (1 <= N <= 100) turns and the location of the marked card remains unknown to Elsie throughout the entirety of the game (including the start).

Elsie’s score at the end of the game is the total number of correct guesses she made throughout the game. Given a record of the N turns, determine the maximum possible score Elsie could have achieved.

INPUT FORMAT:

Line 1: One integer: N, the number of turns
Line 2…N+1: Three integers: the first two integers are the position of the two cards Bessie swaps on her turn and the third integer is the position that Elsie guesses after Bessie swaps. Each integer will be either 1, 2, or 3 and the first two integers will never be equal. 

OUTPUT FORMAT:

Line 1: The maximum score Elsie could have achieved.

SAMPLE INPUT:

4
1 2 1
1 3 1
3 2 3
1 2 2
SAMPLE OUTPUT:

2
In this example, Elsie’s score is maximized if the marked card starts at position 3. After the first turn, the marked card will remain in position 3, and Elsie’s score will be 0. After the second turn, the marked card will go to position 1, and Elsie’s score will be 1. After the third turn, the marked card will remain in position 1, and Elsie’s score will be 1. After the final turn, the marked card will go to position 2, and Elsie’s score will be 2.

*/


#include <vector> 
#include <iostream>

using ll = long long;

int main() {
    int turns; std::cin >> turns;
    std::vector<std::vector<int>> turn_report;
    
    for (int i = 0; i < turns; i++) {
        int f, t, g; std::cin >> f >> t >> g;
        turn_report.push_back({f, t, g});
    }
    
    int opt_score = 0;
    for (int start_loc : {1, 2, 3}) {
        int cur_score = 0;
        int now_loc = start_loc;
        for (std::vector<int> turn : turn_report) {
            int swap_from = turn[0];
            int swap_to = turn[1];
            int guess = turn[2];
            
            if (swap_from == now_loc) {
                now_loc = swap_to;
            } else if (swap_to == now_loc) {
                now_loc = swap_from;
            }
            
            if (now_loc == guess) {
                cur_score++;
            }
        }
        opt_score = std::max(opt_score, cur_score);
    }
    
    std::cout << opt_score << std::endl;
}