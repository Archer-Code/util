
typedef struct Fix_S {
    int *value;
    int size;
}Fix_S;


Fix_S *prifix_postfix_max(char *s);

Fix_S *prifix_postfix_max_sub(char *s);

int kmp_first(const char *src, const char *target);
