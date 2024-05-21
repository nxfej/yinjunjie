#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int cnt = 0;
    char s[1024]; // Buffer for reading words

    if (argc != 3) {
        fprintf(stderr, "Usage: %s [-c|-w] input_file_name\n", argv[0]);
        return 1;
    }

    if ((fp = fopen(argv[2], "r")) == NULL) {
        perror("Error opening file");
        return 1;
    }

    if (strcmp(argv[1], "-w") == 0) { // 统计单词
        while (fscanf(fp, "%s", s) != EOF) {
            cnt++; // Each fscanf read counts as one word
        }
        printf("单词数=%d\n", cnt);
    } else if (strcmp(argv[1], "-c") == 0) { // 统计字符
        int c;
        while ((c = fgetc(fp)) != EOF) {
            cnt++;
        }
        printf("字符数=%d\n", cnt);
    } else {
        fprintf(stderr, "Invalid parameter. Use '-c' for characters or '-w' for words.\n");
        return 1;
    }

    fclose(fp);
    return 0;
}
