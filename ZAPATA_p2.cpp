// Project 2 Math Tutor

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void getprobsPerSet(int probsPerSet); // void function prototype with one reference parameter with a data flow comment
void doOneSet (/* in */ char problemType, /*in*/int probsPerSet,/*out*/int& correctCount); // void function prototype with two value parameters with a data flow comment
void getmaxNum (/*out*/ int& maxNum);
void printHeader (/*in*/ char problemType);
void doOneProblem (/*in*/ char  problemType, /*in*/ int maxNum, /*out*/bool& isCorrect);
void generateOperands (/*in*/int num1,/*in*/int num2,/*in*/ int maxNum);
void calcCorrectAnswer (/*in*/char problemType,/*in*/int num1,/*in*/int num2, /*inout*/int& answer);
void checkAnswer (/*in*/int num1,/*in*/int num2, /*out*/bool& isCorrect);
void printReport (/* in */int probsPerSet, /* in */ int set1Correct,/* in */int set2Correct, /* in */int set3Correct);


int main()
{
    int probsPerSet = 0;
    int set1Correct, set2Correct, set3Correct;

    srand(time(0));
    getprobsPerSet(probsPerSet); // void function call with a single argument
    doOneSet('+', probsPerSet, set1Correct); // void function call with a single argument
    doOneSet('-', probsPerSet, set2Correct); // void function call with a single argument
    doOneSet('*', probsPerSet, set3Correct); // void function call with a single argument

    printReport (probsPerSet, set1Correct, set2Correct, set3Correct);

    return 0;
}

void getprobsPerSet (/*out*/int probsPerSet)
{
    cout << "Enter problems per set: ";
    cin >> probsPerSet;
   if (probsPerSet < 3 || probsPerSet > 10)// Restrict the user to no less than 3 sets but no more than 10
    {
        cout << "Invalid Input, Enter a number between 3 and 10: ";
        cin >> probsPerSet;
    }
}


void printHeader (/*in*/ char problemType)
{
    switch(problemType)
    {
        case '+': cout << "Set #1" << endl;
                  cout << "----------" << endl;
        break;
        case '-': cout << "Set #2" << endl;
                  cout << "----------" << endl;
        break;
        case '*': cout << "Set #3" << endl;
                  cout << "----------" << endl;
        break;
    }
}

void getmaxNum(int& maxNum)
{
    cout << "What is the maximum number for this set? " ;
    cin >> maxNum;
}

void generateOperands (/*in*/int num1,/*in*/int num2,/*in*/ int maxNum)
{
        num1 = rand() % (maxNum + 1);
        num1++;
        num2 = rand() % (maxNum + 1);
        num2++;
}

void calcCorrectAnswer (/*in*/char problemType,/*in*/int num1,/*in*/int num2, /*inout*/int& answer)
{
    switch(problemType)
        {
            case '+': answer = num1 + num2;
            break;
            case '-': answer = num1 - num2;
            break;
            case '*': answer = num1 * num2;
            break;
            default: cout << "incorrect" << endl;
        }
}

void checkAnswer (/*in*/int num1,/*in*/int num2, /*out*/bool& isCorrect)
{
        int answer, input;
        if (answer == input)
        {
            cout << "correct" << endl;
            isCorrect++;
        }
        else
            cout << "incorrect" << endl;
}

void doOneProblem (/*in*/ char  problemType, /*in*/ int maxNum, /*out*/bool& isCorrect)
{
    int num1, num2, input, answer;

    getmaxNum(maxNum);
    generateOperands(num1, num2, maxNum);

    cout << num1 << " " << problemType << " " << num2 << " = ";
    cin >> input;

    calcCorrectAnswer('+', num1, num2, answer);
    calcCorrectAnswer('-', num1, num2, answer);
    calcCorrectAnswer('*', num1, num2, answer);
    checkAnswer(num1, num2, isCorrect);

}

void doOneSet(/* in */ char problemType, /*in*/ int probsPerSet, /*out*/int& correctCount) // void function with two value parameters with a data flow comment
{
    int maxNum;
    bool isCorrect;

    for (int count = 0; count <= probsPerSet; count++)
    {
        printHeader(problemType);
        doOneProblem(problemType, maxNum, isCorrect);
    }
}

void printReport (/* in */int probsPerSet, /* in */ int set1Correct, /* in */int set2Correct, /* in */int set3Correct)

// This function prints a report detailing the user's success rate
// at correctly answering arithmetic problems, posed in three sets.
// It prints the user's score and percentage correct for each set,and overall.
{
	int set1Percent, set2Percent, set3Percent, totalCorrect, totalPercent;

	set1Percent = (100 * set1Correct) / probsPerSet;
	set2Percent = (100 * set2Correct) / probsPerSet;
	set3Percent = (100 * set3Correct) / probsPerSet;
	totalCorrect = set1Correct + set2Correct + set3Correct;
    totalPercent = (100 * totalCorrect) / (probsPerSet * 3);

	cout << endl;
	cout << "Set#1: You got " << set1Correct << " correct out of "<< probsPerSet << " for " << set1Percent << "%" << endl;
	cout << endl;
	cout << "Set#2: You got " << set2Correct << " correct out of "<< probsPerSet << " for " << set2Percent << "%" << endl;
	cout << endl;
	cout << "Set#3: You got " << set3Correct << " correct out of "<< probsPerSet << " for " << set3Percent << "%" << endl;
	cout << endl;
	cout << "Overall you got " << totalCorrect << " correct out of "<< (probsPerSet * 3) << " for " << totalPercent << "%" << endl;
}
