#include "token.h"
#include <iostream>
#include "number.h"
#include "operator.h"
#include <cassert>
#include <math.h>
#include <string>

using namespace std;

Token::Token()
{
    //left blank
}

void Token::show(){
    //    cout<<"In token's show function, You are fucked son\n";

}


double Token::get_value(){
    //    cout<<"In token's get_value function, You are fucked son\n";

}

bool Token::is_variable(){
    //    cout<<"In token's is_variable function, You are fucked son\n";

}


void Token::set_value(double value){
    //    cout<<"In token's set_value function, You are fucked son\n";

}



char Token::get_face(){
    //    cout<<"In token's get_face function, You are fucked son\n";
    return NULL;
}

int Token::get_preceden(){
    //    cout<<"In token's get_preceden function, You are fucked son\n";

}


double Token::string_to_double(string numbers){

    double sum = 0;

    int temp = 0;

    int power = 0;

    int num =0;


    for(int i = 0; i < numbers.size(); i++){

        if(numbers[i] == '.'){

            i++;

            power = numbers.size() - i;


            for(int j = 1; j <= power; j++ ){

                temp = static_cast<double>(numbers[i] - '0');

                sum += pow(10, -j) * temp;

                i++;
            }

        }



        else{

            for(int i = 0; i < numbers.size(); i++){

                if(numbers[i] == '.'){

                    num = i;

                    break;
                }

                else{

                    num = numbers.size();
                }
            }

            temp = static_cast<double>(numbers[i] - '0');

            //        cout<<"in string_to_double  temp is "<< temp<<endl;


            sum += (pow(10,(num- (i+1)))) * temp;

            cout<<"in string_to_double  sum is "<< sum<<endl;
        }
    }

    return sum;
}


Queue<Token*> Token::input_infile(string input){
    Queue<Token*> output;

    string temp;

    string number;

    double answer;

    char operation;

    char pi = 227;

    int i = 0;

    while(i <input.size()){

        //if its pi
        if(input[i] == 112){

            output.push(new Number(3.14));

            i++;

            i++;
        }

        //if its x
        else if(input[i] == 120){

            //            cout<<"temp right now is x"<<endl;

            output.push(new Number());

            i++;
        }

        //if its a number
        else if(input[i] >=48 && input[i] <=58){

            temp = "";

            while(input[i] >=48 && input[i] <=58 || input[i] ==46){

                number = input[i];

                temp +=number;

                cout<<"temp right now is"<<temp<<endl;

                i++;
            }


            answer = string_to_double(temp);

            //            cout<<"answer is "<<answer<<endl;

            output.push(new Number(answer));

        }

        //if it starts with s
        else if(input[i] == 115){

            i++;

            //if its sin
            if(input[i] == 105){

                output.push(new Operator('s'));

                i +=2;

            }

            //if its sec
            else{

                output.push(new Operator('C'));

                i +=2;

            }
        }

        //if it starts with c
        else if(input[i] == 99){

            i++;

            //if its csc
            if(input[i] == 115){

                output.push(new Operator('S'));

                i +=2;


            }

            else{

                i++;

                //if its cos
                if(input[i] == 115){

                    output.push(new Operator('c'));

                    i++;

                }

                //if its cot
                else{

                    output.push(new Operator('T'));

                    i++;

                }

            }
        }

        //if its tan
        else if(input[i] == 116){

            output.push(new Operator('t'));

            cout<<"tan in equation"<<endl;

            i +=3;

        }


        //if its any operator
        else{

            operation = NULL;

            operation = input[i];

            output.push(new Operator(operation));

            i++;
        }
    }

    cout<<"Your Highness' Input Is"<<output<<endl;

    return output;


}




