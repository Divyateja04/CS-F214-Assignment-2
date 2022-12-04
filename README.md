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
The first step was analyzing Input, We have 2 Possibilities. If last character is P it is a premise, Otherwise it's a statement


### AND ELIMINATION
Here also we have two cases If it's and elimination 1, Here we loop until the bigger line goes to the start
and keep comparing i.e. if we have (a^b) and we get b(this is i) using and elimination we compare from start till the smaller string goes to the start
Otherwise, case 2Here we go until the current line ends
and keep comparing i.e. if we have (a^b) and we get a
using and elimination we compare from start till the
smaller string ends


### OR INTRODUCTION
In or introduction also we have 2 modes, one for left introduction
and one for right introduction
If mode is 1, Here we go until the current line ends
and keep comparing i.e. if we have a and we want (avb)
using or introduction we compare from start till the
smaller string ends
If mode is 2
Here we loop until the bigger line goes to the start
and keep comparing i.e. if we have b and (avb)(this is i)
using and elimination we compare from start till the
smaller string goes to the start


### IMPLICATION ELIMINATION
Here if i is the current line which is a
and lineNo1 gives is (a>b) and lineNo2 gives b
We make the string (a>b) and compare it with (a>b)


### MODUS TOLLENS
Here if i is the current line which is (~a)
and lineNo1 gives is a>b and lineNo2 gives (~b)