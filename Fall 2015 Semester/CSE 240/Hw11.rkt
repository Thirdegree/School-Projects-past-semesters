#lang racket

;Q1
(define (Ackermann s t) (cond
                         [(zero? s) (+ t 1)] ;Stopping condition + return value
                         [(and (positive? s) (zero? t)) (Ackermann (- s 1) 1)] ;Size n problem
                         [(and (positive? s) (positive? t))
                          (Ackermann (- s 1) ;Construct size n problem
                                    (Ackermann s (- t 1)) ;Construct size n problem
                                    )] ;Side M problems
                         ) ;weird indenting is so comments can be made in a sane way
  )
#|
(Ackerman 0 0)
(Ackerman 1 1)
(Ackerman 2 3)
(Ackerman 3 4)
(Ackerman 3 7)
|#
;Q2
(define (combine-four lst1 lst2 lst3 lst4) (append lst1 lst2 lst3 lst4))
;(combine-four '(1 2) '(3 4) '(5 6) '(7 8 9))

;Q3
(define (last-n lst n) (drop lst (- (length lst) n)))
;(last-n '(1 6 3 4 5) 2)
((lambda (lst n) (drop lst (- (length lst) n))) '(1 6 3 4 5) 2)

;Q4
(define (first-n lst) (take lst (read)))
;(first-n '(1 5 3 4 5))

;Q5
(define (shuffle lst1 lst2) (cond
                              [(empty? lst1) (append (take lst2 1) '())]
                              [(positive? (- (length lst2) (length lst1))) (append (take lst2 1) (shuffle lst1 (list-tail lst2 1)))]
                              [else (append (take lst1 1) (shuffle (list-tail lst1 1) lst2))]
                              )
  )

;(shuffle '(1 2 3) '(a b c))

;Q6
(define (shufflePairs one two) (cond
                                 [(empty? one) '()]
                                 [else (cons (append (take one 1) (append (take two 1) '())) (shufflePairs (list-tail one 1) (list-tail two 1)))]
                                 )
  )
(shufflePairs '(1 2 3) '(a b c))

;Q7
(define (addSquare lst) (cond
                          [(empty? lst) "Empty list"]
                          [else (addNonEmptyList lst)]))
(define (addNonEmptyList lst) (cond
                                [(empty? lst) 0]
                                [else (foldl + 0 (map (lambda (x) (expt x 2)) lst))]
                                )
  )
#|
(addSquare '())
(addNonEmptyList '())
(addNonEmptyList '(1 2 3))
(addNonEmptyList '(1 4 3 2))
|#