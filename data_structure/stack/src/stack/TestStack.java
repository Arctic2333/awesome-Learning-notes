package stack;

import java.util.Stack;

public class TestStack {
    private String teststring;
    private Stack<Character> stack;

    public TestStack(String teststring) {
        this.teststring = teststring;
        this.stack = new Stack<>();
    }

    public static void main(String[] args) {
        TestStack testStacknew = new TestStack("1*(2+3/4)-5*6");
        testStacknew.analysisString();
    }

    private void analysisString() {
        for (int i = 0; i < teststring.length(); i++) {
            char c = teststring.charAt(i);
            if (c == '+' || c == '-') {
                if (stack.isEmpty() || stack.peek() == '(') {
                    stack.push(c);
                } else {
                    while (!stack.isEmpty() && (stack.peek() == '*' || stack.peek() == '/' || stack.peek() == '+' || stack.peek() == '-')) {
                        System.out.print(stack.pop());
                    }
                    stack.push(c);
                }
            } else if (c == '*' || c == '/') {
                if (stack.isEmpty() || stack.peek() == '+' || stack.peek() == '-' || stack.peek() == '(') {
                    stack.push(c);
                } else {
                    while (!stack.isEmpty() && (stack.peek() == '/' || stack.peek() == '*')) {
                        System.out.print(stack.pop());
                    }
                    stack.push(c);
                }
            } else if (c == '(') {
                stack.push(c);
            } else if (c == ')') {
                char temp;
                while ((temp = stack.pop()) != '(') {
                    System.out.print(temp);
                }
            } else {
                System.out.print(c);
            }
        }
        if (!stack.isEmpty()) {
            while (!stack.isEmpty()) {
                System.out.print(stack.pop());
            }
        }
    }
}

