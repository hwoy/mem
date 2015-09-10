#define MEM_VERSION_MAJOR 1
#define MEM_VERSION_MINOR 0
#define MEM_VERSION_SUBMINOR 1

static const char MEM_VERSION_STR[]="1.0.0";

void *mm_init (unsigned int nblock);

void *mm_malloc (unsigned int size);

void mm_freeall (void);

void mm_freesys (void);

unsigned int mm_getsetup (void);

void mm_free (void *sptr);

void mm_freeinit (void);