Queue<Token*> Token::input(){
    Queue<Token*> output;

    string input;

    string temp;

    string number;

    double answer;

    char operation;

    char pi = 227;

    cout<<"please enter your problem your highness\n y=";

    getline(cin,input);

    int i = 0;

    while(i <input.size()){

        //if its pi
        if(input[i] == 112){

            output.push(new Number(3.14));

            i++;

            i++;
        }

        //if its x
        else if(input[i] == 120){

            //            cout<<"temp right now is x"<<endl;

            output.push(new Number());

            i++;
        }

        //if its a number
        else if(input[i] >=48 && input[i] <=58){

            temp = "";

            while(input[i] >=48 && input[i] <=58 || input[i] ==46){

                number = input[i];

                temp +=number;

                cout<<"temp right now is"<<temp<<endl;

                i++;
            }


            answer = string_to_double(temp);

            //            cout<<"answer is "<<answer<<endl;

            output.push(new Number(answer));

        }

        //if it starts with s
        else if(input[i] == 115){

            i++;

            //if its sin
            if(input[i] == 105){

                output.push(new Operator('s'));

                i +=2;

            }

            //if its sec
            else{

                output.push(new Operator('C'));

                i +=2;

            }
        }

        //if it starts with c
        else if(input[i] == 99){

            i++;

            //if its csc
            if(input[i] == 115){

                output.push(new Operator('S'));

                i +=2;


            }

            else{

                i++;

                //if its cos
                if(input[i] == 115){

                    output.push(new Operator('c'));

                    i++;

                }

                //if its cot
                else{

                    output.push(new Operator('T'));

                    i++;

                }

            }
        }

        //if its tan
        else if(input[i] == 116){

            output.push(new Operator('t'));

            i +=3;

        }


        //if its any operator
        else{

            operation = NULL;

            operation = input[i];

            output.push(new Operator(operation));

            i++;
        }
    }

    cout<<"Your Highness' Input Is"<<output<<endl;

    return output;

}


double Token::RPN(Queue<Token*> q){
    Stack<double> s;

    double result;

    double pop_num;

    char operation;

    while(q.top()!= NULL){

        if(q.top()->get_face() == NULL){

            //            cout<<"pushed a number in RPN\n";
            s.push(q.pop()->get_value());

            if(q.empty()== true){

                return s.pop();

                break;
            }
        }

        if(q.top()->get_face() == '+' ||
                q.top()->get_face() == '-' ||
                q.top()->get_face() == '*' ||
                q.top()->get_face() == '/' ||
                q.top()->get_face() == '^' ||
                q.top()->get_face() == 's' ||
                q.top()->get_face() == 'c' ||
                q.top()->get_face() == 't' ||
                q.top()->get_face() == 'S' ||
                q.top()->get_face() == 'C' ||
                q.top()->get_face() == 'T'){

            pop_num = s.pop();

            operation = q.pop()->get_face();


            if(operation == 's'){

                result = sin(pop_num);

                s.push(result);
            }

            else if(operation == 'c'){

                result = cos(pop_num);

                s.push(result);
            }

            else if(operation == 't'){

                result = tan(pop_num);

                s.push(result);
            }

            else if(operation == 'S'){

                result = 1 / (sin(pop_num));

                s.push(result);
            }

            else if(operation == 'C'){

                result = 1/ (cos(pop_num));

                s.push(result);
            }

            else if(operation == 'T'){

                result = 1 / (tan(pop_num));

                s.push(result);
            }


            else if(operation == '^'){

                result = pow(s.pop(), pop_num);

                s.push(result);
            }

            else if(operation == '+'){

                result = s.pop() + pop_num;

                s.push(result);
            }

            else if(operation == '-'){

                result = s.pop() - pop_num;

                s.push(result);
            }

            else if(operation == '*'){

                result = s.pop() * pop_num;

                s.push(result);
            }

            else if(operation == '/'){

                //                assert (pop_num != 0);

                result = s.pop() / pop_num;


                s.push(result);
            }

            else{
                cout<<"In Token's RPN: no matching operator found."<<endl;

            }
        }
    }

    return s.pop();
}

