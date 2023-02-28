#include "Event.h"
#include <iostream>
#include <string.h>
#pragma warning(disable:4996)

Event::Event()
{
    this->title[0] = '\0';
    this->organizer[0] = '\0';
}

Event::Event(char title[256], char organizer[256], Time start_time, Time end_time)
{
    strcpy(this->title, title);
    strcpy(this->organizer, organizer);
    this->start_time = start_time;
    this->end_time = end_time;
}

void Event::set_start_time(Time time)
{
    this->start_time = time;
}

Time Event::get_start_time()
{
    return this->start_time;
}

void Event::set_end_time(Time time)
{
    this->end_time = time;
}

Time Event::get_duration()
{
    return end_time.get_diff(start_time);
}

void Event::display()
{
    std::cout << "Title: " << title << "\nOrganizer: " << organizer << "\nDuration: ";
    get_duration().display();
    std::cout << "\n";
}

bool Event::compare_events(Event event_to_compare)
{
    return (this->start_time.comp_time(event_to_compare.start_time) && this->end_time.comp_time(event_to_compare.end_time));
}