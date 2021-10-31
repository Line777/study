# 不相交集ADT

## 1.不相交集
解决等价关系的一种数据结构。在不相交集里有两种操作，一种是Union，添加关系，将两个元素所在的等价类合并，去掉原来两个集合。
另一种操作是Find，返回包含元素的集合的名字。
## 2.等价关系
（1）自反性，对于所有a∈A，aRa。

（2）对称性，aRb当且仅当bRa。

（3）传递性，若aRb且bRc则aRc。
## 3.集合的划分
等价类形成对S的一个划分：S的每一个成员恰好出现在一个等价类中。（要判断a~b是否成立，即判断ab是否在同一个等价类中）
又因为每个等价类中都含有不相同的元素，即S1 ∩ S2 = 空集，使得这些集合不相交
## 4.Union
实现Union有很多算法。
1.通过使第二颗树成为第一棵树的子树而完成合并

void SetUnion(DisjSet S, SetType Root1, SetType Root2 )

{

    S[Root1] = Root2;
}

2.按高度（秩）求并的程序

void SetUnion(DisjSet S, SetType Root1, SetType Root2 )

{

    if(S[Root2] < S[Root1])  //Root2 is deeper set
        S[Root1] = Root2;    //Make Root2 new root
    else
    {
        if(S[Root2] = S[Root1]) //Same Height
            S[Root1]--;         //so update
        S[Root2] = S[Root1];
    }
}
## 5.Find
SetType Find(ElementType X, DisjSet S)

{
    
    if(S[X] <= 0)
        return X;
    else
        return Find(S[X], S);        //尾递归
}



