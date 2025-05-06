
(defun square (v)
(setq square_i 0)
(* v v)
)
(defun fact (n)
(setq fact_f 0)
(if (= n 1)
(progn
(setq fact_i 0)
(loop while (< fact_i 10) do
(princ fact_i)
(setf fact_i (+ fact_i 1))))
(setf fact_f (* n (fact (- n 1)))))
fact_f
)
(defun is_even (v)
(setq is_even_ep 0)
(setq is_even_mivector (make-array 10))
(princ v)
(loop while (> v 0) do
(setf v v))
(if (= (mod v 2) 0)
(progn
(print " is even")
(setf is_even_ep 1))
(progn
(print " is odd")
(setf is_even_ep 0)))
(setf (aref is_even_mivector 5) 123)
is_even_ep
)
(defun main ()
(princ (square 7))
(princ (fact 7))
(princ (is_even 7))
(princ (is_even 8))
(is_even 8)
)
 (main)
