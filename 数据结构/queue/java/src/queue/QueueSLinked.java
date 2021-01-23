package queue;

public class QueueSLinked implements Queue {
    private SLNode front;
    private SLNode rear;
    private int size;

    public QueueSLinked() {
        front = new SLNode();
        rear = front;
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
    public void enqueue(Object e) {
        SLNode q = new SLNode(e, null);
        rear.setNext(q);
        rear = q;
        size++;
    }

    @Override
    public Object dequeue() throws QueueEmptyException {
        if (size < 1)
            throw new QueueEmptyException("ERROR,EMPTY QUEUE");
        SLNode p = front.getNext();
        front.setNext(p.getNext());
        size--;
        if (size < 1) rear = front;
        return p.getData();
    }

    @Override
    public Object peek() throws QueueEmptyException {
        if (size < 1)
            throw new QueueEmptyException("ERROR,EMPTY QUEUE");
        return front.getNext().getData();
    }
}
