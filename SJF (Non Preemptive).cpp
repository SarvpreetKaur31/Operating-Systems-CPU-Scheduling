// SJF(Non-Preemptive)
#include<iostream>
#include<climits>
#include<string>
using namespace std;

class Process 
{
 public:
    int pid;
    int at,ct,bt,tat,wt;
};

int main() {
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;

    Process p[n];
    for (int i=0;i<n;i++)
	{
        cout<<"Enter the arrival time for process"<<i+1<<endl;
        cin>>p[i].at;
        cout<<"Enter the burst time for process"<<i+1<<endl;
        cin>>p[i].bt;
        p[i].pid=i+1;
    }

    string execution_seq=" ";
    int current_time=0,completed=0;
    float avgwt=0,avgtat=0;

    while(completed<n)
	{
        int idx=-1;
        int min_bt=INT_MAX;
        for (int i=0;i<n;i++)
		{
            if(p[i].at<=current_time && p[i].bt!=-1 && p[i].bt<min_bt) 
			{
                min_bt = p[i].bt;
                idx=i;
            }
        }

        if (idx!=-1) 
		{
            p[idx].ct=current_time+p[idx].bt;
            p[idx].tat=p[idx].ct-p[idx].at;
            p[idx].wt=p[idx].tat-p[idx].bt;
            current_time=p[idx].ct;
            p[idx].bt=-1; 
            completed++;
            execution_seq+="P"+to_string(p[idx].pid)+" ";

            avgwt+= p[idx].wt;
            avgtat+= p[idx].tat;
        } 
		else
		{
        
            current_time++;
        }
    }

    
    cout<<"Process Details"<<endl;
    for (int i=0;i<n;i++) 
	{
        cout<<"Process P"<<p[i].pid<<endl;cout<<"the arrival time is:"<<p[i].at<<endl<<"the burst time is: Originally entered"<<
		endl<<"the completion time is:"<<p[i].ct<<endl<<"the waiting time is:"<<p[i].wt<<
		endl<<"the turn around time is:"<<p[i].tat<<endl;
    }

    cout<<endl<<"Average Waiting Time:"<<avgwt/n<<endl;
    cout<<"Average Turnaround Time:"<<avgtat/n<<endl;
    cout<<"Execution Sequence:"<<execution_seq<<endl;

    return 0;
}

