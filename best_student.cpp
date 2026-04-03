#include <iostream>
#include <vector>

using namespace std;

struct Student
{
    string name;
    int id;
    float cgpa;
};

Student bestStudent (vector<Student> &arr, int start, int end);

int main()
{
    vector<Student> arr = {{"S", 1, 4.0}, {"R", 2, 3.0}, {"P", 3, 2.0}};
    cout << bestStudent(arr, 0, arr.size() - 1).name << endl;
}

Student bestStudent (vector<Student> &arr, int start, int end)
{
    if (start == end) return arr[start];
    int mid = (start + end) / 2;
    Student left = bestStudent(arr, start, mid);
    Student right = bestStudent(arr, mid + 1, end);
    return (left.cgpa > right.cgpa) ? left : right;
}