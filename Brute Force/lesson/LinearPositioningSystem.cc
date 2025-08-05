/*

Linear Positioning System
[ Memory: 32 MB, CPU: 1 sec ]

With the technological revolution in full effect, Farmer John decides to innovate an upgrade to the well-known GPS (Global Positioning System), inventing the LPS (Linear Positioning System). This initial prototype version will only function along a linear street. Rather than relying on satellites and spooky “electromagnetic waves” to locate itself, it will simply use landmarks in its proximity – or more specifically, the first initials of homeowners along the street (Due to budget limitations, this device does not have the memory capacity to hold or use any more information, other than a compass).

Along the street there are 𝑁 identical houses (1≤𝑁≤100). Each house is identified only by the owner’s first initial, an uppercase English letter in the range A..Z. This sequence of initials is represented as a string. Farmer John wants to know the smallest value of 𝐾 such that any sequence of 𝐾 consecutive houses can be uniquely defined by this sequence of initials. This way, Farmer John can calibrate the device to accurately and uniquely determine the location of any user of the Linear Positioning System. He needs your help to find this value for several streets in his neighborhood.

For example, suppose the homeowners of a street have the initials ‘ABABA’. On this street, the LPS cannot be calibrated with 𝐾=3 because there is no distinction between positions 1..3 and 3..5. However, calibrating it with 𝐾=4 is sufficient, because ‘ABAB’ and ‘BABA’ are both distinct. (The LPS does have a built-in compass so it knows the direction of a string of initials).

INPUT FORMAT

Line 1: The integer 𝑁
Line 2: A string of 𝑁 characters, containing only the uppercase English letters A..Z
OUTPUT FORMAT

A single line with the integer 𝐾, the minimum number of consecutive houses to scan in order to uniquely determine the position along the street.

SAMPLE INPUT:

7
ABCDABC
SAMPLE OUTPUT:

4

*/


#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n; std::cin >> n;

    std::string houses;
    houses.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> houses[i];
    }

    int k = 1;
    for (k = 1; k <= n; k++) {
        std::unordered_set<std::string> seen;
        bool ok = true;

        for (int start = 0; start <= n - k; start++) {
            std::string sub = houses.substr(start, k);
            if (seen.count(sub)) {
                ok = false;
                break;
            } else {
                seen.insert(sub);
            }
        }

        if (ok) break;
    }

    std::cout << k << std::endl;
    return 0;
}
