#include <iostream>
using namespace std;

struct Activity
{
    int start, finish;
};

int main()
{
    int n;

    cout << "Enter number of activities: ";
    cin >> n;

    Activity a[100];

    cout << "Enter start and finish time of each activity:\n";

    for (int i = 0; i < n; i++)
        cin >> a[i].start >> a[i].finish;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].finish > a[j].finish)
            {
                Activity temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    cout << "Selected activities:\n";

    int lastFinish = -1;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i].start >= lastFinish)
        {
            cout << "(" << a[i].start << ", " << a[i].finish << ")\n";
            lastFinish = a[i].finish;
            count++;
        }
    }

    cout << "Maximum number of activities: " << count << endl;

    return 0;
}