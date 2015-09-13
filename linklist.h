
typedef struct _linklist
{
  struct _linklist *prev;
  struct _linklist *forw;
  unsigned int id;

  void *ptr;
} linklist;

typedef struct
{
  linklist *begin;
  linklist *end;
  linklist *current;

  unsigned int id;
} assem;




linklist *l2_new (void);
void l2_getversion (unsigned int *major, unsigned int *minor,
		    unsigned int *subminor);
assem *l2_init (assem * asmb, unsigned int id);

linklist *l2_add (assem * asmb, linklist * lst);


void l2_freeall (assem * asmb);

unsigned int l2_numelement (assem * asmb);

linklist *l2_findbyid (assem * asmb, unsigned int id);

int l2_replace (assem * asmb, linklist * lst, unsigned int id);

int l2_delete (assem * asmb, unsigned int id);

int l2_insert (assem * asmb, linklist * lst, unsigned int id);
