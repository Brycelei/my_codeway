## 背包问题

表头|  重量	|价值
:---:|:---:|:---:
物品0	|1	|15
物品1	|3	|20
物品2	|4	|30

```c++
  // 初始化
    for (int j = weight[0]; j <= bagweight; j++)
    {
        dp[0][j] = value[0];
    }
    
```
* -> dp[i][j] 表示从下标为[0-i]的物品里任意取，放进容量为j的背包，价值总和最大是多少。
* 物品i，背包重量j；初始化"dp"数组

dp[i][j]|背包0|背包1|背包2|背包3
:---:|:---:|:---:|:---:|:---:
物品0	|0	|15 |15 |15
物品1	|0	|0  |0  |0
物品2	|0	|0  |0  |0