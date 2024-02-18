对于两数相乘然后取模有以下公式：
( a ∗ b ) % k = ( a % k ) ( b % k ) % k (a * b) \% k = (a \% k)(b \% k) \% k
(a∗b)%k=(a%k)(b%k)%k

证明：

假设
a = A k + B ； b = C k + D a = Ak +B；b = Ck + D
a=Ak+B；b=Ck+D

其中 A,B,C,D 是任意常数，那么：
a ∗ b = A C k 2 + A D k + B C k + B D ( a ∗ b ) % k = ( A C k 2 + A D k + B C k + B D ) % k = 0 + 0 + 0 + B D % k = B D % k a*b = ACk^2 + ADk + BCk +BD \\ (a * b) \% k = (ACk^2 + ADk + BCk +BD)\%k \\=0+0+0+BD \% k \\=BD \% k
a∗b=ACk 
2
 +ADk+BCk+BD
(a∗b)%k=(ACk 
2
 +ADk+BCk+BD)%k
=0+0+0+BD%k
=BD%k

又因为：
a % k = B ； b % k = D a \% k = B；b \% k = D
a%k=B；b%k=D

所以：
( a ∗ b ) % k = B D % k = ( a % k ) ( b % k ) % k (a * b) \% k = BD \% k = (a \% k)(b \% k) \% k
(a∗b)%k=BD%k=(a%k)(b%k)%k

高幂运算的情况
由于高幂运算很容易造成数字溢出，因此不能直接求幂
而高幂运算后取模，例如a^c%k，相当于c个a连乘然后对k取模：(a*a*a....*a) % k

这里b个a相乘很容易溢出，应该考虑如何缩小相乘的结果
根据上面公式可知：
( a ∗ a ∗ a . . . ∗ a ) % k = ( ( a % k ) ( a % k ) ( a % k ) . . . ( a % k ) ) % k (a*a*a...*a) \% k=((a\%k)(a\%k)(a\%k)...(a\%k)) \% k
(a∗a∗a...∗a)%k=((a%k)(a%k)(a%k)...(a%k))%k

设b=(a%k)，则相当于
( a ∗ a ∗ a . . . ∗ a ) % k = ( b ∗ b ∗ b ∗ . . . b ) % k (a*a*a...*a) \% k=(b*b*b*...b)\%k
(a∗a∗a...∗a)%k=(b∗b∗b∗...b)%k

其中b是小于k的，这样就保证了每个因子都小于k，然后我们需要进一步缩小相乘结果
c个b相乘对k取模，可以把前面两个因子相乘结果看做一个数，后面c-2个因子相乘的结果看做一个数：
( b ∗ b ∗ b ∗ . . . b ) % k = ( ( b ∗ b ) % k ∗ ( b ∗ b ∗ b . . ∗ b ) % k ) % k = ( ( b ∗ b ) % k ∗ ( b % k ) ( b % k ) ( b % k ) . . . ( b % k ) ) % k = ( ( b ∗ b ) % k ∗ b ∗ b ∗ . . . ∗ b ) % k (b*b*b*...b)\%k = ((b*b)\%k * (b*b*b..*b)\%k)\%k \\= ((b*b)\%k * (b\%k)(b\%k)(b\%k)...(b\%k))\%k \\=((b*b)\%k *b*b*...*b)\%k
(b∗b∗b∗...b)%k=((b∗b)%k∗(b∗b∗b..∗b)%k)%k
=((b∗b)%k∗(b%k)(b%k)(b%k)...(b%k))%k
=((b∗b)%k∗b∗b∗...∗b)%k

假设B=b*b，那么有
( ( b ∗ b ) % k ∗ b ∗ b ∗ . . . ∗ b ) % k = ( B ∗ b ∗ b . . . . ∗ b ) % k = ( ( B ∗ b ) % k ∗ ( b ∗ b . . . ∗ b ) ) % k ((b*b)\%k *b*b*...*b)\%k=(B*b*b....*b)\%k \\=((B*b)\%k * (b*b...*b) )\%k
((b∗b)%k∗b∗b∗...∗b)%k=(B∗b∗b....∗b)%k
=((B∗b)%k∗(b∗b...∗b))%k
依此类推，因此可以得出结论，在高幂运算之后取模，我们可以先将底数取一次模，然后求幂的过程中，两两相乘后再次取模

// 计算a的c次方对k取模的结果
```c++
public int pow(int a ,int c ,int k){
    // 保证每个因子都小于base
    a %= k;
    int res = 1;
    for (int i = 0; i < c; i++) {
        // 两两相乘
        res *= a;
        // 对乘法结果求模
        res %= k;
    }
    return res;
}
```
