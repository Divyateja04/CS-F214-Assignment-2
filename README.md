# CS-F214-Assignment-2

## Introduction
This repository is for Logic in Computer Science Assignment 2 at BITS Pilani Hyderabad Campus.  
The task is to verify if a proof is correct or not. Given that the proof has:   
1. Premise
2. AND Introduction/Elmination
3. OR Introduction
4. IMPLIES Elimination
5. MT
  
  
## Our Team 
1. Divyateja Pasupuleti- 2021A7PS0075H  
2. Kumarasamy Chelliah- 2021A7PS0096H  
3. Harsh Rachalwar- 2021A7PS0200H  
4. Manan Gupta- 2021A7PS2091H

## Algorithm
WE went over a lot of ideas to make this code and we thought of using trees, recursive functions etc. but judging by the initial conditions given to us, we thought we can also use String Comparision. The first step was analyzing Input, we have 2 Possibilities for each line. If last character is P it is a premise, otherwise it's a statement.

### AND ELIMINATION
Here we have two cases:
If it's and elimination 1, i.e we have "(a^b)". We must have "a" in the corresponding line which comes from ^ elimination 1
Here we loop on the statement "(a^b)" using a as the reference. So we start from the left-mostbracket and keep comparing until the eliminated string ends i.e. a and we verify this.

Otherwise, case 2 - Here we start from behind. We keep comparing until we reach the start of the smaller string.

Example: We have "((a^b)^(c^d))" and "(c^d)" we compare "(c^d)" ignoring the ending bracket by looping through the string "(c^d)".

---

### OR INTRODUCTION
In or introduction we have 2 modes, one for left introduction and one for right introduction
If mode is 1, Here we go until the current line ends and keep comparing i.e. if we have a and we want "(avb)" using or introduction we compare from start till the smaller string ends i.e. here we loop on "a" and go until the it ends.
For case 2, we start from behind. We keep comparing till we reach the start of smaller string.

---

### IMPLICATION ELIMINATION
Here if current statement is "b" and we get this by using implication elimination on the statement "a>b" given "a".
We generate a string "a>b" since we know the initial term and we also know the eliminated term
Then we compare it with the term from which we eliminate i.e. "(a>b)"
By default brackets are added while comparing since we always know > will be inside brackets

---

### MODUS TOLLENS
Here if i is the current line which is "(~a)" and lineNo1 gives is a>b and lineNo2 gives "(~b)"
We compare using "a" and "b" by removing both the negations from each of those terms and compare it with the actual statement "(a>b)"

## Future Prospects

We used C due to the fact that it's extensible and since we have to build most of the functionality from scratch we can be a lot more flexible. Since the main idea behind this program is just string comparision, We plan on extending the algorithm to double negation elimination, negation elimination and bottom elimination, which might help us verify a larger number of proofs in the coming future. We did not go towards implementing trees or anything because we thought that'll lead to a lot of space management and increase time complexity.


Infact, if we have to implement double negation elimination, then all we have to do is check if the inner statement matches with the one that comes after the elimination.


For negation elimination, we just check the line numbers in the current line. If the expression in one of the lines is the negation of the other, we will say that the corresponding negation elimination rule applied is correct.


For bottom elimination, if the line number specified in the current line is a bottom, we can conclude that any expression can be written in the current line, and thus say the bottom elimination rule applied at the current line is valid.
