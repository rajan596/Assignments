1.  Is Albert a parent of Peter?
parent(albert,peter).
true 

2. Who is the child of Jim?
parent(jim,X).
X = brian.

3. Who are the parents of Brian?
parent(X,brian).
X = jim 

4. Is Irene a grandparent of Brian?
parent(irene,parent(X,brian)).
false.

5. Find all the grandchildren of Irene
% grand(X,Z) :- parent(X,Y) , parent(Y,Z).
grand(irene,X).
Ans : 
X = brian ;
X = lee ;
X = sandra ;
X = james ;
X = kate ;
X = kyle.

6. Now add the following rule to familytree.pl and re-consult:
  older(Person1, Person2) :-
  yearOfBirth(Person1, Year1),
  yearOfBirth(Person2, Year2),
  Year2 > Year1.
  
7.  Who is older than Pat?
older(X,pat).
X = irene ;
X = albert ;
X = jim ;
X = peter ;
false.

8.  Who is younger than  Darren?
older(darren,X).
X = jenny ;
X = amanda ;
false.

9.  List the siblings of Sandra.
% sibbling(X,Y) :- parent(Z,X) , parent(Z,Y) , X\=Y.
sibbling(sandra,Y).
Y = lee ;
Y = james ;
Y = kate ;
Y = kyle.

10.  Who is the older brother of Sandra?
% olderbrother(X,Y):- parent(Z,X) , parent(Z,Y) , X\=Y ,male(Y).
olderbrother(X,sandra).
false.

11.  Find the predecessors of Kyle.
%predecessor(X,Z):-parent(X,Z).
%predecessor(X,Z):-parent(X,Y),predecessor(Y,Z).

predecessor(X,kyle).
Ans :
X = peter ;
X = albert ;
X = irene ;

12.  Does Kate have a sister? 
% sister(X,Y):-parent(Z,X) , parent(Z,Y) , X\=Y,female(Y).
sister(kate,X).
X = lee ;
X = sandra ;
false.

13. How many females and males are there in the knowledge base?
aggregate_all(count , female(X),Count) , aggregate_all(count,male(X),Count1).
Ans:
Count = 7,
Count1 = 8.

****************************************  (( familytree.pl  )) **********************************

% Program:  family.pl
% Source:   Prolog
%
% Purpose:  This is the sample program for the Prolog Lab in COMP9414/9814/3411.
%           It is a simple Prolog program to demonstrate how prolog works.
%           See lab.html for a full description.
%
% History:  Original code by Barry Drake


% rules 

% grand( irene , X)
grand(X,Z) :- parent(X,Y) , parent(Y,Z).

% if Person2 > Person1 => true
older(Person1, Person2) :- yearOfBirth(Person1, Year1), yearOfBirth(Person2, Year2), Year2 > Year1.

% sibbling(irene , X )
sibbling(X,Y) :- parent(Z,X) , parent(Z,Y) , X\=Y.

% olderbrother( irene ,  X )
olderbrother(X,Y):- parent(Z,X) , parent(Z,Y) , X\=Y ,male(Y).

% predesessor( irene , X)
predecessor(X,Z):-parent(X,Z).
predecessor(X,Z):-parent(X,Y),predecessor(Y,Z).

% sister( X , variable)
sister(X,Y):-parent(Z,X) , parent(Z,Y) , X\=Y,female(Y).


% parent(Parent, Child)
%
parent(albert, jim).
parent(albert, peter).
parent(jim, brian).
parent(john, darren).
parent(peter, lee).
parent(peter, sandra).
parent(peter, james).
parent(peter, kate).
parent(peter, kyle).
parent(brian, jenny).
parent(irene, jim).
parent(irene, peter).
parent(pat, brian).
parent(pat, darren).
parent(amanda, jenny).


% female(Person)
%
female(irene).
female(pat).
female(lee).
female(sandra).
female(jenny).
female(amanda).
female(kate).

% male(Person)
%
male(albert).
male(jim).
male(peter).
male(brian).
male(john).
male(darren).
male(james).
male(kyle).


% yearOfBirth(Person, Year).
%
yearOfBirth(irene, 1923).
yearOfBirth(pat, 1954).
yearOfBirth(lee, 1970).
yearOfBirth(sandra, 1973).
yearOfBirth(jenny, 2004).
yearOfBirth(amanda, 1979).
yearOfBirth(albert, 1926).
yearOfBirth(jim, 1949).
yearOfBirth(peter, 1945).
yearOfBirth(brian, 1974).
yearOfBirth(john, 1955).
yearOfBirth(darren, 1976).
yearOfBirth(james, 1969).
yearOfBirth(kate, 1975).
yearOfBirth(kyle, 1976).
