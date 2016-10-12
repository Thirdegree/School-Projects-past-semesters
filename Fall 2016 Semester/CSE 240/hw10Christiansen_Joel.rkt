#lang racket
;Q1
(+ 7 3 5)
(+ 3 3 5 7)
(+ (* 3 2) (* 3 8 8))
(+ (+ (* 3 2) (* 9 9)) (/ 18 3))
(/ (+ 2 3 6 8 10 12 14) (+ 2 3 6))

;Q2
(define three 3)
(+ 7 three 5)
(+ three three 5 7)
(+ (* three 2) (* three 8 8))
(+ (+ (* three 2) (* 9 9)) (/ 18 three))
(/ (+ 2 three 6 8 10 12 14) (+ (+ 2 three) 6))

;Q3
(define base 5)
(define height 10)
(define (RectArea base height) (* base height))
(RectArea base height)

;Q4
(define (RectVol base height depth) (* (RectArea base height) depth))
;(display (RectVol base height (read)))

;Q5
(define (DiffVolume base1 height1 depth1 base2 height2 depth2) ;this is super messy
  (- (RectVol base1 height1 depth1) (RectVol base2 height2 depth2)))
(DiffVolume 1 1 1 1 1 2)

;Q5
(let RectAreaLet ([base 5] [height 10]) (* base height))

;Q6
(let RectVolLet ([base 5] [height 10]) (* base height (read)))

;I really, really like this language. 