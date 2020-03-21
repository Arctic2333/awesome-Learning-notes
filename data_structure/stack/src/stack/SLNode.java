package stack;

public class SLNode {
    private Object data;
    private SLNode nextLink;

    public SLNode(Object e, SLNode top) {
        this.data = e;
        this.nextLink = top;
    }

    public Object getData() {
        return this.data;
    }

    public SLNode getNext() {
        return this.nextLink;
    }
}
