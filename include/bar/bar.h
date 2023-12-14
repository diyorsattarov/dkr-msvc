#pragma once
#ifndef BAR_H
#define BAR_H

class Bar {
public:
    Bar();
    Bar(int value);
    ~Bar();
    int getValue() const;
    void setValue(int value);
    void doSomething();
private:
    int value_;
};

#endif // BAR_H
