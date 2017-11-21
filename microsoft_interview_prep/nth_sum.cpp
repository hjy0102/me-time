/**
Given two sorted arrays, we can get a set of sums(add one element from the first and one from second). Find the N’th element in the set considered in sorted order.
Note: Set of sums should have unique elements.

Input : arr1[] = {1, 2}
        arr2[] = {3, 4}
        N = 3
Output : 6
We get following elements set of sums.
4(1+3), 5(2+3 or 1+4), 6(2+4)
Third element in above set is 6.

Input : arr1[] = {1, 3, 4, 8, 10} 
        arr2[] = {20, 22, 30, 40} 
        N = 4
Output : 25
We get following elements set of sums.
21(1+20), 23(1+22 or 20+3), 24(20+4), 25(22+3)...
Fourth element is 25.

*/

