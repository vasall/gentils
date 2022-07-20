#include "refnc.h"

#include <stdlib.h>


GTLS_API s32 tozero(const s8 *s)
{
	const s8 *sc;

	if(!s) {
		ALARM(ALARM_WARN, "s undefined");
		return -1;
	}

	for(sc = s; *sc != 0; ++sc)
		/* nothing */;
	return sc - s;
}


GTLS_API s32 cpytozero(s8 *dst, const s8 *src)
{
	s8 *tmp = dst;

	if(!dst || !src) {
		ALARM(ALARM_WARN, "dst or src undefined");
		return -1;
	}

	while((*dst++ = *src++) != 0)
		/* nothing */;

	return src - tmp - 1;
}


GTLS_API s8 cmptozero(const s8 *cs, const s8 *ct)
{
	u8 c1;
	u8 c2;

	while(1) {
		c1 = *cs++;
		c2 = *ct++;
		if(c1 != c2)
			return c1 < c2 ? -1 : 1;
		if(!c1)
			break;
	}
	return 0;
}


GTLS_API void *smalloc(s32 len)
{
	void *p;

	if(len < 1) {
		ALARM(ALARM_WARN, "len invalid");
		return NULL;
	}

	if(!(p = malloc(len))) {
		ALARM(ALARM_ERR, "failed to allocate memory");
		return NULL;
	}

	return p;
}


GTLS_API void *scalloc(s32 len)
{
	void *p;

	if(len < 1) {
		ALARM(ALARM_WARN, "len invalid");
		return NULL;
	}

	if(!(p = calloc(1, len))) {
		ALARM(ALARM_ERR, "failed to callocate memory");
		return NULL;
	}

	return p;
}


GTLS_API void *srealloc(void *old, s32 newlen)
{
	void *p;

	if(!old || newlen < 1) {
		ALARM(ALARM_WARN, "old undefined or newlen invalid");
		return NULL;
	}

	if(!(p = realloc(old, newlen))) {
		ALARM(ALARM_ERR, "failed to reallocate memory");
		return NULL;
	}

	return p;
}


GTLS_API void sfree(void *p)
{
	if(!p) {
		ALARM(ALARM_WARN, "p undefined");
		return;
	}

	free(p);
}
