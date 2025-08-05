/*
Picture Game
[ Memory: 16 MB, CPU: 1 sec ]

Harry is teaching baby bunnies how to read by giving them a set of N (1 <= N <= 100) leaflets. Each leaflet has a word and an image on each side. For example, a leaflet might have the word “bunny” and a picture of a bunny next to it on one side, and the word “squirrel” and a picture of a squirrel on the other side. When the leaflets are layed down,N words are shown, and by flipping the leaflets over, a different set of N words can be seen. 

Harry, determined to help the bunnies with their spelling, decides to make clay blocks, each engraved with a single letter of the alphabet. Harry wants to make enough clay blocks of each letter so that regardless of which set of N words are visible, the bunnies can spell the words out with the clay blocks.

For example, if N = 3 and the words “leaf”, “tree”, and “bird” were facing up, the bunnies would need at least one ‘a’ block, one ‘b’ block, one ‘d’ block, three ‘e’ blocks, one ‘f’ block, one ‘i’ block, one ‘l’ block, two ‘r’ blocks, and one ‘t’ block. . 

Calculate the minimum number of clay blocks for each letter of the alphabet that Harry needs to provide so that the bunnies can spell N visible words.

INPUT FORMAT

Line 1 contains a single integer, N.

The next N lines each contain 2 words separated by a space, indicating the one word on the hidden side and one word on the visible side. Each word is a string of at most 10 lowercase letters. 

OUTPUT FORMAT

Output 26 lines. The ith line should indicate the number of blocks needed for the i th letter of the alphabet, so line 1 should indicate how many ‘a’s are needed, line 2 should indicate how many ‘b’s are needed, and so on and so forth.

SAMPLE INPUT

3
leaf green
root tree
bird fly
SAMPLE OUTPUT

1
1
0
1
4
2
1
0
1
0
0
2
0
1
2
0
0
3
0
1
0
0
0
0
1
0
*/

#include <vector> 
#include <iostream>

using ll = long long; 

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    std::vector<int> char_frequency_count(26);
    
    int n; std::cin >> n;
    
    for (int sc = 0; sc < n; sc++) {
        std::string side_1,  side_2;
        std::cin >> side_1 >> side_2;
        
        std::vector<int> a_count(26);
        std::vector<int> b_count(26);
        
        for (int i = 0; i < side_1.length(); i++) {
            a_count[side_1[i] - 'a']++; 
        }
        
        for (int i = 0; i < side_2.length(); i++) {
            b_count[side_2[i] - 'a']++; 
        }
        
        for (int i = 0; i < 26; i++) {
            char_frequency_count[i] += std::max(a_count[i], b_count[i]);
        }
    }
    
    for (int i = 0; i < 26; i++) {
        std::cout << char_frequency_count[i] << std::endl;
    }
}