#include <stdlib.h>
#include "mem.h"

static void **ptr;
static int block, allocblock, setup = 0;

void *
mm_init (unsigned int nblock)
{
  if (setup)
    {
      mm_freesys ();
    }
  if ((ptr = malloc (sizeof (void *) * nblock)) != NULL)
    {
      setup = 1;
      allocblock = 0;
      block = nblock;
    }
  return ptr;
}

void *
mm_malloc (unsigned int size)
{
  unsigned int i;
  if (setup && (allocblock < block))
    {
      *(ptr + allocblock) = (void *) malloc (size);
      i = allocblock;
      if (*(ptr + allocblock) != NULL)
	allocblock++;
      return *(ptr + i);
    }
  return NULL;
}

void
mm_freeall (void)
{
  unsigned int i;
  for (i = 0; i < allocblock; i++)
    {
      free (*(ptr + i));
    }
  allocblock = 0;
}

void
mm_freesys (void)
{
  mm_freeall ();
  mm_freeinit ();
}

unsigned int
mm_getsetup (void)
{
  return setup;
}

void
mm_free (void *sptr)
{
  unsigned int i, flag;
  flag = 0;
  if (allocblock)
    {
      for (i = 0; i < allocblock; i++)
	{
	  if (*(ptr + i) == sptr)
	    {
	      free (sptr);
	      flag = 1;
	      break;
	    }
	}

      for (i++; i < allocblock; i++)
	{
	  *(ptr + i - 1) = *(ptr + i);
	}
      if (flag)
	allocblock--;
    }

}

void
mm_freeinit (void)
{
  if (setup)
    {
      free (ptr);
      block = 0;
      setup = 0;
      allocblock = 0;
    }

}
