// Priority Non-Preemptive(higher no. higher priority)
#include<iostream>
#include<climits>
#include<string>
using namespace std;

class Process {
public:
    int at, bt, ct, tat, wt, pr,pid;
};

void nonprepriority() 
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    Process p[n];
    
    for (int i = 0; i < n; ++i) 
	{
        cout << "Enter arrival time of process " << i + 1 << " : ";
        cin >> p[i].at;
        cout << "Enter burst time of process " << i + 1 << " : ";
        cin >> p[i].bt;
        cout << "Enter priority of process " << i + 1 << " : ";
        cin >>p[i].pr;
        p[i].pid=i+1;
    }

    for (int i = 0; i < n; i++) 
	{
        for (int j = i + 1; j < n; j++) 
		{
            if (p[i].at > p[j].at) 
			{
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int isExecuted[n] = {0};
    int count = 0, current_time = 0;
    string execution_seq = ""; 

    while (count < n)
	 {
        int idx = -1;
        int high = INT_MIN;
        for (int i = 0; i < n; i++) 
		{
            if (!isExecuted[i] && p[i].at <= current_time)
			 {
                if (p[i].pr > high) 
				{
                    high = p[i].pr;
                    idx = i;
                }
                else if (p[i].pr == high && p[i].at < p[idx].at)
				{
                    idx = i;
                }
            }
        }
        
	        if (idx != -1) 
		{
            p[idx].ct = current_time + p[idx].bt;
            p[idx].tat = p[idx].ct - p[idx].at; 
            p[idx].wt = p[idx].tat - p[idx].bt; 
            current_time = p[idx].ct; 
            isExecuted[idx] = 1; 
            count++; 
            execution_seq += "P" + to_string(idx + 1) + " ";
        } 
		else 
		{
            current_time++; 
        }
    }

    cout<<"Process Details"<<endl;
    for (int i=0;i<n;i++)
	{
        cout<<"Process P"<<p[i].pid<<endl;cout<<"the arrival time is:"<<p[i].at<<endl<<"the burst time is:"<<p[i].bt<<
		endl<<"the completion time is:"<<p[i].ct<<endl<<"the waiting time is:"<<p[i].wt<<
		endl<<"the turn around time is:"<<p[i].tat<<endl;
    }
    float avgwt = 0, avgtat = 0;
    for (int i = 0; i < n; i++)
	{
        avgwt += p[i].wt;
        avgtat += p[i].tat;
    }
    cout << "Average Waiting Time: " << avgwt / n << endl;
    cout << "Average Turnaround Time: " << avgtat / n << endl;
    cout << "Execution Sequence: " << execution_seq << endl;
}

int main() 
{
    nonprepriority();
    return 0;
}

