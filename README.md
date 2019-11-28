# ITFS's Libraries

>C
```
// clib
int get_string(char *alloc_str_length_1);
char* get_time(void);
void print_bin_8byte(const unsigned long long num, const int size_t);
void print_bin_4byte(const unsigned int num, const int size_t);
void print_bin(const unsigned long long num, const int size_t, const unsigned int size_group, const bool non_segmentation);
void insert_str(char *string_1, char *string_2, char ch);
int dec_com(int array_dec_3_3);
bool is_prime_num(long long int num);
bool is_letter(char ch);
bool is_num(char ch);
double *hash(const char *name, const double *base, int size, const char *hash_seed);
```
```
// sorters
int bubble_sorter(int *array, int length, bool (*comp)(int, int));
void selection_sorter(int *array, int length, bool (*comp)(int, int));
int insertion_sorter(int *array, int length, bool (*comp)(int, int));
```