//creating array
A=[1,2,3;4,9,6;7,8,9]
B=[1,2,3;4,2,3;1,9,3]

//display array
disp("A:")
disp(A)

disp("B:")
disp(B)

// Transpose of A
disp("Transpose of A:")
disp(A')

//Add A+B
disp("A+B : ")
disp(A+B)

//Multiply A*B
disp("A*B : ")
disp(A*B)

// Multiplying individual elements of A with B
disp("A.*B : ")
disp(A.*B)

//Square of individual elements
disp("A.^2 : ")
disp(A.^2)

disp("B.^B : ")
disp(B.^2)

//First raw of A
disp("First raw of A : ")
disp(A(1,:))

//last column of B
disp("last column of B")
disp(B(:,$))

// determinanat
disp("Determinant of A :")
disp(det(A))

//Inverse of B
disp("Inverse of B")
disp(inv(B))

//Array using random function
disp("Creating array using random function")
A=rand(5,6)*10
disp(A)

//string in a variable
line="I am an Indian"
disp(line)

//type
disp("Type of A : ")
disp(typeof(A))

//Sub matrix
disp(A(3:4, 2:5))

// variable Exists or not 
disp("If Exists variable A : ")
disp(exists("A"))

//Removing variable
disp("Removing line variable")
clear line
disp(line)   // it will show error

