#include <iostream>
#include "../../LinkClass_include/Queue/my_queue.h"
#include "token.h"
#include "operator.h"
#include "number.h"
#include "../../LinkClass_include/Stacks/my_stack.h"
#include "../../LinkClass_include/nodes/node_template.h"
#include "../../LinkClass_include/LinkList_functions/linklist_template_function.h"
#include "../../LinkClass_include/lists/list_templated.h"
#include "points.h"
#include "../TwoBalls/game.h"


using namespace std;

void test_token_functions();

void test_operator_functions();

int main()
{


    Game game;

    game.run();
    

    return 0;
    






//    input = t.input();

//    after_shunt = t.Shunt(input);

//    cout<<"after shunt is "<< after_shunt<<endl;

//    answer = t.RPN(after_shunt);

//    cout<<"answer is: "<< answer<<endl;

//    Queue<Token*> input1;
//    Queue<Token*> after_shunt1;

//    input1.push(new Number(5));
//    input1.push(new Operator('*'));
//    input1.push(new Number(2));
//    input1.push(new Operator('-'));
//    input1.push(new Number(3));
//    input1.push(new Operator('*'));
//    input1.push(new Number(4));
//    input1.push(new Operator('+'));
//    input1.push(new Number(2));
//    input1.push(new Operator('+'));
//    input1.push(new Number(10));
//    input1.push(new Operator('/'));
//    input1.push(new Number(5));

//    cout<< "Queue input1 is "<<input1<<endl;

//    after_shunt1 = c.Shunt(input1);

//    answer = t.RPN(after_shunt1);

//    cout<<"answer is: "<< answer<<endl;


//    Queue<Token*> input2;
//    Queue<Token*> after_shunt2;

//    input2.push(new Number(5));
//    input2.push(new Operator('+'));
//    input2.push(new Operator('('));
//    input2.push(new Number(7));
//    input2.push(new Operator('-'));
//    input2.push(new Number(4));
//    input2.push(new Operator(')'));
//    input2.push(new Operator('*'));
//    input2.push(new Operator('('));
//    input2.push(new Operator('('));
//    input2.push(new Number(3));
//    input2.push(new Operator('+'));
//    input2.push(new Number(2));
//    input2.push(new Operator(')'));
//    input2.push(new Operator('*'));
//    input2.push(new Operator('('));
//    input2.push(new Number(4));
//    input2.push(new Operator('-'));
//    input2.push(new Number(2));
//    input2.push(new Operator(')'));
//    input2.push(new Operator(')'));

//    cout<< "Queue input2 is "<<input2<<endl;

//    after_shunt2 = c.Shunt(input2);

//    cout<<"after_shunt2 is "<<after_shunt2<<endl;

//    answer = t.RPN(after_shunt2);

//    cout<<"answer is: "<< answer<<endl;


//    return 0;
}


void test_token_functions(){
    Token* t1 = new Number(7);
    cout<<"Token t1 after setting to 7 is: ";
    cout<<t1<<endl;

    Token* t2 = new Number(8);
    cout<<"Token t2 after setting to 8 is: ";
    cout<<t2<<endl;

    Token* t3 = new Number(9);
    cout<<"Token t3 after setting to 9 is: ";
    cout<<t3<<endl;

    Token* t4 = new Number(10);
    cout<<"Token t4 after setting to 10 is: ";
    cout<<t4<<endl;

    Token* t5 = new Operator('+');
    cout<<"Token t5 after setting to + is: ";
    cout<<t5<<endl;

    Token* t6 = new Operator('-');
    cout<<"Token t6 after setting to - is: ";
    cout<<t6<<endl;

    Token* t7 = new Operator('*');
    cout<<"Token t7 after setting to * is: ";
    cout<<t7<<endl;

    Token* t8 = new Operator('/');
    cout<<"Token t8 after setting to / is: ";
    cout<<t8<<endl;
}


void test_operator_functions(){
    Operator add('+');

    cout<<"+'s precedence is "<<add.get_preceden()<<endl;

    Operator minus('-');

    cout<<"-'s precedence is "<<minus.get_preceden()<<endl;

    Operator product('*');

    cout<<"*'s precedence is "<<product.get_preceden()<<endl;

    Operator divide('/');

    cout<<"/'s precedence is "<<divide.get_preceden()<<endl;

    Queue<Token*> input2;
    Queue<Token*> after_shunt2;

    input2.push(new Number(5));
    input2.push(new Operator('+'));
    input2.push(new Number(3));
    input2.push(new Operator('^'));
    input2.push(new Number(2));
    input2.push(new Operator('*'));
    input2.push(new Operator('('));
    input2.push(new Number(3));
    input2.push(new Operator('+'));
    input2.push(new Number(4));
    input2.push(new Operator(')'));
    input2.push(new Operator('-'));
    input2.push(new Number(5));
    input2.push(new Operator('*'));
    input2.push(new Operator('('));
    input2.push(new Number(6));
    input2.push(new Operator('/'));
    input2.push(new Number(3));
    input2.push(new Operator(')'));
    input2.push(new Operator('+'));
    input2.push(new Number(2));


//    cout<< "Queue input2 is "<<input2<<endl;

//    after_shunt2 = c.Shunt(input2);

//    cout<<"after_shunt2 is "<<after_shunt2<<endl;

//    answer = t.RPN(after_shunt2);

//    cout<<"answer is: "<< answer<<endl;


    input2.push(new Number(5));
    input2.push(new Operator('*'));
    input2.push(new Number(7));
    input2.push(new Operator('^'));
    input2.push(new Number(2));
    input2.push(new Operator('+'));
    input2.push(new Operator('('));
    input2.push(new Number(2));
    input2.push(new Operator('-'));
    input2.push(new Number(1));
    input2.push(new Operator(')'));
}
