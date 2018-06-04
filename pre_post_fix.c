#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "fix.h"

Fix_S *prefix_postfix_max(const char *s) {
    if (NULL == s || 0 == s[0]) {
        return NULL;
    }


    int i;
    int *value;
    size_t len = strlen(s);
    size_t size = len * sizeof(int) + sizeof(Fix_S);
    Fix_S *f = (Fix_S *)malloc(size);
    if (NULL == f) {
        return f;
    }

    memset(f, 0, size);
    
    f->size = len;
    f->value = (int *)(((char *)f) + sizeof(Fix_S));
    value = f->value;

    for (i = 1; i < len; i++) {
        if (s[i] == s[value[i - 1]]) {
            value[i] = value[i - 1] + 1;
        }
    }

    return f;
}

Fix_S *prefix_postfix_max_sub(const char *s) {
    if (NULL == s || 0 == s[0]) {
        return NULL;
    }


    int i;
    int *value;
    size_t len = strlen(s);
    size_t size = (len + 1) * sizeof(int) + sizeof(Fix_S);
    Fix_S *f = (Fix_S *)malloc(size);
    if (NULL == f) {
        return f;
    }

    memset(f, 0, size);
    
    f->size = len + 1;
    f->value = (int *)(((char *)f) + sizeof(Fix_S));
    value = f->value;

    for (i = 1; i < len; i++) {
        if (s[i] == s[value[i]]) {
            value[i + 1] = value[i] + 1;
        }
    }

    return f;
}

static void print_fix(int size, int *f) {
    while (size) {
        if (size > 1) {
            printf("%d, ", *f);
        }
        else {
            printf("%d\n", *f);
        }
        f++;
        size--;
    }
}

int kmp_first(const char *src, const char *target) {
    int i, j;
    int index = -1;
    size_t targetLen = strlen(target);
    size_t srcLen = strlen(src);
    Fix_S *f = prefix_postfix_max_sub(target);

    if (NULL == f) {
        return index;
    }

    for (i = 0, j = 0; i < srcLen;) {
        if (src[i] != target[j]) {
            if (0 == j) {
                i++;
            }
            j = f->value[j];
        }
        else { 
            if (j == targetLen - 1) {
                index = i - j ;
                break;
            }
            else {
                j++;
                i++;
            }
        }
    }

    free(f);
    return index;
}
