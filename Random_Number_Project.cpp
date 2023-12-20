#include <iostream>
#include <cstdlib>

using namespace std;

int random_number(int min,int max);

int main(){
    int ub; //Upper Bound
    int lb; //Lower Bound
    char anwser;
    int life = 5; //times for guess
    int number,maximum_number,minimum_number,user_number,random_times = 1;
    double sum = 0,average_number = 0;
    do{
        cout << "Input Upper Bound : ";
        cin >> ub;
        cout << "Input Lower Bound : ";
        cin >> lb;
        if(ub < lb)
        {
            cout << "ERROR : Lower Bound is greater than Upper Bound" << endl;
        }
    }
    while(ub < lb);
    cout << "<==============game start==============>" << "\n\n";
    do{
        life = 5;
        number = random_number(lb,ub);
        if(random_times == 1){
            maximum_number = number;
            minimum_number = number; 
        }
        while(life > 0){
            cout << "-------------------------" << endl;
            cout << "Guess number : ";
            cin >> user_number;
            if(user_number == number){
                cout << "your anwser is correct" << endl;
                cout << "-------------------------" << endl;
                break;
            }
            else if(user_number > number){
                cout << "your anwser is uncorrect" << endl;
                cout << "your number is greater than random number" << endl;
                life--;
                cout << "your lifes : " << life << endl;
                cout << "-------------------------" << endl;
            }
            else{
                cout << "your anwser is uncorrect" << endl;
                cout << "your number is less than random number" << endl;
                life--;
                cout << "your lifes : " << life << endl;
                cout << "-------------------------" << endl;
            }
        }
        //find maximum number
        if(maximum_number < number){
            maximum_number = number;
        }
        
        //find minimum number
        if(minimum_number > number){
            minimum_number = number;
        }

        sum += number;
        cout << "random number : " << number << endl;
        cout << "Do you want to try again(y/n)";
        cin >> anwser;
        if(anwser == 'y'){
            random_times++;
        }
    }
    while(anwser == 'y');
    //find average number
    average_number = sum/random_times;

    cout << "===================" << endl;
    cout << "maximum number : " << maximum_number << endl;
    cout << "minimum number : " << minimum_number << endl;
    cout << "average number : " << average_number << endl;
    cout << "===================" << endl;
    cout << "<==============game end==============>" << endl;
    return 0;
}

int random_number(int min,int max){
    int number = 0;
    number = (rand()%(max - min +1))+min;
    return number;
}