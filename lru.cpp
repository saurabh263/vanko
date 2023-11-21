#include <bits/stdc++.h>
using namespace std;

int least(int pages[], int n, int cap)
{
    int pfault = 0;
    vector<int> v(cap);
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int page = pages[i];
        auto it = find(v.begin(), v.end(), page);  
        if (it != v.end())
        {
            v.erase(it);

            v.push_back(page);
        }

        else
        {
            if (v.size() == cap)
            {
                cout << "Page fault at index " << i << ": ";
                cout << "Replacing " << v[0] << " with " << page << endl;
                v.erase(v.begin()); 
            }
            else
            {
                cout << "Page fault at index " << i << ": ";
                cout << "Inserting " << page << " into frame" << endl;
            }
            count++;
            v.push_back(page);
        }

   
       cout << "Current state of frames: ";
        for (int j = 0; j < cap; j++)
        {
            cout << v[j] << " ";
        }
        cout << endl;
    }
     
    return count;
}

int main()
{
    int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int cap = 3;
    cout << least(pages, 12,cap) << endl;

    return 0;
}
