vector<int> Solution::maxset(vector<int> &a)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int cmax, gmax;

    vector<int> c, g;
    cmax = gmax = 0;
    for (auto i : a)
    {
        if (i >= 0)
        {
            cmax += i;
            c.push_back(i);
        }
        else
        {
            if(cmax > gmax){
                g = c;
            }
            c.clear();
        }
    }
    return g;
}
