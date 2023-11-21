#include <iostream>
// #include <queue>
// #include <unordered_set>
#include<bits/stdc++.h>
using namespace std;

void fifoPage(int pages[], int n, int capacity) {
    unordered_set<int> s;
    queue<int> indexes;
    int page_faults = 0;

    for (int i = 0; i < n; i++) {
        cout << "Page " << pages[i] << " is ";
        if (s.size() < capacity) {
            if (s.find(pages[i]) == s.end()) {
                s.insert(pages[i]);
                page_faults++;
                indexes.push(pages[i]);
                cout << "in the frame. Frame Contents: [";
            } else {
                cout << "already in the frame. Frame Contents: [";
            }
        } else {
            if (s.find(pages[i]) == s.end()) {
                int val = indexes.front();
                indexes.pop();
                s.erase(val);
                s.insert(pages[i]);
                indexes.push(pages[i]);
                page_faults++;
                cout << "in the frame. Frame Contents: [";
            } else {
                cout << "already in the frame. Frame Contents: [";
            }
        }

        // Display frame contents
        queue<int> temp = indexes;
        while (!temp.empty()) {
            cout << temp.front();
            temp.pop();
            if (!temp.empty()) {
                cout << ", ";
            }
        }

        cout << "]" << endl;
    }

    cout << "Total Page Faults: " << page_faults << endl;
}

int main() {
    int pn;
    cout << "Enter the number of pages: ";
    cin >> pn;

    int* pg = new int[pn];
    cout << "Enter the page numbers:" << endl;
    for (int i = 0; i < pn; i++) {
        cin >> pg[i];
    }

    int fn;
    cout << "Enter the frame size: ";
    cin >> fn;

    fifoPage(pg, pn, fn);

    delete[] pg; // Free the allocated memory
    return 0;
}