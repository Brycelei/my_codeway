
function deepestLeavesSum(root: TreeNode | null): number {
    var maxlevel = -1;
    var sum = 0;
    function dfs(root: TreeNode | null, level: number )
    {
        if(!root) return;
        if(level > maxlevel)
        {
            maxlevel = level;
            sum = root.val;
        }else if(level == maxlevel)
        {
            sum += root.val;
        }
        dfs(root.left, level + 1);
        dfs(root.right, level + 1 );
    }
    dfs(root, 0);
    return sum;
};