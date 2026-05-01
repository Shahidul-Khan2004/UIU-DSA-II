#include <iostream>
#include <vector>

using namespace std;

class student{
    public:
    string name;
    int id;
    double cg;
};

student best_student(vector<student> &students, int s, int e);

int main() {
    vector<student> students = {{"S", 1, 4.0}, {"R", 2, 3.0}, {"P", 3, 2.0}};
    student best = best_student(students, 0, students.size() - 1);
    cout << best.name << endl;
}

student best_student(vector<student> &students, int s, int e) {
    if (s == e) return students[s];
    int mid = (s + e) / 2;
    student l = best_student(students, s, mid);
    student r = best_student(students, mid + 1, e);
    if(l.cg > r.cg) return l;
    else return r;
}