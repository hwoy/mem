#include <stdlib.h>
#include "linklist.h"
#include "mem.h"


memman *
mm_init (memman * mm)
{

  return l2_init (mm, 0);
}

void *
mm_malloc (memman * mm, unsigned int size)
{
  return (l2_add (mm, l2_new ())->ptr = malloc (size));
}

void
mm_freeall (memman * mm)
{
  memlist *tmp;

  mm->current = mm->begin;
  while (mm->current)
    {
      tmp = mm->current;
      mm->current = mm->current->forw;

      free (tmp->ptr);
      free (tmp);
    }
  mm->begin = (memlist *) 0;
  mm->end = (memlist *) 0;
  mm->current = (memlist *) 0;
}



int
mm_free (memman * mm, void *sptr)
{
  memlist *tmp2;
  tmp2 = mm->current;
  for (mm->current = mm->begin; mm->current; mm->current = mm->current->forw)
    {
      if (mm->current->ptr == sptr)
	{
	  l2_delete (mm, mm->current->id);
	  free (sptr);
	  return 1;
	}
    }

  mm->current = tmp2;
  return 0;
}
