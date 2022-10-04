// lt20: Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/
#include <stack>
#include <string>

// Checks if every open brackets in s have matched close brackets.
// e.g. {} [] (), [{}()[()]]
bool isValid(std::string s) {
  std::stack<char> stack;
  for (char ch : s) {
    // get a open bracket, push the next close bracket we are looking for
    if (ch == '(')
      stack.push(')');
    else if (ch == '[')
      stack.push(']');
    else if (ch == '{')
      stack.push('}');
    // get a close bracket, check if it's what we are looking for
    else if (ch == ')' || ch == ']' || ch == '}') {
      if (stack.empty() || stack.top() != ch) return false;
      stack.pop();
    }
  }
  // check if there is still unmatched open brackets
  return stack.empty();
}
