//FCFS
#include<iostream>
#include<string>
using namespace std;
class Process
{
	public:
		int pid;
		int at,ct,bt,tat,wt;
};
int main()
{
	int n;
	cout<<"enter the number of processes"<<endl;
	cin>>n;
	Process p[n];
	for(int i=0;i<n;i++)
	{
	   cout<<"enter the arrival time for process "<<i+1<<endl;
	   cin>>p[i].at;
	   cout<<"enter the burst time for process "<<i+1<<endl;
       cin>>p[i].bt;
       p[i].pid=i+1;   
    }
    for(int i=0;i<n-1;i++)
    {
    	for(int j=i+1;j<n;j++)
    	{
    		if(p[i].at>p[j].at)
    		{
    			Process temp=p[i];
    			p[i]=p[j];
    			p[j]=temp;
			}
		}
	}
	string execution_seq=" ";
	p[0].wt=0;
	p[0].ct=p[0].at+p[0].bt;
	p[0].tat=p[0].ct-p[0].at;
	execution_seq+="p"+to_string(p[0].pid)+" ";
	for(int i=1;i<n;i++)
	{
		if(p[i-1].ct>p[i].at)
		{
			p[i].ct=p[i-1].ct+p[i].bt;
		}
		else
		{
			p[i].ct=p[i].at+p[i].bt;
		}
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
		execution_seq+="p"+to_string(p[i].pid)+" ";
	}
	for(int i=0;i<n;i++)
	{
		cout<<"Process P"<<p[i].pid<<endl;cout<<"the arrival time is:"<<p[i].at<<endl<<"the burst time is:"<<p[i].bt<<
		endl<<"the completion time is:"<<p[i].ct<<endl<<"the waiting time is:"<<p[i].wt<<
		endl<<"the turn around time is:"<<p[i].tat<<endl;
	}
	float avgwt=0;
	float avgtat=0;
	for(int i=0;i<n;i++)
	{
		avgwt=(avgwt+p[i].wt);
		avgtat=(avgtat+p[i].tat);
	}
	cout<<endl<<"the average waiting time is:"<<avgwt/n<<endl;
    cout<<"the average turn around time is:"<<avgtat/n<<endl;
	cout<<"the execution sequence is:"<<execution_seq<<endl;	
	return 0;
}
