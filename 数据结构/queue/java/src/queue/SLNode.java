package queue;

public class SLNode {
    public Object data;
    public SLNode next;

    public SLNode() {
        this(null,null);
    }

    public SLNode(Object obj, SLNode next) {
        this.data = obj;
        this.next = next;
    }

    public void setNext(SLNode p){
        this.next = p;
    }

    public SLNode getNext(){
        return this.next;
    }

    public Object getData(){
        return this.data;
    }
}
