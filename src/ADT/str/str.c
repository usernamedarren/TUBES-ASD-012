#include "str.h"

int strcmp(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] && (str1[i] == str2[i])) {
        i++;
    }
    return (unsigned char)str1[i] - (unsigned char)str2[i];
}

void strcopy(char *dest, const char *src) {
    int i = 0;
    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}


int strlength(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void strconcat(char *dest, const char *src) {
    int i = strlength(dest); 
    int j = 0;
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
}

int strcontains(const char *str1, const char *str2) {
    int i = 0;
    int j = 0;
    while (str1[i]) {
        if (str1[i] == str2[j]) {
            while (str1[i + j] && str2[j] && str1[i + j] == str2[j]) {
                j++;
            }
            if (!str2[j]) {
                return 1;
            }
        }
        i++;
    }
    return 0;
}
