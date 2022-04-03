# 剑指 Offer 66. 构建乘积数组
给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

 

示例:

输入: [1,2,3,4,5]
输出: [120,60,40,30,24]

本题的难点在于 不能使用除法 ，即需要 只用乘法 生成数组 B 。根据题目对 B[i] 的定义，可列表格，如下图所示。

根据表格的主对角线（全为 1 ），可将表格分为 上三角 和 下三角 两部分。分别迭代计算下三角和上三角两部分的乘积，即可 不使用除法 就获得结果。
初始化：数组 B ，其中 B[0] = 1；辅助变量 tmp=1 ；
计算 B[i] 的 下三角 各元素的乘积，直接乘入 B[i] ；
计算 B[i]的 上三角 各元素的乘积，记为 tmp ，并乘入B[i] ；
返回 B 。