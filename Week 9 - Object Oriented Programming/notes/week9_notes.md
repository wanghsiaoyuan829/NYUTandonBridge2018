#  Module 15 - Object Oriented Programming

----
## :notebook: Notes :notebook:
----

**Concept**: 

### 

![Array Syntax 1](https://github.com/Nam-H-Nguyen/NYUTandonBridge2018/blob/master/Week%206%20-%20Array%2C%20String%2C%20Bernoulli%2C%20Expected%20Value/notes/images/array_syntax1.png)

### Classes
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
