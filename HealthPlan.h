#pragma once
#ifndef HEALTHPLAN_H
#define HEALTHPLAN_H

#include <iostream>
#include <string>
using namespace std;

// 추상 클래스
class HealthPlan {
public:
    virtual void displayPlan() const = 0; // 가상 함수
    virtual ~HealthPlan() {}
};

// 템플릿 클래스
template <typename T>
class GenericPlan {
private:
    T planDetail;
public:
    GenericPlan(T detail) : planDetail(detail) {}
    void show() {
        cout << "Plan Detail: " << planDetail << endl;
    }
};

#endif
