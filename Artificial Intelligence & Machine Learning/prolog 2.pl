1. Create your own predicates to find whether a symbol entered by the user is an alphabet
   using the concept of recursion and lists.(Hint: Use the 26 alphabets as a list)

alphabets(X,[X|T]).
alphabets(X,[H|T]):-
	alphabets(X,T).

find:-
	write('enter any value..'),nl,
	read(Input),nl,
	alphabets(Input,[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z]).

