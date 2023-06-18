//https://www.codingninjas.com/codestudio/problems/valid-parentheses_8230714?challengeSlug=striver-sde-challenge&leftPanelTab=1
bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char>st;
    int n=expression.size();
    for(int i=0;i<n;i++)
    {
        if(expression[i]=='(' || expression[i]=='[' || expression[i]=='{')
        {
            st.push(expression[i]);
        }
        else
        {
            if(st.empty())
            {
                return 0;
            }
            if(expression[i]==')' and st.top()=='(')
            {
                st.pop();
            } else if (expression[i] == ']' and st.top() == '[') {
              st.pop();
            } else if (expression[i] == '}' and st.top() == '{') {
              st.pop();
            } else {
              return 0;
            }
        }
    }
    return st.empty();

}
