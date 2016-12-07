/* Database for family. It consists of facts and rules. */

/* Facts */
male(mark).
male(tom).
	male(eric).
	male(josh).
	male(austin).

female(jen).
female(beth).
	female(lisa).
	female(alice).
	female(alex).



father_of(mark, beth). /*mark is the father of beth */
	father_of(josh, eric).
	father_of(austin, alice).
	father_of(eric, jen).

mother_of(jen, tom). /*jen is the mother of tom*/
	mother_of(lisa, eric).
	mother_of(alex, alice).
	mother_of(alice, jen).

/* Rules */
is_male(X) :-
	male(X);
	father_of(X, _).

/* Question 1.2 */
is_female(X) :-
	female(X);
	mother_of(X,_).

/* Question 1.3 */
grandmother_of(X,Z) :-
	(mother_of(X, Y), mother_of(Y,Z));
	(mother_of(X, Y), father_of(Y,Z)).

grandfather_of(X,Z) :-
	(father_of(X,Y), mother_of(Y,Z));
	(father_of(X,Y), father_of(Y,Z)).

/*Question 1.4 */
sibling_of(X,Y) :-
	(father_of(Z,X), father_of(Z,Y));
	(mother_of(Z,X), mother_of(Z,Y)).

/*Question 1.5 */
parent_of(X,Y) :-
	father_of(X,Y); mother_of(X,Y).

/*Question 1.6 */
decendent_of(X,Y) :-
	parent_of(Y,X);
	(parent_of(Y,Z), decendent_of(Z,Y)).
