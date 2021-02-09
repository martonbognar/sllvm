#include "sharevalue.h"

#define SPECIAL_SHARE 42

static int lookupVal(int id)
{
  return 7;
}

int sharevalue_enter(__attribute__((secret)) int ids[], int qty[], int len)
{
  int shareVal = 0;
  int i = 0;

  while (i < len) 
  {
    int id = ids[i];
    int val = lookupVal(id) * qty[i];

    int condition = (id == SPECIAL_SHARE);
    int tmask = -condition;
    int sum = shareVal + val;

    shareVal  = (sum & tmask);
    shareVal |= (shareVal & ~tmask);

    i++;
  }

  return shareVal;
}

// The following functions should be generated by the SLLVM but this feature
// is not supported yet.
#if 1
__attribute__((noinline, used))
static void _nds___mspabi_mpyi(int a, int b) { asm("nop"); }
__attribute__((noinline, used))
static void _ndd___mspabi_mpyi(int a, int b) { asm("nop"); }
#endif
