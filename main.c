#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <bsd/string.h>
#include <assert.h>

void	test_is_funcs(void)
{
	for (int i = -1; i <= 128; i++)
	{
		if ((!!isalpha(i) != !!ft_isalpha(i)))
			printf("Error in isalpha(%d)\n", i);
		if ((!!isdigit(i) != !!ft_isdigit(i)))
			printf("Error in isdigit(%d)\n", i);
		if ((!!isalnum(i) != !!ft_isalnum(i)))
			printf("Error in isalnum(%d)\n", i);
		if ((!!isascii(i) != !!ft_isascii(i)))
			printf("Error in isascii(%d)\n", i);
		if ((!!isprint(i) != !!ft_isprint(i)))
			printf("Error in isprint(%d)\n", i);
		if (toupper(i) != ft_toupper(i))
			printf("Error in toupper(%d)\n", i);
		if (tolower(i) != ft_tolower(i))
			printf("Error in tolower(%d)\n", i);
	}
}

void	test_strlen(void)
{
	size_t		ft_len;
	size_t		strlen_len;
	const char	*test_strings[] = {
        "Hello, world!",
        "This is a test string.",
        "An empty string.", "", "12345",
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit.",
        NULL
    };

	for (const char **ptr = test_strings; *ptr != NULL; ++ptr)
	{
        const char *test_str = *ptr;
		ft_len = ft_strlen(test_str);
		strlen_len = strlen(test_str);
		if (ft_len != strlen_len)
		{
			printf("Error: Lengths don't match for string: \"%s\"\n", test_str);
		}
	}
}

void	test_memset(void)
{
	char	str_ftmemset[] = "123456789";
	char	*str_memset;
	size_t	str_size;

	str_memset = strdup(str_ftmemset);
	str_size = strlen(str_ftmemset);
	for (int i = -5; i < 1000; i++)
	{
		ft_memset(str_ftmemset, i, 5);
		memset(str_memset, i, 5);
		if (memcmp(str_memset, str_ftmemset, str_size) != 0)
		{
			printf("Error in ft_memset for char: %d\n", i);
			break ;
		}
	}
	free(str_memset);
}

void	test_bzero(void)
{
	char	str_ftbzero[] = "123456789";
	char	*str_bzero;
	size_t	str_size;

	str_bzero = strdup(str_ftbzero);
	str_size = strlen(str_ftbzero);
	ft_bzero(str_ftbzero, 5);
	bzero(str_bzero, 5);
	if (memcmp(str_bzero, str_ftbzero, str_size) != 0)
		printf("Error in ft_bzero\n");
    free(str_bzero);
}

void	test_memcpy()
{
    const char *str = "Hello, world!";
    size_t n = strlen(str) + 1;
	char	dst_ft[20] = {0};
	char	dst_memcpy[20] = {0};
	
    void *ft_memcpy_result = ft_memcpy(dst_ft, str, n);
	memcpy(dst_memcpy, str, n);
	if (dst_ft != ft_memcpy_result)
	{
		printf("Error: Result of ft_memcpy returns wrong value\n");
	}
	if (memcmp(dst_ft, dst_memcpy, n) != 0)
	{
		printf("Error: Result of ft_memcpy does not match memcpy for %zu bytes\n", n);
	}
}

void	test_memmove(void)
{
	void	inner(void *dst_ft, void *src_ft, size_t len)
	{
		char *dst_memmove = strdup(dst_ft);
		char *src_memmove = strdup(src_ft);
		char *ft_memmove_result = (char *)ft_memmove(dst_ft, src_ft, len);
		char *memmove_result = (char *)memmove(dst_memmove, src_memmove, len);

		if (dst_ft != ft_memmove_result)
			printf("Error: Result of ft_memmove returns wrong value\n");
		if (strcmp(ft_memmove_result, memmove_result) != 0)
			printf("Error: Result of ft_memmove does not match memmove: %ld\n", src_ft - dst_ft);
		free(dst_memmove);
		free(src_memmove);
	}
	char str[] = "0123456789";
	inner(str, str, 5);
	inner(str + 3, str, 5);
	inner(str, str + 3, 5);
}

