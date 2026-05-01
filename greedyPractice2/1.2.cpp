#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class question{
    public:
    int mark;
    int time;
};

int comp(question a, question b) {
    double unit_a = a.mark / (double) a.time;
    double unit_b = b.mark / (double) b.time;
    return unit_a > unit_b;
}

int maximumMarks(int totalTime, vector<question> &questions);

int main() {
    int totalMarks;
    cin >> totalMarks;
    int totalTime;
    cin >> totalTime;
    int totalQuestions;
    cin >> totalQuestions;
    vector<question> questions;
    for (int i = 0; i < totalQuestions; i++) {
        int mark; int time;
        cin >> mark; cin >> time;
        question question;
        question.mark = mark;
        question.time = time;
        questions.push_back(question);
    }
    sort(questions.begin(), questions.end(), comp);
    int max_alone = maximumMarks(totalTime, questions);
    cout << "maximum marks alone: " << max_alone << endl;
    int max_together = maximumMarks(totalTime * 2, questions);
    cout << "maximum marks with a friend: " << max_together << endl;
}

int maximumMarks(int totalTime, vector<question> &questions) {
    int questionNo = 1;
    int maximum_marks = 0;
    for(question question: questions) {
        if (totalTime == 0) break;
        if (question.time <= totalTime) {
            cout << "ques " << questionNo << ": 100\% done -- " << question.mark << " marks" << endl;
            totalTime -= question.time;
            maximum_marks += question.mark;
            questionNo++;
        }
        else {
            double unit_marks = question.mark / (double) question.time;
            int marks = totalTime * unit_marks;
            maximum_marks += marks;
            cout << "ques " << questionNo << "1: " << (marks / (double) question.mark) * 100 << "\% done -- " << marks << " marks" << endl;
            totalTime = 0;
            questionNo++;
        }
    }
    return maximum_marks;
}