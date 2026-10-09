#pragma once

class Building {
private:
    char* address;
    int storeyCount;
    bool quarantineFlag;
    static int objectCount;

public:
    Building(const char* addr, int storeys);
    Building(const Building& other);

    ~Building();

    void addStoreys(int count);
    void quarantine();

    const char* getAddress() const;
    int getStoreyCount() const;
    bool isQuarantined() const;
    static int getObjectCount();
};

class HiddenBuilding {
private:
    char* address;
    int storeyCount;
    bool quarantineFlag;
    static int objectCount;

    HiddenBuilding(const char* addr, int storeys);
    ~HiddenBuilding();

public:
    static HiddenBuilding* create(const char* addr, int storeys);
    static void destroy(HiddenBuilding* obj);

    void addStoreys(int count);
    void quarantine();

    const char* getAddress() const;
    int getStoreyCount() const;
    bool isQuarantined() const;
    static int getObjectCount();
};

class FriendBuilding {
    friend FriendBuilding* createFriendBuilding(const char* addr, int storeys);
    friend void destroyFriendBuilding(FriendBuilding* obj);

private:
    char* address;
    int storeyCount;
    bool quarantineFlag;
    static int objectCount;

    FriendBuilding(const char* addr, int storeys);
    ~FriendBuilding();

public:
    void addStoreys(int count);
    void quarantine();

    const char* getAddress() const;
    int getStoreyCount() const;
    bool isQuarantined() const;
    static int getObjectCount();
};

// Тестовые функции
void testBuilding();
void testHiddenBuilding();
void testFriendBuilding();
