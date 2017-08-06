int main()
{
    int sum = 100, i = 0;
    int x = 20;
    // loop body is executed at least once
    do
    {
        sum -= x;
        i++;
    }
    while(sum >= 0);

    return i;
}