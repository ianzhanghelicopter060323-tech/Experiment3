#include <iostream>
using namespace std;


class Monitor
{
    public:

        // incident function to be called
        void incident()
        {
             cout<<"FUNCTION INCIDENT CALLED"<<endl;
            incidentCall_count++;
        }

        // print how many times incident function is called
        // static function, can be called without any object
        static void print()
        {
            cout<<"incident has been called: "<<incidentCall_count<<endl;
        }

        private:
            static int incidentCall_count;
};

//
// static data incidentCall_count initialize
int Monitor::incidentCall_count = 0;


int main()
{
    // call print() without object
    Monitor::print();
    Monitor::print();

    Monitor m1, m2, m3;

    // call incident() once
    m1.incident();
    m1.print();

    // call incident() twice
    m2.incident();
    m2.print();

    // call incident() three times
    m3.incident();
    m3.print();

    return 0;
}