/*
Confused Farmer
[ Memory: 64 MB, CPU: 1 sec ]

Farmer John has three buckets, each with a certain amount of milk A, B, and C (A ≤ B ≤ C). However, he got confused, and randomly mixed up seven buckets with (not necessarily distinct) milk amounts A, B, C, A + B, B + C, C + A, and A + B + C (in some order) in the range [1, 109].

Given a list of these seven milk amounts, please help Farmer John determine the original amounts of milk that he had before: A, B, and C.

INPUT FORMAT:

The only line of input consists of seven space-separated integers.

OUTPUT FORMAT:

Print A, B, and C separated by spaces.

SAMPLE INPUT:

12 2 10 6 8 6 4
SAMPLE OUTPUT:

2 4 6
SCORING:

Test cases 2 - 3 satisfy C ≤ 50.
Test cases 4 - 10 satisfy no additional constraints.
*/

#include <vector>
#include <string> 
#include <iostream>
#include <algorithm>

using ll = long long;

int main() {
    std::vector<int> nums(7);
    for (int i = 0; i < 7; i++) {
        std::cin >> nums[i];
    }
    
    std::sort(nums.begin(), nums.end());
    int a = nums[0];
    int b = nums[1];
    int abc = nums[nums.size() - 1];
    int c = abc - a - b;
    
    std::cout << a << " " << b << " " << c << std::endl;
}