## Remaining questions that are easy or already implemented
Q-1       Min stack
Approach  To push - if coming element(x) is smaller than current minEle then push 2*x-minEle else push x simple
          To pop  - if s.top() < minEle then minELe = 2*minEle - s.top() then pop else simple pop
Q-2       Queue using stacks
Approach  Use 2 stacks we have to make either push operation costly or pop. we will shift element from 1 stack to other for any of operation which we choose to make costly


          
