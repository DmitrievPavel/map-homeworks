#include <iostream>
#include <mutex>

class Data {
public:
    Data(int value) : data(value) {}
    int getData() { return data; }
    void setData(int value) { data = value; }

    std::mutex mutex;

private:
    int data;
};

void swap1(Data& d1, Data& d2) {
    std::lock(d1.mutex, d2.mutex);

    int temp = d1.getData();
    d1.setData(d2.getData());
    d2.setData(temp);
    d1.mutex.unlock();
    d2.mutex.unlock();
}

void swap2(Data& d1, Data& d2) {

    std::scoped_lock lock(d1.mutex, d2.mutex);
    int temp = d1.getData();
    d1.setData(d2.getData());
    d2.setData(temp);
}

void swap3(Data& d1, Data& d2) {
    //std::unique_lock<std::mutex> lock1(d1.mutex, std::try_to_lock);
    //std::unique_lock<std::mutex> lock2(d2.mutex, std::try_to_lock);
    std::unique_lock<std::mutex> lock1(d1.mutex, std::defer_lock);
    std::unique_lock<std::mutex> lock2(d2.mutex, std::defer_lock);
    std::lock(lock1, lock2);

    int temp = d1.getData();
    d1.setData(d2.getData());
    d2.setData(temp);
}

int main() {
    Data d1(10);
    Data d2(20);

    std::cout << "Before swap: d1 = " << d1.getData() << ", d2 = " << d2.getData() << std::endl;
    swap3(d1, d2);
    std::cout << "After swap: d1 = " << d1.getData() << ", d2 = " << d2.getData() << std::endl;

    return 0;
}
