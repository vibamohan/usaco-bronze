/*

Average Height
[ Memory: 64 MB, CPU: 1 sec ]

Farmer John is measuring the heights of all his N (N <= 100) cows, where cow i has height h_i (h_i <= 1000). For each pair i, j (1 <= i <= j <= N), the average height is defined as the average height of cow i, i + 1 … j. A pair is good, if there exists a cow x (i <= x <= j) such that h_x is equal to the average height. Farmer John wants to find out how many good pairs there are.

INPUT FORMAT

The first line contains N, the number of cows. The next line contains N numbers, h_1, h_2 … h_n, the height of the cows.

OUTPUT FORMAT

Print the number of good pairs.

SAMPLE INPUT:

4
1 1 2 3
SAMPLE OUTPUT:

6

*/



#include <iostream>
#include <vector>
#include <unordered_set>

using ll = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n_cows;
    std::cin >> n_cows;
    std::vector<int> cows(n_cows);
    for (int i = 0; i < n_cows; i++) {
        std::cin >> cows[i];
    }

    int good_pairs = 0;
    for (int left = 0; left < n_cows; left++) {
        ll sum_so_far = 0;
        std::unordered_set<int> seen_so_far;
        for (int right = left; right < n_cows; right++) {
            sum_so_far += cows[right];
            seen_so_far.emplace(cows[right]);
            int length = right - left + 1;
            if (sum_so_far % length != 0) continue;
            int avg = (int)(sum_so_far / length);
            if (seen_so_far.count(avg) > 0) {
                good_pairs++;
            }
        }
    }

    std::cout << good_pairs << "\n";
    return 0;
}
