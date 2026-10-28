/********************************************************
 * Program: C-seven_segments_display_simulator          *
 * About  : . A C-code convert a user input numbers to  *
 *            the seven digits representation of them   *
 *            and prints them to the terminal.          *
 *          . The max allowed digits are 10 digits, and *
 *            whatever after it is ignored.             *
 *          . Only numbers are accepted as input and    *
 *            everything else is ignored.               *
 *                                                      *
 * Author : Ammar MULLAOGLU                             *
 * Date   : 28.10.2026                                  *
 ********************************************************/
//Preprocessor MACROS
////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#define MAX_DIGITS 10
#define CHAR_LENGTH_OF_DIGITS 4
////////////////////////////

//Global variables
////////////////////////////
char segments[10][7] = {
    {'_', '|', '|', '_', '|', '|', ' '},        // 0's representation in seven digits.
    {' ', '|', '|', ' ', ' ', ' ', ' '},        // 1's representation in seven digits.
    {'_', '|', ' ', '_', '|', ' ', '_'},        // 2's representation in seven digits.
    {'_', '|', '|', '_', ' ', ' ', '_'},        // 3's representation in seven digits.
    {' ', '|', '|', ' ', ' ', '|', '_'},        // 4's representation in seven digits.
    {'_', ' ', '|', '_', ' ', '|', '_'},        // 5's representation in seven digits.
    {'_', ' ', '|', '_', '|', '|', '_'},        // 6's representation in seven digits.
    {'_', '|', '|', ' ', ' ', ' ', ' '},        // 7's representation in seven digits.
    {'_', '|', '|', '_', '|', '|', '_'},        // 8's representation in seven digits.
    {'_', '|', '|', '_', ' ', '|', '_'}         // 9's representation in seven digits.
};
char digits[4][MAX_DIGITS * 4];                 //This represents the output.
////////////////////////////

//Prototypes
////////////////////////////
void clear_digits_array(void);                  //Store blank chars into digits[] array.
void process_digit(int digit, int position);    //Represent the digit into the digits[]
                                                //array, don't end until reaching 10 digits or '\n'.
void print_digits_array(void);                  //Print the digits[] array.
void read_input(void);                          //Reads the user input.
////////////////////////////

int main(void){
    system("title C-seven_segments_display_simulator");
    printf( "/********************************************************\n"
            "* Program: C-seven_segments_display_simulator          *\n"
            "* About  : . A C-code convert a user input numbers to  *\n"
            "*            the seven digits representation of them   *\n"
            "*            and prints them to the terminal.          *\n"
            "*          . The max allowed digits are 10 digits, and *\n"
            "*            whatever after it is ignored.             *\n"
            "*          . Only numbers are accepted as input and    *\n"
            "*            everything else is ignored.               *\n"
            "*          . To terminate the program enter q or Q.    *\n"
            "*                                                      *\n"
            "* Author : Ammar MULLAOGLU                             *\n"
            "* Date   : 28.10.2026                                  *\n"
            "********************************************************/\n\n\n");
    for(;;){
        printf("Enter digits:\n");
        read_input();
    }
    return 0;
}
/*******************************************************
 * read_input(): Reads the user input char by char     *
 * where if char is not a number ignore it, if char    *
 * is a digit sends it process_digit(), if char is     *
 * '\n' finish reading and call print_digits_array().  *
 *******************************************************/
void read_input(void){
    char user_input;
    int position = 0;                       //position is going to be from 0 to 9, when
                                            //passed as an argument it would be passed as
                                            //position + 4, because each digit is 4 columns
                                            //in this seven digits representation, 3 chars and
                                            //a space.
    clear_digits_array();
    while(1){    //position from 0 - 9, so we need + 1 here.
        user_input = getchar();

        if(user_input == '\n'){  //call print_digits_array();
            print_digits_array();
            return;
        }else if(position + 1 > MAX_DIGITS){
            print_digits_array();
            while(getchar()!= '\n');
            return;
        }else if(user_input == 'q' || user_input == 'Q')
            exit(EXIT_SUCCESS);
        else if(user_input >= '0' && user_input <= '9'){
            process_digit(user_input - '0', 1 + 4 * position); //1 because position is from 0 to 9 and 4 because each digit is 4 column width.
            position++;
        }
    }
}
/*******************************************************
 * clear_digits_array(): Sets all the elements of      *
 * the output array digits[][] into space to clear it. *
 *******************************************************/
void clear_digits_array(void){
    for(int i = 0; i < CHAR_LENGTH_OF_DIGITS; i++){
        for(int j = 0; j < MAX_DIGITS * 4; j++)
            digits[i][j] = ' ';
    }
    return;
}
/*******************************************************
 * process_digit(): It takes a digit, represent it in  *
 * digits[] array according to its position.           *
 *******************************************************/
void process_digit(int digit, int position){
    digits[0][1 + (position - 1)] = segments[digit][0];
    digits[1][2 + (position - 1)] = segments[digit][1];
    digits[2][2 + (position - 1)] = segments[digit][2];
    digits[2][1 + (position - 1)] = segments[digit][3];
    digits[2][0 + (position - 1)] = segments[digit][4];
    digits[1][0 + (position - 1)] = segments[digit][5];
    digits[1][1 + (position - 1)] = segments[digit][6];
    return;
}
/*******************************************************
 * print_digits_array(): prints every element in the   *
 * array digits[][] to represent the seven segments    *
 * numbers.                                            *
 *******************************************************/
 void print_digits_array(void){
    for(int i = 0; i < CHAR_LENGTH_OF_DIGITS; i++){
        for(int j = 0; j < MAX_DIGITS * 4; j++)
            printf("%c", digits[i][j]);
        printf("\n");
    }
    printf("\n");
    return;
 }
