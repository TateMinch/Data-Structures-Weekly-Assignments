#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;
    vector<int>::iterator it;
    int newNum;

    while(cin >> newNum)
    {
        v1.push_back(newNum);
    } 

    v1.erase( unique( v1.begin(), v1.end() ), v1.end() );

    for(it = v1.begin(); it != v1.end(); it++)
    {
        cout << *it << endl;
    }


    return 0;
}