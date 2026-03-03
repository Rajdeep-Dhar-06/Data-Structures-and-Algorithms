# [Max Xor Subarray of size K](https://www.geeksforgeeks.org/problems/max-xor-subarray-of-size-k/1)
## Medium
Given an array of integers&nbsp;arr[]&nbsp;&nbsp;and a number&nbsp;k. Return&nbsp;the&nbsp;maximum xor&nbsp;of a subarray of size k.
Note:&nbsp;A subarray is a contiguous part of any given array.
Examples:
Input: arr[] = [2, 5, 8, 1, 1, 3], k = 3
Output: 15
Explanation: arr[0] ^ arr[1] ^ arr[2] = 15, which is maximum.
Input: arr[] = [1, 2, 4, 5, 6] , k = 2
Output: 6
Explanation: arr[1] ^ arr[2] = 6, which is maximum.
Constraints:1 ≤ arr.size() ≤ 1060 ≤ arr[i] ≤ 1061 ≤ k ≤ arr.size()