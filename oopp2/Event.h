#ifndef EVENT_H
#define EVENT_H
#include "Time.h"

class Event {
private:
    char title[256];
    char organizer[256];
    Time start_time;
    Time end_time;

public:

    Event();

    Event(char title[256], char organizer[256], Time start_time, Time end_time);

    void set_start_time(Time time);

    Time get_start_time();

    void set_end_time(Time time);

    Time get_duration();

    void display();

    bool compare_events(Event event_to_compare);

};

#endif
