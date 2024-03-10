/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 20:54:08 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/10 20:50:58 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdint.h>
//#include <stdbool.h>
/*
DESCRIPTION
       The  malloc()  function allocates size bytes and returns a
       pointer to the allocated memory.  The memory is  not  ini‐
       tialized.   If  size  is  0,  then malloc() returns either
       NULL, or a unique pointer value that can later be success‐
       fully passed to free().

       The  free()  function frees the memory space pointed to by
       ptr, which must have been returned by a previous  call  to
       malloc(),   calloc(),  or  realloc().   Otherwise,  or  if
       free(ptr) has already been called before, undefined behav‐
       ior occurs.  If ptr is NULL, no operation is performed.

       The  calloc()  function  allocates  memory for an array of
       nmemb elements of size bytes each and returns a pointer to
       the  allocated  memory.   The  memory  is set to zero.  If
       nmemb or size is 0, then calloc() returns either NULL,  or
       a  unique  pointer  value  that  can later be successfully
       passed to free().  If the multiplication of nmemb and size
       would result in integer overflow, then calloc() returns an
       error.  By contrast, an integer overflow would not be  de‐
       tected  in the following call to malloc(), with the result
       that an incorrectly sized block of memory would  be  allo‐
       cated:
	    malloc(nmemb * size);

       The  realloc()  function  changes  the  size of the memory
       block pointed to by ptr to size bytes.  The contents  will
       be  unchanged in the range from the start of the region up
       to the minimum of the old and new sizes.  If the new  size
       is  larger than the old size, the added memory will not be
       initialized.  If ptr is NULL, then the call is  equivalent
       to  malloc(size), for all values of size; if size is equal
       to zero, and ptr is not NULL, then the call is  equivalent
       to  free(ptr).   Unless ptr is NULL, it must have been re‐
       turned by an earlier call to malloc(), calloc(), or  real‐
       loc().   If  the area pointed to was moved, a free(ptr) is
       done.

       The reallocarray() function changes the size of the memory
       block pointed to by ptr to be large enough for an array of
       nmemb elements, each of which is size bytes.  It is equiv‐
       alent to the call

               realloc(ptr, nmemb * size);

       However,  unlike that realloc() call, reallocarray() fails
       safely in the case where the  multiplication  would  over‐
       flow.   If such an overflow occurs, reallocarray() returns
       NULL, sets errno to ENOMEM, and leaves the original  block
       of memory unchanged.

RETURN VALUEimnt,ax oim
       The  malloc()  and  calloc() functions return a pointer to
       the allocated memory, which is suitably  aligned  for  any
       built-in  type.   On  error,  these functions return NULL.
       NULL may also be returned by a successful call to malloc()
       with  a  size of zero, or by a successful call to calloc()
       with nmemb or size equal to zero.
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if (nmemb > 2147483647 / size)
		return (NULL);
	ret = malloc(nmemb * size);
	if (!ret)
		return (NULL);
	ft_bzero(ret, nmemb * size);
	return (ret);
}
/*
int main() {
    bool pass = true; // Flag to track overall test pass/fail

    // Test case 1: Allocating memory for an array of 5 integers
    int *arr1 = (int *)ft_calloc(5, sizeof(int));
    if (arr1 == NULL) {
        printf("Test case 1 failed: Memory allocation failed\n");
        pass = false;
    } else {
        printf("Test case 1 passed: Memory allocation successful\n");
        free(arr1);
    }

    // Test case 2: Allocating memory for an array of 0 elements
    int *arr2 = (int *)fintmax in c syntax;
        pass = false;
    } else {
    printf("Test case 2 passed:
	Memory allocation failed as expected for 0 elements\n");
    }

    // Test case 3: Allocating memory with potential overflow
    size_t max_elements = SIZE_MAX / sizeof(int);
    int *arr3 = 
	(int *)ft_calloc(max_elements + 1, sizeof(int)); 
	// Trying to allocate more than SIZE_MAX bytes
    if (arr3 != NULL) {
    printf("Test case 3 failed: Memory allocation succeeded but
			 should have failed due to potential overflow\n");
        free(arr3);
        pass = false;
    } else {
        printf("Test case 3 passed: 
		Memory allocation failed as expected due to potential overflow\n");
    }

    if (pass) {
        printf("All test cases passed!\n");
    } else {
        printf("Some test cases failed!\n");
    }

    return pass ? 0 : 1;
}*/
