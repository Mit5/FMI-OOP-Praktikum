#include "VendingMachine.h"

#pragma once

class VendingController {
    VendingMachine* vendingMachineList;
    int numMachines;
    int capacity;
    void resize();

public:
    //include big 4-5-6 
    void addVendingMachine(VendingMachine machine);
    void getAddressOfMachine(int machineID);
    void getInventoryOfMachine(int machineID);
    void sellProductInMachine(int machineID, char* product);
    void restockProductInMachine(int machineID, char* product);
    void seeWarningMsgForMachine(int machineID);
};
