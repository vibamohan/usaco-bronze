/*

Cow Golf
[ Memory: 16 MB, CPU: 1 sec ]

The seven strangest cows (Bessie, Elsie, Daisy, Gertie, Annabelle, Maggie, and Henrietta) on Farmer John’s farm have collectively decided to take up cow golf as a hobby this summer. The summer is N (1 <= N <= 100) days long and, on each day, a single cow will play a round of cow golf. This cow’s name and score S_i (1 <= S_i <= 100) is recorded in a log.

At the end of the summer, the cows want to know who won their competition. The score of a cow is equal to the cumulative sum of each of their individual daily scores. Unlike normal golf (where the lowest score is best), the winner of cow golf is whomever has the smallest score strictly larger than the minimum score. Given the log of scores, determine who won the competition. If multiple cows won, print “Tie”.

If a cow does not appear in the log, you should assume their score is 0.

INPUT FORMAT:

Line 1: One integer: N
Line 2…N+1: One string and one integer: The name of the cow playing and their score S_i

OUTPUT FORMAT:

Line 1: The name of the cow who won the summer’s competition or the word “Tie” if multiple cows won.

SAMPLE INPUT:

8
Elsie 4
Daisy 17
Bessie 2
Gertie 6
Annabelle 4
Bessie 3
Henrietta 7
Maggie 4
SAMPLE OUTPUT:

Bessie
In this example, Bessie’s final score is 5, which is the smallest score strictly larger than the minimum score of 4.
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue> 
#include <map>

using ll = long long;

int main() {
    int n; std::cin >> n;
    std::map<std::string, int> score_map;
    for (std::string i : {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"}) {
        score_map.emplace(i, 0);
    }
    
    for (int i = 0; i < n; i++) {
        std::string name; int score_earned;
        std::cin >> name >> score_earned;
        score_map.insert_or_assign(name, score_map[name] + score_earned);
    }
    
    std::priority_queue<std::pair<int, std::string>, 
                        std::vector<std::pair<int, std::string>>,  
                        std::greater<std::pair<int, std::string>>> pq;
    for (const auto& [name, score] : score_map) {
            pq.push({score, name});
    }
    
    int min_score = pq.top().first;
    pq.pop();
    while (!pq.empty() && pq.top().first == min_score) {
        pq.pop();
    }
    
    if (n == 2) { std::cout << "Tie" << std::endl; }
    else if (!pq.empty()) { std::cout << pq.top().second << std::endl; } 
    else { std::cout << "Tie" << std::endl; }
    
    return 0;
}