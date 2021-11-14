# 第七周总结
本周学习了第十一章和第十二章内容。比较难懂。第十一章摊还分析聚合分析，核算法，势能法三种方法。但是在聚合分析和核算法的估计上还是不知道该怎么去估计。实际上可能不会太运用。第十二章的高级数据结构难度有些大。伸展树进行扩展时，我看博客中有两种扩展的方式，而书上只讲了一种。使用过的元素调整到根节点，但后面又有按频率进行排序的。在红黑树、AA树等数据结构中，实现难度太大，在看代码时在结点的插入删除比较麻烦。确定性跳跃表有些不知道该怎么使用。
## 摊还分析
在摊还分析中，我们求数据结构的一个操作序列中所执行的所有操作的平均时间，来评价操作的代价。注意，摊还分析不同于上一篇博客中的平均情况分析，它并不涉及不同输入出现的概率，可以保证最坏情况下每个操作的平均性能。这样，就可以说明一个操作的平均代价是很低的，即使序列中某个单一操作的代价很高。

### 聚合分析
 聚合分析要求我们要总体看问题，首先multipop(s, k)也是一个弹栈的操作，当栈里有数据的时候执行此操作才有效，所以上述提到的O(n^2)是不科学的。并且push(s, x)、pop(s)的代价是1，可想而知最坏的情况当然是前n-1次操作都是压栈，而最后一次才执行multipop(s, n-1)，这样的代价也只有2(n-1) = 2n-2，时间复杂度是O(n)，平均下来每个操作的摊还代价就是O(1)了。
### 核算法
我们将赋予一个操作的费用称为它的摊还代价。当一个操作的摊还代价超出其实际代价时，我们将差额存入数据结构中的特定对象，存入的差额称为信用。对于后续操作中摊还分析小于实际代价的情况，信用可以用来支付差额。因此，我们可以将一个操作的摊还代价分解为其实际代价和信用（存入的或用掉的）。不同的操作可能有不同的摊还代价。这种方法不同于聚合分析中所有操作都赋予相同摊还代价的方式。

### 势能法
 势能法其实与核算法相似。势能法摊还分析并不将预付代价表示为数据结构中特定对象的信用，而是表示成“势能”，将势能释放即可用来支付未来操作的代价。我们将势能与整个数据结构而不是特定的对象相关联

## 高级数据结构
### 伸展树
假设想要对一个二叉查找树执行一系列的查找操作，为了使整个查找时间更小，被查频率高的那些条目就应当经常处于靠近树根的位置。于是想到设计一个简单方法， 在每次查找之后对树进行重构，把被查找的条目搬移到离树根近一些的地方。伸展树应运而生。伸展树是一种自调整形式的二叉查找树，它会沿着从某个节点到树根之间的路径，通过一系列的旋转把这个节点搬移到树根去。

两种重构方法：

1、单旋：在查找完位于节点x中的条目i之后，旋转链接x和其父节点的边。（除非x就是树根）

2、搬移至树根：在查找完位于节点x中的条目i之后，旋转链接x和其父节点的边，然后重复这个操作直至x成为树根。
### 红黑树
红黑树是一种特定类型的二叉树，它是在计算机科学中用来组织数据比如数字的块的一种结构。
红黑树是一种平衡二叉查找树的变体，它的左右子树高差有可能大于 1，所以红黑树不是严格意义上的平衡二叉树（AVL），但 对之进行平衡的代价较低， 其平均统计性能要强于 AVL 。

由于每一棵红黑树都是一颗二叉排序树，因此，在对红黑树进行查找时，可以采用运用于普通二叉排序树上的查找算法，在查找过程中不需要颜色信息。 
红黑树是每个结点都带有颜色属性的二叉查找树，颜色或红色或黑色。  

在二叉查找树强制一般要求以外，对于任何有效的红黑树我们增加了如下的额外要求

性质1. 结点是红色或黑色。 

性质2. 根结点是黑色。

性质3. 所有叶子都是黑色。（叶子是NIL结点） 

性质4. 每个红色结点的两个子结点都是黑色。（从每个叶子到根的所有路径上不能有两个连续的红色结点）

性质5. 从任一节结点其每个叶子的所有路径都包含相同数目的黑色结点。
### AA树
AA树是Arne Andersson教授在1993年在他的论文"Balanced search trees made simple"中介绍，设计的目的是减少红黑树考虑的不同情况。区别于红黑树的是，AA树的红结点只能作为右叶子。另外AA树为实现方便，不再使用红黑两种颜色，而是用level标记结点，结点中的level相当于红黑树中结点的黑高度。AA树可以在O(log n)的时间内做查找，插入和删除，这里的n是树中元素的数目。
从实现角度看，AA树减少了红黑树插入删除考虑的情况；
AA树属于红黑树，时间复杂度和红黑树相同，即O(logn)，但是旋转次数相对较多。

level的规定满足以下5个条件

1、每个叶子的level是1；

2、每个左孩子的level是其父结点的level减1；

3、每个右孩子的level等于其父结点的level或等于其父结点的level减1

4、每个右孙子的level一定比其祖父的level小；

5、每个level大于1的结点有两个孩子。

