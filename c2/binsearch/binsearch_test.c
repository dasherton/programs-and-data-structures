#include "binsearch.h"
#include "mintest.h"

#include <stdio.h>

int tests_run = 0;

char *test_element_present()
{
  int a[] = {3, 4, 6, 8, 10};
  mu_assert("Element found when present in array",
    binsearch(6, a, sizeof(a)/sizeof(int)) == 2);
  return 0;
}

char *test_belongs_at_start()
{
  int a[] = {3, 4, 6, 8, 10};
  mu_assert("Element belongs at start of array",
    binsearch(1, a, sizeof(a)/sizeof(int)) == 0);
  return 0;
}

char *test_belongs_at_end()
{
  int a[] = {3, 4, 6, 8, 10};
  mu_assert("Element belongs at end of array",
    binsearch(100, a, sizeof(a)/sizeof(int)) == 5);
  return 0;
}

char *all_tests()
{
  mu_run_test(test_element_present);
  mu_run_test(test_belongs_at_start);
  mu_run_test(test_belongs_at_end);
  return 0;
}

int main()
{
    char *test_result = all_tests();

    if (test_result)
      printf("Error. Test failed. Msg: %s\n", test_result);
    else
      printf("All tests passed: %d\n", tests_run);
   
    return 0;
}
