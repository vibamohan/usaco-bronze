/*
 
LANGUAGE: multi-language
Selection Sort
[ Memory: 16 MB, CPU: 1 sec ]

Use "Selection Sort" algorithm to sort given N <= 100 integers in ascending order.

INPUT FORMAT

The first line of the input contains the number of integers, N. The second line contains N integers separated with one space.

OUTPUT FORMAT

The output contains N lines that contains all the steps in selection sort. The first line is the initial sequence and the last line is the final sequence.

SAMPLE INPUT

10
36 9 2191 66 3 4 -18 876 156 12
SAMPLE OUTPUT

36 9 2191 66 3 4 -18 876 156 12
-18 9 2191 66 3 4 36 876 156 12
-18 3 2191 66 9 4 36 876 156 12
-18 3 4 66 9 2191 36 876 156 12
-18 3 4 9 66 2191 36 876 156 12
-18 3 4 9 12 2191 36 876 156 66
-18 3 4 9 12 36 2191 876 156 66
-18 3 4 9 12 36 66 876 156 2191
-18 3 4 9 12 36 66 156 876 2191
-18 3 4 9 12 36 66 156 876 2191
 */

import java.util.Scanner;
public class selectionsort {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int len = Integer.parseInt(scanner.nextLine());
		String[] tempie = scanner.nextLine().split(" ");
		int[] arr = new int[len];
		for (int i = 0; i < tempie.length; i++) {
			arr[i] = Integer.parseInt(tempie[i]);
		}
		for (int s = 0; s<arr.length; s++) {
			if (s<arr.length-1) {
				System.out.print(arr[s] + " ");
			} else {
				System.out.print(arr[s]);
				System.out.println();
			}
		}
		for (int i = 0; i < len - 1; i++) {
			int min_ind = i;
			int min = arr[min_ind];
			for (int j = i + 1; j < len; j++) {
				if (arr[j] < min) {
					min_ind = j;
					min = arr[j];
				}
			}
			arr[min_ind] = arr[i];
			arr[i] = min;
			for (int s = 0; s<arr.length; s++) {
				if (s<arr.length-1) {
					System.out.print(arr[s] + " ");
				} else {
					System.out.print(arr[s]);
					System.out.println();
				}
			}
		}
	}
}
