package stack;

import stack.Stack;

public class StackArray implements Stack {
    private final int LEN = 8;  // 数组的默认大小
    private Object[] elements; // 数据元素数组
    private int top; // 栈顶指针

    public StackArray() {
        top = -1;
        elements = new Object[LEN];
    }

    // 返回栈的大小
    public int getSize() {
        return top + 1;
    }

    // 判断栈是否为空
    public boolean isEmpty() {
        return top < 0;
    }

    // 入栈
    public void push(final Object e) {
        if (getSize() >= elements.length)
            expandSpace();
        elements[++top] = e;
    }

    private void expandSpace() {
        final Object[] a = new Object[elements.length * 2];
        for (int i = 0; i < elements.length; i++)
            a[i] = elements[i];
        elements = a;
    }

    public Object pop() throws StackEmptyException {
        if (getSize() < 1)
            throw new StackEmptyException("��璇�锛�����涓虹┖");
        final Object obj = elements[top];
        elements[top--] = null;  // elements[top] = null;  top -= 1;
        return obj;
    }

    public Object peek() throws StackEmptyException {
        if (getSize() < 1)
            throw new StackEmptyException("错误，堆栈为空");
        return elements[top];
    }
}