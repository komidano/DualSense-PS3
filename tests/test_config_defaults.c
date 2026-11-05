/* Verify safety-sensitive configuration defaults from the production source. */
#include "../src/config.c"

void *memset(void *dest, int value, size_t count)
{
	unsigned char *d = dest;

	while (count--)
		*d++ = (unsigned char)value;
	return dest;
}

char *strchr(const char *s, int c)
{
	while (*s) {
		if (*s == c)
			return (char *)s;
		s++;
	}
	return c == 0 ? (char *)s : 0;
}

int strcmp(const char *a, const char *b)
{
	while (*a && *a == *b) {
		a++;
		b++;
	}
	return (unsigned char)*a - (unsigned char)*b;
}

int ds45_read_file(const char *path, char *out, int cap)
{
	(void)path;
	(void)out;
	(void)cap;
	return -1;
}

ds45_map_t ds45_parse_map(const char *name)
{
	(void)name;
	return DS45_MAP_NONE;
}

void ds45_boot_mark(const char *mark) { (void)mark; }
void ds45_boot_mark_hex(const char *mark, uint32_t value)
{
	(void)mark;
	(void)value;
}

int run_config_tests(void)
{
	ds45_config_t config;

	ds45_config_defaults(&config);
	return config.insert_into_game == 0 ? 0 : __LINE__;
}
