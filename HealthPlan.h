#pragma once
#ifndef HEALTHPLAN_H
#define HEALTHPLAN_H

#include <iostream>
#include <string>
using namespace std;

// �߻� Ŭ����
class HealthPlan {
public:
    virtual void displayPlan() const = 0; // ���� �Լ�
    virtual ~HealthPlan() {}
};

// ���ø� Ŭ����
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
