#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int pid;
        int cpu_time;
        int arrival_time;

        Node(int p_id,int ctime,int atime){
            pid=p_id;
            cpu_time=ctime;
            arrival_time=atime;
        }
};

class comparator{
    public:
        bool operator()(const Node *l,const Node *r) const{
            if(l->cpu_time > r->cpu_time) {
                return 1;
            }
            else if(l->cpu_time==r->cpu_time){
                if(l->pid < r->pid)
                    return 1;
                else
                    return 0;
            }
            else
                return 0;
        }
};

class comparatorBuffer{
    public:
        bool operator()(const Node *l,const Node *r) const{
            if(l->arrival_time > r->arrival_time) {
                return 1;
            }
            else if(l->arrival_time ==r->arrival_time ){
                if(l->pid < r->pid)
                    return 1;
                else
                    return 0;
            }
            else
                return 0;
        }
};

class SRTF{
    public:
        priority_queue< Node*,vector<Node*>,comparator > q;
        priority_queue< Node*,vector<Node*>,comparatorBuffer > buffer;

        void insertProcess(int pid,int ctime,int atime);
        void schedule();
};

void SRTF::insertProcess(int pid,int ctime,int atime){
    Node *temp=new Node(pid,ctime,atime);
    buffer.push(temp);
}

void SRTF::schedule(){
    Node *temp;
    int t=0;

    printf("%20s%20s%20s\n","Time","processID","RemainedBurstTime");

    while(!q.empty() || t==0){
        /* load processes from buffer */
        temp=buffer.top();
        while(!buffer.empty() && temp->arrival_time == t){
            q.push(temp);
            buffer.pop();
            temp=buffer.top();
        }

        temp=q.top();
        q.pop();
        temp->cpu_time--;

        printf("%20d%20d%20d\n",t,temp->pid,temp->cpu_time);

        if(temp->cpu_time!=0)
            q.push(temp);

        t++;
    }
}

int main(){

    SRTF *s1=new SRTF();

    s1->insertProcess(1,5,0);
    s1->insertProcess(2,2,1);
    //s1->insertProcess(3,10,3);
    //s1->insertProcess(4,6,6);

    s1->schedule();

    return 0;
}
