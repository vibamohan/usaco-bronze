/*
Addictive Games
[ Memory: 64 MB, CPU: 1 sec ]

Farmer John’s cows have recently picked up gaming, an addictive habit which Farmer John is desperately trying to prevent.

Farmer John’s barn has 𝑁 separate rooms (2≤𝑁≤105). Due to recent expansions, some of these rooms house cows and others are empty. Realizing that the cows communicate by mooing through the walls, Farmer John wants to maximize the distance between the closest two rooms with cows. For example, if rooms 3 and 5 are the closest rooms with cows, then that distance is 2.

Farmer John recently received two more cows as a gift, and he must figure out where in his barn to place them. However, his current cows have all grown very attached to their current rooms, so Farmer John cannot move them, he can only place the new cows in certain rooms. Help him figure out the maximum distance between the closest two rooms.

INPUT FORMAT

The first line of input contains N. The next line contains a string of length N made of 0s and 1s, with 0 referring to an empty room and 1 representing a room with a cow in it.

OUTPUT FORMAT

Please print the maximum distance between the closest two rooms that can be created.

SAMPLE INPUT

8
10000100
SAMPLE OUTPUT

2
In this example, Farmer John could add cows x and y to the possible positions as 10xx010y that gives the maximum distance.

SCORING:

Test cases 2-6 satisfy N ≤ 10.
Test cases 7-8 satisfy N ≤ 100.
Test cases 9-11 satisfy N ≤ 5000.
Test cases 12-15 satisfy no additional constraints.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool can_place(const std::string &barn, int d) {
    int n = barn.size();
    std::vector<int> cows;

    for (int i = 0; i < n; ++i) {
        if (barn[i] == '1') cows.push_back(i);
    }

    std::vector<bool> occupied(n);
    for (int pos : cows) occupied[pos] = true;

    int placed = 0;
    int last = -1;

    for (int i = 0; i < n; i++) {
        if (barn[i] == '0' && !occupied[i]) {
            bool ok = true;
            if (last != -1 && i - last < d) ok = false;

            auto it = std::lower_bound(cows.begin(), cows.end(), i);
            if (it != cows.end() && std::abs(*it - i) < d) ok = false;
            if (it != cows.begin() && std::abs(*(it - 1) - i) < d) ok = false;

            if (ok) {
                placed++;
                last = i;
                cows.insert(it, i);
                if (placed == 2) return true;
            }
        }
    }

    return false;
}

int main() {
    int n;
    std::cin >> n;
    std::string barn;
    std::cin >> barn;

    int lo = 0, hi = n, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (can_place(barn, mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    std::cout << ans << '\n';
}
