# 排序
本周就部分排序算法进行进一步学习，希望更加巩固加强理解。
## 堆排序
时间复杂度：O(nlgn)

具有空间原址性：任何时候都只需要常数个额外的元素空间存储临时数据。

### 堆
可应用于构造优先队列，堆排序等。

堆可以看作一个近似的完全二叉树，除了最底层，该树是完全充满的,并且为从左向右填充。

表示堆的数组A有两个属性：

A.length:数组规模，即数组元素的个数

A.heap-size:当前堆存放的有效元素个数

0<=A.heap-size<=A.length

把堆的高度定义为根结点的高度，因此一个包含n个元素的队可以看作一个完全二叉树，该堆的高度为Θ（lgn）。堆结构上基础操作与树高度成正比，即时间复杂度O(lgn)。
### 二叉堆
最大堆：满足堆的定义，且A[PARENT(i)]>A[i]

最小堆:满足堆的定义，且A[PARENT(i)]<A[i]
最小堆通常可构成优先队列。堆排序算法中，通常使用最大堆。
### MAX-HEAPIFY
维护堆性质，时间复杂度为O(lgn)

在程序的每一步，从A[i],A[LEFT(i)]和A[RIGHT(i)]中选择最大的，将其下标存于largest中，将A[i]与A[largest]交换。



   void heap::maxHeapify(int pos)
   {

	if (pos >= vecSize)

	{
		return;
	}
	int max=pos;
	if (Left(pos) <vecSize && heapVec[max]<heapVec[Left(pos)] )
	{
		max = Left(pos);
	}
	if (Right(pos) < vecSize && heapVec[max] < heapVec[Right(pos)])
	{
		max = Right(pos);
	}
	int exchange = max;
	max = pos;
	pos = exchange;
	maxHeapify(pos);

### BUILD-MAX-HEAP(A)


build_Max_heap()
{

	for (int i = vecSize / 2; i >= 0; i--)
	{
		maxHeapify(i);
	}
}

### 堆排序
heap::heapSort()

{
	
    build_Max_heap();
	int size = vecSize;
	for (int i = size-1; i >= 1; i++)
	{
		int k = heapVec[i];
		heapVec[i] = heapVec[0];
		heapVec[0] = k;
		size--;
		maxHeapify(0);
	}
}

