#include <iostream>

using namespace std;

int main(int argc, char* argv[]){

    // 1
    cout << "Guille == Amigo" << endl;
    
    // 4 Bonus
    int i = 1;
    for (i ; i < argc; i++){
        cout << "Argument: " << i << " => "<<argv[i] << endl;
    }
    
    cout << "This program has " << i-1 << " arguments" << endl;

    return 0;
}

/*
Question 1:
• What type of file is produced by the above command line ?
• What does the argument -Wall on the command line correspond to?

Question 2:
• What type of file is produced by the above command line ?
*/