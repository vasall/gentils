#ifndef _GENTILS_REFNC_H
#define _GENTILS_REFNC_H

#include "define.h"
#include "imports.h"
#include "data_types.h"


/*
 * The same as strlen() but takes a s8 pointer instead of char pointer.
 *
 * @s: Pointer to string to determine the length of
 *
 * Returns: Either the length of the string in bytes or -1 if an error occurred
 */
GTLS_API s32 tozero(const s8 *s);


/*
 * The same as strcpy() but takes s8 pointers instead of char pointers.
 *
 * @dst: The pointer to copy to
 * @src: The pointer to copy from
 *
 * Returns: Either the number of copied bytes or -1 if an error occurred
 */
GTLS_API s32 cpytozero(s8 *dst, const s8 *src);


/*
 * The same as strcmp() but takes s8 pointers instead of char pointers. 
 *
 * @cs: The original string
 * @ct: The string to compare to
 *
 * Returns: 0 if they are equal, 1 if cs is bigger and -1 if ct is bigger
 */
GTLS_API s8 cmptozero(const s8 *cs, const s8 *ct);


/*
 * Safer reimplementation of malloc().
 *
 * @len: Number of bytes to allocate in the heap
 *
 * Returns: Pointer to the allocated memory or NULL if an error occurred
 */
GTLS_API void *smalloc(s32 len);


/*
 * Safer reimplementation of calloc().
 *
 * @len: Number of bytes to allocate in the heap and set to zero
 *
 * Returns: Pointer to the allocated memory or NULL if an error occurred
 */
GTLS_API void *scalloc(s32 len);


/* 
 * Safer reimplementation of realloc().
 *
 * @old: Pointer to the old memory
 * @newlen: The number of bytes to allocate
 *
 * Returns: Either a pointer to the reallocated memory or NULL if an error
 *          occurred
 */
GTLS_API void *srealloc(void *old, s32 newlen);

/*
 * Safer reimplementation of free().
 *
 * @p: Pointer to the memory to free
 */
GTLS_API void sfree(void *p);

#endif /* _GENTILS_REFNC_H */
