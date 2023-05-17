#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;
int seconds, minutes, hours;
void rt_clock() {
    time_t total_seconds = time(0);
    struct tm* ct = localtime(&total_seconds);

    seconds = ct -> tm_sec;
    minutes = ct -> tm_min;
    hours = ct -> tm_hour;
}

int main( )
{
    int sub_second = -1;

    system("CLS");

    while(true){
        
        string str;

        rt_clock();
        
        //converting it into 12 hour format
        if(hours>=12)
            str = "PM";
        else
            str = "AM";
        hours = hours > 12? hours - 12: hours;  
        
        //printing the result
        if (sub_second != seconds) {
            //system("CLS");
            cout <<"\33[2K\r " << (hours<10?"0":"") << hours <<":" << (minutes<10?"0":"") << minutes << ":" << (seconds<10?"0":"") << seconds << " " << str;
            sub_second = seconds;
        }
    }
    return 0;
}