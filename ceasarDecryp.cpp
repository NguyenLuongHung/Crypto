#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

void ceasarCipherDe(char s[], char s1[], int key){
	char ch;
	int i;

	for (i = 0; s[i] != '\0'; i++ ){
		ch = s[i];
		if ( ch >= 'a' && ch <= 'z'){
			ch = ch - key;
			if (ch < 'a')
				ch = ch + 'z' - 'a' + 1; 
			s1[i] = ch;
		}
	
		else if (ch >= 'A' && ch <= 'Z'){
			ch = ch - key;
			if (ch < 'A')
				ch = ch + 'Z' - 'A' + 1;	
			s1[i] = ch;
		}
		else 
			s1[i] = ch;	
	}
}

int main(){
	char message[1000];
	char s1[26][1000];
	char s2[1000];
	cout << "Please enter the cipher text: ";
	cin.getline(message, 1000);
	cout << "\n\n\nMessage: " << "H_"<<message<<"_H\n\n";
	for (int i = 1; i < 26; i++){
		strcpy(s2,s1[i]);
		ceasarCipherDe(message, s2, i);	
		strcpy(s1[i], s2);
		cout << "The plaintext with key " << i << "  is: " << s1[i] << "\n\n";
	}
	return 0;
}
