class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size();
        queue<int> qs;   // sandwiches
        queue<int> q;   // for students
        int c=0;

        int rc=0;
        for(int i=0;i<n;i++){
            qs.push(sandwiches[i]);
            q.push(students[i]);
        }

        while(!q.empty()){
            int f=q.front();
            int k=qs.front();
            if(k==f){
                q.pop();
                qs.pop();
                c++;
                rc=0;

            }
            else{
                int x=q.front();
                q.pop();
                q.push(x);
                rc++;
                
            }

            if(rc==q.size()) break;
        }

        return q.size();

    }
};