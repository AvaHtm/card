#include<iostream>
#include<cstring>
using namespace std;

struct Validcard {
    char name[20];
    char validcard[7]; // First 6 digits + null terminator
};

class card {
public:
    char number[17]; // 16 digits + null terminator
    char bankname[20];
    Validcard validcards[4]; // Move the declaration inside the class

    bool isvalid() {
        for (int i = 0; i < 16; i++) {
            if (number[i] == '0' || number[i] == '9') {
                return false;
            }
        }
        if (strlen(number) == 16) {
            for (int i = 0; i < 4; i++) {
                if (strncmp(number , validcards[i].validcard,6)==0) {
                    strcpy(this->bankname,validcards[i].name); // Correct the syntax
                    return true;
                }
            }
        }
        return false;
    }

    void print() {
        for (int i = 1; i <= 16; i++) {
            if (i == 5 || i == 9 || i == 13) {
                cout << "_";
            }
            cout << number[i-1];
        }
    }
};

int main() {
    card mycard;

    strcpy(mycard.validcards[0].name,"meli");
    strcpy(mycard.validcards[0].validcard,"603799");
    strcpy(mycard.validcards[1].name,"sepah");
    strcpy(mycard.validcards[1].validcard,"6589210");
    strcpy(mycard.validcards[2].name,"saderat");
    strcpy(mycard.validcards[2].validcard,"603769");
    strcpy(mycard.validcards[3].name,"pasargad");
    strcpy(mycard.validcards[3].validcard,"502229");

    cout << "Enter your card number: ";
    cin >> mycard.number;

    if(mycard.isvalid()) {
        cout << "Card: ";
        mycard.print();
        cout << endl << "Bank: " << mycard.bankname;
        cout << endl << "Is valid";
    } else {
        cout << "Invalid";
    }

    return 0;
}
