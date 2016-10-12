/* Question 2.1 */
entre(halloween, chocolate).
entre(thanksgiving, turkey).

side(halloween, candy).
side(halloween, soda).
side(thanksgiving, bread).
side(thanksgiving, pumpkinpie).

ingredient(candy, sugar).
ingredient(candy, foodcoloring).
ingredient(soda, water).
ingredient(soda, syrup).
ingredient(bread, egg).
ingredient(bread, flour).
ingredient(pumpkinpie, pumpkin).
ingredient(pumpkinpie, pie).

/* Question 2.2 */
meal(X,Y) :-
    entre(X,Y);
    side(X,Y).

/* Question 2.3 */
shoppinglist(X,Y) :-
    side(X,Z), ingredient(Z,Y).