#include <stdlib.h>
#include "linklist.h"


#define VERSION_MAJOR 1
#define VERSION_MINOR 0
#define VERSION_SUBMINOR 0



linklist *
l2_new (void)
{
  return (malloc (sizeof (linklist)));
}


void
l2_getversion (unsigned int *major, unsigned int *minor,
	       unsigned int *subminor)
{
  *major = VERSION_MAJOR;
  *minor = VERSION_MINOR;
  *subminor = VERSION_SUBMINOR;
}


assem *
l2_init (assem * asmb, unsigned int id)
{
  asmb->begin = asmb->end = asmb->current = (linklist *) 0;
  asmb->id = id;
  return asmb;
}

linklist *
l2_add (assem * asmb, linklist * lst)
{
  lst->prev = lst->forw = (linklist *) 0;
  if (!asmb->begin)
    {
      asmb->begin = lst;
      asmb->end = lst;
      lst->id = 0;
    }
  else
    {
      asmb->end->forw = lst;
      lst->prev = asmb->end;
      asmb->end = lst;
      lst->id = lst->prev->id + 1;
    }
  return lst;
}


void
l2_freeall (assem * asmb)
{
  linklist *tmp;
  asmb->current = asmb->begin;
  while (asmb->current)
    {

      tmp = asmb->current;
      asmb->current = asmb->current->forw;
      free (tmp);
    }
  asmb->begin = asmb->end = asmb->current = (linklist *) 0;
}

unsigned int
l2_numelement (assem * asmb)
{
  return (asmb->end->id + 1);
}

linklist *
l2_findbyid (assem * asmb, unsigned int id)
{
  linklist *tmp2;
  tmp2 = asmb->current;
  asmb->current = asmb->begin;
  while (asmb->current)
    {
      if (id == asmb->current->id)
	{
	  return (asmb->current);
	}
      asmb->current = asmb->current->forw;
    }
  asmb->current = tmp2;
  return (0);
}

int
l2_replace (assem * asmb, linklist * lst, unsigned int id)
{
  linklist *tmp;
  if (!(tmp = l2_findbyid (asmb, id)))
    {
      return (0);
    }
  if (asmb->begin == asmb->end)
    {
      asmb->begin = asmb->end = (linklist *) 0;
      l2_add (asmb, lst);
    }
  else if (tmp == asmb->begin)
    {
      tmp->forw->prev = lst;
      lst->prev = tmp->prev;
      lst->forw = tmp->forw;
      asmb->begin = lst;
    }
  else if (tmp == asmb->end)
    {
      tmp->prev->forw = lst;
      lst->prev = tmp->prev;
      lst->forw = tmp->forw;
      asmb->end = lst;
    }
  else
    {
      tmp->prev->forw = lst;
      tmp->forw->prev = lst;
      lst->prev = tmp->prev;
      lst->forw = tmp->forw;
    }
  lst->id = tmp->id;
  free (tmp);
  return (1);
}

int
l2_delete (assem * asmb, unsigned int id)
{
  linklist *tmp;
  linklist *tmp2;
  tmp2 = asmb->current;
  if (!(tmp = l2_findbyid (asmb, id)))
    {
      return (0);
    }
  else if (asmb->begin == asmb->end)
    {
      asmb->begin = asmb->end = (linklist *) 0;
    }
  else if (tmp == asmb->begin)
    {
      tmp->forw->prev = tmp->prev;
      asmb->begin = tmp->forw;
    }
  else if (tmp == asmb->end)
    {
      tmp->prev->forw = tmp->forw;
      asmb->end = tmp->prev;
    }
  else
    {
      tmp->prev->forw = tmp->forw;
      tmp->forw->prev = tmp->prev;
    }
  asmb->current = tmp->forw;
  while (asmb->current)
    {
      asmb->current->id--;
      asmb->current = asmb->current->forw;
    }
  free (tmp);

  asmb->current = tmp2;
  return (1);
}

int
l2_insert (assem * asmb, linklist * lst, unsigned int id)
{
  linklist *tmp;
  linklist *tmp2;
  tmp2 = asmb->current;
  if (!(tmp = l2_findbyid (asmb, id)))
    {
      return (0);
    }
  if ((asmb->begin == asmb->end) || (tmp == asmb->end))
    {
      l2_add (asmb, lst);
      return (1);
    }
  else
    {
      lst->prev = tmp;
      lst->forw = tmp->forw;

      tmp->forw->prev = lst;
      tmp->forw = lst;

    }

  asmb->current = lst;
  while (asmb->current)
    {
      asmb->current->id = asmb->current->prev->id + 1;
      asmb->current = asmb->current->forw;
    }

  asmb->current = tmp2;
  return (1);
}
