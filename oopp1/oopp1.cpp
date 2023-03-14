// oopp1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Time {
    int hour;
    int minute;
    int second;

    Time get_diff(const Time other_time) const
    {
        Time result;
        result.hour = this->hour - other_time.hour;
        result.minute = this->minute - other_time.minute;
        result.second = this->second - other_time.second;
        return result;
    }

    void add_time(const Time other_time)
    {
        this->hour += other_time.hour;
        this->minute += other_time.minute;
        this->second += other_time.second;
    }

    void display()
    {
        cout << hour << ":" << minute << ":" << second << "\n";
    }
};

struct Event {
    char title[256];
    char organizer[256];
    Time start_time;
    Time end_time;

    Time get_duration()
    {
        return end_time.get_diff(start_time);
    }

    void display()
    {
        cout << "Title: " << title << "\nOrganizer: " << organizer << "\nDuration: ";
        get_duration().display();
        cout << "\n";
    }

};


//int main()
//{
//    int n;
//    cin >> n;
//    Time sumTime = { 0,0,0 };
//    for (int i = 0; i < n; i++)
//    {
//        Event myEvent;
//        Time start_time, end_time;
//        cout << "\nEvent title >\n";
//        cin.ignore();
//        cin.getline(myEvent.title, 256);
//        cout << "Event oragniser >\n";
//        cin.ignore();
//        cin.getline(myEvent.organizer, 256);
//        cout << "Start time >\n";
//        cin >> start_time.hour >> start_time.minute >> start_time.second;
//        myEvent.start_time = start_time;
//        cout << "End time >\n";
//        cin >> end_time.hour >> end_time.minute >> end_time.second;
//        myEvent.end_time = end_time;
//        myEvent.display();
//        sumTime.add_time(myEvent.get_duration());
//    }
//    sumTime.display();
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
