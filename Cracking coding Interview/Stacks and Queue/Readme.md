## Remaining questions that are easy or already implemented
Q-1       Min stack
Approach  To push - if coming element(x) is smaller than current minEle then push 2*x-minEle else push x simple
          To pop  - if s.top() < minEle then minELe = 2*minEle - s.top() then pop else simple pop
          
