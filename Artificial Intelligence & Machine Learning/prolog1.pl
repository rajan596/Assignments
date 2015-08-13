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
grand(X,Y).
X = albert,
Y = brian ;
X = albert,
Y = lee ;
X = albert,
Y = sandra ;
X = albert,
Y = james ;
X = albert,
Y = kate ;
X = albert,
Y = kyle ;
X = jim,
Y = jenny ;
X = irene,
Y = brian ;
X = irene,
Y = lee ;
X = irene,
Y = sandra ;
X = irene,
Y = james ;
X = irene,
Y = kate ;
X = irene,
Y = kyle ;
X = pat,
Y = jenny ;
false.

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

12.  Does Kate have a sister? 
% sister(X,Y):-parent(Z,X) , parent(Z,Y) , X\=Y,female(Y).
sister(kate,X).
X = lee ;
X = sandra ;
false.

13. How many females and males are there in the knowledge base?


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
grand(X,Z) :- parent(X,Y) , parent(Y,Z).
older(Person1, Person2) :- yearOfBirth(Person1, Year1), yearOfBirth(Person2, Year2), Year2 > Year1.
sibbling(X,Y) :- parent(Z,X) , parent(Z,Y) , X\=Y.
olderbrother(X,Y):- parent(Z,X) , parent(Z,Y) , X\=Y ,male(Y).
predecessor(X,Z):-parent(Y,X),predecessor(Y,Z).
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
