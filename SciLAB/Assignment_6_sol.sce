// FILE HANDELING IN SCILAB

// data in file is like
// No Name Mark1 Mark2 Mark3

// NOTE : write full file path instead of just file name if any error occurs !!


function menu()
    disp("1 : Read File");
    disp("2 : Write File");
    disp("3 : Search in File");
    disp("4 : Deletion File");
    disp("5 : Copy file");
    disp("6 : EXIT");
endfunction

function read_file()
    fp=mopen('data1.txt','rt');
    
    while 1
        [scanned_latters,no,name,mark1,mark2,mark3]=mfscanf(fp,"%s %s %d %d %d");
        
        if scanned_latters==-1 then   // it means end of a file
            break;
        end
        
        avg=(mark1 + mark2 + mark3)/3;
        
        mprintf("%s %s %f\n",no,name,avg);
    end
    

    
    mclose(fp);
endfunction

function write_file()
    fp=mopen('data1.txt','at');
    
    want_to_write=%t
    
    while want_to_write
        
        no=input("No : ","string");
        name=input("Name : ","string");
        mark1=input("Mark 1 : ");
        mark2=input("Mark 2 : ");
        mark3=input("Mark 3 : ");
        
        mfprintf(fp,"%s %s %d %d %d\n",no,name,mark1,mark2,mark3);
        
        x=input("Want to write further (yes : 1) || (No : 0)");
        
        if x==0 then
            want_to_write=%f;
        end
    end
    
    mclose(fp);
endfunction

function search_file()
    fp=mopen('data1.txt','rt');
    
    x=input("Search by ROLL NO (PRESS 1) || by NAME (PRESS 2)");
    search=input("Enter search name  | roll no :","string");
    
    search_rollno="NULL";
    search_name="NULL";
    
    if x==1 then
        search_rollno=search;
    else
        search_name=search;
    end
    
    while 1
        [scanned_latters,no,name,mark1,mark2,mark3]=mfscanf(fp,"%s %s %d %d %d");
        
        
        if scanned_latters==-1 then   // it means end of a file
            disp("--- Record Not Found ---");
            break;
        end
        
        
        if search_rollno=="NULL" & search_name==name then    // search by name
            mprintf(" Record Founded :: %s %s %d %d %d\n",no,name,mark1,mark2,mark3);
            break;
        end
        
        if search_name=="NULL" & search_rollno==no then   // search by roll no
            mprintf(" Record Founded  :: %s %s %d %d %d\n",no,name,mark1,mark2,mark3);
            break;
        end
        
    end
    
    mclose(fp);
endfunction

function copy_file()
    
    x=input("Enter a name of new file : ","string");
    
    fp=mopen("data1.txt","rt");    // source file
    fp2=mopen(x,"w");   // destination file
    
    while 1
       [scanned_latters,no,name,mark1,mark2,mark3]=mfscanf(fp,"%s %s %d %d %d");
       
       if scanned_latters==-1 then
           break;
       end
       
       mfprintf(fp2,"%s %s %d %d %d\n",no,name,mark1,mark2,mark3);
       
    end
    
    mclose(fp);
    mclose(fp2);
endfunction

function delete_file()    // delete record from file
    
    fp=mopen("data1.txt","rt");    
    fp2=mopen("temp.txt","wt");             
    
    x=input("Delete by ROLL NO (PRESS 1) || by NAME (PRESS 2)");
    y=input("Enter name  | roll no :","string");
    
    delete_rollno="NULL";
    delete_name="NULL";
    
    if x==1 then
        delete_rollno=y;
    else
        delete_name=y;
    end
    
    
    found=%f;   // record found or not ?
    
    while 1
        [scanned_latters,no,name,mark1,mark2,mark3]=mfscanf(fp,"%s %s %d %d %d");
        
        
        if scanned_latters==-1 then   // it means end of a file
            
            if found==%t then
                disp(" :: Record Successfully deleted ::");
            else
                disp(" :: Record Not found in file   ::");
            end
            
            break;
        end
        
        
        if delete_rollno=="NULL" & delete_name==name then    // search by name
            found=%t;
        elseif delete_name=="NULL" & delete_rollno==no then
            found=%t;
        else
            mfprintf(fp2,"%s %s %d %d %d\n",no,name,mark1,mark2,mark3);
        end
        
        
    end
    
    mclose(fp);
    mclose(fp2);
    
    movefile("temp.txt","data1.txt");
    mdelete("temp.txt");
    
endfunction



flag=%t;   // flag=1 -> continue loop

while flag
    
    menu();   // shows menu
    
    choice=input("Select any option :");
    
    select choice
        case 1 then
            read_file();
           
        case 2 then
            write_file();
            
        case 3 then
            search_file();
           
        case 4 then
            delete_file();
            
        case 5 then
            copy_file();
            
        case 6 then
            flag=%f;
            
    end
end
