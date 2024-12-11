#include "HealthPlan.h"

class ExercisePlan : public HealthPlan {
private:
    string exerciseType;
public:
    ExercisePlan(string type) : exerciseType(type) {}
    void displayPlan() const override {
        cout << "Exercise Plan: " << exerciseType << endl;
    }
};
