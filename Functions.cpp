#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <cstring>
#include <iostream>

// Определения статических полей
int Building::objectCount = 0;
int HiddenBuilding::objectCount = 0;
int FriendBuilding::objectCount = 0;

// ================= Класс Building =================
Building::Building(const char* addr, int storeys) {
    address = new char[std::strlen(addr) + 1];
    std::strcpy(address, addr);
    storeyCount = storeys;
    quarantineFlag = false;
    objectCount++;
}

Building::Building(const Building& other) {
    address = new char[std::strlen(other.address) + 1];
    std::strcpy(address, other.address);
    storeyCount = other.storeyCount;
    quarantineFlag = other.quarantineFlag;
    objectCount++;
}

Building::~Building() {
    delete[] address;
    objectCount--;
}

void Building::addStoreys(int count) {
    if (count > 0) {
        storeyCount += count;
    }
}

void Building::quarantine() {
    quarantineFlag = true;
}

const char* Building::getAddress() const { return address; }
int Building::getStoreyCount() const { return storeyCount; }
bool Building::isQuarantined() const { return quarantineFlag; }
int Building::getObjectCount() { return objectCount; }

// ================= Класс HiddenBuilding =================
HiddenBuilding::HiddenBuilding(const char* addr, int storeys) {
    address = new char[std::strlen(addr) + 1];
    std::strcpy(address, addr);
    storeyCount = storeys;
    quarantineFlag = false;
    objectCount++;
}

HiddenBuilding::~HiddenBuilding() {
    delete[] address;
    objectCount--;
}

HiddenBuilding* HiddenBuilding::create(const char* addr, int storeys) {
    return new HiddenBuilding(addr, storeys);
}

void HiddenBuilding::destroy(HiddenBuilding* obj) {
    delete obj;
}

void HiddenBuilding::addStoreys(int count) {
    if (count > 0) {
        storeyCount += count;
    }
}

void HiddenBuilding::quarantine() {
    quarantineFlag = true;
}

const char* HiddenBuilding::getAddress() const { return address; }
int HiddenBuilding::getStoreyCount() const { return storeyCount; }
bool HiddenBuilding::isQuarantined() const { return quarantineFlag; }
int HiddenBuilding::getObjectCount() { return objectCount; }

// ================= Класс FriendBuilding =================
FriendBuilding::FriendBuilding(const char* addr, int storeys) {
    address = new char[std::strlen(addr) + 1];
    std::strcpy(address, addr);
    storeyCount = storeys;
    quarantineFlag = false;
    objectCount++;
}

FriendBuilding::~FriendBuilding() {
    delete[] address;
    objectCount--;
}

void FriendBuilding::addStoreys(int count) {
    if (count > 0) {
        storeyCount += count;
    }
}

void FriendBuilding::quarantine() {
    quarantineFlag = true;
}

const char* FriendBuilding::getAddress() const { return address; }
int FriendBuilding::getStoreyCount() const { return storeyCount; }
bool FriendBuilding::isQuarantined() const { return quarantineFlag; }
int FriendBuilding::getObjectCount() { return objectCount; }

// Дружественные функции
FriendBuilding* createFriendBuilding(const char* addr, int storeys) {
    return new FriendBuilding(addr, storeys);
}

void destroyFriendBuilding(FriendBuilding* obj) {
    delete obj;
}

// ================= Тестовые функции =================
void testBuilding() {
    std::cout << "\n--- Класс Building ---\n";
    std::cout << "Объектов в начале теста: " << Building::getObjectCount() << "\n";

    Building arr[3] = {
        Building("Ленина 1", 5),
        Building("Мира 2", 9),
        Building("Гагарина 3", 12)
    };
    std::cout << "После статического массива: " << Building::getObjectCount() << "\n";

    Building* p = new Building("Советская 4", 7);
    std::cout << "После динамического объекта: " << Building::getObjectCount() << "\n";

    p->addStoreys(2);
    p->quarantine();

    std::cout << "Динамический объект: " << p->getAddress()
        << ", этажей=" << p->getStoreyCount()
        << ", карантин=" << p->isQuarantined() << "\n";

    delete p;
    std::cout << "После удаления динамического объекта: " << Building::getObjectCount() << "\n";
}

void testHiddenBuilding() {
    std::cout << "\n--- Класс HiddenBuilding ---\n";
    std::cout << "Объектов в начале: " << HiddenBuilding::getObjectCount() << "\n";

    HiddenBuilding* h = HiddenBuilding::create("Пушкина 5", 4);
    std::cout << "После создания: " << HiddenBuilding::getObjectCount() << "\n";

    h->addStoreys(3);
    h->quarantine();

    std::cout << "Объект: " << h->getAddress()
        << ", этажей=" << h->getStoreyCount()
        << ", карантин=" << h->isQuarantined() << "\n";

    HiddenBuilding::destroy(h);
    std::cout << "После уничтожения: " << HiddenBuilding::getObjectCount() << "\n";
}

void testFriendBuilding() {
    std::cout << "\n--- Класс FriendBuilding ---\n";
    std::cout << "Объектов в начале: " << FriendBuilding::getObjectCount() << "\n";

    FriendBuilding* f = createFriendBuilding("Кирова 6", 2);
    std::cout << "После создания: " << FriendBuilding::getObjectCount() << "\n";

    f->addStoreys(5);
    f->quarantine();

    std::cout << "Объект: " << f->getAddress()
        << ", этажей=" << f->getStoreyCount()
        << ", карантин=" << f->isQuarantined() << "\n";

    destroyFriendBuilding(f);
    std::cout << "После уничтожения: " << FriendBuilding::getObjectCount() << "\n";
}