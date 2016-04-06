#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
	int start_addr;
	int end_addr;
	int pid; // if not allocated = -1 OR +ve
    Node *next;

	Node(int sa,int ea){
        start_addr=sa;
        end_addr=ea;
        pid=-1;
        next=NULL;
	}
};

/*
    fhead : free memory list head node
    ahead : allocated memory list head node
*/
class MemoryAllocation {
    public:
        Node *fhead,*ahead;

        bool allocate_memory_firstfit(int pid,int bsize);
        bool allocate_memory_bestfit(int pid,int bsize);
        bool allocate_memory_worstfit(int pid,int bsize);
        bool allocate_free_space(int start_addt,int end_addr);
        bool allocate_process_memory(int start_addr,int end_addr,int pid,int bsize);
        int blockSize(Node *head);
        void mergeMemory();
        bool kill_process(int pid);
        void displayFreeMemoryStatus();
        void displayAllocatedMemoryStatus();

        MemoryAllocation(){
            fhead=NULL,ahead=NULL;
        }
};

int MemoryAllocation::blockSize(Node *head){
    if(head==NULL) return 0;
    return head->end_addr-head->start_addr+1;
}

void MemoryAllocation::displayFreeMemoryStatus(){
    Node *temp=fhead;
    printf("\nFree Memory Status\n");
    printf("%20s%20s%20s\n","Start Address","End Address","Size(MB)");

    while(temp){
        printf("%20d%20d%20d\n",temp->start_addr,temp->end_addr,blockSize(temp));
        temp=temp->next;
    }
    printf("\n");
}

void MemoryAllocation::displayAllocatedMemoryStatus(){
    Node *temp=ahead;
    printf("\nAllocated Memory Status\n");
    printf("%20s%20s%20s%20s\n","Start Address","End Address","Size(MB)","Process ID");

    while(temp){
        printf("%20d%20d%20d%20d\n",temp->start_addr,temp->end_addr,blockSize(temp),temp->pid);
        temp=temp->next;
    }
    printf("\n");
}

bool MemoryAllocation::allocate_free_space(int start_addr,int end_addr){
    Node *temp=fhead,*pre=NULL;

    // empty list
    if(fhead==NULL){
        temp=new Node(start_addr,end_addr);
        fhead=temp;
        return 1;
    }

    // first node to be inserted
    if(temp->start_addr>end_addr){
        temp=new Node(start_addr,end_addr);
        temp->next=fhead;
        fhead=temp;
        return 1;
    }

    while(temp!=NULL && temp->start_addr < end_addr){
        pre=temp;
        temp=temp->next;
    }

    if(temp==NULL){  // last node
        pre->next=new Node(start_addr,end_addr);
        return 1;
    }
    else {
        pre->next=new Node(start_addr,end_addr);
        pre->next->next=temp;
        return 1;
    }
    return 0;
}

void MemoryAllocation::mergeMemory(){
    Node *temp=fhead;

    if(temp==NULL) return;

    while(temp){
        if(temp->next && temp->end_addr+1 == temp->next->start_addr){
            temp->end_addr=temp->next->end_addr;
            temp->next=temp->next->next;
        }
        temp=temp->next;
    }

 }

bool MemoryAllocation::allocate_process_memory(int start_addr,int end_addr,int pid,int bsize){
    Node *newNode=new Node(start_addr,end_addr);
    newNode->pid=pid;

    Node *temp=ahead,*pre=NULL;

    // empty list
    if(ahead==NULL){
        ahead=newNode;
        return 1;
    }

    // first node to be inserted
    if(temp->start_addr>end_addr){
        temp=newNode;
        temp->next=fhead;
        ahead=temp;
        return 1;
    }

    while(temp!=NULL && temp->start_addr < end_addr){
        pre=temp;
        temp=temp->next;
    }

    if(temp==NULL){  // last node
        pre->next=newNode;
        return 1;
    }
    else {
        pre->next=newNode;
        pre->next->next=temp;
        return 1;
    }
    return 0;
}

bool MemoryAllocation::allocate_memory_firstfit(int pid,int bsize){
    Node *temp=fhead,*pre=NULL;

    if(fhead==NULL) return 0;

    while(temp){
        if(blockSize(temp) >= bsize){  // block found
            allocate_process_memory(temp->start_addr,temp->start_addr+bsize-1,pid,bsize);

            if(blockSize(temp) == bsize) {
                if(temp==fhead){
                    fhead=fhead->next;
                }else{
                    pre->next=temp->next;
                }
            }else {
                temp->start_addr=temp->start_addr+ bsize;
            }
            return 1;
        }
        pre=temp;
        temp=temp->next;
    }

    if(temp==NULL)
        return 0;

    return 0;
}

