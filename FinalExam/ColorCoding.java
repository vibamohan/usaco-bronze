/*

Color Coding
[ Memory: 16 MB, CPU: 1 sec ]

Farmer John has N (1 <= N <= 100) black cows and N brown cows. He does not understand why some cows are black and some cows are brown, so he goes to his local university to ask an animal science professor. The professor believes that traits of cows are determined by a single index in their DNA sequence. DNA sequences for cows are M (1 <= M <= 100) character strings composed of the characters A, T, C, and G. Given this information, Farmer John gets the DNA sequences of his cows and tasks himself with determining how many indices could determine their color. 

For example, say Farmer John has 4 black cows and 4 brown cows with the DNA sequences

Positions:   1 2 3 4 5 6 7 8 9 ... M
Black Cow 1: A T T G C G C G T ... A
Black Cow 2: G T A C T G G T G ... C
Black Cow 3: C T G T G G A A A ... T
Black Cow 4: T G A C A G A C G ... G
Brown Cow 1: C A G T C C T A C ... A
Brown Cow 2: A C T G G C T C A ... C
Brown Cow 3: G A C C A T A T G ... G
Brown Cow 4: G C T A A C C C T ... G
Farmer John concludes that indices 2 and 6 could determine the color of his cows. That is, by looking at only index 2, he can conclude that a cow is black if there is a T or a G, and he can conclude that a cow is brown if there is an A or a C. By looking at only index 6, he can conclude that a cow is black if there is a G, and he can conclude that a cow is brown if there is a C or a T. The character A does not appear in any of the cows’ DNA sequences at index 6. If he were to look at index 9, he would not be able to determine what color his cows are, because the characters A, G, and T appear in both black and brown cows.

INPUT FORMAT

The first line contains two space-separated integers N and M. The next N lines contain an M character string representing the DNA sequence of a black cow. The last N lines contain an M character string representing the DNA sequence of a brown cow.

OUTPUT FORMAT

The number of indices in the DNA sequence that could determine the color of the cow. 

SAMPLE INPUT

4 10
ATTGCGCGTA
GTACTGGTGC
CTGTGGAAAT
TGACAGACGG
CAGTCCTACA
ACTGGCTCAC
GACCATATGG
GCTAACCCTG

SAMPLE OUTPUT

2
 */

 import java.util.*;

public class ColorCoding {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int nPerColor = scanner.nextInt();
        int dnaLen = scanner.nextInt();

        List<Set<Character>> blackCows = new ArrayList<>(dnaLen);
        List<Set<Character>> brownCows = new ArrayList<>(dnaLen);

        for (int i = 0; i < dnaLen; i++) {
            blackCows.add(new HashSet<>());
            brownCows.add(new HashSet<>());
        }

        for (int curCowNum = 0; curCowNum < nPerColor; curCowNum++) {
            char[] curLine = scanner.next().toCharArray();
            for (int i = 0; i < curLine.length; i++) {
                blackCows.get(i).add(curLine[i]);
            }
        }

        for (int curCowNum = 0; curCowNum < nPerColor; curCowNum++) {
            char[] curLine = scanner.next().toCharArray();
            for (int i = 0; i < curLine.length; i++) {
                brownCows.get(i).add(curLine[i]);
            }
        }

        int possibleLocations = 0;
        for (int i = 0; i < dnaLen; i++) {
            if (Collections.disjoint(blackCows.get(i), brownCows.get(i))) {
                possibleLocations++;
            }
        }

        System.out.println(possibleLocations);
    }
}
