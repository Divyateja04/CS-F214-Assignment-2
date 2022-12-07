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
The first step was analyzing Input, We have 2 Possibilities. If last character is P it is a premise, Otherwise it's a statement.

### AND ELIMINATION
Here we have two cases:
If it's and elimination 1, i.e we have "(a^b)" and then we must have "a" in the corresponding line which comes from ^ elimination 1
Here we loop on the statement (a^b) using a as the reference. So we start from the left-mostbracket and keep comparing until the eliminated string ends i.e. a and we verify this.

Otherwise, case 2 Here we start from behind. We keep comparing until we reach the start of the smaller string.

Example: We have ((a^b)^(c^d)) and (c^d) we compare (c^d) ignoring the ending bracket by looping through the string (c^d).

---

### OR INTRODUCTION
In or introduction we have 2 modes, one for left introduction and one for right introduction
If mode is 1, Here we go until the current line ends and keep comparing i.e. if we have a and we want "(avb)" using or introduction we compare from start till the smaller string ends i.e. here we loop on "a" and go until the it ends.
For case 2, we start from behind. We keep comparing till we reach the start of smaller string.

---

### IMPLICATION ELIMINATION
Here if current statement is "b" and we are getting this by using implication elimination on the statement "a>b" given a
We generate a string "a>b "since we know the initial term and we also know the eliminated term
Then we compare it with the term from which we eliminate i.e. (a>b)
By default brackets are added while comparing since we always know > will be inside brackets

---

### MODUS TOLLENS
Here if i is the current line which is (~a) and lineNo1 gives is a>b and lineNo2 gives (~b)
We compare using "a" and "b" by removing both the negations from each of those terms and compare it with the actual statement (a>b)
