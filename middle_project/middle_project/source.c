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
        printf("    *************************************'토 린 이'를 위한 단어장************************************* \n\n\n\n\n\n\n\n");
        printf("          1. 단어장 펼치기\n\n\n");
        printf("          2. 공부 시작\n\n\n");
        printf("          3. 단어장 관리\n\n\n");
        printf("          4. 공부 종료\n\n\n");
        printf("\n\n\n\n\n");
        printf("                                                   선택: ");
        scanf("%d", &choice);

        switch (choice) {
        
        case 1:
            system("cls");
            OpenBook();
            break;
        case 2:
            system("cls");
            printf("    *************************************'토 린 이'를 위한 단어장************************************* ");
            printf("\n\n\n\n\n                                               *공부 시작*");
            study();
            break;
        case 3:
            system("cls");
            printf("    *************************************'토 린 이'를 위한 단어장************************************* ");
            printf("\n\n\n\n\n                                             *단어장 관리*");
            printf("\n\n\n          1. 추가\n\n\n");
            printf("          2. 삭제\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            printf("                                                   선택: ");
            scanf("%d", &choice);
           
            switch (choice) {

            case 1:
                system("cls");
                printf("    *************************************'토 린 이'를 위한 단어장************************************* ");
                printf("\n\n\n\n\n                                                *단어 추가*");
                addWord();
                break;
            case 2:
                system("cls");
                printf("    *************************************'토 린 이'를 위한 단어장************************************* ");
                printf("\n\n\n\n\n                                                *단어 삭제*");
                delete();
                break;
            }
            break;
        case 4:
            printf("프로그램을 종료합니다.\n");
            exit(0);
        default:
            printf("잘못된 선택입니다. 다시 시도해주세요.\n");
            system("cls");
        }
    }

    return 0;
}



