#  Module 7 - Algorithm Analysis

----
## :notebook: Notes :notebook:
----

**Concept**: 

### Primality Testing
    Only divisors are 1 and the num.
    
    k*d = num
    4*25 = 100; 4 and 25 are called complementary divisors

### Runtime Analysis
    Depends on the size of the input
    Compare the number of primitive operations executed by a process, as a function of its input size
        e.g; each primitive operations count as 1

### Asymptotic Analysis (Big-O or Theta)
    Measures the order of growth of the function
    Depends on machine hardware technology

### Probability
    Definition: If S is a finite nonempty sample space of equally likely outcomes, and E is an event, that is, a subset of S, then the probability of E is p(E) = |E| / |S| 
    For every event E, we have 0 <= p(E) <= 1. 
    
    Sample space = set of possible outcomes
    Event = subset of the sample space
    
### Union Probability
    p(E1 U E2) = p(E1) + p(E2) - p(E1 ∩ E2)

### Assigning Probability
    Probability distribution = the set of all outcomes of the sample space S
        i. 0 <= p(s) <= 1 for each s in S
        ii. sum of p(s) = 1
        
        e.g. Fair coin flipped p(H) = p(T) = 1/2
        p(H) + p(T) = 1
        
### Conditional Probability
    Definition: p(E|F) = p(E ∩ F) / p(F)
    
### Independence 
    Definition: The events E and F are independent if and only if p(E∩F) = p(E)p(F)

### Pairwise & Mutual Independence
    Definition: p(Ei ∩ Ej) = p(Ei)p(Ej) 
    
    The events are mutually independent if 
    p(Ei1 ∩ Ei2 ∩ . . . ∩ Eim ) = p(Ei1)p(Ei2) . . . p(Eim)
