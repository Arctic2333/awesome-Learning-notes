public class StuLinkList {  // 定义链表类 StuLinkList
    // 链表头节点
    private StuNode head;

    // 构造方法，新建链表将传递进来的结点对象设置为链表头结点
    public StuLinkList(StuNode hd) {
        head = hd;
    }

    public void insertAfter(StuNode p, StuNode s) {
        s.setNextlink(p.getNextlink());
        p.setNextlink(s);
    }

    public void insertBefore(StuNode p, StuNode s) {
        if (head == null)
            return;
        StuNode q = head;
        while (q.getNextlink() != null) {
            if (q.getNextlink() == p) {
                q.setNextlink(s);
                s.setNextlink(p);
                break;
            }
            q = q.getNextlink();
        }
    }

    public void delete(StuNode p) {
        if (head == null)
            return;
        StuNode q = head;
        while (q.getNextlink() != null) {
            if (q.getNextlink() == p) {
                q.setNextlink(p.getNextlink());
            }
            q = q.getNextlink();
        }
    }


}
