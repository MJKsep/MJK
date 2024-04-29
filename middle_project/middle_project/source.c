#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENG_LENGTH 15
#define MAX_KOR_LENGTH 15
#define MAX_WORDS 60

void OpenBook();
void study();
void quiz(char*** words, int* error, int Day, int WordCount);
void quiz_error(char*** words, int* error, int Day, int WordCount);
void quiz_know(char*** words, int* error, int Day, int WordCount);
void addWord();
void delete();
int Choice_Day();
int readWordCount(int _Day);
void Load_Words(char*** words, int _Day, int* error);

int main() {
    int choice;

    while (1) {
        system("cls");
        printf("    *************************************'�� �� ��'�� ���� �ܾ���************************************* \n\n\n\n\n\n\n\n");
        printf("          1. �ܾ��� ��ġ��\n\n\n");
        printf("          2. ���� ����\n\n\n");
        printf("          3. �ܾ��� ����\n\n\n");
        printf("          4. ���� ����\n\n\n");
        printf("\n\n\n\n\n");
        printf("                                                   ����: ");
        scanf("%d", &choice);

        switch (choice) {
        
        case 1:
            system("cls");
            OpenBook();
            break;
        case 2:
            system("cls");
            printf("    *************************************'�� �� ��'�� ���� �ܾ���************************************* ");
            printf("\n\n\n\n\n                                               *���� ����*");
            study();
            break;
        case 3:
            system("cls");
            printf("    *************************************'�� �� ��'�� ���� �ܾ���************************************* ");
            printf("\n\n\n\n\n                                             *�ܾ��� ����*");
            printf("\n\n\n          1. �߰�\n\n\n");
            printf("          2. ����\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            printf("                                                   ����: ");
            scanf("%d", &choice);
           
            switch (choice) {

            case 1:
                system("cls");
                printf("    *************************************'�� �� ��'�� ���� �ܾ���************************************* ");
                printf("\n\n\n\n\n                                                *�ܾ� �߰�*");
                addWord();
                break;
            case 2:
                system("cls");
                printf("    *************************************'�� �� ��'�� ���� �ܾ���************************************* ");
                printf("\n\n\n\n\n                                                *�ܾ� ����*");
                delete();
                break;
            }
            break;
        case 4:
            printf("���α׷��� �����մϴ�.\n");
            exit(0);
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
            system("cls");
        }
    }

    return 0;
}



//1 �ܾ��� ��ġ��
void OpenBook() {
    //�ܾ� ����
    printf("    *************************************'�� �� ��'�� ���� �ܾ���************************************* \n\n\n\n\n");
    printf("                                             *�ܾ��� ��ġ��*\n");
    int Day = Choice_Day();
    int WordCount = readWordCount(Day);
    char*** words = (char***)malloc(MAX_WORDS * sizeof(char**));
    int* error = (int*)malloc(MAX_WORDS * sizeof(int));

    for (int i = 0; i < WordCount; i++) {
        words[i] = (char**)malloc(2 * sizeof(char*));
        for (int j = 0; j < 2; j++) {
            words[i][j] = (char*)malloc(MAX_ENG_LENGTH * sizeof(char));
        }
    }
    
    Load_Words(words, Day, error);
    int page = (WordCount / 20) + 1; // 1-> 1~20 / 2-> 21~40 / 3-> 41~60
    int Last_num = WordCount % 20;
    int mv_page=1;
    int mv_to_page = 0;
    int end = 0;
    if (page == 1) {
        while (end == 0) {
            system("cls");
            printf("    *************************************'�� �� ��'�� ���� �ܾ���************************************* \n\n\n\n\n");
            printf("                                             *�ܾ��� ��ġ��*\n\n\n\n");

            for (int i = 0; i < WordCount; i += 2) {
                // ù ��° �ܾ�/�� ��
                if (i < 10) {
                    int space = 15 - strlen(words[i][0]);
                    printf("                  ");
                    printf(" %d. %s", i + 1, words[i][0]);
                    for (int j = 0; j < space; j++) printf(" ");
                    printf("%s", words[i][1]);

                    int space2 = 15 - strlen(words[i][1]);
                    // �߰� ����
                    for (int i = 0; i < space2; i++) printf(" ");
                    printf("||    ");

                    // �� ��° �ܾ�/�� �� (WordCount�� Ȧ���� ��� ������ �ܾ�/�� ���� ó���ϱ� ���� ����)
                    if (i + 1 < WordCount) {
                        space = 15 - strlen(words[i + 1][0]);
                        if (i == 8) printf("%d. %s", i + 2, words[i + 1][0]);
                        else printf(" %d. %s", i + 2, words[i + 1][0]);
                        for (int j = 0; j < space; j++) {
                            printf(" ");
                        }
                        printf("%s", words[i + 1][1]);
                        int space3 = 15 - strlen(words[i + 1][1]);
                        for (int i = 0; i < space3; i++) printf(" ");
                        printf("\n");
                        //printf("                                                    ||\n");
                        printf("                                                    ||");
                    }

                    printf("\n");
                }
                else {
                    int space = 15 - strlen(words[i][0]);
                    printf("                  ");
                    printf("%d. %s", i + 1, words[i][0]);
                    for (int j = 0; j < space; j++) printf(" ");
                    printf("%s", words[i][1]);

                    int space2 = 15 - strlen(words[i][1]);
                    // �߰� ����
                    for (int i = 0; i < space2; i++) printf(" ");
                    printf("||    ");

                    // �� ��° �ܾ�/�� �� (WordCount�� Ȧ���� ��� ������ �ܾ�/�� ���� ó���ϱ� ���� ����)
                    if (i + 1 < WordCount) {
                        space = 15 - strlen(words[i + 1][0]);
                        printf("%d. %s", i + 2, words[i + 1][0]);
                        for (int j = 0; j < space; j++) {
                            printf(" ");
                        }
                        printf("%s", words[i + 1][1]);
                        int space3 = 15 - strlen(words[i + 1][1]);
                        for (int i = 0; i < space3; i++) printf(" ");
                        printf("\n");
                        //printf("                                                    ||\n");
                        printf("                                                    ||");
                    }

                    printf("\n");
                }
            }          
            break;
        }//while
    }





    else if (page == 2) {
        while (1) {
            system("cls");
            printf("    *************************************'�� �� ��'�� ���� �ܾ���************************************* \n\n\n\n\n");
            printf("                                             *�ܾ��� ��ġ��*\n\n\n");
            if (mv_page == 1) {
                for (int i = 0; i < 20; i += 2) {
                    // ù ��° �ܾ�/�� ��
                    if (i < 10) {
                        int space = 15 - strlen(words[i][0]);
                        printf("                  ");
                        printf(" %d. %s", i + 1, words[i][0]);
                        for (int j = 0; j < space; j++) printf(" ");
                        printf("%s", words[i][1]);

                        int space2 = 15 - strlen(words[i][1]);
                        // �߰� ����
                        for (int i = 0; i < space2; i++) printf(" ");
                        printf("||    ");

                        // �� ��° �ܾ�/�� �� (WordCount�� Ȧ���� ��� ������ �ܾ�/�� ���� ó���ϱ� ���� ����)
                        if (i + 1 < WordCount) {                            
                            space = 15 - strlen(words[i + 1][0]);
                            if(i==8) printf("%d. %s", i + 2, words[i + 1][0]);
                            else printf(" %d. %s", i + 2, words[i + 1][0]);
                            for (int j = 0; j < space; j++) {
                                printf(" ");
                            }
                            printf("%s", words[i + 1][1]);
                            int space3 = 15 - strlen(words[i + 1][1]);
                            for (int i = 0; i < space3; i++) printf(" ");
                            printf("\n");
                            //printf("                                                    ||\n");
                            printf("                                                    ||");
                        }
                        printf("\n");
                    }
                    else {
                        int space = 15 - strlen(words[i][0]);
                        printf("                  ");
                        printf("%d. %s", i + 1, words[i][0]);
                        for (int j = 0; j < space; j++) printf(" ");
                        printf("%s", words[i][1]);

                        int space2 = 15 - strlen(words[i][1]);
                        // �߰� ����
                        for (int i = 0; i < space2; i++) printf(" ");
                        printf("||    ");

                        // �� ��° �ܾ�/�� �� (WordCount�� Ȧ���� ��� ������ �ܾ�/�� ���� ó���ϱ� ���� ����)
                        if (i + 1 < WordCount) {
                            space = 15 - strlen(words[i + 1][0]);
                            printf("%d. %s", i + 2, words[i + 1][0]);
                            for (int j = 0; j < space; j++) {
                                printf(" ");
                            }
                            printf("%s", words[i + 1][1]);
                            int space3 = 15 - strlen(words[i + 1][1]);
                            for (int i = 0; i < space3; i++) printf(" ");
                            printf("\n");
                            //printf("                                                    ||\n");
                            printf("                                                    ||");
                        }
                        printf("\n");
                    }
                }
                printf("1. ���� ������  2. ���� ������ \n>>");
                scanf("%d", &mv_to_page);
                if (mv_to_page == 2) {
                    mv_page = 2;
                }
            }//page 1

            else if (mv_page == 2) {
                for (int i = 21; i < WordCount; i += 2) {
                    // ù ��° �ܾ�/�� ��
                    if (i < 10) {
                        int space = 15 - strlen(words[i][0]);
                        printf("                  ");
                        printf(" %d. %s", i + 1, words[i][0]);
                        for (int j = 0; j < space; j++) printf(" ");
                        printf("%s", words[i][1]);

                        int space2 = 15 - strlen(words[i][1]);
                        // �߰� ����
                        for (int i = 0; i < space2; i++) printf(" ");
                        printf("||    ");

                        // �� ��° �ܾ�/�� �� (WordCount�� Ȧ���� ��� ������ �ܾ�/�� ���� ó���ϱ� ���� ����)
                        if (i + 1 < WordCount) {
                            space = 15 - strlen(words[i + 1][0]);
                            printf(" %d. %s", i + 2, words[i + 1][0]);
                            for (int j = 0; j < space; j++) {
                                printf(" ");
                            }
                            printf("%s", words[i + 1][1]);
                            int space3 = 15 - strlen(words[i + 1][1]);
                            for (int i = 0; i < space3; i++) printf(" ");
                            printf("\n");
                            //printf("                                                    ||\n");
                            printf("                                                    ||");
                        }
                        printf("\n");
                    }
                    else {
                        int space = 15 - strlen(words[i][0]);
                        printf("                  ");
                        printf("%d. %s", i + 1, words[i][0]);
                        for (int j = 0; j < space; j++) printf(" ");
                        printf("%s", words[i][1]);

                        int space2 = 15 - strlen(words[i][1]);
                        // �߰� ����
                        for (int i = 0; i < space2; i++) printf(" ");
                        printf("||    ");

                        // �� ��° �ܾ�/�� �� (WordCount�� Ȧ���� ��� ������ �ܾ�/�� ���� ó���ϱ� ���� ����)
                        if (i + 1 < WordCount) {
                            space = 15 - strlen(words[i + 1][0]);
                            printf("%d. %s", i + 2, words[i + 1][0]);
                            for (int j = 0; j < space; j++) {
                                printf(" ");
                            }
                            printf("%s", words[i + 1][1]);
                            int space3 = 15 - strlen(words[i + 1][1]);
                            for (int i = 0; i < space3; i++) printf(" ");
                            printf("\n");
                            //printf("                                                    ||\n");
                            if (i + 2 != WordCount) printf("                                                    ||");
                        }
                        printf("\n");
                    }
                }
                printf("1. ���� ������  2. �ܾ��� ��ġ�� ���� \n>>");
                scanf("%d", &mv_to_page);
                if (mv_to_page == 2) break;
                else if (mv_to_page == 1) mv_page = 1;
            }//mv page 2
        }//while��
    }//page 2�϶�

    else if (page == 3) {
        while (1) {
            system("cls");
            printf("    *************************************'�� �� ��'�� ���� �ܾ���************************************* \n\n\n\n\n");
            printf("                                             *�ܾ��� ��ġ��*\n\n\n");
            if (mv_page == 1) {
                for (int i = 0; i < 20; i += 2) {
                    // ù ��° �ܾ�/�� ��
                    if (i < 10) {
                        int space = 15 - strlen(words[i][0]);
                        printf("                  ");
                        printf(" %d. %s", i + 1, words[i][0]);
                        for (int j = 0; j < space; j++) printf(" ");
                        printf("%s", words[i][1]);

                        int space2 = 15 - strlen(words[i][1]);
                        // �߰� ����
                        for (int i = 0; i < space2; i++) printf(" ");
                        printf("||    ");

                        // �� ��° �ܾ�/�� �� (WordCount�� Ȧ���� ��� ������ �ܾ�/�� ���� ó���ϱ� ���� ����)
                        if (i + 1 < WordCount) {
                            space = 15 - strlen(words[i + 1][0]);
                            if (i == 8) printf("%d. %s", i + 2, words[i + 1][0]);
                            else printf(" %d. %s", i + 2, words[i + 1][0]);
                            for (int j = 0; j < space; j++) {
                                printf(" ");
                            }
                            printf("%s", words[i + 1][1]);
                            int space3 = 15 - strlen(words[i + 1][1]);
                            for (int i = 0; i < space3; i++) printf(" ");
                            printf("\n");
                            //printf("                                                    ||\n");
                            printf("                                                    ||");
                        }
                        printf("\n");
                    }
                    else {
                        int space = 15 - strlen(words[i][0]);
                        printf("                  ");
                        printf("%d. %s", i + 1, words[i][0]);
                        for (int j = 0; j < space; j++) printf(" ");
                        printf("%s", words[i][1]);

                        int space2 = 15 - strlen(words[i][1]);
                        // �߰� ����
                        for (int i = 0; i < space2; i++) printf(" ");
                        printf("||    ");

                        // �� ��° �ܾ�/�� �� (WordCount�� Ȧ���� ��� ������ �ܾ�/�� ���� ó���ϱ� ���� ����)
                        if (i + 1 < WordCount) {
                            space = 15 - strlen(words[i + 1][0]);
                            printf("%d. %s", i + 2, words[i + 1][0]);
                            for (int j = 0; j < space; j++) {
                                printf(" ");
                            }
                            printf("%s", words[i + 1][1]);
                            int space3 = 15 - strlen(words[i + 1][1]);
                            for (int i = 0; i < space3; i++) printf(" ");
                            printf("\n");
                            //printf("                                                    ||\n");
                            printf("                                                    ||");
                        }
                        printf("\n");
                    }
                }
                printf("1. ���� ������  2. ���� ������ \n>>");
                scanf("%d", &mv_to_page);
                if (mv_to_page == 2) {
                    mv_page = 2;
                }
            }//page 1

            else if (mv_page == 2) {
                for (int i = 21; i < 40; i += 2) {
                    // ù ��° �ܾ�/�� ��                                     
                        int space = 15 - strlen(words[i][0]);
                        printf("                  ");
                        printf("%d. %s", i + 1, words[i][0]);
                        for (int j = 0; j < space; j++) printf(" ");
                        printf("%s", words[i][1]);

                        int space2 = 15 - strlen(words[i][1]);
                        // �߰� ����
                        for (int i = 0; i < space2; i++) printf(" ");
                        printf("||    ");

                        // �� ��° �ܾ�/�� �� (WordCount�� Ȧ���� ��� ������ �ܾ�/�� ���� ó���ϱ� ���� ����)
                        if (i + 1 < WordCount) {
                            space = 15 - strlen(words[i + 1][0]);
                            printf("%d. %s", i + 2, words[i + 1][0]);
                            for (int j = 0; j < space; j++) {
                                printf(" ");
                            }
                            printf("%s", words[i + 1][1]);
                            int space3 = 15 - strlen(words[i + 1][1]);
                            for (int i = 0; i < space3; i++) printf(" ");
                            printf("\n");
                            //printf("                                                    ||\n");
                            printf("                                                    ||");
                        }
                        printf("\n");
                    
                }
                printf("1. ���� ������  2. ���� ������ \n>>");
                scanf("%d", &mv_to_page);
                if (mv_to_page == 2) mv_page = 3;
                else if (mv_to_page == 1) mv_page = 1;
            }//mv page 2

            else if (mv_page == 3) {
                for (int i = 41; i < WordCount; i += 2) {
                    // ù ��° �ܾ�/�� ��
                        int space = 15 - strlen(words[i][0]);
                        printf("                  ");
                        printf("%d. %s", i + 1, words[i][0]);
                        for (int j = 0; j < space; j++) printf(" ");
                        printf("%s", words[i][1]);

                        int space2 = 15 - strlen(words[i][1]);
                        // �߰� ����
                        for (int i = 0; i < space2; i++) printf(" ");
                        printf("||    ");

                        // �� ��° �ܾ�/�� �� (WordCount�� Ȧ���� ��� ������ �ܾ�/�� ���� ó���ϱ� ���� ����)
                        if (i + 1 < WordCount) {
                            space = 15 - strlen(words[i + 1][0]);
                            printf("%d. %s", i + 2, words[i + 1][0]);
                            for (int j = 0; j < space; j++) {
                                printf(" ");
                            }
                            printf("%s", words[i + 1][1]);
                            int space3 = 15 - strlen(words[i + 1][1]);
                            for (int i = 0; i < space3; i++) printf(" ");
                            printf("\n");
                            //printf("                                                    ||\n");
                            if (i + 2 != WordCount) printf("                                                    ||");
                        }
                        printf("\n");                    
                }
                printf("1. ���� ������  2. �ܾ��� ��ġ�� ���� \n>>");
                scanf("%d", &mv_to_page);
                if (mv_to_page == 2) break;
                else if (mv_to_page == 1) mv_page = 2;
                }//mv page 3
        }//while��
    }//page 3�϶�

    // ���� �Ҵ� ����
    for (int i = 0; i < WordCount; i++) {
        for (int j = 0; j < 2; j++) {
            free(words[i][j]);
        }
        free(words[i]);
    }
    free(words);
    free(error);
    while (1) {
        printf("\n\n\n\n");
        printf("���� Ű �Է�.\n");
        int input = getchar(); // ����ڷκ��� �� ���� �Է� �ޱ�
        if (input == '\n') { // �Է¹��� ���ڰ� '\n'�̸�, �� ���� Ű�̸�

            break; // while ������ �������� ���� �ܰ�� ����
        }
    }
}//�ܾ��� ����

//2.���ν���
void study() {
    int Day = Choice_Day();
    int WordCount = readWordCount(Day);
    char*** words = (char***)malloc(WordCount * sizeof(char**));
    int* error = (int*)malloc(WordCount * sizeof(int));

    for (int i = 0; i < WordCount; i++) {
        words[i] = (char**)malloc(2 * sizeof(char*));
        for (int j = 0; j < 2; j++) {
            words[i][j] = (char*)malloc(MAX_ENG_LENGTH * sizeof(char));
        }
    }
    
    Load_Words(words, Day, error);
    int choice=0;
    system("cls");
    printf("    *************************************'�� �� ��'�� ���� �ܾ���************************************* ");
    printf("\n\n\n\n\n\n\n\n\n");
    printf("                               1. ���� Quiz     2. ���� ����     3. ������ ���ߴ� ���� \n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                                                   ����: ");
    scanf("%d", &choice);
    getchar();

    switch (choice) {
    case 1:
        quiz(words, error, Day, WordCount);
        break;

    case 2:
        quiz_error(words, error, Day, WordCount);
        break;

    case 3:
        quiz_know(words, error, Day, WordCount);
        break;
    }

    char filename[20]; // ���� �̸��� ������ �迭�� ũ�⸦ �÷Ƚ��ϴ�.
    sprintf(filename, "Day%d.txt", Day); // ���� �̸� ����

    char tempFilename[25];
    sprintf(tempFilename, "%s_temp", filename); // �ӽ� ���� �̸� ����
    FILE* tempFile = fopen(tempFilename, "w");
    if (tempFile == NULL) {
        printf("�ӽ� ������ ������ �� �����ϴ�.\n");
        return;
    }

    // �ۼ�
    for (int i = 0; i < WordCount; i++) {
            fprintf(tempFile, "%s-%s-%d\n", words[i][0], words[i][1], error[i]);   
    }

    // ���� �� �޸� �ڿ� ����
    fclose(tempFile);


    // ���� ���� ���� �� �ӽ� ���� �̸� ����
    remove(filename);
    rename(tempFilename, filename);

    //�޸� ����
    for (int i = 0; i < WordCount; i++) {
            for (int j = 0; j < 2; j++) {
                free(words[i][j]);
            }
            free(words[i]);
        }
        free(words);
        free(error);
}//���� ����

//(1)���� - fgets ���
void quiz(char*** words, int* error, int Day, int WordCount) {
    int wrongCount = 0;
    
    for (int j = 0; j < WordCount; j++) {
        system("cls");
        printf("    *************************************'�� �� ��'�� ���� �ܾ���************************************* ");
        printf("\n\n\n\n\n");
        printf("                                              *���� ����*\n\n\n\n");
        printf("                                         %d. '%s'�� �ǹ̴�? ",j+1, words[j][0]);
        printf("\n\n\n\n\n\n\n\n\n\n\n");
        printf("                                                >>");
        char userAnswer[MAX_KOR_LENGTH + 1]; // +1 for null terminator
        fgets(userAnswer, MAX_KOR_LENGTH + 1, stdin);

        // fgets�� ������ ���ڵ� �����ϹǷ�, �Էµ� ���ڿ����� ������ ���ڸ� �����մϴ�.
        userAnswer[strcspn(userAnswer, "\n")] = 0;

        if (strcmp(userAnswer, words[j][1]) != 0) {
            printf("\n                                   ");
            printf("Ʋ�Ƚ��ϴ�! %s�� ���� %s�Դϴ�.\n", words[j][0],words[j][1]);
            wrongCount++;
            error[j]++;
        }
        else {
            printf("\n                                               ");
            printf("�����Դϴ�!\n");
        }
        while (1) {
            printf("\n\n\n\n");
            printf("���� Ű �Է�.\n");
            int input = getchar(); // ����ڷκ��� �� ���� �Է� �ޱ�
            if (input == '\n') { // �Է¹��� ���ڰ� '\n'�̸�, �� ���� Ű�̸�
                
                break; // while ������ �������� ���� �ܰ�� ����
            }
        }
    }
    system("cls");
    printf("    *************************************'�� �� ��'�� ���� �ܾ���************************************* ");
    printf("\n\n\n\n\n");
    printf("                                     ");
    printf("��� �������ϴ�. <Day %d> �� Ʋ�� ����: %d\n", Day, wrongCount);
    while (1) {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("���� Ű �Է�.\n");
        int input = getchar(); // ����ڷκ��� �� ���� �Է� �ޱ�
        if (input == '\n') { // �Է¹��� ���ڰ� '\n'�̸�, �� ���� Ű�̸�

            break; // while ������ �������� ���� �ܰ�� ����
        }
    }
}


//(2)���� ���� - error �Լ� �̿�
void quiz_error(char*** words, int* error, int Day, int WordCount) {
    int wrongCount = 0;
    int* error_sort = (int*)malloc(WordCount * sizeof(int));
    int* error_temp = (int*)malloc(WordCount * sizeof(int));
    int temp;
    int sort_temp;

    for (int i = 0; i < WordCount; i++) {
        error_sort[i] = i;
        error_temp[i] = error[i];
    }

    for (int j = 0; j < WordCount; j++) {
        for (int k = 0; k < WordCount-1; k++) {
            if (error_temp[k] < error_temp[k+1]) {
                temp = error_temp[k];
                error_temp[k] = error_temp[k + 1];
                error_temp[k + 1] = temp;
                sort_temp = error_sort[k];
                error_sort[k] = error_sort[k + 1];
                error_sort[k + 1] = sort_temp;
            }
        }
    }
    for (int j = 0; j < WordCount; j++) {
        system("cls");
        printf("    *************************************'�� �� ��'�� ���� �ܾ���************************************* ");
        printf("\n\n\n\n\n");
        printf("                                           *���� ���� ����*\n\n\n\n");
        printf("                                           %d. '%s'�� �ǹ̴�? ", j+1,words[error_sort[j]][0]);
        printf("\n\n\n\n\n\n\n\n\n\n\n");
        printf("                                                >>");
        char userAnswer[MAX_KOR_LENGTH + 1]; // +1 for null terminator
        fgets(userAnswer, MAX_KOR_LENGTH + 1, stdin);

        // fgets�� ������ ���ڵ� �����ϹǷ�, �Էµ� ���ڿ����� ������ ���ڸ� �����մϴ�.
        userAnswer[strcspn(userAnswer, "\n")] = 0;

        if (strcmp(userAnswer, words[error_sort[j]][1]) != 0) {
            printf("\n\n                                                   �����Դϴ�. %s�� �ǹ̴� %s �Դϴ�.\n ", words[error_sort[j]][0],words[error_sort[j]][1]);
            wrongCount++;
            error[error_sort[j]]++;
            while (1) {
                printf("\n\n");
                printf("���� Ű �Է�.\n");
                int input = getchar(); // ����ڷκ��� �� ���� �Է� �ޱ�
                if (input == '\n') { // �Է¹��� ���ڰ� '\n'�̸�, �� ���� Ű�̸�

                    break; // while ������ �������� ���� �ܰ�� ����
                }
            }
        }
        else {
            printf("\n\n                                               �����Դϴ�!\n");
            while (1) {
                printf("\n\n");
                printf("���� Ű �Է�.\n");
                int input = getchar(); // ����ڷκ��� �� ���� �Է� �ޱ�
                if (input == '\n') { // �Է¹��� ���ڰ� '\n'�̸�, �� ���� Ű�̸�

                    break; // while ������ �������� ���� �ܰ�� ����
                }
            }
        }
    }
    
    system("cls");
    printf("    *************************************'�� �� ��'�� ���� �ܾ���************************************* ");
    printf("\n\n\n\n\n");
    printf("                                     ");
    printf("��� �������ϴ�. <Day %d> �� Ʋ�� ����: %d\n", Day, wrongCount);
    while (1) {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("���� Ű �Է�.\n");
        int input = getchar(); // ����ڷκ��� �� ���� �Է� �ޱ�
        if (input == '\n') { // �Է¹��� ���ڰ� '\n'�̸�, �� ���� Ű�̸�

            break; // while ������ �������� ���� �ܰ�� ����
        }
    }


    free(error_sort);
    free(error_temp);


}




//(3)������ �����ϱ�
void quiz_know(char*** words, int* error, int Day, int WordCount) {
    int wrongCount = 0;
    int choice1 = 0;
    int choice2 = 0;
    for (int j = 0; j < WordCount; j++) {
        system("cls");
        printf("    *************************************'�� �� ��'�� ���� �ܾ���************************************* ");
        printf("\n\n\n\n\n");
        printf("                                           *������ �����ϱ�*\n\n\n\n");
        printf("                                          %d. '%s'�� �ǹ̴�? ", j + 1, words[j][0]);
        printf("\n\n\n\n\n\n\n");
        printf("                                         1. �˰��ִ�  2. �𸣰ڴ�");
        printf("\n\n\n\n\n\n\n");
            printf("                                                >>");
        scanf("%d", &choice1);
        getchar();
        switch (choice1) {
        case 1:
            printf("%s�� �ǹ̴� %s �Դϴ�.\n\n", words[j][0], words[j][1]);
            printf("1. �����  2. Ʋ�ȴ�\n>>");
            scanf("%d", &choice2);
            getchar();
            if (choice2 == 2) {
                error[j]++;
            }
            break;

        case 2:
            printf("%s�� �ǹ̴� %s �Դϴ�.", words[j][0], words[j][1]);
            error[j]++;
            while (1) {
                printf("\n\n���� Ű �Է�.");
                int input = getchar(); // ����ڷκ��� �� ���� �Է� �ޱ�
                if (input == '\n') { // �Է¹��� ���ڰ� '\n'�̸�, �� ���� Ű�̸�

                    break; // while ������ �������� ���� �ܰ�� ����
                }
            }
            break;
        }
    }
}




//3.�ܾ��� ����
//( 1 ) �߰�
void addWord() {
    int Day = Choice_Day();
    int wordCount = readWordCount(Day);
    if (wordCount >= MAX_WORDS) {
        printf("�ܾ� ������ �ʰ��Ǿ����ϴ� ! \n ");
        return;
    }
    system("cls");
    printf("    *************************************'�� �� ��'�� ���� �ܾ���************************************* ");
    printf("\n\n\n\n\n                                                *�ܾ� �߰�*");
    printf("\n\n                                           �߰��� �ܾ��� : Day %d\n", Day);
    char ENG[MAX_ENG_LENGTH];
    char KOR[MAX_KOR_LENGTH];
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                   �ܾ�: ");
    scanf("%s", ENG);
    printf("                                                   �ǹ�: ");
    scanf(" %[^\n]", KOR); // ���� ���� �Է� ó��
    getchar();
    char filename[12]; // ���� �̸��� ������ �迭
    sprintf(filename, "Day%d.txt", Day); // ���� �̸� ����

    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return;
    }

    fprintf(file, "%s-%s-0\n", ENG, KOR);
    fclose(file);

    system("cls");
    printf("    *************************************'�� �� ��'�� ���� �ܾ���************************************* ");
    printf("\n\n\n\n\n                                                *�ܾ� �߰�*");
    printf("\n\n                                           �߰��� �ܾ��� : Day %d\n", Day);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                      \"%s\"�� �ܾ��忡 �߰��Ǿ����ϴ�.\n", ENG);
    while (1) {
        printf("\n\n\n���� Ű �Է�.\n");
        int input = getchar(); // ����ڷκ��� �� ���� �Է� �ޱ�
        if (input == '\n') { // �Է¹��� ���ڰ� '\n'�̸�, �� ���� Ű�̸�

            break; // while ������ �������� ���� �ܰ�� ����
        }
    }
}
//( 2 ) ����
void delete() {
    int Day = Choice_Day();
    int WordCount = readWordCount(Day);
    char*** words = (char***)malloc(WordCount * sizeof(char**));
    int* error = (int*)malloc(WordCount * sizeof(int));

    for (int i = 0; i < WordCount; i++) {
        words[i] = (char**)malloc(2 * sizeof(char*));
        for (int j = 0; j < 2; j++) {
            words[i][j] = (char*)malloc(MAX_ENG_LENGTH * sizeof(char));
        }
    }
    system("cls");
    printf("    *************************************'�� �� ��'�� ���� �ܾ���************************************* ");
    printf("\n\n\n\n\n                                                *�ܾ� ����*");
    printf("\n\n                                          ������ �ܾ��� : Day %d\n", Day);
    int deletenum=0;
    char deleteWord[MAX_ENG_LENGTH];
    Load_Words(words, Day, error);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                   �ܾ�: ");
    scanf("%s", deleteWord);
    getchar();
    int no_word = 1;
    for (int i = 0; i < WordCount; i++) {
        if (strcmp(words[i][0], deleteWord) == 0){
            deletenum = i;
            no_word = 0;
            char filename[20]; // ���� �̸��� ������ �迭�� ũ�⸦ �÷Ƚ��ϴ�.
            sprintf(filename, "Day%d.txt", Day); // ���� �̸� ����

            char tempFilename[25];
            sprintf(tempFilename, "%s_temp", filename); // �ӽ� ���� �̸� ����
            FILE* tempFile = fopen(tempFilename, "w");
            if (tempFile == NULL) {
                printf("�ӽ� ������ ������ �� �����ϴ�.\n");
                return;
            }

            // ������ �ܾ ������ ������ �ܾ �ӽ� ���Ͽ� ����
            for (int i = 0; i < WordCount; i++) {
                if (i != deletenum) {
                    fprintf(tempFile, "%s-%s-%d\n", words[i][0], words[i][1], error[i]);
                }
            }

            // ���� �� �޸� �ڿ� ����
            fclose(tempFile);
            

            // ���� ���� ���� �� �ӽ� ���� �̸� ����
            remove(filename);
            rename(tempFilename, filename);

            printf("\"%s\" �ܾ �����Ǿ����ϴ�.\n", deleteWord);
            break;
        }
    }

    for (int i = 0; i < WordCount; i++) {
        free(words[i][0]);
        free(words[i][1]);
        free(words[i]);
    }
    free(words);
    free(error);

    if (no_word == 1) {
        system("cls");
        printf("    *************************************'�� �� ��'�� ���� �ܾ���************************************* ");
        printf("\n\n\n\n\n                                                *�ܾ� ����*");
        printf("\n\n                                         ������ �ܾ��� : Day %d\n", Day);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                    \"%s\"�� �ܾ��� Day %d�� �������� �ʽ��ϴ�. ",deleteWord,Day);
    }
    while (1) {
        printf("\n\n\n���� Ű �Է�.\n");
        int input = getchar(); // ����ڷκ��� �� ���� �Է� �ޱ�
        if (input == '\n') { // �Է¹��� ���ڰ� '\n'�̸�, �� ���� Ű�̸�

            break; // while ������ �������� ���� �ܰ�� ����
        }
    }
}


