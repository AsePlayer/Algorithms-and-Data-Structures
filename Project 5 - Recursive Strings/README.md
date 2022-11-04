# Project 2: Singly-Linked List
The purpose of this assignment is to assess your ability to:

* Implement recursive algorithms
* Communicate details of your solution effectively

Recognizing strings based on a set of restrictions is a common computational problem. A Slop is a string of characters that has certain properties. Your program will read in strings of characters and output whether or not they are Slops. 

### A *Slip* is a character string that has the following properties:
* Its first character is either a 'D' or an 'E'
* The first character is followed by a string of one or more 'F's
* The string of one or more 'F's is followed by either a Slip or a 'G'
* The Slip or 'G' that follows the F's ends the Slip. For example, DFFEFFFG is a Slip since it has a 'D' for its first character, followed by a string of two F's, and ended by the Slip 'EFFFG'
* Nothing else is a Slip

### A *Slap* is a character string that has the following properties:
* Its first character is an 'A'
* If it is a two-character Slap then its second and last character is an 'H'
* If it is not a two-character Slap, then it is in one of these two forms:
* 'A' followed by 'B' followed by a Slap, followed by a 'C'
* 'A' followed by a Slip (see above) followed by a 'C'
* Nothing else is a Slap

### A Slop is a character string that consists of a Slap followed by a Slip.
Examples:  
Slips:     	DFG, EFG, DFFFFFG, DFDFDFDFG, DFEFFFFFG
Not Slips:   	DFEFF, EFAHG, DEFG, DG, EFFFFDG
Slaps: 	AH, ABAHC, ABABAHCC, ADFGC, ADFFFFGC, ABAEFGCC, ADFDFGC
Not Slaps:   ABC, ABAH, DFGC, ABABAHC, SLAP, ADGC
Slops:       AHDFG, ADFGCDFFFFFG, ABAEFGCCDFEFFFFFG
Not Slops:   AHDFGA, DFGAH, ABABCC


## Run code easily on Repl.it!
https://replit.com/@RScott46/Recursive-Strings

---

Write a program that will read input from a file and determine whether or not a string of characters is a slop.  The file will be organized as follows.  The first line contains an integer N between 1 and 100 indicating how many strings of characters are to be tested.  The next N lines each contain a string.

## Write three recursive methods that determine whether or not a string is a slop. Here are the function signatures:
* bool isSlop(string str);
* bool isSlap(string str);
* bool isSlip(string str);

You will want to write isSlip first, followed by isSlap, and finally isSlop. Make sure that isSlip and isSlap work flawlessly. Do not proceed to isSlop until you are sure that the other two methods work.

Your program should write its output to the console.  The first line of output should read SLOPS OUTPUT.  Each of the next N lines of output should consist of either YES or NO depending on whether or not the corresponding input line is a Slop. The last line of output should read: END OF OUTPUT.

Shown below is a sample run.  The following input data:
2
AHDFG
DFGAH
Should produce the following output: 

SLOPS OUTPUT
YES
NO
END OF OUTPUT

Test everything carefully.
