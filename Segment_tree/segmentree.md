## 离散化的方法
离散化的理解正如百度百科的样例一样：把 1, 999, 100000, 15 变成 1, 3, 4, 2

我们需要确定各个数字在这一堆数里的位置，因此需要两步操作：排序 和 去重

用到两个 <algorithm>库 里的函数 sort() 、 unique() 和 upper_bound()

首先输入一个 n 表示有 n 张海报
将数据存入原数据数组 orig 和离散数据数组 bcre 这里强烈建议大家使用 vector 容器 来代替数组，同样可以预定数组大小，和传统数组一样，而且操作更灵活
将 n*2 方便之后使用，因为我们储存了海报的两边，因此数组里的元素一定是 2n 个
`sort()` 用于将数组区间内的元素排序
* `unique()` 用于将数组区间内 相邻的相同元素 进行删除只剩下一个，排序后再这样删除就是 去重 辣
* 做完去重的工作以后再遍历原数组，使用 `upper_bound()` 函数求出原数据中每一个数在所有数里 排第几
* `upper_bound()` 返回指定数组区间中出现的第一个大于指定数的数的位置
* 我们用这个位置减去开始位置 bcre.begin() 就能求出包括这个数在内前面有多少个数了
由于这个原数据中的数一定存在于去重之后的数据中，因此这里也可以换成

```c++
orig[i] = lower_bound(bcre.begin(), bcre.end(), orig[i]) - bcre.begin() + 1;
1
lower_bound() 返回指定数组区间中出现的第一个大于等于指定数的数的位置
``
原文链接：https://blog.csdn.net/qq_37504214/article/details/104773384