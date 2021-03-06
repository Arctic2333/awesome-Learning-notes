
public class StudentList {
    private Student[] Students;  // student 对象数组
    private Student[] students1;
    private int maxlength;  // 数组最大容量
    private int length;  // 数组的当前元素个数

    // 构造方法
    public StudentList(int maxlength) {
        initiate(maxlength);
    }

    private void initiate(int maxlength) {
        Students = new Student[maxlength];
        students1 = new Student[maxlength];
        this.maxlength = maxlength;
    }

    public int length() {
        return length;
    }

    public int maxlength() {
        return maxlength;
    }

    public boolean insert(int index, Student student) {  // (位置，元素)
        if (index < 0 || index > length) {
            System.out.println("插入位置出错");
            return false;
        }
        if (length + 1 > maxlength) {
            System.out.println("线性表已满");
        }
        length++;
        for (; index < length; index++) {
            Student stunext = Students[index];
            Students[index] = student;
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
            Students[index] = Students[index + 1];
        }
        length--;
        return true;
    }

    public int locate(int id) {
        for (int i = 0; i < length; i++) {
            if (Students[i].getId() == id) {
                System.out.println("定位成功");
                return i;
            }
        }
        System.out.println("列表中查无此ID：");
        return id;
    }

    public boolean get(int i, Student temp) {
        if (i < 0 || i > length - 1) {
            System.out.println("查找位置有误");
            return false;
        }
        temp = Students[i];
        return true;
    }

    public void traverse() {
        if (length == 0) {
            System.out.println("表为空");
        }
        for (int i = 0; i < length; i++) {
            System.out.println(Students[i].getId() + " " + Students[i].getName() + " " + Students[i].getGender()
                    + " " + Students[i].getAge() + " " + Students[i].getNativeplace());
        }
    }

    // copy 和 merge 没实现 要有两个表 在声明一个对象数组
    public void copy() {
        if (length == 0) {
            System.out.println("表为空");
        }
        for (int i = 0; i < length; i++) {
            students1[i] = Students[i];
        }
    }

    public boolean merge() {
        if (length == 0) {
            System.out.println("表为空");
        }
        int len = length;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (students1[i].getId() == Students[j].getId()) {
                    return false;
                }
                Students[length + 1] = students1[j];
                length++;
            }
        }
        return true;
    }
}
