

void *mm_init (unsigned int nblock);

void *mm_malloc (unsigned int size);

void mm_freeall (void);

void mm_freesys (void);

unsigned int mm_getsetup (void);

void mm_free (void *sptr);

void mm_freeinit (void);
