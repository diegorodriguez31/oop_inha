#include <iostream>
using namespace std;

class Time {
    int m_hour;
    int m_minute;
    int m_second;

public:
    bool setTime(int h, int m, int s) {
        // Max hour is 23, max minute is 59, max second is 59
        // Set 0 if not respected
        if (h >= 0 && h <= 23 && m >= 0 && m <= 59 && s >= 0 && s <= 59) {
            m_hour = h;
            m_minute = m;
            m_second = s;
            return true;
        } else {
            m_hour = 0;
            m_minute = 0;
            m_second = 0;
            return false;
        }
    }

    void print() {
        cout << m_hour << ":" << m_minute << ":" << m_second << endl;
    }

    void isValid(bool validTime) {
        if (validTime) {
            cout << "Valid time" << endl;
        } else {
            cout << "Invalid time" << endl;
        }
    }
    
    void addTime(int h, int m, int s) {
        // Add time to current time
        m_second += s;
        m_minute += m;
        m_hour += h;
        // While second is greater than 59, add 1 to minute and subtract 60 from second
        while (m_second > 59) {
            m_minute += 1;
            m_second -= 60;
        }
        // While minute is greater than 59, add 1 to hour and subtract 60 from minute
        while (m_minute > 59) {
            m_hour += 1;
            m_minute -= 60;
        }
        // While hour is greater than 23, subtract 24 from hour
        while (m_hour > 23) {
            m_hour -= 24;
        }
    }
};

int main() {
    Time time;
    bool validTime = time.setTime(10, 20, 30);
    time.isValid(validTime);
    time.print();
    validTime = time.setTime(20, 30, 45);
    time.isValid(validTime);
    time.print();
    // Test all wrong possibilities
    validTime = time.setTime(25, 30, 45);
    time.isValid(validTime);
    time.print();
    validTime = time.setTime(20, 60, 45);
    time.isValid(validTime);
    time.print();
    validTime = time.setTime(20, 30, 60);
    time.isValid(validTime);
    time.print();
    validTime = time.setTime(20, 30, -1);
    time.isValid(validTime);
    time.print();

    // Set new time and add time
    cout << endl << "New time!!" << endl;
    Time newTime;
    newTime.setTime(10, 20, 30);
    newTime.print();
    newTime.addTime(1, 1, 1);
    newTime.print();
    newTime.addTime(0, 30, 120);
    newTime.print();
    newTime.addTime(0, 0, 3600);
    newTime.print();
    newTime.addTime(0, 0, 64323);
    newTime.print();
    return 0;
}