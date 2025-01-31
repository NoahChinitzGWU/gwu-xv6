#include "types.h"
#include "stat.h"
#include "fcntl.h"
#include "user.h"
#include "x86.h"
#include "pstat.h"

char *
strcpy(char *s, char *t)
{
	char *os;

	os = s;
	while ((*s++ = *t++) != 0)
		;
	return os;
}

int
strcmp(const char *p, const char *q)
{
	while (*p && *p == *q) p++, q++;
	return (uchar)*p - (uchar)*q;
}

uint
strlen(char *s)
{
	int n;

	for (n = 0; s[n]; n++)
		;
	return n;
}

void *
memset(void *dst, int c, uint n)
{
	stosb(dst, c, n);
	return dst;
}

char *
strchr(const char *s, char c)
{
	for (; *s; s++)
		if (*s == c) return (char *)s;
	return 0;
}

char *
gets(char *buf, int max)
{
	int  i, cc;
	char c;

	for (i = 0; i + 1 < max;) {
		cc = read(0, &c, 1);
		if (cc < 1) break;
		buf[i++] = c;
		if (c == '\n' || c == '\r') break;
	}
	buf[i] = '\0';
	return buf;
}

int
stat(char *n, struct stat *st)
{
	int fd;
	int r;

	fd = open(n, O_RDONLY);
	if (fd < 0) return -1;
	r = fstat(fd, st);
	close(fd);
	return r;
}

int
atoi(const char *s)
{
	int n;

	n = 0;
	while ('0' <= *s && *s <= '9') n= n * 10 + *s++ - '0';
	return n;
}

void *
memmove(void *vdst, void *vsrc, int n)
{
	char *dst, *src;

	dst = vdst;
	src = vsrc;
	while (n-- > 0) *dst++= *src++;
	return vdst;
}

// ps function that prints out all active processes
void 
ps(void)
{
	struct pstat ps;
	int result;
	uint i;
	// since there can only be 64 processes we should not iterate past that
	for (i = 0; i < 64; i++) {
		result = procstat(i, &ps);
		// If UNUSED or error then go past that process
		if (result == 1 || result == -1) {
			continue;
		}
		else {
			// First argument = "file descriptor" to print to
			// Setting first argument to 1 so it can print to standard output
			printf(1, "%d %d %c %s\n", ps.pid, ps.ppid, ps.state, ps.name);
		}
	}
}
