public class StuLinkList {  // 定义链表类 StuLinkList
    // 链表头节点
    private StuNode head;
    // 链表尾结点
    private StuNode last;  // 只在尾插法中用到

    // 构造方法，新建链表将传递进来的结点对象设置为链表头结点
    public StuLinkList(StuNode hd) {
        head = hd;
        last = hd;
    }

    // 建表的两种方法还没写 （头插法、尾插法）
    public void create_list_head(StuNode p) {  // 头插法
        p.setNextlink(head.getNextlink());
        head.setNextlink(p);
    }

    public void create_list_last(StuNode p) {  // 尾插法
        last.setNextlink(p);
        p.setNextlink(null);
        last = p;
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
