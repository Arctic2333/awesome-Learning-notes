package queue;

public class QueueArray implements Queue {
    private static final int CAP = 7;  // 队列默认长度
    private Object[] elements;
    private int capacity;  // 数组的大小
    private int front;  // 队首指针
    private int rear; // 队尾指针

    public QueueArray() {
        this(CAP);
    }

    public QueueArray(int cap) {
        capacity = cap + 1;
        elements = new Object[capacity];
        front = rear = 0;
    }

    @Override
    public int getSize() {
        return (rear - front + capacity) % capacity;
    }

    @Override
    public boolean isEmpty() {
        return front == rear;
    }

    @Override
    public void enqueue(Object e) {
        if (getSize() == capacity - 1)
            expandSpace();
        elements[rear] = e;
        rear = (rear + 1) % capacity;
    }

    private void expandSpace() {
        Object[] a = new Object[elements.length * 2];
        int i = front;
        int j = 0;
        while (i != rear) {
            a[j++] = elements[i];
            i = (i + 1) % capacity;
        }
        elements = a;
        capacity = elements.length;
        front = 0;
        rear = j;
    }

    @Override
    public Object dequeue() throws QueueEmptyException {
        if (isEmpty())
            throw new QueueEmptyException("错误队列为空");
        Object obj = elements[front];
        elements[front] = null;
        front = (front + 1) % capacity;
        return obj;
    }

    @Override
    public Object peek() throws QueueEmptyException {
        if (isEmpty())
            throw new QueueEmptyException("错误队列为空");
        return elements[front];
    }
}
