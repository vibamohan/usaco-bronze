/*


Cownting Detention
[ Memory: 16 MB, CPU: 1 sec ]

Bessie the cow accidentally crashed Farmer John’s brand new tractor into Farmer John’s brand new bar. To give time for Bessie to reflect on her choices, Farmer John has assigned her the following (extremely boring) task: count the number of each digit in every integer from X to Y (1 <= X <= Y <= 2,000,000,000), including Y itself. 

For example, X = 248 and Y = 256, then the sequence would be 248, 249, 250, 251, 252, 253, 254, 255, 256, there would be:

1 zero         8 fives
1 ones         1 six
10 twos        0 sevens
1 three        1 eight
3 fours        1 nine
To ensure that Bessie is able to complete her task, Farmer John has chosen the integers such that Y - X <= 500,000. As a friend to Bessie, your goal is to write a program that completes her task. 

INPUT FORMAT:

Line 1: Two integers: X and Y

OUTPUT FORMAT:

Line 1: Ten space separated integers, each representing the number of occurrences of a digit in the sequence (starting with 0 and ending with 9).

SAMPLE INPUT:

248 256
SAMPLE OUTPUT:

1 1 10 1 3 8 1 0 1 1

*/

#include <vector>
#include <string>
#include <iostream>

using ll = long long;

int main() {
    int start_num, end_num;
    std::cin >> start_num >> end_num;
    std::vector<int> digit_count(10, 0);
    
    for (int i = start_num; i <= end_num; i++) {
        int mutable_num = i;
        while (mutable_num > 0) {
            int cur_digit = mutable_num % 10;
            mutable_num /= 10;
            digit_count[cur_digit] = digit_count[cur_digit] + 1;
        }
    }
    
    for (int i = 0; i < digit_count.size(); i++) {
        int count = digit_count[i];
        std::cout << count << " "[i > 9];
    }
    
    return 0;
}