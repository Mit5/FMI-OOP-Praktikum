// oopp1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Time.h"
#include "Event.h"


using namespace std;

int main()
{
    int n;
    cin >> n;
    Time sumTime;
    for (int i = 0; i < n; i++)
    {
        char title[256], organizer[256];
        int start_time_hour, start_time_minute, start_time_second, end_time_hour,end_time_minute, end_time_second;
        cout << "\nEvent title >\n";
        cin.ignore();
        cin.getline(title, 256);

        cout << "Event oragniser >\n";
        cin.ignore();
        cin.getline(organizer, 256);

        cout << "Start time >\n";
        cin >> start_time_hour >> start_time_minute >> start_time_second;
        Time start_time(start_time_hour, start_time_minute, start_time_second);

        cout << "End time >\n";
        cin >> end_time_hour >> end_time_minute >> end_time_second;
        Time end_time(end_time_hour, end_time_minute, end_time_second);
        
        Event myEvent(title, organizer, start_time, end_time);

        myEvent.display();
        sumTime.add_time(myEvent.get_duration());
    }
    sumTime.display();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
