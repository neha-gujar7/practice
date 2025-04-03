// 1352A- Sum of Round Numbers
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
 
        long long count = 0;
        vector<long long> v;
        long long placeValue = 1;
 
        while (n > 0)
        {
            long long r = n % 10;
            if (r != 0)
            {
                v.push_back(r * placeValue);
                count++;
            }
            n /= 10;
            placeValue *= 10;
        }
 
        cout << count << endl;
        for (long long i = 0; i < v.size(); i++)
        {
            cout << v[i];
            if (i != v.size() - 1) // Ensure space between numbers but not at the end
                cout << " ";
        }
        cout << endl; // Ensure each test case prints on a new line
    }
    return 0;
}
