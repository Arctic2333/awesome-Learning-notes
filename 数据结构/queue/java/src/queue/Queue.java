package queue;

public interface Queue {
    public int getSize();

    public boolean isEmpty();

    public void enqueue(Object e);

    public Object dequeue() throws QueueEmptyException;

    public Object peek() throws QueueEmptyException;
}
