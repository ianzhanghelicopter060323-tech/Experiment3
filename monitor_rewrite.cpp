#include <iostream>
using namespace std;


class Monitor
{
    private:
        static int incidentCount;
    public:
        void incident() 
        {
            incidentCount ++;
            cout << "incident() called" << endl;
        }
        static void print() 
        {
            cout << "dunction incident() is called " 
                 << incidentCount << " times" << endl;
        }
};

int Monitor::incidentCount = 0;

int main()
{
    Monitor m;
    Monitor m1;

    m.print();          // should be 0
    Monitor::print();   // should be 0
    m.incident();
    m.print();          // should be 1
    
    m.incident();
    m.print();          // should be 2

    m1.print();          // should be 2
    return 0;
}