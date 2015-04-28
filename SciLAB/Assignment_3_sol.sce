// ans 1.1

function i=length_string(s)
    p=strsplit(s)
    i=max(strindex(s,p($)))
endfunction

a=input("Enter string : ","s")

disp(length_string(a))


a=input("Enter string : ","s")

disp(lenl(a))

// ans 1.2

function r=reverseString(s)
    i=length_string(s)
    r=''
    while i>0
        if ~isalphanum(part(s,i)) then
            break
        end
        
        r=strcat([r,part(s,i)])
        
        i=i-1
        
    end
    
endfunction

a=input("Enter string :","s")
b=reverseString(a)
disp(b)



//1.3 palindrome
function flag=is_palindrome(s)
    r=strrev(s)
    if s==r then
        flag=%t
    else
        flag=%f
    end
    
endfunction


//1.4
function [b,a]=swap(a,b)
endfunction

a=5
b=2
[a,b]=swap(a,b)
disp("")
disp(a)
disp(b)

//1.5
function C=transpose(A)
    for i=1:3
        for j=1:3
            C(i,j)=A(j,i)
        end
    end

endfunction

function C=mult_matrix(A,B)
    C=[0,0,0;0,0,0;0,0,0]
    for i=1:3
        for j=1:3
            p=1,q=1
            for k=1:3
                C(i,j)=C(i,j)+A(i,p)*B(q,j)
                
                p=p+1
                q=q+1
            end
        end
    end
endfunction

//1.6

function y=fact(x)
    y=1
    while x>0
        y=y*x
        x=x-1
    end
endfunction

function fibb(x)
    f0=0
    f1=1

    disp(f0)
    disp(f1)

    for i=1:x-2
        f2=f0+f1
        f0=f1
        f1=f2
        disp(f2)
    end

endfunction

//------------------------------------------------------------------------

s=input("Enter string to check palindrome :",'s')
disp(is_palindrome(s))

A=[1,2,3;
   5,4,9;
   6,4,7]
   
B=transpose(A)
disp(B)


x=input("Factorial of : ")
disp(fact(x))

x=input('Finonacci series terms : ')
fibb(x)


//ans 2

disp("-------- GRADESHEET --------")

disp("Enter marks (0 to 100): ")

sub1=input("Subject 1 : ")
sub2=input("Subject 2 : ")
sub3=input("Subject 3 : ")
sub4=input("Subject 4 : ")

total = sub1 +sub2 + sub3+ sub4
per = total/4


disp("---------RESULT ------------")

mprintf("Subject 1 : %d\n",sub1)
mprintf("Subject 2 : %d\n",sub2)
mprintf("Subject 3 : %d\n",sub3)
mprintf("Subject 4 : %d\n",sub4)
mprintf("Total     : %d\n",total)
mprintf("Percentage: %d\n",per)

if per <35 then
    disp("Fail")
elseif per <50
    disp("Pass Class")
elseif per <60
    disp("Second Class")
else
    disp("First Class")    
end


//ans 3
function calculator()

    disp("1 : Addition ")
    disp("2 : Subtraction")
    disp("3 : Multiplication")
    disp("4 : Division")
 
    choice=input("Enter choice : ")
    
    x=input("Enter first No. : ")
    y=input("ENter second no. :")
    
    select choice
        case 1 then
            mprintf("%d + %d = %d ",x,y,x+y)
        case 2 then
            mprintf("%d - %d = %d ",x,y,x-y)
        case 3 then
            mprintf("%d * %d = %d",x,y,x*y)
        case 4 then
            mprintf("%d / %d = %d ",x,y,x/y)
        else 
            disp("Incorrect Entry")
    end
 
endfunction

calculator()
