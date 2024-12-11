#include "HealthPlan.h"

class DietPlan : public HealthPlan {
private:
    string dietType;
public:
    DietPlan(string type) : dietType(type) {}
    void displayPlan() const override {
        cout << "Diet Plan: " << dietType << endl;
    }
};
