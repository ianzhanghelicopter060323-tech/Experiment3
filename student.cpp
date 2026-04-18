# include <iostream>
#include <cstring>
using namespace std;

#define MAXSIZE 100


class Student
{
    public:
        // construct without param
        Student()
        {
            name[0] = '\0';
            score = 0;

            count ++;
            // id = former_id + 1
            id = ++former_id;
        }

        // construct with param
        Student(const char *name_in, /*int id_in,*/ int score_in)
        {
            // strcpy(name, name_in);
            strncpy(name, name_in ? name_in: "", MAXSIZE-1);
            name[MAXSIZE-1] = '\0';
            // id = id_in;
            score = score_in;

            count ++;
            // id = former_id + 1
            id = ++former_id;
        }

        // copy construct
        Student(const Student &stu)
        {
           std::strncpy(name, stu.name, MAXSIZE - 1);
            name[MAXSIZE - 1] = '\0';

            score = stu.score;

            count ++;// id = former_id + 1
            id = ++former_id;
        }

        // deconstruct
        ~Student()
        {
            cout<<"DECONSTRUCT PROCESSED"<<endl;
        }


        // setting score
        void setScore(int s)
        {
            score = s;
        }


        // show basic information and passing passline or not
        void show() const
        {
            // name output
            int i = 0;
            cout<<"Student name:";
            while (name[i] != '\0')
            {
                cout<<name[i];
                i ++;
            }
            cout<<'\n';

            // other infornmation
            cout<<"Student id:"
                <<id<<endl;
            cout<<"Student score:"
                <<score<<endl;

            if (score >= passline)
            {
                cout<<"PASS!"<<endl;
            }
            else
            {
                cout<<"FAILED!"<<endl;
            }
        }

        // show how many objects are created
        static void showCount();

    private:
        char name[MAXSIZE]; 
        int id; 
        int score;

        static int former_id;
        static const int passline = 80; // score < passline -> failed
        static int count; // count how many student objects have been created
};

int Student::count = 0;
int Student::former_id = 0; 
void Student::showCount()
{
    cout<<"there are "<<count<<" objects have been created"<<endl;
}


// test advaced function
void test()
{
    char name_test1[] = "test1";
    char name_test2[] = "test2";

    Student s1(name_test1, 60);
    static Student s2(name_test2,80);

s1.show();
s2.show();
}


int main()
{
    char name1[] = "Alice";
    // int id1 = 1145;
    int score1 = 90;

    char name2[] = "Bob";
    // int id2 = 1919;
    int score2 = 60;

    // call test function for advanced feature test
    test();
    test();

    Student stu1(name1, score1);
    stu1.show();
    stu1.showCount();

    cout<<"\n";

    Student stu2(name2, score2);
    stu2.show();
    stu2.showCount();

    // trigger copy constructor
    Student stu3 = stu1; 
    stu3.show();
    Student::showCount();
    return 0;
}
