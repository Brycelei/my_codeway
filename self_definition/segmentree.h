struct segmentree
{
    int begin;
    int end;
    int val;
    segmentree *left;
    segmentree *right;
    segmentree()
    {
        begin = end = val = 0;
        left = right = nullptr;
    }
};