void test_strlcpy()
{
	char dst_ft[] = "abcdefghijklmnopqrstuvwxyz";
	char dst[] = "abcdefghijklmnopqrstuvwxyz";
	char *src = "123456789";

	void inner(char *dst, char *dst_ft, char *src, size_t size)
	{
		size_t res, res_ft;
		res = ft_strlcpy(dst_ft, src, size);
		res_ft = strlcpy(dst, src, size);
		if (res != res_ft)
			printf("Error: Result of ft_strlcpy does not match strlcpy for size %li\n", size);
		if (memcmp(dst_ft, dst, 27) != 0)
			printf("Error: Result of ft_strlcpy does not match strlcpy for size %li\n", size);
	}
	inner(dst, dst_ft, src, 0);
	inner(dst, dst_ft, src, 5);
	inner(dst, dst_ft, src, 20);
}

void test_strlcat()
{
	char	*dst = calloc(20, 1);
	char	*dst_ft = calloc(20, 1);

	char	*src_1 = "123";
	char	*src_2 = "456789";
	char	*src_3 = "asd";
	char	*src_4 = "bcd";
	char	*src_5 = "qwerty";
	char	*src_6 = "!@#$%";

	void inner(char *dst, char *dst_ft, char *src, size_t size)
	{
		size_t res, res_ft;

		res = strlcat(dst, src, size);
		res_ft = ft_strlcat(dst_ft, src, size);
		if (res != res_ft)
			printf("Error: Result of ft_strlcat does not match strlcat for src %s\n", src);
		if (memcmp(dst_ft, dst, size) != 0)
			printf("Error: Dst of ft_strlcat does not match strlcat for src %s\n", src);
	}

	inner(dst, dst_ft, src_1, 20);
	inner(dst, dst_ft, src_2, 20);
	inner(dst, dst_ft, src_3, 20);
	inner(dst, dst_ft, src_4, 20);
	inner(dst, dst_ft, src_5, 20);
	inner(dst, dst_ft, src_6, 20);
	inner(dst, dst_ft, src_6, 0);
	
	free(dst);
	free(dst_ft);
}

void test_strchr()
{
	void inner(const char **test_strings, int c) {
		for (const char **ptr = test_strings; *ptr != NULL; ++ptr) {
			const char *test_str = *ptr;

			// Call ft_strchr and strchr to find the first occurrence of character c
			char *ft_strchr_result = ft_strchr(test_str, c);
			char *strchr_result = strchr(test_str, c);

			// Compare the result of ft_strchr with strchr
			if (ft_strchr_result != strchr_result) {
				printf("Error: Result of ft_strchr does not match strchr for string: \"%s\"\n", test_str);
			}
		}
	}

	const char *test_strings[] = {
		"Hello, world!",
		"This is a test string.",
		"An empty string.",
		"",
		"12345",
		"Lorem ipsum dolor sit amet, consectetur adipiscing elit.",
		NULL // End of test strings marker
	};
	inner(test_strings, 'r');
    inner(test_strings, 't');
}

void test_strrchr()
{
	void inner(const char **test_strings, int c) {
		for (const char **ptr = test_strings; *ptr != NULL; ++ptr) {
			const char *test_str = *ptr;

			char *ft_strrchr_result = ft_strrchr(test_str, c);
			char *strrchr_result = strrchr(test_str, c);

			if (ft_strrchr_result != strrchr_result) {
				printf("Error: Result of ft_strrchr does not match strrchr for string: \"%s\"\n", test_str);
			}
		}
	}

	const char *test_strings[] = {
		"Hello, world!",
		"This is a test string.",
		"An empty string.",
		"",
		"12345",
		"Lorem ipsum dolor sit amet, consectetur adipiscing elit.",
		NULL // End of test strings marker
	};
	inner(test_strings, 'r');
    inner(test_strings, 't');
}

