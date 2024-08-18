#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char* buff = NULL;

void print_binary(char ch, char* binary_ptr) {
    int i;
    for (i = 0; i < 8; i++)
    {
        binary_ptr[i] = 0x30 + ((ch >> (7 - i)) & 1);    //从高位开始进行转换，对于部分文件可能涉及大小端问题，请注意甄别
    }
    binary_ptr[8] = 0;
}

int main(void)
{
    char binary[9];
    FILE* fp = NULL;

    if ((fp = fopen("omnissiah_string.txt", "r")) == NULL)
    {
        printf("the omnissiah_string.txt is not found.\n");
        printf("IMMORTAL OMNISSIAH is not happy.\n");
        printf("please check the file.\n");
        
        return -1;
    }
    
    fseek(fp, 0, SEEK_END);
    long length = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    buff = (char*)malloc(length + 1);
    memset(buff, 0, length + 1);
    fread(buff, 1, length, fp);
    fclose(fp);

    
    if ((fp = fopen("omnissiah_binary.txt", "wt+")) == NULL)
    {
        printf("the omnissiah_buinary.txt is not found.\n");
        printf("IMMORTAL OMNISSIAH is not happy.\n");
        printf("please check the file or the file right.\n");

        return -1;
    }
    printf("please wait.the machine is writing the file.\n");
    for (int i = 0; i < strlen(buff); i++)
    {
        print_binary(buff[i], binary);
        for (int i = 0; i < 8; i++)
        {
            fputc(binary[i], fp);
        }
        fputc('\n', fp);
    }
    printf("the brinary file is ready.\n");
    fclose(fp);
    free(buff);

    return 0;
}
