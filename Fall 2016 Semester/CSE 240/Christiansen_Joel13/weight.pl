% 2.1
weight(R,O,Y,G,B) :- 
    member(B, [0,1,2,3,4,5,6]),
    member(G, [0,1,2,3,4,5,6,7]),
    member(Y, [0,1,2,3,4,5,6,7,8,9,10]),
    member(O, [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]),
    S is B*5 + G*4 + Y*3 + O*2,
    S =< 30,
    R is 30-S.

% 2.2
/*

G = 0
O = 5
Y = 0 ? ;

G = 0
O = 2
Y = 2 ? ;

G = 1
O = 3
Y = 0 ? ;

G = 1
O = 0
Y = 2 ? ;

G = 2
O = 1
Y = 0 ? ;

*/

% 2.3
/*

no

*/