#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[]){
    FILE* fp;
    uint32_t tmp1, tmp2;

    if(argc != 3){
        printf("Usage : %s [file1] [file2] \n", argv[0]);
        return 0;
    }

    if((fp = fopen(argv[1], "r")) == NULL ){
        return 0;
    }
    fread(&tmp1, sizeof(uint32_t), sizeof(tmp1), fp);
    fclose(fp);

    if((fp = fopen(argv[2], "r")) == NULL ){
        return 0;
    }
    fread(&tmp2, sizeof(uint32_t), sizeof(tmp2), fp);
    fclose(fp);

    tmp1 = htonl(tmp1);
    tmp2 = htonl(tmp2);

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x) \n", tmp1, tmp1, tmp2, tmp2, tmp1+tmp2, tmp1+tmp2);
    return 0;
}