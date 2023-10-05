/*
    จงเขียนฟังก์ชันในการตรวจสอบตัวเลขที่ผู้ใช้ป้อนเข้ามา ว่าเป็นตัวเลขที่เป็นอาร์มสตรองหรือไม่ หากใช่ให้แสดงคำว่า Pass หากไม่ใช่แสดงคำว่า Not Pass
    
    หมายเหตุ: ตัวเลขอาร์มสตรอง คือ ตัวเลขที่ผลรวมของเลขยกกำลังของจำนวนหลัก เช่น
    153 เป็นตัวเลขอาร์มสตรอง เพราะ 153 มีทั้งหมด 3 หลัก จึงมีค่าเท่ากับ = 1^3 +  5^3 +  3^3 (โดยที่เครื่องหมาย ^ หมายถึงเลขยกกำลัง)
    370 = 3^3 + 7^3 + 0^3

    Test Case:
        Enter Number:
            153
    Output:
        Pass.
    
    Test Case:
        Enter Number:
            370
    Output:
        Pass.
    
    Test Case:
        Enter Number:
            372
    Output:
        Not Pass.
*/

#include <stdio.h>
#include <math.h>

int calculatePower( int num, int digitCount ) {
    int power = 1 ;
    for ( int i = 0 ; i < digitCount ; i++ ) {
        power *= num ;
    }
    return power ;
}

int isArmstrongNumber( int num ) {
    int originalNum = num ;
    int digitCount = 0 ;
    int sum = 0 ;

    while ( num > 0 ) {
        num /= 10 ;
        digitCount++ ;
    }

    num = originalNum ;

    while ( num > 0 ) {
        int digit = num % 10 ;
        sum += calculatePower( digit, digitCount ) ;
        num /= 10 ;
    }

    if ( sum == originalNum ) {
        return 1 ;
    } 
    else {
        return 0 ;
    }
}

int main() {
    int num ;
    printf( "Input Number: " ) ;
    scanf( "%d", &num ) ;

    if ( isArmstrongNumber( num ) ) {
        printf( "Pass." ) ;
    } 
    else {
        printf( "Not Pass." ) ;
    }

    return 0 ;
}