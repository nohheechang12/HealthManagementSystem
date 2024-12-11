#include "HealthPlan.h"
#include "ExercisePlan.cpp"
#include "DietPlan.cpp"
#include <fstream>
#include <vector>
#include <exception>

void saveToFile(const string& filename, const string& data) {
    ofstream file(filename);
    if (!file) throw runtime_error("File open error!");
    file << data;
    file.close();
}

string loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) throw runtime_error("File read error!");
    string data;
    getline(file, data);
    file.close();
    return data;
}

int main() {
    try {
        // ��ü �迭 �� ������ ���
        vector<HealthPlan*> plans;
        plans.push_back(new ExercisePlan("Running 30 minutes"));
        plans.push_back(new DietPlan("Low-carb diet"));

        // ���
        for (const auto& plan : plans) {
            plan->displayPlan();
        }

        // ���� �����
        saveToFile("plans.txt", "Running 30 minutes, Low-carb diet");
        cout << "Saved plans: " << loadFromFile("plans.txt") << endl;

        // ���ø� Ŭ���� Ȱ��
        GenericPlan<string> customPlan("Custom Fitness Plan");
        customPlan.show();

        // �޸� ����
        for (const auto& plan : plans) delete plan;

    }
    catch (exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
