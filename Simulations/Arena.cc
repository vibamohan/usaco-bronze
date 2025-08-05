/*

Arena
[ Memory: 16 MB, CPU: 1 sec ]

Josh, a fan of modern architecture, has constructed a new arena in the shape of a perfect circle. The arena's interior consists of a ring of n rooms, numbered 1...n clockwise around the perimeter of the arena (3 <= n <= 1,000). Each room has doors to its two adjacent rooms as well as a door to the arena's exterior. 

Josh wants exactly r_i people to end up in each room i  (1 <= r_i <= 100). He intends to unlock the exterior door of a single room, allowing people to enter through that door, in order to allow people into the arena in an orderly fashion. Each person then walks clockwise  through the rooms until they reach a suitable destination. Josh wants to unlock the exterior door, which will require everyone to walk a minimum total distance. Please determine the minimum total distance people will need to walk, if Josh chooses the best such door to unlock. The distance walked by one person is the number of interior doors through which they pass. 

INPUT FORMAT

The first line of input contains n. Each of the remaining n lines contain r_1...r_n.

OUTPUT FORMAT

Please write out the minimum total amount of distance the people collectively need to travel.

SAMPLE INPUT

5 
8 
9 
1 
2 
3 
SAMPLE OUTPUT

29
In this example, Josh will let people enter the arena through the door of the room that requires 8 people.

*/



#include <iostream>
#include <vector>
#include <limits>

int main() {
    int num_rooms; std::cin >> num_rooms;
    std::vector<int> people_requested(num_rooms);
    for (int i = 0; i < num_rooms; i++) {
        std::cin >> people_requested[i];
    }
    
    int min_distance_traveled = std::numeric_limits<int>::max();
    for (int room = 0; room < num_rooms; room++) {
        int cur_dist = 0;
        for (int next_room = 0; next_room < num_rooms; next_room++) {
            cur_dist += people_requested[(room + next_room) % num_rooms] * next_room;
        }
        min_distance_traveled = std::min(cur_dist, min_distance_traveled);
    }
    
    std::cout << min_distance_traveled;
}
