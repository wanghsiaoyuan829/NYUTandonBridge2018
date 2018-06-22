#  Module 15 - Object Oriented Programming

----
## :notebook: Notes :notebook:
----

**Concept**: 

### 

![Array Syntax 1](https://github.com/Nam-H-Nguyen/NYUTandonBridge2018/blob/master/Week%206%20-%20Array%2C%20String%2C%20Bernoulli%2C%20Expected%20Value/notes/images/array_syntax1.png)

### Object 
    Instance of a class (represent data: i.e. House)
    
### Classes
    Framework which is used to build multiple similar objects (i.e. Blueprint for a house)
    By default, classes are set to 'private'
    
    class Date {
    public: 
        int day;
        int month;
        int year;
    public:
        void setDat(int newDay);
        void setMonth(int newMonth);
        // setYear is defined in the class
        void setYear(int newYear) {
            year = newYear:
        }
    }
    // setDay is defined outside the class
    void Date::setDay(int newDay) {
        if (newDay > 0 && newDay <= 31)
            day = newDay;
    }
    void Date::setMonth(int newMonth) {
        if (newMonth > 0 && newMonth <= 31)
            month = newMonth;
    }
    Private classes: cannot access to any variables; encapsulation (protects data from public access)
    
    Accessors (getters): functions used to get information out of the class
    Mutators (setters: functions used to put information into the class

    These functions are members of the class. Members have access to the private information (data, variables, etc. ) inside the class
    
    '::' = Scope resolutions operator. 

### Const Objects
    Consta-fied objects are passed to the functions to make sure the public can't change the data inside
    
### Constructors
    When we create an object, immediately it would be set to a garbage value. 
    A Constructor are functions called immediately after an object is created to set a default value for the object.
        -Same name as class
        -No return type and not void 
        -No parameters
    
    Can take multiple parameters and initialized all at once or separately
    
### 'this' Pointer
    C++ creates an interesting structure everytime an object is created called 'this.' 
    'this' points to the object itself.
        example:) a.setYear; this would point to 'a' 
        
### Operator Overloading
    operator+(a, b) = non-member function call of a + b
    a.operator+(b) = member function call 'this' is one of the operand
    
    Some operators return the data in an object
    Some operators return a new object

### Polymorphisms
    Copy data from derivative class object to base class object (copy data from cat to pet object).
    p = c take cat and store it into pet always works, also known as 'slicing'
    c = p is allowed IF operator = (const Pet&) is overloaded
    pptr = &c polymorphism where the pet pointer points to cat derived data type

### Virtual Function
    C++ Assumptions: Base class pntr points to bass class objects. 
    However, Polymorphism calls base class pointer function to point to derived class object. Thus, unfortunately even if we use polymorphism, C++ still uses a version of base class pointer to point at bass class objects.
    If we use destructors to destroy the derived class, we would accidentally destroy the base class instead = catastrophic.
    SOLUTION: Mark the function as VIRTUAL in the base class. 
    Late or dynamic binding at runtime, C++ decides which version of the function to call at the end of the runtime NOT at compile time. THUS, the version of function call depends on the TYPE OF OBJECT NOT POINTER.
    
### Pure Virtual Function
    Pure virtual function: 'virtual void speak() const =0' 
        Marked with a '=0'
    Use Case: if base class should contain a function, but it does not know what the function would actually do, it can be marked as a pure virtual function

### Webinar
    Copy data not copy pointers. 
    When creating memory in the constructor, we need to destroy data that falls out of scope

____

# Reading Notes

    Object: is a variable that has member functions
    Class: is a data type whose variables are objects. Thus, the definition of a class should be a data type definition that describes two things: (1) what kinds of values the variables can hold and (2) what the member functions are
    
### Struct
    Definition - can be thought of as an object without any member functions
    
    ```
    struct CDAccount {
    double balance;
    double interest_rate;
    int term; //months until maturity
    };
    ```
    
    A structure value is a collection of smaller values called member values. There is one member value for each member name declared in the structure definition. For example, a value of the type CDAccount is a collection of three member values: two of type double and one of type int. The member values that together make up the structure value are stored in member variables
    
    CDAccount my_account, your_account, account;
    my_account, account, your_account = structure variables
    balance, interest_rate, and term = member variables
    
    Can be assigned like normal variables
    account.balance = 1000.00;
    account.interest_rate = 4.7;
    account.term = 11;
    
    You specify a member variable for a structure variable by using the dot operator in the same way you used it in Chapter 6, where the dot operator was used to specify a member function of a class. The only difference is that in the case of structures, the members are variables rather than functions.
    
    Two or more structure types may use the same member names
    ```
    struct FertilizerStock {
        double quantity;
        double nitrogen_content; };
    struct CropYield {
        int quantity;
        double size; };
    ```
    
    FertilizerStock super_grow;
    CropYield apples;
    
    The two similar member names will produce no problems. 
    Quantity of super_grow fertilizer is stored in the member variable super_grow.quantity and the quantity of apples produced is stored in the member variable apples.quantity
