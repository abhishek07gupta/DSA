#include <iostream>
#include<queue>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> sandwich;
        queue<int> student;
        int served =  0 ;
        for(int i = 0 ; i < sandwiches.size() ; i++){
            sandwich.push(sandwiches[i]);
            student.push(students[i]);
        }
        while(!sandwich.empty() && served < student.size()){
            if(student.front()==sandwich.front()){
                student.pop();
                sandwich.pop();
                served=0;
            }else{
                student.push(student.front());
                student.pop();
                served++;
                }
            }
        
        return student.size();
    }
};