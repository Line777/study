# 剑指 Offer 32 - I. 从上到下打印二叉树

从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

 

例如:

给定二叉树:
 [3,9,20,null,null,15,7],

    3

   / \

  9  20

    /  \

   15   7

返回：

[3,9,20,15,7]

## 算法
特例处理： 当树的根节点为空，则直接返回空列表 [] ；

初始化： 打印结果列表 res = [] ，包含根节点的队列 queue = [root] ；

BFS 循环： 当队列 queue 为空时跳出；


出队： 队首元素出队，记为 node；

打印： 将 node.val 添加至列表 tmp 尾部；


添加子节点： 若 node 的左（右）子节点不为空，则将左（右）子节点加入队列 queue ；

返回值： 返回打印结果列表 res 即可。
