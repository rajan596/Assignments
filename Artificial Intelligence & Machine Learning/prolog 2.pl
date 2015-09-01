1. Create your own predicates to find whether a symbol entered by the user is an alphabet
   using the concept of recursion and lists.(Hint: Use the 26 alphabets as a list)

alphabets(X,[X|T]).
alphabets(X,[H|T]):- 
	alphabets(X,T).

RUN : 
alphabets(a,[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z]).
Ans : 
true

alphabets(aa,[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z]).
false.


