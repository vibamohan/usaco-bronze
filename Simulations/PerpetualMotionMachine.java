/*

Perpetual Motion Machine
[ Memory: 64 MB, CPU: 1 sec ]

Farmer John is determined to build a perpetual motion machine. Currently his machine consists of three large containers which store and transfer water. Each container will have a capacity of C_i liters and will start with an initial W_i liters of water (1 <= W_i <= C_i <= 1,000,000,000). 

The machine works by transferring water from container 1 to container 2, then container 2 to container 3, then container 3 to container 1, and so on in a continuous cycle. This cycle will continue for 100 transfers until Farmer John’s machine inevitably breaks down. When FJ transfers water from container A to container B, he transfers the water in container A into container B until one of the following events occurs:

Container A runs out of water
Container B fills with water entirely.
Determine how much water will be in each container at the end of 100 transfers.

INPUT FORMAT:

Line 1: Two integers: The capacity and contents of the first container C_1, W_1
Line 2: Two integers: The capacity and contents of the second container C_2, W_2
Line 3: Two integers: The capacity and contents of the third container C_3, W_3

OUTPUT FORMAT:

Line 1: The final contents of the first container after 100 transfers
Line 2: The final contents of the second container after 100 transfers
Line 3: The final contents of the third container after 100 transfers

SAMPLE INPUT:

4 4
5 3
8 4
SAMPLE OUTPUT:

0
5
6
Explanation: The amount of water in each container can be determined as follows

Initial state: 4 3 4
Transfer 1->2: 2 5 4
Transfer 2->3: 2 1 8
Transfer 3->1: 4 1 6
Transfer 1->2: 0 5 6
Transfer 2->3: 0 3 8
Transfer 3->1: 4 3 4
And then the cycle repeats until the 100th transfer.     
*/

import java.util.Scanner;

public class PerpetualMotionMachine {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] capacities = new int[3];
        int[] amts = new int[3];
        
        for (int i = 0; i < 3; i++) {
            int ci = scanner.nextInt();
            int wi = scanner.nextInt();
            capacities[i] = ci;
            amts[i] = wi;
        }
        
        for (int transfers = 0; transfers < 100; transfers++) {
			int b1 = transfers%3;
			int b2 = (transfers+1)%3;
			int amt = Math.min(amts[b1],capacities[b2]-amts[b2]);
			amts[b1] -= amt;
			amts[b2] += amt;
		}
		
		for (int i = 0; i < 3; i++) {
			System.out.println(amts[i]);
		}
    }
}