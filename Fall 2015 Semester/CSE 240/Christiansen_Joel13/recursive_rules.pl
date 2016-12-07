% 1.1
ackermann(S,T,A) :- S =:= 0, A is T+1.  % Base Case
ackermann(S,T,A) :- S>0, T=:=0,         % Size n problem
    S1 is S-1, 
    ackermann(S1,1,A).
ackermann(S,T,A) :- S>0, T>0,          
    S1 is S-1,
    T1 is T-1,
    ackermann(S, T1, T2),               % Construct size n problem
    ackermann(S1, T2, A).               % Size m problem

% 1.2
exp(_,X,N) :- X =:= 0, N =:= 0, write('Error: 0^0 is undefined.').  %undefined Error case
exp(Y,X,N) :- N =:= 0, Y is 1.                                      %Base case
exp(Y,X,N) :- N > 0, 
    N1 is N-1,
    exp(Y1, X, N1),                                                 %construct size n problem
    Y is Y1*X.                                                      %size m problem

% 1.3   Not sure what the question was asking for, this is my best guess.
factorial(Y,X,N) :- 
    exp(Y1, X, N),
    factorialHelper(Y,Y1).

factorialHelper(A,X) :- X =:= 1, A is 1.    %Base case
factorialHelper(A,X) :-                     
    X1 is X-1,
    factorialHelper(A1, X-1),               %consturct the size n problem
    A is X*A1.                              %Size m problem