void test_strncmp()
{
	void inner(const char *s1, const char *s2, size_t n) {
		// Call ft_strncmp and strncmp to compare the strings s1 and s2 for the first n characters
		int ft_strncmp_result = ft_strncmp(s1, s2, n);
		int strncmp_result = strncmp(s1, s2, n);

		// Compare the result of ft_strncmp with strncmp
		if ((ft_strncmp_result > 0 && strncmp_result <= 0) 
			|| (ft_strncmp_result < 0 && strncmp_result >= 0) 
			|| (ft_strncmp_result == 0 && strncmp_result != 0)) {
			printf("Error: Result of ft_strncmp does not match strncmp for strings: \"%s\" and \"%s\" with length: %zu\n", s1, s2, n);
		}
	}

	const char *s1 = "Hello";
	const char *s2 = "Hello";
	const char *s3 = "World";
	const char *s4 = "Hello!";
	size_t n = 5;
	inner(s1, s2, n);
	inner(s1, s3, n);
	inner(s1, s3, 0);
	inner(s1, s4, n);
}

void test_memchr()
{
	void inner(const void *s, int c, size_t n) {
		void *ft_memchr_result = ft_memchr(s, c, n);
		void *memchr_result = memchr(s, c, n);

		if (ft_memchr_result != memchr_result) {
			printf("Error: Result of ft_memchr does not match memchr\n");
		}
	}

	const char *str_memcpy = "Hello, world!";
	size_t size = strlen(str_memcpy);
	for (size_t i = 0; i < size; i++)
        inner(str_memcpy + i, 'o', size + 1 - i);
}

void test_memcmp()
{
	void inner(const char *s1, const char *s2, size_t n) {
		int ft_memcmp_result = ft_memcmp(s1, s2, n);
		int memcmp_result = memcmp(s1, s2, n);

		if ((ft_memcmp_result > 0 && memcmp_result <= 0) 
			|| (ft_memcmp_result < 0 && memcmp_result >= 0) 
			|| (ft_memcmp_result == 0 && memcmp_result != 0)) {
			printf("Error: Result of ft_memcmp does not match memcmp for strings: \"%s\" and \"%s\" with length: %zu\n", s1, s2, n);
		}
	}

	const char *s1 = "Hello";
	const char *s2 = "Hello";
	const char *s3 = "World";
	const char *s4 = "Hello!";
	size_t n = 5;
	inner(s1, s2, n);
	inner(s1, s3, n);
	inner(s1, s3, 0);
	inner(s1, s4, n);
}

void test_strnstr()
{
	char *
	strnstr(const char *s, const char *find, size_t slen) // https://github.com/lattera/freebsd/blob/master/lib/libc/string/strnstr.c
	{
		char c, sc;
		size_t len;

		if ((c = *find++) != '\0') {
			len = strlen(find);
			do {
				do {
					if (slen-- < 1 || (sc = *s++) == '\0')
						return (NULL);
				} while (sc != c);
				if (len > slen)
					return (NULL);
			} while (strncmp(s, find, len) != 0);
			s--;
		}
		return ((char *)s);
	}

	void inner(const char *str, const char *sub, size_t len) {
		char *ft_strnstr_result = ft_strnstr(str, sub, len);
		char *strnstr_result = strnstr(str, sub, len);
		
		if ((ft_strnstr_result == NULL && strnstr_result != NULL) || (ft_strnstr_result != NULL && strnstr_result == NULL) ||
			(ft_strnstr_result != NULL && strnstr_result != NULL && ft_strnstr_result != strnstr_result)) {
			printf("Error: Result of ft_strnstr does not match strnstr for string: \"%s\", substring: \"%s\", and length: %zu\n", str, sub, len);
		}
	}

	const char *str = "This is a test string.";
	const char *sub1 = "is";
	const char *sub2 = "Hello";
	const char *sub3 = "string";
	const char *sub4 = "";
	inner(str, sub1, 15);
	inner(str, sub1, 6);
	inner(str, sub2, 15);
	inner(str, sub3, 15);
	inner(str, sub4, 15);
}

