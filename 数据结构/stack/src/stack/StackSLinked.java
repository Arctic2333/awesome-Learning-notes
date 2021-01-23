package stack;

import stack.SLNode;
import stack.Stack;
import stack.StackEmptyException;

public class StackSLinked implements Stack {
    private SLNode top;
    private int size;

    public StackSLinked() {
        top = null;
        size = 0;
    }

    @Override
    public int getSize() {
        return size;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public void push(final Object e) {
        @SuppressWarnings("UnnecessaryLocalVariable") final SLNode q = new SLNode(e, top);
        top = q;
        size++;
    }

    @Override
    public Object pop() throws StackEmptyException {
        if (size < 1)
            throw new StackEmptyException("错误，堆栈为空");
        final Object obj = top.getData();
        top = top.getNext();
        size--;
        return obj;
    }

    @Override
    public Object peek() throws StackEmptyException {
        if(size < 1)
            throw new StackEmptyException("错误，堆栈为空");
        return top.getData();
    }
}
