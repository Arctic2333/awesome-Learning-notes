package stack;

public interface Stack {
    public int getSize(); // 返回堆栈的大小

    public boolean isEmpty(); // 判断栈空

    public void push(Object e);  // 入栈

    public Object pop() throws StackEmptyException;  // 栈顶元素出栈

    public Object peek() throws StackEmptyException;  // 取栈顶元素


}