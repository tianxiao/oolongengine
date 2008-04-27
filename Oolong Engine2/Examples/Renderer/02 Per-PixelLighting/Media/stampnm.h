/******************************************************************************

 @File         stampnm.h

 @Title        Demonstrates multitexturing in OGLES

 @Copyright    Copyright (C) 2006 - 2007 by Imagination Technologies Limited.

 @Platform     Independant

 @Description  Shows multitexturing in OGLES using combiners.

******************************************************************************/
#ifndef A32BIT 
 #define A32BIT static const unsigned long
#endif

A32BIT stampnm[] = {

/* Header */
0x00000034,		/* dwHeaderSize */
0x00000080,		/* dwHeight */
0x00000080,		/* dwWidth */
0x00000000,		/* dwMipMapCount */
0x00000219,		/* dwpfFlags */
0x00002000,		/* dwDataSize */
0x00000004,		/* dwBitCount */
0x00000000,		/* dwRBitMask */
0x00000000,		/* dwGBitMask */
0x00000000,		/* dwBBitMask */
0x00000001,		/* dwAlphaBitMask */
0x21525650,		/* dwPVR */
0x00000001,		/* dwNumSurfs */

/* Data */
0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efc3f0,
0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efc3f0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,
0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efc3f0,0xaaaaaaaa,0xc3efc3f0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efc3f0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efc3f0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,
0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0x6aa86a8a,0xbff0c3ee,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xfcfcf106,0xbfefc3ee,0xaaaaaaaa,0xc3efbff0,0xa4e8eaaa,0xbfefbff0,0xaba8acbc,0xbff0c3ee,0xebababab,0xc3f0bfee,
0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefc3f0,0xaaaaaaaa,0xbfefc3f0,0xaaaaaaaa,0xbfefc3f0,0xaea8aaca,0xc3f0bfee,0xaaaaaaca,0xbfefc3f0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefc3f0,0xa6a8aa8a,0xbff0c3ee,0xeaaa6a6a,0xbfefc3f0,0xaaaaaacc,0xc3f0bfee,0xaaaaaa8c,0xbfefc3f0,0xeaeaeaff,0xc3f0bbee,0xeaeaeaea,0xc7efbbf0,
0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefc3f0,0xaaaaaaaa,0xbfefc3f0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefc3f0,0xaba8ee8a,0xc3f0bfee,0xaaa8aba8,0xc3f0bfee,0xffffffea,0xbfefbbf0,0xaaaaeafe,0xc3f0bfee,0xaaaa6a8a,0xbfefc3f0,0xaaa8aaca,0xc3f0bfee,0xaba8aaaa,0xc3f0bfee,0xaaa86b8c,0xbfefc3f0,
0xa5aaaaaa,0xbfefc3f0,0xffabeffc,0xc3f0bbee,0xaaaaaa0a,0xc3efbff0,0xffababaa,0xbfefc3f0,0xffffffff,0xbfef839a,0xffffffff,0xbbf0820c,0x0fffffff,0xbff1c27e,0x4350c0c3,0xf3298e8f,0xe6a86400,0xbff0c3ee,0xefeaeaea,0xbfefc3f0,0xffeae9c0,0xbfefc3f0,0xffffffff,0xc3f18e10,0x96efefef,0xc7efbff2,0xbe6f5b55,0xfdbf8bec,0xc30f3fff,0xb3f18e5a,0xf0f0e0b0,0xf3498210,
0xffffffff,0xc3f08230,0xffffffff,0xbfefbbf0,0xffff3f0f,0xb7f0820a,0xffffffff,0xc3f08310,0xaaaaeafe,0xc3f0bfee,0xaaa8aaaa,0xc3f0bfee,0xffffffff,0xbfefbbf0,0xaaaaeafe,0xc3f0bfee,0x4390e4f9,0xe7e99a42,0xffff3f0f,0xb7f08230,0xbe2f1be2,0xfd9d8288,0x4390e4f9,0xebea9242,0xffffffff,0xc3ef8390,0xffffffff,0xbfefbbf0,0xffff3f0f,0xb7f08210,0xffffffff,0xc3f08370,
0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xeae8ea0a,0xbff0c3ee,0xaaaaaaaa,0xbfefc3f0,0xffffff00,0xc3efbfee,0xaaaaaaaa,0xc3efbff0,0xeaa8aa8a,0xbff0c3ee,0xaaaaaaaa,0xc3efbff0,0xffa8aaaa,0xc3efbff0,0xeaeaeaca,0xc3efbff0,0xefeaead5,0xc3f0bfee,0xffffffff,0xbff093fa,0xffffffff,0xbff08364,
0xaaaaaaca,0xc3efbff0,0xaaabaf40,0xbff0c3ee,0xa9a9eaef,0xc3f0bfee,0xaaa8a995,0xc3efbff0,0xa9aaaaaa,0xbfefc3f0,0xffa9a9a8,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xffaaaaaa,0xbfefc3f0,0xffffffff,0xbfefbbf0,0xaaaaeaea,0xc3efbff0,0xffffffff,0xbff0820c,0xeaeaffff,0xc3efbbf0,0xa6a8aaca,0xbff0c3ee,0xffaa6aaa,0xbfefc3f0,0xaaaaeaff,0xbff0c3ee,0xafa8aaaa,0xc3f0bfee,
0xaaaaaa8a,0xc3efbff0,0xffaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefc3f0,0xffaaaaaa,0xc3efbbf0,0xffffffff,0xbff0f77e,0xb4d0420b,0xe6e6861c,0xffffffff,0xbbf0e21e,0xc7f1fcff,0xcff1ea1f,0xaaa8fdfd,0xc3f0bfee,0xafaaaaca,0xbfefc3f0,0xeaaaaa9b,0xc3f0bfee,0xaaaaaa8c,0xbfefc3f0,0xffafafaf,0xc3efbbf0,0xffffffff,0xb7efba1e,0xbfaaaaaa,0xbfefc3f0,0xffffffff,0xc3f0bbf0,
0xff7f0f93,0xbfee8200,0xffffffff,0xbff08210,0x40c0f52e,0xfe32b6ee,0xff3f0f03,0xc3ef8202,0xebebffff,0xc3efbbf0,0xaba8ebeb,0xbfefc3f0,0xffffffff,0xbff08210,0xeaeaffff,0xc3efbbf0,0xcbf3fcff,0xcff1d21e,0x40c0f43e,0xfe13b70e,0xffffffff,0xb7efba1e,0x8ff3fcff,0xd3d1ca1e,0xff3f0f03,0xc3ef8202,0xffffffff,0xbff08210,0x40c0f43d,0xfe13b30e,0xff3f0f03,0xc3ef8202,
0xffffffff,0xbff1921e,0xd30f3fff,0xbfaa8216,0xf3ffffff,0xc3f0d35e,0xff3f0880,0xca20ca1c,0xaa6900e3,0xd3e2e2de,0xa5ff7faa,0x9a40e3fe,0x2e00307e,0xd3f5ae3c,0xffff55aa,0xc660aff6,0xffffffff,0xbff0bbfe,0xf1f4fdff,0xbbf0df1e,0x6fafaf5f,0xc3efbff0,0x7fff3f0f,0xbfefc3ee,0x7e7c7c4f,0xfe5283ee,0x430f3d7d,0xf303a6bf,0xe5e5e5f1,0xbff0c3ee,0xd50000d5,0xc7e6ca9f,
0xf0dd0300,0xd6609e3d,0xbe6f5bb2,0xfddc83f2,0x820b1f20,0xf3ea8258,0xc1514141,0xf7ee8eed,0x4390e4f9,0xebca9242,0xffff3f0f,0xb7f08270,0xbe2fcbc2,0xfdb98210,0x4390e4f9,0xefec8e02,0xd5565450,0xefe99bf4,0x030f3df5,0xed60d3ee,0x030f3df5,0xed40bbec,0xa4a04000,0xbbefc3f0,0xf40e0143,0xb660a29c,0xbeafdbd2,0xfdf7836e,0x0f3f3080,0xf703961e,0xa2a28283,0xebee82ce,
0xaca86ba4,0xbff0c3ee,0xffa8a440,0xc3efbff0,0xe9aaeaea,0xbfefc3f0,0xffe8e9e5,0xbff0c3ee,0xffffffff,0xc3f0bbfc,0xd0f4ffff,0xbff0de5f,0xffffffff,0xc3efa21a,0xffffffff,0xbff083ee,0xffebffff,0xc3f0bbee,0xffffffff,0xc3efa21a,0xffffffff,0xbbed83da,0x0f3fffff,0xbff09a18,0x033fffff,0xbff0a61e,0x0f83d0c8,0xc3ec8e06,0xbffcf0c3,0xbbf18316,0x1ffefaeb,0xfa82a21c,
0xf170b88b,0xfe708310,0x0abcb4f0,0xdf438a1a,0xfefefeff,0xbbefbbfe,0x0080fefe,0xc3efd6de,0xaaa8a000,0xcbebabf8,0x5f7df5d5,0xfaa193fb,0x5f7df5ea,0xf64097f4,0xb0c20a2b,0xbff18e7c,0xffffff3f,0xc7f1838c,0xfcffffff,0xbbefee3e,0xe5f97c03,0x9221cffc,0xefff1b16,0xbff0cfec,0x706cc7f2,0xf333a23e,0x39f1f1f4,0xfe2bcfe8,0xeacfcfdf,0xb3eebbf0,0x38e0e4e9,0xcbedbbf4,
0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaa8a,0xbfefc3f0,0xaaaaaaaa,0xc3efc3f0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efc3f0,0xaaaaaaaa,0xbfefbff0,
0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,
0xaaaa6a8a,0xbfefc3f0,0xaaaaaaaa,0xc3efbff0,0xaaa8aaaa,0xc3f0bfee,0xaaaa6a8a,0xbfefc3f0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efc3f0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaeafe,0xc3f0bfee,0xaaa8aaaa,0xc3f0bfee,0xffffffff,0xbfefbbf0,0xaaaaeafe,0xc3f0bfee,0xaaaa6a8a,0xbfefc3f0,0xaaaaaaaa,0xc3efbff0,0xaaa8aaaa,0xc3f0bfee,0xaaaa6a8a,0xbfefc3f0,
0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efc3f0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efc3f0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efc3f0,0xaaaaaaaa,0xbfefbff0,
0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,
0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,
0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,
0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,
0xffffffff,0xc3f083f0,0xffffffff,0xbfefbbf0,0xffff3f0f,0xb7ef8270,0xffffffff,0xc3f083f0,0xaaaaeafe,0xc3f0bfee,0xaaa8aaaa,0xc3f0bfee,0xffffffff,0xbfefbbf0,0xaaaaeafe,0xc3f0bfee,0x4390e4f9,0xebee8e02,0xffff3f0f,0xb7ef82d0,0x3ecfc3d2,0xfd8e9e18,0x4390e4f9,0xf3f08a02,0xffffffff,0xc3f083f0,0xffffffff,0xbfefbbf0,0xffff3f0f,0xb7ef82b0,0xffffffff,0xc3f083f0,
0xaaaa6a8a,0xbfefc3f0,0xaaaaaaaa,0xc3efbff0,0xaaa8aaaa,0xc3f0bfee,0xaaaa6a8a,0xbfefc3f0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efc3f0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaeafe,0xc3f0bfee,0xaaa8aaaa,0xc3f0bfee,0xffffffff,0xbfefbbf0,0xaaaaeafe,0xc3f0bfee,0xaaaa6a8a,0xbfefc3f0,0xaaaaaaaa,0xc3efbff0,0xaaa8aaaa,0xc3f0bfee,0xaaaa6a8a,0xbfefc3f0,
0x7f400017,0x9340aedf,0x3e0f43fc,0xedcbc71a,0xfec10564,0xde80cfee,0xf8e0c13f,0xfe68823c,0x4390e4f9,0xf7f08a02,0xffff3f0f,0xb7ef82f0,0x3e4f2334,0xe9ea8e34,0x4390e4f9,0xf3ec8e04,0x959f4f3c,0xe767b7f6,0x80030b28,0xcbec969c,0xd0830ecd,0xa7f6861a,0xf6da68f0,0xdfe9a3f2,0xfdc35568,0xcf00bff0,0x3e4f0738,0xf6108e16,0x020b7ffd,0xfa02c75c,0xe34f3ce0,0xede19218,
0xffffffff,0xc3f083f0,0xffffffff,0xbfefbbf0,0xffff3f0f,0xb7f08310,0xffffffff,0xc3f083f0,0xaaaaeafe,0xc3f0bfee,0xaba8aaaa,0xc3f0bfee,0xe6e8ffff,0xbfefc3f0,0xaaaaeaca,0xc3f0bfee,0x4390e4f9,0xefe78a04,0xffff3f0f,0xb7f1872e,0xfe3f8bd2,0xea19820a,0x4390e4f9,0xebe48a06,0xffffffff,0xc3ef83f0,0xe6e8ffff,0xbfefc3f0,0xffff3f0f,0xb7f1872e,0xffffffff,0xc3ef83f0,
0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efc3f0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efc3f0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,
0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efc3f0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,
0xaaa8aba8,0xbff0c3ee,0xaaaa6a8a,0xc3efbff0,0xaaaaaaaa,0xc3f0bfee,0xaaa8aaaa,0xbff0c3ee,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaca,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaeaca,0xc3f0bfee,0xaaaaaaaa,0xc3f0bfee,0xe6e8ffff,0xbfefc3f0,0xaaaaeaea,0xbff0c3ee,0xaaaaaacc,0xbfefc3f0,0xaaaaaaaa,0xc3efbff0,0xaaaaaa8c,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,
0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaa8aa8a,0xbff0c3ee,0xaaaaaaaa,0xbfefc3f0,0xaaa8aaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefc3f0,0xaaaaaaaa,0xbfefc3f0,0xaaaaaaaa,0xc3efbff0,0xfda8aa8a,0xc3f0bfee,0xfdfdfdfd,0xbfefbfef,0xa9a8aaaa,0xbfefc3f0,0xaba9a9a9,0xc3efbff0,
0xaaa8aaaa,0xbfefc3f0,0xaaaaaaaa,0xbfefc3f0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xabaaaaaa,0xc3efbff0,0xbfafabaf,0xbfefc3f0,0xaaaaaaaa,0xc3efbff0,0x66aaaa8a,0xbff0c3ee,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaa8aaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefc3f0,
0xffffffff,0xc3f0bff0,0xffffffff,0xb7efbbde,0xbfafabab,0xbfefc3f0,0xffafafff,0xc7f0bbf0,0x8fe3f8fe,0xdbd0c65e,0x40c0f43d,0xfe32b30e,0xffffffff,0xb3efbbfe,0x4fd3f4fd,0xdbefc69e,0xaaaaaaaa,0xbfefc3f0,0xffafabab,0xbfefc3f0,0x6aaaaaaa,0xbfefc3f0,0xaba8ae8a,0xc3f0bfee,0xffafafff,0xc7f0bbf0,0xffffffff,0xb3efbbbe,0xafaf6f8f,0xbfefc3f0,0xffafafaf,0xc7efbbf0,
0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefc3f0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,
0xaaa8ae8a,0xc3f0bfee,0xaaaaaaaa,0xc3f0bfee,0xa6a8aaaa,0xbfefc3f0,0xaaaaaa8a,0xc3f0bfee,0xaaa8aaaa,0xc3f0bfee,0xafaa6a8a,0xbfefc3f0,0xaaaaaaaa,0xc3f0bfee,0xaaaaaaaa,0xbff0c3ee,0xaaaaaaaa,0xc3efbff0,0xa6a8aaaa,0xbfefc3f0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaa8a,0xc3f0bfee,0xaaaaaaaa,0xc3f0bfee,0xa6a8aaaa,0xbfefc3f0,0xaaaaaa8a,0xc3f0bfee,
0xf33b0b02,0xcefe8204,0xaaa8e0f1,0xefc6839e,0x00c0f03d,0xfd95bb0c,0xbf2f0b02,0xe99f8208,0x0ffefaea,0xe6a1c2bc,0xf030e103,0xe6ee86b4,0xa0c0c3f3,0xe76882d8,0x3cff5754,0xce60af1d,0x4fd3f4fd,0xdbeeca9e,0x00c0f03c,0xfdb5baec,0xffffffff,0xb3f0bbfe,0x0fd3f0fc,0xdbcfcebe,0x5f1b0702,0xfe9f8308,0x50425f5f,0xff68a73e,0x40d0f43c,0xfe72aea8,0xbf3e0a01,0xd25f824c,
0x3ffbd5d4,0xf6838fb0,0x3f3f3f29,0xbfef820a,0xa8b08303,0xd3ef86b8,0x7df7d668,0xf644b3f6,0xffff7f3f,0xc7f18223,0xfcffffff,0xbbf0be1e,0xdff70c0c,0xb6c48e1e,0xdfd77f7f,0xbff3c7eb,0x3df1c555,0xe643c3ec,0x4105175f,0xf7e192fc,0x4105c7ff,0xf66186dc,0xc0410050,0xfde4c7ee,0xffd30010,0xc9c0cbea,0xc2055501,0xcfe0ab98,0x432fbcf0,0xe6e4cfee,0xfc8002b9,0xb3f7a61e,
0xffafafaf,0xc7efbbf0,0xffffffff,0xb3f0bffe,0xafaa6aaa,0xbfefc3f0,0xffafafaf,0xc7efbbf0,0x0fd3f0fc,0xdbafce9e,0x00c0f03c,0xfe14b6ca,0xffffffff,0xb3f0bbfe,0x0fd3f0fc,0xd7afce7e,0xa9aaaaaa,0xbff0c3ee,0xafa9a9a8,0xbff0c3ee,0xeaaaaaaa,0xc3f0bfee,0xaaaaa68a,0xbfefc3f0,0xffafaf9f,0xc7efbbf0,0xffffffff,0xb3f0bffe,0xafaaaaaa,0xbfefc3f0,0xffafafaf,0xc7efbbf0,
0x5f1b0b02,0xff7f82e8,0x07079f5f,0xeab18fae,0x40d0f43d,0xfeb0ae6a,0x7f1f0701,0xd2de82e9,0xc9050525,0xf7e58ab4,0xabaf9000,0xb7e7bade,0x024b7b7e,0xfe0b929e,0xfd055550,0xb780c7f0,0x0fc3f0fc,0xdbafce9e,0x0080e03c,0xfe75ba88,0xffffffff,0xb3f0bb5e,0x0fc3f0fc,0xd7aed29e,0x6f1a0601,0xf6df834a,0xeffff0bd,0xddc9bff2,0x40d0f03c,0xfed2ae08,0xf93b0a41,0xcbef832c,
0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efc3f0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,
0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efc3f0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaba8aaaa,0xbfefc3f0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,
0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,
0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efc3f0,
0xaaa8aba8,0xbfefc3f0,0x6aaaaaaa,0xbfefc3f0,0xaaaaaaaa,0xbfefc3f0,0xaaa8ae8a,0xc3f0bfee,0xaaa8ae8a,0xc3f0bfee,0xafaaaaca,0xbfefc3f0,0xeaaaaaaa,0xc3f0bfee,0xaaaaaa8c,0xbfefc3f0,0xaaaaaaaa,0xc3efbff0,0xaba8aaaa,0xbfefc3f0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaa8aba8,0xbfefc3f0,0xaaaaaaaa,0xbfefc3f0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,
0xffafafaf,0xc7efbbf0,0xffffffff,0xb7f0bb9e,0xafa96aaa,0xbff0c3ee,0xffafefff,0xc3efbbf0,0x0fc3f0fc,0xd390d27e,0x90e4f93e,0xfae8860c,0xffffffff,0xbbefd3fe,0x0bd3f0fc,0xcfb0e61e,0xaba8aaaa,0xc3efbff0,0x6fabab8f,0xbff0c3ee,0xaaaaaaaa,0xc3efbbf0,0xa9aaaaaa,0xbfefc3f0,0xffafefff,0xc3efbbf0,0xffffffff,0xbbf0bbfe,0xafaba764,0xbff0c3ee,0xffafafff,0xc3efbbf0,
0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efc3f0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,
0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaa85,0xbff0c3ee,0xabaaaaaa,0xc3f0bfee,0xa9aaaaaa,0xbfefc3f0,0xaaa9a9a8,0xc3efbff0,0xaaaaaaaa,0xc3efc3f0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaa8aa8a,0xbff0c3ee,0xaaaaaaaa,0xc3efbff0,0xaaa8aaaa,0xc3efbff0,
0x1f07c1f0,0xd3eaf1ff,0x030f3ffe,0xf1a0c7ec,0xfcffffff,0xbff087fe,0xf9e4f9fb,0xc7eea7f2,0xe0e99541,0xbbecbff6,0x030f2fa0,0xf3eb9e3c,0x431f3f3e,0xb7f4821a,0xea68b0d0,0xcbed97f4,0xffff3f4b,0xbff08202,0xf0ffffff,0xc3f0aa3e,0xf3f8edff,0xcee18232,0xffff3f3f,0xbbf1820c,0x7f1e04c3,0xbfeef5fa,0x0f2ffdf6,0xf9e0c3ec,0xa0fcffff,0xc3eea77e,0x0000505f,0xeb00bff0,
0xf85d54a0,0xbec0a3f6,0xbe2f1be2,0xf9f98210,0x0b2ffdf5,0xfe40c73c,0x3cfdf0c0,0xe2a48a36,0x4390e4f9,0xefe58a06,0xffff3f0f,0xb7f1836e,0x3ecfc706,0xd650a23c,0x4390e4fa,0xebe48e06,0xa8945503,0xbbeabff4,0xc1f1730b,0xfef3aa1e,0xffd28040,0xbff2bfee,0x3f7fffff,0xb3ee8a18,0x1f3ffaeb,0xe6a282f2,0x3e2f0b06,0xfe798210,0xfafcd003,0xbbeec25e,0x0f5bfffe,0xce20c33e,
0xe087fffa,0xee23befc,0x72747d70,0xfa8b87ce,0x000003ff,0xfd03bfee,0xf5f50100,0xc3f0cbf0,0x565a5a5a,0xc3eac3f0,0xf9f4a555,0xbff0bbf0,0xa9a5f5f5,0xbfefc3f0,0xffafaaaa,0xc3efbff0,0x00000000,0xf7e0c3ee,0x57570000,0xbfeebff1,0xf4f4f4f9,0xbff0bbf0,0xeaeaf5f4,0xc3efbff0,0xaaa8fa97,0xc3f0bfee,0xafaaaaca,0xbfefc3f0,0xaba8eaea,0xbfefc3f0,0xeba8eb8c,0xc3f0bfee,
0x0f3ffffe,0xc3efb21e,0xaffdf0c3,0xd2808e7a,0xfcffffff,0xbfefffde,0xc2fdbf00,0xea378eaa,0xffbf0600,0xc7eefe5e,0x00f9ffab,0xa680ae7e,0xdae1c0c2,0xfbea8afa,0x002fffd6,0xe9e0c7ee,0x57afafcf,0xc3f0bfee,0x03010000,0xa39fc7ee,0xb0a8ab8c,0xbfefc3f0,0xa0a460d0,0xc3f1bbee,0x03030303,0xfc16c3ee,0x00000003,0xc780bff0,0xa0a0a0a0,0xc3efbff0,0xf5f4f4f0,0xc3f0bff0,
0xffffffff,0xc3ef87f0,0xaaaaffff,0xbfefc3f0,0xffff3f0f,0xbbf1878e,0xeaeaffff,0xc3efbbf0,0xaaaaaaaa,0xc3efbff0,0xfca8aa8a,0xbff0c3ee,0xaa6aaaea,0xc3eebff0,0xa7a8aaaa,0xc3efbff0,0x8390e4f9,0xdbc28a08,0xffff3f0f,0xb7f1836e,0x3f0ff311,0xe24daa1e,0x4391a8fe,0xdfa48208,0xfde9ffff,0xc3f0bfee,0xfdfdfdfd,0xbfefbfef,0xbfbf3f0f,0xbfef9bf0,0x16566abf,0xc7f1c3ee,
0xf1fcfcfc,0xc3efbfee,0xaaaaaa06,0xbfefc3f0,0xafafef4f,0xbff0c3ee,0xaaaaaa80,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaa8a995,0xc3efbff0,0xaaaaaaaa,0xbfefc3f0,0xbaaafe85,0xbfefbff0,0xeae8eafe,0xc3f0bfee,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaa0a,0xbfefc3f0,0xaaaaaaaa,0xc3efbff0,
0x030f3df0,0xfe05bfd0,0x3e2d0701,0xfd8ec3b6,0x00000000,0xfeb3bfee,0x50500000,0xcbd4bfee,0x0101030f,0xe6a0c3ee,0x55540101,0xbfedbff0,0x50505040,0xc3edbff0,0xfafaf5a4,0xbff0c3f0,0x90905040,0xc7f0c3f0,0xf9f93580,0xbfefbfee,0x6a6aa9a5,0xbfeebff0,0xa7a8a9aa,0xbfefc3f0,0x9599a9a9,0xc3f1bfee,0xebeb3f4e,0xbfefc3f0,0xaaaaaa8a,0xc3f0bfee,0x57545555,0xc3f1bfef,
0x6aaaaaaa,0xc3efbff0,0xffffffc1,0xbfefc3ef,0xfdf9358a,0xc3efbfee,0xafabffff,0xbff0c3ee,0xaaaaaa00,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaa80,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xa8a8a9aa,0xbfefc3f0,0xaaa8a8a8,0xc3efbff0,0xaaaaef9b,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,
0xff7f1f43,0xb7ee82a6,0xffffffff,0xc3f18bee,0xa0a8aa2e,0xfb008e16,0xff3f0f83,0xbbed8328,0xfafeffff,0xbfefbbf0,0xaaa8eaea,0xbfefc3f0,0xffffffff,0xc3f183ec,0xfcfcffff,0xbfefbbee,0x06d2f0fc,0xcfedf23e,0xf0bc6f1b,0xc280b216,0xffffffff,0xbbf1bb3e,0x9ac1f0fc,0xd3ecde9e,0xbf7f0fc3,0xc3ee838c,0x5b5abfbf,0xbff1bfee,0x01020f3f,0xfce0bfee,0xa8a80101,0xbfefc3f0,
0xaaaaaaaa,0xbfefc3f0,0xafadabab,0xbfefc3f0,0xeea8fcfc,0xc3f0bfee,0xaaaaaa8a,0xbfefc3f0,0xaaaaaaaf,0xc3efbff0,0x6bafabab,0xbfefc3f0,0xaaaaaaaa,0xbfefc3f0,0xaba8aa8a,0xc3f0bfee,0xaaa8a307,0xbfefc3f0,0xaaaaaaaa,0xbfefc3f0,0xaea8e880,0xc3f0bfee,0xaaaaaa8a,0xbfefc3f0,0xaaaaaaaa,0xc3efbff0,0xaba8aaaa,0xbfefc3f0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,
0x5f5f5f5f,0xc3eebff1,0x0e0f0f0f,0xb3f2bfee,0xaaaaaaaa,0xbfefc3f0,0xa868a8aa,0xc3eebff0,0xa090f004,0xc7efbff0,0xaaaaa4a0,0xbfefbff0,0xaaaaabab,0xbfefc3f0,0xaaaaaaaa,0xc3efbff0,0xaaaaaa8a,0xc3efbff0,0xededfeba,0xbff0bfee,0xaaaaaaaa,0xc3efbbf0,0xababaaaa,0xc3efbff0,0xaba8adad,0xc3f0bfee,0xaaa8aba8,0xbff0c3ee,0xaba8abab,0xbfefc3f0,0xaaa8aba8,0xc3efbff0,
0xaaa8aaaa,0xbfefc3f0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaa8a,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efc3f0,0xaaaaaaaa,0xc3efc3f0,0xaaaaaaaa,0xbfefbff0,
0xe5f9f5c6,0xc3efbfee,0xaaaaaa56,0xc3efbff0,0xafafafaf,0xbff0c3ee,0xaaaaaa85,0xc3efbff0,0xa9a8aaaa,0xbfefc3f0,0xaea9a9ad,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaa8aba8,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efc3f0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,
0xaaaaabaf,0xbfefc3f0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,
0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efc3f0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xbfefbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,
0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,0xaaaaaaaa,0xc3efbff0,
0 };
