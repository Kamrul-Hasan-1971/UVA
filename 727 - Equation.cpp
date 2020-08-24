#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int isLeftToRight(char op)
{
    if (op == '+' || op=='-' || op=='/' || op=='*' || op=='%') return true;
    return false;
}

int Weight(char c)
{
    if(c == '^' || c == '%') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return -1;
}

bool prec(char op1, char op2)
{
    int op1Weight = Weight(op1);
    int op2Weight = Weight(op2);
    if (op1Weight == op2Weight)
    {
        if (isLeftToRight(op1))return false;
        return true;
    }
    return op1Weight > op2Weight ? true : false;
}

bool close(char c)
{
    if(c==')' || c=='}' || c==']') return true;
    return false;
}
bool open(char c)
{
    if(c=='(' || c=='{' || c=='[') return true;
    return false;
}
bool bracPair(char o,char c)
{
    if(o=='(' || c==')') return true;
    if(o=='{' || c=='}') return true;
    if(o=='[' || c==']') return true;
    return false;
}

string infixToPostfix(string s)
{
    stack<char> st;
    int l = s.length();
    string ans="";
    for(int i = 0; i < l; i++)
    {
        if(s[i]==' ') continue;
        else if(isalnum(s[i])) ans+=s[i];
        else if(open(s[i])) st.push(s[i]);
        else if(close(s[i]))
        {
            while(!st.empty() && !open(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            if(!st.empty())
            {
                if(bracPair(st.top(),s[i])) st.pop();
                else return "-1";
            }
            else return "-1";
        }
        else
        {
            //ans+=' ';
            while(!st.empty())
            {
                if(open(st.top())) break;
                if(prec(s[i],st.top())) break;
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        if(open(st.top())) return "-1";
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main()
{
    int T,i;
    cin >> T ;
    getchar();
    getchar();
    for( i = 0 ; i < T ; i++)
    {
        string exp="";
        char ch;
        while((ch=getchar())!=EOF && ch!='\n' ) {exp+=ch;getchar();}
        cout<<infixToPostfix(exp)<<endl;
        if(i+1!=T) cout<<endl;
    }
    return 0;
}
//K+L-M*N+(O^P)*W/U/V*T+Q^J^A
