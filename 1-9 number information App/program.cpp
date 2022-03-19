#include <iostream>
#include <string>
using namespace std;

class askingClass {
	
	public:
		string welcomeString;
		string askingString;
	
};

	
int main() {
	askingClass welcomeObject;
	welcomeObject.welcomeString = "hello sailor!";
	welcomeObject.askingString = "give me a number between 0 and 9:";
	
	cout << welcomeObject.welcomeString << endl;
	cout << welcomeObject.askingString << endl;
	while(0==0) {
	
	int input;
    cin >> input;
    cout << "your input is: " << input << endl;
    
    if(input!=0 && input!=1 && input!=2 && input!=3 && input!=4 && input!=5 && input!=6 && input!=7 && input!=8 && input!=9) {
    	cout << "sorry, but your input is not a number between 0 and 9.";
	}
	
	if(input==0 || input==1 || input==2 || input==3 || input==4 || input==5 || input==6 || input==7 || input==8 || input==9) {
	  cout <<"your input is one of the allowed numbers" << endl;
	}
	else {
		  cout <<"your input is NOT one of the allowed numbers." << endl;
		  return 0;
	}
	
if(input==0) {
    cout << "0 is a number, and the numerical digit used to represent that number in numerals. "<< endl;
cout <<	"It fulfills a central role in mathematics as the additive identity of the integers\,"<< endl;
	cout << "real numbers\, and many other algebraic structures\. "<< endl;
cout << "As a digit\, 0 is used as a placeholder in place value systems\. "<< endl;
		
	}
	
	if(input==1) {
		cout << "1 (one, also called unit, and unity) is a number and a numerical digit used to represent that number in numerals. It represents a single entity, the unit of counting or measurement. For example, a line segment of unit length is a line segment of length 1. In conventions of sign where zero is considered neither positive nor negative, 1 is the first and smallest positive integer."<< endl;
	}
	
	if(input==2) {
				cout << "2 (two) is a number, numeral and digit. It is the natural number following 1 and preceding 3. It is the smallest and only even prime number. Because it forms the basis of a duality, it has religious and spiritual significance in many cultures."<< endl;

	}
	
	if(input==3) {
				cout << "3 (three) is a number, numeral and digit. It is the natural number following 2 and preceding 4, and is the smallest odd prime number and the only prime preceding a square number. It has religious or cultural significance in many societies."<< endl;

	}
	
	if(input==4) {
				cout << "4 (four) is a number, numeral and digit. It is the natural number following 3 and preceding 5. It is the smallest composite number, and is considered unlucky in many East Asian cultures."<< endl;

	}
	
	if(input==5) {
				cout << "5 (five) is a number, numeral and digit. It is the natural number, and cardinal number, following 4 and preceding 6, and is a prime number. It has attained significance throughout history in part because typical humans have five digits on each hand."<< endl;

	}
	
	
	if(input==6) {
				cout << "6 (six) is the natural number following 5 and preceding 7. It is a composite number and the smallest perfect number."<< endl;

	}
	
	if(input==7) {
				cout << "7 (seven) is the natural number following 6 and preceding 8. It is the only prime number preceding a cube."<< endl;

	}
	
	if(input==8) {
				cout << "8 (eight) is the natural number following 7 and preceding 9."<< endl;

	}
	
	
	if(input==9) {
				cout << "9 (nine) is the natural number following 8 and preceding 10."<< endl;

	}
	}
	
	return 0;
	
}


