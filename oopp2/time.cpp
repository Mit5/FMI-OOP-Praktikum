#include "Time.h"
#include <iostream>

    Time::Time()
    {
        this->hour = 0;
        this->minute = 0;
        this->second = 0;
    }

    Time::Time(int hour, int minute, int second)
    {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }

    void Time::set_hour(int hour)
    {
        if (hour >= 1 && hour <= 23)
        {
            this->hour = hour;
        }
    }

    void Time::set_minute(int minute)
    {
        this->minute = minute;
    }

    void Time::set_second(int second)
    {
        this->second = second;
    }

    Time Time::get_diff(const Time other_time) const
    {
        Time result;
        result.hour = this->hour - other_time.hour;
        result.minute = this->minute - other_time.minute;
        result.second = this->second - other_time.second;
        return result;
    }

    bool Time::comp_time(const Time other_time)
    {
        return (this->hour == other_time.hour && this->minute == other_time.minute && this->second == other_time.second);
    }

    void Time::add_time(const Time other_time)
    {
        this->hour += other_time.hour;
        this->minute += other_time.minute;
        this->second += other_time.second;
    }

    void Time::display()
    {
        std::cout << hour << ":" << minute << ":" << second << "\n";
    }