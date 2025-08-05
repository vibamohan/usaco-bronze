/*
Working Time
[ Memory: 16 MB, CPU: 1 sec ]

Oh no, Bessie received a speeding ticket again! This time, Farmer John is determined to teach her a lesson.

Farmer John has arranged N (1 <= N <= 100) farm tasks for Bessie to do over the weekend (no more partying for her). Bessie starts doing tasks at time 0. Each task will take her exactly B_i (1 <= B_i <= 100) minutes to complete. Bessie must complete each task in order, with no breaks in between. She now wonders which task she will be performing at time T_i. Help her answer Q (1 <= Q <= 1,000) questions in this form.

INPUT FORMAT

Line 1: The first line contains integers N and Q. 
Line 2...N+1: Line i+1 contains a single integer B_i
Line N+2…N+Q+1: Line N+i+1 contains a single integer  T_i
OUTPUT FORMAT

* Line 1...Q: Line i contains a single integer representing the task Bessie will be performing at time T_i.

SAMPLE INPUT

3 5
3
2
4
0
4
2
7
6
SAMPLE OUTPUT

1
2
1
3
3
As per the chart below:

Task     1   1   1   2   2   3   3   3   3
       +---+---+---+---+---+---+---+---+---+
TIME     0   1   2   3   4   5   6   7   8
*/

#include <vector>
#include <string> 
#include <iostream>

using ll = long long;

int main() {
    int n_tasks, q_queries;
    std::cin >> n_tasks >> q_queries;
    
    std::vector<int> task_by_time;
    for (int task_num = 1; task_num <= n_tasks; task_num++) {
        int task_len; std::cin >> task_len;
        for (int i = 0; i < task_len; i++) {
            task_by_time.push_back(task_num);
        }
    }
    
    for (int query_num = 0; query_num < q_queries; query_num++) {
        int timestamp; std::cin >> timestamp;
        std::cout << task_by_time[timestamp] << std::endl;
    }
    
    return 0;
}