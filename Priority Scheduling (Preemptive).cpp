//Priority Preemptive
#include <iostream>
#include <climits>
#include <string>
using namespace std;

void pp() {
    class Process {
       public:
	    int at;  
        int bt;  
        int ct; 
        int tat; 
        int wt;  
        int pr; 
        int rt;  
    };

    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    Process processes[n];

    for (int i = 0; i < n; ++i) 
	{
        cout << "Enter arrival time of process " << i + 1 << " : ";
        cin >> processes[i].at;
        cout << "Enter burst time of process " << i + 1 << " : ";
        cin >> processes[i].bt;
        cout << "Enter priority of process " << i + 1 << " : ";
        cin >> processes[i].pr;
        processes[i].rt = processes[i].bt; 
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].at > processes[j].at || 
               (processes[i].at == processes[j].at && processes[i].bt > processes[j].bt)) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
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
            if (!isExecuted[i] && processes[i].at <= current_time)
			 {
                if (processes[i].pr > high || 
                   (processes[i].pr == high && processes[i].at < processes[idx].at) ||
                   (processes[i].pr == high && processes[i].at == processes[idx].at && processes[i].rt < processes[idx].rt)) 
			    {
                    high = processes[i].pr;
                    idx = i;
                }
            }
        }

        if (idx != -1)
		 {
            execution_seq += "P" + to_string(idx + 1) + " ";
            processes[idx].rt--;
            current_time++;

            // If process is finished
            if (processes[idx].rt == 0) 
			{
                processes[idx].ct = current_time; 
                processes[idx].tat = processes[idx].ct - processes[idx].at; 
                processes[idx].wt = processes[idx].tat - processes[idx].bt; 
                isExecuted[idx] = 1;
                count++;
            }
        }
		 else 
		{
            current_time++;
        }
    }
    cout << "\nProcess Details:\n";
    cout << "P#\tAT\tBT\tPR\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) 
	{
        cout << "P" << i + 1 << "\t" << processes[i].at << "\t" << processes[i].bt
             << "\t" << processes[i].pr << "\t" << processes[i].ct
             << "\t" << processes[i].tat << "\t" << processes[i].wt << endl;
    }
    float avgwt = 0, avgtat = 0;
    for (int i = 0; i < n; i++)
	{
        avgwt += processes[i].wt;
        avgtat += processes[i].tat;
    }
    cout << "\nAverage Waiting Time: " << avgwt / n << endl;
    cout << "Average Turnaround Time: " << avgtat / n << endl;
    cout << "Execution Sequence: " << execution_seq << endl;
}

int main() 
{
    pp();
    return 0;
}