//1 단어장 펼치기
void OpenBook() {
    //단어 생성
    printf("    *************************************'토 린 이'를 위한 단어장************************************* \n\n\n\n\n");
    printf("                                             *단어장 펼치기*\n");
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
            printf("    *************************************'토 린 이'를 위한 단어장************************************* \n\n\n\n\n");
            printf("                                             *단어장 펼치기*\n\n\n\n");

            for (int i = 0; i < WordCount; i += 2) {
                // 첫 번째 단어/뜻 쌍
                if (i < 10) {
                    int space = 15 - strlen(words[i][0]);
                    printf("                  ");
                    printf(" %d. %s", i + 1, words[i][0]);
                    for (int j = 0; j < space; j++) printf(" ");
                    printf("%s", words[i][1]);

                    int space2 = 15 - strlen(words[i][1]);
                    // 추가 공간
                    for (int i = 0; i < space2; i++) printf(" ");
                    printf("||    ");

                    // 두 번째 단어/뜻 쌍 (WordCount가 홀수일 경우 마지막 단어/뜻 쌍을 처리하기 위한 조건)
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
                    // 추가 공간
                    for (int i = 0; i < space2; i++) printf(" ");
                    printf("||    ");

                    // 두 번째 단어/뜻 쌍 (WordCount가 홀수일 경우 마지막 단어/뜻 쌍을 처리하기 위한 조건)
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
            printf("    *************************************'토 린 이'를 위한 단어장************************************* \n\n\n\n\n");
            printf("                                             *단어장 펼치기*\n\n\n");
            if (mv_page == 1) {
                for (int i = 0; i < 20; i += 2) {
                    // 첫 번째 단어/뜻 쌍
                    if (i < 10) {
                        int space = 15 - strlen(words[i][0]);
                        printf("                  ");
                        printf(" %d. %s", i + 1, words[i][0]);
                        for (int j = 0; j < space; j++) printf(" ");
                        printf("%s", words[i][1]);

                        int space2 = 15 - strlen(words[i][1]);
                        // 추가 공간
                        for (int i = 0; i < space2; i++) printf(" ");
                        printf("||    ");

                        // 두 번째 단어/뜻 쌍 (WordCount가 홀수일 경우 마지막 단어/뜻 쌍을 처리하기 위한 조건)
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
                        // 추가 공간
                        for (int i = 0; i < space2; i++) printf(" ");
                        printf("||    ");

                        // 두 번째 단어/뜻 쌍 (WordCount가 홀수일 경우 마지막 단어/뜻 쌍을 처리하기 위한 조건)
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
                printf("1. 이전 페이지  2. 다음 페이지 \n>>");
                scanf("%d", &mv_to_page);
                if (mv_to_page == 2) {
                    mv_page = 2;
                }
            }//page 1

            else if (mv_page == 2) {
                for (int i = 21; i < WordCount; i += 2) {
                    // 첫 번째 단어/뜻 쌍
                    if (i < 10) {
                        int space = 15 - strlen(words[i][0]);
                        printf("                  ");
                        printf(" %d. %s", i + 1, words[i][0]);
                        for (int j = 0; j < space; j++) printf(" ");
                        printf("%s", words[i][1]);

                        int space2 = 15 - strlen(words[i][1]);
                        // 추가 공간
                        for (int i = 0; i < space2; i++) printf(" ");
                        printf("||    ");

                        // 두 번째 단어/뜻 쌍 (WordCount가 홀수일 경우 마지막 단어/뜻 쌍을 처리하기 위한 조건)
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
                        // 추가 공간
                        for (int i = 0; i < space2; i++) printf(" ");
                        printf("||    ");

                        // 두 번째 단어/뜻 쌍 (WordCount가 홀수일 경우 마지막 단어/뜻 쌍을 처리하기 위한 조건)
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
                printf("1. 이전 페이지  2. 단어장 펼치기 종료 \n>>");
                scanf("%d", &mv_to_page);
                if (mv_to_page == 2) break;
                else if (mv_to_page == 1) mv_page = 1;
            }//mv page 2
        }//while문
    }//page 2일때

    else if (page == 3) {
        while (1) {
            system("cls");
            printf("    *************************************'토 린 이'를 위한 단어장************************************* \n\n\n\n\n");
            printf("                                             *단어장 펼치기*\n\n\n");
            if (mv_page == 1) {
                for (int i = 0; i < 20; i += 2) {
                    // 첫 번째 단어/뜻 쌍
                    if (i < 10) {
                        int space = 15 - strlen(words[i][0]);
                        printf("                  ");
                        printf(" %d. %s", i + 1, words[i][0]);
                        for (int j = 0; j < space; j++) printf(" ");
                        printf("%s", words[i][1]);

                        int space2 = 15 - strlen(words[i][1]);
                        // 추가 공간
                        for (int i = 0; i < space2; i++) printf(" ");
                        printf("||    ");

                        // 두 번째 단어/뜻 쌍 (WordCount가 홀수일 경우 마지막 단어/뜻 쌍을 처리하기 위한 조건)
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
                        // 추가 공간
                        for (int i = 0; i < space2; i++) printf(" ");
                        printf("||    ");

                        // 두 번째 단어/뜻 쌍 (WordCount가 홀수일 경우 마지막 단어/뜻 쌍을 처리하기 위한 조건)
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
                printf("1. 이전 페이지  2. 다음 페이지 \n>>");
                scanf("%d", &mv_to_page);
                if (mv_to_page == 2) {
                    mv_page = 2;
                }
            }//page 1

            else if (mv_page == 2) {
                for (int i = 21; i < 40; i += 2) {
                    // 첫 번째 단어/뜻 쌍                                     
                        int space = 15 - strlen(words[i][0]);
                        printf("                  ");
                        printf("%d. %s", i + 1, words[i][0]);
                        for (int j = 0; j < space; j++) printf(" ");
                        printf("%s", words[i][1]);

                        int space2 = 15 - strlen(words[i][1]);
                        // 추가 공간
                        for (int i = 0; i < space2; i++) printf(" ");
                        printf("||    ");

                        // 두 번째 단어/뜻 쌍 (WordCount가 홀수일 경우 마지막 단어/뜻 쌍을 처리하기 위한 조건)
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
                printf("1. 이전 페이지  2. 다음 페이지 \n>>");
                scanf("%d", &mv_to_page);
                if (mv_to_page == 2) mv_page = 3;
                else if (mv_to_page == 1) mv_page = 1;
            }//mv page 2

            else if (mv_page == 3) {
                for (int i = 41; i < WordCount; i += 2) {
                    // 첫 번째 단어/뜻 쌍
                        int space = 15 - strlen(words[i][0]);
                        printf("                  ");
                        printf("%d. %s", i + 1, words[i][0]);
                        for (int j = 0; j < space; j++) printf(" ");
                        printf("%s", words[i][1]);

                        int space2 = 15 - strlen(words[i][1]);
                        // 추가 공간
                        for (int i = 0; i < space2; i++) printf(" ");
                        printf("||    ");

                        // 두 번째 단어/뜻 쌍 (WordCount가 홀수일 경우 마지막 단어/뜻 쌍을 처리하기 위한 조건)
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
                printf("1. 이전 페이지  2. 단어장 펼치기 종료 \n>>");
                scanf("%d", &mv_to_page);
                if (mv_to_page == 2) break;
                else if (mv_to_page == 1) mv_page = 2;
                }//mv page 3
        }//while문
    }//page 3일때

    // 동적 할당 해제
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
        printf("엔터 키 입력.\n");
        int input = getchar(); // 사용자로부터 한 문자 입력 받기
        if (input == '\n') { // 입력받은 문자가 '\n'이면, 즉 엔터 키이면

            break; // while 루프를 빠져나와 다음 단계로 진행
        }
    }
}//단어장 열기

//2.공부시작
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
    printf("    *************************************'토 린 이'를 위한 단어장************************************* ");
    printf("\n\n\n\n\n\n\n\n\n");
    printf("                               1. 정독 Quiz     2. 약점 보완     3. 눈으로 맞추는 퀴즈 \n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                                                   선택: ");
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

    char filename[20]; // 파일 이름을 저장할 배열의 크기를 늘렸습니다.
    sprintf(filename, "Day%d.txt", Day); // 파일 이름 생성

    char tempFilename[25];
    sprintf(tempFilename, "%s_temp", filename); // 임시 파일 이름 생성
    FILE* tempFile = fopen(tempFilename, "w");
    if (tempFile == NULL) {
        printf("임시 파일을 생성할 수 없습니다.\n");
        return;
    }

    // 작성
    for (int i = 0; i < WordCount; i++) {
            fprintf(tempFile, "%s-%s-%d\n", words[i][0], words[i][1], error[i]);   
    }

    // 파일 및 메모리 자원 정리
    fclose(tempFile);


    // 원본 파일 삭제 및 임시 파일 이름 변경
    remove(filename);
    rename(tempFilename, filename);

    //메모리 해제
    for (int i = 0; i < WordCount; i++) {
            for (int j = 0; j < 2; j++) {
                free(words[i][j]);
            }
            free(words[i]);
        }
        free(words);
        free(error);
}//공부 시작

//(1)퀴즈 - fgets 사용
void quiz(char*** words, int* error, int Day, int WordCount) {
    int wrongCount = 0;
    
    for (int j = 0; j < WordCount; j++) {
        system("cls");
        printf("    *************************************'토 린 이'를 위한 단어장************************************* ");
        printf("\n\n\n\n\n");
        printf("                                              *정독 퀴즈*\n\n\n\n");
        printf("                                         %d. '%s'의 의미는? ",j+1, words[j][0]);
        printf("\n\n\n\n\n\n\n\n\n\n\n");
        printf("                                                >>");
        char userAnswer[MAX_KOR_LENGTH + 1]; // +1 for null terminator
        fgets(userAnswer, MAX_KOR_LENGTH + 1, stdin);

        // fgets는 뉴라인 문자도 저장하므로, 입력된 문자열에서 뉴라인 문자를 제거합니다.
        userAnswer[strcspn(userAnswer, "\n")] = 0;

        if (strcmp(userAnswer, words[j][1]) != 0) {
            printf("\n                                   ");
            printf("틀렸습니다! %s의 뜻은 %s입니다.\n", words[j][0],words[j][1]);
            wrongCount++;
            error[j]++;
        }
        else {
            printf("\n                                               ");
            printf("정답입니다!\n");
        }
        while (1) {
            printf("\n\n\n\n");
            printf("엔터 키 입력.\n");
            int input = getchar(); // 사용자로부터 한 문자 입력 받기
            if (input == '\n') { // 입력받은 문자가 '\n'이면, 즉 엔터 키이면
                
                break; // while 루프를 빠져나와 다음 단계로 진행
            }
        }
    }
    system("cls");
    printf("    *************************************'토 린 이'를 위한 단어장************************************* ");
    printf("\n\n\n\n\n");
    printf("                                     ");
    printf("퀴즈가 끝났습니다. <Day %d> 총 틀린 개수: %d\n", Day, wrongCount);
    while (1) {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("엔터 키 입력.\n");
        int input = getchar(); // 사용자로부터 한 문자 입력 받기
        if (input == '\n') { // 입력받은 문자가 '\n'이면, 즉 엔터 키이면

            break; // while 루프를 빠져나와 다음 단계로 진행
        }
    }
}


//(2)약점 보완 - error 함수 이용
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
        printf("    *************************************'토 린 이'를 위한 단어장************************************* ");
        printf("\n\n\n\n\n");
        printf("                                           *약점 보완 퀴즈*\n\n\n\n");
        printf("                                           %d. '%s'의 의미는? ", j+1,words[error_sort[j]][0]);
        printf("\n\n\n\n\n\n\n\n\n\n\n");
        printf("                                                >>");
        char userAnswer[MAX_KOR_LENGTH + 1]; // +1 for null terminator
        fgets(userAnswer, MAX_KOR_LENGTH + 1, stdin);

        // fgets는 뉴라인 문자도 저장하므로, 입력된 문자열에서 뉴라인 문자를 제거합니다.
        userAnswer[strcspn(userAnswer, "\n")] = 0;

        if (strcmp(userAnswer, words[error_sort[j]][1]) != 0) {
            printf("\n\n                                                   오답입니다. %s의 의미는 %s 입니다.\n ", words[error_sort[j]][0],words[error_sort[j]][1]);
            wrongCount++;
            error[error_sort[j]]++;
            while (1) {
                printf("\n\n");
                printf("엔터 키 입력.\n");
                int input = getchar(); // 사용자로부터 한 문자 입력 받기
                if (input == '\n') { // 입력받은 문자가 '\n'이면, 즉 엔터 키이면

                    break; // while 루프를 빠져나와 다음 단계로 진행
                }
            }
        }
        else {
            printf("\n\n                                               정답입니다!\n");
            while (1) {
                printf("\n\n");
                printf("엔터 키 입력.\n");
                int input = getchar(); // 사용자로부터 한 문자 입력 받기
                if (input == '\n') { // 입력받은 문자가 '\n'이면, 즉 엔터 키이면

                    break; // while 루프를 빠져나와 다음 단계로 진행
                }
            }
        }
    }
    
    system("cls");
    printf("    *************************************'토 린 이'를 위한 단어장************************************* ");
    printf("\n\n\n\n\n");
    printf("                                     ");
    printf("퀴즈가 끝났습니다. <Day %d> 총 틀린 개수: %d\n", Day, wrongCount);
    while (1) {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("엔터 키 입력.\n");
        int input = getchar(); // 사용자로부터 한 문자 입력 받기
        if (input == '\n') { // 입력받은 문자가 '\n'이면, 즉 엔터 키이면

            break; // while 루프를 빠져나와 다음 단계로 진행
        }
    }


    free(error_sort);
    free(error_temp);


}




//(3)눈으로 공부하기
void quiz_know(char*** words, int* error, int Day, int WordCount) {
    int wrongCount = 0;
    int choice1 = 0;
    int choice2 = 0;
    for (int j = 0; j < WordCount; j++) {
        system("cls");
        printf("    *************************************'토 린 이'를 위한 단어장************************************* ");
        printf("\n\n\n\n\n");
        printf("                                           *눈으로 공부하기*\n\n\n\n");
        printf("                                          %d. '%s'의 의미는? ", j + 1, words[j][0]);
        printf("\n\n\n\n\n\n\n");
        printf("                                         1. 알고있다  2. 모르겠다");
        printf("\n\n\n\n\n\n\n");
            printf("                                                >>");
        scanf("%d", &choice1);
        getchar();
        switch (choice1) {
        case 1:
            printf("%s의 의미는 %s 입니다.\n\n", words[j][0], words[j][1]);
            printf("1. 맞췄다  2. 틀렸다\n>>");
            scanf("%d", &choice2);
            getchar();
            if (choice2 == 2) {
                error[j]++;
            }
            break;

        case 2:
            printf("%s의 의미는 %s 입니다.", words[j][0], words[j][1]);
            error[j]++;
            while (1) {
                printf("\n\n엔터 키 입력.");
                int input = getchar(); // 사용자로부터 한 문자 입력 받기
                if (input == '\n') { // 입력받은 문자가 '\n'이면, 즉 엔터 키이면

                    break; // while 루프를 빠져나와 다음 단계로 진행
                }
            }
            break;
        }
    }
}




//3.단어장 관리
//( 1 ) 추가
void addWord() {
    int Day = Choice_Day();
    int wordCount = readWordCount(Day);
    if (wordCount >= MAX_WORDS) {
        printf("단어 갯수가 초과되었습니다 ! \n ");
        return;
    }
    system("cls");
    printf("    *************************************'토 린 이'를 위한 단어장************************************* ");
    printf("\n\n\n\n\n                                                *단어 추가*");
    printf("\n\n                                           추가할 단어장 : Day %d\n", Day);
    char ENG[MAX_ENG_LENGTH];
    char KOR[MAX_KOR_LENGTH];
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                   단어: ");
    scanf("%s", ENG);
    printf("                                                   의미: ");
    scanf(" %[^\n]", KOR); // 공백 포함 입력 처리
    getchar();
    char filename[12]; // 파일 이름을 저장할 배열
    sprintf(filename, "Day%d.txt", Day); // 파일 이름 생성

    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    fprintf(file, "%s-%s-0\n", ENG, KOR);
    fclose(file);

    system("cls");
    printf("    *************************************'토 린 이'를 위한 단어장************************************* ");
    printf("\n\n\n\n\n                                                *단어 추가*");
    printf("\n\n                                           추가할 단어장 : Day %d\n", Day);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                      \"%s\"가 단어장에 추가되었습니다.\n", ENG);
    while (1) {
        printf("\n\n\n엔터 키 입력.\n");
        int input = getchar(); // 사용자로부터 한 문자 입력 받기
        if (input == '\n') { // 입력받은 문자가 '\n'이면, 즉 엔터 키이면

            break; // while 루프를 빠져나와 다음 단계로 진행
        }
    }
}
//( 2 ) 삭제
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
    printf("    *************************************'토 린 이'를 위한 단어장************************************* ");
    printf("\n\n\n\n\n                                                *단어 삭제*");
    printf("\n\n                                          삭제할 단어장 : Day %d\n", Day);
    int deletenum=0;
    char deleteWord[MAX_ENG_LENGTH];
    Load_Words(words, Day, error);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                   단어: ");
    scanf("%s", deleteWord);
    getchar();
    int no_word = 1;
    for (int i = 0; i < WordCount; i++) {
        if (strcmp(words[i][0], deleteWord) == 0){
            deletenum = i;
            no_word = 0;
            char filename[20]; // 파일 이름을 저장할 배열의 크기를 늘렸습니다.
            sprintf(filename, "Day%d.txt", Day); // 파일 이름 생성

            char tempFilename[25];
            sprintf(tempFilename, "%s_temp", filename); // 임시 파일 이름 생성
            FILE* tempFile = fopen(tempFilename, "w");
            if (tempFile == NULL) {
                printf("임시 파일을 생성할 수 없습니다.\n");
                return;
            }

            // 삭제할 단어를 제외한 나머지 단어를 임시 파일에 쓰기
            for (int i = 0; i < WordCount; i++) {
                if (i != deletenum) {
                    fprintf(tempFile, "%s-%s-%d\n", words[i][0], words[i][1], error[i]);
                }
            }

            // 파일 및 메모리 자원 정리
            fclose(tempFile);
            

            // 원본 파일 삭제 및 임시 파일 이름 변경
            remove(filename);
            rename(tempFilename, filename);

            printf("\"%s\" 단어가 삭제되었습니다.\n", deleteWord);
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
        printf("    *************************************'토 린 이'를 위한 단어장************************************* ");
        printf("\n\n\n\n\n                                                *단어 삭제*");
        printf("\n\n                                         삭제할 단어장 : Day %d\n", Day);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                    \"%s\"는 단어장 Day %d에 존재하지 않습니다. ",deleteWord,Day);
    }
    while (1) {
        printf("\n\n\n엔터 키 입력.\n");
        int input = getchar(); // 사용자로부터 한 문자 입력 받기
        if (input == '\n') { // 입력받은 문자가 '\n'이면, 즉 엔터 키이면

            break; // while 루프를 빠져나와 다음 단계로 진행
        }
    }
}


int Choice_Day() {
    int Day_Choice = 0;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                           원하는 단어장 Day : ");
    scanf("%d", &Day_Choice);
    getchar();
    if (Day_Choice < 1 || Day_Choice > 10) {
        printf("단어장 선택 오류 !!");
        Day_Choice = 0;
    }

    return Day_Choice;
}


int readWordCount(int _Day) {
    
    char filename[20]; // 파일 이름을 저장할 배열의 크기를 늘렸습니다.
    sprintf(filename, "Day%d.txt", _Day); // 파일 이름 생성
    
    
    
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
        printf("파일을 열 수 없습니다.\n");
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
    char filename[20]; // 파일 이름을 저장할 배열의 크기를 늘렸습니다.
    sprintf(filename, "Day%d.txt", _Day); // 파일 이름 생성

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    char line[256]; // 각 줄을 읽기 위한 충분한 크기의 문자 배열을 선언합니다.
    int i = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        // line에서 단어, 뜻, 오류 횟수를 분리하여 읽습니다.
        // sscanf 사용 시, line 배열을 사용합니다.
        sscanf(line, "%[^-]-%[^-]-%d", words[i][0], words[i][1], &error[i]);
        i++;
    }
    fclose(file);
}
 
//24.04.09 
//필요한 수정 사항
//1. Quiz구간 상단  고정바 수정 ex *정독 Quiz*  또는  *약점 보완*  *눈으로 맞추는 퀴즈*
//여러번 테스트 후 규격 검증
//그것만 하면 끝