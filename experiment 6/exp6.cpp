#include <iostream>
using namespace std;

struct Item {
    int profit;
    int weight;
    double ratio;
};

void sortItems(Item a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j].ratio < a[j + 1].ratio) {
                Item temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    Item items[n];

    cout << "Enter profit and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].profit >> items[i].weight;
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }

    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    sortItems(items, n);

    double maxProfit = 0;

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            maxProfit += items[i].profit;
        } else {
            maxProfit += items[i].ratio * capacity;
            break;
        }
    }

    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}