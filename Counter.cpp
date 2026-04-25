#include <iostream>
using namespace std;


class Counter
{
    private:
        static int total; // how many times add() has been called
    public:
        void add()
        {
            cout << "add() called" << endl;
            total ++;
        }

        static void showTotal()
        {
            cout << "add() is called " << total << " times in total." << endl;
        }
};

int Counter::total = 0;

int main()
{
    Counter::showTotal(); // should be 0
    
    Counter c1;
    Counter c2;

    c1.add();
    c1.add();
    c2.add();
    c2.add();

    Counter::showTotal(); // should be 4

    return 0;
}