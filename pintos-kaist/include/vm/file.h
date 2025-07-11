#include "vm/vm.h"
#include "filesys/file.h"
#include "threads/malloc.h"
#ifndef VM_FILE_H
#define VM_FILE_H

struct page;
enum vm_type;

struct file_page {
	struct aux *aux;
    bool modified;    
};

void vm_file_init (void);
bool file_backed_initializer (struct page *page, enum vm_type type, void *kva);
void *do_mmap(void *addr, size_t length, int writable,
		struct file *file, off_t offset);
void do_munmap (void *va);
void file_backed_destroy (struct page *page);
#endif
