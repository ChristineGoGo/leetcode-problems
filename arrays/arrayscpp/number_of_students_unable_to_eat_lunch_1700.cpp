/*

    The school cafeteria offers circular and square sandwiches at lunch break,
    referred to by numbers 0 and 1 respectively. All students stand in a queue.
    Each student either prefers square or circular sandwiches.

    The number of sandwiches in the cafeteria is equal to the number of students.
    The sandwiches are placed in a stack. At each step:

    If the student at the front of the queue prefers the sandwich on the top of the
    stack, they will take it and leave the queue.
    Otherwise, they will leave it and go to the queue's end.
    This continues until none of the queue students want to take the top sandwich
    and are thus unable to eat.

    You are given two integer arrays students and sandwiches where sandwiches[i]
    is the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack)
    and students[j] is the preference of the j​​​​​​th student in the initial queue (j = 0 is
    the front of the queue). Return the number of students that are unable to eat.



    Example 1:

    Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
    Output: 0
    Explanation:
    - Front student leaves the top sandwich and returns to the end of the line making students = [1,0,0,1].
    - Front student leaves the top sandwich and returns to the end of the line making students = [0,0,1,1].
    - Front student takes the top sandwich and leaves the line making students = [0,1,1] and sandwiches = [1,0,1].
    - Front student leaves the top sandwich and returns to the end of the line making students = [1,1,0].
    - Front student takes the top sandwich and leaves the line making students = [1,0] and sandwiches = [0,1].
    - Front student leaves the top sandwich and returns to the end of the line making students = [0,1].
    - Front student takes the top sandwich and leaves the line making students = [1] and sandwiches = [1].
    - Front student takes the top sandwich and leaves the line making students = [] and sandwiches = [].
    Hence all students are able to eat.
    Example 2:

    Input: students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
    Output: 3


    Constraints:

    1 <= students.length, sandwiches.length <= 100
    students.length == sandwiches.length
    sandwiches[i] is 0 or 1.
    students[i] is 0 or 1.


*/


#include <iostream>
#include <map>
#include <queue>


using namespace std;


    // APPROACH: Use two queues for the students and the sandwiches
    // initialize a variable to track the students refusing the top sandwiches
    // loop while there are students and sandwiches in the queues as well as students willing to accept top sandwich:
    //      - if the sandwich is what the student wants remove the student from the queue and reset the
    //        students refusing to 0 and remove the sandwich from the queue as well.
    //      - else send the student to the back of the line, add to the students refusing variable
    // return the students refusing variable

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> studentPrefs;
    queue<int> sandwichesLeft;

    int studentRefused = 0;
    int totalStudents = students.size();

    // add to the student preferences queue
    for (int student: students) {
        studentPrefs.push(student);
    }

    //add to the available sandwiches queue
    for (int sandwich: sandwiches) {
        sandwichesLeft.push(sandwich);
    }

    // distribute the sandwich
    while (!studentPrefs.empty() && !sandwichesLeft.empty() && totalStudents > studentRefused) {
        if (studentPrefs.front() != sandwichesLeft.front()) {
            int currSt = studentPrefs.front();
            studentPrefs.pop();
            studentPrefs.push(currSt);
            studentRefused++;

        } else {
            studentPrefs.pop();
            sandwichesLeft.pop();
            studentRefused = 0;
            totalStudents--;
        }
    }

    // return result
    return studentRefused;


}


int main() {
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = { 0, 1, 0, 1};

    cout << countStudents(students, sandwiches);
}