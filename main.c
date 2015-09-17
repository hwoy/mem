#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linklist.h"
#include "mem.h"
#define BSIZE 32

const char *str[] = { "Hello", "My,Name", "is", "Hwoy", NULL };

int
main (void)
{
  unsigned int i;
  memman *mm;
  mm = mm_init (malloc (sizeof (memman)));
  for (i = 0; str[i]; i++)
    {
      strcpy (mm_malloc (mm, BSIZE), str[i]);

    }

  for (mm->current = mm->begin; mm->current; mm->current = mm->current->forw)
    {

      puts (mm->current->ptr);

    }

  mm_freeall (mm);
  free (mm);

  return 0;
}