Queue<Token*> Token::Shunt(Queue<Token*> q){
    Queue<Token*> output;

    Stack<Token*> operation;

    int i = 1;

    while(q.empty() != true){

        //        cout<<i++<<"Q currently is "<< q<<endl;

        //if its a number
        if(q.top()->get_face() == NULL){


            //push into ouput queue
            output.push(q.pop());

            //            cout<<"q is"<<q;

            //            cout<<"added a number\n";

            if(q.empty() == true && operation.empty() == false){

                while(operation.empty() != true){

                    output.push(operation.pop());
                }

                break;
            }


            if(q.empty() == true && operation.empty() == true){

                //                cout<<"only x\n";

                break;
            }

        }
        //if its left parenthesis
        if(q.top()->get_face() == '('){

            operation.push(q.pop());

            //            cout<<"after inputting ( operation is"<<operation<<endl;

        }

        //if its right parenthesis
        if(q.top()->get_face() == ')'){

            while(operation.top()->get_face() != '('){

                if(operation.empty() == true){

                    cout<<"========Missing Parenthesis, Exiting Program=========\n";

                    exit(0);
                }

                output.push(operation.pop());
            }

            operation.pop();

            q.pop();


            if(q.top() == NULL && operation.top() != NULL){

                while(operation.empty() != true){

                    output.push(operation.pop());
                }

                break;
            }
        }

        //if its a trig function
        if(q.top()->get_face() == 's' ||
                q.top()->get_face() == 'c' ||
                q.top()->get_face() == 't' ||
                q.top()->get_face() == 'S' ||
                q.top()->get_face() == 'C' ||
                q.top()->get_face() == 'T'){

            operation.push(q.pop());

            //            cout<<"After putting in sin, cos , or tan \n";

        }


        //if its an operation
        if(q.top()->get_face() == '+' ||
                q.top()->get_face() == '-' ||
                q.top()->get_face() == '*' ||
                q.top()->get_face() == '/' ||
                q.top()->get_face() == '^'){


            //if operation stack is empty
            if(operation.empty() == true){

                //                cout<<"added a operator\n";


                //push into the stack
                operation.push(q.pop());
            }

            //if stack is not empty
            else{

                if(q.top() == NULL && operation.top() != NULL){

                    while(operation.empty() != true){

                        output.push(operation.pop());
                    }

                    break;
                }

                if(q.top()->get_preceden() ==4 && operation.top()->get_preceden() ==4){

                    //                    cout<<"added another ^ after ^"<<endl;

                    operation.push(q.pop());

                }

                // if the stack's operation's precedence is less than or equal to
                // the current operation's precenden then put into stack
                else if(operation.top()->get_face() != '(' &&
                        operation.top()->get_preceden() >= q.top()->get_preceden()){

                    while(operation.empty() != true &&
                          operation.top()->get_preceden() >= q.top()->get_preceden()
                          ){

                        output.push(operation.pop());

                        //                        cout<<"output got an new operation ouput rn is"<<output<<endl;

                        //                        cout<<"operation stack is "<< operation<<endl;

                        //                        cout<<"q is "<<q<<endl;

                    }

                    //                    cout<<"added a operator in greater or equal \n";

                    //push operation into stack
                    operation.push(q.pop());

                    //                    cout<<"after adding operator q is"<<q<<endl;
                    //                    cout<<"operation stack is "<< operation<<endl;
                    //                    cout<<"output got an new operation ouput rn is"<<output<<endl;

                }

                //if the stack's operation's precendence is greater than the current
                // operation's precendence then put everything in stack into queue
                // and push operation into stack
                else if(operation.top()->get_preceden() < q.top()->get_preceden()){

                    //                    cout<<"added a operator in less than\n";

                    operation.push(q.pop());

                }

                //                cout<<"after adding operator operator q is"<<operation<<endl;
            }

        }

    }


    //        cout<<"end of function\n";

    return output;
}


double Token::get_point(const Queue<Token *> &q, double x){

    Token t;
    double answer;
    Queue<Token*> input;
    Queue<Token*> after_shunt;
    Queue<Token*> temp;

    //walker holds original input
    Queue<Token*> walker = q;

    //    cout<<"before while loop to change x"<<endl;

    while(walker.empty() != true){

        if(walker.top()->is_variable() == true){

            walker.pop();

            temp.push(new Number(x));

            //            cout<<"adding x\n";
        }

        else{

            temp.push(walker.pop());
        }

    }

    //    cout<<"input after changing x is "<<temp<<endl;

    after_shunt = t.Shunt(temp);

    answer = t.RPN(after_shunt);

    //    cout<<"answer is: "<< x << " "<< answer<<endl;

    //        cout<<"original input is"<<walker<<endl;


    return answer;



}




ostream& operator <<(ostream& outs, Token* print_me){
    print_me->show();

    return outs;
}




