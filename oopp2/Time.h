#ifndef TIME_H
#define TIME_H

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    Time();

    Time(int hour, int minute, int second);

    void set_hour(int hour);

    void set_minute(int minute);

    void set_second(int second);

    Time get_diff(const Time other_time) const;

    bool comp_time(const Time other_time);

    void add_time(const Time other_time);

    void display();
};

#endif // !TIME_H

