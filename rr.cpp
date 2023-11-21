#include <bits/stdc++.h>
using namespace std;

int main()
{
  
    int n, qu;
    cin >> n >> qu;

    
    vector<vector<int>> v;

    
    cout << "arrival " << "burst" << endl;

    
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        vector<int> v1;
        v1.push_back(x);
        v1.push_back(y);
        v1.push_back(i);
        v.push_back(v1);
    }

   
    vector<vector<int>> v2 = v;

    sort(v.begin(), v.end());

    
    int x = v[0][0];

   
    int a[n] = {0};

    
    queue<vector<int>> q;

   
    while (1)
    {
       
        for (int i = 0; i < n; i++)
        {
            if (v[i][0] != -1 && v[i][0] <= x)
            {
                q.push(v[i]);
                v[i][0] = -1;
            }
        }
        

       
        if (!q.empty())
        {
            vector<int> v3 = q.front();
            q.pop();

           
            if (v3[1] <= qu)
            {
                x += v3[1];
                a[v3[2]] = x; // Completion time for the process
            }
            else
            {
                x += qu;  // rat le
                v3[1] -= qu;
                // Re-queue the process if it has remaining burst time
                for (int i = 0; i < n; i++)
                {
                    if (v[i][0] != -1 && v[i][0] <= x)
                    {
                        q.push(v[i]);
                        v[i][0] = -1;
                    }
                }
                q.push(v3);
            }
        }
        else
        {
            x++; 
        }

        // Check if all processes are completed
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i][0] == -1)
            {
                k++;
            }
        }

       
        if (k == n && q.empty())
        {
            break;
        }
    }

    
    cout << "processno " << " arrival " << " burst " << " completion " << " waiting time " << " turnaround" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " " << v2[i][0] << " " << v2[i][1] << " " << a[i] << " " << a[i] - (v2[i][0] + v2[i][1]) << " " << a[i] - v2[i][0] << endl;
    }

    return 0;
}