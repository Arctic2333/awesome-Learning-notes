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

    public void converse() {  //  逆置操作，单链表头插法建表，数据顺序是逆序
        StuNode p = head.getNextlink();
        // 设置表头后的一个元素的 引用域为空
        if (p == null)
            return;
        StuNode q = p.getNextlink();
        if (q == null)
            return;
        p = q;
        q = p.getNextlink();
        p.setNextlink(head.getNextlink());
        head.setNextlink(p);
        p.getNextlink().setNextlink(null);
        //
        while (q != null) {
            p = q;
            q = p.getNextlink();
            p.setNextlink(head.getNextlink());
            head.setNextlink(p);
        }
    }

    public int length() {
        StuNode p = head;
        int len = 0;
        while (p.getNextlink() != null) {
            p = p.getNextlink();
            len++;
        }
        return len;
    }
}
