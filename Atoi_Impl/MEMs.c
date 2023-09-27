/*********************************
 * Author: Yohai Azoulai            
 * ******************************/

#include <stdio.h>
#include <stddef.h>
#include <string.h>

size_t MaskMaker(char a);
void *MemSet(void *str, int c, size_t n);
void *MemCpy(void *dest,const void *src, size_t n);
void *ReverseMemCpy(void *dest, void *src, size_t n);
void *MemMove(void *dest, const void *src, size_t n);

void *MemSet(void *str, int c, size_t n)
{
    char *str_tmp = str;
    char tmp = c;
    size_t mask = MaskMaker(tmp);
    while (0 != (long)str_tmp%8 && n > 0)
    {
        *str_tmp = tmp;
        str_tmp += 1;
        n -= 1;
    }

    while (n >= 8)
    {
        *(size_t *)str_tmp = mask;
        str_tmp += 8;
        n -= 8;
    }
    
    
    while (n > 0)
    {
        *str_tmp = tmp;
        str_tmp += 1;
        n -= 1;
    }
    
    return str;
}

size_t MaskMaker(char to_mask)
{
    int i = 0;
    size_t mask = 0;
    for(i = 0; i < 8; i++)
    {
        mask <<= 8;
        mask |= to_mask;
    }
    return mask;
}

void *MemCpy(void *dest,const void *src, size_t n)
{
    char *ptr_strt = dest, *ptr_end = (void *)src;
    while(0 != (long)ptr_end%8 && 0 < n)

    {
        *ptr_strt = *ptr_end; 
        ++ptr_strt;
        ++ptr_end;
        --n;
    }
    while(n >= 8)
    {
        *(size_t *)ptr_strt = *(size_t *)ptr_end;
        ptr_strt += 8;
        ptr_end += 8;
        n -= 8;
    }
    while(n > 0)
    {
        *ptr_strt = *ptr_end;
        ++ptr_strt;
        ++ptr_end;
        --n;
    }
    return dest;
}

void *ReverseMemCpy(void *dest, void *src, size_t n)
{
    char *ptr_strt = (char *)dest + n, *ptr_end = (char *)src + n;
    
    printf("CR:reverse\n");
    while(0 != (long)ptr_end%8 && n > 0)
    {
        --ptr_strt;
        --ptr_end;
        *ptr_strt = *ptr_end;
        --n;
    }
    while(n >= 8) 
    {
        ptr_strt -= 8;
        ptr_end -= 8;
        *(size_t *)ptr_strt = *(size_t *)ptr_end;
        n -= 8;
    }
    while(n > 0)
    {
        --ptr_strt;
        --ptr_end;
        *ptr_strt = *ptr_end;
        --n;
    }
    
    return dest;
}

void *MemMove(void *dest, const void *src, size_t n)
{
    return(0 < ((char *)dest - (char *)src)? ReverseMemCpy(dest,(void *)src,n): MemCpy(dest,(void *)src,n));
}

int main()
{
    int letter = 21;
    char arry[]= "Zlatan Ibrahimovitch";
    char arry2[] = "KlavLav Ho BidiBamBam";
    char arry3[] = "Marsellous Wallace";
    char arry4[] = "Oxygen Azoulai";
    char arry5[] = "Oxygen Azoulai";
    char arry6[] = "Oxygen Azoulai";
    char arry7[] = "Oxygen Azoulai";
    char arr1[100] = {0};
    char arr2[100] = {0};
    

    MemSet(arry,letter,9);
    printf("%s\n",arry);
    
    MemCpy(arr1,arry2,12);
    printf("%s\n",arr1);
    
    ReverseMemCpy(arr2,arry3,18);
    printf("%s\n",arr2);

    MemMove(arry4,arry4+4,2);
    printf("This is the My func result - %s\n",arry4);

    memmove(arry5,arry5+4,2);
    printf("This is the OG func result - %s\n",arry5);

    MemMove(arry6+2,arry6,3);
    printf("This is the My func result - %s\n",arry6);

    memmove(arry7+2,arry7,3);
    printf("This is the OG func result - %s\n",arry7);

    return 0;
}
