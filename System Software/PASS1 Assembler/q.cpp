#include<bits/stdc++.h>

using namespace std;

class Info{
    public:
    string class_info,opcode_info;
    int opcode_len;
};

Info makeInfo(string class_info , string opcode_info="",int opcode_len=0){
    Info temp;
    temp.class_info=class_info;
    temp.opcode_info=opcode_info;
    temp.opcode_len=opcode_len;
    return temp;
}

map< string , Info > mnemonics;

void build(){
    mnemonics["START"]  =makeInfo("IS","1",0);
    mnemonics["END"]    =makeInfo("","");
    mnemonics["READ"]   =makeInfo("","");
    mnemonics["ADD"]    =makeInfo("","");
    mnemonics["SUB"]    =makeInfo("","");
    mnemonics["MULT"]   =makeInfo("","");
    mnemonics["MOVER"]  =makeInfo("","");
    mnemonics["MOVEM"]  =makeInfo("","");
    mnemonics["BC"]     =makeInfo("","");
    mnemonics["COMP"]   =makeInfo("","");
    mnemonics["PRINT"]  =makeInfo("","");
    mnemonics["DIV"]    =makeInfo("","");
    mnemonics["STOP"]   =makeInfo("","");
    mnemonics["DC"]     =makeInfo("","");
    mnemonics["DS"]     =makeInfo("","");
    mnemonics["LTORG"]  =makeInfo("","");
    mnemonics["EQU"]    =makeInfo("","");
}

int main(){
    build();
    freopen("program.txt","r",stdin);

    char s[100005];

    while(gets(s)!=0) {
        cout<<s<<endl;
        vector<string> tokens;
        string t="";
        for(int i=0;i<strlen(s);){
            while(s[i]==' ' || s[i]==',' || s[i]==':'){
                if(t!="") {
                    tokens.push_back(t);
                }
                i++;
                t="";
            }
            t+=s[i++];
        }
        for(int i=0;i<tokens.size();i++){
            cout<<" :: TOKEN :  "<<tokens[i]<<endl;
        }
    }

    return 0;
}
