// Twiddle factor with 512-point FFT
// exp(j2*pi/Nt*2 * k) exp(j2*pi/Nt * k) exp(j2*pi/Nt * 3 * k), k in 0~Nt-1
// where and k in 0~Nt/4-1
// Each complex value is of 32bit with each real and imag 16bit, respectively
#include "ambiq_nnsp_debug.h"
#if ARM_FFT==0
#include <stdint.h>
const int32_t fft_tw_coeff[] = {
0x00007fff, 0x00007fff, 0x00007fff, 0x00007fff,
0x00007fff, 0xf9b87fd8, 0xfcdb7ff6, 0xf6957fa7,
0x00007fff, 0xf3747f62, 0xf9b87fd8, 0xed377e9d,
0x00007fff, 0xed377e9d, 0xf6957fa7, 0xe3f47ce3,
0x00007fff, 0xe7077d8a, 0xf3747f62, 0xdad77a7d,
0x00007fff, 0xe0e67c29, 0xf0547f09, 0xd1ee776c,
0x00007fff, 0xdad77a7d, 0xed377e9d, 0xc94573b5,
0x00007fff, 0xd4e07884, 0xea1d7e1d, 0xc0e86f5f,
0x00007fff, 0xcf047641, 0xe7077d8a, 0xb8e36a6d,
0x00007fff, 0xc94573b5, 0xe3f47ce3, 0xb14064e8,
0x00007fff, 0xc3a970e2, 0xe0e67c29, 0xaa0a5ed7,
0x00007fff, 0xbe316dca, 0xdddc7b5d, 0xa34b5842,
0x00007fff, 0xb8e36a6d, 0xdad77a7d, 0x9d0d5133,
0x00007fff, 0xb3c066cf, 0xd7d9798a, 0x975949b4,
0x00007fff, 0xaecc62f2, 0xd4e07884, 0x923541ce,
0x00007fff, 0xaa0a5ed7, 0xd1ee776c, 0x8daa398c,
0x00007fff, 0xa57d5a82, 0xcf047641, 0x89be30fb,
0x00007fff, 0xa12855f5, 0xcc217504, 0x86752826,
0x00007fff, 0x9d0d5133, 0xc94573b5, 0x83d61f19,
0x00007fff, 0x99304c3f, 0xc6737255, 0x81e215e2,
0x00007fff, 0x9592471c, 0xc3a970e2, 0x809d0c8b,
0x00007fff, 0x923541ce, 0xc0e86f5f, 0x80090324,
0x00007fff, 0x8f1d3c56, 0xbe316dca, 0x8027f9b8,
0x00007fff, 0x8c4a36ba, 0xbb856c24, 0x80f6f054,
0x00007fff, 0x89be30fb, 0xb8e36a6d, 0x8275e707,
0x00007fff, 0x877b2b1f, 0xb64b68a6, 0x84a2dddc,
0x00007fff, 0x85822528, 0xb3c066cf, 0x877bd4e0,
0x00007fff, 0x83d61f19, 0xb14064e8, 0x8afbcc21,
0x00007fff, 0x827518f8, 0xaecc62f2, 0x8f1dc3a9,
0x00007fff, 0x816212c8, 0xac6460ec, 0x93dbbb85,
0x00007fff, 0x809d0c8b, 0xaa0a5ed7, 0x9930b3c0,
0x00007fff, 0x80270647, 0xa7bd5cb4, 0x9f13ac64,
0x00007fff, 0x80000000, 0xa57d5a82, 0xa57da57d,
0x00007fff, 0x8027f9b8, 0xa34b5842, 0xac649f13,
0x00007fff, 0x809df374, 0xa12855f5, 0xb3c09930,
0x00007fff, 0x8162ed37, 0x9f13539b, 0xbb8593db,
0x00007fff, 0x8275e707, 0x9d0d5133, 0xc3a98f1d,
0x00007fff, 0x83d6e0e6, 0x9b174ebf, 0xcc218afb,
0x00007fff, 0x8582dad7, 0x99304c3f, 0xd4e0877b,
0x00007fff, 0x877bd4e0, 0x975949b4, 0xdddc84a2,
0x00007fff, 0x89becf04, 0x9592471c, 0xe7078275,
0x00007fff, 0x8c4ac945, 0x93db447a, 0xf05480f6,
0x00007fff, 0x8f1dc3a9, 0x923541ce, 0xf9b88027,
0x00007fff, 0x9235be31, 0x90a03f17, 0x03248009,
0x00007fff, 0x9592b8e3, 0x8f1d3c56, 0x0c8b809d,
0x00007fff, 0x9930b3c0, 0x8daa398c, 0x15e281e2,
0x00007fff, 0x9d0daecc, 0x8c4a36ba, 0x1f1983d6,
0x00007fff, 0xa128aa0a, 0x8afb33de, 0x28268675,
0x00007fff, 0xa57da57d, 0x89be30fb, 0x30fb89be,
0x00007fff, 0xaa0aa128, 0x88932e11, 0x398c8daa,
0x00007fff, 0xaecc9d0d, 0x877b2b1f, 0x41ce9235,
0x00007fff, 0xb3c09930, 0x86752826, 0x49b49759,
0x00007fff, 0xb8e39592, 0x85822528, 0x51339d0d,
0x00007fff, 0xbe319235, 0x84a22223, 0x5842a34b,
0x00007fff, 0xc3a98f1d, 0x83d61f19, 0x5ed7aa0a,
0x00007fff, 0xc9458c4a, 0x831c1c0b, 0x64e8b140,
0x00007fff, 0xcf0489be, 0x827518f8, 0x6a6db8e3,
0x00007fff, 0xd4e0877b, 0x81e215e2, 0x6f5fc0e8,
0x00007fff, 0xdad78582, 0x816212c8, 0x73b5c945,
0x00007fff, 0xe0e683d6, 0x80f60fab, 0x776cd1ee,
0x00007fff, 0xe7078275, 0x809d0c8b, 0x7a7ddad7,
0x00007fff, 0xed378162, 0x8058096a, 0x7ce3e3f4,
0x00007fff, 0xf374809d, 0x80270647, 0x7e9ded37,
0x00007fff, 0xf9b88027, 0x80090324, 0x7fa7f695,
};
const int32_t rfft_tw_coeff[] = {
0x00007fff, 0xfe6d7ffd, 0xfcdb7ff6, 0xfb497fe9, 0xf9b87fd8, 0xf8267fc2, 0xf6957fa7, 0xf5047f87, 0xf3747f62, 0xf1e47f38, 0xf0547f09, 0xeec67ed5, 0xed377e9d, 0xebaa7e5f, 0xea1d7e1d, 0xe8927dd6, 0xe7077d8a, 0xe57d7d39, 0xe3f47ce3, 0xe26c7c89, 0xe0e67c29, 0xdf607bc5, 0xdddc7b5d, 0xdc597aef, 0xdad77a7d, 0xd9577a05, 0xd7d9798a, 0xd65c7909, 0xd4e07884, 0xd36777fa, 0xd1ee776c, 0xd07876d9, 0xcf047641, 0xcd9175a5, 0xcc217504, 0xcab2745f, 0xc94573b5, 0xc7db7307, 0xc6737255, 0xc50d719e, 0xc3a970e2, 0xc2477023, 0xc0e86f5f, 0xbf8c6e96, 0xbe316dca, 0xbcda6cf9, 0xbb856c24, 0xba326b4a, 0xb8e36a6d, 0xb796698c, 0xb64b68a6, 0xb50467bd, 0xb3c066cf, 0xb27e65dd, 0xb14064e8, 0xb00463ef, 0xaecc62f2, 0xad9661f1, 0xac6460ec, 0xab355fe3, 0xaa0a5ed7, 0xa8e25dc7, 0xa7bd5cb4, 0xa69b5b9d, 0xa57d5a82, 0xa4625964, 0xa34b5842, 0xa238571d, 0xa12855f5, 0xa01c54ca, 0x9f13539b, 0x9e0e5269, 0x9d0d5133, 0x9c104ffb, 0x9b174ebf, 0x9a224d81, 0x99304c3f, 0x98424afb, 0x975949b4, 0x96734869, 0x9592471c, 0x94b545cd, 0x93db447a, 0x93064325, 0x923541ce, 0x91694073, 0x90a03f17, 0x8fdc3db8, 0x8f1d3c56, 0x8e613af2, 0x8daa398c, 0x8cf83824, 0x8c4a36ba, 0x8ba0354d, 0x8afb33de, 0x8a5a326e, 0x89be30fb, 0x89262f87, 0x88932e11, 0x88052c98, 0x877b2b1f, 0x86f629a3, 0x86752826, 0x85fa26a8, 0x85822528, 0x851023a6, 0x84a22223, 0x843a209f, 0x83d61f19, 0x83761d93, 0x831c1c0b, 0x82c61a82, 0x827518f8, 0x8229176d, 0x81e215e2, 0x81a01455, 0x816212c8, 0x812a1139, 0x80f60fab, 0x80c70e1b, 0x809d0c8b, 0x80780afb, 0x8058096a, 0x803d07d9, 0x80270647, 0x801604b6, 0x80090324, 0x80020192, 0x80000000, 0x8002fe6d, 0x8009fcdb, 0x8016fb49, 0x8027f9b8, 0x803df826, 0x8058f695, 0x8078f504, 0x809df374, 0x80c7f1e4, 0x80f6f054, 0x812aeec6, 0x8162ed37, 0x81a0ebaa, 0x81e2ea1d, 0x8229e892, 0x8275e707, 0x82c6e57d, 0x831ce3f4, 0x8376e26c, 0x83d6e0e6, 0x843adf60, 0x84a2dddc, 0x8510dc59, 0x8582dad7, 0x85fad957, 0x8675d7d9, 0x86f6d65c, 0x877bd4e0, 0x8805d367, 0x8893d1ee, 0x8926d078, 0x89becf04, 0x8a5acd91, 0x8afbcc21, 0x8ba0cab2, 0x8c4ac945, 0x8cf8c7db, 0x8daac673, 0x8e61c50d, 0x8f1dc3a9, 0x8fdcc247, 0x90a0c0e8, 0x9169bf8c, 0x9235be31, 0x9306bcda, 0x93dbbb85, 0x94b5ba32, 0x9592b8e3, 0x9673b796, 0x9759b64b, 0x9842b504, 0x9930b3c0, 0x9a22b27e, 0x9b17b140, 0x9c10b004, 0x9d0daecc, 0x9e0ead96, 0x9f13ac64, 0xa01cab35, 0xa128aa0a, 0xa238a8e2, 0xa34ba7bd, 0xa462a69b, 0xa57da57d, 0xa69ba462, 0xa7bda34b, 0xa8e2a238, 0xaa0aa128, 0xab35a01c, 0xac649f13, 0xad969e0e, 0xaecc9d0d, 0xb0049c10, 0xb1409b17, 0xb27e9a22, 0xb3c09930, 0xb5049842, 0xb64b9759, 0xb7969673, 0xb8e39592, 0xba3294b5, 0xbb8593db, 0xbcda9306, 0xbe319235, 0xbf8c9169, 0xc0e890a0, 0xc2478fdc, 0xc3a98f1d, 0xc50d8e61, 0xc6738daa, 0xc7db8cf8, 0xc9458c4a, 0xcab28ba0, 0xcc218afb, 0xcd918a5a, 0xcf0489be, 0xd0788926, 0xd1ee8893, 0xd3678805, 0xd4e0877b, 0xd65c86f6, 0xd7d98675, 0xd95785fa, 0xdad78582, 0xdc598510, 0xdddc84a2, 0xdf60843a, 0xe0e683d6, 0xe26c8376, 0xe3f4831c, 0xe57d82c6, 0xe7078275, 0xe8928229, 0xea1d81e2, 0xebaa81a0, 0xed378162, 0xeec6812a, 0xf05480f6, 0xf1e480c7, 0xf374809d, 0xf5048078, 0xf6958058, 0xf826803d, 0xf9b88027, 0xfb498016, 0xfcdb8009, 0xfe6d8002, };
const int16_t br_coeff[] = {
0, 128, 64, 192, 32, 160, 96, 224, 16, 144, 80, 208, 48, 176, 112, 240, 8, 136, 72, 200, 40, 168, 104, 232, 24, 152, 88, 216, 56, 184, 120, 248, 4, 132, 68, 196, 36, 164, 100, 228, 20, 148, 84, 212, 52, 180, 116, 244, 12, 140, 76, 204, 44, 172, 108, 236, 28, 156, 92, 220, 60, 188, 124, 252, 2, 130, 66, 194, 34, 162, 98, 226, 18, 146, 82, 210, 50, 178, 114, 242, 10, 138, 74, 202, 42, 170, 106, 234, 26, 154, 90, 218, 58, 186, 122, 250, 6, 134, 70, 198, 38, 166, 102, 230, 22, 150, 86, 214, 54, 182, 118, 246, 14, 142, 78, 206, 46, 174, 110, 238, 30, 158, 94, 222, 62, 190, 126, 254, 1, 129, 65, 193, 33, 161, 97, 225, 17, 145, 81, 209, 49, 177, 113, 241, 9, 137, 73, 201, 41, 169, 105, 233, 25, 153, 89, 217, 57, 185, 121, 249, 5, 133, 69, 197, 37, 165, 101, 229, 21, 149, 85, 213, 53, 181, 117, 245, 13, 141, 77, 205, 45, 173, 109, 237, 29, 157, 93, 221, 61, 189, 125, 253, 3, 131, 67, 195, 35, 163, 99, 227, 19, 147, 83, 211, 51, 179, 115, 243, 11, 139, 75, 203, 43, 171, 107, 235, 27, 155, 91, 219, 59, 187, 123, 251, 7, 135, 71, 199, 39, 167, 103, 231, 23, 151, 87, 215, 55, 183, 119, 247, 15, 143, 79, 207, 47, 175, 111, 239, 31, 159, 95, 223, 63, 191, 127, 255, };
#endif