void test_atoi()
{
	const char *test_atoi_strings[] = {
		"1",
		"7",
		"10",
		"100000",
		"946189",
		"-1",
		"-7",
		"-10",
		"-100000",
		"-946189",
		"Lorem ipsum dolor sit amet, consectetur adipiscing elit.",
		"  +01ad",
		" \t\n\v\r\f -1",
		"asdasd -5",
		"++5",
		"--9",
		"- 9",
		"",
		NULL // End of test strings marker
	};
	int i = -1;
	while (test_atoi_strings[++i])
	{
		if (atoi(test_atoi_strings[i]) != ft_atoi(test_atoi_strings[i]))
			printf("Error in atoi(%s): %d vs %d\n", test_atoi_strings[i], atoi(test_atoi_strings[i]), ft_atoi(test_atoi_strings[i]));
	}
}

void	test_calloc(void)
{
	void *ptr1 = ft_calloc(0, 10);
	if (ptr1 == NULL)
	{
		printf("Error: calloc failed on test 1\n");
		free(ptr1);
	}

	void *ptr2 = ft_calloc(10, 0);
	if (ptr2 == NULL)
	{
		printf("Error: calloc failed on test 2\n");
		free(ptr2);
	}

	void *ptr3 = ft_calloc(4294967295, 2);
	if (ptr3 != NULL)
	{
		printf("Error: calloc failed on test 3\n");
		free(ptr3);
	}

	size_t nmemb = 5;
	size_t size = sizeof(int);
	int *ptr4 = ft_calloc(nmemb, size);
	if (ptr4 == NULL)
		printf("Error: calloc failed on test 4: failed memmory allocation\n");
	else
	{
		int all_zeros = 1;
		for (size_t i = 0; i < nmemb; ++i)
		{
			if (ptr4[i] != 0)
			{
				all_zeros = 0;
				break ;
			}
		}
		if (!all_zeros)
			printf("Error: calloc failed on test 4: values are not all 0\n");
		int *ptr5 = calloc(nmemb, size);
		if (memcmp(ptr4, ptr5, nmemb * size) != 0)
			printf("Error: calloc failed on test 4: result is differ from build-in func\n");
		free(ptr4);
		free(ptr5);
	}
}

void test_strdup()
{
	const char *test_strings[] = {
		"Hello, world!",
		"This is a test string.",
		"An empty string.",
		"",
		"12345",
		"Lorem ipsum dolor sit amet, consectetur adipiscing elit.",
		NULL // End of test strings marker
	};

	for (const char **ptr = test_strings; *ptr != NULL; ++ptr) {
        const char *test_str = *ptr;

        // Duplicate string using both functions
        char *ft_dup = ft_strdup(test_str);
        char *strdup_dup = strdup(test_str);

        // Check if the duplicated strings are NULL
        if (ft_dup == NULL || strdup_dup == NULL) {
            printf("Error: Memory allocation failed for string: \"%s\"\n", test_str);
        } else {
            // Compare the duplicated strings
            if (strcmp(ft_dup, strdup_dup) != 0) {
                printf("Error: Duplicated strings don't match for string: \"%s\"\n", test_str);
            }
        }

        // Free the duplicated strings
        free(ft_dup);
        free(strdup_dup);
    }
}

void test_substr()
{
    const char *str = "Hello, World!";
    void inner(char const* s, unsigned int start, size_t len, const char *ref)
    {
        char *res = ft_substr(s, start, len);
        if ((res == NULL && ref != NULL) || (res != NULL && ref == NULL) || !((res == NULL && ref == NULL) || memcmp(res, ref, strlen(ref) + 1) == 0))
            printf("Error: result of ft_substr doesn't fit to reference string: \"%s\" vs \"%s\"\n", ref, res);
    
        free(res);
    }
    inner(str, 0, 20, str);
    inner(str, 0, 13, str);
    inner(str, 0,  1, "H");
    inner(str, 0,  5, "Hello");
    inner(str, 7, 20, "World!");
    inner(str, 7,  5, "World");
    inner(str, 7,  0, "");
    inner(str, 20, 9, "");
}

