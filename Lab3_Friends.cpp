#include <windows.h>
#include "Header.h"
#include <iostream>

int main()
{
    SetConsoleOutputCP(1251); 
    SetConsoleCP(1251);       
    setlocale(LC_ALL, "Russian");

    std::cout << "Объектов Building в начале main: "
        << Building::getObjectCount() << "\n";

    testBuilding();
    testHiddenBuilding();
    testFriendBuilding();

    return 0;
}
