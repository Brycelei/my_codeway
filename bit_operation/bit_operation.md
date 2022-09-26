## 按位与
**特性，和 1 相与不变，和 0 相与 得 0**：
```c++
x && 1 = x 
x && 0 = 0
```
![avatar](https://img-blog.csdnimg.cn/be475c87dcba40e3a6e4f0fffb181b7c.png#pic_center)
- 从上面可以看到，与1相与不变，与0相与会变为0。可以利用这个特性将某些位清零，也可以取出某些位。

## 按位或
<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=default"></script>

**特性，和 1 相或 得 1，和 0 相或不变**
```c++
x || 1 = 1
x || 0 = x
```
![avatar](https://img-blog.csdnimg.cn/0c10cfc65a8e4e08a534524f4bfb4fc9.png#pic_center)

- 从上面可以看到，与1相或会变为1，与0相或不变。可以利用这个特性将某些位置位(位的值变为1)

## 按位异或
在 `逻辑异或` 运算 中，参与运算的两个布尔值只有 `0` 和 `1` 两种取值，只有当两个布尔值不同时，结果才得`1`，其余结果为`0`，类似不等于的关系
- 按位异或 则是对两个二进制数的对应位分别做 逻辑异或 运算， 符号为 ^

![avatar](https://img-blog.csdnimg.cn/c51682fd78cb41488a532588bd6ca8b9.png#pic_center)

从上面可以看到，与1异或会取反(由1变0，或由0变1)，与0异或不变。可以利用这个特性将某些位取反。
a^b^b=a
​
