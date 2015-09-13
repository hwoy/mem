#include "linklist.h"

#define MEM_VERSION_MAJOR 1
#define MEM_VERSION_MINOR 0
#define MEM_VERSION_SUBMINOR 0

typedef assem memman;
typedef linklist memlist;

static const char MEM_VERSION_STR[] = "1.0.0";

memman *mm_init (memman * mm);

void *mm_malloc (memman * mm, unsigned int size);

void mm_freeall (memman * mm);

int mm_free (memman * mm, void *sptr);
