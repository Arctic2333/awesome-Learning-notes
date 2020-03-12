
public class StudentList {
    private student[] students;  // stdent 对象数组
    private int maxlength;  // 数组最大容量
    private int length;  // 数组的当前元素个数

    // 构造方法
    public StudentList(int maxlength) {
        initiate(maxlength);
    }

    private void initiate(int maxlength) {
        students = new student[maxlength];
        this.maxlength = maxlength;
    }

    public int length() {
        return length;
    }

    public int maxlength() {
        return maxlength;
    }

    public boolean insert(int index, student student) {  // (位置，元素)
        if (index < 0 || index > length) {
            System.out.println("插入位置出错");
            return false;
        }
        if (length + 1 > maxlength) {
            System.out.println("线性表已满");
        }
        length++;
        for (; index < length; index++) {
            student stunext = students[index];
            students[index] = student;
            student = stunext;
        }
        return true;
    }

    public boolean delete(int index) {
        if (index < 0 || index >= length) {
            System.out.println("删除位置有误");
            return false;
        }
        for (; index < length - 1; index++) {
            students[index] = students[index + 1];
        }
        length--;
        return true;
    }

    public int locate(int id) {
        for (int i = 0; i < length; i++) {
            if (students[i].getId() == id) {
                System.out.println("定位成功");
                return i;
            }
        }
        System.out.println("列表中查无此ID：");
        return id;
    }

    public boolean get(int i, student temp) {
        if (i < 0 || i > length - 1) {
            System.out.println("查找位置有误");
            return false;
        }
        temp = students[i];
        return true;
    }

    public void traverse() {
        if (length == 0) {
            System.out.println("表为空");
        }
        for (int i = 0; i < length; i++) {
            System.out.println(students[i].getId() + " " + students[i].getName() + " " + students[i].getGender()
                    + " " + students[i].getAge() + " " + students[i].getNativeplace());
        }
    }

    // copy 和 merge 没实现 要有两个表 在声明一个对象数组
}