void test_strjoin()
{
    void inner(char const *s1, char const *s2, const char *ref)
    {
        char *res = ft_strjoin(s1, s2);
        if ((res == NULL && ref != NULL) || (res != NULL && ref == NULL) || !((res == NULL && ref == NULL) || memcmp(res, ref, strlen(ref) + 1) == 0))
            printf("Error: result of ft_strjoin doesn't fit to reference string: \"%s\" vs \"%s\"\n", ref, res);
    
        free(res);
    }
    inner("Hello, ", "World!", "Hello, World!");
    // inner("Hello, ", NULL, NULL);
    // inner(NULL, "World!", NULL);
    inner("Hello, ", "", "Hello, ");
    inner("", "World!", "World!");
}

void test_strtrim()
{
    void inner(char const *s1, char const *set, const char *ref)
    {
        char *res = ft_strtrim(s1, set);
        if ((res == NULL && ref != NULL) || (res != NULL && ref == NULL) || !((res == NULL && ref == NULL) || memcmp(res, ref, strlen(ref) + 1) == 0))
            printf("Error: result of ft_strtrim doesn't fit to reference string: \"%s\" vs \"%s\"\n", ref, res);
        free(res);
    }
    // inner(NULL, "", NULL);
    // inner("", NULL, NULL);
    inner("123456789", "", "123456789");
    inner("123456789", "a", "123456789");
    inner("123456789", "1", "23456789");
    inner("123456789", "2", "123456789");
    inner("", "a", "");
    inner("", "", "");
    inner("!!@!!qwerty!!@!!", "!", "@!!qwerty!!@");
    inner("!!@!!qwerty!!@!!", "!@", "qwerty");
    inner("!!@!!qwerty!!@!!", "@!", "qwerty");
    inner("!!@!!qwerty", "@!", "qwerty");
    inner("qwerty!!@!!", "@!", "qwerty");
}

void test_split()
{
    void inner(char const *s, char c, char **expected_result)
    {
        char **result = ft_split(s, c);
        if ((!result && expected_result) || (result && !expected_result))
            printf("Error: result of ft_split doesn't fit to reference string: one of them is NULL and another not\n");
        else if (result && expected_result)
        {
            int i = 0;
            while (result[i] != NULL)
            {
                if (!expected_result[i] || strcmp(result[i], expected_result[i]) != 0)
                    printf("Error: result of ft_split doesn't fit to reference string: \"%s\" vs \"%s\"\n", expected_result[i], result[i]);
            
                 i++;
            }
            if (result[i] != NULL || expected_result[i] != NULL)
                printf("Error: result of ft_split doesn't fit to reference: diff length \n");
        }

        if (result != NULL)
        {
            for (int i = 0; result[i] != NULL; i++)
                free(result[i]);
            free(result);
        }
    }
    char *expected1[] = {"hello", "world", NULL};
    inner("hello,world", ',', expected1);

    char *expected2[] = {"apple", "banana", "cherry", NULL};
    inner("apple banana cherry", ' ', expected2);

    char *expected3[] = {"a", "b", "c", "d", NULL};
    inner("a b c d", ' ', expected3);

    char *expected4[] = {"one", "two", "three", NULL};
    inner("  one   two three   ", ' ', expected4);

    char *expected5[] = {"one", "two", "three", "four", NULL};
    inner(";one;two;three;four", ';', expected5);
}

void test_itoa()
{
    char ref[20];
    char *res;
    
    for (int i = -10000; i <= 10000; i++)
    {
        sprintf(ref, "%d", i);
        res = ft_itoa(i);
        if ((res == NULL && ref != NULL) || (res != NULL && ref == NULL) || !((res == NULL && ref == NULL) || strcmp(res, ref) == 0))
            printf("Error: result of ft_itoa doesn't fit to reference string: \"%s\" vs \"%s\"\n", ref, res);
        free(res);
    }
    
    sprintf(ref, "%d", 2147483647);
    res = ft_itoa(2147483647);
    if ((res == NULL && ref != NULL) || (res != NULL && ref == NULL) || !((res == NULL && ref == NULL) || strcmp(res, ref) == 0))
        printf("Error: result of ft_itoa doesn't fit to reference string: \"%s\" vs \"%s\"\n", ref, res);
    free(res);
    
    sprintf(ref, "%d", (int)-2147483648);
    res = ft_itoa(-2147483648);
    if ((res == NULL && ref != NULL) || (res != NULL && ref == NULL) || !((res == NULL && ref == NULL) || strcmp(res, ref) == 0))
        printf("Error: result of ft_itoa doesn't fit to reference string: \"%s\" vs \"%s\"\n", ref, res);
    free(res);
    
}

