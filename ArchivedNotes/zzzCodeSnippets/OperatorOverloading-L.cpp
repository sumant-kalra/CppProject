// Operator overloading Concepts

#include <iostream>

class Vector2D
{
private:
	float m_x;
	float m_y;

public:
	Vector2D(float x, float y):
		m_x(x), m_y(y){}

	Overload the operators +,*,==,=

	Vector2D operator+(const Vector2D& second)
	{
		return Vector2D(m_x + second.m_x, m_y + second.m_y);
	}

	Vector2D operator*(const int factor)
	{
		return Vector2D(m_x * factor, m_y * factor);
	}
	
	bool operator==(const Vector2D& second)
	{
		return (m_x == second.m_x && m_y == second.m_y);
	}

	Vector2D& operator=(const Vector2D& second)
	{
		m_x = second.m_x;
		m_y = second.m_y;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& obj, const Vector2D& vectorObject);

};

// Overloading the << operator
// std::ostream can not be const since the object is being modified in the definition
std::ostream& operator<<(std::ostream& obj,const Vector2D& vectorObject)
{
	obj << "X= " << vectorObject.m_x << ", Y= " << vectorObject.m_y;
	return obj;
}

int main()
{
	Vector2D obj1(2, 3);
	Vector2D obj2(4, 5);
	std::cout << obj1 + obj2 << "\n";
	std::cout << obj1*5 << "\n";
	obj2 = obj1;
	std::cout << obj2 << "\n";

	return 0;
}

/*
Operator Overloading: 

[1] [Definition. Why is it needed? Precautions?]
    It is just a syntactical sugar over the functions (the operator's symbol is used in the place of function name) such that the developers 
    don't have to look for the function definition to understand what function does, the symbol should be good enough to understand 
    the use of the overload.
    C++ allows developers to overload operators in any way they want. So, the operator overloading should be used responsibly keeping the original
    definition/meaning of operator intact. For example, if the add operator (+) is used to multiply two numbers then the whole thing loses its
    purpose. The language puts no other constraints on what the overloaded operators do, or on the return type (it does not participate in 
    overload resolution), but in general, overloaded operators are expected to behave as similar as possible to the built-in operators like
    operator+ is expected to add, rather than multiply its arguments, operator= is expected to assign, etc. 
    Other related operators are expected to behave similarly (operator+ and operator+= do the same addition-like operation). 

    Refer cppreference.com or cplusplus.com for the original declaration/definitions of the operators.
    
    [Not all the operators can be overloaded]

[2] [Overloading as a non member function or a member method of a class]
    As a 'Non-Member' function: 
            [Fundamental to understanding operator overloading]
            returnType operator<operatorSymbol>(<leftOperand parameter definition>,<rightOperand parameter definition>);
            returnType can be a reference, copy (or a pointer) depending upon the operator definition.
        USAGE as an operator: dataType var = <leftOperand> <symbol> <rightOperand>
        USAGE as a function: dataType var = operator<operatorSymbol>(<leftOperand>,<rightOperand>);
    As a 'Member' function of a class: 
            that is, defined inside the class of the <leftOperand>:
            returnType operator<operatorSymbol>(<rightOperand parameter definition>);
            the <leftOperand> is the object of the class in which the operator is defined
            returnType can be a reference, copy (or a pointer) depending upon the operator definition.
        USAGE as an operator: dataType var = <leftOperand> <symbol> <rightOperand> 
    	USAGE as a function: dataType var = <leftOperand>.operator<symbol>(<rightOperand>) [since the operator is a member method of the class]
    Some operators can be overloaded in one of the two ways described above that is either as a 'Non-Member' function or as 'Member' function 
    while some can be overloaded in both the ways. It all depends upon whether the class can be modified to include a new definition 
    of the operator.
    
    Note: 
    [I] If the operator is overloaded as a 'Non-Member' method then it has to be declared as a friend inside the class if it needs to access
        the private members of the class objects.
    [II] If the operator is to be overloaded as a 'Member' method then the definition should be in the left operand's class.

[4] [Return void, Return by reference or Return by value]
    [Keep the corresponding usage as a function call in mind to sort out all the confusion about the return type]
    [Do I need to return anything? If yes, then by reference or by value?]
    
    [4.1] [void] : By default - then think do we need to return anything, if yes then decide - by value or by reference
            Most of the times, when we modify the object itself, we return void but there are some cases where we have to return something to 
            get the chaining like a=b=c=d or std::cout<<a<<b<<c<<d, then we have to return reference or value. Returning anything allows chaining.
    [4.2] [Returning by reference or Return by value]
           Chaining; Modification of returned object; Avoid copy; New objects created on stack
            Return by reference:
            - When the object is not created on the stack frame of the operator call and we want to modify the object like operator[], operator<<
            - When the object is not copyable like operator<< and we want chaining
            - Returning by reference avoids un-necessary copied but it also makes the returned object available for modification.
            - If you do not want to modify the object return by const reference.
            Return by value:
            - When a new object is created on stack and we want the chaining
The return types are limited by the expressions in which the operator is expected to be used: for example, assignment operators return by reference to make it possible to write a = b = c = d, because the built-in operators allow that.

Note: 
[1] std::istream and std::ostream are not copyable, so trying to return objects of those types by value is wrong and they must be 
    returned by reference. Not returning void, which we could because we want the branching std::cout<<a<<b<<c<<d;
[2] std::istream and std::ostream should not be passed as 'const' references because they are actually modified when data is entered in the stream.
[3] friend and namespace : I. First define the function in a namespace and then II. Declare it as a friend with appropriate namespace.
[4] [] operator:  This function must return a reference as array element can be put on left side. 
[5] = operator: The operator assigns a new value to an existing object. There is no need to create a new object and return it
                contrary to what we do for +, -, *, / etc operators. It is similar to the copy constructor.
                However, we can return the copy of the object passed as argument to enable the branching a=b=c=d;

Important Links
https://stackoverflow.com/questions/3858675/where-can-one-find-a-list-of-operator-overloads/49026261#49026261 
https://stackoverflow.com/questions/4421706/what-are-the-basic-rules-and-idioms-for-operator-overloading/4421715#4421715
https://stackoverflow.com/questions/21485366/why-we-use-reference-return-in-assignment-operator-overloading-and-not-at-plus-m
https://stackoverflow.com/questions/2337213/return-value-of-operator-overloading-in-c
https://tutorialspoint.dev/language/cpp/overloading-array-index-operator
https://stackoverflow.com/questions/58656643/const-reference-to-the-ostream-class-object
https://www.ibm.com/docs/en/zos/2.4.0?topic=only-namespaces-friends-c

*/



