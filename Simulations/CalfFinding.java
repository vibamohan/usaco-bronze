/*
 LANGUAGE: multi-language
 Calf Finding
 [ Memory: 32 MB, CPU: 1 sec ]
 
 Bessie the cow is worried; it is dark outside and her calf is missing! Bessie knows that her calf is on the narrow part of Farmer John’s barn, which can be viewed as a number line. Unfortunately, since it is dark, Bessie does not know where on this number line her calf is, so she has to walk back and forth until she finds her. Bessie decides to employ this strategy to find her calf: starting at position x (0 <= x <= 1000), she will walk right to position x + 1, left to position x - 2, right to position x + 4, left to position x - 8, and so on until she reaches her calf, who is at position y (0 <= y <= 1000). Determine the total distance Bessie will travel until she finds her calf.
 
 INPUT FORMAT
 
 A line containing two distinct space-separated integers, x and y.
 
 OUTPUT FORMAT
 
 A single integer denoting the distance that Bessie will travel to find her calf.
 
 SAMPLE INPUT
 
 10 25
 SAMPLE OUTPUT
 
 45
 */
public class CalfFinding {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int x = scanner.nextInt();
		int y = scanner.nextInt();
		int bessie = x;
		int distance = 1;
		int output = 0;
		for (int i = 0; i<1000; i++) {
			bessie = x + distance;
			
			if (bessie >= y && y>x || bessie<=y && y<x) {
				output += Math.abs(x-y);
				break;
			} 
			
			output+=Math.abs(distance)*2;
			distance = distance*(-2);
		}
		S

import java.util.Scanner;

	}
}
