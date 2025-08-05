/*


Discow
[ Memory: 16 MB, CPU: 1 sec ]

The cows in Farmer John’s farm have developed a new game called Discow. In Discow, 26 pairs of cows, labeled A through Z, stand in a circle and throw a frisbee in a straight line back and forth to each other, with the two cows labelled A passing to each other, the two cows labeled B passing to each other, and so and so forth. However, sometimes, two frisbees can collide when being thrown, which only happens if the paths of the two frisbees intersect. Given an arrangement of cows, determine how many pairs of frisbees could collide when thrown.

INPUT FORMAT

A single string with 52 upper-case characters, with each letter A…Z showing up twice, listing the cows in the circle in clockwise order.

OUTPUT FORMAT

The number of pairs of frisbees that could collide with each other.

SAMPLE INPUT

AABBCDEEFFGGYHHIIJJKKLLCMMXNNOOPPQQRRSDSTTUUVVWWXYZZ
SAMPLE OUTPUT

5
Frisbees C and D, C and Y, D and X, D and Y, and D and S could collide.

*/

// Overall logic is to find the pairs that overlap with one another

#include <vector>
#include <iostream>
#include <map>

using ll = long long; 

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    std::string circle; std::cin >> circle;
    int num_collisions = 0;
    std::vector<std::pair<int, int>> chords;
    
    std::map<char, int> sofar;

    for (int i = 0; i < circle.size(); ++i) {
        char ch = circle[i];
        if (sofar.count(ch)) {
            int first = sofar[ch];
            chords.emplace_back(first, i);
        } else {
            sofar[ch] = i;
        }
    }
    
    int count = 0;
    int n = chords.size();
    for (int i = 0; i < n; i++) {
        int a1 = chords[i].first;
        int a2 = chords[i].second;
        for (int j = i + 1; j < n; j++) {
            int b1 = chords[j].first;
            int b2 = chords[j].second;

            if ((a1 < b1 && b1 < a2 && b2 > a2) ||
                (b1 < a1 && a1 < b2 && a2 > b2)) {
                count++;
            }
        }
    }
    
    std::cout << count;
}