#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll f,page_faults=0;  // frame size
map< ll,ll > mp;  // mp[page_no] => most recent index of page_no
set< pair< ll , ll > > s;  // contains pairs of { index , page_no } in sorted order of index
set< pair< ll , ll > >::iterator it;

void printSet(){
    cout<<"Frame : ";
    for(it=s.begin();it!=s.end();it++){
        cout<<(*it).second << "(" << (*it).first <<")" << " "; // (page_no , least_index)
    }
    cout<<"\n";
}

int main(){

    f=5;

    ll page[]={-100,1,5,3,4,5,6,7,9,4,7,8}; // first one is dummy page
    ll n=sizeof(page)/sizeof(page[0]);

    for(ll i=1;i<n;i++){
        ll pre_index=mp[page[i]];

        // page_fault
        if(s.find(make_pair(pre_index,page[i])) == s.end()){ // page[i] is not in frame
            page_faults++;
            cout<<"Page fault occured..."<<endl;
            if(s.size()<f){
                s.insert(make_pair(i,page[i]));  // insert{i,page[i]} in frame
            }
            else{
                // replace page[i] with least recently used page
                it=s.begin();
                cout<< (*it).second <<" page is deleted " <<endl;
                s.erase(s.begin());
                s.insert(make_pair(i,page[i]));
            }

            cout<<page[i] << " is inserted "<<endl;
        }
        else{
            s.erase(make_pair(pre_index,page[i]));
            s.insert(make_pair(i,page[i]));

            cout<< page[i]<< " updated index " <<endl;
        }

        // Mark least recent index of page[i] as i
        mp[page[i]]=i;

        printSet();
        //cout<<s.size()<<endl;
        cout<<"\n\n";

    }

    cout<< "Page faults : "<<page_faults <<endl;

    return 0;
}
