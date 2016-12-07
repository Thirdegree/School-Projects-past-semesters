foo([],[]) :- !.
foo([H|T], NL) :- member(H,T), foo(T,NL), !.
foo([H1|T1], [H1|T2]) :- foo(T1, T2).