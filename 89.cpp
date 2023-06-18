#include <stack>
//https://www.codingninjas.com/codestudio/problems/next-smaller-element_8230814?challengeSlug=striver-sde-challenge&leftPanelTab=1
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int>ans(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--)
    {
        if(st.empty())
        {
            ans[i]=-1;
            st.push(arr[i]);
        }
        else
        {
            while(st.size() and st.top()>=arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                ans[i]=-1;
            }
            else
            {
                ans[i]=st.top();
            }
            st.push(arr[i]);
        }
    }
    return ans;
}
