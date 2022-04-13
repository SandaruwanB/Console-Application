#include <iostream>
#include <string>
#include <cmath>

int binary(int);
int octal(int);
int hexadec(int);
float normlcal(float,float,char);
float sciencecal(char);
float sciencecal2 (char);

using namespace std;
int main(){
    int num;
    string loop="YES";

    char conversion, Mode;
    cout << "*********************************************************************************" << endl;
    cout << "\t\t\t| CALCULATOR AND NUMBER CONVERTER |\n\t\t\t|          VIRSION 1.0            |\n\t\t\t-----------------------------------\n";

    while (loop=="YES" || loop=="yes" || loop=="Yes" || loop=="y" || loop=="Y"){
        cout << "\n\t\tPress,\n \t\t\tC - for Calculator\n \t\t\tN - for Decimal Number Converter \n\t\t\t\t: ";
        cin >> Mode;
        cout << endl;

        //calculator
        if (Mode == 'C' || Mode == 'c') {
            float num1,num2;
            char op,calmode;

            cout << "------------------------------ CALCULATOR MODE ----------------------------------\n\n";
            cout << "  Enter calculator mode, \n \t\t 1 for Normal calculator \n\t\t 2 for Scientific calculator\n\t\t\t  : ";
            cin >> calmode;

            //normal mood
            if (calmode=='1'){
                cout << "\n\t\t>>>>>>>>>>>>  Normal Calculator  <<<<<<<<<<<<\n\n";
                cout << "  ENTER AN OPTION,\n\t * for multiply\n\t - for subtract \n\t + for add\n\t / for divide \n\t % for residual value (valid for integers) \n\t\t\tenter here : ";
                cin >> op;

                    cout << "\n\tEnter first number for calculation  : ";
                    cin >> num1;
                    cout << "\tEnter second number for calculation : ";
                    cin >> num2;

                cout << "\n\t\tThe answer of " << num1 << " " << op << " " << num2 << " = ";
                cout << normlcal(num1,num2,op) << endl << endl;}

            //scientific mood
            else if (calmode=='2'){
                cout << "\n\t\t>>>>>>>>>>>>  Scientific Calculator  <<<<<<<<<<<<\n\n";
                cout << "  CHOOSE OPTION, \n\t > C for Cos \n\t > S for Sin \n\t > T for Tan \n\t > A for Circle related operations \n\t > B for Rectangle related operations \n\t > D Square related operations \n\t > E Triangle related operations \n\t > F for Multiplication table \n\t\t  : ";
                cin >> op;

                if (op=='f' || op=='F')
                    cout << sciencecal2(op)  << endl << endl;
                else
                    cout << "  Answer is : " << sciencecal(op) << endl << endl;
            }
        }

        //decimal number converter
        else if (Mode == 'N' || Mode == 'n') {
            cout << "--------------------------------CONVERTER MODE------------------------------------\n\n";
            cout << "\t What is the Decimal number you want to convert : ";
            cin >> num;
            cout << "\n\t\tEnter type of Conversion, \n\t\t\t 1.Binary \n\t\t\t 2.Octal \n\t\t\t 3.Hexadecimal \n\t\t Enter Here : ";
            cin >> conversion;
            switch (conversion) {
                case '1':
                    cout <<"\n  Decimal Number :" << num << "\tBinary Number :";
                    binary(num);
                    cout << endl;
                    break;
                case '2':
                    cout <<"\n  Decimal Number :" << num << "\tOctal number :";
                    octal(num);
                    cout << endl;
                    break;
                case '3':
                    cout <<"\n Decimal Number :" << num << "\tHexadecimal Number :";
                    hexadec(num);
                    cout << endl;
                    break;
                default:
                    cout << "\n--------Invalid number :" << &num << " Please enter valid conversion number------\n";

            }
        }
        else
            cout << "-----------------------Invalid Operation-----------------------------";



    cout << "\n Do you want to run Calculator or converter again yes/no : ";
    cin >> loop;
    cout << endl << endl;
    }
    }

