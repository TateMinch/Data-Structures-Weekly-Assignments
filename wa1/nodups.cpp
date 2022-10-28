#include <iostream>

using namespace std;

int main()
{
    //I don't know why this isnt working
    //I don't know how to do this without the STL
    int arr[100];
    int temp, count = 0;
    bool done = false;

    while(cin >> arr[count])
    {
        count++;
    }

    while(!done)
    {
        done = true;
        for(int i = 0; i < count; i++)
        {
            if(arr[i - 1] > arr[i])
            {
                done = false;
                temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
            }
        }
    }

    int temparr[count];
    int j = 0;
    for(int i = 0; i < count - 1; i++)
    {
        if(arr[i] != arr[i + 1])
        {
            temparr[j++] = arr[i];
        }
    }
    temparr[j++] = arr[count - 1];
    for(int i = 0; i < j; i++)
    {
        arr[i] = temparr[i];
    }

    for(int i = 0; i < count; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}