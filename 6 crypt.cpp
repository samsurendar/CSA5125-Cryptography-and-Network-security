#include <stdio.h>
#include <stdint.h>


int initial_permutation[] = {58, 50, 42, 34, 26, 18, 10, 2,
                              60, 52, 44, 36, 28, 20, 12, 4,
                              62, 54, 46, 38, 30, 22, 14, 6,
                              64, 56, 48, 40, 32, 24, 16, 8,
                              57, 49, 41, 33, 25, 17, 9, 1,
                              59, 51, 43, 35, 27, 19, 11, 3,
                              61, 53, 45, 37, 29, 21, 13, 5,
                              63, 55, 47, 39, 31, 23, 15, 7};

int final_permutation[] = {40, 8, 48, 16, 56, 24, 64, 32,
                            39, 7, 47, 15, 55, 23, 63, 31,
                            38, 6, 46, 14, 54, 22, 62, 30,
                            37, 5, 45, 13, 53, 21, 61, 29,
                            36, 4, 44, 12, 52, 20, 60, 28,
                            35, 3, 43, 11, 51, 19, 59, 27,
                            34, 2, 42, 10, 50, 18, 58, 26,
                            33, 1, 41, 9, 49, 17, 57, 25};


int s_box[8][4][16] = {
    {
        {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
        {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
        {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
        {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
    },
    
};


void initialPermutation(uint64_t *block) {
    uint64_t result = 0;
    for (int i = 0; i < 64; i++) {
        result |= ((*block >> (64 - initial_permutation[i])) & 1) << (63 - i);
    }
    *block = result;
}


void finalPermutation(uint64_t *block) {
    uint64_t result = 0;
    for (int i = 0; i < 64; i++) {
        result |= ((*block >> (64 - final_permutation[i])) & 1) << (63 - i);
    }
    *block = result;
}


void des_encrypt(uint64_t *block, uint64_t key) {
    
    initialPermutation(block);

    
    
    *block ^= key;  

    
    finalPermutation(block);
}


void des_decrypt(uint64_t *block, uint64_t key) {
    
    initialPermutation(block);

    
    
    *block ^= key;  

    
    finalPermutation(block);
}

int main() {
    uint64_t block = 0x123456789abcdef0; 
    uint64_t key = 0x133457799BBCDFF1;    

    printf("Original block: 0x%llx\n", block);

    
    des_encrypt(&block, key);
    printf("Encrypted block: 0x%llx\n", block);

    
    des_decrypt(&block, key);
    printf("Decrypted block: 0x%llx\n", block);

    return 0;
}
