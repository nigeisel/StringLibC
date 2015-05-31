#include "String.h"
#include "CUnit.h"

int main(){
	

  String str1 = mkStringFromChars("HELLO");
  String str2 = mkStringFromChars("world");
  String strE = mkStringFromChars("");



  assertIntEq("String hello has 5 characters",str1.length,5);
  String str3 = strFromBool(42==17);
  assertStringEq("wrong result of strFromBool","false",str3.data);
  strDelete(str3);
  str3 = strFromBool(42==42);
  assertStringEq("wrong result of strFromBool","true",str3.data);
  strDelete(str3);
  


  
  strPrintLn(str1);
  strPrintLn(str2);
  //  {length=5;data="HELLO"}
  
  str3 = strAppend(str1,str2);
  assertStringEq("wrong result of strAppend","HELLOworld",str3.data);




  String str4 = strAppend(str1,str3);
  assertStringEq("wrong result of strAppend","HELLOHELLOworld",str4.data);
  strDelete(str3);
  strDelete(str4);
  str3 = strAppend(str1,strE);
  assertStringEq("wrong result of strAppend","HELLO",str3.data);
  strDelete(str3);
  str3 = strAppend(strE,str1);
  assertStringEq("wrong result of strAppend","HELLO",str3.data);
  strDelete(str3);

  str3 = strReverse(str1);
  assertStringEq("wrong result of strReverse","OLLEH",str3.data);
  strDelete(str3);
  
  str3 = strToLowerCase(str1);
  assertStringEq("wrong result of strToUpperCase","hello",str3.data);
  strDelete(str3);

  str3 = strToUpperCase(str2);
  assertStringEq("wrong result of strToUpperCase","WORLD",str3.data);
  strDelete(str3);

  str3 = strToUpperCase(strE);
  assertStringEq("wrong result of strToUpperCase","",str3.data);
  strDelete(str3);

  str3 = strToLowerCase(strE);
  assertStringEq("wrong result of strToUpperCase","",str3.data);
  strDelete(str3);
  
  str3 = strSubstring(str1,1,3);
  assertStringEq("wrong result of strSubstring","EL",str3.data);
  strDelete(str3);
 
  str3 = strSubstring(str1,0,0);
  assertStringEq("wrong result of strSubstring","",str3.data);
  strDelete(str3);
 
  str3 = strSubstring(strE,1,3);
  assertStringEq("wrong result of strSubstring","",str3.data);
  strDelete(str3);

  str4 = mkStringFromChars("   HE LLO    ");
  str3 = strTrim(str4);
  assertStringEq("wrong result of strTrim","HE LLO",str3.data);
  strDelete(str3);
  strDelete(str4);

  str4 = mkStringFromChars("       ");

  str3 = strTrim(str4);
 
  
  assertStringEq("wrong result of strTrim","",str3.data);
  strDelete(str3);
  strDelete(str4);

  String str5 = mkStringFromChars("worldahkhgj");
  String str6 = mkStringFromChars("worldbhkkh");
  assertIntEq("",strCompare(str5,str6),lt);
  assertIntEq("",strCompare(str6,str5),gt);
  assertIntEq("",strCompare(str6,str6),eq);
  strDelete(str5);
  strDelete(str6);  
  
  str5 = mkStringFromChars("worl");
  str6 = mkStringFromChars("worldbhkkh");
  assertIntEq("strStartsWith",strStartsWith(str6,str5),true);
  strDelete(str5);
  strDelete(str6);

  str5 = mkStringFromChars("");
  str6 = mkStringFromChars("worldbhkkh");
  assertIntEq("strStartsWith",strStartsWith(str6,str5),true);
  strDelete(str5);
  strDelete(str6);
  
  str3 = strReplace(str1,'E','A');
  assertStringEq("wrong result of strReplace","HALLO",str3.data);
  strDelete(str3);

  
  str3 = strFromInt(42);
  assertStringEq("wrong result of strFromInt","42",str3.data);
  strDelete(str3);

  str3 = strFromInt(-42);

  assertStringEq("wrong result of strFromInt","-42",str3.data);
  strDelete(str3);

  str3 = strFromInt(0);
  assertStringEq("wrong result of strFromInt","0",str3.data);
  strDelete(str3);

  str3 = strFromInt(10000);
  assertStringEq("wrong result of strFromInt","10000",str3.data);
  strDelete(str3);

  
  str3 = strAppendInt(str2,42);
  assertStringEq("wrong result of strAppendInt","world42",str3.data);
  strDelete(str3);


  str3 = strToLowerCase(str1);
  
  strDelete(str3);
  
  char encrypt(char c){ 
	  return c +1;
  }
 
  char decrypt(char c){
	  return c -1;
  }
  
	//strMap test
  String strM = mkStringFromChars("hallo");
  String strN = strMap(strM, encrypt);
  assertStringEq("wrong result of strMap","ibmmp",strN.data);
  strDelete(strM);
  strDelete(strN);
  
  strDelete(str1);
  strDelete(str2);
  strDelete(strE);
  

  
  reportTestResults();


  return EXIT_SUCCESS;
  
  
  return 0;
}
