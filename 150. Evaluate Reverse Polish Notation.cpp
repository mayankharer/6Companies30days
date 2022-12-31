class Solution
{
public:
    int evalRPN(vector<string> &v)
    {
        stack<int> s;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == "+" || v[i] == "-" || v[i] == "*" || v[i] == "/")
            {
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();
                switch (v[i][0])
                {
                case '+':
                    s.push(op1 + op2);
                    break;
                case '-':
                    s.push(op1 - op2);
                    break;
                case '*':
                    s.push(op1 * op2);
                    break;
                case '/':
                    s.push(op1 / op2);
                    break;
                }
            }
            else
            {
                s.push(stoi(v[i]));
            }
        }
        return s.top();
    }
};