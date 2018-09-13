/* 
 * CS:APP Data Lab 
 * 
 * <David Martin Dama7453>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
	// int t2 = (t << 4) + t;
	// int t3 = (t2 << 8) + t2;
	// int t4 = (t3 << 16) + t3;
	// t = (t4 << 24) + t4;
	int t = 0X55;
	//originally I wanted to add the previous temp variable so that the right shift would leave zero slots and the 1010 would fill in correctly
	//however it did not work and I am unsure as to why it wouldn't. But I know that if an addition didn't work in this case a | make
	//do the job that I am still looking for.
	t = (t | (t<<4));
	t = (t | (t<<8));
	t = (t | (t<<16));
	t = (t | (t<<24));
  return t;
}
/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
	//the equivalent of a -1 can be represented as a ~0. Simple.
  return ~0;
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
	//Shift left first so that all other bits are essentially "kicked" other than the LSB at 32
	//then shift it all right where it will then "refill" all 31 and place back the LSB
	x = x<<31;
	x = x>>31;
  return x;
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
	// can't do x >> n because we need to round towards 0!!!!
	// for rounding in this environement we need to consider two things.
	// we consider what magnitude is rounding occuring and whether the value added
	// needs to be positive or negative
	// So how do you do that? Lemme show ya
	// create an int called p which will set the magnitude of rounding that we will need to do later
	int p = (1 << n) + ~0;
	// create a int to designate whether to add(can occur if x is negative) or 
	//subtract(can occur if x is positive) that value to round to 0
	int s = (x >> 31) & p;
	//s sets whether addition or subtraction needs to take place to round towards 0
   return ((x+s) >> n);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
	//to get the byte n we want right shift out anything after the byte n
	//int t = x >> n;
	//after right shifting out anything before then we left shift by 3 bytes as the 
	//desire byte now sits at the 0-th byte position. left shifting will make it the MSB
	//and everything following will be zeroed
	//int t2 = t << 3;
	//return t2 & 0xFF;
	//1111 1111
	//masking with 0xFF will allow us to essentialy perform a ! for the preceeding numbers and simplly allow for the return of the desire nth byte
	x = x >> (n<<3);
	x = x & 0xFF;
	return x;
}
/* 
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x) {
//5 has the binary of 0101
//consider the positions of the (3rd|2nd|1st|0th) bits and you'll see that all of the 1's in 5's binary fall on even numbered bits
//however for 7 w/ binary 0111 the 1st numbered bit contains a 1 therefore the function returns a 1.
	// 1010 1010
	x = !!((x >> 24) | (x>>16) | (x>>8) | (x & 0xAA ));
	//x = x & 0xAAAAAA;
	//Considered to mask the full x however this did not work
   return x;
}
/* 
 * isNegative - return 1 if x < 0, return 0 otherwise 
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x) {
	x = x >> 31 & 0x01;
	//if we use a right shift of 31 to move the Most significant bit and 
	//then a mask of 0x01 it will either return a 1 OR 0 depending
	//on the signed nature of the input
    return x;
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
//STILL NEED TO DO
int a, b;
//need an int set easier with hex for the value 47 for the asciiDigit range beginning
int d = ~0x2F;
a = ((x + d)>>31);
// the variable a is designed to find the distance from x to the bottom most range of the ASCII range
//if the value of a comes out negative, then it was below the range of ascii digitss.
//but we also need to check for values above the range of ascii digits
b = ((58 + ~x)>>31);
//b checks for if x is above the range of ascii digits, where again if the value of b comes out negative,
//then x is not within the range of ascii digits
return !(a | b);
//we then use an or to compare a and b and use a not to acquire the desired output. 
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int fitsBits(int x, int n) {
	//So i knew this was going to require a mask of some sort to make this possible
	//Using the hints I initially tried creating a mask of n-1 however, I quickly realized this 
	//shift wouldn't help with very much as we were having problems representing the LSB in our final calulations
	//as due to the mask the LSB had become our indicator of fitbits
	int t = x >> 31;
	//creat a int t that is a MSB of x this is important for later masking
	//we will mask to help accomodate t=for the range of x values.
	//by creating masks for t2 and t3 we can consider the needed 1's for a signed value
	//or a really large number
	int t2 = t & ~x;
	int t3 = ~t & x;
	//for 5 this came in the form of 0101 + 0101 which eqautes to 1010 which is then right shifted by n-1
	//but here comes the most important part, if there are 1's anywhere beyond the area shifted,
	//the the ! will return 1 and show that the value cannot be represented in the given n number of bits
  return !((t2 + t3)>> (n-1));
}
/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {
// Remember: WHEN OVERFLOW OCCURS, INPUTS WITH SAME SIGNS HAVE AN OPPOSITELY SIGNED SUM
	//I'll need to conclude this function with a right shift of 31 to make the return either all 1's or zeros
	//depending on if overflow occurs.
//So how do we check if we will have overflow?
	//here's how:
	//we create an int which will help us maniuplate x without changing it
	//we will then add x plus (not y) and add 1 to get x + the two's compliment of y
	//a two's complement like the one we use in a is a helpful indicator if overflow has occured!
	int a = x + ~y + 1;
	// we will then use an exclusive or to compare a and x
	int b = a ^ x;
	//then utilize an exlusive between the values of x and y
	//these exclusive or's are used to detect overflow even if the two inputs are not the same sign!
	int c = x ^ y;
	//we will then mask c with b, if overflow occurs in this process then the MSB will equate to 0 as
	//the mask caused an overflow, I then right shift the MSB 31 times so that the entirety of the 
	//output is either 1 or 0. I then use a ! to flip this for the desire return indicator
 return !((c & b) >> 31);
 //the return value will be 1 if the the sign deviated showing that overflow occured
 //however the return value wil be 0 if the sign value did not deviate, therefore no overflow
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */

int conditional(int x, int y, int z) {
//x?y:z means if (x!=0) then return y, else, return z
	//This is fairly straightforward but it seems hard to understand
	x = !x;
	//I'm using the all 0 case if x = 0!
	//so we know that if x = 0 then the first step will set it to all 1's
	x = x -1;
	//then the step above will turn be sure to convert it to all 0's
  return z ^ (x & (y ^ z));
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
	//STILL NEED TO DO
    return 2;
}
/* 
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4 
 */
int isNonZero(int x) {
	//Think about what would happen to return 0 if x was 0
	//conisder how to make any real number = 1 and 0 = 0 still.
	//going to need to use a two's compliment for this
	int t = 1 + ~x;
	//return (x= >> 31); ??????
	//use a (or) with the input and its two's complement. This will help us to get a value of 1 for any number other than 0 
	return(t >> 31 | x>>31) & 1;
	//we need an &1 so that it will return 0 for the | of 0 and its twos complement and essentially do the job of !
  //return (x>>31);
}
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
	//we will create a temporary variable that is x's MSB
	int t = x >> 31;
	//adding the MSB to x will re-cast the number as if it were negative!!
	int t2 = x + t;
	//you can get the absolute value of a negative number by doing an Xor 
	//between the negatively recasted value and its MSB
	return t2 ^ t;
}
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
	//we will first convert x into its two's compliment. when we take the two's compliment, 
	//a zero will be in the position of the nth spot (coming from 2^)
	x = ~x + 1;
	//if we then take the exclusive or of x and -1 we will get either a 1 or 0 depending on
	//	x at this step will equate to a 1 if x is NOT a power of 2 and a 0 if x is a power of 2
	x = (x ^ ~0);
	//we then must retunr a NOT of x in order to switch the returned values to the desired outputs
  return !x;
}
