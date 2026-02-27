# [Number of submatrix have sum X](https://www.geeksforgeeks.org/problems/number-of-submatrix-have-sum-k/1)
## Hard
Given a&nbsp;matrix mat[][] of size&nbsp;n × m and an integer x, find the number of square submatrices whose sum of elements is equal to x.
Examples:
Input: mat[][] = [[2, 4, 7, 8, 10],                [3, 1, 1, 1, 1],                [9, 11, 1, 2, 1],                [12, -17, 1, 1, 1]] , x = 10Output: 3Explanation: The sub-squares whose sum of elements = 10, are colored in the matrix.
Input: mat[][] = [[3, 3, 5, 3],                [2, 2, 2, 6],                [11, 2, 2, 4]] ,x = 1Output: 0Explanation: There is no sub-squares whose sum of elements is 1.
Constraints:1 ≤ n, m ≤ 100-103 ≤ mat[i] ≤ 103-109 ≤ x ≤&nbsp;109