#include <iostream>
using namespace std;

int main() {
    unsigned char data[8] = { 10, 3, 4, 7, 8, 12, 1, 6 };
    unsigned char lsb[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
    unsigned char Even_Nums[8] = { 0 };
    unsigned int SUM = 0;

    __asm {
        MOVQ MM0, [data]
        MOVQ MM1, [data]
        MOVQ MM2, [lsb]

        PAND MM1, MM2   // Result: 1 if odd, 0 if even

        PXOR MM2, MM2   // MM2 = 0
        PCMPEQB MM1, MM2    // Compare (data & 1) == 0. 
                            // Result: 0xFF if even, 0x00 if odd.

        PAND MM0, MM1   // Masking -> Odd numbers become 0, Evens stay the same.

        MOVQ[Even_Nums], MM0
        EMMS
    }

    unsigned int temp = 0;
    cout << "Even Numbers: ";
    for (int i = 0; i < 8; i++) {
        temp = Even_Nums[i];
        if (temp != 0) {
            cout << temp << " ";
        }
    }cout << endl;


    for (int i = 0; i < 8; i++) {
        SUM += Even_Nums[i];
    }

    cout << "Sum: " << SUM << endl;

    return 0;
}