void test_strmapi()
{
    char up_and_down(unsigned int i, char c)
    {
        if (i % 2)
            return (ft_tolower(c));
        return (ft_toupper(c));
    }
    char down_and_up(unsigned int i, char c)
    {
        if (!(i % 2))
            return (ft_tolower(c));
        return (ft_toupper(c));
    }
    char *str = "Hello, World!";
    char *res;
    
    char *ref1 = "HeLlO, wOrLd!";
    res = ft_strmapi(str, &up_and_down);
    if ((res == NULL && ref1 != NULL) || (res != NULL && ref1 == NULL) || !((res == NULL && ref1 == NULL) || strcmp(res, ref1) == 0))
        printf("Error: result of ft_itoa doesn't fit to reference string: \"%s\" vs \"%s\"\n", ref1, res);
    free(res);
    
    char *ref2 = "hElLo, WoRlD!";
    res = ft_strmapi(str, &down_and_up);
    if ((res == NULL && ref2 != NULL) || (res != NULL && ref2 == NULL) || !((res == NULL && ref2 == NULL) || strcmp(res, ref2) == 0))
        printf("Error: result of ft_itoa doesn't fit to reference string: \"%s\" vs \"%s\"\n", ref2, res);
    free(res);
}

void test_striteri()
{
    void suppor(unsigned int i, char *c)
    {
        if (*c == 'l')
            *c = 'L';
        if (i == 6)
            *c = '6';
    }
    char str[] = "Hello, World!";
    ft_striteri(str, &suppor);
    char *ref = "HeLLo,6WorLd!";
    if ((str == NULL && ref != NULL) || (str != NULL && ref == NULL) || !((str == NULL && ref == NULL) || strcmp(str, ref) == 0))
        printf("Error: result of ft_itoa doesn't fit to reference string: \"%s\" vs \"%s\"\n", ref, str);
}

void test_putchar_fd()
{
    write(0, "Should be same: \'m\' vs \'", 25);
    ft_putchar_fd('m', 0);
    write(0, "\'\n", 2);
}

void test_putstr_fd()
{
    write(0, "Should be same: \"Hello, World!\" vs \"", 37);
    ft_putstr_fd("Hello, World!", 0);
    write(0, "\"\n", 2);
}

void test_putendl_fd()
{
    write(0, "Test ft_putendl_fd:\n", 20);
    ft_putendl_fd("Fist line", 0);
    ft_putendl_fd("Last line", 0);
}

void test_putnbr_fd()
{
    write(0, "Test ft_putnbr_fd:\n", 19);
    ft_putnbr_fd(-2147483648, 0);
    ft_putendl_fd("", 0);
    ft_putnbr_fd(0, 0);
    ft_putendl_fd("", 0);
    ft_putnbr_fd(-7, 0);
    ft_putendl_fd("", 0);
    ft_putnbr_fd(100000, 0);
    ft_putendl_fd("", 0);
    ft_putnbr_fd(2147483647, 0);
    ft_putendl_fd("", 0);
}

void test_lstnew() {
    t_list *list = ft_lstnew("test");
    assert(list != NULL);
    assert(list->content != NULL);
    assert(list->next == NULL);
    assert(strcmp(list->content, "test") == 0);
    free(list);
}

void test_lstlast() {
    void do_nothing(void *content) { (void)content;}
    t_list *list = ft_lstnew("first");
    ft_lstadd_back(&list, ft_lstnew("second"));
    ft_lstadd_back(&list, ft_lstnew("third"));
    t_list *last = ft_lstlast(list);
    assert(last != NULL);
    assert(strcmp(last->content, "third") == 0);
    ft_lstclear(&list, &do_nothing);
}

