/*

Cowphabet Sequence
[ Memory: 64 MB, CPU: 1 sec ]

Cows have a unique way of reciting the alphabet, known as the "cowphabet." This comprises the 26 letters 'a' through 'z', but when a cow recites the cowphabet, the letters follow a distinct order that may differ from the familiar 'abcdefghijklmnopqrstuvwxyz.'

Bessie the cow has been repeatedly reciting the cowphabet to pass time, and Farmer John is keen to discover how many times she has done so.

Given a lowercase string of letters that Farmer John heard Bessie utter, determine the least number of times Bessie must have completed the entire cowphabet for Farmer John to have heard the provided string. Farmer John might not always be attentive to Bessie's recitation, so the string you receive may only include the letters he recalls hearing.

INPUT FORMAT:

The input's first line contains the 26 lowercase letters 'a' through 'z' in the order they appear in the cowphabet. The subsequent line contains the lowercase string of letters that Farmer John heard Bessie utter. This string has a length of at least 1 and no more than 1000.

OUTPUT FORMAT:

Print the minimum number of times Bessie must have recited the entire cowphabet.

SAMPLE INPUT:

bacmefghijklondpqrstuvwxyz
dmyob
SAMPLE OUTPUT:

4
In this example, the cowphabet order differs from the regular alphabet, for instance 'b' comes before 'a'.

Bessie must have recited the cowphabet at least four times. It is feasible for Bessie to have recited the cowphabet only four times, and for Farmer John to have heard the uppercase letters as illustrated below.

bacmefghijklonDpqrstuvwxyz
bacMefghijklondpqrstuvwxYz
bacmefghijklOndpqrstuvwxyz
Bacmefghijklondpqrstuvwxyz
SCORING:

In test cases 2-5, the cowphabet is the same as the regular alphabet.
Test cases 6-10 have no additional constraints.
*/

#include <vector>
#include <iostream>
#include <string> 

using ll = long long;

int main() {
    std::string cowphabet; std::cin >> cowphabet;
    std::string heard; std::cin >> heard;
    int heard_idx = 0;
    int reps = 0;
    
    while (heard_idx < heard.length()) {
        reps++;
        for (char c : cowphabet) {
            if (heard[heard_idx] == c) {
                heard_idx++;
            }
        }
    }
    
    std::cout << reps << std::endl;
    return 0;
}