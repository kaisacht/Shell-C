#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;
int seconds, minutes, hours;
void rt_clock() {
    time_t total_seconds = time(0);
    struct tm* ct = localtime(&total_seconds);

    seconds = ct -> tm_sec;
}

int main( )
{
    int sub_second = -1;
    int a=22;
    while(true){
        
        string str;

        rt_clock();
     
        if (sub_second != seconds) {
            //system("CLS");
            cout <<"\33[2K\r " << a;
            a--;
            sub_second = seconds;
        }
    }
    return 0;
}