
/*

Squaredle
[ Memory: 64 MB, CPU: 1 sec ]

Bessie may have played Wordle before, but now everyone has moved on to Squaredle!

In Squaredle, instead of a 5 letter word, you are given a 3 by 3 grid to try to guess. Each spot on the grid can only contain the letters A-Z, so there are 26 possible choices for each grid.

When guessing, Bessie will also input a 3 by 3 grid, and each spot can only have a capital letter inside, then gives it to Farmer John. Farmer John, knowing the real grid, will grade Bessie’s guess with two numbers. The first number is going to be the amount of squares on the guessed grid that match up directly with the real grid, and the second number is the amount of squares on the guessed grid that could be rearranged with some other incorrect square in order to be correct. In other words, how many squares have a letter that is missing from the answer but inside the guessed grid.
The latter number can be used to discern how many squares of one letter there are. For example, if there are 0 correct squares and 3 “correct letters but incorrectly positioned” squares in the guess grid, and the guess is

BBB
AAA
AAA
Then you know that there are at most 3 A’s because otherwise there would be more A’s that count for the second number. To be specific, the number of “correct letter but incorrectly positioned” squares for a certain letter should never exceed the number of occurrences of that letter in the first guess.

Farmer John now tasks you with writing a program that will grade one of Bessie’s guesses.

INPUT FORMAT:

The first 3 lines of input give the grid representing the correct answer. The next 3 lines of input represent a guess of this answer.

OUTPUT FORMAT:

Two lines: the first line should contain the number of squares that match up directly, and the second line should contain the number of squares that can be rearranged with some other incorrect square in order to be correct.

SAMPLE INPUT:

DDD
CCC
BBB
DXX
DDD
ZZZ
SAMPLE OUTPUT:

1
2
Only the first D in the first line is correct. And for the second number only two D’s in the second line can be rearranged because there are only 2 incorrect D’s to begin with, so the answer is 2.
 */

import java.util.*;

public class Squaredle {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		char[][] guess  = new char[3][3];
		char[][] answer = new char[3][3];
		
		for (int i = 0; i < 3; i++)
		    guess[i] = scanner.next().toCharArray();
		
		for (int i = 0; i < 3; i++)
		    answer[i] = scanner.next().toCharArray();
		
		// Count correct in-place matches
		int correctMatches = 0;
		Map<Character, Integer> answerOccurences = new HashMap<>();
		Map<Character, Integer>  guessOccurences = new HashMap<>();
		for (int i = 0; i < 3; i++) {
		    for (int j = 0; j < 3; j++) {
		        if (guess[i][j] == answer[i][j]) {
		            correctMatches++; 
		        } else {
		            answerOccurences.put(answer[i][j], 
		                answerOccurences.getOrDefault(answer[i][j], 0) + 1);
		            guessOccurences.put(guess[i][j], 
		                guessOccurences.getOrDefault(guess[i][j], 0) + 1);
		        }
		    }
		}
		
		int wrongPlace = 0;
		// Count wrong place - correct letter 
		for (char letter : guessOccurences.keySet()) {
		    if (answerOccurences.containsKey(letter)) {
		        wrongPlace += Math.min(answerOccurences.get(letter), 
		                               guessOccurences.get(letter));
		    }
		}
		
		System.out.println(correctMatches);
		System.out.println(wrongPlace);
    } 
}

