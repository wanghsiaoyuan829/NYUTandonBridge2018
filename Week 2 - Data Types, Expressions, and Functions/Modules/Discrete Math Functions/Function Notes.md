#  Module 2 - Positional Number System

----
## :notebook: Notes :notebook:
----

### What is a function?
    A nonempty set that is maps element of A to an element of B
    
    f: A -> B (function f from A to B, an assignment of exactly one element of B to each element of A)
    f(a) = b (b is the unique element of B assigned by the function f to the element a of A)
        
        Carlos can get grade A. Sandeep can also get grade A. A student is mapped onto a specific grade. A student cannot get two grades in one class. 
        
### Domain vs. Codomain, Image vs Preimage, Range
    f: A -> B 
    f maps A to B 
    A = Domain of f
    B = Codomain of f

    f(a) = b
    b is the image of a
    a is the preimage of b
    Range of f = set of all images of elements of A
    
### Equal Functions
    Two functions are equal when they have the same domain, have the same codomain, and map each element of their common domain to the same element in their common codomain.
    
### One-to-One Functions
    Definition: Some functions never assign the same value to two different domain elements. These functions are said to be one-to-one.
    
        We can express that f is one-to-one using quantifiers as ∀a∀b(f (a) = f (b) → a = b) or equivalently ∀a∀b(a ̸= b → f (a) ̸= f (b))

### Onto Functions (Surjection)
    Definition: For some functions the range and the codomain are equal. That is, every member of the codomain is the image of some element of the domain. Functions with this property are called onto functions.

    A function f from A to B is called onto, or a surjection, if and only if for every element b∈B there is an element a∈A with f(a)=b. A function f is called surjective if it is onto.
    
### Bijection Function
    Definition: Both one-to-one and onto. We also say that such a function is bijective.
