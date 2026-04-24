#include <iostream>
#include <cstring>
using namespace std;


class Student
{
    private:
        char name[100];
        int id;
        int score;

        static const int passline = 80;
        static int count; // how many Student objects is created
    public:
        Student(): score(0)
        {
            name[0] = '\0';
            id = ++count;
        }
        Student(const char *name_in, int score_in): score(score_in)
        {
            strncpy(name, name_in, 99);
            name[99] = '\0';

            id = ++count;
        }
        Student(const Student &stu): score(stu.score)
        {
            strncpy(name, stu.name, 99);
            name[99] = '\0';

            id = ++count;
        }
        ~Student() {}
        
        void setScore(int s)
        {
            if (s < 0)
            {
                cout << "ERROR" << endl;
                return ;
            }

            score = s;
        }

        void show() const
        {
            int i = 0;

            cout << "name: "
                 << name << endl;
            cout << "id: "
                 << id << endl;
            cout << "score: "
                 << score << endl;

            if (score < passline)
                cout << "FAIL" << endl;
            else 
                cout << "PASS" << endl;
        }

        static void showCount()
        {
            cout << "There are " << count << " Student that are created" << endl;
        }
};

int Student::count = 0;

/*void test()
{
    Student s3("test",60);
    static Student s("test2",80);

    s3.show();
    s.show();
}*/ 

int main()
{
    char name1[] = "Alice";
    char name2[] = "Bob";
    char name3[] = "Carlie";

    Student::showCount(); // show be 0
    Student stu1(name1, 90);
    Student stu2(name2, 50);
    Student stu3(name3, 85);

    Student::showCount(); // show be 3
    stu1.show(); // PASS
    
    stu1.setScore(79); 
    Student::showCount(); // should be 1
    stu1.show(); // FAIL

    stu2.show();
    stu3.show();

    return 0;
}