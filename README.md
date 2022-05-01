# Tower_Of_Hanoi-Problem
A Program to display step by step solution to Tower_Of_Hanoi Problem</br>
The Program asks for no. of disks in the first rod and then displays all steps with the help of a figure to solve the Problem.</br>
Just clone the repository or copy the code , compile it and run it.

Example :-</br>
```
Enter number of disks in the first rod : 3

Initially

        1_|_        |         |
       2__|__       |         |
      3___|___      |         |
      ____|____ ____|____ ____|____
          A         B         C


Step 1 - Transfer disk 1 from A to C

          |         |         |
       2__|__       |         |
      3___|___      |       1_|_
      ____|____ ____|____ ____|____
          A         B         C


Step 2 - Transfer disk 2 from A to B

          |         |         |
          |         |         |
      3___|___   2__|__     1_|_
      ____|____ ____|____ ____|____
          A         B         C


Step 3 - Transfer disk 1 from C to B

          |         |         |
          |       1_|_        |
      3___|___   2__|__       |
      ____|____ ____|____ ____|____
          A         B         C


Step 4 - Transfer disk 3 from A to C

          |         |         |
          |       1_|_        |
          |      2__|__   3___|___
      ____|____ ____|____ ____|____
          A         B         C


Step 5 - Transfer disk 1 from B to A

          |         |         |
          |         |         |
        1_|_     2__|__   3___|___
      ____|____ ____|____ ____|____
          A         B         C


Step 6 - Transfer disk 2 from B to C

          |         |         |
          |         |      2__|__
        1_|_        |     3___|___
      ____|____ ____|____ ____|____
          A         B         C


Step 7 - Transfer disk 1 from A to C

          |         |       1_|_
          |         |      2__|__
          |         |     3___|___
      ____|____ ____|____ ____|____
          A         B         C



All the disks are transfered from A to C

```
