
#ifndef _OBLIV_BASE_H_
#define _OBLIV_BASE_H_

// this is a small file that tries to resolve the interdependence of bcrandom and obliv_common// it is by no means a solution, but a band-aid
// so that i can externalize some diffie-hellman elliptic curve functions

void gcryDefaultLibInit(void);


// C++ doesn't have the restrict keyword
#ifdef __cplusplus
static inline void memxor(void *dest, const void *src, size_t n) {
#else
static inline void memxor(void *restrict dest, const void *restrict src, size_t n) {
#endif
  for(size_t i = 0; i < n; i++) {
    ((char *) dest)[i] ^= ((char *)src)[i];
  }
}

 #endif
