#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "String.h"


bool strIsEmpty(String this){
	if (this.length == 0) return true;
	return false;
}

String strShowWhitespaces(String this){
	
	if (strIsEmpty(this)) return mkStringForLength(0);
	
	int i;
	String s = mkStringForLength(this.length);
	
	for (i = 0; i<this.length; i++){
		if (this.data[i] == 32) s.data[i] = 45;
		else s.data[i] = this.data[i];
	}
	
	return s;
}

String mkStringFromChars(_char* str) {
	sizetype j = 0;
	String s;

	while (str[j] != '\0') j++;
  
	s.length = j;
  
	s.data = malloc((j+1)*sizeof(_char));

	for(j = 0; j < s.length; j++) {
		s.data[j] = str[j];
	}
	
	s.data[j] = '\0'; //???

	return s;
}

String mkStringForLength(sizetype l) {
	String s;
	s.length = l;
	s.data = malloc((l+1)*sizeof(_char));
	s.data[l] = '\0';
	return s;
};

void strDelete(String this){
	free(this.data);
}

String strFromInt(int i){
	
	bool minus = false;
	
	if (i==0) return mkStringFromChars("0");
	
	if (i<0){
		minus = true; //if <0
		i *= -1;
	}
	
	// Count of digits
	int tmp ,zahl = i,stellen=0; 
    for(tmp=1; tmp <= zahl; tmp*=10) stellen++;   

	//creates String for calculated number of digits
	String s = mkStringForLength(stellen);
	int a = i;
	int b;
	int j = 0;
	

	while (a != 0){		
		b = a%10;
		s.data[j] = 48 + b;

		a = a/10;
		j++;
	}
	
	
	if (minus) { 
		s.length = s.length + 1;
		s.data[s.length-1] = '-';
		s.data[s.length] = '\0';
	}
	
	
	String result = strReverse(s);
	strDelete(s);

	return result;
}

String strFromBool(bool b){
	
	
	if (b) {String s = mkStringFromChars("true");
		return s;
	}	 
	else {String s = mkStringFromChars("false");
		return s;
	}
	
}

void strPrintLn(String this){
	printf("String data = '%s', String length = '%d'\n", this.data, this.length);
}

String strAppend(String this,String that){
	String s = mkStringForLength(this.length + that.length);
	
	int i, j;
	for (i = 0; i < this.length; i++) s.data[i] = this.data[i];
	for (j = 0; j < that.length; j++) s.data[j+this.length] = that.data[j];
	s.data[s.length] = '\0';
		
	return s;

}; 

String strAppendInt(String this,int i){
	String number = strFromInt(i);
	String result = strAppend(this, number);
	strDelete(number);
	return result;
}

String strReverse(String this){
	String s = mkStringForLength(this.length);
	int i;
	for (i = 0; i < this.length; i++){
		s.data[this.length-i-1] = this.data[i];	
	}
	return s;
}

String strMap(String this,char f(char)){
	String s = mkStringForLength(this.length);
	
	unsigned int i;
	
	for (i=0; i<this.length;i++){
		s.data[i] = f(this.data[i]);
	}
	
	return s;

}

String strToUpperCase(String this){
	
	if (strIsEmpty(this)) return mkStringFromChars("");
	
	int i;
	String s = mkStringForLength(this.length);
	
	for (i = 0; i<this.length; i++){
		if (this.data[i] >= 97 && this.data[i] <= 122) s.data[i] = this.data[i]-32;
		else s.data[i] = this.data[i];
	}
	s.data[s.length] = '\0';
	
	return s;
}

String strToLowerCase(String this){
	int i;
	String s = mkStringForLength(this.length);
	for (i = 0; i<this.length; i++){
		if (this.data[i] >= 65 && this.data[i] <= 90) s.data[i] = this.data[i]+32;
		else s.data[i] = this.data[i];
	}
	s.data[s.length] = '\0';
		
	return s;	
}

String strSubstring(String this,sizetype from, sizetype to){
	
	if (strIsEmpty(this)) return mkStringForLength(0);
	
	if (to<from){
		sizetype tmp;
		tmp = to;
		to = from;
		from = tmp;
	}
	
	if (to>this.length) to = this.length;
	
	String s = mkStringForLength(to-from);
	
	int a = from;
	
	for (; from < to; from++){
		s.data[from-a] = this.data[from];
	}
	
	s.data[s.length] = '\0';
	return s; 
}

String strTrim(String this){
	
	if (strIsEmpty(this)) return mkStringForLength(0);
	
	int i = 0;
	while (this.data[i] == ' ' || this.data[i] == '\t' || this.data[i] == '\n') i++;
	
	if (i >= this.length) return mkStringForLength(0);
	
	int j = this.length-1;
	while (this.data[j] == ' ' || this.data[j] == '\t' || this.data[j] == '\n') j--;	
	
	return strSubstring(this,i,j+1);
}

//..
Ord strCompare(String this,String that){
	unsigned int i,j,to;
	bool b = true;
	String thisL = strToLowerCase(this);
	String thatL = strToLowerCase(that);
	

	if (thisL.length == thatL.length){
		for (;i < thisL.length; i++){
			 if (thisL.data[i] != thatL.data[i]) b = false;
		}
		if (b) return eq;
	}
	
	if (thisL.length < thatL.length) to = thisL.length; else to = thatL.length;
		
	for (j=0;j<to;j++){
		if (this.data[i] >= 97 && this.data[i] <= 122){
			if (thisL.data[j] < thatL.data[j]) return gt;
		}
		
	}

	strDelete(thisL);
	strDelete(thatL);
	
	return lt;
}

bool strStartsWith(String this,String prefix){
	String s = strSubstring(this,0,prefix.length);
	bool b;
	
	if (strCompare(prefix,s) == eq) b = true; else b = false;
	
	strDelete(s);
	return b;
}

bool strEndsWith(String this,String suffix){
	String s = strSubstring(this,this.length-suffix.length,this.length);
	bool b;
	
	if (strCompare(suffix,s) == eq) b = true; else b = false;
	
	strDelete(s);
	return b;
}

String strReplace(String this,_char oldChar, _char newChar){
	int i;
	String s = mkStringForLength(this.length);
	for (i=0; i < this.length; i++){
		if (this.data[i] == oldChar) s.data[i] = newChar;
		else s.data[i] = this.data[i];
	}
	return s;
}



