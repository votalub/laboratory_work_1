#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <functional>
#include <iomanip>

using namespace std;

struct Student {
    Student(string name, string id, string subj1, double val1, string subj2, double val2, string subj3, double val3){
        this->Name = name;
        this->GroupId = id;
        this->Ratings.emplace(subj1, val1);
        this->Ratings.emplace(subj2, val2);
        this->Ratings.emplace(subj3, val3);
        this->mVal = (val1 + val2 + val3)/3;
    }
    string Name;
    string GroupId;
    map<string, int> Ratings;
    double mVal;
};

int main(){
    vector <Student> students = {
            Student("Паша", "17a", "math", 5, "physics", 5, "political", 5),
            Student("Миша", "17b", "math", 4, "physics", 3, "political", 2),
            Student("Олег", "17c", "math", 5, "physics", 4, "political", 3),
            Student("Глеб", "17d", "math", 2, "physics", 3, "political", 3),
            Student("Иван", "17e", "math", 4, "physics", 4, "political", 3),
            Student("Витя", "17f", "math", 3, "physics", 2, "political", 2)
    };
    cout << "Сортировка по именам: " << endl;
    sort(students.begin(), students.end(), [](const Student &s1, const Student &s2){
        return s1.Name < s2.Name;
    });
    for (auto el : students)
        cout << el.Name << setw(10) << el.GroupId << " math: " << el.Ratings["math"] << " physics: " << el.Ratings["physics"] << " political: " << el.Ratings["political"] << endl;

    cout << "Сортировка по средней оценке: " << endl;
    sort(students.begin(), students.end(), [](const Student &s1, const Student &s2){
        return s1.mVal < s2.mVal;
    });
    for (auto el : students)
        cout << el.Name << setw(10) << el.GroupId << "  math: " << el.Ratings["math"] << " physics: " << el.Ratings["physics"] << " political: " << el.Ratings["political"] << " mean: " << el.mVal << endl;

    int res1 = count_if(students.begin(), students.end(), [](Student &s){
        return s.Ratings["math"] == 2 || s.Ratings["physics"] == 2;
    });
    cout << "Сколько студентов имеют неуд хотя бы по одному предмету: " << res1 << endl;

    int res2 = count_if(students.begin(), students.end(), [](Student &p){
        return p.Ratings["math"] == 5 && p.Ratings["physics"] == 5;
    });
    cout << "Сколько студентов имеют отл по всем предметам: " << res2 << endl;

    cout << "Студенты, имеющие отл по math: " << endl;
    vector <Student> exlents;
    copy_if(students.begin(), students.end(), back_inserter(exlents), [](Student &p){
        return p.Ratings["math"] == 5;
    });
    for (auto el : exlents)
        cout << el.Name << setw(10) << el.GroupId << "  math: " << el.Ratings["math"] << " physics: " << el.Ratings["physics"] << " political: "<< el.Ratings["political"] << " mean: " << el.mVal << endl;

    cout << "Поставили всем студентам хор по политологии! " << endl;
    for (auto &el : students)
        el.Ratings.at("political") = 4;
    for (auto el : students)
        cout << el.Name << setw(10) << el.GroupId << "  math: " << el.Ratings["math"] << " physics: " << el.Ratings["physics"] << " political: "<< el.Ratings["political"] << " mean: " << el.mVal << endl;

    return 0;
}
