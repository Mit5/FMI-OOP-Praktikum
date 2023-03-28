#include<iostream>
#pragma once
struct Inventory {
    unsigned int salty;
    unsigned int sweet;
    unsigned int drinks;

    void changeSalty(int quantity);
    void changeSweets(int quantity);
    void changeDrinks(int quantity);
    void print();
};

class VendingMachine {
    int id;
    char* address;
    Inventory inventory;
    char** warningMessages;
    int numWarningMsgs;
    int capacity;

public:
    int getId();
    VendingMachine(); //default constructor
    VendingMachine(char* address, Inventory inventory); //default constructor
    VendingMachine(VendingMachine const& other); // copy constructor
    VendingMachine(VendingMachine&& other); // move constructor
    VendingMachine& operator=(VendingMachine const& other);
    ~VendingMachine();

    //include other needed methods
};