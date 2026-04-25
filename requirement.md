# monitor.cpp 要求
1. 创建一个```cpp Monitor```类,它能知道成员函数```cpp incident()```被调用了几次.
2. 增加一个成员函数```cpp print()```,显示```cpp incident()```被调用的次数,
3. 并能在没有定义任何```cpp Monitor```类的对象时，就显示次数的初始值
4. 提示：使用静态成员（数据和函数）

# student.cpp要求
## 基础功能（100）
1. 私有数据成员：```cpp char name[100]; int id; int score;```
2. 有常静态成员：```cpp static const int passline;```（为80分）
3. 有静态成员：```cpp static int count; ```用于记录有多少个学生类对象被创建了

## 功能：
1. 构造函数，拷贝构造函数，析构函数
2. 设置成绩```cpp void setScore(int s);```
3. 成绩查询```cpp void show()```（输出基本信息，显示是否通过）；
4. 静态成员函数显示对象数```cpp static void showCount()```
5. 设计main函数测试
## 附加功能（120）：可尝试根据对象生成的顺序决定id值，这是可以思考是否需要增加静态数据成员来满足该功能
附加功能测试建议调用以下函数两次：
```cpp
void test()
{
    Stu s3("test",60);
    static Stu s("test2",80);

    s3.show();
    s.show();
} 
```

# 多文件（Point.cpp Point.h Rectangle.cpp Rectangle.h Triangle.cpp Triangle.h）要求
在一个工程中创建第2次上机的Rectangle类和第3次上机的Triangle类,他们共享一个Point类（都有Point类的成员）,写成多文件格式,Rectangle类是Point类的友元类,尝试在成员函数中直接访问Point类的私有成员.

**多文件提交格式：**
```cpp 
//Point.h (文件名)

代码

//Point.cpp(文件名）

代码

…… 
```
# friend.cpp 要求
## 一、实验要求

1. 定义一个 `Point` 类，表示二维平面上的点。

2. `Point` 类有两个私有数据成员：

```cpp
double x;
double y;
```

3. 为 `Point` 类定义构造函数：

```cpp
Point(double x = 0, double y = 0);
```

4. 定义一个 `Segment` 类，表示线段。

5. `Segment` 类中包含两个 `Point` 对象：

```cpp
Point p1;
Point p2;
```

6. 将 `Segment` 类声明为 `Point` 类的友元类，使 `Segment` 的成员函数可以直接访问 `Point` 的私有成员 `x` 和 `y`。

7. `Segment` 类需要实现以下成员函数：

```cpp
Segment(Point a, Point b);
double length() const;
void midpoint() const;
void show() const;
```

其中：

- `length()`：计算线段长度；
- `midpoint()`：输出线段中点坐标；
- `show()`：输出两个端点坐标。

8. 在 `main()` 函数中创建两个 `Point` 对象，再创建一个 `Segment` 对象，测试所有成员函数。