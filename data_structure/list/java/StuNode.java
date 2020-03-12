public class StuNode {  // 链表节点
    // 数据域为学生对象
    private Student student;
    // 引用域指向下一个节点
    private StuNode nextlink;

    public Student getStudent() {
        return student;
    }

    public void setStudent(Student student) {
        this.student = student;
    }

    public StuNode getNextlink() {
        return nextlink;
    }

    public void setNextlink(StuNode nextlink) {
        this.nextlink = nextlink;
    }
}
