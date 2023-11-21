#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printFrameContents(const vector<int>& frame) {
    cout << "Frame Contents: ";
    for (int pageNum : frame) {
        cout << pageNum << " ";
    }
    cout << endl;
}

void optimalPage(const vector<int>& pages, int capacity) {
    vector<int> frame;
    int hits = 0, misses = 0;

    for (int page : pages) {
        bool pageInFrame = false;

        for (int i = 0; i < frame.size(); i++) {
            if (frame[i] == page) {
                pageInFrame = true;
                hits++;
                break;
            }
        }

        if (!pageInFrame) {
            misses++;

            if (frame.size() == capacity) {
                // Replace the page with the farthest future reference
                int farthestIndex = -1, farthestPage = -1;
                for (int i = 0; i < frame.size(); i++) {
                    int futureRefIndex = find(pages.begin(), pages.end(), frame[i]) - pages.begin();
                    if (futureRefIndex == pages.size()) {
                        farthestIndex = i;
                        break;
                    }
                    if (futureRefIndex > farthestPage) {
                        farthestIndex = i;
                        farthestPage = futureRefIndex;
                    }
                }
                frame[farthestIndex] = page;
            } else {
                frame.push_back(page);
            }
        }

        // Display frame contents after each iteration
        printFrameContents(frame);
    }

    cout << "No. of hits = " << hits << endl;
    cout << "No. of misses = " << misses << endl;
}

int main() {
    int n, capacity;

    cout << "Enter the number of pages: ";
    cin >> n;
    vector<int> pages(n);

    cout << "Enter the page numbers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << "Enter the number of frames: ";
    cin >> capacity;

    optimalPage(pages, capacity);

    return 0;
}