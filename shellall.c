#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX 100

// ---------- typeline command ----------
void typeline(char *option, char *fname) {
    FILE *fp = fopen(fname, "r");
    if (!fp) { printf("File not found!\n"); return; }

    char line[256];
    int n;

    if (strcmp(option, "-a") == 0) { // print all lines
        while (fgets(line, sizeof(line), fp)) printf("%s", line);
    } 
    else if (option[0] == '+') { // print first n lines
        n = atoi(option + 1);
        for (int i = 0; i < n && fgets(line, sizeof(line), fp); i++)
            printf("%s", line);
    }

    fclose(fp);
}

// ---------- count command ----------
void count(char *opt, char *fname) {
    FILE *fp = fopen(fname, "r");
    if (!fp) { printf("File not found!\n"); return; }

    int ch, words = 0, lines = 0, chars = 0;
    while ((ch = fgetc(fp)) != EOF) {
        chars++;
        if (ch == '\n') lines++;
        if (ch == ' ' || ch == '\n' || ch == '\t') words++;
    }

    if (strcmp(opt, "c") == 0)
        printf("Characters: %d\n", chars);
    else if (strcmp(opt, "w") == 0)
        printf("Words: %d\n", words);
    else if (strcmp(opt, "l") == 0)
        printf("Lines: %d\n", lines);

    fclose(fp);
}

// ---------- list command ----------
void list(char *opt, char *dirname) {
    DIR *dp = opendir(dirname);
    if (!dp) { printf("Directory not found!\n"); return; }

    struct dirent *entry;
    struct stat info;
    int count = 0;

    while ((entry = readdir(dp))) {
        char path[256];
        sprintf(path, "%s/%s", dirname, entry->d_name);
        stat(path, &info);
        count++;

        if (strcmp(opt, "f") == 0)
            printf("%s\n", entry->d_name);
        else if (strcmp(opt, "i") == 0)
            printf("%s\tInode:%lu\n", entry->d_name, entry->d_ino);
    }

    if (strcmp(opt, "n") == 0)
        printf("Total entries: %d\n", count);

    closedir(dp);
}

// ---------- search command ----------
void search(char *opt, char *fname, char *pattern) {
    FILE *fp = fopen(fname, "r");
    if (!fp) { printf("File not found!\n"); return; }

    char line[256];
    int line_no = 1, found = 0, count = 0;

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, pattern)) {
            found = 1;
            count++;
            if (strcmp(opt, "f") == 0) { // first occurrence
                printf("Found at line %d: %s", line_no, line);
                break;
            }
            else if (strcmp(opt, "a") == 0) // all occurrences
                printf("Found at line %d: %s", line_no, line);
        }
        line_no++;
    }

    if (strcmp(opt, "c") == 0)
        printf("Total occurrences: %d\n", count);
    else if (!found && strcmp(opt, "c") != 0)
        printf("Pattern not found.\n");

    fclose(fp);
}

// ---------- main shell ----------
int main() {
    char cmd[MAX], *args[5];

    while (1) {
        printf("myshell$ ");
        fgets(cmd, sizeof(cmd), stdin);
        cmd[strcspn(cmd, "\n")] = 0;  // remove newline

        if (strlen(cmd) == 0) continue;
        if (strcmp(cmd, "exit") == 0) break;

        int i = 0;
        args[i] = strtok(cmd, " ");
        while (args[i] != NULL)
            args[++i] = strtok(NULL, " ");

        if (strcmp(args[0], "typeline") == 0)
            typeline(args[1], args[2]);
        else if (strcmp(args[0], "count") == 0)
            count(args[1], args[2]);
        else if (strcmp(args[0], "list") == 0)
            list(args[1], args[2]);
        else if (strcmp(args[0], "search") == 0)
            search(args[1], args[2], args[3]);
        else { // run normal shell commands
            if (fork() == 0) {
                execlp(args[0], args[0], args[1], args[2], args[3], NULL);
                perror("Command failed");
                exit(0);
            }
            wait(NULL);
        }
        printf("\n");
    }
    return 0;
}
