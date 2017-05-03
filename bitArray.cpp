#include <iostream>
using namespace std;

#define NO_OF_BITS (8 * sizeof(unsigned int)) //int size 32 bit

class BitArray{
  unsigned int *a;
  int size;
  public:
    BitArray(int n){
      a = new unsigned int[n/NO_OF_BITS + 1];
      size = n;
    }
    ~BitArray(){
      delete []a;
    }
    void setBit(unsigned int k){
      a[k/NO_OF_BITS] |= (1U << (k%NO_OF_BITS));
    }
    void resetBit(unsigned int k){
      a[k/NO_OF_BITS] &= ~(1U << (k%NO_OF_BITS));
    }
    bool checkSetBit(unsigned int k){
      return ((a[k/NO_OF_BITS] & (1U << (k%NO_OF_BITS))) != 0);
    }
    void flipBit(unsigned int k){
          a[k/NO_OF_BITS] ^= (1U <<(k%NO_OF_BITS));
    }
    void print(){
      for(int i=1;i<=size;i++){
        if(checkSetBit(i))
          cout<<i<<":"<<1<<endl;
        else
          cout<<i<<":"<<0<<endl;
      }
    }
};

int main(){
  BitArray bit(32);
  bit.setBit(8);
  bit.setBit(15);
  bit.setBit(25);
  bit.print();
  bit.resetBit(15);
  bit.print();
  bit.flipBit(16);
  bit.print();
}

