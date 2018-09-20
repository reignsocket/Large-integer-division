Problem Description  
Find the quotient of two large positive integers  
  
Input data  
  
Line 1 is the number of groups of test data n, each group of test data is 2 rows, the first row is the dividend and the second row is the divisor. There is a blank line between each set of test data, each line of data does not exceed 100 characters
Output requirements
n rows, each set of test data has a line of output is the corresponding integer quotient  
  
Input sample  
3  
2405337312963373359009260457742057439230496493930355595797797660791082739646  
2987192585318701752584429931160870372907079248971095012509790550883793197894  
10000000000000000000000000000000000000000  
10000000000  
5409656775097850895687056798068970934546546575676768678435435345  
1  
  
Output sample  
0  
1000000000000000000000000000000  
5409656775097850895687056798068970934546546575676768678435435345  
  
Problem solving  
The basic idea is to do the subtraction repeatedly to see how many divisors can be subtracted from the dividend, and how much is the quotient. One by one is obviously too slow, how can it be reduced faster? Take 7546 and divide by 23 as an example to see: the starting quotient is 0. First, subtract 100 times of 23, which is 2300. It is found that it is reduced by 3 times and the remaining 646. Then the value of the quotient increases by 300. Then subtract 260 by 646 and find that it is reduced by 2 times and the remaining 186, so the value of the quotient increases by 20. Finally, subtracting 23 from 186 is enough to reduce 8 times, so the final quotient is 328. So the core of this question is to write a subtraction function of a large integer, and then call the function repeatedly to perform the subtraction operation. When calculating the divisor by 10 times or 100 times, you do not need to do multiplication. You can add 0 directly after the divisor.  
  
common problem  
Problem 1. Forgot to test data for each group, first initialize an1, an2 and aResult to all 0s, but only initialize them once. This resulted in the wrong starting from the second set of test data.  
Problem 2: When subtracting the borrowing, it is easy to ignore the continuous borrowing, for example, 10000 – 87, the borrowing will continue until 1.  
