#include "CUnit.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MemoryTest.h"

unsigned int errorcount = 0;
unsigned int testcount = 0;
unsigned int speicherAlloc=0;
unsigned int speicherFree=0;

bool assertTrueLine(int line,char* message, bool val){
    testcount++;
    if (!val){
      errorcount++;
      printf("(%d) fail: %s\n",line,message);
    }
    return val;
}

bool assertIntEqLine(int line,char* message, int expected, int found){
  testcount++;
  if (expected!=found){
      errorcount++;
      printf("(%d) fail: %s, expected %d found %d\n",line,message,expected,found);
      return false;
  }
  return true;
}

bool assertStringEqLine(int line,char* message, char* expected,char* this){
  testcount++;
  bool result = strcmp(expected,this)==0;
  if (!result){
    errorcount++;
    printf("(%d)  fail:  %s, expected %s  but found %s\n",line,message,expected,this);
  }
  return result;
}


void reportTestResults(){
  printf("%u test run, %u errors, %u success\n memory allocation: %d, memory deallocation: %d, difference: %d\n"
   ,testcount,errorcount,testcount-errorcount,speicherAlloc,speicherFree,speicherAlloc-speicherFree);

}
