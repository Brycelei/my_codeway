function finalPrices(prices : number[]) : number[]
{
    const n = prices.length;
    const ans :number[] = new Array(n).fill(0);
    const stack :number[] = [];
    /**
     * 数组中最后一个元素一定没有满足条件的j
     */

    for (let i = n - 1; i >= 0; i--)
    {
        while (stack.length && stack[stack.length - 1] > prices[i])
        {
            stack.pop();
        }
        ans[i] = stack.length === 0 ? prices[i] : prices[i] - stack[stack.length - 1];
        stack.push(prices[i]);
    }
    return ans;
};

/**
 * 
 * 给你一个数组 prices ，其中 prices[i] 是商店里第 i 件商品的价格。
 * 商店里正在进行促销活动，如果你要买第 i 件商品，那么你可以得到与 prices[j] 相等的折扣
 * 其中 j 是满足 j > i 且 prices[j] <= prices[i] 的 最小下标，
 * 如果没有满足条件的 j ，你将没有任何折扣。
 * 请你返回一个数组，数组中第 i 个元素是折扣后你购买商品 i 最终需要支付的价格
 * input prices = [8,4,6,2,3]
 * output [4,2,4,2,3]
 */

const prices :number[] = [8,4,6,2,3]
// function call
const output = finalPrices(prices);
for(let a of output)
{
    console.log(a)
}