int binary(int num){
    int bin[32],i=0;
    while (num>0){
        bin[i]=num%2;
        num=num/2;
        ++i;
    }
    for (int j = i-1; j >= 0; j--) {
        cout << bin[j];

    }

}
int octal(int num){
    int oct[20],i=0;
    while (num>0){
        oct[i]=num%8;
        num=num/8;
        ++i;
    }
    for (int j = i-1; j >= 0 ; j--) {
        cout << oct[j];
    }
}
int hexadec(int num) {
    int hex[16], i = 0;
    while (num > 0) {
        hex[i] = num % 16;
        num = num / 16;
        ++i;
    }
    for (int j = i - 1; j >= 0; j--) {
        if (hex[j] >= 10) {
            if (hex[j] == 10) {
                cout << "A";
            }
            else if (hex[j] == 11) {
                cout << "B";
            }
            else if (hex[j] == 12) {
                cout << "C";
            }
            else if (hex[j] == 13) {
                cout << "D";
            }
            else if (hex[j] == 14) {
                cout << "E";
            }
            else if (hex[j] == 15) {
                cout << "F";
            }
        }
        else
            cout << hex[j];
    }
}
float normlcal(float num1,float num2,char op){
    float tot;
    if (op=='+'){
        tot = num1+num2;
    }
    else if (op=='-'){
        tot = num1-num2;
    }
    else if (op == '/'){

            tot = num1/num2;

    }
    else if (op=='*'){
        tot = num1*num2;
    }
    else if (op == '%'){
        int a = num1,b = num2;
        tot = a%b;
    }
    else
        cout << "Invalid Option";
    return tot;
}
float sciencecal(char option){

    float value,input;
    if (option=='C' || option=='c'){
        cout << "\t\t\tEnter Number for Cosine : ";
        cin >> input;
        value = cos(input);
    }
    else if (option=='T' || option=='t'){
        cout << "\t\t\tEnter Number for Tan : ";
        cin >> input;
        value = tan(input);
    }
    else if (option=='S' || option=='s'){
        cout << "\t\t\tEnter Number for Sin : ";
        cin >> input;
        value = sin(input);
    }
    else if (option=='A' || option=='a'){
        char mood;
        cout << "\n\t > A for Area \n\t > P for Perimeter \n\t\t  : ";
        cin >> mood;
        if (mood=='A' || mood=='a'){
            cout << "  Enter radius : ";
            cin >> input;
            value = 3.14*(input*input);
        }
        else if (mood=='P'|| mood=='p'){
            cout << "  Enter radius : ";
            cin >> input;
            value = 2*(3.14*input);
        }
    }

    else if (option=='B' || option=='b'){
        char mood;
        float wid;
        cout << "\n\t > A for Area \n\t > P for Perimeter \n\t\t  : ";
        cin >> mood;
        if (mood=='A' || mood=='a'){
            cout << "\n  Enter Length : ";
            cin >> input;
            cout << "  Enter Width  : ";
            cin >> wid;
            value = wid*input;
        }
        else if (mood=='P'|| mood=='p'){
            cout << "\n  Enter Length : ";
            cin >> input;
            cout << "  Enter Width  : ";
            cin >> wid;
            value = 2*(wid+input);
        }
    }

    else if (option=='D' || option=='d'){
        char mood;
        cout << "\n\t > A for Area \n\t > P for Perimeter \n\t\t  : ";
        cin >> mood;
        if (mood=='A' || mood=='a'){
            cout << "\n  Enter Side length : ";
            cin >> input;
            value = input*input;
        }
        else if (mood=='P' || mood=='p'){
            cout << "\n  Enter side length : ";
            cin >> input;
            value = 4*input;
        }

    }

    else if (option=='E' || option=='e'){
        char mood;
        float base,height,side;
        cout << "\n\t > A for Area \n\t > P for Perimeter \n\t\t  : ";
        cin >> mood;
        if (mood=='A' || mood=='a'){
            cout << "\n  Enter Base   : ";
            cin >> base;
            cout << "\n  Enter Height : ";
            cin >> height;
            value = 0.5*base*height;
        }
        else if (mood=='P' || mood=='p'){
            cout << "\n  Enter value of Side 1   : ";
            cin >> base;
            cout << "  Enter value of Side 2   : ";
            cin >> height;
            cout << "  Enter value of Base     : ";
            cin >> side;
            value = base+height+side;
        }
    }


    return value;
}
float sciencecal2(char opt){

        float num;
        int times;
        cout << "  Enter number for multiplication : ";
        cin >> num;
        cout << "  Enter number of time            : ";
        cin >> times;
        cout << "\n";

        for(int x=1;x<=times;x++){
            cout << "\t  " << num <<" X " << x <<"  = " << x*num <<endl;
        }
}
