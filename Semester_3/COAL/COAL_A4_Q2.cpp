#include <iostream>
using namespace std;

int main() {
    int arr[10] = { 25, 10, 5, 30, 15, 2, 8, 12, 20, 3 };
    int n = 10;

    cout << "Array before Sorting: ";w
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n\n";

    __asm {
        mov ecx, n
        outer_loop :
        dec ecx
            jz done

            mov esi, 0
            mov edx, ecx        // Inner loop counter

            inner_loop :
            mov eax, [arr + esi * 4]       // eax = arr[j]
            mov ebx, [arr + esi * 4 + 4]   // ebx = arr[j+1]

            cmp eax, ebx        // Compare arr[j] & arr[j+1]
            jle skip_swap       // If arr[j] <= arr[j+1], no swap needed

            // Swap
            mov[arr + esi * 4], ebx
            mov[arr + esi * 4 + 4], eax

            skip_swap :
        inc esi             // j++
            dec edx             // Decrement inner counter
            jnz inner_loop      // Repeat inner loop if edx != 0

            jmp outer_loop      // Repeat outer loop
            done :
              EMMS
    }

    cout << "Sorted Array: ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
