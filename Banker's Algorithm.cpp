// Banker's Algorithm 
#include<iostream>
using namespace std;
int main() 
{
    int n, m;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the number of resources: ";
    cin >> m;
    int max[n][m];        
    int allocated[n][m];  
    int available[m];      
    int need[n][m];     
    bool finish[n];        
    int safe_sequence[n]; 
	 
    for(int i = 0; i < n; i++) 
	{
        finish[i] = false;
    }
    cout << "Enter the maximum resources required by each process:\n";
    for(int i = 0; i < n; i++)
	{
        for(int j = 0; j < m; j++) 
		{
            cin >> max[i][j];
        }
    }
    cout << "Enter the allocated resources for each process:\n";
    for(int i = 0; i < n; i++) 
	{
        for(int j = 0; j < m; j++) 
		{
            cin >> allocated[i][j];
        }
    }
    for(int i = 0; i < n; i++) 
	{
        for(int j = 0; j < m; j++) 
		{
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }
    cout << "Enter the available resources:\n";
    for(int i = 0; i < m; i++) 
	{
        cin >> available[i];
    }

    int count = 0;
    int safe_count = 0;  
    while(count < n) 
	{
        bool found = false;
        for(int i = 0; i < n; i++) 
		{
            if(!finish[i])
			{
                bool can_finish = true;
                for(int j = 0; j < m; j++) 
				{
                    if(need[i][j] > available[j]) 
					{
                        can_finish = false;
                        break;
                    }
                }

                if(can_finish) 
				{
                    finish[i] = true;
                    safe_sequence[safe_count++] = i;
                    for(int j = 0; j < m; j++) 
					{
                        available[j] += allocated[i][j];
                    }
					found = true;
                    count++;
                    break;
                }
            }
        }
        if(!found) 
		{
            cout << "Safe sequence does not exist. The system is in an unsafe state.\n";
            return 0;
        }
    }
    cout << "Safe sequence exists. The safe sequence is: ";
    for(int i = 0; i < n; i++) 
	{
        cout << "P" << safe_sequence[i] << " ";
        if(i != n - 1) 
		{
            cout << "-> ";
        }
    }
    cout << endl;
    return 0;
}


