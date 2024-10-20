class Solution {
public:

    bool parseBoolExpr(string expression) {
        stack<char> s;

        for (char ch : expression) {
            if (ch == ',' || ch == '(')
                continue;
            
            if (ch == 't' || ch == 'f' || ch == '!' || ch == '&' || ch == '|') {
                s.push(ch);
            } 
            else if (ch == ')') {
                bool tFlag = false, fFlag = false;

                while (s.top() != '!' && s.top() != '&' && s.top() != '|') {
                    char top = s.top();
                    s.pop();
                    if (top == 't') tFlag = true;
                    if (top == 'f') fFlag = true;
                }
                
                char operatorChar = s.top();
                s.pop();

                if (operatorChar == '!') {
                    s.push(tFlag ? 'f' : 't');
                } else if (operatorChar == '&') {
                    s.push(fFlag ? 'f' : 't');
                } else if (operatorChar == '|') {
                    s.push(tFlag ? 't' : 'f');
                }
            }
        }
        return s.top() == 't';
    }
};