int Choice_Day() {
    int Day_Choice = 0;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                           ���ϴ� �ܾ��� Day : ");
    scanf("%d", &Day_Choice);
    getchar();
    if (Day_Choice < 1 || Day_Choice > 10) {
        printf("�ܾ��� ���� ���� !!");
        Day_Choice = 0;
    }

    return Day_Choice;
}


int readWordCount(int _Day) {
    
    char filename[20]; // ���� �̸��� ������ �迭�� ũ�⸦ �÷Ƚ��ϴ�.
    sprintf(filename, "Day%d.txt", _Day); // ���� �̸� ����
    
    
    
    //int Day = _Day;
    int count = 0;
    char buffer[MAX_ENG_LENGTH + MAX_KOR_LENGTH+4];
    FILE* file = NULL;

    file = fopen(filename, "r");

    /*switch (Day) {
    case 1:
        file = fopen("Day1.txt", "r");
        break;
    case 2:
        file = fopen("Day2.txt", "r");
        break;
    case 3:
        file = fopen("Day3.txt", "r");
        break;
    case 4:
        file = fopen("Day4.txt", "r");
        break;
    case 5:
        file = fopen("Day5.txt", "r");
        break;
    }
    */

    if (file == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return 0;
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (strchr(buffer, '-') != NULL) {
            count++;
        }
    }
    fclose(file);

    return count;
}//COUNT_WORDS
void Load_Words(char*** words, int _Day, int* error) {
    char filename[20]; // ���� �̸��� ������ �迭�� ũ�⸦ �÷Ƚ��ϴ�.
    sprintf(filename, "Day%d.txt", _Day); // ���� �̸� ����

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return;
    }

    char line[256]; // �� ���� �б� ���� ����� ũ���� ���� �迭�� �����մϴ�.
    int i = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        // line���� �ܾ�, ��, ���� Ƚ���� �и��Ͽ� �н��ϴ�.
        // sscanf ��� ��, line �迭�� ����մϴ�.
        sscanf(line, "%[^-]-%[^-]-%d", words[i][0], words[i][1], &error[i]);
        i++;
    }
    fclose(file);
}
 
//24.04.09 
//�ʿ��� ���� ����
//1. Quiz���� ���  ������ ���� ex *���� Quiz*  �Ǵ�  *���� ����*  *������ ���ߴ� ����*
//������ �׽�Ʈ �� �԰� ����
//�װ͸� �ϸ� ��