int maximumNonAdjacentSum(vector<int> &arr)
{
    int i = 0, j = 0, temp = 0;
    for(int n: arr) {
        temp = max(i + n, j);
        i = j;
        j = temp;
    }
    return j;
}