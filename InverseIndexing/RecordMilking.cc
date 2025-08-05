/*

LANGUAGE: multi-language
Record Milking
[ Memory: 16 MB, CPU: 1 sec ]

The cows on Farmer John’s farm are competing to see who can produce milk at the fastest rate in their 100-minute milking sessions. For some reason, the rate at which cows produce milk can change significantly during various parts of their milking sessions. Bessie wants to compare her milking session to the current milking record holder. Bessie’s milking session can be divided into M positive integer length intervals that add up to 100, each with a milking rate between 1 and 100. Similarly, the record holder’s milking session can be divided into N intervals. Determine the maximum amount in which Bessie’s milking rate is over the record holder’s milking rate at one particular moment.

INPUT FORMAT

The first line of the input contains two space separated integers N and M. The next N lines each contain two space separated integers describing an interval of the milking session for the record holder, with the first integer denoting the length of the interval and the second denoting the milking rate in that interval. The next M lines each contain two space separated integers describing an interval of Bessie’s milking, with the first integer denoting the length of the interval and the second denoting the milking rate in that interval.

OUTPUT FORMAT

A single integer denoting the maximum amount that Bessie’s milking rate is over the record holder’s milking rate at one particular moment. If Bessie’s milking rate is never greater than the record holder’s, output 0.

SAMPLE INPUT

3 4
40 50
30 60
30 35
20 70
30 40
40 60
10 40
SAMPLE OUTPUT

25
The record holder’s milking session had 3 intervals: a milking rate of 50 for 40 minutes, followed by a milking rate of 60 for 30 minutes, followed by a milking rate of 35 for 30 minutes. Bessie’s milking session had 4 intervals: a milking rate of 70 for 20 minutes, a milking rate of 40 for 30 minutes, a milking rate of 60 for 40 minutes, and lastly a milking rate of 40 for 10 minutes.
*/

#include <iostream>
#include <vector> 
#include <limits>
#include <cmath>

using ll = long long;

int main() {
    int record_intervals, bessie_intervals;
    std::cin >> record_intervals >> bessie_intervals;
    
    std::vector<int> record_rates(100);
    std::vector<int> bessie_rates(100);
    
    int last_end = 0;
    for (int i = 0; i < record_intervals; i++) {
        int length, milking_rate; 
        std::cin >> length >> milking_rate;
        std::fill(record_rates.begin() + last_end, 
                  record_rates.begin() + last_end + length, 
                  milking_rate);
        last_end += length;
    }
    
    last_end = 0;
    for (int i = 0; i < bessie_intervals; i++) {
        int length, milking_rate; 
        std::cin >> length >> milking_rate;
        std::fill(bessie_rates.begin() + last_end, 
                  bessie_rates.begin() + last_end + length, 
                  milking_rate);
        last_end += length;
    }
    
    int max_exceed = 0;
    for (int i = 0; i <= 100; i++) {
        max_exceed = std::max(bessie_rates[i] - record_rates[i], max_exceed);
    }
    
    std::cout << max_exceed;
}