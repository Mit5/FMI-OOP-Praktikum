#include "Time.h"
#include <iostream>

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    Time()
    {
        this->hour = 0;
        this->minute = 0;
        this->second = 0;
    }

    Time(int hour, int minute, int second)
    {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }

    void set_hour(int hour)
    {
        if (hour >= 1 && hour <= 23)
        {
            this->hour = hour;
        }
    }

    void set_minute(int minute)
    {
        this->minute = minute;
    }

    void set_second(int second)
    {
        this->second = second;
    }

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
        std::cout << hour << ":" << minute << ":" << second << "\n";
    }
};