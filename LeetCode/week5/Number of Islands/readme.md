# 岛屿数量
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

 

示例 1：

输入：grid = [

  ["1","1","1","1","0"],

  ["1","1","0","1","0"],

  ["1","1","0","0","0"],

  ["0","0","0","0","0"]

]

输出：1

示例 2：

输入：grid = [

  ["1","1","0","0","0"],

  ["1","1","0","0","0"],

  ["0","0","1","0","0"],

  ["0","0","0","1","1"]

]

输出：3
## 深度搜索
因为前边看数据结构时没有看过图，对图只有一点印象，这道图的题确实不会。

根据题意，可将1看做一个结点，在水平和竖直方向上有连接的1可以看做是中间有连线的两个结点，就这样将数组看作一个无向图，对图进行深度搜索。将搜索到的结点置0.每次搜索将一个岛屿置零，岛屿数+1
