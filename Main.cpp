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
        // 객체 배열 및 포인터 사용
        vector<HealthPlan*> plans;
        plans.push_back(new ExercisePlan("Running 30 minutes"));
        plans.push_back(new DietPlan("Low-carb diet"));

        // 출력
        for (const auto& plan : plans) {
            plan->displayPlan();
        }

        // 파일 입출력
        saveToFile("plans.txt", "Running 30 minutes, Low-carb diet");
        cout << "Saved plans: " << loadFromFile("plans.txt") << endl;

        // 템플릿 클래스 활용
        GenericPlan<string> customPlan("Custom Fitness Plan");
        customPlan.show();

        // 메모리 해제
        for (const auto& plan : plans) delete plan;

    }
    catch (exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
