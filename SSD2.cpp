#include "SSD2.h" //include the declaration for this class

int sgmnts [7] = {0,0,0,0,0,0,0};
const byte nums [10] = {0b1111110, 0b0110000, 0b1101101, 0b1111001, 0b0110011, 0b1011011,0b1011111, 0b1110000, 0b1111111, 0b1111011 };
int com1, com2;

//<<constructor>> 
SSD2::SSD2(int A,int B,int C,int D,int E,int F_SEG,int G,int comc1,int comc2){
	sgmnts[0] = A;
	sgmnts[1] = B;
	sgmnts[2] = C;
	sgmnts[3] = D;
	sgmnts[4] = E;
	sgmnts[5] = F_SEG;
	sgmnts[6] = G;
	
        for(int i = 0; i<7 ; i++){
          pinMode(sgmnts[i],OUTPUT);
        }
	com1 = comc1;
	com2 = comc2;
	pinMode(com1,OUTPUT);
	pinMode(com2,OUTPUT);
      }

//other methods
void SSD2::lightTwoDigits(int number,int dly){
  
  for(int j=0;j<dly/4;j++){
    lightDigit1(number/10);
    delay(2);
    lightDigit2(number%10);
    delay(2);
    digitalWrite(com2, HIGH);
  }
}
void SSD2::lightDigit1(int digit) {
  digitalWrite(com1, LOW);
  digitalWrite(com2, HIGH);
  lightSegments(digit);
}

void SSD2::lightDigit2(int digit) {
  digitalWrite(com1, HIGH);
  digitalWrite(com2, LOW);
  lightSegments(digit);
}

void SSD2::lightSegments(int digit) {
  
  for (int i = 0; i < 7; i++) {
    int bit = bitRead(nums[digit], 6-i);
    digitalWrite(sgmnts[i],bit); 
  }
}