bool MemoryAllocation::allocate_memory_bestfit(int pid,int bsize){
    Node *temp=fhead,*pre=NULL;

    if(temp==NULL) return 0;

    /* Find best fot node */
    Node *bestfitnode=NULL;

    while(temp){
        if(blockSize(temp) >= bsize){
            if(bestfitnode==NULL){
                bestfitnode=temp;
            }
            else{
                if(blockSize(bestfitnode) > blockSize(temp))
                    bestfitnode=temp;
            }
        }

        temp=temp->next;
    }

    /* Best fit Memory not found */
    if(bestfitnode==NULL) return 0;

    temp=fhead,pre=NULL;

    while(temp!=bestfitnode){
        pre=temp;
        temp=temp->next;
    }

    // first node to be deleted
    allocate_process_memory(bestfitnode->start_addr,bestfitnode->start_addr+bsize-1,pid,bsize);

    if(bestfitnode==fhead){
        if(blockSize(bestfitnode)==bsize) {
            fhead=fhead->next;
            free(bestfitnode);
        }else {
            bestfitnode->end_addr=bestfitnode->start_addr+bsize;
        }
    }
    else {
        if(blockSize(bestfitnode)==bsize) {
            pre->next=temp->next;
            free(bestfitnode);
        }else {
            bestfitnode->start_addr=bestfitnode->start_addr+bsize;
        }
    }

}

bool MemoryAllocation::allocate_memory_worstfit(int pid,int bsize){
    Node *temp=fhead,*pre=NULL;

    if(temp==NULL) return 0;

    /* Find best fot node */
    Node *worstfitnode=NULL;

    while(temp){
        if(blockSize(temp) >= bsize){
            if(worstfitnode==NULL){
                worstfitnode=temp;
            }
            else{
                if(blockSize(worstfitnode) < blockSize(temp))
                    worstfitnode=temp;
            }
        }

        temp=temp->next;
    }

    /* Best fit Memory not found */
    if(worstfitnode==NULL) return 0;

    temp=fhead,pre=NULL;

    while(temp!=worstfitnode){
        pre=temp;
        temp=temp->next;
    }

    // first node to be deleted
    allocate_process_memory(worstfitnode->start_addr,worstfitnode->start_addr+bsize-1,pid,bsize);

    if(worstfitnode==fhead){
        if(blockSize(worstfitnode)==bsize) {
            fhead=fhead->next;
            free(worstfitnode);
        }else {
            worstfitnode->start_addr=worstfitnode->start_addr+bsize;
        }
    }
    else {
        if(blockSize(worstfitnode)==bsize) {
            pre->next=temp->next;
            free(worstfitnode);
        }else {
            worstfitnode->start_addr=worstfitnode->start_addr+bsize;
        }
    }

}

bool MemoryAllocation::kill_process(int pid){
    Node *temp=ahead,*pre=NULL;

    if(ahead==NULL) return 0;

    if(temp->pid==pid){
        allocate_free_space(temp->start_addr,temp->end_addr);
        free(temp);
        ahead=ahead->next;
        mergeMemory();
        return 0;
    }

    while(temp){
        if(temp->pid==pid){
            pre->next=temp->next;
            allocate_free_space(temp->start_addr,temp->end_addr);
            mergeMemory();
            return 1;
        }
        pre=temp;
        temp=temp->next;
    }

    if(temp==NULL)
        return 0;
}

void menu(){
    printf(" >> 1 : Display Memory Status : \n");
    printf(" >> 2 : Allocate Free Space   : \n");
    printf(" >> 3 : First Fit Memory Allocation \n");
    printf(" >> 4 : Best Fit Memory Allocation \n");
    printf(" >> 5 : Worst Fit Memory Allocation \n");
    printf(" >> 6 : Kill Process\n");
}

int main(){

    MemoryAllocation *m1=new MemoryAllocation();
    int startaddr,endaddr,pid,bsize;

    while(1){
        menu();
        int choice;
        cin>>choice;

        switch(choice) {
            case 1:
                m1->displayAllocatedMemoryStatus();
                m1->displayFreeMemoryStatus();
                break;

            case 2:
                cout<<"Enter [ startaddress | endaddress  ]"<<endl;
                cin>>startaddr>>endaddr;
                m1->allocate_free_space(startaddr,endaddr);
                break;

            case 3:
                cout<<"Enter [ processID | Block Size ] "<<endl;
                cin>>pid>>bsize;
                m1->allocate_memory_firstfit(pid,bsize);
                break;

            case 4:
                cout<<"Enter [ processID | Block Size ] "<<endl;
                cin>>pid>>bsize;
                m1->allocate_memory_bestfit(pid,bsize);
                break;

            case 5:
                cout<<"Enter [ processID | Block Size ] "<<endl;
                cin>>pid>>bsize;
                m1->allocate_memory_worstfit(pid,bsize);
                break;

            case 6:
                cout<<"Enter [ processID ] "<<endl;
                cin>>pid;
                m1->kill_process(pid);
                break;

        }
    }

    /*
    m1->allocate_free_space(1,2);
    m1->allocate_free_space(5,10);
    m1->allocate_free_space(15,60);
    m1->allocate_free_space(70,80);

    m1->displayFreeMemoryStatus();
    m1->displayAllocatedMemoryStatus();

    //m1->allocate_memory_firstfit(1,2);
    //m1->allocate_memory_firstfit(2,20);

    m1->allocate_memory_worstfit(1,1);

    m1->displayFreeMemoryStatus();
    m1->displayAllocatedMemoryStatus();

    m1->kill_process(1);

    m1->displayFreeMemoryStatus();
    m1->displayAllocatedMemoryStatus();
    */
    return 0;
}