void test_lstadd_back() {
    void do_nothing(void *content) {(void)content;}
    t_list *list = NULL;
    ft_lstadd_back(&list, ft_lstnew("first"));
    ft_lstadd_back(&list, ft_lstnew("second"));
    assert(list->next != NULL);
    assert(strcmp(list->content, "first") == 0);
    assert(strcmp(list->next->content, "second") == 0);
    ft_lstclear(&list, &do_nothing);
}

void test_lstadd_front() {
    void do_nothing(void *content) {(void)content;}
    t_list *list = ft_lstnew("first");
    ft_lstadd_front(&list, ft_lstnew("second"));
    assert(list != NULL);
    assert(strcmp(list->content, "second") == 0);
    assert(strcmp(list->next->content, "first") == 0);
    ft_lstclear(&list, &do_nothing);
}

void test_lstsize() {
    void do_nothing(void *content) {(void)content;}
    t_list *list = ft_lstnew("first");
    ft_lstadd_back(&list, ft_lstnew("second"));
    ft_lstadd_back(&list, ft_lstnew("third"));
    assert(ft_lstsize(list) == 3);
    ft_lstclear(&list, &do_nothing);
}

void test_lstdelone() {
    t_list *list = ft_lstnew(ft_strdup("first"));
    ft_lstdelone(list, &free);
    // should be no memory leakage! valgrind
}

void test_lstclear() {
    t_list *list = ft_lstnew(ft_strdup("first"));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("second")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("third")));
    ft_lstclear(&list, &free);
    // should be no memory leakage! valgrind
}

void test_lstiter() {
    void print_content(void *content)
    {
        ft_putendl_fd(content, 0);
    }
    t_list *list = ft_lstnew("first");
    ft_lstadd_back(&list, ft_lstnew("second"));
    ft_lstiter(list, &print_content);
    free(list);
}

void test_lstmap() {
    void *double_content(void *content) {
        int *val = (int *)content;
        int *result = (int *)malloc(sizeof(int));
        *result = (*val) * 2;
        return result;
    }

    t_list *list = ft_lstnew(malloc(sizeof(int)));
    *(int *)(list->content) = 5;
    ft_lstadd_back(&list, ft_lstnew(malloc(sizeof(int))));
    *(int *)(ft_lstlast(list)->content) = 6;
    ft_lstadd_back(&list, ft_lstnew(malloc(sizeof(int))));
    *(int *)(ft_lstlast(list)->content) = 7;
    t_list *mapped = ft_lstmap(list, &double_content, &free);
    assert(list != NULL);
    assert(*(int *)(list->content) == 5);
    assert(*(int *)(list->next->content) == 6);
    assert(*(int *)(list->next->next->content) == 7);
    assert((list->next->next->next) == NULL);
    assert(mapped != NULL);
    assert(*(int *)(mapped->content) == 10);
    assert(*(int *)(mapped->next->content) == 12);
    assert(*(int *)(mapped->next->next->content) == 14);
    assert((mapped->next->next->next) == NULL);
    ft_lstclear(&list, &free);
    ft_lstclear(&mapped, &free);
}

int	main(void)
{
	test_is_funcs();
	test_strlen();
	test_memset();
    test_bzero();
    test_memcpy();
	test_strlcpy();
	test_strlcat();
	test_strchr();
	test_strrchr();
	test_strncmp();
	test_memchr();
	test_memcmp();
	test_strnstr();
	test_atoi();
	test_calloc();
	test_strdup();
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	test_itoa();
	test_strmapi();
	test_striteri();
	test_putchar_fd();
	test_putstr_fd();
	test_putendl_fd();
	test_putnbr_fd();
    test_lstnew();
    test_lstlast();
    test_lstadd_back();
    test_lstadd_front();
    test_lstsize();
    test_lstdelone();
    test_lstclear();
    test_lstiter(); // prints strings
    test_lstmap();
	printf("END\n");
}
